//
//  VPInterfaceControllerConfig.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by peter on 07/12/2017.
//  Copyright © 2017 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VPInterfaceControllerType) {
    VPInterfaceControllerTypeVideoOS,                      //点播
    VPInterfaceControllerTypeLiveOS,                       //直播
    VPInterfaceControllerTypeMall,                         //子商城
    VPInterfaceControllerTypeEnjoy                         //互娱
};


@interface VPInterfaceControllerConfig : NSObject

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign, readonly) VPInterfaceControllerType type;

@end

