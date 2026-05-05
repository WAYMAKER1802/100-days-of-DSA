//Problem: Sort array of non-negative integers using counting sort.
//Find max, build freq array, compute prefix sums, build output.
#include<stdio.h>
void countSort(int a[],int n){
    int mx=a[0],i;
    for(i=1;i<n;i++)if(a[i]>mx)mx=a[i];
    int cnt[mx+1];
    for(i=0;i<=mx;i++)cnt[i]=0;
    for(i=0;i<n;i++)cnt[a[i]]++;
    for(i=0;i<n;i=i){
        for(int j=0;j<=mx;j++)
            while(cnt[j]--)a[i++]=j;
    }
}
int main(){
    int a[]={4,2,2,8,3,3,1},n=7;
    countSort(a,n);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
}