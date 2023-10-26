#ifndef list_H
#define list_H

#include <cstddef>

/**
 * @brief Singly-linked list that uses position
 *
 * Implement all described functions and provide a test program using CATCH2
 *
 * @tparam Object
 */
template <typename Object>
class DSList
{
private:
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {};
    };

    Node *head;
    Node *tail;

public:
    DSList();

    ~DSList();

    DSList(const DSList &rhs);

    DSList &operator=(const DSList &rhs);

    size_t size() const;

    bool empty() const;

    void clear();

    int find_element(const Object &value);

    void push_front(const Object &value);

    void push_back(const Object &value);

    Object pop_front();

    Object pop_back();

    Object front() const;

    Object at(size_t value) const;
};
#endif
