#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef int ElementType;
typedef struct LNode *List;
//用数组实现线性表
struct LNode{
    ElementType Data[MAX_SIZE];
    int Last;
};
//函数定义
List MakeEmpty();  //建立空表
int Find(ElementType X,List Ptrl);  //查找
void Inset(ElementType X,int i,List Ptrl);  //插入
void Delete(int i,List Ptrl);  //删除

int main()
{
    /**
     * 以下的是实验
     */
    int i,temp;
    ElementType num = 5;
    List Ptrl = MakeEmpty();
    //表的初始化
    for(i=0;i<MAX_SIZE-1;i++){
        Ptrl->Data[i] = i;
        Ptrl->Last++;
    }
    Inset(num,3,Ptrl);//插入
    Delete(8,Ptrl);   //删除
    for(i=0;i<=Ptrl->Last;i++){
        printf("%d\t",Ptrl->Data[i]);
    }
    printf("\n");
    printf("%d\n",Find(num,Ptrl));
    printf("%d\n",Ptrl->Last);
    return 0;
}

//初始化(建立空的顺序表)
List MakeEmpty(){
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl->Last = -1;
    return Ptrl;
}

//查找
int Find(ElementType X,List Ptrl){
    int i = 0;
    while(i <= Ptrl->Last && Ptrl->Data[i] != X)
        i++;
    if(i > Ptrl->Last) return -1;
    else return i;
}


//插入
void Inset(ElementType X,int i,List Ptrl){//要插入在i位置,插入的下标为i-1
    int j;
    if(Ptrl->Last == MAX_SIZE-1){//表已满,不能插入
        printf("已满");
        return;
    }
    if(i < 1 || i > Ptrl->Last+2){//插入在合法的位置
        printf("位置不合法");
        return;
    }
    for(j=Ptrl->Last;j>=i-1;j--){   //移动表
        Ptrl->Data[j+1] = Ptrl->Data[j];
    }
    Ptrl->Data[i-1] = X; //插入X
    Ptrl->Last++;
    return;
}

//删除
void Delete(int i,List Ptrl){
    int j;
    if(i<i || i > Ptrl->Last+2){
        printf("不存在第%d个元素",i);
        return;
    }
    for(j=i;j<=Ptrl->Last;j++){
        Ptrl->Data[j-1] = Ptrl->Data[j];
    }
    Ptrl->Last--;
    return;
}


