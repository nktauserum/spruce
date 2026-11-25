#include "../include/spruce.h"
using namespace spruce;

template <typename type>
Pool<type>::Pool(int size) : set{new bitmap[size]}, data{new type[size*64]}, size{size} {}

template <typename type>
Pool<type>::~Pool() {
    delete[] set;
    delete[] data;
}

bitmap::bitmap() : array{static_cast<uint64_t>(~0)} {}
