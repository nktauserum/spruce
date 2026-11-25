#pragma once

#include <atomic>

namespace spruce {
    namespace {
        template <typename type>
        struct bitmap {
        private:
            alignas(64) uint64_t array;
        public:
            alignas(64) type*   data;

            uint32_t acquire();
            void     release(uint32_t);
            
            bitmap();
            ~bitmap();
        };
    }

    template <typename type>
    class Pool {
    private:
        alignas(64) int           size;
        alignas(64) bitmap<type>* set;

    public:
        uint32_t Acquire(int);
        void     Release(uint32_t);
        type*    Reach  (uint32_t);

        Pool(int);
        ~Pool();
    };
}
