//Problem Statement: Given an array of integers containing both positive and negative values,
//  find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>

int maxLen(int arr[], int n)
{
    int sum = 0, maxLength = 0;

    int hash[1000];
    int index[1000];

    for(int i = 0; i < 1000; i++)
        hash[i] = -1;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum == 0)
            maxLength = i + 1;

        int key = sum + 500; 

        if(hash[key] == -1)
            hash[key] = i;
        else
        {
            int length = i - hash[key];
            if(length > maxLength)
                maxLength = length;
        }
    }

    return maxLength;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}
