//
//  VPIUserInfo.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by 鄢江波 on 2017/9/24.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VPIUserInfo : NSObject

@property (nonatomic, strong) NSString *uid;
@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *nickName;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *phoneNum;
@property (nonatomic, assign) BOOL isAnchor;

@end
