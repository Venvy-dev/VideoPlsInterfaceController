//
//  VPInterfaceStatusNotifyDelegate.h
//  VideoPlsInterfaceViewSDK
//
//  Created by Zard1096 on 2017/7/3.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>


#ifdef VP_VIDEOOS
/**
 *  VideoOS需要接收播放器关闭WebView通知
 *  当外链由 app 打开并自己管理时需要发。如果是有中插，必须发。
 */
#define VPPlayerCloseWebViewNotification VPCytronPlayerCloseWebViewNotification
#endif

@protocol VPInterfaceStatusNotifyDelegate <NSObject>

@optional

/**
 *  打开WebView
 *  @param url 外链Url
 */
- (void)vp_webLinkOpenWithURL:(NSString *)url;

/**
 *  互动层加载完成后通知
 *  @param completeDictionary 点播端会有返回值,直播端为空(直播由于数据有实时性, 初始加载基本不含数据)
 *  点播端返回结果为 {@"VideoDataIsEmpty" : NSNumber(boolValue), @"VideoDataNeedShowInFullScreen" : NSNumber(boolValue)}
 *  VideoDataIsEmpty                    表示该视频是否有点位
 *  VideoDataNeedShowInFullScreen       表示是否有全屏点
 */
- (void)vp_interfaceLoadComplete:(NSDictionary *)completeDictionary;


/**
 *  互动层加载失败
 *  @param errorString 错误信息
 */
- (void)vp_interfaceLoadError:(NSString *)errorString;

#ifdef VP_VIDEOOS

/**
 *  交互状态枚举
 */
typedef NS_ENUM(NSInteger, VPIViewNodeState) {
    VPIViewNodeTagOpenInfoLayer,               //云链被点击,打开云窗,右边遮住小半屏,可自行根据需求暂停视频(最好隐藏控制栏)
    VPIViewInfoLayerClose,                     //云窗关闭,如果之前控制暂停视频可以继续播放
    
    //以下两个状态为信息层打开外链的通知,如果不由SDK控制外链打开不会发送这两个通知
    VPIViewInfoLayerOpenWebView,               //云窗的外链被点击,打开网页(遮盖整个互动层),最好暂停视频(最好隐藏控制栏)
    VPIViewWebViewClose,                       //网页关闭,可以继续播放
    
    VPIVideoClipShow,                          // 视频中插显示，暂停视频
    VPIVideoClipFinish                         // 视频中插结束，继续播放
};

/**
 *  点播在互动内容被点击或者触发时可能需要做的某些对播放器的改变
 *  直播暂时不会影响到播放器相关,所以暂时没有这层通知
 *  @param changeStatus 互动内容触发,对应触发内容见 VPCytronViewNodeState
 */
- (void)vp_interfaceViewChangeStatus:(VPIViewNodeState)changeStatus;

/**
 *  云链/云窗枚举
 */
typedef NS_ENUM(NSInteger, VPIViewNodeType) {
    VPIViewNodeTag,                            //云链
    VPIViewNodeInfoLayer                       //云窗
};

/**
 *  热点或者信息层显示
 *  @param itemType 显示的类型
 */
- (void)vp_interfaceCytronItemShow:(VPIViewNodeType)itemType;

#endif

@end
