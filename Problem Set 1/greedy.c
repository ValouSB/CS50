#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float f = -1;
    while (f < 0 )
    {
        printf("How much change is owed?\n");
        f = GetFloat();
    }
    f = f*100;
    int fa = round(f);
    int i = 0;
    while (fa >= 25) 
    {
        fa = fa-25;
        i = i +1;
    }
    while (fa >= 10) 
    {
        fa = fa-10;
        i = i +1;
    }
    while (fa >= 5) 
    {
        fa = fa-5;
        i = i +1;
    }
    while (fa < 5 && fa > 0) 
    {
        fa = fa-1;
        i = i +1;
    }
    printf("%i\n", i);
}