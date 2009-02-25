/* 
 * CFLog is a singleton logging object for more powerful logging in your cocoa projects
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
 *
 * CFLog.h
 * 
 * Created by Camron Flanders on 2.23.09
 * Copyright 2009 camronflanders. All rights reserved.
 * 
 */

#import <Foundation/Foundation.h>

/* ****** CFLog CONFIGURATION ****** */
#define GLOBAL_SOFT_ENABLE	YES			// turn logging on or off, globally, allowing overrides
#define LOG_LEVEL			5			// 0-5, this defines what levels to actually display.

#define USE_NSLOG			NO			// If no, we use printf. printf won't pollute your
										// console/system.logs, is bit less expensive to call
										// but won't output Project name, time, thread.

// output configuration
#define BARE_OUTPUT			NO			// if YES, disables all verbose information
#define LOG_SEVERITY		YES			// if NO, severity level won't be output
#define LOG_PATH            YES         // if NO, no path (full or partial) will be output
#define LOG_FULL_PATH		NO			// if NO, outputs just filename. YES, output abs path
#define LOG_LINE_NUM        YES         // if YES, line number of log statment will be output
#define LOG_FUNC_NAME       YES         // if YES, function containing log will be output 


#define DISABLE_NSLOG_WITH_CFLOG	1	// 0 or 1 (NO / YES).
										// If 1 (YES) and _CFLOG_ENABLED is not defined, 
										// NSLog statements will also be disabled.

/* ****** END CONFIGURATION ******* */


// functions
#ifdef _CFLOG_ENABLED
#define cfLog(level, override, format,...) [[CFLog sharedDebug] log:(level) overrideGlobal:(override) fileName:__FILE__ lineNumber:__LINE__ functionName:__PRETTY_FUNCTION__ input:(format), ##__VA_ARGS__]

// convenience functions
#define cfDebug(format,...)     [[CFLog sharedDebug] log:5 overrideGlobal:NO fileName:__FILE__ lineNumber:__LINE__ functionName:__PRETTY_FUNCTION__ input:(format), ##__VA_ARGS__]
#define cfInfo(format,...)      [[CFLog sharedDebug] log:4 overrideGlobal:NO fileName:__FILE__ lineNumber:__LINE__ functionName:__PRETTY_FUNCTION__ input:(format), ##__VA_ARGS__]
#define cfWarning(format,...)   [[CFLog sharedDebug] log:3 overrideGlobal:NO fileName:__FILE__ lineNumber:__LINE__ functionName:__PRETTY_FUNCTION__ input:(format), ##__VA_ARGS__]
#define cfError(format,...)     [[CFLog sharedDebug] log:2 overrideGlobal:NO fileName:__FILE__ lineNumber:__LINE__ functionName:__PRETTY_FUNCTION__ input:(format), ##__VA_ARGS__]
#define cfCritical(format,...)  [[CFLog sharedDebug] log:1 overrideGlobal:NO fileName:__FILE__ lineNumber:__LINE__ functionName:__PRETTY_FUNCTION__ input:(format), ##__VA_ARGS__]
#define cfBlank()				[[CFLog sharedDebug] blankLine]

#else
// clear all functions so we don't waste any processing overhead while not in DEBUG
#define cfLog(level, override, format,...)
#define cfDebug(format,...)
#define cfInfo(format,...)
#define cfWarning(format,...)
#define cfError(format,...)
#define cfCritical(format,...)
#define cfBlank()
// if we are disabling nslog too, kill it.
#if DISABLE_NSLOG_WITH_CFLOG
#define NSLog(format, ...)
#endif
#endif



@interface CFLog : NSObject {
}

+ (CFLog *)sharedDebug;

- (void)log:(int)severity overrideGlobal:(BOOL)override fileName:(char *)file lineNumber:(int)line functionName:(const char *)function input:(NSString *)message, ...;
- (void)blankLine;
@end
