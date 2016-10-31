//
//  GSWWSingleton.h
//  通用单例宏
//
//  Created by chenwei on 2016/10/31.
//  Copyright © 2016年 gsww. All rights reserved.
//
/**
 *使用方式：
 *1.在需要创建单例的类中#import "GSWWSingleton.h"
 *2.在类的@interface部分添加：singleton_interface(className)
 *3.在类的@implementation部分添加：singleton_implementation(className)
 *calssName为需要创建单例的类名
 */

// @interface
#define singleton_interface(className) \
+ (className *)shared##className;

// @implementation
#if __has_feature(objc_arc) // 是ARC
#define singleton_implementation(className) \
static className *sharedSingleton = nil; \
+ (className *)shared##className  \
{  \
    return [[self alloc] init];  \
} \
+ (id)allocWithZone:(struct _NSZone *)zone \
{ \
    if (sharedSingleton == nil) { \
        static dispatch_once_t onceToken; \
        dispatch_once(&onceToken, ^{ \
            sharedSingleton = [super allocWithZone:zone]; \
        }); \
    } \
    return sharedSingleton; \
} \
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
    return sharedSingleton; \
} \
+ (id)mutableCopyWithZone:(struct _NSZone *)zone \
{ \
    return sharedSingleton; \
}
#else // 不是ARC
#define singleton_implementation(className) \
static className *sharedSingleton = nil; \
+ (className *)shared##className \
{ \
    return [[self alloc] init]; \
} \
 \
+ (id)allocWithZone:(struct _NSZone *)zone \
{ \
    if (sharedSingleton == nil) { \
        static dispatch_once_t onceToken; \
        dispatch_once(&onceToken, ^{ \
            sharedSingleton = [super allocWithZone:zone]; \
        }); \
    } \
    return sharedSingleton; \
} \
 \
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
    return sharedSingleton; \
} \
 \
+ (id)mutableCopyWithZone:(struct _NSZone *)zone \
{ \
    return sharedSingleton; \
} \
 \
- (oneway void)release \
{ \
     \
} \
\
- (NSUInteger)retainCount \
{ \
    return 1; \
} \
 \
- (instancetype)retain \
{ \
    return self; \
}
#endif

