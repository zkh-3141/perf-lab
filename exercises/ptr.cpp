#include<cstdio>

int array_sum(int* arr, int n);
int array_max(int* arr, int n);
void swap_ints(int* a, int* b);

void probe(int* p);

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    const int n = sizeof(arr)/sizeof(arr[0]);
    printf("Sum: %d\n", array_sum(arr, n));
    printf("Max: %d\n", array_max(arr, n)); 
    int a = 5, b = 10;
    swap_ints(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);

    printf("main 里 sizeof = %zu\n", sizeof(arr));
    probe(arr);
    return 0;
}

int array_sum(int* arr,int n){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum+= *(arr + i);
    }
    return sum;
}

int array_max(int* arr,int n){
    int max_val = *arr;
    for(int i = 1; i < n; ++i){
        if(*(arr + i) > max_val){
            max_val = *(arr + i);
        }
    }
    return max_val;
}

void swap_ints(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void probe(int* p) {
    printf("函数内部 sizeof = %zu\n", sizeof(p));
}