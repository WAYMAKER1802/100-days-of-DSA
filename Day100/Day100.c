//Problem: For each element, count how many smaller elements appear on right side. Use merge sort technique or Fenwick Tree (BIT).
#include<stdio.h>
int res[100];
void merge(int idx[],int tmp[],int a[],int l,int m,int r){
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r){
        if(a[idx[i]]<=a[idx[j]]){
            res[idx[i]]+=r-j+1; // count elements on right that are smaller... wait
            // actually count j-m-1 already passed
            tmp[k++]=idx[i++];
        } else tmp[k++]=idx[j++];
    }
    while(i<=m)tmp[k++]=idx[i++];
    while(j<=r)tmp[k++]=idx[j++];
    for(int i=l;i<=r;i++)idx[i]=tmp[i];
}
void ms(int idx[],int tmp[],int a[],int l,int r){
    if(l>=r)return;
    int m=(l+r)/2;
    ms(idx,tmp,a,l,m);
    ms(idx,tmp,a,m+1,r);
    // count before merge
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r){
        if(a[idx[i]]>a[idx[j]]){res[idx[i]]+=r-j+1;i++;}
        else j++;
    }
    // now merge
    i=l;j=m+1;
    while(i<=m&&j<=r)
        tmp[k++]=a[idx[i]]<=a[idx[j]]?idx[i++]:idx[j++];
    while(i<=m)tmp[k++]=idx[i++];
    while(j<=r)tmp[k++]=idx[j++];
    for(int i=l;i<=r;i++)idx[i]=tmp[i];
}
int main(){
    int a[]={5,2,6,1},n=4;
    int idx[n],tmp[n];
    for(int i=0;i<n;i++)idx[i]=i,res[i]=0;
    ms(idx,tmp,a,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",res[i]);
}