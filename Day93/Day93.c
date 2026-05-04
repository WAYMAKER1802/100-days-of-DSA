//Problem: Sort an array using insertion sort. 
// Stable sort. Good for nearly sorted arrays.
#include<stdio.h>
void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0&&a[j]>key)
            a[j+1]=a[j--];
        a[j+1]=key;
    }
}
int main(){
    int a[]={5,3,8,1,2},n=5;
    insertionSort(a,n);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
}