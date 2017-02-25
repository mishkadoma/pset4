#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[]) {
  if (argc != 3)
  {
    printf("Usage: ./resize small.bmp large.bmp\n");
    return 1;
  }

  char *small = argv[1];
  char *large = argv[2];


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

  fwrite(&bf, BITMAPFILEHEADER, 1, larptr);

  fwrite(&bf, BITMAPINFOHEADER, 1, larptr);

  


  return 0;
}
