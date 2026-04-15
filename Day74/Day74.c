//Problem Statement: Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who 
// received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char names[n][50];

    for(int i = 0; i < n; i++)
        scanf("%s", names[i]);

    int maxVotes = 0;
    char winner[50];

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(strcmp(names[i], names[j]) == 0)
                count++;
        }

        if(count > maxVotes)
        {
            maxVotes = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxVotes)
        {
            if(strcmp(names[i], winner) < 0)
                strcpy(winner, names[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}