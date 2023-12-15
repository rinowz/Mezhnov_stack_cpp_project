#ifndef STACK_H
#define STACK_H

template<typename Type>
class stack {
public:
    struct Node;
    Node* head_;
    size_t size_;
public:
    stack();
    stack(const stack& other);
    stack& operator=(const stack& other);
    ~stack();
    void push(const Type& value);
    void pop();
    Type top() const;
    bool is_empty() const;
    size_t size() const;
    void clear();
};

#endif //STACK_H
#include "stack.cpp"
