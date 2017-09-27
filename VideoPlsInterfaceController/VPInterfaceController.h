//
//  VPInterfaceController.h
//  VideoPlsInterfaceViewSDK
//
//  Created by Zard1096 on 2017/6/25.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VPInterfaceStatusNotifyDelegate.h"
#import "VPUPUserLoginInterface.h"


@interface VPInterfaceController : NSObject

#pragma mark Class method
/**
 *  页面有需要加载互动层,在页面初始化时调用
 */
+ (void)startVideoPls;

/**
 *  页面退出或者在不再需要使用互动层时调用
 */
+ (void)stopVideoPls;

#pragma mark instance property
/**
 *  互动层的View, 在添加view时使用 [xxx addSubview:interfaceView.view];
 *  注意:无法切换生成的interfaceView即VideoOS和LiveOS无法互相切换,建议每次重新生成VPInterfaceController
 */
@property (readonly, nonatomic, weak) UIView *view;

/**
 *  interface状态切换代理
 */
@property (nonatomic, weak) id<VPInterfaceStatusNotifyDelegate> delegate;


/**
 *  获取用户信息回调
 */
@property (nonatomic, weak) id<VPUPUserLoginInterface> userDelegate;


/**
 *  视频的标识(原url),可以用url作为参数 或 使用拼接ID的方式来识别(前提为与pc对接并通过);直播即对应原接口的Url
 */
@property (readonly, nonatomic) NSString *videoIdentifier;

/**
 *  是否为直播
 */
@property (readonly, nonatomic, assign, getter = isLive) BOOL live;

#ifdef VP_VIDEOOS
#pragma mark property for VideoOS
/**
 *  视频的标题,如果没传入且为第一次播放(在所有端中),将会默认设置生成视频标题为:default(可选,标题在控制台统计中可见与修改)
 */
@property (readonly, nonatomic) NSString *videoTitle;
#endif

#ifdef VP_LIVEOS
#pragma mark property for LiveOS
@property (readonly, nonatomic) NSString *platformUserID;
#endif

#pragma mark instance method
#pragma mark init method
/**
 *  初始化InterfaceView
 *
 *  @param frame view对应frame
 *  @param identifier 对应videoIdentifier
 *  @param isLive 是否为直播
 *  @return InterfaceView,注意为NSObject,需要使用 .view 来获取视图层
 */
- (instancetype)initWithFrame:(CGRect)frame
              videoIdentifier:(NSString *)identifier
                       isLive:(BOOL)isLive;

#ifdef VP_VIDEOOS
#pragma mark VideoOS init
//默认isLive为No
- (instancetype)initVideoOSViewWithFrame:(CGRect)frame
                         videoIdentifier:(NSString *)identifier
                              videoTitle:(NSString *)videoTitle;
#endif

#ifdef VP_LIVEOS
#pragma mark LiveOS init
//默认isLive为YES
- (instancetype)initLiveOSViewWithFrame:(CGRect)frame
                        videoIdentifier:(NSString *)identifier
                         platformUserID:(NSString *)platformUserID;
#endif

#pragma mark set method
//参数的设置方法,仅在startLoading之前能够设置
- (void)setVideoIdentifier:(NSString *)videoIdentifier;
- (void)setLive:(BOOL)isLive;

/**
 *  videoType已经无重要含义, 无须再设置
 */
- (void)setVideoType:(NSInteger)videoType;

#ifdef VP_VIDEOOS
#pragma mark VideoOS set method
- (void)setVideoTitle:(NSString *)videoTitle;
#endif
#ifdef VP_LIVEOS

#pragma mark LiveOS set method
- (void)setPlatformUserID:(NSString *)platformUserID;
#endif


#pragma mark Interface loading and control
/**
 *  开始加载互动层,无法再设置属性
 */
- (void)startLoading;


/**
 *  停止并销毁互动层所有内容
 */
- (void)stop;

/**
 *  加载后能够设置,请加载完成后立即执行一次来适配视图位置
 *  设置互动层大小和该视频具体位置大小
 *  互动层与整体显示区域大小相当,videoRect与视频实际显示位置相同
 *  全屏显示互动,小窗不显示互动(暂定),通过后台配置,部分资源能够在小屏时显示
 *
 *  @param frame        互动层位置和大小
 *  @param videoRect    视频实际显示位置和大小
 *  @param isFullScreen 是否全屏
 */
- (void)updateFrame:(CGRect)frame videoRect:(CGRect)videoRect isFullScreen:(BOOL)isFullScreen;


#ifdef VP_VIDEOOS
/**
 *  设置当前播放时间,需设置一个计时器来持续调用
 *  根据热点出现的精准度需求可在`0.1~1s`之间选择
 *  请传入当前正在播放进度
 *  直播无需调用此方法
 *
 *  @param milliSecond 当前播放时间(单位:毫秒)
 */
- (void)updateCurrentPlaybackTime:(NSTimeInterval)milliSecond;

/**
 *  关闭所有信息层(点播专有)
 */
- (void)closeAllInfoLayer;
#endif


#ifdef VP_LIVEOS
/**
 *  打开子商城页面
 */
- (void)openGoodsList;
#endif


/**
 *  暂停所有业务
 */
- (void)pauseInterfaceView:(BOOL)isPause;

@end
