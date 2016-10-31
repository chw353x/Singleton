//
//  ViewController.m
//  Singleton
//
//  Created by chenwei on 2016/10/31.
//  Copyright © 2016年 gsww. All rights reserved.
//

#import "ViewController.h"
#import "CHSingleton.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    CHSingleton *obj1 = [CHSingleton sharedCHSingleton];
    CHSingleton *obj2 = [CHSingleton sharedCHSingleton];
    CHSingleton *obj3 = [[CHSingleton alloc] init];
    CHSingleton *obj4 = [[CHSingleton alloc] init];
    NSLog(@"%@", obj1);
    NSLog(@"%@", obj2);
    NSLog(@"%@", obj3);
    NSLog(@"%@", obj4);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
