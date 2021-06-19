#ifndef _LIST_H
#define _LIST_H
#include <iostream>
#include <memory>
#include <initializer_list>
#include "helper_function.h"

namespace myList
{
template <typename T>
struct Node
{
    Node<T> *next{nullptr};
    T data{};
    Node<T>(const T &element, Node<T> *ptr = nullptr)
        : data{element}, next{ptr}
    {
    }
    Node<T>() = default;
};

template <typename T>
class singly_list
{
public:
    singly_list() = default;
    singly_list(const T &element);
    singly_list(const std::initializer_list<T>& element);
    singly_list(const singly_list<T> &obj);
    singly_list(singly_list<T> &&obj);
    singly_list &operator=(const singly_list<T> &obj);
    singly_list &operator=(singly_list<T> &&obj);
    ~singly_list();
public:
    bool is_empty();
    void push_front(const T &element);
    void push_front(T&& element);
    void pop_front();
    void insert(const T &element, std::size_t position);
    void remove_at(std::size_t position);
    void traverse(void (*print)(const T &element));
    void reverse() noexcept;
private:
    Node<T> *_head = nullptr;
    std::size_t _size{};
};
#include "singly_linked_list.tpp"
}
#endif /* _LIST_H */