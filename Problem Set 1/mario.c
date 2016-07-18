#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    do 
    {
        printf("How many block heights do you want the pyramid to have ? It should be less than 23.\n");
        i = GetInt();
    }    
    while (i > 23 || i < 0);
    for (int m = 1; m <= i ; m++)
    {   
        
        for (int n = m; n < i; n++)
        {
            printf(" ");
        }
        
        for (int n = 0; n <= m; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}