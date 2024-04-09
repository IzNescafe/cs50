#include <cs50.h>
#include <stdio.h>

int colatz(int n);

int main(void)
{
    int number = get_int("Enter the number: ");
    printf("Number of steps it takes: %i\n",colatz(number));
}

int colatz(int n)
{
    if(n == 1)
        return 0;

    else if((n%2) != 0)
        return 1+ colatz(3*n + 1);

    else
        return 1+ colatz(n/2);
}
