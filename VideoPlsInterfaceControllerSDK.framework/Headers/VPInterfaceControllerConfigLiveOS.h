//
//  VPInterfaceControllerConfigLiveOS.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by peter on 10/01/2018.
//  Copyright © 2018 videopls. All rights reserved.
//

#import "VPInterfaceControllerConfig.h"

@interface VPInterfaceControllerConfigLiveOS : VPInterfaceControllerConfig

@property (nonatomic, copy) NSString *platformID;
@property (nonatomic, copy) NSString *platformUserID;

@property (nonatomic, copy) NSString *cate;
@property (nonatomic, assign) BOOL isAnchor;

@end
