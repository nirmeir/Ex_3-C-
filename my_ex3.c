#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define word 30
#define TXT 1024
int Geo(char *, int);


void funA(char *txt, int geo, int counter)
{
    int index = 0;
    int sum = 0;
    char e[geo];
    char c;
    char finaltext[strlen(txt)];
    int l = 0;
  
   
   

    for (int i = 0; i < counter; i++)
    {

        c = txt[i];

        if (c == ' ' || c == ',' || c == '\n')
        {
            e[index] = c;
            index++;
            continue;
        }

        if (c >= 48 && c <= 57)
        {

            continue;
        }

        if (isupper(c))
        {
            sum += (c - 'A' + 1);
            e[index] = c;
            index++;
        }

        else if (islower(c))
        {
            sum += (c - 'a' + 1);
            e[index] = c;
            index++;
        }

        else if (c > 33 && c <= 47)
        {
            e[index] = c;
            index++;
        }

        if (sum == geo && (e[0] == ' ' || e[0] == ',' || e[0] == '\n' || e[0] == '.'))
        {
            memset(e, 0, geo);
            sum = 0;
            i = i - index + 1;
            index = 0;
        }

        else if (sum == geo)
        {
            int j = strlen(e);
            

            for (int h = 0; h < j; h++)
            {

                finaltext[l] = e[h];
                l++;

                if (h == j - 1)
                {
                    finaltext[l] = '~';
                    l++;
                }
            }

            memset(e, 0, geo);

            sum = 0;
            i = i - index + 1;
            index = 0;
        }

        else if (sum > geo)
        {
            memset(e, 0, geo);
            sum = 0;
            i = i - index + 1;
            index = 0;
        }

        if (c == '~')
        {

            break;
        }
    }

    printf("Gematria Sequences: ") ;
    for (int i = 0; i < l - 1; i++)
    {
        char a = finaltext[i];

        if (a == '\n')
        {
            printf("\n");
        }

        else
            printf("%c", a);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void funB(char *txt, char *w, int counterS, int counterW)

{
    int index = 0;
    char c;
    char temptext[word];
    char finaltext[word];
    char Rev[counterW];
    int l = 0;
    int wordcount = 0;
   
    int t = 0;
    

    for (int i = 0; i < counterW; i++)
    {
        Rev[i] = w[counterW - i - 1];
    }

    for (int i = 0; i < counterS; i++)
    {
        c = txt[i];

        if (c == w[index])
        {

            temptext[index] = c;

            index++;
            wordcount++;
            t++;

            while (t < counterS)
            {
                t++;
                i++;
                c = txt[i];

                if (c == w[index])
                {
                    temptext[index] = c;
                    index++;
                    wordcount++;
                }

                else if (c == ' ' || c == ',')
                {
                    temptext[index] = c;
                    index++;
                }

                else if (c != w[index] && (c != ' ' || c != ','))
                {
                    memset(temptext, 0, word);
                    index = 0;
                    wordcount = 0;
                    t = 0;
                    break;
                }

                else if (c >= 48 && c <= 57)
                {

                    continue;
                }

                if (wordcount == counterW && (temptext[0] == ' ' || temptext[0] == ',' || temptext[0] == '.' || temptext[0] == '-'))
                {
                    memset(temptext, 0, word);
                    index = 0;
                    wordcount = 0;
                    t = 0;
                    break;
                }

                else if (wordcount == counterW)
                {
                    int j = index;

                    for (int h = 0; h < j; h++)
                    {

                        finaltext[l] = temptext[h];
                        l++;

                        if (h == j - 1)
                        {
                            finaltext[l] = '~';
                            l++;
                        }
                    }

                    memset(temptext, 0, word);
                    wordcount = 0;
                    index = 0;
                    t = 0;
                    break;
                }
            }
        }
        index = 0;
        if (c == Rev[index])
        {
            // printf("%s",Rev);

            temptext[index] = c;

            index++;
            wordcount++;
            t++;

            while (t < counterS)
            {
                t++;
                i++;
                c = txt[i];

                if (c == Rev[index])
                {

                    temptext[index] = c;
                    index++;
                    wordcount++;
                }

                else if (c == ' ' || c == ',')
                {
                    temptext[index] = c;
                    index++;
                }

                else if (c != Rev[index] && (c != ' ' || c != ','))
                {
                    memset(temptext, 0, word);
                    index = 0;
                    wordcount = 0;
                    t = 0;
                    break;
                }

                else if (c >= 48 && c <= 57)
                {

                    continue;
                }

                if (wordcount == counterW && (temptext[0] == ' ' || temptext[0] == ',' || temptext[0] == '.' || temptext[0] == '-'))
                {
                    memset(temptext, 0, word);
                    index = 0;
                    wordcount = 0;
                    t = 0;
                    break;
                }

                else if (wordcount == counterW)
                {
                    int j = index;

                    for (int h = 0; h < j; h++)
                    {

                        finaltext[l] = temptext[h];
                        l++;

                        if (h == j - 1)
                        {
                            finaltext[l] = '~';
                            l++;
                        }
                    }

                    memset(temptext, 0, word);
                    wordcount = 0;
                    index = 0;
                    t = 0;
                    break;
                }
            }
        }
    }

    printf("Atbash Sequences: ");
    for (int i = 0; i < l - 1; i++)
    {
        char a = finaltext[i];

        if (a == '\n')
        {
            printf("\n");
        }

        else
            printf("%c", a);
    }
}


void funC(char *txt, char *w, int counterS, int counterW, int geo)
{

    int index = 0;
    char c;
    char c2;
    char temptext[word];
    char finaltext[TXT];
    int l = 0;
    int wordcount = 0;
    int t = 0;
    int counter = 0;
    int sum = 0;
    
   

    
    for (int i = 0; i < counterS; i++)
    {
        c2 = txt[i];
        for (int j = 0; j < counterW; j++)
        {
           
            c = w[j];
            

             if (c == ' ')
            {
                t++;
                continue;
            }

             if (c2 == ' ' && index!=0)
            {
                temptext[index] = c2;
                index++;
                break;
            }


        

            else if (c == c2 )
            {
                temptext[index] = c2;
                index++;
                wordcount++;
                counter=0;
                sum=Geo(temptext,index);
               


            if (wordcount == counterW-t && sum != geo ) {

                memset(temptext, 0, word);
                wordcount = 0;
                index = 0;
                t = 0;
                counter=0;
                sum=0;
                i=i-counterW+1;
            }


                
            else if (wordcount == counterW-t && sum == geo )
            {
        
                int j = index;

                for (int h = 0; h < j; h++)
                {

                    finaltext[l] = temptext[h];
                    l++;

                    if (h == j - 1)
                    {
                        finaltext[l] = '~';
                        l++;
                      
                    }
                }

                memset(temptext, 0, word);
                wordcount = 0;
                index = 0;
                t = 0;
                counter=0;
                sum=0;
               
            }
            else break;

            
                }


            else if (c2 != c)
            {
               counter++;
               
            }


             if( counter == counterW && c2 != c) {

                 
                memset(temptext, 0, word);
                wordcount = 0;
                index = 0;
                t = 0;
                counter=0;
                sum=0;
                break;
            }
            

        }
    }


     printf("Anagram Sequences: ");
    for (int i = 0; i < l-1 ; i++)
    {
        char q = finaltext[i];

        if (q == '\n')
        {
            printf("\n");
        }

        else
           
            printf("%c",q);
    }

}

