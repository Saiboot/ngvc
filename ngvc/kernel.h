#ifndef __KERNEL_H
#define __KERNEL_H

#define MODE_SHORT	// Current operating system mode

#if defined(MODE_SHORT)
  #define __NGVC8__
#elif defined(MODE_PROTECTED)
  #define __NGVC32__
#endif

#endif //!__KERNEL_H
