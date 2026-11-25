#include "../include/spruce.h"
using namespace spruce;

template <typename type>
uint32_t Pool<type>::Acquire(int hint) {
   int h = hint % size; 
   return set[h].acquire() | (h << 16);
}

template <typename type>
void Pool<type>::Release(uint32_t idx) {
    set[idx >> 16].release(idx & 0x0000FFFF);
}

template <typename type>
type* Pool<type>::Reach(uint32_t idx) {
    return &set[idx >> 16].data[idx & 0x0000FFFF];
}
