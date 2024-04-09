#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int sub[100];
    if(argc!=27)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    for(int i=0;i<strlen(argv[1]);i++)
    {
        if(!(isalpha(argv[1][i])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    for(int i=0;i<strlen(argv[1]);i++)
    {
        sub[i] = argv[1][i];
    }

        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        for(int j=0;j<strlen(plaintext);j++)
        {
            if(isupper(plaintext[j]))
            {
                printf("%c",sub[(plaintext[j] - 65)]);
            }
            else if(islower(plaintext[j]))
            {
                printf("%c",sub[(plaintext[j] - 97)]);
            }
            else
            {
                printf("%c",plaintext[j]);
            }
        }
        printf("\n");
}
