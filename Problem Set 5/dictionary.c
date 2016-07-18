#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#define N 32767

typedef struct node 
{
	char wordval[LENGTH+1];
	struct node* next;
}
node;
node* hashtable[N] = {NULL}; 
int dsize = 0;
bool check(const char* wordval)
{
    char *calquer = malloc(strlen(wordval));
    for (int i = 0; i < strlen(wordval); i++) calquer[i] = tolower(wordval[i]);
    calquer[strlen(wordval)] = '\0';
    unsigned int hash = 0;
    for (int i = 0; i < strlen(calquer); i++) hash = calquer[i] ^ (hash << 2);
    node* entry = hashtable[hash % N];
    if (entry)
    {
        node* pointer = entry;
        int alphatemp = 0;
		while (alphatemp == 0)
		{
		   if (pointer->next == NULL) alphatemp = 1;
		   if (strcmp(calquer, pointer->wordval) == 0) return true;
		   pointer = pointer->next;
		}
    }
    return false;
}
bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary, "r");
    char buffer[LENGTH+2]; 
    int BetaHash ;
    unsigned int hash = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {
        dsize++;
        hash = 0;
        buffer[strlen(buffer) - 1] = '\0';
        for (int i = 0; i < strlen(buffer); i++) hash = buffer[i] ^ (hash << 2);
        BetaHash = hash % N;
        node* pointer = hashtable[BetaHash];
    	node* tango = malloc(sizeof(node));
    	strncpy(tango->wordval, buffer, LENGTH + 1);
    	tango->next = NULL;
    	if (hashtable[BetaHash] != NULL)
    	{
    		while (pointer->next != NULL) pointer = pointer->next;
    		pointer->next = tango;
    	}
    	else hashtable[BetaHash] = tango;
    }
    fclose(file);
    return true;
}
unsigned int size(void) {return dsize;}
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node* pointer = hashtable[i];
        if (pointer)
        {
            node* tango = pointer->next;
            free(pointer);
            pointer = tango;
        }
    }
    return true;
}