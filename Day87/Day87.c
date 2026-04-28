//Problem: Implement Binary Search Iterative - Implement the algorithm.
#include <stdio.h>

int main()
{
    int n, i, key;
    
    scanf("%d", &n);

    int A[n];

    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    scanf("%d", &key);

    int low = 0, high = n - 1, mid;
    int found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(A[mid] == key)
        {
            printf("Element found at index %d", mid);
            found = 1;
            break;
        }
        else if(key < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}