//统一接口,A[]表示待排数组,N表示数组大小
//默认从小到大
void Swap(int *a,int *b){
    int t = *a; *a = *b; *b = t;
}

void PerDown(int A[],int p,int N){
    //将N个元素的数组以A[P]为根的子堆调整为最大堆
    int Parenet,Child;
    int temp;
    temp = A[p];
    for(Parenet = p; (Parenet*2+1) < N; Parenet = Child){
        Child = Parenet * 2 + 1;
        if((Child != N -1) && (A[Child] < A[Child + 1]))
            Child++; //指向子节点中大的数
        if(temp >= A[Child]) break;
        else // 下滤
            A[Parenet] = A[Child];
    }
    A[Parenet] = temp;
}

void sorted(int A[],int N){
    int i;
    for(i = N/2 - 1; i >= 0; i--)
        PerDown(A,i,N);
    for(i = N -1; i > 0; i--){
        //删除最大堆顶,放到数组的最后
        Swap(&A[0],&A[i]);
        PerDown(A,0,i);
    }
}
