//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>
int main() {
    int n, i, a[100];
    int left, right, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    left = 0;
    right = n - 1;

    while(left < right) {
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;

        left++;
        right--;
    }

    printf("Reversed array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
