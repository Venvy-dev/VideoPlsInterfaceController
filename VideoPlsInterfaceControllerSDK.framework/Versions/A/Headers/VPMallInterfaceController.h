//
//  VPMallInterfaveController.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by peter on 04/12/2017.
//  Copyright © 2017 videopls. All rights reserved.
//

#import "VPInterfaceController.h"
#ifdef VP_MALL
@interface VPMallInterfaceController : VPInterfaceController

- (instancetype)initWithFrame:(CGRect)frame
                        param:(NSDictionary *)param;

- (instancetype)initWithFrame:(CGRect)frame
                        param:(NSDictionary *)param
                         type:(VPInterfaceControllerType)type;

/**
 *  打开子商城页面
 */
- (void)openGoodsList;

@end
#endif
