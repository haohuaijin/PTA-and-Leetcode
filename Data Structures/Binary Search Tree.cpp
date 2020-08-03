#include <stdio.h>
#include <stdlib.h>

/**
 * 链表实现,二叉搜索树
 */
typedef int ElementType;
typedef struct Leaves *BinTree;
struct Leaves{
    ElementType Data;
    BinTree left,right;
};

//操作
BinTree CreateNode(); //新建立结点
BinTree Find(ElementType X,BinTree BST); //递归查找元素
BinTree IterFind(ElementType X,BinTree BST); //非递归查找元素
BinTree FindMin(BinTree BST); //查找最小元素,即最左边结点,递归
BinTree FindMax(BinTree BST); //查找最大元素,即最右边结点,非递归
BinTree Insert(ElementType X,BinTree BST); //插入
BinTree Delete(ElementType X,BinTree BST); //删除

int main()
{
    //小测试
    BinTree q,ptr;
    q = CreateNode();
    q->Data = 3;
    Insert(1,q);
    Insert(4,q);
    Insert(2,q);
    ptr = FindMin(q);
    printf("%d\n",ptr->Data);
    ptr = FindMax(q);
    printf("%d\n",ptr->Data);
    Delete(4,q);
    ptr = FindMax(q);
    printf("%d\n",ptr->Data);
    system("pause");
    return 0;
}

//新建立结点
BinTree CreateNode()
{
    BinTree q;
    q = (BinTree)malloc(sizeof(struct Leaves));
    q->Data = 0;
    q->left = q->right = NULL;
    return q;
}

//递归查找元素
BinTree Find(ElementType X,BinTree BST)
{
    if(!BST) return NULL; //查找失败
    if(X > BST->Data)
        return Find(X,BST->right); //在右子树中继续查找
    else if(X < BST->Data)
        return Find(X,BST->left);
    else
        return BST;
}

//非递归查找元素
BinTree IterFind(ElementType X,BinTree BST)
{
    while(BST){
        if(X > BST->Data) 
            BST = BST->right; //向右子树查找
        else if(X < BST->Data)
            BST = BST->left; //向左子树查找
        else //X == BST->Data
            return BST; //查找成功,返回找到的结点地址
    }
    return NULL; //查找失败
}

//查找最小元素,即最左边结点,递归
BinTree FindMin(BinTree BST)
{
    if(!BST) return NULL; //空白二叉搜索树,返回NULL
    else if(!BST->left)
        return BST; //返回找到的最左边的结点
    else 
        return FindMin(BST->left); //继续向左分支查找
}

//查找最大元素,即最右边结点,非递归
BinTree FindMax(BinTree BST)
{
    if(BST)
        while(BST->right) BST = BST->right; //沿右分支查找
    return BST;
}

//插入
BinTree Insert(ElementType X,BinTree BST)
{
    if(!BST){ //若原树为空，生成并返回一个节点的二叉搜索树
        BST = (BinTree)malloc(sizeof(struct Leaves));
        BST->Data = X;
        BST->left = BST->right = NULL;
    } else { //开始找要插入元素的位置
        if(X < BST->Data)
            BST->left = Insert(X,BST->left); //递归插入左子树
        else if(X > BST->Data)
            BST->right = Insert(X,BST->right); //递归插入右子树
        // else X 已经存在，什么也不操作
    }
    return BST;
}

//删除
BinTree Delete(ElementType X,BinTree BST)
{
    BinTree temp;
    if(!BST) printf("要删除的元素未找到\n");
    else if(X < BST->Data)
        BST->left = Delete(X,BST->left); //左子树递归删除
    else if(X > BST->Data)
        BST->right = Delete(X,BST->right); //右子树递归删除
    else{ //找到了要删除的节点
        if(BST->left && BST->right){ //被删结点有左右两个子节点
            /**
             * 在右子树中找到最小的元素填充删除结点
             */ 
            temp = FindMin(BST->right); 
            BST->Data = temp->Data;
            //在删除结点的右子树中删除最小的元素
            BST->right = Delete(BST->Data,BST->right);
        } else { //被删除的结点有一个或无子结点
            temp = BST;
            if(!BST->left)
                BST = BST->right; //有右孩子或无子节点
            else if(!BST->right)
                BST = BST->left; //有左孩子或无子节点
            free(temp);
        }
    }
    return BST;
}
