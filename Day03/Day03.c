//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>
int main() {
    int n, k, i;
    int c = 0;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for(i=0; i<n; i++){
        c++;
        if(arr[i]==k){
            printf("Found at index %d\n", i);
            printf("Comparisions = %d\n", c);
            return 0;
        }
    }
    printf("not found\n");
    printf("Comaprisions = %d\n",c);
    return 0;
}