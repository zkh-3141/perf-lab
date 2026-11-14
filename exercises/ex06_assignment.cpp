#include<cstdio>

struct IntArray{
    int* data;
    int size;

    IntArray(): data(nullptr), size(0){
         printf("[默认构造] size=0\n");
    }    
                         // size = 0, data = nullptr
    IntArray(int n); 
                                               // n 个元素，全为 0
    IntArray(int n, int init_value) {
        data = new int[n];
        size = n;
        for(int i = 0; i < n; i++){
        *(data + i) = init_value;
    }
        printf("两个参数~\n");
    }   
                                                            // n 个元素，全为 init_value
    IntArray(const IntArray& other){
        //记录大小，原创建的对象传进来，const不得更改传进来的对象，只看
        size = other.size;
        data = new int[size];

        for(int i = 0; i < size; i++){
            *(data + i) = *(other.data + i);
        }
        printf("[拷贝构造] 复制了 %d 个 int\n", size);
    }      
                       // 深拷贝  
    ~IntArray();

    IntArray& operator=(const IntArray& other){
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

    void set(int index, int value);
    int get(int index) const;
    void print() const;

};

int main() {
    IntArray a(5);
    for (int i = 0; i < a.size; ++i) a.set(i, (i + 1) * 10);

    IntArray b(3);
    b = a;                  // ← 注意：这里没有 IntArray，b 早就存在了
    b.set(0,999);

// 编译器生成的（伪代码）
// IntArray& operator=(const IntArray& other) {
//     data = other.data;      // 又是浅拷贝，而且还是直接覆盖
//     size = other.size;
//     return *this;
// }//报错原因

    printf("a: "); a.print();
    printf("b: "); b.print();

    IntArray c(5);
    c = c;                          // ③ 自赋值不崩
    c.print();

    return 0;
}

IntArray::IntArray(int n){
    data = new int[n];
    size = n;
    printf("一个参数构造~\n");
}

IntArray::~IntArray(){
    printf("[析构函数] 释放 %d 个 int\n", size);
    delete [] data;
    data = nullptr;
    size = 0;
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