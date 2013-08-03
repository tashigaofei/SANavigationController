///**
// * This header is generated by class-dump-z 0.2a.
// * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
// *
// * Source: /System/Library/Frameworks/UIKit.framework/UIKit
// */
//
//#import <UIKit/UIKit.h>
//
//@class UINavigationTransitionView, NSArray, UIView, UINavigationBar, UIToolbar;
//@protocol UINavigationControllerDelegate;
//
//@interface UINavigationController : UIViewController {
//@private
//	UIView* _containerView;
//	UINavigationBar* _navigationBar;
//	Class _navigationBarClass;
//	UIToolbar* _toolbar;
//	UIView* _navigationTransitionView;
//	UIEdgeInsets _currentScrollContentInsetDelta;
//	UIEdgeInsets _previousScrollContentInsetDelta;
//	float _previousScrollContentOffsetDelta;
//	float _bottomInsetDelta;
//	UIViewController* _disappearingViewController;
//	id<UINavigationControllerDelegate> _delegate;
//	int _savedNavBarStyleBeforeSheet;
//	int _savedToolBarStyleBeforeSheet;
//	struct {
//		unsigned isAppearingAnimated : 1;
//		unsigned isAlreadyPoppingNavigationItem : 1;
//		unsigned isNavigationBarHidden : 1;
//		unsigned isToolbarShown : 1;
//		unsigned needsDeferredTransition : 1;
//		unsigned isTransitioning : 1;
//		unsigned lastOperation : 4;
//		unsigned lastOperationAnimated : 1;
//		unsigned deferredTransition : 8;
//		unsigned didPreloadKeyboardAnimation : 1;
//		unsigned didHideBottomBar : 1;
//		unsigned isChangingOrientationForPop : 1;
//		unsigned pretendNavBarHidden : 1;
//		unsigned avoidMovingNavBarOffscreenBeforeUnhiding : 1;
//		unsigned searchBarHidNavBar : 1;
//		unsigned useSystemPopoverBarAppearance : 1;
//		unsigned isCustomTransition : 1;
//	} _navigationControllerFlags;
//	Class _toolbarClass;
//	float _customNavigationTransitionDuration;
//	BOOL _interactiveTransition;
//}
//@property(assign, nonatomic, getter=isInteractiveTransition) BOOL interactiveTransition;
//@property(assign, nonatomic, setter=_setToolbarClass:) Class _toolbarClass;
//@property(readonly, assign, nonatomic) UIViewController* bottomViewController;
//@property(readonly, assign, nonatomic) UIViewController* previousViewController;
//@property(retain, nonatomic) UIViewController* disappearingViewController;
//@property(assign, nonatomic) float customNavigationTransitionDuration;
//@property(assign, nonatomic) BOOL avoidMovingNavBarOffscreenBeforeUnhiding;
//@property(assign, nonatomic) BOOL pretendNavBarHidden;
//@property(readonly, assign, nonatomic) UINavigationTransitionView* navigationTransitionView;
//@property(assign, nonatomic) BOOL needsDeferredTransition;
//@property(assign, nonatomic) id<UINavigationControllerDelegate> delegate;
//@property(readonly, assign, nonatomic) UIToolbar* toolbar;
//@property(assign, nonatomic, getter=isToolbarHidden) BOOL toolbarHidden;
//@property(readonly, assign, nonatomic) UINavigationBar* navigationBar;
//@property(assign, nonatomic, getter=isNavigationBarHidden) BOOL navigationBarHidden;
//@property(copy, nonatomic) NSArray* viewControllers;
//@property(readonly, assign, nonatomic) UIViewController* visibleViewController;
//@property(readonly, assign, nonatomic) UIViewController* topViewController;
//@property(assign) BOOL isExpanded;
//@property(retain) UIViewController* detailViewController;
//-(id)moreListTableCell;
//-(id)moreListSelectedImage;
//-(id)moreListImage;
//-(id)_moreListTitle;
//-(void)_didResignContentViewControllerOfPopover:(id)popover;
//-(void)_didBecomeContentViewControllerOfPopover:(id)popover;
//-(void)_willBecomeContentViewControllerOfPopover:(id)popover;
//-(id)_viewForContentInPopover;
//-(BOOL)isModalInPopover;
//-(void)_prepareForPresentationInPopover:(id)popover;
//-(void)_prepareForDismissalInPopover:(id)popover;
//-(CGRect)_frameForContainerViewInSheetForBounds:(CGRect)bounds displayingTopView:(BOOL)view andBottomView:(BOOL)view3;
//-(CGSize)contentSizeForViewInPopover;
//-(void)setContentSizeForViewInPopover:(CGSize)popover;
//-(CGSize)_adjustedContentSizeForPopover:(CGSize)popover;
//-(void)_layoutTopViewControllerOutOfSheet;
//-(void)_layoutTopViewControllerInSheetWithPopoverView:(id)popoverView;
//-(void)_layoutTopViewControllerInSheet;
//-(void)updateTabBarItemForViewController:(id)viewController;
//-(id)tabBarItem;
//-(id)defaultPNGName;
//-(void)navigationBarDidChangeOpacity:(id)navigationBar;
//-(void)navigationBarDidResizeForPrompt:(id)navigationBar;
//-(void)navigationBar:(id)bar buttonClicked:(int)clicked;
//-(BOOL)navigationBar:(id)bar shouldPopItem:(id)item;
//-(void)updateTitleForViewController:(id)viewController;
//-(void)didRotateFromInterfaceOrientation:(int)interfaceOrientation;
//-(void)willAnimateSecondHalfOfRotationFromInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
//-(void)didAnimateFirstHalfOfRotationToInterfaceOrientation:(int)interfaceOrientation;
//-(void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
//-(void)willAnimateRotationToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
//-(void)willRotateToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
//-(void)_getRotationContentSettings:(XXStruct_tXAZTC*)settings;
//-(BOOL)_shouldUseOnePartRotation;
//-(id)rotatingFooterView;
//-(id)rotatingHeaderView;
//-(BOOL)_isSupportedInterfaceOrientation:(int)orientation;
//-(BOOL)_shouldSynthesizeSupportedOrientations;
//-(BOOL)shouldAutorotateToInterfaceOrientation:(int)interfaceOrientation;
//-(BOOL)_doesTopViewControllerSupportInterfaceOrientation:(int)orientation;
//-(BOOL)_allowsAutorotation;
//-(void)makeModalViewControllerTopViewController;
//-(id)popToViewControllerWithSnapbackIdentifier:(id)snapbackIdentifier animated:(BOOL)animated;
//-(id)popToViewController:(id)viewController transition:(int)transition;
//-(id)popToViewController:(id)viewController animated:(BOOL)animated;
//-(id)popToRootViewControllerWithTransition:(int)transition;
//-(id)popToRootViewControllerAnimated:(BOOL)rootViewControllerAnimated;
//-(id)popViewControllerWithTransition:(int)transition;
//-(id)popViewControllerWithAnimationTransition:(int)animationTransition duration:(double)duration curve:(int)curve;
//-(id)_popViewControllerWithTransition:(int)transition allowPoppingLast:(BOOL)last;
//-(void)_popViewControllerAndUpdateInterfaceOrientationAnimated:(BOOL)animated;
//-(float)_customNavigationTransitionDuration;
//-(BOOL)_isInteractiveCustomNavigationTransition;
//-(BOOL)_willPerformCustomNavigationTransitionForPush;
//-(BOOL)_willPerformCustomNavigationTransitionForPop;
//-(BOOL)_shouldPopFromLandscapeToPortraitOrientation;
//-(id)_snapshotView;
//-(void)_tabBarControllerDidFinishShowingTabBar:(id)_tabBarController;
//-(void)_hideOrShowBottomBarIfNeededWithTransition:(int)transition;
//-(void)_updateBottomBarHiddenState;
//-(void)_resetBottomBarHiddenState;
//-(BOOL)_shouldBottomBarBeHidden;
//-(id)popViewControllerAnimated:(BOOL)animated;
//-(void)pushViewController:(id)controller transition:(int)transition;
//-(void)pushViewController:(id)controller transition:(int)transition forceImmediate:(BOOL)immediate;
//-(void)pushViewController:(id)controller animated:(BOOL)animated;
//-(void)__viewWillLayoutSubviews;
//-(void)_clearLastOperation;
//-(int)_deferredTransition;
//-(void)_startDeferredTransitionIfNeeded;
//-(void)_startDeferredTransitionIfNeeded:(id)needed;
//-(void)_startTransition:(int)transition fromViewController:(id)viewController toViewController:(id)viewController3;
//-(void)_updateScrollViewFromViewController:(id)viewController toViewController:(id)viewController2;
//-(int)_navigationTransitionForUITransition:(int)uitransition;
//-(void)_layoutViewController:(id)controller;
//-(void)_computeAndApplyScrollContentInsetDeltaForViewController:(id)viewController;
//-(void)_applyScrollContentInsetDelta:(UIEdgeInsets)delta forViewController:(id)viewController;
//-(UIEdgeInsets)_expectedContentInsetDeltaForViewController:(id)viewController;
//-(float)_scrollViewTopContentInsetForViewController:(id)viewController;
//-(float)_scrollViewBottomContentInset;
//-(void)_layoutTopViewController;
//-(CGRect)_frameForViewController:(id)viewController;
//-(BOOL)_shouldChildViewControllerUseFullScreenLayout:(id)layout;
//-(BOOL)_shouldNavigationBarInsetViewController:(id)controller;
//-(BOOL)_isNavigationBarVisible;
//-(BOOL)_hasTranslucentNavigationBarIncludingViewController:(id)controller;
//-(void)_restoreOriginalInsetAndOffsetToScrollView:(id)scrollView;
//-(void)_applyScrollContentOffsetDelta:(float)delta toScrollView:(id)scrollView;
//-(void)_applyScrollContentInsetDelta:(UIEdgeInsets)delta toScrollView:(id)scrollView;
//-(void)_updateLayoutForStatusBarAndInterfaceOrientation;
//-(void)_updateBarsForCurrentInterfaceOrientation;
//-(BOOL)wasLastOperationAnimated;
//-(int)lastOperation;
//-(void)setNeedsDeferredTransition;
//-(BOOL)isCustomTransition;
//-(double)navigationTransitionView:(id)view durationForTransition:(int)transition;
//-(void)navigationTransitionView:(id)view didCancelTransition:(int)transition fromView:(id)view3 toView:(id)view4 wrapperView:(id)view5;
//-(void)navigationTransitionView:(id)view didEndTransition:(int)transition fromView:(id)view3 toView:(id)view4;
//-(void)navigationTransitionView:(id)view didStartTransition:(int)transition;
//-(BOOL)_isTransitioning;
//-(void)didShowViewController:(id)controller animated:(BOOL)animated;
//-(void)willShowViewController:(id)controller animated:(BOOL)animated;
//-(id)defaultFirstResponder;
//-(id)segueForUnwindingToViewController:(id)viewController fromViewController:(id)viewController2 identifier:(id)identifier;
//-(id)viewControllerForUnwindSegueAction:(SEL)unwindSegueAction fromViewController:(id)viewController withSender:(id)sender;
//-(BOOL)_reallyWantsFullScreenLayout;
//-(void)_updateToolbarItemsFromViewController:(id)viewController animated:(BOOL)animated;
//-(BOOL)editing;
//-(void)setEditing:(BOOL)editing animated:(BOOL)animated;
//-(void)viewDidUnload;
//-(void)purgeMemoryForReason:(int)reason;
//-(void)viewDidDisappear:(BOOL)view;
//-(void)viewWillDisappear:(BOOL)view;
//-(id)_viewControllerForDisappearCallback;
//-(void)viewDidAppear:(BOOL)view;
//-(void)viewDidMoveToWindow:(id)view shouldAppearOrDisappear:(BOOL)disappear;
//-(void)viewWillAppear:(BOOL)view;
//-(BOOL)isShown;
//-(void)loadView;
//-(void)_hideShowToolbarDidStop:(id)_hideShowToolbar finished:(id)finished context:(void*)context;
//-(void)_setToolbarHidden:(BOOL)hidden edge:(int)edge duration:(double)duration;
//-(void)_positionToolbarHidden:(BOOL)hidden edge:(int)edge;
//-(void)_positionToolbarHidden:(BOOL)hidden;
//-(void)setToolbarHidden:(BOOL)hidden animated:(BOOL)animated;
//-(void)setToolbar:(id)toolbar;
//-(void)_configureToolbar;
//-(id)_existingToolbar;
//-(void)_sendNavigationBarToBack;
//-(void)setSearchBarHidNavBar:(BOOL)bar;
//-(BOOL)searchBarHidNavBar;
//-(void)_hideShowNavigationBarDidStop:(id)_hideShowNavigationBar finished:(id)finished context:(void*)context;
//-(void)_setNavigationBarHidden:(BOOL)hidden edge:(int)edge duration:(double)duration;
//-(void)_positionNavigationBarHidden:(BOOL)hidden edge:(int)edge;
//-(void)_positionNavigationBarHidden:(BOOL)hidden;
//-(void)_setNavigationBarHidden:(BOOL)hidden edgeIfNotNavigating:(int)navigating duration:(double)duration;
//-(void)setNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated;
//-(BOOL)_animationParametersForHidingNavigationBar:(BOOL)hidingNavigationBar lastOperation:(int)operation edge:(int*)edge duration:(double*)duration;
//-(void)setNavigationBar:(id)bar;
//-(void)setNavigationBarClass:(Class)aClass;
//-(Class)navigationBarClass;
//-(void)_startCustomTransitionFromViewController:(id)viewController toViewController:(id)viewController2 transitionController:(id)controller;
//-(void)_cancelInteractiveTransition:(float)transition;
//-(void)_finishInteractiveTransition:(float)transition;
//-(void)_updateInteractiveTransition:(float)transition;
//-(void)_setContentInset:(UIEdgeInsets)inset;
//-(void)_setClipsToBounds:(BOOL)bounds;
//-(void)_setViewControllers:(id)controllers transition:(int)transition;
//-(id)_navigationItems;
//-(void)setViewControllers:(id)controllers animated:(BOOL)animated;
//-(int)_transitionForOldViewControllers:(id)oldViewControllers newViewControllers:(id)controllers;
//-(BOOL)_isPresentationContextByDefault;
//-(int)modalTransitionStyle;
//-(void)dealloc;
//-(void)_releaseContainerViews;
//-(void)encodeWithCoder:(id)coder;
//-(BOOL)_shouldPersistViewWhenCoding;
//-(id)initWithCoder:(id)coder;
//-(id)initWithNibName:(id)nibName bundle:(id)bundle;
//-(id)initWithNavigationBarClass:(Class)navigationBarClass toolbarClass:(Class)aClass;
//-(id)initWithRootViewController:(id)rootViewController;
//-(void)decodeRestorableStateWithCoder:(id)coder;
//-(void)encodeRestorableStateWithCoder:(id)coder;
//@end
//
