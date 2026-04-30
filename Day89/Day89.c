//Problem Statement Given an array of integers where each element represents the number of pages in a book, and m students, 
// allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized. 
// Books must be allocated in contiguous order.
#include <stdio.h>

int isPossible(int arr[], int n, int m, int mid)
{
    int student = 1;
    int pages = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > mid)
            return 0;

        if(pages + arr[i] <= mid)
        {
            pages += arr[i];
        }
        else
        {
            student++;
            pages = arr[i];

            if(student > m)
                return 0;
        }
    }

    return 1;
}

int allocatePages(int arr[], int n, int m)
{
    int max = arr[0], sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];

        sum += arr[i];
    }

    int low = max;
    int high = sum;
    int answer = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid))
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return answer;
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", allocatePages(arr, n, m));

    return 0;
}