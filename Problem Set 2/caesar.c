#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please, enter an encryption key like : './caesar 5' (where 5 is the encryption key) \n");
        return 1;
    }
    else 
    {
        int j = atoi(argv[1]);
        string s = GetString();
        for(int i = 0; i < strlen(s); i++)
        {
            if(isalpha(s[i]))
            {
                if(islower(s[i])) printf("%c", ((((s[i] +j)-97)%26)+97));
                else printf("%c", ((((s[i] +j)-65)%26)+65));
            }
            else printf("%c", s[i]);
        }
        printf("\n");
        return 0; 
    }
}