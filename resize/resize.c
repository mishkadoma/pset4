#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3)
  {
    printf("Usage: ./resize small.bmp large.bmp\n");
    return 1;
  }

  char *small = argv[1];
  char *large = argv[2];


//open both files;
  FILE *inptr = fopen(small, "r");
  if (inptr == NULL)
  {
    fprintf(stderr, "Couldn't open %d\n", *small);
    return 2;
  }

  FILE *outptr = fopen(large, "w");
  if (outptr == NULL)
  {
    fprintf(stderr, "Couldn't open %d\n", *large);
    return 3;
  }



  return 0;
}
