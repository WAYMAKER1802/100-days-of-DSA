//Problem Statement : Given n boards of different lengths and k painters, each painter paints contiguous boards. 
// Painting a unit length of board takes one unit of time.
#include <stdio.h>

int possible(int boards[], int n, int k, int mid)
{
    int painters = 1;
    int time = 0;

    for(int i = 0; i < n; i++)
    {
        if(boards[i] > mid)
            return 0;

        if(time + boards[i] <= mid)
        {
            time += boards[i];
        }
        else
        {
            painters++;
            time = boards[i];

            if(painters > k)
                return 0;
        }
    }

    return 1;
}

int minTime(int boards[], int n, int k)
{
    int max = boards[0], sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(boards[i] > max)
            max = boards[i];

        sum += boards[i];
    }

    int low = max, high = sum, ans = sum;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(possible(boards, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &boards[i]);

    printf("%d", minTime(boards, n, k));

    return 0;
}