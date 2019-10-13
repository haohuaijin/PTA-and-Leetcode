#include <stdio.h>
#include <stdlib.h>
typedef struct node List;
struct node{ //类此静态链表
    int Address,Rear;
    int Data;
};
void Reavers(int *front,int *rear,int k){ 
    int i = 0,a[k];
    for(int *p = front;p != rear+1;p++){ //先储存
        a[i++] = *p;
    } 
    i = 0;
    for(int *p = rear;p != front-1;p--){ 
        *p = a[i++];
    }
}
int main(){
    int first,total,k,count = 0;
    int *a;
    List *p;
    scanf("%d%d%d",&first,&total,&k);
    p = (List*)malloc(sizeof(struct node)*total);
    a = (int*)malloc(sizeof(int)*total);
    for(int i=0;i<total;i++){
        scanf("%d%d%d",&p[i].Address,&p[i].Data,&p[i].Rear);
    }
    while(1){ //将List恢复正常序列,用a[]记录索引。 复杂度n^2 应优化这里(结果去掉break)
        for(int i=0;i<total;i++){
            if(first == p[i].Address){
                a[count++] = i;
                first = p[i].Rear;
//                break; //开始找到1个就break,现在一直往下找
            }
        }
        if(first == -1) break;
    }
    //用count代表有多少结点在链表上
    for(int i=0;i<(count/k);i++){ //逆转
        for(int j=k-1;j>0;j--){
            p[a[j+i*k]].Rear = p[a[j+i*k-1]].Address;
        }
        if(i != 0) p[a[i*k-1]].Rear = p[a[k+i*k-1]].Address; //修改逆转序列的前一个元素的Rear
        //注意前后的连接
        if(i == count/k - 1 && (count%k == 0)) p[a[i*k]].Rear = -1; //修改逆转序列的最后元素的Rear
        else p[a[i*k]].Rear = p[a[i*k+k]].Address;
        Reavers((a+k*i),(a+k*(i+1)-1),k); //逆转索引a[]
    }
    for(int i=0;i<count;i++){
        if(i == count - 1){
            printf("%05d %d %d\n",p[a[i]].Address,p[a[i]].Data,p[a[i]].Rear);
            break;
        } 
        printf("%05d %d %05d\n",p[a[i]].Address,p[a[i]].Data,p[a[i]].Rear);
    }
    system("pause");
    return 0;
}