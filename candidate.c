#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int vote;
}
candidates;

candidates get_candidate(string prompt);

int main(void)
{
    int n = get_int("Enter the numbers of candidate: ");
    candidates candidate_array[n];
    for(int i=0; i<=n; i++)
    {
        candidate_array[i] = get_candidate("Enter a candidate: ");
    }
}

candidates get_candidate(string prompt)
{
    printf("%s\n",prompt);

    candidates c;
    c.name = get_string("Enter a name: ");
    c.vote = get_int("Enter a number of votes: ");
    return c;
}
