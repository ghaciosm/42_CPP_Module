#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    private:
        T* data;
        int length;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](int index);

        int size() const;
};

template <typename T>
Array<T>::Array() : data(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : length(n) 
{
    data = new T[length];
}

template <typename T>
Array<T>::Array(const Array& other) : length(other.length) 
{
    int i = -1;
    data = new T[length];
    while (++i < length)
        data[i] = other.data[i];
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) 
{
    if (this != &other) 
    {
        delete[] data;
        length = other.length;
        data = new T[length];
        int i = -1;
        while (++i < length)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() 
{
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if (index >= length || index < 0)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
int Array<T>::size() const
{
    return length;
}

#endif