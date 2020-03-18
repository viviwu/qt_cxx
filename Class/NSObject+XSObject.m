//
//  NSObject+XSObject.m
//  XBase
//
//  Created by vivi wu on 2020/3/16.
//  Copyright © 2020 vivi wu. All rights reserved.
//

#import "NSObject+XSObject.h"

//#import <AppKit/AppKit.h>


@implementation NSObject (XSObject)

- (void)introSelf{
  NSLog(@"%@\n%@", self,  self.description);
}

@end
