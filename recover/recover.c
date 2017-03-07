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
  char *outfile = argv[2];

  FILE *input = fopen(infile, "r");
  if (input == NULL)
  {
    fprintf(stderr, "couldn't open %s.\n", infile);
    return 2;
  }

  FILE *output = fopen(outfile, "w");
  if (output == NULL)
  {
    fprintf(stderr, "couldn't write to a file%s\n", outfile);
    return 3;
  }

  x = malloc(64);


  {

    fread(&x, 64, 1, input);
    if()
    fwrite(&x, 64. 1, output);
  }


}
