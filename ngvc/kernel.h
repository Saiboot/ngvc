#ifndef __KERNEL_H
#define __KERNEL_H

#define MODE_SHORT	// Current operating system mode

#if defined(MODE_SHORT)
  #define __NGVC8__
#elif defined(MODE_REAL)
  #define __NGVC16__
#endif

#endif //!__KERNEL_H
