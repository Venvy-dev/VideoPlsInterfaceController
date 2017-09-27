//
//  VPUPUserLoginInterface.h
//  VideoPlsUtilsPlatformSDK
//
//  Created by 鄢江波 on 2017/9/22.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPUserInfo.h"

@protocol VPUPUserLoginInterface <NSObject>

@required
-(VPUserInfo *) getUserInfo;
-(void) userLogined:(VPUserInfo *) userInfo;
-(void) notifyScreenChange:(NSString *)url;

@end
