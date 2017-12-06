//
//  VPVideoOSInterfaceController.h
//  VideoPlsInterfaceControllerSDK
//
//  Created by peter on 04/12/2017.
//  Copyright © 2017 videopls. All rights reserved.
//

#import "VPInterfaceController.h"
#ifdef VP_VIDEOOS
@interface VPVideoOSInterfaceController : VPInterfaceController

- (instancetype)initVideoOSViewWithFrame:(CGRect)frame
                         videoIdentifier:(NSString *)identifier
                              videoTitle:(NSString *)videoTitle;

- (instancetype)initWithFrame:(CGRect)frame
                        param:(NSDictionary *)param;

- (instancetype)initWithFrame:(CGRect)frame
                        param:(NSDictionary *)param
                         type:(VPInterfaceControllerType)type;

/**
 *  视频的标题,如果没传入且为第一次播放(在所有端中),将会默认设置生成视频标题为:default(可选,标题在控制台统计中可见与修改)
 */
@property (readonly, nonatomic) NSString *videoTitle;

- (void)setVideoTitle:(NSString *)videoTitle;

/**
 *  设置当前播放时间,需设置一个计时器来持续调用
 *  根据热点出现的精准度需求可在`0.1~1s`之间选择
 *  请传入当前正在播放进度
 *  直播无需调用此方法
 *
 *  @param milliSecond 当前播放时间(单位:毫秒)
 */
- (void)updateCurrentPlaybackTime:(NSTimeInterval)milliSecond;

/**
 *  关闭所有信息层(点播专有)
 */
- (void)closeAllInfoLayer;

@end
#endif
