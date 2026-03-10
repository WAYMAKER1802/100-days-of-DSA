//Problem: Deque (Double-Ended Queue)
#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

void push_front(int x)
{
    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front > 0)
    {
        front--;
    }
    else
    {
        printf("Deque full\n");
        return;
    }

    dq[front] = x;
}

void push_back(int x)
{
    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear < MAX-1)
    {
        rear++;
    }
    else
    {
        printf("Deque full\n");
        return;
    }

    dq[rear] = x;
}

void pop_front()
{
    if(front == -1)
    {
        printf("-1\n");
        return;
    }

    front++;

    if(front > rear)
        front = rear = -1;
}

void pop_back()
{
    if(front == -1)
    {
        printf("-1\n");
        return;
    }

    rear--;

    if(front > rear)
        front = rear = -1;
}

void print_front()
{
    if(front == -1)
        printf("-1\n");
    else
        printf("%d\n", dq[front]);
}

void print_back()
{
    if(front == -1)
        printf("-1\n");
    else
        printf("%d\n", dq[rear]);
}

void size()
{
    if(front == -1)
        printf("0\n");
    else
        printf("%d\n", rear - front + 1);
}

void empty()
{
    if(front == -1)
        printf("1\n");
    else
        printf("0\n");
}

int main()
{
    int n,x;
    char op[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"push_front")==0)
        {
            scanf("%d",&x);
            push_front(x);
        }
        else if(strcmp(op,"push_back")==0)
        {
            scanf("%d",&x);
            push_back(x);
        }
        else if(strcmp(op,"pop_front")==0)
        {
            pop_front();
        }
        else if(strcmp(op,"pop_back")==0)
        {
            pop_back();
        }
        else if(strcmp(op,"front")==0)
        {
            print_front();
        }
        else if(strcmp(op,"back")==0)
        {
            print_back();
        }
        else if(strcmp(op,"size")==0)
        {
            size();
        }
        else if(strcmp(op,"empty")==0)
        {
            empty();
        }
    }

    return 0;
}