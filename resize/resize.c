#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[]) {
  if (argc != 4)
  {
    printf("Usage: ./resize n small.bmp large.bmp\n");
    return 1;
  }


  char *multiplier = argv[1];
  char *small = argv[2];
  char *large = argv[3];


//open both files;
  FILE *smptr = fopen(small, "r");
  if (smptr == NULL)
  {
    fprintf(stderr, "Couldn't open %d\n", *small);
    return 2;
  }

  FILE *larptr = fopen(large, "w");
  if (larptr == NULL)
  {
    fprintf(stderr, "Couldn't open %d\n", *large);
    return 3;
  }

  BITMAPFILEHEADER bf;
  fread(&bf, sizeof(BITMAPFILEHEADER), 1, smptr);

  BITMAPINFOHEADER bi;
  fread(&bi, sizeof(BITMAPINFOHEADER), 1, smptr);

  if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
      bi.biBitCount != 24 || bi.biCompression != 0)
  {
      fclose(larptr);
      fclose(smptr);
      fprintf(stderr, "Unsupported file format.\n");
      return 4;
  }

  int small_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
  int small_height = abs(bi.biHeight);
  int small_width = bi.biWidth;

  //**
  bi.biHeight *= atoi(multiplier);
  bi.biWidth *= atoi(multiplier);
  int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
  bi.biSizeImage *= ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
  bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


  //**


  fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, larptr);
  fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, larptr);



  for (int i = 0, biHeight = abs(small_height); i < biHeight; i++)
  {
    for (int f = 0, repeat_time = atoi(multiplier); f < repeat_time; f++)
    {
      for (int j = 0; j < small_width; j++)
      {
        for (int k = 0; k < atoi(multiplier); k++)
        {
          RGBTRIPLE triple;
          fread(&triple, sizeof(RGBTRIPLE), 1, smptr);
          printf("pixel number: %d row number: %d\n", k, i);
          fwrite(&triple, sizeof(RGBTRIPLE), 1, larptr);
          fseek(smptr, -(sizeof(RGBTRIPLE)), SEEK_CUR);
        }

        fseek(smptr, sizeof(RGBTRIPLE), SEEK_CUR);
      }

      fseek(smptr, small_padding, SEEK_CUR);

      for (int q = 0; q < padding; q++)
          fputc(0x00, larptr);

      fseek(smptr, -(small_padding + sizeof(RGBTRIPLE) * small_width), SEEK_CUR);
    }
    fseek(smptr, (small_padding + sizeof(RGBTRIPLE) * small_width), SEEK_CUR);
  }

  printf("smal pdng: %d\n", small_padding);
  printf("large pdng: %d\n", padding);

  return 0;
}
