#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "Usage: ./recover image\nxxd ");
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

  int *x = malloc(512);


  while(sizeof(x) == 64)
  {
    printf("sizeof malloc x: %lu", sizeof(x));
    // copying 512 bytes from infile into outfile
    fread(&x, 64, 1, input);

    // if()
    // {
    //
    // }

    fwrite(&x, 64, 1, output);
  }

  return 0;
}
