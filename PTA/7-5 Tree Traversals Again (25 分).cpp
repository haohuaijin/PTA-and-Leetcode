#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode *Tree; //树
struct TreeNode{
    int Data;
    Tree Left,Right;
};
typedef struct node *Stack; //栈
struct node{
    Tree Node;
    Stack Next;
};
Tree CreateTreeNode(int X){
    Tree q = (Tree)malloc(sizeof(struct TreeNode));
    q->Data = X;
    q->Left = q->Right = NULL;
    return q;
}  
Stack CreateStack(){
    Stack q = (Stack)malloc(sizeof(struct node));
    q->Node = NULL; //树
    q->Next = NULL; //下一结点
    return q;
}
void Push(Stack p,Tree node){
    Stack ptr = CreateStack();
    ptr->Next = p->Next;
    p->Next = ptr;
    ptr->Node = node;
}
Tree Pop(Stack p){
    Tree q;
    Stack ptr = p->Next;
    p->Next = ptr->Next;
    q = ptr->Node;
    free(ptr);
    return q;
}
Tree GetTop(Stack p){
    if(p->Next) 
        return p->Next->Node;
    else 
        return NULL;
}
int Flag = 1; //控制打印
void PostTraversals(Tree q){
    if(q->Left) PostTraversals(q->Left);
    if(q->Right) PostTraversals(q->Right);
    if(Flag){
        printf("%d",q->Data);
        Flag = 0;
    }
    else 
        printf(" %d",q->Data);
}
int main(){
    int n,num,sign = 0,flag = 1;
    Stack stack = CreateStack();
    Tree tree = CreateTreeNode(0);
    Tree PopNode;
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        char string[5];
        scanf("%s",string);
        if(flag){
            scanf("%d",&num);
            tree->Data = num;
            Push(stack,tree);
            flag = 0;
            continue;
        }
        if(strcmp(string,"Push") == 0){ //Push
            //Stack空，入栈
            scanf("%d",&num);
            Tree New = CreateTreeNode(num);
            if(sign){ //Push前面有Pop，PopNode
                if(!PopNode->Left){
                    PopNode->Left = New;
                }
                else if(!PopNode->Right){
                    PopNode->Right = New;
                }
                Push(stack,New);
            }
            else { //Push前面是Push，用栈的Top元素
                Tree Temp = GetTop(stack);
                if(!Temp->Left){
                    Temp->Left = New;
                }
                else if(!Temp->Right){
                    Temp->Right = New;
                }
                Push(stack,New);
            }
            sign = 0;
        }
        else //Pop
        {
            PopNode = Pop(stack);
            sign = 1;
        }
    }
    PostTraversals(tree);
    printf("\n");
    system("pause");
    return 0;
}
