//
//  VPAVPlayerController.h
//  VPInterfaceControllerDemo
//
//  Created by Zard1096 on 2017/7/11.
//  Copyright © 2017年 videopls. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

extern NSString *const VPAVPlayerIsPreparedToPlayNotification;
extern NSString *const VPAVPlayerLoadStateDidChangeNotification;
extern NSString *const VPAVPlayerPlaybackDidFinishNotification;
extern NSString *const VPAVPlayerPlaybackStateDidChangeNotification;
extern NSString *const VPAVPlayerPlayerbackDidSeekCompleteNotification;

@interface VPAVPlayerController : NSObject

@property (nonatomic, readonly) UIView *view;
@property (nonatomic, assign, readonly) NSTimeInterval duration;
@property (nonatomic, assign, readonly) NSTimeInterval playableDuration;
@property (nonatomic, assign, readonly) NSInteger bufferingProgress;

@property (nonatomic, assign, readonly) MPMoviePlaybackState playbackState;
@property (nonatomic, assign, readonly) MPMovieLoadState loadState;

@property (nonatomic, assign) NSTimeInterval currentPlaybackTime;

@property (nonatomic, readonly) CGSize videoTrueSize;
@property (nonatomic, readonly) CGRect videoNowRect;

- (instancetype)initWithContentURLString:(NSString *)urlString;
- (void)setContentURLString:(NSString *)urlString;

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;
- (void)shutdown;
- (void)setCurrentPlaybackTime:(NSTimeInterval)currentPlaybackTime;
- (void)updateFrame:(CGRect)newFrame;

@end
