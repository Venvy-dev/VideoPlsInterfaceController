//
//  VPUPPubWebView.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by 鄢江波 on 2017/9/25.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifdef VP_LIVEOS
//#import <VideoPlsLiveSDK/LDPubWebView.h>
#import <VideoPlsUtilsPlatformSDK/VideoPlsUtilsPlatformSDK.h>
#import "VPMGoodsListStorePublicWebView.h"
@protocol VPUPUserLoginInterface;

@protocol VPUPPubWebViewCloseDelegate <NSObject>

@optional
//需要调用 closeAndRemoveFromSuperView
- (void)webViewNeedClose;

@end

@interface VPUPPubWebView : VPMGoodsListStorePublicWebView

@property (nonatomic, weak) id<VPUPPubWebViewCloseDelegate> delegate;
@property (nonatomic, weak) id<VPUPUserLoginInterface> userDelegate;

- (void)loadUrl:(NSString *)url;

- (void)closeAndRemoveFromSuperView;

@end

#endif
