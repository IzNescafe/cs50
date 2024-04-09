#include<stdio.h>
#include<cs50.h>
#include<string.h>

bool check_phrase(string);

int main(void)
{
    string phrase = get_string("What's the secret phrase?\n");
    bool correct = check_phrase(phrase);
    if(correct==true)
    {
        printf("Come on in\n");
    }
}

bool check_phrase(string phrase)
{
    string password = "Please";
    if(strcmp(phrase,password) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
