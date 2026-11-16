#pragma once
#include<cstdio>
#include <utility>  
template<typename T>

struct Array{
    T* data;
    int size;

    Array();
    ~Array();
    Array(int n);  // n 个元素，全为 0
    Array(int n, T init_value);
    Array(const Array& other); //深层拷贝
    Array& operator=(const Array& other);//拷贝赋值
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;//移动赋值

    void set(int index, T value);
    T get(int index) const;//不允许修改对象

};

    template<typename T>
    Array<T>:: Array(): data(nullptr), size(0){
         printf("[默认构造] size=0\n");
    }    // size = 0, data = nullptr

    template<typename T>
    Array<T>::Array(int n){
    printf("一个参数构造~\n");
    data = new T[n]();
    size = n;
}

    template<typename T>
    Array<T>::~Array(){
    printf("[析构函数] 释放 %d 个 T\n", size);
    delete [] data;
    data = nullptr;
    size = 0;
}

    template<typename T>
    Array<T>::Array(const Array<T>& other){
        //记录大小，原创建的对象传进来，const不得更改传进来的对象，只看
        size = other.size;
        data = new T[size];

        for(int i = 0; i < size; i++){
            *(data + i) = *(other.data + i);
        }
        printf("[拷贝构造] 复制了 %d 个 T\n", size);
    }      // 深拷贝 

    template<typename T>
    Array<T>::Array(int n, T init_value) {
        data = new T[n];
        size = n;
        for(int i = 0; i < n; i++){
        *(data + i) = init_value;
    }
        printf("两个参数~\n");
    }   // n 个元素，全为 init_value

    template<typename T>
    Array<T>::Array(Array<T>&& other) noexcept {
    // 1. 偷走对方的指针和大小
    data = other.data;
    size = other.size;

    // 2. 让对方放手（否则 double free）
    other.data = nullptr;
    other.size = 0;

    // 3. 日志
    printf("[移动构造] 偷走 %d 个 T 的指针\n", size);
}

    template<typename T>
    Array<T>& Array<T>:: operator=(const Array<T>& other){
        printf("[拷贝赋值] ...\n");
        if(this == &other) return *this;
        delete [] data;
        data = new T [other.size];
        size = other.size;
        for(int i = 0; i < size; i++){
            *(data + i) = *(other.data + i);
        }
        return *this; 
    }

    template<typename T>
    Array<T>& Array<T>::operator=(Array<T>&& other) noexcept{
    printf("[移动赋值]...\n");
    if(this == &other) return *this;
    delete [] data;
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
    return *this;
}

    template<typename T>
    void Array<T>::set(int index, T value){
    *(data + index) = value;
}

    template<typename T>
    T Array<T>::get(int index) const{
    return *(data + index);
}
