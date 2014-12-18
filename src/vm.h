//
//  vm.h
//  
//
//  Created by James Spann on 3/4/14.
//
//

#ifndef _vm_h
#define _vm_h
//int fileLog;//A flag for logging output to a file. 1 for one 0 for off

void badhalt(std::string reason);

#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#define S_TARGET_ARCH_X86 1
#elif defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || \
defined(_M_AMD64)
#define S_TARGET_ARCH_X64 1
#elif defined(__arm__) || defined(__arm) || defined(__ARM__) || defined(__ARM)
#define S_TARGET_ARCH_ARM 1
// #elif defined(__ppc__) || defined(__ppc) || defined(__PPC__) || \
//       defined(__PPC) || defined(__powerpc__) || defined(__powerpc) || \
//       defined(__POWERPC__) || defined(__POWERPC) || defined(_M_PPC)
//   #ifdef __NO_FPRS__
//     #define S_TARGET_ARCH_PPCSPE 1
//   #else
//     #define S_TARGET_ARCH_PPC 1
//   #endif
// #elif defined(__mips__) || defined(__mips) || defined(__MIPS__) || \
//       defined(__MIPS)
//   #define S_TARGET_ARCH_MIPS 1
#else
#error "Unsupported target architecture"
#endif

#endif
