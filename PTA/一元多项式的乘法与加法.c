#include <stdio.h>
#include <stdlib.h>

//定义链表结构
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
    ElementType ceof; //多项式系数
    ElementType expon; //多项式指数
    List Next; //指向下一个结点
};

//函数定义
void Insert(ElementType ceof,ElementType expon,List Ptrl); //插入
List CreateList(); //建立空表
List multi(List p1,List p2); //乘法
List Plus(List p1,List p2); //加法
int compare(List p1,List p2); //比较指数

int main()
{
    List p1,p2;
    List p;
    p1 = CreateList();
    p2 = CreateList();
    int num1,num2;
    int ceof,expon;
    int i;
    scanf("%d",&num1);
    for(i=0;i<num1;i++){
        scanf("%d %d",&ceof,&expon);
        Insert(ceof,expon,p1);
    }
    scanf("%d",&num2);
    for(i=0;i<num2;i++){
        scanf("%d %d",&ceof,&expon);
        Insert(ceof,expon,p2);
    }
    //乘法
    p = multi(p1->Next,p2->Next);
    while(p){
        if(p->Next != NULL){
            printf("%d %d ",p->ceof,p->expon);
        } else {
            printf("%d %d\n",p->ceof,p->expon);
        }
        p = p->Next;
    }
    //实现了加法
    p = Plus(p1->Next,p2->Next);
    if(p){
    	while(p){
        	if(p->Next != NULL){
            	printf("%d %d ",p->ceof,p->expon);
        	} else {
            	printf("%d %d\n",p->ceof,p->expon);
        	}
        	p = p->Next;
    	}
    } else { //防止出现p1,p2抵消为零的情况
    	printf("0 0\n");
	}
    return 0;
}

//乘法,不带头结点
List multi(List p1,List p2){
    List p,p_1,p_2,dele;
    p = CreateList();
    //p_1 = p1->Next;
    //p_2 = p2->Next;
    p_1 = p1;
    p_2 = p2;
    int flag = 1;
    while(p_1){
        List temp;
        temp = CreateList();
        p_2 = p2;
        while(p_2){
        	//ElementType ceof_muti = p_1->ceof*p_2->ceof;
        	//ElementType expen_plus = p_1->expon+p_2->expon;
            Insert((p_1->ceof*p_2->ceof),(p_1->expon+p_2->expon),temp);
            p_2 = p_2->Next;
        }
        /* 打印中间结果temp
        List temp_1 = temp;
        while(temp_1) {
        	printf("%d %d ",temp_1->ceof,temp_1->expon);
        	temp_1 = temp_1->Next;
		}
		printf("\n");*/
		temp = temp->Next; //去除头节点
        if(flag){
            while(temp){
                Insert(temp->ceof,temp->expon,p);
                temp = temp->Next;
            }
            //因为之前赋了初值是0;如果不消除头指针的话
            //会让第一部分一直在队尾
            p = p->Next;
            flag = 0;
        } else {
            p = Plus(p,temp);
        }
        /*打印合并后的结果p
        List temp_2 = p;
        while(temp_2) {
        	printf("%d %d ",temp_2->ceof,temp_2->expon);
        	temp_2 = temp_2->Next;
		}
		printf("\n");*/
        free(temp);
        p_1 = p_1->Next;
    }
    /* 去除头节点,现在以用不到，前面已经去除了
    //printf("multi去非零项之前：%d\n",p->ceof);
	dele = p; //释放头指针
    p = p->Next; //指向多项式的第一个非零项
    free(dele);
    //printf("multi去非零项之后：%d\n",p->ceof);
    */
    return p;
}

//比较系数大小
int compare(List p1,List p2){
    if(p1->expon > p2->expon) return 1;
    else if(p1->expon < p2->expon) return -1;
    else return 0;
}

//加法,传入的不带头结点
List Plus(List p1,List p2){
    List ptr,p_1,p_2,temp_1;
    ptr = CreateList();
    //p_1 = p1->Next;
    //p_2 = p2->Next;
    p_1 = p1;
    p_2 = p2;
	//printf("plus不带头指针p1：%d\n",p_1->ceof);
	//printf("plus不带头指针p2：%d\n",p_2->ceof);
    while(p_1 && p_2){
        int temp_1 = compare(p_1,p_2);
        switch(temp_1){
            case 1:
                Insert(p_1->ceof,p_1->expon,ptr);
                p_1 = p_1->Next;
                break;
            case -1:
                Insert(p_2->ceof,p_2->expon,ptr);
                p_2 = p_2->Next;
                break;
            case 0:
            	if((p_2->ceof + p_1->ceof) == 0)
                {
                    p_1 = p_1->Next;
                    p_2 = p_2->Next;
                } else {
                    Insert((p_2->ceof + p_1->ceof),p_2->expon,ptr);
                    p_1 = p_1->Next;
                    p_2 = p_2->Next;
                }
                break;
            default:
                break;
        }
    }
    for(;p_1;p_1=p_1->Next) Insert(p_1->ceof,p_1->expon,ptr);
    for(;p_2;p_2=p_2->Next) Insert(p_2->ceof,p_2->expon,ptr);
    //printf("plus去非零项之前：%d\n",ptr->ceof);
	temp_1 = ptr; //释放头指针
    ptr = ptr->Next; //指向多项式的第一个非零项
    free(temp_1);
    //printf("plus去非零项之后：%d\n",ptr->ceof);
    return ptr;
}

//建立空表
List CreateList(){
    List p;
    p = (List)malloc(sizeof(struct LNode));
    p->Next = NULL;
    p->ceof = 0;
	p->expon = 0;
    return p;
}

//插入
void Insert(ElementType ceof,ElementType expon,List Ptrl){
    List s,p;
    p = Ptrl;
    while(p->Next) p = p->Next;
    s = CreateList();
    s->ceof = ceof;
    s->expon = expon;
    p->Next = s;
}
