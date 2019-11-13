#include <iostream>
#include <cstdlib>
using namespace std;
void Bubble_Sort(int N,long int *a){ //冒泡排序
    for(int i=0;i<N-1;i++){
        int flag = 0;
        for(int j=0;j<N-i-1;j++){
            if(a[j] > a[j+1]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
        if(!flag) return;
    }
}

void Insert_Sort(int N,long int *a){ //插入排序
    int i,j;
    for(i=1;i<N;i++){
        int temp = a[i];
        for(j=i;j > 0 && a[j-1] > temp;j--){
            a[j] = a[j-1];
        }
        a[j] = temp; 
    }
}

void Shell_Sort(int N,long int *a){ //希尔排序
    int i,j,k,m;
    int Sedgewick[]={0,1,5,19,41,109,209,505,929,
        2161,3905,8929,16001,36289,64769,146305,260609,
        587521,1045505,2354689,4188161,9427969,16764929,37730305,67084289,
        150958081,268386305,603906049,1073643521};
    for(k = 0;Sedgewick[k] < N;k++); //找到小于N的Sedgewick[]增量
    for(m = Sedgewick[k];k > 0;m = Sedgewick[--k]){
        for(i = m;i < N;i++){
            int temp = a[i];
            for(j = i;j >= m && a[j-m] > temp;j -= m)
                a[j] = a[j-m];
            a[j] = temp;
        }
    }
}

void Swap(long int *a,long int *b){ //交换
    long int temp = *a;*a = *b;*b = temp;
}
void PerDown(int index,int N,long int *a){
    int Parenet,Child;
    int temp = a[index];
    for(Parenet = index;(Parenet*2+1) < N;Parenet = Child){ //Parenet的判断
        Child = 2 * Parenet + 1;
        if(Child != N-1 && a[Child] < a[Child+1]) //Child != N-1
            Child++;
        if(a[Child] <= temp) break; //小于等于
        else
            a[Parenet] = a[Child]; 
    }
    a[Parenet] = temp;
}
void Heap_Sort(int N,long int *a){ // 堆排序
    int i,j;
    for(i = N/2;i >= 0;i--) //建堆
        PerDown(i,N,a);
    for(j = N-1;j > 0;j--){ //排序
        Swap(a,a+j);
        PerDown(0,j,a); //下滤到j
    }
}

void Merge(long int *a,long int *tmpA,int L,int R,int Rightend){
    int Leftend,index;
    index = L;
    Leftend = R - 1;
    while(L <= Leftend && R <= Rightend){
        if(a[L] > a[R]) tmpA[index++] = a[R++];
        else tmpA[index++] = a[L++];
    }
    while(L <= Leftend) tmpA[index++] = a[L++];
    while(R <= Rightend) tmpA[index++] = a[R++];
}
void Merge_pass(long int *a,long int *tmpA,int N,int length){
    int i,j;
    for(i = 0;i <= N-2*length;i += 2*length)
        Merge(a, tmpA, i, i+length, i+2*length-1);
    if(i + length < N)
        Merge(a, tmpA, i, i+length, N-1);
    else 
        for(j = i;j < N;j++) tmpA[j] = a[j];
}
void Merge_Sort(int N,long int *a){
    int length;
    long int *tmpA;
    length = 1;
    tmpA = (long int *)malloc(sizeof(long int)*N);
    if(tmpA != NULL){
        while(length < N){
            Merge_pass(a, tmpA, N, length);
            length *= 2;
            Merge_pass(tmpA, a, N, length);
            length *= 2;
        }
        free(tmpA);
    }
    else printf("空间不足\n");
}

int main(){
    long int N,a[100010];
    scanf("%ld",&N);
    for(int i=0;i<N;i++)
        scanf("%ld",&a[i]);
    Merge_Sort(N,a);
    //输出数据
    cout << a[0];
    for(int i=1;i<N;i++)
        cout << ' ' << a[i];
    cout << endl;
    system("pause");
    return 0;
}