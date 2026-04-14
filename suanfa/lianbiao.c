#include<stdio.h>
#include<stdlib.h>
//2513041719赵天珺
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

void ListCreate_Head(LinkList *L, int n) {
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (int i = 0; i < n; i++) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
void ListCreate_Tail(LinkList *L, int n) {
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    LNode *tail = *L;
    for (int i = 0; i < n; i++) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}
int ListInsert(LinkList L, int i, int e) {
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return 0;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}
int ListDelete(LinkList L,int i,int *e){
    LNode *p=L;
    int j=0;
    while(p->next&&j<i-1){
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i-1){
        return 0;
    }
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return 1;
}
LNode* ElemLocate(LinkList L,int e){
    LNode *p=L->next;
    while(p){
        if(p->data==e){return p;}
        p=p->next;
    }
}
void ListShow(LinkList L){
    LNode* p=L->next;
    while(p){
        printf("%d,",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    LinkList L;
    int e,n,p,choice,num;
    do{
        printf("===单链表操作菜单===\n");
        printf("1.创建链表\n");
        printf("2.插入元素\n");
        printf("3.删除元素\n");
        printf("4.查找元素\n");
        printf("5.显示链表\n");
        printf("0.退出\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("插入方法:   1.头插 2.尾插");
                scanf("%d",&num);
                printf("输入元素个数n:");
                scanf("%d",&n);
                if(num==1){
                    ListCreate_Head(&L,n);
                }
                else if(num==2){
                    ListCreate_Tail(&L,n);
                }else{printf("输入错误！\n");}
                printf("创建成功!\n");
                break;
            case 2:
                printf("请输入插入的位置和元素值:");
                scanf("%d%d",&p,&e);
                if (ListInsert(L, p, e))
                    printf("插入成功！\n");
                else
                    printf("插入失败！\n");
                break;
            case 3:
                printf("请输入删除的位置:");
                scanf("%d",&p);
                if(ListDelete(L,p,&e)){
                    printf("删除元素:%d\n",e);
                }else{printf("删除失败\n");}
                break;
            case 4:
                printf("请输入要查找的元素:");
                scanf("%d",&e);
                if(ElemLocate(L,e)){
                    printf("找到了元素%d\n",e);
                }else{printf("未找到元素%d\n",e);}
                break;
            case 5:
                ListShow(L);
                break;
        }
    }while(choice!=0);
    return 0;
}







//菜单程序，头插、尾插,每一个功能对应一种结果