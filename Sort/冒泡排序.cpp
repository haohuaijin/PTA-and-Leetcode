//统一接口,A[]表示待排数组,N表示数组大小
//默认从小到大
void sorted(int A[],int N){
    for(int i = N;i > 0;i--){
        for(int j = 0;j < i;j++){
            if(A[j] > A[j+1]){
                int temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
}