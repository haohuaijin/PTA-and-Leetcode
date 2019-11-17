/**
 * 基数排序 - 次位优先
 * 假设最多有MaxDigit个关键字,基数全是同样的的Radix
 */ 
#include <iostream>
using namespace std;
const int MaxDigit = 4;
const int Radix = 10;
//桶元素结点
typedef struct Node *PtrToNode;
struct Node{
    int key;
    PtrToNode next;
};
//桶头结点
struct HeadNode{
    PtrToNode head,tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X,int D){
    //默认次位D=1,主位D<=MaxDigit
    int d,i;
    for(i=1;i<=D;i++){
        d = X % Radix;
        X /= Radix;
    }
    return d;
}

void LSDRadix_Sort(int *a,int N){
    int D, Di, i;
    Bucket B;
    PtrToNode tmp, p, List = NULL;

    for(i=0;i<Radix;i++) //初始化每个桶为空链表
        B[i].head = B[i].tail = NULL;
    for(i=0;i<N;i++){ //将原始序列逆序插入初始链表
        tmp = (PtrToNode)malloc(sizeof(struct Node));
        tmp->key = a[i];
        tmp->next = List;
        List = tmp;
    }
    for(D=1;D<=MaxDigit;D++){
        //分配过程
        p = List;
        while(p){
            Di = GetDigit(p->key,D); //获取当前元素的当前位数字
            //从List移除
            tmp = p;
            p = p->next;
            //插入B[Di]号桶尾
            tmp->next = NULL;
            if(B[Di].head == NULL)
                B[Di].head = B[Di].tail = tmp;
            else{
                B[Di].tail->next = tmp;
                B[Di].tail = tmp;
            }
        }
        //收集过程
        List = NULL;
        for(Di=Radix-1;Di>=0;Di--){ //将每个桶的元素收入List
            if(B[Di].head) { //如果桶不空
                //整桶插入List
                B[Di].tail->next = List;
                List = B[Di].head;
                B[Di].head = B[Di].tail = NULL; //清空桶
            }
        }
    }
    //将List倒入a[]并释放空间
    for(i=0;i<N;i++){
        tmp = List;
        List = List->next;
        a[i] = tmp->key;
        free(tmp);
    }
}
int main(){


    system("pause");
    return 0;
}