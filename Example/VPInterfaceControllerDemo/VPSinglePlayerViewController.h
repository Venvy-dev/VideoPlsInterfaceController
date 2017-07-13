//
//  VPSinglePlayerViewController.h
//  VPInterfaceControllerDemo
//
//  Created by Zard1096 on 2017/7/12.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VPSinglePlayerViewController : UIViewController

- (instancetype)initWithUrlString:(NSString *)urlString platformUserID:(NSString *)platformUserID isLive:(BOOL)isLive;

@end
