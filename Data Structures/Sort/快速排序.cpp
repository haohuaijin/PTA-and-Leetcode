#include <iostream>
using namespace std;
void Insert_Sort(long int *a,int N){
    int i,j;
    for(i = 1;i < N;i++){
        long int tmp = a[i];
        for(j = i;j > 0 && a[j-1] > tmp;j--)
            a[j] = a[j-1];
        a[j] = tmp;
    }
}
void Swap(long int &a,long int &b){
    long int t = a;a = b;b = t;
}
long int Median3(long int *A,int Left,int Right){
    long int Center = (Left + Right) / 2;
    if(A[Left] > A[Center])
        Swap(A[Left],A[Center]);
    if(A[Left] > A[Right])
        Swap(A[Left],A[Right]);
    if(A[Center] > A[Right])
        Swap(A[Center],A[Right]);
    //此时A[Left] <= A[Center] <= A[Right]
    Swap(A[Center],A[Right-1]);
    return A[Right-1];
}
void QSort(long int *a,int Left,int Right){
    long int Pivot;
    int Low,High,Cutoff = 1;
    if(Cutoff <= Right-Left){ //如果序列元素多，进入快排
        //Pivot = Median3(a,Left,Right); //选基准
        Pivot = a[Left];
        Low = Left;
        High = Right + 1; //注意
        while(1){ //序列中比基准小的放在左边,大的右边
            while(a[++Low] < Pivot);// if(Low == Right) break;
            while(a[--High] > Pivot);
            if(Low < High) Swap(a[Low],a[High]);
            else break;
        }
        Swap(a[Left],a[High]); //将基准放在正确的位置
        QSort(a,Left,High-1); //递归解决左边
        QSort(a,High+1,Right); //递归解决右边
    }
    else Insert_Sort(a+Left,Right-Left+1);
}
void Quick_Sort(long int *a,int N){
    QSort(a,0,N-1);
}
int main(){
    //int N;
    //long int a[100010];
    //scanf("%d",&N);
    //for(int i=0;i<N;i++)
    //    scanf("%ld",&a[i]);
    long int a[] = {9,8,7,6,5,4,3,2,1};
    int N = 9;
    Quick_Sort(a,N);
    cout << a[0];
    for(int i=1;i<N;i++)
        cout << ' ' << a[i];
    cout << endl;
    //system("pause"); 
    return 0;
}