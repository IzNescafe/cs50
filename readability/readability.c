#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text : ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (float)letters/(float)words*100;
    float S = (float)sentences/(float)words*100;
    int index = round(0.0588*L - 0.296*S - 15.8);

    if(index<1)
    {
        printf("Before Grade 1\n");
    }
    else if(index>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",index);
    }
}

int count_letters(string text)
{
    int i=0;
    int lcount=0;
    while(text[i]!='\0')
    {
        if(isalpha(text[i]))
        {
            lcount++;
        }
        i++;
    }
    return lcount;
}

int count_words(string text)
{
    int wcount=0;
    int i=0;
    while(text[i]!='\0')
    {
        if(text[i]==' ')
        {
            wcount++;
        }
        i++;
    }
    wcount += 1;
    return wcount;
}

int count_sentences(string text)
{
    int i=0;
    int scount=0;
    while(text[i]!='\0')
    {
        if(text[i]=='.' || text[i]=='!' || text[i]=='?')
        {
            scount++;
        }
        i++;
    }
    return scount;
}
