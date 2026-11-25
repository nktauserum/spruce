#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdalign.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    alignas(64) uint64_t array;
    alignas(64) void*    data;
} __spruce_bitmap;

typedef struct {
    alignas(64) int              size;
    alignas(64) __spruce_bitmap* set;
} spruce_pool;

int      spruce_init (spruce_pool*, size_t, size_t);
void     spruce_clean(spruce_pool*);

uint32_t spruce_acquire(spruce_pool*, int);
void     spruce_release(spruce_pool*, uint32_t);
void*    spruce_get    (spruce_pool*, uint32_t);

#ifdef __cplusplus
}
#endif
