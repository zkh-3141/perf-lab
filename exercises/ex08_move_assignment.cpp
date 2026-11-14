#include<cstdio>
#include <utility>      // std::move 在这个头文件里

struct IntArray{
    int* data;
    int size;

    IntArray();
    ~IntArray();
    IntArray(int n);  // n 个元素，全为 0
    IntArray(int n, int init_value);
    IntArray(const IntArray& other); //深层拷贝
    IntArray& operator=(const IntArray& other);//拷贝赋值
    IntArray(IntArray&& other) noexcept;
    IntArray& operator=(IntArray&& other) noexcept;//移动赋值

    void set(int index, int value);
    int get(int index) const;//不允许修改对象
    void print() const;

};



int main() {
    IntArray a(5);
    for (int i = 0; i < a.size; ++i) a.set(i, (i + 1) * 10);

    IntArray b(3);
    b = std::move(a);          // 移动赋值

    printf("a.size = %d\n", a.size);    // 0
    printf("b: "); b.print();           // 10 20 30 40 50
    return 0;
}

IntArray::IntArray(int n){
    printf("一个参数构造~\n");
    data = new int[n];
    size = n;
    
}

IntArray::~IntArray(){
    printf("[析构函数] 释放 %d 个 int\n", size);
    delete [] data;
    data = nullptr;
    size = 0;
}

    IntArray::IntArray(const IntArray& other){
        //记录大小，原创建的对象传进来，const不得更改传进来的对象，只看
        size = other.size;
        data = new int[size];

        for(int i = 0; i < size; i++){
            *(data + i) = *(other.data + i);
        }
        printf("[拷贝构造] 复制了 %d 个 int\n", size);
    }      // 深拷贝 

    IntArray::IntArray(int n, int init_value) {
        data = new int[n];
        size = n;
        for(int i = 0; i < n; i++){
        *(data + i) = init_value;
    }
        printf("两个参数~\n");
    }   // n 个元素，全为 init_value

    IntArray:: IntArray(): data(nullptr), size(0){
         printf("[默认构造] size=0\n");
    }    // size = 0, data = nullptr

    IntArray::IntArray(IntArray&& other) noexcept {
    // 1. 偷走对方的指针和大小
    data = other.data;
    size = other.size;

    // 2. 让对方放手（否则 double free）
    other.data = nullptr;
    other.size = 0;

    // 3. 日志
    printf("[移动构造] 偷走 %d 个 int 的指针\n", size);
}

    IntArray& IntArray:: operator=(const IntArray& other){
        printf("[拷贝赋值] ...\n");
        if(this == &other) return *this;
        delete [] data;
        data = new int[other.size];
        size = other.size;
        for(int i = 0; i < size; i++){
            *(data + i) = *(other.data + i);
        }
        return *this; 
    }

IntArray& IntArray::operator=(IntArray&& other) noexcept{
    printf("[移动赋值]...\n");
    if(this == &other) return *this;
    delete [] data;
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
    return *this;
}

 void IntArray::set(int index, int value){
    *(data + index) = value;
}

int IntArray::get(int index) const{
    return *(data + index);
}

void IntArray::print() const {
    int i = 0;
    while(i < size){
        printf("%d ", *(data + i));
        i++;
    }
    printf("\n");
}