//
//  VPIStoreAPIConfig.m
//  VideoPlsInterfaceControllerSDK
//
//  Created by Zard1096 on 2017/10/12.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import "VPIStoreAPIConfig.h"
#ifdef VP_LIVEOS
#import <VideoPlsLiveSDK/LDStoreAPIURLConfig.h>
#endif


@implementation VPIStoreAPIConfig

+ (NSString *)getStoreAPIURL:(VPIStoreAPIType)type {
#ifdef VP_LIVEOS
    return [LDStoreAPIURLConfig getStoreAPIURL:(LDStoreURLType)type];
#endif
    
    return nil;
}

@end
