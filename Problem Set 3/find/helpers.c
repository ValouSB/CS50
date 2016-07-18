#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

bool search(int value, int values[], int n)
{
    int min = 0;
    int max = (n - 1);
    while(max >= min)
    {
        int half = ((max-min)/2) + min;
        if (value == values[half]) return true;
        else if (values[half] > value) max = half-1;
        else min = half+1;   
    }
    return false;   
}

void sort(int values[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i-1;
        int k = values[i];
        while((k < values[j]) && (j >= 0))
        {
            values[j+1] = values[j];
            j = j-1;
        }
    values[j+1] = k; 
    }
    return; 
}