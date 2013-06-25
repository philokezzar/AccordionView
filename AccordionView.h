/*
 AccordionView.h
 
 Created by Wojtek Siudzinski on 19.12.2011.
 Copyright (c) 2011 Appsome. All rights reserved.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <UIKit/UIKit.h>

@class AccordionView;
@protocol AccordionViewDelegate <NSObject>
@optional
- (void)accordion:(AccordionView *)accordion didChangeSelection:(NSIndexSet *)selection;
@end

@interface AccordionView : UIView <UIScrollViewDelegate> {
    NSMutableArray *views;
    NSMutableArray *headers;
    NSMutableArray *originalSizes;
    
    UIScrollView *scrollView;
}

- (void)addHeader:(id)aHeader withView:(id)aView;
- (void)setOriginalSize:(CGSize)size forIndex:(NSUInteger)index;
- (void)scrollViewDidScroll:(UIScrollView *)aScrollView;

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) NSMutableArray *views;
@property (nonatomic, strong) NSMutableArray *headers;
@property (nonatomic, strong) NSMutableArray *originalSizes;

@property (nonatomic, assign) NSInteger selectedIndex;
@property (readonly) BOOL isHorizontal;
@property (nonatomic, assign) NSTimeInterval animationDuration;
@property (nonatomic, assign) UIViewAnimationCurve animationCurve;
@property (nonatomic, assign) BOOL allowsMultipleSelection;
@property (nonatomic, assign) BOOL allowsUITableSectionStyle;
@property (nonatomic, strong) NSIndexSet *selectionIndexes;
@property (nonatomic, strong) id <AccordionViewDelegate> delegate;

@property BOOL openFirstIndex;  // to have flexibility of not opening 1st tab as default. by default is TRUE

@end