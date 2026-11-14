#include<cstdio>

struct IntArray{
    int* data;
    int size;

    IntArray(int n);
    ~IntArray();

    void set(int index, int value);
    int get(int index) const;
    void print() const;

};

// int main(){
//     IntArray arr(5);
//     for(int i = 0; i < arr.size; i++){
//         arr.set(i, (i+1)*10);
//     }
//     arr.print();
    
//     return 0;
// }
int main() {
    {
        IntArray arr(5);
        for (int i = 0; i < arr.size; ++i) arr.set(i, (i + 1) * 10);
        arr.print();
    }   // ← 右大括号：arr 在这里被销毁

    printf("--- 已经出作用域了 ---\n");
    return 0;
}

IntArray::IntArray(int n){
    data = new int[n];
    size = n;
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