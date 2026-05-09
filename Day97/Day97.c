//Problem: Given meeting intervals, find minimum number of rooms required.
//Sort by start time and use min-heap on end times.
#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return ((int*)a)[0]-((int*)b)[0];
}
int minRooms(int meet[][2],int n){
    qsort(meet,n,sizeof(meet[0]),cmp);
    int heap[n],sz=0,rooms=0;
    for(int i=0;i<n;i++){
        // remove all rooms that freed up
        int j=0;
        while(j<sz&&heap[j]<=meet[i][0])j++;
        if(j>0){
            heap[0]=heap[--sz];
            // re-heapify
            int k=0;
            while(2*k+1<sz){
                int c=2*k+1;
                if(c+1<sz&&heap[c+1]<heap[c])c++;
                if(heap[k]<=heap[c])break;
                int t=heap[k];heap[k]=heap[c];heap[c]=t;
                k=c;
            }
        }
        // push end time
        heap[sz++]=meet[i][1];
        int k=sz-1;
        while(k>0&&heap[(k-1)/2]>heap[k]){
            int t=heap[k];heap[k]=heap[(k-1)/2];heap[(k-1)/2]=t;
            k=(k-1)/2;
        }
        if(sz>rooms)rooms=sz;
    }
    return rooms;
}
int main(){
    int meet[][2]={{0,30},{5,10},{15,20}};
    printf("Rooms: %d\n",minRooms(meet,3));
}