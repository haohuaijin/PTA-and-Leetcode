#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //应用bool类型
#define MAX_SIZE 10

typedef int ElementType;
ElementType ERROR = -1;
typedef struct SNode *Stack;
struct SNode{
    ElementType *Data;
    int Top;
    int MaxSize;
};
//操作
Stack CreateStack(int MaxSize); //建立空表
bool IsFull(Stack S); //判断是否栈满
bool Push(Stack PtrS,ElementType item); //入栈
bool IsEmpty(Stack S); //判断是否为空
ElementType Pop(Stack PtrS); //出栈


int main()
{
    Stack p;
    p = CreateStack(10);
    Push(p,5);
    Push(p,10);
    printf("%d\n",p->Data[p->Top]);
    Pop(p);
    printf("%d\n",p->Data[p->Top]);
    return 0;
}

//建立空表
Stack CreateStack(int MaxSize){
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

//判断是否栈满
bool IsFull(Stack S){
    return (S->Top == S->MaxSize-1);
}


//入栈
bool Push(Stack PtrS,ElementType item){
    if(IsFull(PtrS)){
        printf("堆栈已满\n");
        return false;
    } else{
        PtrS->Data[++(PtrS->Top)] = item;
        return true;
    }
}

//判断是否为空
bool IsEmpty(Stack S){
    return (S->Top == -1);
}

ElementType Pop(Stack PtrS){//出栈
    if(IsEmpty(PtrS)){
        printf("此栈为空");
        return ERROR;
    } else {
        return (PtrS->Data[(PtrS->Top)--]);
    }

}


























