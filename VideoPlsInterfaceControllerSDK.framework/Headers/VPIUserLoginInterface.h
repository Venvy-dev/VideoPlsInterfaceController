//
//  VPIUserLoginInterface.h
//  VideoPlsUtilsPlatformSDK
//
//  Created by 鄢江波 on 2017/9/22.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPIUserInfo.h"

@protocol VPIUserLoginInterface <NSObject>

@required
- (VPIUserInfo *)vp_getUserInfo;
- (void)vp_userLogined:(VPIUserInfo *)userInfo;
- (void)vp_notifyScreenChange:(NSString *)url;

//登陆成功后组成userInfo使用completeBlock(userInfo)完成回调
- (void)vp_requireLogin:(void (^)(VPIUserInfo *userInfo))completeBlock;

@end
