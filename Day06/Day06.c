//Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>
int main() {
    int n, i, j;
    int a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n == 0) return 0;

    j = 0; 

    for (i = 1; i < n; i++) {
        if (a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }

    printf("Array after removing duplicates:\n");
    for (i = 0; i <= j; i++)
        printf("%d ", a[i]);

    return 0;
}
