#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *List;
struct LNode{
    ElementType Data;
    List Next;
};
//函数定义
int Length(List Ptrl); //求表长
List FindKth(int K,List Ptrl); //按序号查找
List Find(ElementType X,List Ptrl); //按值查找
List Insert(ElementType X,int i,List Ptrl); //插入
List Delete(int i,List Ptrl); //删除
List CreateList(); //建立空表

int main()
{
    List L,P;
    List Ptrl;
    ElementType num1 = 1,num2 = 2;
    L = (List)malloc(sizeof(struct LNode));
    P = (List)malloc(sizeof(struct LNode));
    Ptrl = (List)malloc(sizeof(struct LNode));
    L->Data = num1;
    P->Data = num2;
    L->Next = P;
    P->Next = NULL;
    Ptrl = Insert(num1,1,L);
    printf("%d\n",Length(Ptrl));
    return 0;
}

int Length(List Ptrl){
    List p = Ptrl;  //p指向表的第一个节点
    int j = 0;
    while(p){
        p = p->Next;
        j++;  //当前p指向的是第j个结点
    }
    return j;
}

List FindKth(int K,List Ptrl){
    List p = Ptrl;
    int i = 1;
    while(p != NULL && i < K){
        p = p->Next;
        i++;
    }
    if(i == K) return p; //找到第K个，返回指针
    else return NULL;    //否则返回空
}

List Find(ElementType X,List Ptrl){
    List p = Ptrl;
    while(p != NULL && p->Data != X){
        p = p->Next;
    }
    return p;
}

List Insert(ElementType X,int i,List Ptrl){
    List p,s;
    if(i == 1){   //新结点插入表头
        s = (List)malloc(sizeof(struct LNode)); //申请,填装结点
        s->Next = Ptrl;
        s->Data = X;
        return s;  //返回新的表头
    }
    p = FindKth(i-1,Ptrl);  //查找第i-1个结点
    if(p == NULL){          //若不存在,不能插入
        printf("参数i错误");
        return NULL;
    } else {
        s = (List)malloc(sizeof(struct LNode)); //申请,填装结点
        s->Data = X;
        s->Next = p->Next;  //新结点插入在i-1个结点的后面
        p->Next = s;
        return Ptrl;
    }
}

List Delete(int i,List Ptrl){
    List p,s;
    if(i == 1){ //若删除的是第1个结点
        s = Ptrl;  //s指向第1个结点
        if(Ptrl != NULL) Ptrl = Ptrl->Next; //从链表中删除
        else return NULL;
        free(s);   //释放被删除的结点
        return Ptrl;
    }
    p = FindKth(i-1,Ptrl);  //查找第i-1个结点
    if(p == NULL){
        printf("第%d个结点不存在",i-1);
    } else if(p->Next == NULL){
        printf("第%d个结点不存在",i);
    } else{
        s = p->Next;        //s指向第i个结点
        p->Next = s->Next;  //从链表删除第i个结点
        free(s);            //释放被删除的结点
        return Ptrl;
    }
}

























