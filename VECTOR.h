#pragma once
#include <iostream>
/*
Создайте шаблон класса массива, в котором есть методы для вычисления суммы и среднего
значения хранимых в массиве чисел. Перегрузите потоковый ввод/вывод, оператор + для сложения
двух массивов, - для вычитания массивов, != для сравнения массивов, < для сравнения массивов.

sum yes
mean yes
<< yes
>> yes
+ yes
- yes
!= yes
> yes
< yes
*/


template<typename T>
class Vector {
public:

    Vector() 
    {
        arr_ = new T[1];
        capacity_ = 1;
    }

    Vector(Vector&  other) 
    {
        if (this != &other) {



            arr_ = new T[other.capacity()];
            
            for (size_t i = 0; i < other.size(); i++)
            {
                arr_[i] = other.arr_[i];

            }

            size_ = other.size_;
            capacity_ = other.capacity_;
            
        }
    }

    Vector(Vector&& other)  noexcept 
    {
        if (this != &other) {

            delete[] arr_;
            arr_ = new T[other.capacity()];

            for (size_t i = 0; i < other.size(); i++)
            {
                arr_[i] = other.arr_[i];

            }

            size_ = other.size_;
            capacity_ = other.capacity_;

        }
    }

    Vector& operator=(Vector& other) 
    {

        if (this != &other) {
            delete[] arr_;
            arr_ = new T[other.capacity()];

            for (size_t i = 0; i < other.size(); i++)
            {
                arr_[i] = other.arr_[i];

            }

            size_ = other.size_;
            capacity_ = other.capacity_;

        }


        
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept 
    {

        if (this != &other) {
            delete[] arr_;
            arr_ = new T[other.capacity()];

            for (size_t i = 0; i < other.size(); i++)
            {
                arr_[i] = other.arr_[i];

            }

            size_ = other.size_;
            capacity_ = other.capacity_;

        }
        return *this;
    }

    ~Vector() 
    {
        delete[] arr_;
    }

    bool isEmpty() const 
   {
        return size_ == 0;
   }

    size_t size() const 
   {
        return size_;
   }

    size_t capacity() const 
    {
        return capacity_;
    }

    void pushBack(const T& value) 
    {
        if (size_ >= capacity_) addMemory();
        arr_[size_++] = value;
    }

    void pushBack(T& value) 
    {
        if (size_ >= capacity_) addMemory();
        arr_[size_++] = value;
    }

    void remove(size_t index) 
    {
        for (size_t i = index + 1; i < size_; ++i) {
            arr_[i - 1] = arr_[i];
        }
        --size_;
    }

    T* begin() 
    {
        return &arr_[0];
    }

    const T* begin() const 
    {
        return &arr_[0];
    }

    T* end() 
    {
        return &arr_[size_];
    }

    const T* end() const 
    {
        return &arr_[size_];
    }

    T& operator[](size_t index) 
    {
        if (index >= size_)
            throw "ERR: index >= size";
        return arr_[index];
    }

    const T& operator[](size_t index) const 
    {
        return arr_[index];
    }

    T sum()
    {
        T res = NULL;

        for (size_t i = 0; i < size_; i++) 
        {
            res += arr_[i];
        }

        return res;

    }
    T mean()
    {
        T res = NULL;

        for (size_t i = 0; i < size_; i++) 
        {
            res += arr_[i];
        }

        return res / size_;

    }

    bool operator!=(Vector<T>& vec)
    {
        if (vec.size() != this->size())
            return true;

        for (size_t i = 0; i < vec.size(); i++)
        {
            if (vec[i] != (*this)[i])
                return true;

        }
        return false;
    }    
    
    bool operator==(Vector<T>& vec)
    {
        if (vec.size() != this->size())
            return false;

        for (size_t i = 0; i < vec.size(); i++)
        {
            if (vec[i] != (*this)[i])
                return false;

        }
        return true;
    }

    bool operator>(Vector<T>& vec)
    {
        if (this->size() > vec.size())
            return true;

        if (this->size() < vec.size())
            return false;

        for (size_t i = 0; i < vec.size(); i++)
        {
            if ((*this)[i] <= vec[i])
                return false;

        }
        return true;
    }

    bool operator<(Vector<T>& vec)
    {
        if (this->size() < vec.size())
            return true;

        if (this->size() > vec.size())
            return false;

        for (size_t i = 0; i < vec.size(); i++)
        {
            if ((*this)[i] >= vec[i])
                return false;

        }
        return true;
    }
    
    Vector<T> operator+(Vector<T>& vec)
    {
        if (vec.size() != this->size())
            throw "ERR: size error";

        Vector<T>* res = new Vector<T>;

        for (size_t i = 0; i < vec.size(); i++)
        {
            res->pushBack((*this)[i] + vec[i]);

        }


        return *res;
    }

    void set_size(size_t s)
    {

        this->capacity_ = 1;
        delete[] this->arr_;
        this->arr_ = new T[1];
        size_ = 1;
        while (s >= this->capacity())
            this->addMemory();
        size_ = s;
    }

    Vector<T> operator-(Vector<T>& vec)
    {


        if (vec.size() != this->size())
            throw "ERR: size error";

        Vector<T>* res = new Vector<T>;

        for (size_t i = 0; i < vec.size(); i++)
        {
            res->pushBack((*this)[i] - vec[i]);

        }


        return *res;
    }

private:

    void addMemory() {

        capacity_ *= 2;
        T* tmp = arr_;
        arr_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
        delete[] tmp;
    }

    T* arr_;
    size_t size_{};
    size_t capacity_{};


};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) 
{
    for (const T& val : vec) os << val << " ";
    return os;
}

template<typename T>
inline std::istream& operator>>(std::istream& os, Vector<T>& vec)

{
    std::cout << "input size\n";
    size_t size;
    os >> size;
    vec.set_size(size);
    

    T val;
    for (size_t i = 0; i < vec.size(); i++)
    {
        os >> val;
        vec[i] = val;
    }
    return os;
}
