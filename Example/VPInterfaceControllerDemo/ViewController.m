//
//  ViewController.m
//  VPInterfaceViewDemeo
//
//  Created by 李少帅 on 2017/7/9.
//  Copyright © 2017年 李少帅. All rights reserved.
//

#import "ViewController.h"
#import <AVKit/AVKit.h>
#import <AVFoundation/AVFoundation.h>
#import "VPSinglePlayerViewController.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextField *urlTextFiled;

@property (weak, nonatomic) IBOutlet UITextField *roomIdTextFiled;

@property (nonatomic, strong) NSArray *urlArray;

@property (nonatomic, assign) NSInteger index;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _urlArray = @[
                  @"http://7xr5j6.com1.z0.glb.clouddn.com/hunantv0129.mp4?v=0630",
                  @"http://7xr51b.com1.z0.glb.clouddn.com/langlang.mp4?v=2"
                  ];
    [_urlTextFiled setText:[_urlArray firstObject]];
    
    _roomIdTextFiled.text = @"25";
}

- (IBAction)videoButtonDidClick:(UIButton *)sender {
    
    VPSinglePlayerViewController *playerVC = [[VPSinglePlayerViewController alloc] initWithUrlString:_urlTextFiled.text platformUserID:nil isLive:NO];
    [self presentViewController:playerVC animated:YES completion:nil];
    
}

- (IBAction)liveButtonDidClick:(UIButton *)sender {
    VPSinglePlayerViewController *playerVC = [[VPSinglePlayerViewController alloc] initWithUrlString:_urlTextFiled.text platformUserID:_roomIdTextFiled.text isLive:YES];
    [self presentViewController:playerVC animated:YES completion:nil];
}

- (IBAction)exchangeUrlButtonDidClick:(UIButton *)sender {
    _index++;
    if (_index == [_urlArray count]) {
        _index = 0;
    }
    [_urlTextFiled setText:[_urlArray objectAtIndex:_index]];
}




- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
