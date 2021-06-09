#include <stdio.h>
#include <stdlib.h>
#include "../treenode/treenode.h"

// 记录前一个节点的
void postorder(TreeNode *root){
    TreeNode **st = (TreeNode**)malloc(sizeof(TreeNode*)*20);
    int top = 0;
    TreeNode* prev = NULL;
    while(root != NULL || top > 0){
        while (root != NULL) {
            st[top++] = root;
            root = root->left;
        }
        root = st[--top];
        if(root->right == NULL || root->right == prev){
            visit(root);
            prev = root;
            root = NULL;
        } else {
            st[top++] = root;
            root = root->right;
        }
    }
    free(st);
}

// 使用标志位第一种写法
void postflag_one(TreeNode *root){
    TreeNode** st = (TreeNode**)malloc(sizeof(TreeNode*)*20);
    int top = 0;
    TreeNode* cur = root;
    while(cur != NULL || top >0){
        while(cur != NULL){
            cur->flag = 0;
            st[top++] = cur;
            cur = cur->left;
        }
        while(top != 0 && st[top-1]->flag == 1){
            visit(st[top-1]);
            --top;
        }
        if(top != 0){
            st[top-1]->flag = 1;
            cur = st[top-1]->right;
        }
    }
}
// 使用标志位第二种写法
void postflag_two(TreeNode *root){
    TreeNode **st = (TreeNode**)malloc(sizeof(TreeNode*)*20);
    int top = 0;
    TreeNode *cur = root;
    while(cur != NULL || top > 0){
        while(cur != NULL){
            cur->flag = 0;
            st[top++] = cur;
            cur = cur->left;
        }
        if(top > 0){
            cur = st[top-1];
            if(cur->flag == 0){
                cur->flag = 1;
                cur = cur->right;
            } else if (cur->flag ==1) {
                visit(cur);
                --top; // 出栈
                cur = NULL;
            }
        }
    }
}

int main(){
    /*
         1
       /   \
      2     3
       \   / \
        4 5   6
    */
    TreeNode* root =  CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->right = CreateNode(4);
    root->right->left = CreateNode(5);
    root->right->right = CreateNode(6);

    printf("   Postorder traversal:");
    postorder(root);
    printf("\n");

    printf("Postflag_one traversal:");
    postflag_one(root);
    printf("\n");

    printf("Postflag_two traversal:");
    postflag_two(root);
    printf("\n");


    DeleteTree(root);
    return 0;
}
