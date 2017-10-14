#include <stdio.h>
#include <stdlib.h>

#define BASEX 1800
#define BASEY 1800

#define TBASEX 2025
#define TBASEY 2130

#define SIZE 450

int main(int argc, char **argv)
{
  int pattern;
  if (argc!=2) {
    fprintf(stderr, "usage: %s <pattern>\n", argv[0]);
    return 1;
  }
  pattern = atoi(argv[1]);
  printf("#FIG 3.2  Produced by output_lines\n");
  printf("Landscape\n");
  printf("Center\n");
  printf("Metric\n");
  printf("A4      \n");
  printf("100.00\n");
  printf("Single\n");
  printf("-2\n");
  printf("1200 2\n");
  printf("0 32 #c5c5c5\n");
  printf("0 33 #808080\n");
  int i, j;
  for (i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      char weight;
      int col;
      int id;
      int dx, dy;
      id = i;
      switch(pattern) {
        case 0:
          dx = 2;
          dy = -2;
          break;
        case 1:
          dx = 2;
          dy = -1;
          break;
        case 2:
          dx = 2;
          dy = 0;
          break;
        case 3:
          dx = 2;
          dy = 1;
          break;
        case 4:
          dx = 2;
          dy = 2;
          break;
        case 5:
          dx = 1;
          dy = 2;
          break;
        case 6:
          dx = 0;
          dy = 2;
          break;
        case 7:
          dx = -1;
          dy = 2;
          break;
      }
      col = (i==2 && j==2) ? 33 : 7;
      printf("2 2 0 1 0 %d 50 -1 20 0.000 0 0 -1 0 0 5\n", col);
      printf("         %d %d %d %d %d %d %d %d %d %d\n", BASEX+SIZE*(j+0), BASEY+SIZE*(i+0),
        BASEX+SIZE*(j+1), BASEY+SIZE*(i+0),
        BASEX+SIZE*(j+1), BASEY+SIZE*(i+1),
        BASEX+SIZE*(j+0), BASEY+SIZE*(i+1),
        BASEX+SIZE*(j+0), BASEY+SIZE*(i+0)
      );
      printf("2 2 0 1 0 7 50 -1 -1 0.000 0 0 -1 0 0 5\n");
      printf("         %d %d %d %d %d %d %d %d %d %d\n", BASEX+SIZE*(j+0), BASEY+SIZE*(i+0),
        BASEX+SIZE*(j+1), BASEY+SIZE*(i+0),
        BASEX+SIZE*(j+1), BASEY+SIZE*(i+1),
        BASEX+SIZE*(j+0), BASEY+SIZE*(i+1),
        BASEX+SIZE*(j+0), BASEY+SIZE*(i+0)
      );
      if (i==(2 + dy) && j == (2 + dx)) weight = 'a';
      else if (i==(2 - dy) && j == (2 - dx)) weight = 'a';
      else if (i==(2 + dy/2) && j == (2 + dx/2)) weight = 'b';
      else if (i==(2 - dy/2) && j == (2 - dx/2)) weight = 'b';
      else weight = 0;
      if (weight)
        printf("4 1 0 50 -1 1 18 0.0000 4 135 105 %d %d %c\\001\n", TBASEX+SIZE*j, TBASEY+SIZE*i, weight);
    }
  }
  printf("4 1 0 50 -1 1 24 0.0000 4 135 105 %d %d d\\001\n", (int)(TBASEX+SIZE*2.4)-480, (int)(TBASEY+SIZE*5.2));
  printf("4 1 0 50 -1 0 24 0.0000 4 135 105 %d %d = %d\\001\n", (int)(TBASEX+SIZE*2.4), (int)(TBASEY+SIZE*5.2), pattern);
  return 0;
}
