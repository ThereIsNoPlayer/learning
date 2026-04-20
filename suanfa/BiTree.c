#include<stdio.h>
#include<stdlib.h>
//2513041719赵天珺
typedef struct BiTreeNode{
    char data;
    struct BiTreeNode *lchild, *rchild;
}BiTreeNode, *BiTree;

BiTree CreateBiTree(BiTree *T){
    char a;
    scanf("%c", &a);
    if(a == '#'){
        *T = NULL;
    }
    else{
        *T=(BiTree)malloc(sizeof(BiTreeNode));
        (*T)->data = a;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }

}

void PreOrder(BiTree T){
    if(T){
        printf("%c ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        printf("%c ", T->data);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ", T->data);
    }
}

void InOrderTraverse(BiTree T){
    BiTreeNode *stack[100];
    int top = -1;
    BiTreeNode *p=T;
    while(p||top!=-1){
        while(p){
            stack[++top]=p;
            p=p->lchild;
        }
        p=stack[top--];
        printf("%c ",p->data);
        p=p->rchild;
    }
}

int NodeCount(BiTree T){
    if(!T) return 0;
    return 1+NodeCount(T->lchild)+NodeCount(T->rchild);
}

int Height(BiTree T){
    if(!T)return 0;
    int lh=Height(T->lchild);
    int rh=Height(T->rchild);
    return(lh>rh?lh:rh)+1;
}

int main(){
    printf("输入二叉树,先序输入空为#\n");
    BiTree T;
    CreateBiTree(&T);

    printf("\n先序遍历: ");PreOrder(T);
    printf("\n中序遍历: ");InOrder(T);
    printf("\n后序遍历: ");PostOrder(T);
    printf("\n中序遍历(非递归): ");InOrderTraverse(T);
    printf("\n节点个数: %d", NodeCount(T));
    printf("\n树的高度: %d\n", Height(T));

    return 0;
}