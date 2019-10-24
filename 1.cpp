#include <stdio.h>
#include <stdlib.h>
#define MAXHEAP 70
#define MIN -10
typedef struct{ //结点结构
    int Weight;
    char S;
}Edge;
typedef struct{ //堆的结构
    int Size;
    Edge *Data;
}*Heap; /
Heap CreateHeap(){
    Heap p = (Heap)malloc(sizeof(Heap));
    p->Data = (Edge*)malloc(sizeof(Edge)*MAXHEAP);
    p->Data[0].Weight = 0;
    p->Size = 0;
    return p;
}
void InsertHeap(Heap p,Edge E){
    int i = (++p->Size)/2;
    for(;p->Data[i].Weight < E.Weight;i = i/2){
        p->Data[i] = p->Data[i/2];
    }
    p->Data[i] = E;
}
Edge DeleteEdge(Heap p){
    int Parenet,Child;
    Edge E = p->Data[p->Size--];
    for(Parenet=1;Parenet <= p->Size;Parenet = Child){
        Child = 2 * Parenet;
        if(Child != p->Size &&p->Data[Child].Weight > p->Data[Child+1].Weight)
            Child++;
    }


    return E;
}

int main(){
    Heap p = CreateHeap();
    
    system("pause");
    return 0;
}