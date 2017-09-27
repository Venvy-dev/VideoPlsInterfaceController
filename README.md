# VideoPlsInterfaceController

[![CI Status](http://img.shields.io/travis/Zard1096/VideoPlsInterfaceController.svg?style=flat)](https://travis-ci.org/Zard1096/VideoPlsInterfaceController)
[![Version](https://img.shields.io/cocoapods/v/VideoPlsInterfaceController.svg?style=flat)](http://cocoapods.org/pods/VideoPlsInterfaceController)
[![License](https://img.shields.io/cocoapods/l/VideoPlsInterfaceController.svg?style=flat)](http://cocoapods.org/pods/VideoPlsInterfaceController)
[![Platform](https://img.shields.io/cocoapods/p/VideoPlsInterfaceController.svg?style=flat)](http://cocoapods.org/pods/VideoPlsInterfaceController)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

VideoPlsInterfaceViewSDK is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
只引入接入层，不引入直播和点播的SDK，不建议使用
pod "VideoPlsInterfaceController"

引入点播
VideoOS
pod "VideoPlsInterfaceController/VideoOS"

引入直播
LiveOS
pod "VideoPlsInterfaceController/LiveOS"

引入点播和直播
pod "VideoPlsInterfaceController", :subspecs => ['VideoOS', 'LiveOS']
```

## Usage

#### 1.设置`AppKey`和`platformID`
* 在`AppDelegate.m`文件中，`#import <VideoPlsInterfaceControllerSDK/VPConfigSDK.h>`
* 在`didFinishLaunchingWithOptions`中设置与bundleID对应的appkey和bundleID。(注:如何在我们的官网注册应用得到appkey和BundleID请点击链接查看我们的[十分钟玩转控制台教程](//videojj.com/blog/57c559c9e4e7fd450076f325)。)
	
	```
	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    	[VPConfigSDK setAppKey:@"B1016yZS-"
                platformID:@"575e6e087c395e0501980c89"];
		return YES;
}
	```
	
#### 2.创建`InterfaceController`
* 调用`init`方法创建`InterfaceController`

	```Objective-C
	- (instancetype)initWithFrame:(CGRect)frame
              videoIdentifier:(NSString *)identifier
                       isLive:(BOOL)isLive;
	```
* 如果是直播的话，需要额外设置一个`platformUserID`
* `videoTitle`是可选项，可以在后台配置时更清晰明确，建议设置
* 将生成的`controller`中的`view`添加到视频播放层中，加载的最佳位置为控制栏的下方，手势层的上方，请不要将`interfaceController.view`放入包含手势操作的`view`中
	
	```
	 //播放器层
	 [self.view addSubview:_player.view]; 
	 //互动层
    [self.view addSubview:_interfaceController.view];
    //控制栏
    [self.view addSubview:_mediaControlView];
	```

#### 3.开始播放视频
* 在需要使用互动层页面开始时调用`startVideoPls`
	
	```
	[VPInterfaceController startVideoPls];
	```
* 调用`InterfaceController`的`- (void)startLoading`方法
* 设置当前播放时间,根据热点出现的精准度需求可在`0.1~1s`之间选择
	
	```
	//需要更新的时间为毫秒数
    [_interfaceController updateCurrentPlaybackTime:playbackTime * 1000];
	```
	
#### 4.旋转屏幕
* 在旋转屏幕之后，视频的大小发生变化之后，需要调用`- (void)updateFrame:(CGRect)frame videoRect:(CGRect)videoRect isFullScreen:(BOOL)isFullScreen;`方法

	```
	    [_interfaceController updateFrame:self.view.bounds videoRect:_player.videoNowRect isFullScreen:_isFullScreen];
	```
	
* ***视频加载完成之后和互动层加载完成之后最好都调用一下`updateFrame`方法***

#### 5.关闭视频，注销互动层
* 在关闭视频的时候，调用`stop`方法
	```
	[_interfaceController stop];
	```
* 如果有打开多个视频页，并且都有互动层的时候，不在关闭的时候调用`endVideoPls`
* 在最后关闭掉所有互动层的时候，调用`endVideoPls`方法

	```
	[VPInterfaceController endVideoPls];

	```

#### 6.版本1.8.0新增
* VPInterfaceController ```- (void)openGoodsList```, 用来打开子商城侧边栏,关闭点击空白区域即可
* VPUPPubWebView , sdk通用webView需要调用生成
* ```userDelegate``, 对应 VPUPUserLoginInterface 的接口,详见下方
* ```- (void)closeAndRemoveFromSuperView``` 关闭并销毁webView
* ```- (void)loadUrl:(NSString *)url``` 父类方法,加载Url
* 新增 VPUPUserLoginInterface 和 VPUserInfo, VPUserInfo用来组装用户实例, VPUPUserLoginInterface 用来获取关于用户数据的回调; 
* ```- (VPUserInfo *)getUserInfo``` 通过平台方得到你们的userInfo
* ```- (void)userLogined:(VPUserInfo *) userInfo``` 通过sdk的webView登陆后会给你们对应的用户信息
* ```- (void)notifyScreenChange:(NSString *)url``` 当需要切成竖屏时会发出这个通知,传入的url需要打开 ```VPUPPubWebView``` 并调用loadUrl


## Author

Zard1096, mr.zardqi@gmail.com  
Lishaoshuai, lishaoshuai1990@gmail.com  
Bill, fuleiac@gmail.com

## License

VideoPlsInterfaceController is available under the MIT license. See the LICENSE file for more info.
