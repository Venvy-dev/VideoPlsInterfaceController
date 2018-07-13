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
#import "VPIUserLoginInterface.h"
#import "VPInterfaceControllerConfig.h"


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
@property (readonly, nonatomic, strong) UIView *view;

/**
 *  interface状态切换代理
 */
@property (nonatomic, weak) id<VPInterfaceStatusNotifyDelegate> delegate;


/**
 *  获取用户信息回调
 */
@property (nonatomic, weak) id<VPIUserLoginInterface> userDelegate;


/**
 *  Interface创建时的配置信息
 */

@property (nonatomic, readonly, strong) VPInterfaceControllerConfig *config;

#pragma mark instance method
#pragma mark init method
/**
 *  初始化InterfaceView
 *
 *  @param frame view对应frame
 *  @param config 对应config的子类
 *  @return InterfaceView,注意为NSObject,需要使用 .view 来获取视图层
 */

- (instancetype)initWithFrame:(CGRect)frame
                       config:(VPInterfaceControllerConfig *)config;

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
 *  互动层与整体显示区域大小相当,videoRect与视频实际显示位置相同,videoRect坐标系基于frame
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

@end
