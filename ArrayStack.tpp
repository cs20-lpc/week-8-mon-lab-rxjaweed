template <typename T>
ArrayStack<T>::ArrayStack(int size) {
    maxSize = size;
    top = -1;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    top = -1;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    if (copyObj.isEmpty()) {
        top = -1;
    } else {
        top = copyObj.top;
        maxSize = copyObj.maxSize;
        for (int i = 0; i <= top; ++i) {
            buffer[i] = copyObj.buffer[i];
        }
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return top + 1;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return top == -1;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return top == maxSize - 1;
}

template <typename T>
T ArrayStack<T>::peek() const {
    if (isEmpty()) {
        throw std::string ("Stack is empty");
    }
    return buffer[top];
}

template <typename T>
void ArrayStack<T>::pop() {
    if (isEmpty()) {
        throw std::string("Stack is empty");
    }
    --top;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) {
        throw std::string ("Stack is full");
    }
    buffer[++top] = elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (isEmpty()) {
        throw std::string ("Stack is empty");
    }

    if (top == 0) return; // Only one element, nothing to rotate

    if (dir == Stack<T>::RIGHT) {
        T last = buffer[top];
        for (int i = top; i > 0; --i) {
            buffer[i] = buffer[i - 1];
        }
        buffer[0] = last;
    } 
    else if (dir == Stack<T>::LEFT) {
        T first = buffer[0];
        for (int i = 0; i < top; ++i) {
            buffer[i] = buffer[i + 1];
        }
        buffer[top] = first;
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    } else {
        for (int i = myObj.top; i >= 0; i--) {
            outStream << (i == myObj.top ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }
    return outStream;
}
