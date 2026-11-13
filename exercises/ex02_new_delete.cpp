#include<cstdio>

int* make_sequence(int count);

int main(){
    const int count = 10;
    int* sequence = make_sequence(count);
    for(int i = 0; i < count; ++i){
        printf("%d ",*(sequence + i));
    }
    printf("\n");
    //delete[] sequence;
    return 0;
}

// 生成 1..count 的序列，返回数组指针
int* make_sequence(int count){
    int* data = new int[count]; // 分配 count 个 int
    for(int i = 0; i < count; i++){
        *(data + i) = i + 1; // 填充 count 个 int
    }
    return data;//返回指针
}