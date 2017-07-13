//
//  VPConfigSDK.h
//  VideoPlsInterfaceViewSDK
//
//  Created by Zard1096 on 2017/6/30.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VPConfigSDK : NSObject



/**
 *  初始化配置设置SDK相关key值,只可设置一次,如果不使用点播/直播功能,对应key可传空
 *  @param appKey 点播使用的appKey
 *  @param platformID 直播使用的platformID
 */
+ (void)setAppKey:(NSString *)appKey
       platformID:(NSString *)platformID;


/**
 *  设置IDFA
 *  @param IDFA 苹果广告IDFA码
 */
+ (void)setIDFA:(NSString *)IDFA;


#pragma mark Live addition config
#ifdef VP_LIVEOS
/**
 *  是否是芒果
 */
+ (void)setIsMangGuo:(BOOL)isMangGuo;

/**
 *  是否是熊猫
 */
+ (void)setIsPanda:(BOOL)isPanda;

/**
 *  是否是梨视频
 */
+ (void)setIsPear:(BOOL)isPear;

#endif


@end
