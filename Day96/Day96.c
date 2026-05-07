//Problem: Count number of inversions using modified merge sort. Inversion if i < j and a[i] > a[j].
#include<stdio.h>
int merge(int a[],int l,int m,int r){
    int i=l,j=m+1,k=0,cnt=0,t[100];
    while(i<=m&&j<=r){
        if(a[i]<=a[j])t[k++]=a[i++];
        else{cnt+=m-i+1;t[k++]=a[j++];}
    }
    while(i<=m)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];
    for(i=l;i<=r;i++)a[i]=t[i-l];
    return cnt;
}
int mergeSort(int a[],int l,int r){
    if(l>=r)return 0;
    int m=(l+r)/2;
    return mergeSort(a,l,m)+mergeSort(a,m+1,r)+merge(a,l,m,r);
}
int main(){
    int a[]={5,3,8,1,2},n=5;
    printf("Inversions: %d\n",mergeSort(a,0,n-1));
}