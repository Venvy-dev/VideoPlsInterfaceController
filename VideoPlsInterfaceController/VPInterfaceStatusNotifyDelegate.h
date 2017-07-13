//
//  VPInterfaceStatusNotifyDelegate.h
//  VideoPlsInterfaceViewSDK
//
//  Created by Zard1096 on 2017/7/3.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef VP_VIDEOOS
#import <VideoPlsCytronSDK/VPCytronNotificationNameSet.h>
#endif

#ifdef VP_LIVEOS
#import <VideoPlsLiveSDK/LDIVAPlayback.h>
#endif


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
 *  点播在互动内容被点击或者触发时可能需要做的某些对播放器的改变
 *  直播暂时不会影响到播放器相关,所以暂时没有这层通知
 *  @param changeStatus 互动内容触发,对应触发内容见 VPCytronViewNodeState
 */
- (void)vp_interfaceViewChangeStatus:(VPCytronViewNodeState)changeStatus;

/**
 *  热点或者信息层显示
 *  @param itemType 显示的类型
 */
- (void)vp_interfaceCytronItemShow:(VPCytronViewNodeType)itemType;

#endif

@end
