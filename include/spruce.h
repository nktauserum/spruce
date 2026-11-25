#pragma once

#include <atomic>

namespace spruce {
    namespace {
        struct bitmap {
        private:
            alignas(64) uint64_t array;
        public:
            uint32_t acquire();
            void     release(uint32_t);
            
            bitmap();
        };
    }

    template <typename type>
    class Pool {
    private:
        alignas(64) int     size;
        alignas(64) bitmap* set;
        alignas(64) type*   data;

    public:
        uint32_t Acquire(int);
        void     Release(uint32_t);
        type*    Reach  (uint32_t);

        Pool(int);
        ~Pool();
    };
}
