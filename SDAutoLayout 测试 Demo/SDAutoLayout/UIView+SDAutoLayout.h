//
//  UIView+SDAutoLayout.h
//
//  Created by gsd on 15/10/6.
//  Copyright (c) 2015年 gsd. All rights reserved.
//

/*
 *************************************************************************
 
 --------- INTRODUCTION ---------
 
 HOW TO USE ?
 
 MODE 1. >>>>>>>>>>>>>>> You can use it in this way:
 
 Demo.sd_layout
 .topSpaceToView(v1, 100)
 .bottomSpaceToView(v3, 100)
 .leftSpaceToView(v0, 150)
 .rightSpaceToView(v2, 150);
 
 MODE 2. >>>>>>>>>>>>>>> You can also use it in this way that is more brevity:
 
 Demo.sd_layout.topSpaceToView(v1, 100).bottomSpaceToView(v3, 100).leftSpaceToView(v0, 150).rightSpaceToView(v2, 150);
 
 
 *************************************************************************
 */


/*
 
 *********************************************************************************
 *
 * 在您使用此自动布局库的过程中如果出现bug请及时以以下任意一种方式联系我们，我们会及时修复bug并
 * 帮您解决问题。
 * QQ    : 2689718696(gsdios)
 * Email : gsdios@126.com
 * GitHub: https://github.com/gsdios
 * 新浪微博:GSD_iOS
 *
 * 视频教程：http://www.letv.com/ptv/vplay/24038772.html
 * 用法示例：https://github.com/gsdios/SDAutoLayout/blob/master/README.md
 *
 *********************************************************************************
 
 */

#import <UIKit/UIKit.h>

@class SDAutoLayoutModel;

typedef SDAutoLayoutModel *(^MarginToView)(UIView *toView, CGFloat value);
typedef SDAutoLayoutModel *(^Margin)(CGFloat value);
typedef SDAutoLayoutModel *(^MarginEqualToView)(UIView *toView);
typedef SDAutoLayoutModel *(^WidthHeight)(CGFloat value);
typedef SDAutoLayoutModel *(^WidthHeightEqualToView)(UIView *toView, CGFloat ratioValue);
typedef SDAutoLayoutModel *(^AutoHeight)(CGFloat ratioValue);
typedef void (^SpaceToSuperView)(UIEdgeInsets insets);

@interface SDAutoLayoutModel : NSObject

/*
 *************************说明************************
 
 方法名中带有“SpaceToView”的需要传递2个参数：（UIView）参照view 和 （CGFloat）间距数值
 方法名中带有“RatioToView”的需要传递2个参数：（UIView）参照view 和 （CGFloat）倍数
 方法名中带有“EqualToView”的需要传递1个参数：（UIView）参照view
 方法名中带有“Is”的需要传递1个参数：（CGFloat）数值
 
 *****************************************************
 */

/* 设置距离其它view的间距 */

/** 左边到其参照view之间的间距，参数为“(参照view，间距数值)”  */
@property (nonatomic, copy, readonly) MarginToView leftSpaceToView;
/** 右边到其参照view之间的间距，参数为“(参照view，间距数值)”  */
@property (nonatomic, copy, readonly) MarginToView rightSpaceToView;
/** 顶部到其参照view之间的间距，参数为“(参照view，间距数值)”  */
@property (nonatomic, copy, readonly) MarginToView topSpaceToView;
/** 底部到其参照view之间的间距，参数为“(参照view，间距数值)”  */
@property (nonatomic, copy, readonly) MarginToView bottomSpaceToView;



/* 设置x、y、width、height、centerX、centerY 值 */

/** x值  */
@property (nonatomic, copy, readonly) Margin xIs;
/** y值  */
@property (nonatomic, copy, readonly) Margin yIs;
/** centerX值  */
@property (nonatomic, copy, readonly) Margin centerXIs;
/** centerY值  */
@property (nonatomic, copy, readonly) Margin centerYIs;
/** 宽度值  */
@property (nonatomic, copy, readonly) WidthHeight widthIs;
/** 高度值  */
@property (nonatomic, copy, readonly) WidthHeight heightIs;


/* 设置最大宽度和高度、最小宽度和高度 */

/** 最大宽度值  */
@property (nonatomic, copy, readonly) WidthHeight maxWidthIs;
/** 最大高度值  */
@property (nonatomic, copy, readonly) WidthHeight maxHeightIs;
/** 最小宽度值  */
@property (nonatomic, copy, readonly) WidthHeight minWidthIs;
/** 最小高度值  */
@property (nonatomic, copy, readonly) WidthHeight minHeightIs;


/*
 *  设置和哪一个参照view的边距相同
 */

/** 左间距与参照view相同  */
@property (nonatomic, copy, readonly) MarginEqualToView leftEqualToView;
/** 右间距与参照view相同  */
@property (nonatomic, copy, readonly) MarginEqualToView rightEqualToView;
/** 顶部间距与参照view相同  */
@property (nonatomic, copy, readonly) MarginEqualToView topEqualToView;
/** 底部间距与参照view相同  */
@property (nonatomic, copy, readonly) MarginEqualToView bottomEqualToView;
/** centerX与参照view相同  */
@property (nonatomic, copy, readonly) MarginEqualToView centerXEqualToView;
/** centerY与参照view相同  */
@property (nonatomic, copy, readonly) MarginEqualToView centerYEqualToView;


/*  设置宽度或者高度等于参照view的多少倍 */

/** 宽度是参照view宽度的多少倍 */
@property (nonatomic, copy, readonly) WidthHeightEqualToView widthRatioToView;
/** 高度是参照view宽度的多少倍 */
@property (nonatomic, copy, readonly) WidthHeightEqualToView heightRatioToView;
/** 自适应高度，传入高宽比值，label可以传0实现文字高度自适应 */
@property (nonatomic, copy, readonly) AutoHeight autoHeightRatio;

/* 填充父view(快捷方法) */

/** 传入UIEdgeInsetsMake(top, left, bottom, right)，可以快捷设置view到其父view上左下右的间距  */
@property (nonatomic, copy, readonly) SpaceToSuperView spaceToSuperView;

@property (nonatomic, weak) UIView *needsAutoResizeView;

@end




@interface UIView (SDAutoHeight)

@property (nonatomic) CGFloat autoHeight;

@property (nonatomic) UIView *sd_bottomView;
@property (nonatomic) CGFloat sd_bottomViewBottomMargin;

/** 设置Cell的高度自适应，也可用于设置普通view内容自适应 */
- (void)setupAutoHeightWithBottomView:(UIView *)bottomView bottomMargin:(CGFloat)bottomMargin;

@end

@interface UIView (SDLayoutExtention)

/* 设置圆角 */

/** 设置圆角半径值  */
@property (nonatomic, strong) NSNumber *sd_cornerRadius;
/** 设置圆角半径值为view宽度的多少倍  */
@property (nonatomic, strong) NSNumber *sd_cornerRadiusFromWidthRatio;
/** 设置圆角半径值为view高度的多少倍  */
@property (nonatomic, strong) NSNumber *sd_cornerRadiusFromHeightRatio;

/** 设置等宽子view（子view需要在同一水平方向） */
@property (nonatomic, strong) NSArray *sd_equalWidthSubviews;

@end


@interface UIScrollView (SDAutoContentSize)

/** 设置scrollview内容自适应 */
- (void)setupAutoContentSizeWithBottomView:(UIView *)bottomView bottomMargin:(CGFloat)bottomMargin;

@end


@interface UILabel (SDLabelAutoResize)

/** 设置单行文本label宽度自适应 */
- (void)setSingleLineAutoResizeWithMaxWidth:(CGFloat)maxWidth;

@end



































// ----------------- 以下为此库内部需要用到的类和方法（可以不用看）----------------

@interface SDAutoLayoutModelItem : NSObject

@property (nonatomic, strong) NSNumber *value;
@property (nonatomic, weak) UIView *refView;

@end

@interface UIView (SDAutoLayout)

- (NSMutableArray *)autoLayoutModelsArray;

/** 开始自动布局  */
- (SDAutoLayoutModel *)sd_layout;

/** 清空之前的自动布局设置，重新开始自动布局  */
- (SDAutoLayoutModel *)sd_resetLayout;

- (void)addAutoLayoutModel:(SDAutoLayoutModel *)model;

@property (nonatomic, strong) NSNumber *fixedWith;
@property (nonatomic, strong) NSNumber *fixedHeight;

@property (nonatomic, strong) NSNumber *sd_maxWidth;

@property (nonatomic, strong) NSNumber *autoHeightRatioValue;

@end


@interface UIView (SDChangeFrame)

@property (nonatomic) CGFloat left;
@property (nonatomic) CGFloat top;
@property (nonatomic) CGFloat right;
@property (nonatomic) CGFloat bottom;
@property (nonatomic) CGFloat centerX;
@property (nonatomic) CGFloat centerY;

@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat height;


@property (nonatomic) CGPoint origin;
@property (nonatomic) CGSize size;

@end

