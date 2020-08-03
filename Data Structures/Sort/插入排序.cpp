//统一接口,A[]表示待排数组,N表示数组大小
//默认从小到大
void sorted(int A[],int N){
    int i,j;
    for(i = 1;i < N;i++){
        int temp = A[i];
        for(j = i;j > 0 && A[j - 1] > temp;j--){
            A[j] = A[j - 1];
        }
        A[j] = temp;
    }
}