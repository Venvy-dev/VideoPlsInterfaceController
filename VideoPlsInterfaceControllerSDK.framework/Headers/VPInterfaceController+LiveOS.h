/*
 * This file is part of the VPUPSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "VPInterfaceController.h"

@interface VPInterfaceController ()

- (BOOL)videoAdsIsPlaying;

/**
 *  暂停中插，优先级不如暂停所有业务高
 *  即，当暂停所有业务时，调起该API无作用
 */
- (void)pauseVideoAd:(BOOL)isPause;

@end
