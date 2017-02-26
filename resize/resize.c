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

  fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, larptr);

  fwrite(&bf, sizeof(BITMAPINFOHEADER), 1, larptr);

  int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

  for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
  {
      for (int j = 0; j < bi.biWidth; j++)
      {
          RGBTRIPLE triple;

          fread(&triple, sizeof(RGBTRIPLE), 1, smptr);

          for (int k = 0, m = atoi(multiplier); k < m; k++)
            fwrite(&triple, sizeof(RGBTRIPLE), 1, larptr);
      }

      fseek(smptr, padding, SEEK_CUR);

      for (int k = 0; k < padding; k++)
          fputc(0x00, larptr);
  }




  return 0;
}
