//
//  VPConfigSDK.m
//  VideoPlsInterfaceViewSDK
//
//  Created by Zard1096 on 2017/6/30.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import "VPConfigSDK.h"

#define VP_USE_VIDEOOS  0
#define VP_USE_LIVEOOS  0

#ifdef VP_VIDEOOS
#import <VideoPlsCytronSDK/VideoPlsCytronSDK.h>
#undef VP_USE_VIDEOOS
#define VP_USE_VIDEOOS 1
#endif

#ifdef VP_LIVEOS
#import <VideoPlsLiveSDK/LiveIVASDK.h>
#undef VP_USE_LIVEOOS
#define VP_USE_LIVEOOS 1
#endif

@implementation VPConfigSDK

+ (void)setAppKey:(NSString *)appKey
       platformID:(NSString *)platformID {
#ifdef VP_VIDEOOS
    [VideoPlsCytronSDK setAppKey:appKey];
#endif
    
#ifdef VP_LIVEOS
    [LiveIVASDK setPlatformId:platformID];
#endif
}

+ (void)setIDFA:(NSString *)IDFA {
#ifdef VP_VIDEOOS
    [VideoPlsCytronSDK setIDFA:IDFA];
#endif
    
#ifdef VP_LIVEOS
    [LiveIVASDK setIDFA:IDFA];
#endif
}


#ifdef VP_LIVEOS

+ (void)setIsMangGuo:(BOOL)isMangGuo {
    [LiveIVASDK setIsMangGuo:isMangGuo];
}

+ (void)setIsPanda:(BOOL)isPanda {
    [LiveIVASDK setIsPanda:isPanda];
}

+ (void)setIsPear:(BOOL)isPear {
    [LiveIVASDK setIsPear:isPear];
}

#endif

@end
