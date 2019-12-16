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
        
    for(i = 0; i < NumElements; i++,RightEnd--){
        A[RightEnd] = TmpA[RightEnd]; //将有序部分复制回A[]
}

void Msort(int A[],int TmpA[],int L,int RightEnd){
    //核心递归排序函数
    int center;
    int(L < RightEnd){
        center = (L + RightEnd) / 2;
        Msort(A,TmpA,L,center);
        Msort(A,TmpA,Center+1,RightEnd);
        Merge(A,TmpA,L,center+1,RightEnd);
    }
}

// 统一接口
void sorted(int A[],int N){
    int *TmpA;
    TmpA = (int*)malloc(sizeof(int)*N);

    if(TmpA != NULL){
        Msort(A,TmpA,0,N-1);
        free(TmpA);
    }
    else printf("空间不足\n");
}