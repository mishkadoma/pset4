#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    fprintf(stderr, "Usage: ./recover disk\n");
    return 1;
  }

  char *infile = argv[1];

  FILE *input = fopen(infile, "r");
  if(input == NULL)
  {
    fprintf(stderr, "couldn't open %s.\n", infile);
    printf("input file opening\n");
    return 2;
  }
  // creating file with single jpeg
  // FILE *output = fopen(real.jpg, "w");
  // if (output == NULL)
  // {
  //   fprintf(stderr, "couldn't write to a file%s\n", outfile);
  //   return 3;
  // }

  char *x = malloc(512);
  if (x == NULL)
  {
    return 3;
  }

  int k = 0;
  while (1==1)
  {
    k++;

    printf("while cycle starts\n");
    // copying 512 bytes from infile to allocated memory
    fread(x, 512, 1, input);

    if (x[0] == 0xff &&
        x[1] == 0xdf &&
        x[2] == 0xff)
    {
      do {
        FILE *output = fopen("file.jpg", "w");
        if (input == NULL)
        {
          fprintf(stderr, "couldn't create *.jpg file.\n");
          return 4;
        }

        for (int i = 0; i <= 100; i++)
        {
          fwrite(x, 512, 1, output);
        }
      }
    }
  }
  free(x);

  return 0;
}
