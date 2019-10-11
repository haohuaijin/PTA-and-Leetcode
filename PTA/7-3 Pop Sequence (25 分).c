#include <stdio.h>
#include <stdlib.h>
typedef struct node Stack;
struct node{ //栈的定义
    int Data;
    Stack *Next;
};
Stack *CreateNode(){
    Stack *p;
    p = (Stack*)malloc(sizeof(struct node));
    p->Data = 0;
    p->Next = NULL;
    return p;
}
void Push(Stack *p,int item){
    Stack *ptr = CreateNode();
    ptr->Data = item;
    ptr->Next = p->Next;
    p->Next = ptr;
}
int IsEmpty(Stack *p){
    return p->Next == NULL;
}
int Pop(Stack *p){
    Stack *ptr = p->Next;
    int temp = ptr->Data;
    p->Next = ptr->Next;
    free(ptr);
    return temp;
}
int GetTop(Stack *p){
    return p->Next->Data;
}
int **ReadData(int m,int n,int k) //读取数据
{
    int num;
    int **arr;
    arr = (int**)malloc(sizeof(int*)*(k));
    for(int j=0;j<k;j++){ //为每一行分配地址
        arr[j] = (int*)malloc(sizeof(int)*n);
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&num);
            arr[i][j] = num;
        }
    }
    return arr;
}
int main(){
    int m,n,k;
    int **ptr;
    scanf("%d%d%d",&m,&n,&k);
    ptr = ReadData(m,n,k);
    for(int i=0;i<k;i++){ //真正的模拟了栈
        Stack *p = CreateNode();
        int count = 0; //记录栈的容量
        int current = 0; //记录要检测数组下标
        for(int j=1;j<=n;j++){
            Push(p,j);count++;
            if(count > m) break;
            while(!IsEmpty(p) && GetTop(p) == ptr[i][current]){
                Pop(p);count--;
                current++;
            }
        }
        while(!IsEmpty) Pop(p);
        if(current == n) printf("YES\n");
        else printf("NO\n");
    }
    for(int j=0;j<k;j++){ //为每一行分配地址
        free(*(ptr+j));
    }
    system("pause");
    return 0;
}
