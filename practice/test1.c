#include<stdio.h>
#include<string.h>
int main() {
    char a[100005],b[100005],sum1[100005];
    scanf("%s%s",a,b);
    int l=strlen(a)-1;
    int m=strlen(b)-1;
    int n=0;
    int c=0;
    while (l>=0||m>=0||c==1) {
        int na=0,nb=0,sum=0;
        if (l>=0) {
            na=a[l]-'0';
            l--;
        }
        if (m>=0) {
            nb=b[m]-'0';
            m--;
        }
        sum=na+nb+c;
        sum1[n]=(sum%10)+'0';
        n++;
        c=sum/10;
    }
    for (int high=0,low=n-1;high<low;high++,low--) {
        char temp=sum1[high];
        sum1[high]=sum1[low];
        sum1[low]=temp;
    }
    int s0=0;
    for (s0=0;sum1[s0]=='0'&&s0<n-1;s0++);
    char *p;
    p=sum1+s0;
    printf("%s\n",p);
    return 0;
}