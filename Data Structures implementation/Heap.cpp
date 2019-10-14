#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXDATA 10000
typedef int ElementType;
typedef struct node{
    ElementType *Data; //数据
    int size; //当前大小
    int Capacity; //总容量
}*Heap;
Heap CreateHeap(int MaxSize){
    Heap p = (Heap)malloc(sizeof(struct node));
    p->Data = (ElementType*)malloc((sizeof(ElementType))*(MaxSize+1));
    p->size = 0;
    p->Capacity = MaxSize;
    p->Data[0] = MAXDATA; //定义"哨兵"大于堆中的最大元素
    return p;
}
bool Is_Full(Heap p){
    return (p->Capacity == p->size);
}
bool Insert(Heap p,ElementType X){ 
    int i;
    if(Is_Full(p)){
        printf("堆已满\n");
        return false;
    }
    else{
        i = ++p->size; //i指向堆最后一个元素
        for(;p->Data[i/2] < X;i/=2) 
            p->Data[i] = p->Data[i/2]; //上滤X
        p->Data[i] = X; //将X插入
    }
    return true;
}
bool Is_Empty(Heap p){
    return (p->size == 0);
}
ElementType DeleteMax(Heap p){ //取出最大值,并删除
    int Parent,Child;
    ElementType MaxItem,X;
    if(Is_Empty(p)) {
        printf("堆空\n");
        return -1;
    }
    MaxItem = p->Data[1]; //取出最大值,用最大堆的最后一个元素从上到下过滤
    X = p->Data[p->size--];//堆规模减小
    for(Parent = 1;Parent*2 <= p->size;Parent = Child){
        Child = 2*Parent;
        if((Child != p->size) && (p->Data[Child] < p->Data[Child+1]))
            Child++; //Child指向左右儿子较大的
        if(X >= p->Data[Child]) break;
        else //下滤
            p->Data[Parent] = p->Data[Child];
    }
    p->Data[Parent] = X;
    return MaxItem;
}
/*--------建造最大堆-------*/
void PercDown(Heap p,int pos){
    //下滤:将p中以p->Data[pos]为根的子堆调整为最大堆
    int Parent,Child;
    ElementType X;
    X = p->Data[pos]; //取出根结点存放的值
    for(Parent = pos;Parent*2 <= p->size;Parent = Child){
        Child = Parent*2;
        if((Child != p->size) && (p->Data[Child] < p->Data[Child+1]))
            Child++; //Child指向左右子节点的较大者
        if(X >= p->Data[Child]) break; //找到合适位置
        else //下滤
            p->Data[Parent] = p->Data[Child];
    }
    p->Data[Parent] = X;
}
void BuildHeap(Heap p){
    //调整p->Data[]中元素的有序性
    //假设所有p->size中的元素已经存在p->Data
    for(int i = p->size/2;i>0;i--)
        PercDown(p,i);
}
int main(){
    //测试
    Heap p = CreateHeap(100);
    for(int i=1;i<=5;i++){
        p->Data[i] = 2*i;
        p->size++;
    }
    Insert(p,12);
    Insert(p,7);
    BuildHeap(p);
    for(int i=1;i<=p->size;i++){
        printf("%d\n",p->Data[i]);
    }
    system("pause");
    return 0;
}