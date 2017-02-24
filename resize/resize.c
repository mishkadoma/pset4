#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3)
  {
    printf("Usage: ./resize small.bmp large.bmp");
    return 1;
  }

  char *small = argv[1];
  char *large = argv[2];


//open both files;
  FILE *inprt = fopen(small, "r");
  if (inptr == NULL)
  {
    fprintf(stderr, "Couldn't open %s\n", *small);
    return 2;
  }

  FILE *outptr = fopen(large, "w");
  if (outptr == NULL)
  {
    fprintf(stderr, "Couldn't open %s\n", *large);
    return 3;
  }



  return 0;
}
