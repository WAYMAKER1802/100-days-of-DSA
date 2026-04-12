//Problem Statement: Implement a hash table using quadratic probing with formula:
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];
void init()
{
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;

    if(hashTable[index] == -1)
    {
        hashTable[index] = key;
        return;
    }

    for(int i = 1; i < SIZE; i++)
    {
        int newIndex = (index + i*i) % SIZE;

        if(hashTable[newIndex] == -1)
        {
            hashTable[newIndex] = key;
            return;
        }
    }

    printf("Hash table full\n");
}

int search(int key)
{
    int index = key % SIZE;

    if(hashTable[index] == key)
        return index;

    for(int i = 1; i < SIZE; i++)
    {
        int newIndex = (index + i*i) % SIZE;

        if(hashTable[newIndex] == key)
            return newIndex;

        if(hashTable[newIndex] == -1)
            break;
    }

    return -1;
}

int main()
{
    init();

    insert(10);
    insert(20);
    insert(5);
    insert(15);

    int keys[] = {10, 15, 7};

    for(int i = 0; i < 3; i++)
    {
        int pos = search(keys[i]);

        if(pos != -1)
            printf("%d found at index %d\n", keys[i], pos);
        else
            printf("%d not found\n", keys[i]);
    }

    return 0;
}