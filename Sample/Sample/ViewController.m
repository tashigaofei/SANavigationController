//
//  ViewController.m
//  Sample
//
//  Created by tashigaofei on 13-7-31.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    UIButton *pushButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    pushButton.frame = CGRectMake(60, 10, 200, 44);
    pushButton.backgroundColor = [UIColor greenColor];
    [pushButton setTitle:@"pushButton" forState:UIControlStateNormal];
    [pushButton addTarget:self action:@selector(buttonAction:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:pushButton];

}

-(void) buttonAction:(id) sender
{
    UIViewController *vc = [[UIViewController alloc] init];
    vc.view.backgroundColor = [UIColor greenColor];
    UIButton *dissmissButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [dissmissButton setTitle:@"dissmissButton" forState:UIControlStateNormal];
    dissmissButton.frame = CGRectMake(60, 10, 200, 44);
    [dissmissButton addTarget:self action:@selector(dismissAction:) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:dissmissButton];
    [self.scaledNavigationController pushScaleViewController:vc animated:YES];
    
}

-(void) dismissAction:(UIButton*) sender
{
    [self.scaledNavigationController popScaledViewControllerAnimated:YES];
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
