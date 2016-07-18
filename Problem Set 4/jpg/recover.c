#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define BLOCKSIZE 512
typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
	BYTE hexa[BLOCKSIZE];
	int count = 0;
	int FileEnd = 0;
	FILE* file = NULL;
	FILE* mainfile = fopen("card.raw", "r");
    if (mainfile == NULL) return 1;
    
    while (FileEnd == 0)
    {
        for (int i = 0; i < BLOCKSIZE; i++)
        {
            if (feof(mainfile)) return 0;
            fread(&hexa[i], sizeof(BYTE), 1, mainfile);
        }
        
        if ((hexa[0] == 0xff) && (hexa[1] == 0xd8) && (hexa[2] == 0xff) && (hexa[3] == 0xe0 || hexa[3] == 0xe1))
        {
            char filetitle[4];
            if (file != NULL) fclose(file);
            sprintf(filetitle, "%03i.jpg", count);
            file = fopen(filetitle, "w");
            fwrite(&hexa[0], BLOCKSIZE * sizeof(BYTE), 1, file);
            count++;
        }
        else if (file != NULL) fwrite(&hexa[0], BLOCKSIZE * sizeof(BYTE), 1, file);
    }
}