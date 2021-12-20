
#include <stdlib.h>
#include "my_ex3.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define word 30
#define TXT 1024
int Geo(char *, int);
char* atbash (char* , int);
char * help(char*);


int main()
{
    char w[word];
    char sen[TXT];
    int counterW = 0;
    int counterS = 0;

    char c = 0;
    for (int i = 0; i < word; i++)
    {
        scanf("%c", &c);
        if (c == ' '|| c == '\t'|| c == '\n')
        {
            break;
        }
               
            
        else
        {
            w[i] = c;
        }
        counterW++;
    }

    char t = 0;
    for (int i = 0; i < TXT - 1; i++)
    {
        scanf("%c", &t);

        if (t == '~')
        {
            break;
        }

        else
        {
            sen[i] = t;
        }
        counterS++;
    }

    char* e =atbash(w,counterS);    
    int geoSize = 0;
    geoSize = Geo(w, counterW);
    funA(sen,geoSize,counterS);
    printf("\n");
    funB(sen, e, counterS,counterW);
     printf("\n");

    funC(sen,w,counterS,counterW,geoSize);

   return 0;
}


int Geo(char *e, int s)
{
    int sum = 0;

    for (int i = 0; i < s; i++)
    {
        if (isupper(e[i]))
        {
            sum += (e[i] - 'A' + 1);
        }
        else if (islower(e[i]))
        {
            sum += (e[i] - 'a' + 1);
        }

        continue;
    }

    return sum;
}

char* atbash(char *e, int s )
{
    char c = 0;
    char* w=malloc(s) ;

    for (int i = 0; i < s; i++)
    {
        c = e[i];

        if (isupper(c))
        {
            w[i] = ('Z' - c + 'A');
        }

        else if (islower(c))
        {
            w[i] = ('z' - c + 'a');
        }
    }
    return w;
}

char* help (char* w) {

    char* w2 = malloc(strlen(w));
    if (w2 == NULL){
        return NULL;
    }
    strcpy(w2,w);

    char temp =0;

    for(int i =0; i<strlen(w2)-1; i++) {
        for(int j = i+1; j< strlen(w2); j++){
            if(w2[i]>w2[j]){
                temp=w2[i];
                w2[i]=w2[j];
                w2[j]=temp;
            }
        }
    }
    
    return w2;
}
