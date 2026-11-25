#include "../include/spruce.h"

#include <immintrin.h>

static uint32_t __bitmap_acquire(__spruce_bitmap* bitmap) {
    while (1) {
        uint64_t b = __atomic_load_n(&bitmap->array, __ATOMIC_RELAXED);
        if (b != 0) {
            uint64_t offset = __builtin_ctzll(b);
            
            if (__atomic_compare_exchange_n(
                &bitmap->array, &b,
                b^(1 << offset), 0,
                __ATOMIC_ACQUIRE, __ATOMIC_RELAXED
            )) 
                return offset;
        }

        _mm_pause();
    }
}

static void __bitmap_release(__spruce_bitmap* bitmap, uint32_t idx) {
    __atomic_or_fetch(&bitmap->array, (1 << idx), __ATOMIC_RELEASE);
}

uint32_t spruce_acquire(spruce_pool* pool, int hint) {
    int h = hint % pool->size; 
    return __bitmap_acquire(&pool->set[h]) | (h << 16);
}

void spruce_release(spruce_pool* pool, uint32_t idx) {
    __bitmap_release(&pool->set[idx >> 16], idx & 0x0000FFFF);
}

void* spruce_get(spruce_pool* pool, uint32_t idx) {
    return &((unsigned char*)pool->set[idx >> 16].data)[idx & 0x0000FFFF];
}
