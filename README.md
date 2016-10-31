# Singleton
最完整的单例宏<br/>
支持ARC和非ARC,使用时只需要传入类名就可以为该类生成单例<br>
<br>
使用方法<br>
1.在类的头文件中引入GSWWSingleton.h,如下：<br>
```objective-c
#import <Foundation/Foundation.h>
#import "GSWWSingleton.h"

@interface YourClassName : NSObject

singleton_interface(YourClassName)

@end
```
2.在类的implementation中写法如下：<br>
```objective-c
@implementation YourClassName

singleton_implementation(YourClassName)

@end
```
3.在其他类中用YourClassName创建单例对象，如下：<br>
```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
    
    YourClassName *obj1 = [YourClassName sharedYourClassName];
    NSLog(@"%@", obj1);
}
```

