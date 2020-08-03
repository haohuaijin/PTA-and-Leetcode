#include <stdio.h>
#include <stdlib.h>

//定义AVL树
typedef int ElementType;
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode{
    ElementType Data;
    AVLTree left,right;
    int height; //树高
};

//函数
AVLTree CreateNode(int X); //创造节点
int Max(int a,int b); //求最大值
int GetHeight(AVLTree q); //返回树的高度
AVLTree SingleLeftRotation(AVLTree A); //左单旋
AVLTree DoubleLeftRightRotation(AVLTree A); //左-右双旋
AVLTree SingleRightRotation(AVLTree A); //右单旋
AVLTree DoubleRightLeftRotation(AVLTree A); //右-左双旋
AVLTree Insert(AVLTree T,ElementType X); //插入
void PreTraverse(AVLTree q); //前序遍历

int main()
{
    AVLTree q = NULL;
    q = Insert(q,88);
    q = Insert(q,70);
    q = Insert(q,61);
    q = Insert(q,96);
    q = Insert(q,120);
    q = Insert(q,90);
    q = Insert(q,65);
    PreTraverse(q); //前序遍历
    printf("\n");
    system("pause");
    return 0;
}

//创造结点
AVLTree CreateNode(int X)
{
    AVLTree q;
    q = (AVLTree)malloc(sizeof(struct AVLNode));
    q->Data = X;
    q->height = 0;
    q->left = q->right = NULL;
    return q;
}

int Max(int a,int b){
    return a > b ? a : b;
}

//获得树高
int GetHeight(AVLTree q)
{
    int HL,HR,MaxH;
    if(q){
        HL = GetHeight(q->left);
        HR = GetHeight(q->right);
        MaxH = (HL > HR) ? HL : HR;
        return (MaxH + 1);
    }
    else return 0; //空树返回0
}


/**
 * 注意：A必须有一个左子节点B
 * 将A与B做左单旋，更新A与B的高度，返回新的根节点B
 */
AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = Max(GetHeight(A->left),GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left),A->height) + 1;
    return B;
}


/**
 * 注意A必须有一个左子节点B，且B必须有一个右子节点C
 * 将A，B与C左两次单旋，返回新的节点C
 */
AVLTree DoubleLeftRightRotation(AVLTree A)
{
    //将B与C做右单旋，C被返回
    A->left = SingleRightRotation(A->left);
    //将A与C做左单旋，C被返回
    return SingleLeftRotation(A);
}


/**
 * 注意：A必须有一个右子节点B
 * 将A与B做右单旋，更新A与B的高度，返回新的根节点B
 */
AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = Max(GetHeight(A->left),GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->right),A->height) + 1;
    return B;
}


/**
 * 注意A必须有一个右子节点B，且B必须有一个左子节点C
 * 将A，B与C左两次单旋，返回新的节点C
 */
AVLTree DoubleRightLeftRotation(AVLTree A)
{
    //将B与C做左单旋，C被返回
    A->right = SingleLeftRotation(A->right);
    //将A与C做右单旋，C被返回
    return SingleRightRotation(A);
}
//将X插入AVL树T中，并返回调整后的AVL树
AVLTree Insert(AVLTree T,ElementType X)
{
    if(!T){ //空树，则新建包含一个结点的树
        T = CreateNode(X);
    }
    else if(X < T->Data){
        //插入到T的左子树
        T->left = Insert(T->left,X);
        //如果需要左旋
        if(GetHeight(T->left)-GetHeight(T->right) == 2){
            if(X < T->left->Data)
                T = SingleLeftRotation(T); //左单旋
            else 
                T = DoubleLeftRightRotation(T); //左-右双旋
        }
    }
    else if(X > T->Data){
        //插入到T的右子树
        T->right = Insert(T->right,X);
        //如果需要右旋
        if(GetHeight(T->left) - GetHeight(T->right) == -2){
            if(X > T->right->Data)
                T = SingleRightRotation(T); //右单旋
            else 
                T = DoubleRightLeftRotation(T); //右-左单旋
        }
    }
    //else X == T->Data 无需插入
    //更新树高，谨记
    T->height = Max(GetHeight(T->right),GetHeight(T->left)) + 1;
    return T;
}


//前序遍历
void PreTraverse(AVLTree q)
{
    if(q){
        printf("%d ",q->Data);
        PreTraverse(q->left);
        PreTraverse(q->right);
    }
}











