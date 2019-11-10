//统一接口,A[]表示待排数组,N表示数组大小
//默认从小到大
// L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点的位置
void Merge(int A[],int TmpA[],int L,int R,int RightEnd){
    //将A[L]~A[R-1] 和 A[R]~A[RightEnd] 归并成一个有序序列
    int LeftEnd,NumElements,Tmp;
    int i;
    LeftEnd = R - 1; //左边的终点
    Tmp = L; //起点
    NumElements = RightEnd - L + 1;

    while(L <= LeftEnd && R <= RightEnd){
        if(A[L] <= A[R])
            TmpA[Tmp++] = A[L++]; //将左边的元素复制到TmpA
        else
            TmpA[Tmp++] = A[R++]; //将右边的元素复制到TmpA
        }
    }
    while(L <= LeftEnd)
        TmpA[Tmp++] = A[L++]; // 直接复制剩下的元素
    while(R <= RightEnd)
        Tmp[Tmp++] = A[R++]; // 直接复制剩下的元素
}

//Length = 当前有序子序列的长度
void Merge_pass(int A[],int TmpA[],int N,int length){
    int i,j;
    for(i = 0;i <= N-2*length;i += 2*length)
        Merge(A, TmpA, i, i+length, i+2*length-1);
    if(i+length < N) //归并最后两个子列
        Merge(A, TmpA, i, i+length, N-1);
    else // 只剩一个
        for(j = i; j < N; j++) TmpA[j] = A[j];
}

void sorted(int A[],int N){
    int Length;
    int *TmpA;
    length = 1; //初始化子序列的长度
    TmpA = (int*)malloc(sizeof(int)*N);
    if(TmpA != NULL){
        while(length < N){
            Merge_pass(A, TmpA, N, Length);
            length *= 2;
            Merge_pass(TmpA, A, N, length);
            length *= 2; 
        }
        free(TmpA);
    }
    else printf("空间不足\n");
}