#pragma once
#include <memory_resource>
#include <map>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
private:
    void* buffer;
    std::size_t totalSize;
    std::size_t used;

    std::multimap<size_t, void*> freeBlocks;
    std::map<void*, size_t> usedBlocks;

protected:
    void* do_allocate(size_t bytes, size_t alignment) override;
    void do_deallocate(void* p, size_t bytes, size_t alignment) override;
    bool do_is_equal(const memory_resource& other) const noexcept override;

public:
    explicit FixedBlockMemoryResource(size_t size);
    ~FixedBlockMemoryResource();
};