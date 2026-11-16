#include"array.h"
const int N = 4;
void matmul_naive(const Array<float>& A, 
                  const Array<float>& B,
                Array<float>& C,int N){
                    for(int i = 0; i < N; i++){
                        for(int j = 0; j < N; j++){
                            float sum = 0.f;
                            for(int k = 0; k < N; k++){
                                sum += *(A.data + i * N + k)* *(B.data + k * N + j);
                            }
                            *(C.data + i * N + j) = sum;
                        }
                    }
                }

int check(const Array<float>& C){
    for(int i = 0; i < C.size; i++){
        if(*(C.data + i) != static_cast<float> (N)){
            printf("错了!C[%d] = %f,应该是 %d\n", i, C.data[i], N);
            return 0;
        }
    }
    printf("验证通过：所有元素都等于 %d\n", N);
    return 1;
}

int main(){
    
    Array<float> A(N * N, 1.0f);
    Array<float> B(N * N, 1.0f);
    Array<float> C(N * N, 0.0f);

    matmul_naive(A, B, C, N);
    if(!check(C)){
        return 1;
    }
    return 0;
}