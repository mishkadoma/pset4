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
  fread(&bf, size(BITMAPFILEHEADER), 1, smptr);

  BITMAPINFOHEADER bf;

  return 0;
}
