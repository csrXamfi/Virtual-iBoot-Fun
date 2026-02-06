//
//  VZPrivate.h
//  virtualization_test
//
//  Created by noone on 12/4/21.
//

/*
 * This file defines interfaces/extensions
 * needed to access private parts of
 * Virtualization framework's API
 */

#ifndef VZPrivate_h
#define VZPrivate_h

#import <Foundation/Foundation.h>
#import <Virtualization/Virtualization.h>

/*
 * Start options. The old _VZVirtualMachineStartOptions was removed.
 * Now VZMacOSVirtualMachineStartOptions is public (since macOS 13),
 * but forceDFU / stopInIBoot are still private category methods.
 *
 * startWithOptions:completionHandler: is now a public method on
 * VZVirtualMachine, so no category extension is needed for it.
 */

@interface VZMacOSVirtualMachineStartOptions(VZPrivate)
- (void)_setForceDFU:(BOOL)forceDFU;
- (BOOL)_forceDFU;
- (void)_setStopInIBootStage1:(BOOL)stop;
- (BOOL)_stopInIBootStage1;
- (void)_setStopInIBootStage2:(BOOL)stop;
- (BOOL)_stopInIBootStage2;
@end


/*
 * Extension for VZMacPlatformConfiguration,
 * needed for _setProductionModeEnabled:.
 * Makes it run with CPFM:01 (no production fuse)
 */

@interface VZMacPlatformConfiguration()
- (void)_setProductionModeEnabled:(BOOL)enabled;
@end


/*
 * Interface for _VZGDBDebugStubConfiguration,
 * needed for debug server. Just need port
 * property here
 */

@interface _VZGDBDebugStubConfiguration : NSObject <NSCopying>
@property NSInteger port;
@end


/*
 * Extension for VZVirtualMachineConfiguration,
 * needed for _setDebugStub:, which enables
 * GDB server on the requested port
 */

@interface VZVirtualMachineConfiguration()
- (void)_setDebugStub:(_VZGDBDebugStubConfiguration *_Nonnull)config;
@end


/*
 * Extension for VZMacOSBootLoader,
 * needed for _setROMURL:, which
 * allows to pass custom ROM (AVPBooter)
 */

@interface VZMacOSBootLoader()
- (void)_setROMURL:(NSURL *_Nonnull)url;
- (NSURL *_Nullable)_romURL;
@end


/*
 * Interface for _VZPL011SerialPortConfiguration,
 * needed for getting serial output from iBoot,
 * since PL011 is the one used as debug UART port
 */

@interface _VZPL011SerialPortConfiguration : VZSerialPortConfiguration
- (instancetype _Nonnull)init;
@end


#endif /* VZPrivate_h */
