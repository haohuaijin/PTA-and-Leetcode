/**
 * 这道题的主要思路是：
 * 就是让比结点大的数的插入顺序相同，比结点小的数的插入顺序相同。
 * 但是感觉上面的比较麻烦，我好像写不出来😭😭
 * 所以我把树建立了起来，然后用遍历的方法比较是不是相同
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Leaves *Tree;
struct Leaves{
    int Data;
    Tree left,right;
};
//函数
int **ReadData(int n,int l); //读取数据
Tree CreateNode(int item); //创造节点
Tree Insert(Tree q,int item); //插入
void PreTraverse(Tree q); //前序遍历

int m = 0;
int vec1[100] = {0};
int vec2[100] = {0};

int main()
{
    int n,l;
    int **arr;
    int flag = 1;
    while(1){
        Tree front,rear; 
        scanf("%d",&n);
        if(n == 0) break;
        scanf("%d",&l);
        //读取到arr数据
        arr = ReadData(n,l); 
        //每一次循环将vec1，vec2化为零
        memset(vec1, 0, sizeof(int)*100); //memset函数,将数组元素全化为0
        memset(vec2, 0, sizeof(int)*100); //memset函数,将数组元素全化为0
        //初始化好第一棵树
        front = CreateNode(arr[0][0]);
        for(int i=1;i<n;i++) Insert(front,arr[0][i]); //初始化第一棵树
        //前序遍历第一棵树，保存在vec1中
        m = 0;
        PreTraverse(front);
        for(int i=0;i<m;i++) vec1[i] = vec2[i]; //将前序遍历的结果都存放在vec2中。见PreTraverse函数
        //遍历剩余的树并比较
        for(int i=1;i<=l;i++)
        {
            //初始化树
            m = 0;flag = 1;
            rear = CreateNode(arr[i][0]);
            for(int j=1;j<n;j++) Insert(rear,arr[i][j]); 
            //遍历树
            PreTraverse(rear);
            //比较
            for(int n=0;n<m-1;n++) 
            {
                if(vec1[n] != vec2[n]) 
                {
                    printf("No\n");
                    flag = 0;
                    break;
                }
            }
            if(flag) printf("Yes\n");
        }
        //释放每一行的地址
        for(int i = 0; i <= l; ++i) free(*(arr + i));
    }
    system("pause");
    return 0;
}
int **ReadData(int n,int l)
{
    int num;
    int **arr;
    arr = (int**)malloc(sizeof(int*)*(l+1));
    for(int j=0;j<=l;j++){ //为每一行分配地址
        arr[j] = (int*)malloc(sizeof(int)*n);
    }
    for(int i=0;i<=l;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&num);
            arr[i][j] = num;
        }
    }
    return arr;
}
Tree CreateNode(int item)
{
    Tree q;
    q = (Tree)malloc(sizeof(struct Leaves));
    q->Data = item;
    q->left = q->right = NULL;
    return q;
}
Tree Insert(Tree q,int item)
{
    if(!q){
        q = CreateNode(0);
        q->Data = item;
    } 
    else if(item > q->Data){
        q->right = Insert(q->right,item);
    }
    else if(item < q->Data){
        q->left = Insert(q->left,item);
    }
    return q;
}
void PreTraverse(Tree q)
{
    vec2[m++] = q->Data;
    if(q->left) PreTraverse(q->left);
    if(q->right) PreTraverse(q->right);
}

