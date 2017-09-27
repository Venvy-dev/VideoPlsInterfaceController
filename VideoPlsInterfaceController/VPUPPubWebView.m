//
//  VPUPPubWebView.m
//  VideoPlsInterfaceControllerSDK
//
//  Created by 鄢江波 on 2017/9/25.
//  Copyright © 2017年 videopls. All rights reserved.
//


#ifdef VP_LIVEOS
#import "VPUPPubWebView.h"
#import "VPUPUserLoginInterface.h"
#import <VideoPlsLiveSDK/LDIVAPlayback.h>

@interface VPUPPubWebView()

@property (nonatomic, strong) NSDictionary *(^bGetUserInfoBlock)(void);

@end

@implementation VPUPPubWebView


-(instancetype) initWithFrame:(CGRect) frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self initWebViewParams];
    }
    return self;
}

- (void) initWebViewParams {
    __weak typeof(self)  weakSelf = self;
    _bGetUserInfoBlock = ^NSDictionary *(void) {
        return [weakSelf getUserInfoDictionary];
    };
    [self setGetUserInfoBlock:_bGetUserInfoBlock];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notifyUserLogined:) name:LDSDKNotifyUserLoginNotification object:nil];
}

- (NSDictionary *)getUserInfoDictionary {
    VPUserInfo * userInfo = [self.userDelegate getUserInfo];
    if (!userInfo) {
        return nil;
    }
    NSMutableDictionary *dictionary = [[NSMutableDictionary alloc] init];
    if(!userInfo.uid) {
        return nil;
    }
    
    [dictionary setObject:userInfo.uid forKey:@"uid"];
    
    if(userInfo.token) {
        [dictionary setObject:userInfo.token forKey:@"token"];
    }
    if(userInfo.nickName) {
        [dictionary setObject:userInfo.nickName forKey:@"nickName"];
    }
    if(userInfo.userName) {
        [dictionary setObject:userInfo.userName forKey:@"userName"];
    }
    if(userInfo.phoneNum) {
        [dictionary setObject:userInfo.phoneNum forKey:@"phoneNum"];
    }
    
    return dictionary;
}

-(void) notifyUserLogined : (NSNotification *)sender {
    if (self.userDelegate) {
        NSDictionary *dic = sender.userInfo;
        if (dic) {
            VPUserInfo *userInfo = [[VPUserInfo alloc] init];
            if(![dic objectForKey:@"uid"]) {
                return;
            }
            userInfo.uid = [dic objectForKey:@"uid"];
            if([dic objectForKey:@"nickName"]) {
                userInfo.nickName = [dic objectForKey:@"nickName"];
            }
            if([dic objectForKey:@"token"]) {
                userInfo.token = [dic objectForKey:@"token"];
            }
            if([dic objectForKey:@"phoneNum"]) {
                userInfo.phoneNum = [dic objectForKey:@"phoneNum"];
            }
            if ([dic objectForKey: @"userName"]) {
                userInfo.userName = [dic objectForKey:@"userName"];
            }
            [self.userDelegate userLogined:userInfo];
        }
    }
}

- (void)closeAndRemoveFromSuperView {
    [self stopAndRemoveWebView];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:LDSDKNotifyUserLoginNotification object:nil];
    _bGetUserInfoBlock = nil;
}

-(void) dealloc {
     [[NSNotificationCenter defaultCenter] removeObserver:self name:LDSDKNotifyUserLoginNotification object:nil];
    [self stopAndRemoveWebView];
    _bGetUserInfoBlock = nil;
}

@end

#endif
