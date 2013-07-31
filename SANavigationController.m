//
//  NavigationController.m
//  t
//
//  Created by tashigaofei on 13-7-30.
//  Copyright (c) 2013年 tashigaofei . All rights reserved.
//

#import "SANavigationController.h"
#import <QuartzCore/QuartzCore.h>

#if !__has_feature(objc_arc)
#error SANavigationController is ARC only. Either turn on ARC for the project or use -fobjc-arc flag
#endif

#define MinDetectableTransformX 10
#define ScreenWidth [UIScreen mainScreen].bounds.size.width
#define ScreenHeight [UIScreen mainScreen].bounds.size.height

@interface SANavigationController ()
{
    UIView *_animationView;
    UIPanGestureRecognizer *_panGesture;
}
@end

@implementation SANavigationController


-(void) loadView
{
    [super loadView];
    _panGesture = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panGestureAction:)];
    [self.view addGestureRecognizer:_panGesture];
    _animationView = [[UIView alloc] initWithFrame:[UIScreen mainScreen].bounds];
    
    self.underViewScale = self.underViewScale == 0 ? 0.9: self.underViewScale;
    self.animationDuration = self.animationDuration == 0 ? 0.3 : self.animationDuration;
    self.spot = self.spot == 0 ? 150 : self.spot;
}

- (void)pushScaleViewController:(UIViewController *)viewController animated:(BOOL)animated;
{
    
    [CATransaction begin];
    [CATransaction setDisableActions:YES];
    [self.view.window addSubview:_animationView];
    [self.view.window sendSubviewToBack:_animationView];
    _animationView.layer.contents = (id) [self getAnimationBitmap];
    _animationView.layer.position = self.view.center;
    CABasicAnimation *transformAnimation = [CABasicAnimation animationWithKeyPath:@"transform"];
    transformAnimation.fromValue = [NSValue valueWithCATransform3D:CATransform3DIdentity];
    transformAnimation.toValue = [NSValue valueWithCATransform3D:CATransform3DMakeScale(self.underViewScale, self.underViewScale, 1.0)];
    transformAnimation.duration = self.animationDuration;
    transformAnimation.fillMode = kCAFillModeForwards;
    _animationView.layer.transform = [transformAnimation.fromValue CATransform3DValue];
    [_animationView.layer addAnimation:transformAnimation forKey:@"transformAnimation"];
    [super pushViewController:viewController animated:animated];
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"position"];
    animation.fromValue = [NSValue valueWithCGPoint:CGPointMake(_animationView.center.x+ScreenWidth, _animationView.center.y)];
    animation.toValue = [NSValue valueWithCGPoint:_animationView.center];
    animation.duration = self.animationDuration;
    animation.fillMode = kCAFillModeBackwards;
    self.view.layer.position = _animationView.center;
    [self.view.layer addAnimation:animation forKey:@"RotateAnimation"];
    [CATransaction commit];
    
}

- (UIViewController *)popScaledViewControllerAnimated:(BOOL)animated;
{
    
    [CATransaction begin];
    [CATransaction setDisableActions:YES];
    [self.view.window addSubview:_animationView];
    [self.view.window bringSubviewToFront:_animationView];
    _animationView.layer.contents = (id) [self getAnimationBitmap];
    UIViewController * popedVC =  [super popViewControllerAnimated:NO];
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"position"];
    animation.fromValue = [NSValue valueWithCGPoint:self.view.center];
    animation.toValue = [NSValue valueWithCGPoint:CGPointMake(self.view.center.x+ScreenWidth, self.view.center.y)];
    animation.duration = 0.3;
    animation.fillMode = kCAFillModeBackwards;
    _animationView.layer.position = CGPointMake(self.view.center.x+ScreenWidth, self.view.center.y);
    [_animationView.layer addAnimation:animation forKey:@"RotateAnimation"];
    CABasicAnimation *transformAnimation = [CABasicAnimation animationWithKeyPath:@"transform"];
    transformAnimation.fromValue = [NSValue valueWithCATransform3D:CATransform3DMakeScale(self.underViewScale, self.underViewScale, 1.0)];
    transformAnimation.toValue = [NSValue valueWithCATransform3D:CATransform3DIdentity];
    transformAnimation.duration = 0.3;
    transformAnimation.fillMode = kCAFillModeBackwards;
    [self.view.layer addAnimation:transformAnimation forKey:@"transformAnimation"];
    [CATransaction commit];
    
    return popedVC;
}

static UIViewController *popedVC = nil;
-(void) panGestureAction:(UIPanGestureRecognizer *) gestureRecognizer
{
    UIGestureRecognizerState state = gestureRecognizer.state;
    CGPoint translation = [gestureRecognizer translationInView:self.view];
    if (state == UIGestureRecognizerStateBegan || state == UIGestureRecognizerStateChanged) {
        
        if ([self.viewControllers count] <=1 && popedVC == nil) {
            return;
        }
        
        if (translation.x > MinDetectableTransformX) {
            if (popedVC == nil) {
                [CATransaction begin];
                [CATransaction setDisableActions:YES];
                [self.view.window addSubview:_animationView];
                [self.view.window bringSubviewToFront:_animationView];
                _animationView.layer.contents = (id) [self getAnimationBitmap];
                popedVC = [self popViewControllerAnimated:NO];
                [CATransaction commit];
                self.view.transform =  CGAffineTransformMakeScale(self.underViewScale, self.underViewScale);
            }
            
            _animationView.center = (CGPoint){self.view.center.x + translation.x, self.view.center.y};
            CGFloat scale = self.underViewScale+translation.x/self.spot/((1-self.underViewScale)*100);
            scale = scale >= 1.0 ? 1.0: scale;
            self.view.transform =  CGAffineTransformMakeScale(scale, scale);
        }
        
        if (translation.x > self.spot) {
            [CATransaction begin];
            [CATransaction setDisableActions:YES];
            CABasicAnimation *transformAnimation = [CABasicAnimation animationWithKeyPath:@"transform"];
            transformAnimation.fromValue  = [NSValue valueWithCATransform3D:self.view.layer.transform];
            transformAnimation.toValue= [NSValue valueWithCATransform3D:CATransform3DIdentity];
            transformAnimation.duration = self.animationDuration;
            transformAnimation.fillMode = kCAFillModeBoth;
            self.view.layer.transform = CATransform3DIdentity;
            [self.view.layer addAnimation:transformAnimation forKey:@"transformAnimation"];
            CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"position"];
            animation.fromValue = [NSValue valueWithCGPoint:_animationView.center];
            animation.toValue = [NSValue valueWithCGPoint:CGPointMake(self.view.center.x+ScreenWidth, self.view.center.y)];
            animation.duration = self.animationDuration;
            animation.delegate = self;
            animation.fillMode = kCAFillModeBackwards;
            _animationView.layer.position = [animation.toValue CGPointValue];
            [_animationView.layer addAnimation:animation forKey:@"positionAnimation"];
            [CATransaction commit];
            
        }
        
    }else if (state== UIGestureRecognizerStateEnded || state == UIGestureRecognizerStateCancelled
              || state == UIGestureRecognizerStateFailed){
        
        if (translation.x < self.spot && translation.x > 0 && popedVC) {
            [UIView animateWithDuration:self.animationDuration delay:0.0 options:UIViewAnimationOptionCurveLinear animations:^{
                _animationView.center = self.view.center;
                self.view.transform = CGAffineTransformIdentity;
            } completion:^(BOOL finished) {
                [super pushViewController:popedVC animated:NO];
                [self.view.window sendSubviewToBack:_animationView];
                _animationView.layer.contents = nil;
                popedVC = nil;
            }];
        }
        
    }
    
    
}

- (void)animationDidStop:(CAAnimation *)theAnimation finished:(BOOL)flag
{
    popedVC = nil;
}


-(CGImageRef ) getAnimationBitmap
{
    
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(ScreenWidth, ScreenHeight), NO, 0.0);
    [self.view.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return  image.CGImage;
    
}

@end


@implementation UIViewController (NavigationController)
@dynamic scaledNavigationController;

-(SANavigationController *) scaledNavigationController
{
    return (SANavigationController *) self.navigationController;
}

@end

