#include <stdio.h>
#include <stdlib.h>
#define Null -1
#define MAX 15

//树的结构
typedef struct Node *Tree;
struct Node{
    int index;
    int left,right;
};

//队列的结构
typedef struct node *Queue;
struct node{
    int Data[MAX];
    int front,rear;
};



/**
 * 用静态链表的方法实现树的操作时,需要注意的是:
 * 需要在传递树时,加上一个变量,来指示树的根节点在哪里
 */



//树的操作
int ReadData(Tree q); //读取数据
void FindLeaves(Tree q,int root); //找到叶子节点
void middle(Tree q,Queue p,int root); //层次遍历

//队列的操作
void AddQ(Queue q,int number); //入队
int DeleteQ(Queue q); //出队
int IsEmpty(Queue q); //是不是为空
Queue CreateQ(); //创建队列


//全局变量
int count = 0; 
int num[100] = {0}; 
int count_mid = 0;
int mid[100] = {0}; 

int main()
{
    int flag = 1;
    Tree T;
    Queue q = CreateQ(); //初始化队列
    T = (Tree)malloc(sizeof(struct Node)*(100)); //此步不能放在函数里
    int root;
    root = ReadData(T); //读入数据
    FindLeaves(T,root); //找到所有的叶子节点
    middle(T,q,root); //得到层次遍历的结果
    for(int i=0;i<count_mid;i++)
    {
        for(int j=0;j<count;j++)
        {
            if(mid[i] == num[j])
            {
                if(flag)
                {
                    printf("%d",mid[i]);
                    flag = 0;
                    break;
                } 
                else printf(" %d",mid[i]);
            }
        }
    }
    printf("\n");
    system("pause");
    return 0;
}

//层次遍历
void middle(Tree q,Queue p,int root)
{
    int temp;
    AddQ(p,root);
    while(!IsEmpty(p))
    {
        temp = DeleteQ(p);
        mid[count_mid++] = temp;
        if(q[temp].left != Null) AddQ(p,q[temp].left);
        if(q[temp].right != Null) AddQ(p,q[temp].right);
    }
    mid[count_mid] = -1;
} 

//读取数据,找到根节点
int ReadData(Tree q)
{
    char lt,rt; //记录左右结点
    int root; //根节点的下标
    int check[100] = {0}; //记录结点,找到根结点
    int n; //读入的数据
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++) //读入数据
    {
        q[i].index = i;
        scanf("%c %c",&lt,&rt);
        getchar();
        if(lt != '-'){
            q[i].left = lt - '0';
            check[q[i].left] = 1;
        } 
        else q[i].left = Null;
        if(rt != '-'){
            q[i].right = rt - '0';
            check[q[i].right] = 1;
        }
        else q[i].right = Null;
    }
    q[n].index = -1;
    for(int i=0;i<n;i++){ //找到根节点
        if(check[i] == 0){
            root = i;
            break;
        }
    }
    return root;
}

//找到叶子节点
void FindLeaves(Tree q,int root)
{
    if(q[root].left == Null && q[root].right == Null){
        num[count++] = root;
        return;
    }
    if(q[root].left != Null){
        FindLeaves(q,q[root].left);
    }
    if(q[root].right != Null){
        FindLeaves(q,q[root].right);
    }
}
//入队
void AddQ(Queue q,int number)
{
    if((q->rear+1)%MAX == q->front){
        printf("队满\n");
    } 
    q->Data[(++q->rear)%MAX] = number;
    q->rear = (q->rear)%MAX;
}
//出队
int DeleteQ(Queue q)
{
    int number;
    if(q->front == q->rear){
        printf("队空\n"); return Null;
    }
    number = q->Data[(++q->front)%MAX];
    q->front = (q->front)%MAX;
    return number;
}
//创建队列
Queue CreateQ()
{
    Queue q;
    q = (Queue)malloc(sizeof(struct node));
    q->front = 0;
    q->rear = 0;
    return q;
}
//是不是为空
int IsEmpty(Queue q)
{
    return (q->front == q->rear);
}