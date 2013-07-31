//
//  NavigationController.h
//  t
//
//  Created by tashigaofei on 13-7-30.
//  Copyright (c) 2013年 tashigaofei . All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SANavigationController : UINavigationController

@property (nonatomic, assign) CGFloat underViewScale;
@property (nonatomic, assign) CGFloat animationDuration;
@property (nonatomic, assign) CGFloat spot;

- (void)pushScaleViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (UIViewController *)popScaledViewControllerAnimated:(BOOL)animated;

@end

@interface UIViewController (NavigationController)

@property (nonatomic, strong) SANavigationController *scaledNavigationController;
@end

