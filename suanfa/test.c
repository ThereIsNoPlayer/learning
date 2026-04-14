#include<stdio.h>
#include<stdlib.h>

typedef struct BiTreeNode{
    char data;
    struct BiTreeNode *lchild, *rchild;
}BiTreeNode, *BiTree;

void 