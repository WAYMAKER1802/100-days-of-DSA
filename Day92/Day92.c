//Problem: Implement Quick Sort using partition method (Lomuto or Hoare).
#include<stdio.h>
int part(int a[],int l,int r){
int p=a[r],i=l-1,t;
for(int j=l;j<r;j++)
if(a[j]<=p){t=a[++i];a[i]=a[j];a[j]=t;}
t=a[i+1];a[i+1]=a[r];a[r]=t;
return i+1;
}
void qs(int a[],int l,int r){
if(l<r){int p=part(a,l,r);qs(a,l,p-1);qs(a,p+1,r);}
}
int main(){
int a[]={5,3,8,1,2},n=5;
qs(a,0,n-1);
for(int i=0;i<n;i++)printf("%d ",a[i]);
}