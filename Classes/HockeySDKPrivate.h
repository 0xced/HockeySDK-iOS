/*
 * Author: Andreas Linde <mail@andreaslinde.de>
 *         Kent Sutherland
 *
 * Copyright (c) 2012 HockeyApp, Bit Stadium GmbH.
 * Copyright (c) 2011 Andreas Linde & Kent Sutherland.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */


#import <Foundation/Foundation.h>

#ifndef HockeySDK_HockeySDKPrivate_h
#define HockeySDK_HockeySDKPrivate_h

#define BITHOCKEYSDK_NAME @"HockeySDK"
#define BITHOCKEYSDK_VERSION @"2.3.0-dev"

#define kBITUpdateArrayOfLastCheck					@"BITUpdateArrayOfLastCheck"
#define kBITUpdateDateOfLastCheck						@"BITUpdateDateOfLastCheck"
#define kBITUpdateDateOfVersionInstallation	@"BITUpdateDateOfVersionInstallation"
#define kBITUpdateUsageTimeOfCurrentVersion	@"BITUpdateUsageTimeOfCurrentVersion"
#define kBITUpdateUsageTimeForVersionString	@"BITUpdateUsageTimeForVersionString"
#define kBITUpdateAuthorizedVersion					@"BITUpdateAuthorizedVersion"
#define kBITUpdateAuthorizedToken						@"BITUpdateAuthorizedToken"

#define BITHOCKEYSDK_BUNDLE @"HockeySDKResources"
#define BITHOCKEYSDK_URL @"https://sdk.hockeyapp.net/"

#define BITHockeyLog(fmt, ...) do { if([BITHockeyManager sharedHockeyManager].isDebugLogEnabled && ![BITHockeyManager sharedHockeyManager].isAppStoreEnvironment) { NSLog((@"[HockeySDK] %s/%d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__); }} while(0)

NSBundle *BITHockeyBundle(void);
NSString *BITHockeyLocalizedString(NSString *stringToken);
NSString *BITHockeyMD5(NSString *str);


// compatibility helper
#ifdef BITHOCKEYSDK_STATIC_LIBRARY
// If HockeySDK is built as a static library and linked into the project
// we can't use this project's deployment target to statically decide if
// native JSON is available
#define BITHOCKEYSDK_NATIVE_JSON_AVAILABLE 0
#else
#define BITHOCKEYSDK_NATIVE_JSON_AVAILABLE __IPHONE_OS_VERSION_MIN_REQUIRED >= 50000
#endif



#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_5_0
#define kCFCoreFoundationVersionNumber_iPhoneOS_5_0 674.0
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 50000
#define BITHOCKEYSDK_IF_IOS5_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iPhoneOS_5_0) \
{ \
__VA_ARGS__ \
}
#else
#define BITHOCKEYSDK_IF_IOS5_OR_GREATER(...)
#endif

#define BITHOCKEYSDK_IF_PRE_IOS5(...)  \
if (kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_iPhoneOS_5_0)  \
{ \
__VA_ARGS__ \
}


#endif
