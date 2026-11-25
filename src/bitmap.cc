#include "../include/spruce.h"
using namespace spruce;

inline uint32_t bitmap_acquire();
inline void     bitmap_release();

template <typename type>
uint32_t bitmap<type>::acquire() {
    return bitmap_acquire();
}
