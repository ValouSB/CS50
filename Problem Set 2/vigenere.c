#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please, enter an encryption key like : './devigenere bacon' (where 'bacon' is the encryption key) \n");
        return 1;
    }
    else
    {
        char c1 = 0;
        char c2 = 0;
        int j = 0;
        string k = argv[1];
        int klenght = strlen(k);
        for (int i = 0; i < klenght; i++) // check if the key is alphabetical
        {
            if (isalpha(k[i]) == false) 
            {
                printf("error");
                return 1;
            }
        }
        string s = GetString(); // prompt text
        int n = strlen(s);
        for (int i = 0; i < n; i++) // For each element in the string
        {      
            if (isalpha(s[i]) == false) printf("%c", s[i]); // non alphabetical characters
            else
            {
                if (islower(s[i])) c1 = -97;
                if (isupper(s[i])) c1 = -65;
                if (islower(k[j])) c2 = -97;
                if (isupper(k[j])) c2 = -65;
                char r = (((s[i] + c1) + (k[j] + c2)) % 26) - c1;
                printf("%c", r); 
                j = ((j+1) % strlen(k)); // j++
            }
        }
    }
    printf("\n");  
    return 0; 
}