//
//  VPUPPubWebView.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by 鄢江波 on 2017/9/25.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#ifdef VP_MALL

@protocol VPUPUserLoginInterface;

@protocol VPUPPubWebViewCloseDelegate <NSObject>

@optional
//需要调用 closeAndRemoveFromSuperView
- (void)webViewNeedClose;

@end

@interface VPUPPubWebView : UIView

@property (nonatomic, weak) id<VPUPPubWebViewCloseDelegate> delegate;
@property (nonatomic, weak) id<VPUPUserLoginInterface> userDelegate;

- (instancetype)initWithFrame:(CGRect)frame;

- (void)loadUrl:(NSString *)url;

- (void)closeAndRemoveFromSuperView;

@end

#endif
