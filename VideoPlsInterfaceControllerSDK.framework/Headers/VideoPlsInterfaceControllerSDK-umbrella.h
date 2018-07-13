#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "VPIConfigSDK.h"
#import "VPInterfaceController.h"
#import "VPInterfaceControllerConfig.h"
#import "VPInterfaceStatusNotifyDelegate.h"
#import "VPIUserLoginInterface.h"
#import "VPIUserInfo.h"
#import "VPInterfaceControllerConfigLiveOS.h"
#import "VPInterfaceController+LiveOS.h"

FOUNDATION_EXPORT double VideoPlsInterfaceControllerSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char VideoPlsInterfaceControllerSDKVersionString[];

