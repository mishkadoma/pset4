#include <stdio.h>
#include <stdlib.c>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./recover image")
    return 1;
  }

  char *infile = argv[1];

  FILE *input = fopen(infile, "r");
  if (input == NULL)
  {
    fprintf(stderr, "couldn't open %s.\n", infile);
    return 2;
  }


  fread()
}
