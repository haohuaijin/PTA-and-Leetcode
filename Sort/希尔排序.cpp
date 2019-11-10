//统一接口,A[]表示待排数组,N表示数组大小
//默认从小到大
void sorted(int A[],int N){
    int i,j,si,D;
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0}; //增量
    for(si = 0;Sedgewick[si] >= N;si++); //Sedgewick[si]不超过N
    for(D = Sedgewick[si]; D > 0; D = Sedgewick[++si]){
        for(i = D; i < N; i++){
            int temp = A[i];
            for(j = i; j >= D && A[j - D] > temp; j -= D){
                A[j] = A[j - D];
            }
            A[j] = temp;
        }
    }
}