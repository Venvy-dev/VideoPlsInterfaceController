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

@class VPInterfaceController;

typedef NS_ENUM(NSInteger, VPInterfaceControllerType) {
    VPInterfaceControllerTypeVideoOS,                      //点播
    VPInterfaceControllerTypeLiveOS,                       //直播
    VPInterfaceControllerTypeMall                          //子商城
};

@interface VPInterfaceControllerFactory : NSObject

/**
 *  创建VPInterfaceController
 *  param为需要传递的参数,keys为@"identifier"，@"platformUserID",@"videoTitle"
 *  VPInterfaceControllerTypeVideoOS param必须传递@"identifier"，可选@"videoTitle"
 *  VPInterfaceControllerTypeLiveOS param必须传递@"identifier"，可选@"platformUserID"
 *  VPInterfaceControllerTypeMall param必须传递@"identifier"，@"platformUserID"
 */
+ (VPInterfaceController*)createInterfaceControllerWithFrame:(CGRect)frame
                                             param:(NSDictionary*)param
                                              type:(VPInterfaceControllerType)type;

@end



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


/**
 *  切换环境
 *  @param isDebug 是否为测试环境
 */
+ (void)switchToDebug:(BOOL)isDebug;

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

@property (readonly, nonatomic) VPInterfaceControllerType type;

#pragma mark instance method
#pragma mark init method
/**
 *  创建VPInterfaceController
 *  param为需要传递的参数,keys为@"identifier"，@"platformUserID",@"videoTitle"
 *  VPInterfaceControllerTypeVideoOS param必须传递@"identifier"，可选@"videoTitle"
 *  VPInterfaceControllerTypeLiveOS param必须传递@"identifier"，可选@"platformUserID"
 *  VPInterfaceControllerTypeMall param必须传递@"identifier"，@"platformUserID"
 *  不能实例化，请用子类创建对象
 */
- (instancetype)initWithFrame:(CGRect)frame
                        param:(NSDictionary *)param
                         type:(VPInterfaceControllerType)type;

/**
 *  初始化InterfaceView
 *
 *  @param frame view对应frame
 *  @param identifier 对应videoIdentifier
 *  @param isLive 是否为直播
 *  @return InterfaceView,注意为NSObject,需要使用 .view 来获取视图层
 *  已经废弃，请用VPInterfaceControllerFactory创建对象
 */
- (instancetype)initWithFrame:(CGRect)frame
              videoIdentifier:(NSString *)identifier
                       isLive:(BOOL)isLive NS_DEPRECATED_IOS(2.0,2.0);


#pragma mark set method
//参数的设置方法,仅在startLoading之前能够设置
- (void)setVideoIdentifier:(NSString *)videoIdentifier;
- (void)setLive:(BOOL)isLive;

/**
 *  videoType已经无重要含义, 无须再设置
 */
- (void)setVideoType:(NSInteger)videoType;


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

/**
 *  暂停所有业务
 */
- (void)pauseInterfaceView:(BOOL)isPause;

- (BOOL)isString:(NSString *)string containsString:(NSString *)insideString;

@end
