//Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.
#include <stdio.h>

int lowerBound(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    int ans = n;  // default if not found

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(arr[mid] >= x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

// Function to find upper bound
int upperBound(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    int ans = n;  // default if not found

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(arr[mid] > x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, x;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target value: ");
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower Bound Index: %d\n", lb);
    printf("Upper Bound Index: %d\n", ub);

    return 0;
}