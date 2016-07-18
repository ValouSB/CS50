#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How many minutes do stay in the shower ?\n");
    int i = GetInt();
    printf("minutes: %i\n", i);
    i = 12*i;
    printf("bottles: %i\n", i);
    
}