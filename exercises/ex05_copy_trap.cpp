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

    void set(int index, int value);
    int get(int index) const;
    void print() const;

};
int main() {
    IntArray a;                 // 应该看到 [默认构造]
    IntArray b(5);              // [构造] size=5
    IntArray c(5, 99);          // [构造+初值] size=5, value=99
    IntArray d = c;             // [拷贝构造] 复制了 5 个 int

    printf("a.size = %d\n", a.size);      // 0
    printf("b: "); b.print();              // 0 0 0 0 0
    printf("c: "); c.print();              // 99 99 99 99 99

    d.set(0,100);
    printf("d: "); d.print();              // 100 99 99 99 99
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