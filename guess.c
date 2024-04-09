#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int number,guess;
    number = 5;
    guess = get_int("Guess a number : ");
    if(number != guess)
    {
        printf("Wrong guess!\n");
    }
    else
    {
        printf("The answer is correct!\n");
    }
}
