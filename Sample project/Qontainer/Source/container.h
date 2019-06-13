#ifndef CONTAINER
#define CONTAINER

template <class T>
class Container {
    private:
        T* buffer;
        unsigned int capacity;
        unsigned int size;
    public:
        typedef T* iterator;

        Container();
        void add(const T&);
        T& at(const unsigned int&) const;//ritorna il valore all'indice richiesto
        void clear();
        bool erase(const unsigned int&);
        unsigned int getCapacity() const;
        unsigned int getSize() const;
        bool isEmpty() const;

        iterator begin() const;
        iterator end() const;

        T& operator[](const unsigned int&) const;
        Container<T>& operator=(const Container<T>&);
        bool operator==(const Container<T>&) const;
        bool operator!=(const Container<T>&) const;
        bool operator<(const Container<T>&) const;

        int search(const T&) const;
        ~Container();
};

template<class T>
Container<T>::Container(): buffer(nullptr), capacity(0), size(0){}

template<class T>
void Container<T>::add(const T& t) {
    if(isEmpty()){
        capacity=1;
        buffer=new T[1];
    }
    if(size >= capacity) {
        capacity = 1+size;
        T* newBuffer = new T[capacity];
        for(unsigned int i = 0; i < size; ++i) {
            newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
    }
    buffer[size] = t;
    size++;
}

//ritorna il valore all'indice richiesto
template<class T>
T& Container<T>::at(const unsigned int& i) const {
    if(i <= size) {
        return buffer[i];
    }
}

template<class T>
void Container<T>::clear() {
    if(size > 0) {
        T* newBuffer = nullptr;
        delete[] buffer;
        buffer = newBuffer;
        capacity = 0;
        size = 0;
    }
}

template<class T>
bool Container<T>::erase(const unsigned int &i) {
    if(i < size) {
        unsigned int pos = 0;
        T* newBuffer = new T[capacity];
        for(unsigned int l = 0; l < size; l++) {
            if(l != i) {
                newBuffer[pos] = buffer[l];
                pos++;
            }
        }
        size--;
        delete[] buffer;
        buffer = newBuffer;
        return true;
    }
    return false;
}

template<class T>
unsigned int Container<T>::getCapacity() const {
    return capacity;
}

template<class T>
unsigned int Container<T>::getSize() const {
    return size;
}

template<class T>
bool Container<T>::isEmpty() const {
    return size == 0;
}

template<class T>
typename Container<T>::iterator Container<T>::begin() const {
    return buffer;
}

template<class T>
typename Container<T>::iterator Container<T>::end() const {
    return buffer+size;
}

template<class T>
T& Container<T>::operator[](const unsigned int& t) const {
    return buffer[t];
}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& t) {
    if(t.isEmpty()) {
        clear();
    }
    else if(this != &t) {
        T* newBuffer = new T[t.capacity];

        for(unsigned int i = 0; i < t.size; ++i) {
            newBuffer[i] = t[i];
        }
        delete[] buffer;
        size = t.size;
        capacity = t.capacity;

        buffer = newBuffer;
    }
    return *this;
}

template<class T>
bool Container<T>::operator==(const Container<T>& t) const {
    if(buffer && t) {
        if(size == t.getSize()) {
            for(unsigned int i = 0; i < size; ++i) {
                if(buffer[i] != t[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

template<class T>
bool Container<T>::operator!=(const Container<T>& t) const {
    if(buffer && t) {
        if(size == t.getSize()) {
            for(unsigned int i = 0; i < size; ++i) {
                if(buffer[i] == t[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

template<class T>
bool Container<T>::operator<(const Container<T>& t) const {
    return buffer < t.buffer;
}

template<class T>
int Container<T>::search(const T& t) const {
    for(unsigned int i = 0; i < size; ++i) {
        if(buffer[i] == t) {
            return i;
        }
    }
    return -1;
}

template<class T>
Container<T>::~Container() {
    if(buffer) {
        delete[] buffer;
    }
}


#endif
