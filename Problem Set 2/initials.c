#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   string s = GetString();
   printf("%c",toupper(s[0]));
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            printf("%c", toupper(s[i+1]));
        }
    }
    printf("\n");
}