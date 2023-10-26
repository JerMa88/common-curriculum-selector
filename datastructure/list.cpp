#include "list.h"

template <typename Object>
DSList<Object>::DSList()
    : head{nullptr}, tail{nullptr}
{
}

template <typename Object>
DSList<Object>::~DSList()
{
    while (!(head == nullptr))
        {
            // delete the node
            Node *tmpNode = head;
            head = head->next;
            delete tmpNode;
        }
        tail = nullptr;
        head = nullptr;
}

template <typename Object>
DSList<Object>::DSList(const DSList &rhs)
    : head{nullptr}, tail{nullptr}
{
    Node *prev_next = head;
        Node *rhs_current = rhs.head;
        while (rhs_current != nullptr)
        {
            if (prev_next == nullptr)
            {
                prev_next = new Node{rhs_current->data, nullptr};
                head = prev_next;
            }
            else
            {
                prev_next->next = new Node{rhs_current->data, nullptr};
                prev_next = prev_next->next;
            }
            rhs_current = rhs_current->next;
        }
        tail = prev_next;
}

template <typename Object>
DSList<Object> &DSList<Object>::operator=(const DSList &rhs)
{
    if (this == &rhs)
            return *this;
        clear(); // destroys this(lhs)
        Node *prev_next = head;
        Node *rhs_current = rhs.head;
        while (rhs_current != nullptr)
        {
            if (prev_next == nullptr)
            {
                prev_next = new Node{rhs_current->data, nullptr};
                head = prev_next;
            }
            else
            {
                prev_next->next = new Node{rhs_current->data, nullptr};
                prev_next = prev_next->next;
            }
            rhs_current = rhs_current->next;
        }
        tail = prev_next;
        return *this;
}

template <typename Object>
size_t DSList<Object>::size() const
{
    size_t size = 0;
        Node *current = head;

        while (current != nullptr)
        {
            ++size;
            current = current->next;
        }
        return size;
}

template <typename Object>
bool DSList<Object>::empty() const
{
    return (head == nullptr);
}

template <typename Object>
void DSList<Object>::clear()
{
    while (!(head == nullptr))
        {
            // delete the node
            Node *tmpNode = head;
            head = head->next;
            delete tmpNode;
        }
        tail = nullptr;
        head = nullptr;
}

template <typename Object>
int DSList<Object>::find_element(const Object &value)
{
    if (head == nullptr) // empty
            return -1;

        int pos = 0;
        Node *iter = head;
        do
        {
            if (iter->data == value) // if current node == value
                return pos;

            pos++; // if not increment position and current node to next node
            iter = iter->next;
        } while (head != nullptr);
        return -1;
}

template <typename Object>
void DSList<Object>::push_front(const Object &value)
{
    Node *newNode = new Node(value); // creating a new Node with the given value
        newNode->next = head;            // set the next pointer of the new node to the curernt head of the list
        head = newNode;                  // set the head of the list to new node
        if (head->next == nullptr)
            tail = head;
}

template <typename Object>
void DSList<Object>::push_back(const Object &value)
{
    Node *newNode = new Node;
        newNode->data = value;
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
}

template <typename Object>
Object DSList<Object>::pop_front()
{
    if (empty())
            throw std::out_of_range("List is empty!");

        // save the data (we move it if it is movable)
        Object tmpObject = std::move(head->data);

        // delete the node
        Node *tmpNode = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete tmpNode;

        return tmpObject;
}

template <typename Object>
Object DSList<Object>::pop_back()
{
    if (tail == nullptr)
            throw std::out_of_range("List is empty");

        else if (head == tail)
        {
            // list has only one node, remove it
            Object val = tail->data;
            delete tail;
            head = nullptr;
            tail = nullptr;
            return val;
        }
        else
        {
            // list has more than one node, remove the last node
            Node *prev = head;
            while (prev->next != tail)
            {
                prev = prev->next; // move forward
            }
            prev->next = nullptr;
            Object val = tail->data;
            delete tail;
            tail = prev;
            return val;
        }
}

template <typename Object>
Object DSList<Object>::front() const
{
        if (empty())
            throw std::out_of_range("List is empty.");
        else
            return head->data;
}

template <typename Object>
Object DSList<Object>::at(size_t value) const
{
    if(value >= size())
        throw std::out_of_range("Index out of range.");
    node* current = head;
    for(int i = 0; i < value; i++)
        current = current->next;
    return current->data;

}