#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //可以使用布尔型

typedef int ElementTpye;
typedef struct SNode *Stack;
struct SNode{
    ElementTpye Data;
    Stack Next;
};
//操作
Stack CreateStack(); //建立一个结点
int IsEmpty(Stack S); //判断是否为空
void Push(Stack S,ElementTpye X); //入栈
ElementTpye Pop(Stack S); //出栈

int main()
{
    Stack p;
    p = CreateStack();
    Push(p,54);
    Push(p,15);
    Push(p,23);
    printf("%d\n",Pop(p));
    printf("%d\n",IsEmpty(p));
    return 0;
}

//建立空结点
Stack CreateStack(){
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

//判断是否为空
int IsEmpty(Stack S){
    return (S->Next == NULL);
}

//入栈
void Push(Stack S,ElementTpye X){
    Stack TmpCell;
    TmpCell = (Stack)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

//出栈
ElementTpye Pop(Stack S){
    //删除并返回堆栈S的栈顶元素
    Stack FirstCell;
    ElementTpye TopElem;
    if(IsEmpty(S)){
        printf("堆栈空"); return NULL;
    } else {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }

}










































