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



typedef NS_ENUM(NSUInteger, VPIActionItemType) {
    VPIActionItemTypeTag,               // 热点
    VPIActionItemTypeAdInfo,            // 海报
    VPIActionItemTypeBasicWiki,         // 百科
    VPIActionItemTypeBasicMix,          // 轮播广告
    VPIActionItemTypeCardGame,          // 卡牌
    VPIActionItemTypeVote,              // 投票
    VPIActionItemTypeImage,             // 云图
    VPIActionItemTypeGift,              // 红包
    VPIActionItemTypeEasyShop,          // 轻松购,商品
    VPIActionItemTypeLottery,           // 趣味抽奖
    VPIActionItemTypeBubble,            // 灵动气泡
    VPIActionItemTypeVideoClip,         // 中插广告
    VPIActionItemTypeNews,              // 新闻
    VPIActionItemTypeText,              // 图文链
    VPIActionItemTypeFavor,             // 点赞
    VPIActionItemTypeGoodList,          // 电商清单
};

/**
 *  事件发送通知类型枚举
 */
typedef NS_ENUM(NSUInteger, VPIActionType) {
    VPIActionTypeShow,                  // 显示
    VPIActionTypeClick,                 // 点击
    VPIActionTypeClose,                 // 关闭
};

/**
 *  事件监控通知
 *  @param actionDictionary 参数字典
 *  对应
 *  Key:    resourceID
 *  Value:  string
 *
 *  Key:    adID
 *  Value:  string
 *
 *  Key:    adType
 *  Value:  VPIActionItemType
 *
 *  Key:    adTypeDetail
 *  Value:  string(从点播或直播来的原始数据)
 *
 *  Key:    action
 *  Value:  VPIActionType
 */
- (void)vp_interfaceActionNotify:(NSDictionary *)actionDictionary;



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
    VPIVideoClipFinish,                        // 视频中插结束，继续播放
    VPIVideoClipPlay,                          // 视频中插播放（包括开始播放，暂停之后的播放）
    VPIVideoClipPause                          //视频中插暂停(包括平台方调用导致暂停、退出／关闭中插导致暂停)
};

/**
 *  点播在互动内容被点击或者触发时可能需要做的某些对播放器的改变
 *  直播暂时不会影响到播放器相关,所以暂时没有这层通知
 *  @param changeStatus 互动内容触发,对应触发内容见 VPCytronViewNodeState
 */
- (void)vp_interfaceViewChangeStatus:(VPIViewNodeState)changeStatus;
#ifdef VP_VIDEOOS
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

#ifdef VP_LIVEOS

/**
 *  播放中插时，点击左上角返回按钮事件，交由平台方处理
 *  暂时只有直播有返回按钮
 */
- (void)vp_interfaceVideoAdBack;
#endif

#ifdef VP_ENJOY

/**
 *  互娱主播端关闭配置页通知
 */
- (void)vp_interfaceEnjoyEnd;
#endif

@end
