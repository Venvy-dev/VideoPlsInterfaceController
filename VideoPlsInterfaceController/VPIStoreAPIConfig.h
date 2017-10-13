//
//  VPIStoreAPIConfig.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by Zard1096 on 2017/10/12.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VPIStoreAPIType) {
    VPIStoreAPITypeShelf = 0,               //货架
    VPIStoreAPITypeOrder                    //我的订单
};

@interface VPIStoreAPIConfig : NSObject

+ (NSString *)getStoreAPIURL:(VPIStoreAPIType)type;

@end
