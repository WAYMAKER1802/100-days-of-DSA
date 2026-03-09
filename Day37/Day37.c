//Problem Statement:Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x)
{
    pq[size++] = x;
}

int getMinIndex()
{
    if(size == 0)
        return -1;

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    return minIndex;
}

void delete()
{
    int index = getMinIndex();

    if(index == -1)
    {
        printf("-1\n");
        return;
    }

    int val = pq[index];

    for(int i = index; i < size-1; i++)
    {
        pq[i] = pq[i+1];
    }

    size--;

    printf("%d\n", val);
}

void peek()
{
    int index = getMinIndex();

    if(index == -1)
        printf("-1\n");
    else
        printf("%d\n", pq[index]);
}

int main()
{
    int n;
    char op[10];
    int x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"insert") == 0)
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete") == 0)
        {
            delete();
        }
        else if(strcmp(op,"peek") == 0)
        {
            peek();
        }
    }

    return 0;
}