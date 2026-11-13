#include<cstdio>
struct IntArray {
    int* data;
    int size;
};

// 创建：分配 size 个 int，全部置 0，返回结构体
IntArray create_array(int size);

// 销毁：释放内存，并把 data 置空、size 置 0
void destroy_array(IntArray* arr);

// 设值：把第 index 个元素设为 value
void set_element(IntArray* arr, int index, int value);

// 取值：返回第 index 个元素
int get_element(const IntArray* arr, int index);

// 打印：输出所有元素和 size
void print_array(const IntArray* arr);

int main(){
    IntArray arr = create_array(5);
    // for(int i = 10,int j = 0; i < 1000, j < arr.size; i += 10, j++){
    //     if(j > arr.size)  break;
    //     set_element(&arr, j, i);
    // }
    for (int j = 0; j < arr.size; ++j) {
    set_element(&arr, j, (j + 1) * 10);
}
    print_array(&arr);
    destroy_array(&arr);
    return 0;
}

IntArray create_array(int size){
    IntArray arr;
    arr.data = new int[size];
    for(int i = 0; i < size; i++){
        *(arr.data + i) = 0;
    }
    arr.size = size;
    return arr;
}

void destroy_array(IntArray* arr){
    delete [] arr->data;
    arr->data = nullptr;
    arr->size = 0;
}

void set_element(IntArray* arr, int index, int value){
    *(arr->data + index) = value;
}

int get_element(const IntArray* arr, int index){
    return *(arr->data + index);
}

void print_array(const IntArray* arr){
    for(int i = 0; i < arr->size; i++){
        printf("%d ",*(arr->data + i));
    }
    printf("arr的size = %d ", arr->size);
}