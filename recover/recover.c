#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usare: ./recover infile")
    return 1;
  }

  char *infile = argv[1];

  FILE *input = fopen(infile, "r");
  if (input == NULL)
  {
    fprintf(stderr, "couldn't open %s.\n", infile)
  }
}
