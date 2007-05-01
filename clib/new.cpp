#include <cstdio>
#include <cstdlib>

//#define USE_MY_NEW
#ifdef USE_MY_NEW

void* operator new(size_t sz) {
  static unsigned int k = 40503;
  void* m = malloc(sz);
  unsigned int c = (unsigned) m;
  c = (c >> 16) ^ (c & 0xffff);
  unsigned int h = ((c * k) >> (16-10)) & 1023);
  printf("operator new: %d Bytes at %p, hash: %u\n", sz, m, h);
  if(!m) { puts("out of memory"); exit(1); }
  return m;
  /*
   * other: x[n] = a*x[n-1] mod p
   * a = 3355703948966806692
   * p = 2^62-2^16+1
   * */
}

/*
 * k = 10 # M==1024
w = 32
mask = (1 << k) - 1
a = 2654435769L

def h(x):
    return ((x * a) >> (w - k)) & mask
*/

void operator delete(void* m) {
  puts("operator delete");
  free(m);
}

#endif
