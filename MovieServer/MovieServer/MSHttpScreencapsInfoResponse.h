//
//  MSHttpScreencapsInfoResponse.h
//  MovieServer
//
//  Created by Curtis Jones on 2012.12.16.
//  Copyright (c) 2012 Curtis Jones. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSHttpResponse.h"

@interface MSHttpScreencapsInfoResponse : MSHttpResponse

+ (MSHttpResponse *)responseWithPath:(NSString *)filePath andFiles:(NSArray *)files forConnection:(HTTPConnection *)connection;

@end
