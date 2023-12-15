template<typename Type>
struct stack<Type>::Node {
    Type data;
    Node* prev;
};

template<typename Type>
stack<Type>::stack() : head_(nullptr), size_(0) {}

template<typename Type>
stack<Type>::stack(const stack& other) : head_(nullptr), size_(0) {
    Node* otherCurrent = other.head_;
    Node* thisPrevious = nullptr;

    while (otherCurrent) {
        Node* tmp_node = new Node{otherCurrent->data, nullptr};
        if (thisPrevious)
            thisPrevious->prev = tmp_node;
        else
            head_ = tmp_node;

        thisPrevious = tmp_node;
        otherCurrent = otherCurrent->prev;
        ++size_;
    }
}

template<typename Type>
stack<Type>& stack<Type>::operator=(const stack& other) {
    if (this != &other) {
        clear();
        Node* otherCurrent = other.head_;
        Node* thisPrevious = nullptr;

        while (otherCurrent) {
            Node* tmp_node = new Node{otherCurrent->data, nullptr};
            if (thisPrevious)
                thisPrevious->prev = tmp_node;
            else
                head_ = tmp_node;

            thisPrevious = tmp_node;
            otherCurrent = otherCurrent->prev;
            ++size_;
        }
    }
    return *this;
}

template<typename Type>
stack<Type>::~stack() {
    clear();
}

template<typename Type>
void stack<Type>::push(const Type& value) {
    stack<Type>::Node* newNode = new stack<Type>::Node{value, head_};
    head_ = newNode;
    ++size_;
}

template<typename Type>
void stack<Type>::pop() {
    Node* temp = head_;
    head_ = head_->prev;
    delete temp;
    size_ -= (!is_empty());
}

template<typename Type>
Type stack<Type>::top() const {
    return head_->data;
}

template<typename Type>
bool stack<Type>::is_empty() const {
    return head_ == nullptr;
}

template<typename Type>
size_t stack<Type>::size() const {
    return size_;
}

template<typename Type>
void stack<Type>::clear() {
    while (!is_empty())
        pop();
}

template<typename Type>
std::ostream& operator<<(std::ostream& os, const stack<Type> Stack) {
    stack<Type> tmp = Stack;
    os << "________\n";
    while (!tmp.is_empty()) {
        os << "| " << tmp.top() << " |" << '\n';
        tmp.pop();
    }
    os << "________\n";
    return os;
}