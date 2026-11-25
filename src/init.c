#include "../include/spruce.h"

#include <stdlib.h>

int spruce_init(spruce_pool* pool, size_t set, size_t item) {
    pool->size = set;
    pool->set = (__spruce_bitmap*)calloc(set, sizeof(__spruce_bitmap));
    if (!pool->set)
        return 0;

    for (int i = 0; i < set; ++i) {
        pool->set[i].data = calloc(64, item);
        if (!pool->set[i].data)
            return 0;

        pool->set[i].array = ~0;
    }

    return 1;
}
