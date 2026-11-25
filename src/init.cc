#include "../include/spruce.h"
using namespace spruce;

template <typename type>
Pool<type>::Pool(int size) : set{new bitmap<type>[size]}, size{size} {}

template <typename type>
Pool<type>::~Pool() {
    delete[] set;
}

template <typename type>
bitmap<type>::bitmap() : array{static_cast<uint64_t>(~0)}, data{new type[64]} {}

template <typename type>
bitmap<type>::~bitmap() {
    delete[] data;
}
