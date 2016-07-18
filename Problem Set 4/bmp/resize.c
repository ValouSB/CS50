/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    if (n > 100 || n < 1) 
    {
        printf("n should be in [1;100]\n");
        return 5;
    }
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    BITMAPFILEHEADER out_bf = bf;
    BITMAPINFOHEADER out_bi = bi;
    out_bi.biWidth *= n;
    out_bi.biHeight *= n;
    int in_padding =  ((4 - ((sizeof(RGBTRIPLE) * bi.biWidth)) % 4) % 4);
    int out_padding =  ((4 - ((sizeof(RGBTRIPLE) * out_bi.biWidth)) % 4) % 4);
    out_bi.biSizeImage = (sizeof(RGBTRIPLE) * abs(out_bi.biHeight) * out_bi.biWidth) + (out_bi.biWidth * out_padding);
    out_bf.bfSize = out_bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    int offset = bi.biWidth * sizeof(RGBTRIPLE) + in_padding;
    
    // iterate over infile's scanlines
    for (int i = 0; i < abs(bi.biHeight); i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < bi.biWidth; k++)
            {
                RGBTRIPLE triple;
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for (int l = 0; l < n; l++) fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

            fseek(inptr, in_padding, SEEK_CUR);
            for (int m = 0; m < out_padding; m++) fputc(0x00, outptr);
            fseek(inptr, -offset, SEEK_CUR); 
        }
        fseek(inptr, offset , SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}