//Problem: Implement merge sort (divide, sort halves, merge).
//Print sorted array.
#include<stdio.h>
void merge(int a[],int l,int m,int r){
int i=l,j=m+1,k=0,t[100];
while(i<=m&&j<=r)
t[k++]=a[i]<=a[j]?a[i++]:a[j++];
while(i<=m)t[k++]=a[i++];
while(j<=r)t[k++]=a[j++];
for(i=l;i<=r;i++)a[i]=t[i-l];
}
void ms(int a[],int l,int r){
if(l<r){int m=(l+r)/2;ms(a,l,m);ms(a,m+1,r);merge(a,l,m,r);}
}
int main(){
int a[]={5,3,8,1,2},n=5;
ms(a,0,n-1);
for(int i=0;i<n;i++)printf("%d ",a[i]);
}