#include <stdio.h>
#include <stdlib.h>
typedef struct Node *Heap;
struct Node{
    int Data[1001];
    int Size,Capacity;
};
Heap CreateHeap(){
    Heap p = (Heap)malloc(sizeof(struct Node));
    p->Size = 0;
    p->Capacity = 0;
    p->Data[0] = -100000;
    return p;
}
void Insert(Heap p,int X){
    int i = ++p->Size;
    for(;X < p->Data[i/2];i/=2){
        p->Data[i] = p->Data[i/2];
    }
    p->Data[i] = X;
}
int main(){
    Heap p = CreateHeap();
    int n,m,num,flag = 1;
    int *a;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        Insert(p,num);
    }
    a = (int*)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
        flag = 1;
        for(int j=a[i];j>0;j/=2){
            if(flag){
                printf("%d",p->Data[j]);
                flag = 0;
            } 
            else 
                printf(" %d",p->Data[j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}