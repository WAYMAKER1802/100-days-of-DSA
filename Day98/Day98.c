//Problem: Given intervals, merge all overlapping ones.Sort first, then compare with previous. 
#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return ((int*)a)[0]-((int*)b)[0];
}
int main(){
    int a[][2]={{1,3},{2,6},{8,10},{15,18}};
    int n=4;
    qsort(a,n,sizeof(a[0]),cmp);
    int res[n][2],k=0;
    for(int i=0;i<n;i++){
        if(k==0||res[k-1][1]<a[i][0]){
            res[k][0]=a[i][0];
            res[k++][1]=a[i][1];
        } else if(res[k-1][1]<a[i][1])
            res[k-1][1]=a[i][1];
    }
    for(int i=0;i<k;i++)printf("[%d,%d] ",res[i][0],res[i][1]);
}