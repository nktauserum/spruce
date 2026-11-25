#include "../include/spruce.h"
using namespace spruce;

#include <immintrin.h>

template <typename type>
uint32_t bitmap<type>::acquire() {
    while (true) {
        uint64_t b = __atomic_load_n(&array, __ATOMIC_RELAXED);
        if (b != 0) {
            uint64_t offset = _mm_tzcnt_64(b);
            
            if (__atomic_compare_exchange_n(
                &array, &b,
                b^(1 << offset), false,
                __ATOMIC_ACQUIRE, __ATOMIC_RELAXED
            )) 
                return offset;
        }

        _mm_pause();
    }
}

template <typename type>
void bitmap<type>::release(uint32_t idx) {
    __atomic_or_fetch(&array, (1 << idx), __ATOMIC_RELEASE);
}

