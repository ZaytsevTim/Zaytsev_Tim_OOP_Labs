#pragma once
#include <memory_resource>
#include <cassert>
#include <utility>
#include <type_traits>
#include <memory>

template<typename T>
class PmrList {
    struct Node {
        T value;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    std::pmr::polymorphic_allocator<Node> alloc;

public:
    explicit PmrList(std::pmr::memory_resource* res)
        : alloc(res) {}

    ~PmrList() {
        clear();
    }

    void push_back(const T& v) {
        Node* n = alloc.allocate(1);
        std::allocator_traits<decltype(alloc)>::construct(alloc, n);

        n->value = v;
        n->prev = tail;
        n->next = nullptr;

        if (tail) tail->next = n;
        else head = n;

        tail = n;
    }

    void push_front(const T& v) {
        Node* n = alloc.allocate(1);
        std::allocator_traits<decltype(alloc)>::construct(alloc, n);

        n->value = v;
        n->next = head;
        n->prev = nullptr;

        if (head) head->prev = n;
        else tail = n;

        head = n;
    }

    void erase(Node* n) {
        assert(n);

        if (n->prev) n->prev->next = n->next;
        else head = n->next;

        if (n->next) n->next->prev = n->prev;
        else tail = n->prev;

        std::allocator_traits<decltype(alloc)>::destroy(alloc, n);
        alloc.deallocate(n, 1);
    }

    void clear() {
        Node* p = head;
        while (p) {
            Node* next = p->next;

            std::allocator_traits<decltype(alloc)>::destroy(alloc, p);
            alloc.deallocate(p, 1);

            p = next;
        }
        head = tail = nullptr;
    }

    class Iterator {
        Node* ptr;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iterator(Node* p) : ptr(p) {}

        reference operator*() const { return ptr->value; }
        pointer operator->() const { return &ptr->value; }

        Iterator& operator++() { 
            ptr = ptr->next; 
            return *this; 
        }
        
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Iterator& operator--() { 
            ptr = ptr->prev; 
            return *this; 
        }
        
        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }

        Node* node() const { return ptr; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    Iterator rbegin() { return Iterator(tail); }
    Iterator rend() { return Iterator(nullptr); }

    Node* front_node() const { return head; }
    Node* back_node() const { return tail; }
};