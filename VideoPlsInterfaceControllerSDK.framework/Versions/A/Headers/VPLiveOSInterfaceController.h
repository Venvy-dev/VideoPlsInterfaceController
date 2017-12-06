//
//  VPLiveOSInterfaceController.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by peter on 04/12/2017.
//  Copyright © 2017 videopls. All rights reserved.
//

#import "VPInterfaceController.h"
#ifdef VP_LIVEOS
@interface VPLiveOSInterfaceController : VPInterfaceController

- (instancetype)initLiveOSViewWithFrame:(CGRect)frame
                        videoIdentifier:(NSString *)identifier
                         platformUserID:(NSString *)platformUserID;

- (instancetype)initWithFrame:(CGRect)frame
                        param:(NSDictionary *)param;

- (instancetype)initWithFrame:(CGRect)frame
                        param:(NSDictionary *)param
                         type:(VPInterfaceControllerType)type;

@property (readonly, nonatomic) NSString *platformUserID;

- (void)setPlatformUserID:(NSString *)platformUserID;

- (BOOL)videoAdsIsPlaying;

/**
 *  暂停中插，优先级不如暂停所有业务高
 *  即，当暂停所有业务时，调起该API无作用
 */
- (void)pauseVideoAd:(BOOL)isPause;

@end
#endif
