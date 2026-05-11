//Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
//Sort cars by position in descending order and calculate time to reach target.
#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    return ((int*)b)[0]-((int*)a)[0];
}
int carFleet(int target,int*pos,int n,int*speed){
    int idx[n];
    for(int i=0;i<n;i++)idx[i]=i;
    // sort indices by position descending
    int p[n][2];
    for(int i=0;i<n;i++){p[i][0]=pos[i];p[i][1]=speed[i];}
    qsort(p,n,sizeof(p[0]),cmp);
    int fleets=0;
    double top=0;
    for(int i=0;i<n;i++){
        double t=(double)(target-p[i][0])/p[i][1];
        if(t>top){top=t;fleets++;}
    }
    return fleets;
}
int main(){
    int pos[]={10,8,0,5,3},speed[]={2,4,1,1,3},target=12,n=5;
    printf("Fleets: %d\n",carFleet(target,pos,n,speed));
}