#include "../include/MemoryResource.hpp"
#include <cstdlib>
#include <iostream>

FixedBlockMemoryResource::FixedBlockMemoryResource(size_t size)
    : totalSize(size), used(0)
{
    buffer = std::malloc(size);
    if (!buffer) throw std::bad_alloc();
}

FixedBlockMemoryResource::~FixedBlockMemoryResource() {
    std::free(buffer);
}

void* FixedBlockMemoryResource::do_allocate(size_t bytes, size_t alignment) {
    for (auto it = freeBlocks.lower_bound(bytes); it != freeBlocks.end(); ++it) {
        void* p = it->second;
        usedBlocks[p] = it->first;
        freeBlocks.erase(it);
        return p;
    }

    if (used + bytes > totalSize)
        throw std::bad_alloc();

    void* result = static_cast<char*>(buffer) + used;
    usedBlocks[result] = bytes;
    used += bytes;
    return result;
}

void FixedBlockMemoryResource::do_deallocate(void* p, size_t, size_t) {
    auto it = usedBlocks.find(p);
    if (it != usedBlocks.end()) {
        freeBlocks.insert({it->second, p});
        usedBlocks.erase(it);
    }
}

bool FixedBlockMemoryResource::do_is_equal(const memory_resource& other) const noexcept {
    return this == &other;
}