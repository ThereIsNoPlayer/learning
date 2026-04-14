//2513041719赵天珺 9/3/26
#include<stdio.h>
#include<stdlib.h>
typedef float ElemType;
typedef ElemType* Triplet;
typedef struct{
    Triplet data;
}Triple;
int InitTriplet(Triple *T,ElemType a,ElemType b,ElemType c){
    T->data = (Triplet)malloc(3*sizeof(ElemType));
    if(T->data==NULL){return 0;}
    T->data[0]=a;
    T->data[1]=b;
    T->data[2]=c;
    return 1;
}
int Get(Triple T,int i,ElemType* e){
    if(i<1||i>3){
        return 0;
    }
    *e=T.data[i-1];
    return 1;
}
int Put(Triple T,int i,ElemType e){
    if(i<1||i>3){
        return 0;
    }
    T.data[i-1]=e;
    return 1;
}
int getMax(Triple T, ElemType* max) {
    *max=T.data[0];
    for(int i=1;i<3;i++){
        if(T.data[i]>*max){
            *max=T.data[i];
        }

    }
    return 1;
}
int getMin(Triple T,ElemType* min){
    *min=T.data[0];
    for(int i=1;i<3;i++){
        if(T.data[i]<*min){
            *min=T.data[i];
        }
    }
    return 1;
}
int Plus(Triple a,Triple b,Triple* c){
    c->data=(Triplet)malloc(3*sizeof(ElemType));
    if(c->data==NULL){return 0;}
    for(int i=0;i<3;i++){
        c->data[i]=a.data[i]+b.data[i];
    }
    return 1;
}
int Minus(Triple a,Triple b,Triple *c){
    c->data=(Triplet)malloc(3*sizeof(ElemType));
    if(c->data==NULL){return 0;}
    for(int i=0;i<3;i++){
        c->data[i]=a.data[i]-b.data[i];
    }
    return 1;
}
int Multiply(Triple T,ElemType fac,Triple *result){
    result->data=(Triplet)malloc(3*sizeof(ElemType));
    if(result->data==NULL){
        return 0;
    }
    for(int i=0;i<3;i++){
        result->data[i]=T.data[i]*fac;
    }
    return 1;
}
void Print(Triple T){
    printf("(%.2f,%.2f,%.2f)\n",T.data[0],T.data[1],T.data[2]);
}
void Destroy(Triple *T){
    free(T->data);
    T->data=NULL;
}
int main(){
    Triple T;
    ElemType e,max,min;
    int a,b,c;
    //scanf("%f%f%f",a,b,c);
    InitTriplet(&T,2.3,5.2,7.0);
    printf("三元组：");
    Print(T);
    Get(T,2,&e);
    printf("第%d个:%.2f\n",2,e);
    Put(T,1,9.0);
    printf("修改后:");
    Print(T);
    getMax(T, &max);
    printf("最大:%.2f\n",max);
    getMin(T,&min);
    printf("最小:%.2f\n",min);
    Triple T2,T3,TEMP;
    printf("第2组:");
    InitTriplet(&T2,1.6,4.5,8.0);
    Print(T2);
    printf("第3组:");
    InitTriplet(&T3,2.4,3.2,6.4);
    Print(T3);
    printf("两组相加:");
    Plus(T2,T3,&TEMP);
    Print(TEMP);
    printf("两组相减:");
    Minus(T2,T3,&TEMP);
    Print(TEMP);
    printf("第一组(修改后)与3.0相乘");
    Multiply(T,3.0,&TEMP);
    Print(TEMP);


    Destroy(&T);
    printf("三元组已销毁");
}
