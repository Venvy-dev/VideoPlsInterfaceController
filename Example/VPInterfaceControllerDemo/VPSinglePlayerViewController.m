//
//  VPSinglePlayerViewController.m
//  VPInterfaceControllerDemo
//
//  Created by Zard1096 on 2017/7/12.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import "VPSinglePlayerViewController.h"
#import "VPAVPlayerController.h"
#import "VPMediaControlView.h"

#import <VideoPlsInterfaceController/VPInterfaceController.h>
#import <VideoPlsInterfaceController/VPInterfaceStatusNotifyDelegate.h>

@interface VPSinglePlayerViewController() <VPInterfaceStatusNotifyDelegate> {
    NSString *_urlString;
    NSString *_platformUserID;
    BOOL _isLive;
    
    BOOL _isFullScreen;
    
    BOOL _videoClipOpen;
    BOOL _needToPlay;
    
    VPAVPlayerController *_player;
    VPMediaControlView *_mediaControlView;
    UIView *_gestureView;
    
    VPInterfaceController *_interfaceController;
    
    NSTimer *_refreshInterfaceTimer;
}

@end

@implementation VPSinglePlayerViewController

- (instancetype)initWithUrlString:(NSString *)urlString platformUserID:(NSString *)platformUserID isLive:(BOOL)isLive {
    self = [super init];
    if (self) {
        _urlString = urlString;
        _platformUserID = platformUserID;
        _isLive = isLive;
        
        
        //在需要使用互动层页面开始时调用startVideoPls
        //TODO: 如果有navigationController需要打开多个视频页不在这里开启
        [VPInterfaceController startVideoPls];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    if(!_urlString) {
        return;
    }
    
    _isFullScreen = UIDeviceOrientationIsLandscape([UIDevice currentDevice].orientation);
    
    [self initPlayer];
    [self initMediaControlView];
    [self initGestureView];
    [self initInterfaceController];
    
    [self.view addSubview:_player.view];
    //手势层置于互动层下方
    [self.view addSubview:_gestureView];
    [self.view addSubview:_interfaceController.view];
    //控制栏没有全屏幕手势放在最上方
    [self.view addSubview:_mediaControlView];
    
    [self registerDeviceOrientationNotification];
}

- (void)dealloc {
    
}

- (void)initPlayer {
    _player = [[VPAVPlayerController alloc] initWithContentURLString:_urlString];
    _player.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [_player updateFrame:self.view.bounds];
    [self registerPlayerNotification];
    [_player prepareToPlay];
}

- (void)initMediaControlView {
    _mediaControlView = [VPMediaControlView mediaControlViewWithNib];
    [_mediaControlView setFrame:self.view.bounds];
    [_mediaControlView setAVPlayerController:_player];
    
    __weak typeof(self) weakSelf = self;
    [_mediaControlView setBackButtonTappedToDo:^{
        [weakSelf dismissPlayerViewController];
    }];
    
    _mediaControlView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
}

- (void)initGestureView {
    _gestureView = [[UIView alloc] initWithFrame:self.view.bounds];
    _gestureView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    UITapGestureRecognizer *tapGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(gestureViewTapped:)];
    tapGestureRecognizer.numberOfTapsRequired = 1;
    tapGestureRecognizer.numberOfTouchesRequired = 1;
    
    [_gestureView addGestureRecognizer:tapGestureRecognizer];
}

- (void)initInterfaceController {
    //videoIdentifier可传协商过唯一ID拼接,并非必须为url
    _interfaceController = [[VPInterfaceController alloc] initWithFrame:self.view.bounds videoIdentifier:_urlString isLive:_isLive];
    _interfaceController.delegate = self;
    if(!_isLive) {
#ifdef VP_VIDEOOS
        [_interfaceController setVideoTitle:@"Test"];
#endif
    } else {
#ifdef VP_LIVEOS
        [_interfaceController setPlatformUserID:_platformUserID];
#endif
    }
    [_interfaceController startLoading];
}

- (void)refreshInterfaceContainer {
    NSTimeInterval playbackTime = _player.currentPlaybackTime;
    //需要更新的时间为毫秒数
    [_interfaceController updateCurrentPlaybackTime:playbackTime * 1000];
}

- (void)dismissPlayerViewController {
    [self stop];
    [self dismissViewControllerAnimated:YES completion:^{
        //TODO: 如果有navigationController需要打开多个视频页不在这里关闭
        [VPInterfaceController stopVideoPls];
    }];
}

- (void)stop {
    if(_refreshInterfaceTimer) {
        [_refreshInterfaceTimer invalidate];
        _refreshInterfaceTimer = nil;
    }
    [_player shutdown];
    [_mediaControlView stop];
    [_interfaceController stop];
    _interfaceController.delegate = nil;
    
    [self deregisterPlayerNotification];
    
    [_gestureView removeGestureRecognizer:[_gestureView.gestureRecognizers firstObject]];
}

- (void)gestureViewTapped:(id)sender {
    if(_mediaControlView.isShowed) {
        [_mediaControlView hideControlView];
    }
    else {
        [_mediaControlView showControlView];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)registerPlayerNotification {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(playerIsPreparedToPlay:) name:VPAVPlayerIsPreparedToPlayNotification object:_player];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(playerPlaybackDidFinish:) name:VPAVPlayerPlaybackDidFinishNotification object:_player];
}

- (void)deregisterPlayerNotification {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:VPAVPlayerIsPreparedToPlayNotification object:_player];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:VPAVPlayerPlaybackDidFinishNotification object:_player];
}

- (void)registerDeviceOrientationNotification {
    [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(deviceOrientationChange:) name:UIDeviceOrientationDidChangeNotification object:nil];
}

- (void)deregisterDeviceOrientationNotification {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIDeviceOrientationDidChangeNotification object:nil];
    
    [[UIDevice currentDevice] endGeneratingDeviceOrientationNotifications];
}

#pragma mark -- Notification

- (void)playerIsPreparedToPlay:(NSNotification *)notification {
    //在视频加载完成后更新一次interface的界面大小
    [_interfaceController updateFrame:self.view.bounds videoRect:_player.videoNowRect isFullScreen:_isFullScreen];
}

- (void)playerPlaybackDidFinish:(NSNotification *)notification {
    //    MPMovieFinishReasonPlaybackEnded,
    //    MPMovieFinishReasonPlaybackError,
    //    MPMovieFinishReasonUserExited
    int reason = [[[notification userInfo] valueForKey:MPMoviePlayerPlaybackDidFinishReasonUserInfoKey] intValue];
    
    NSLog(@"finish reasion:%d",reason);
    
}

- (void)deviceOrientationChange:(NSNotification *)notification {
    UIDeviceOrientation orientation = [UIDevice currentDevice].orientation;
    
    if(UIDeviceOrientationIsLandscape(orientation)) {
        _isFullScreen = YES;
    }
    else {
        _isFullScreen = NO;
    }
    
    [_player updateFrame:self.view.bounds];
    [_mediaControlView setIsFullScreen:_isFullScreen];
    //旋转更新界面大小
    [_interfaceController updateFrame:self.view.bounds videoRect:_player.videoNowRect isFullScreen:_isFullScreen];
}


#pragma mark -- VPInterfaceStatusChangeNotifyDelegate
- (void)vp_webLinkOpenWithURL:(NSString *)url {
    //可以使用url去打开webview
}

- (void)vp_interfaceLoadComplete:(NSDictionary *)completeDictionary {
    NSLog(@"%@",completeDictionary);
    
    //在互动层加载完成后最好也更新一次interface界面大小
    [_interfaceController updateFrame:self.view.bounds videoRect:_player.videoNowRect isFullScreen:_isFullScreen];
    
    //添加刷新timer,只有点播需要
    if(!_isLive) {
        if(!_refreshInterfaceTimer) {
            _refreshInterfaceTimer = [NSTimer scheduledTimerWithTimeInterval:0.1 target:self selector:@selector(refreshInterfaceContainer) userInfo:nil repeats:YES];
        }
    }
}

- (void)vp_interfaceLoadError:(NSString *)errorString {
    NSLog(@"%@",errorString);
}

- (void)vp_interfaceViewChangeStatus:(VPIViewNodeState)changeStatus {
    
    if (changeStatus == VPIViewInfoLayerOpenWebView || changeStatus == VPIViewNodeTagOpenInfoLayer || changeStatus == VPIVideoClipShow) {
        [_mediaControlView hideControlView];
    }

  
    
    if (!_isLive) {
        switch (changeStatus) {
            case VPIViewInfoLayerOpenWebView: {
                
                if ([_player isPlaying]) {
                    _needToPlay = YES;
                    [_mediaControlView playButtonTapped:nil];
                }
                break;
            }
            case VPIViewWebViewClose: {
                
                if (_videoClipOpen) {
                    //TODO: 如果接管webView打开，需要发通知
//                    [[NSNotificationCenter defaultCenter] postNotificationName:VPPlayerCloseWebViewNotification object:nil];
                    break;
                }
                
                if (_needToPlay) {
                    if (![_player isPlaying]) {
                        [_mediaControlView playButtonTapped:nil];
                    }
                }
                break;
            }
            case VPIVideoClipShow: {
                
                _videoClipOpen = YES;
                
                if ([_player isPlaying]) {
                    _needToPlay = YES;
                    [_mediaControlView playButtonTapped:nil];
                }
                
                break;
            }
            case VPIVideoClipFinish: {
                _videoClipOpen = NO;
                
                if (_needToPlay) {
                    if (![_player isPlaying]) {
                        [_mediaControlView playButtonTapped:nil];
                    }
                }
                
                break;
            }
            default:
                break;
        }
    }
    
}

- (void)vp_interfaceCytronItemShow:(VPIViewNodeType)itemType {
    
}

- (void)vp_interfaceActionNotify:(NSDictionary *)actionDictionary {
    NSLog(@"%@", actionDictionary);
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
