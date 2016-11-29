#include <stdio.h>

int main(int argc, char *noargs[]) {
  int x, y, ell[4];
  char res;
  scanf ("%d %d %d %d %d %d", &x, &y, &ell[0], &ell[1], &ell[2], &ell[3]);
  if (((x >= ell[0] + ell[2]) && (y >= ell[1]) && (y >= ell[3])) ||
      ((x >= ell[0] + ell[3]) && (y >= ell[1]) && (y >= ell[2])) ||
      ((x >= ell[1] + ell[2]) && (y >= ell[0]) && (y >= ell[3])) ||
      ((x >= ell[1] + ell[3]) && (y >= ell[0]) && (y >= ell[2])) ||
      ((y >= ell[0] + ell[2]) && (x >= ell[1]) && (x >= ell[3])) ||
      ((y >= ell[0] + ell[3]) && (x >= ell[1]) && (x >= ell[2])) ||
      ((y >= ell[1] + ell[2]) && (x >= ell[0]) && (x >= ell[3])) ||
      ((y >= ell[1] + ell[3]) && (x >= ell[0]) && (x >= ell[2])))
    res = 'S';
  else res = 'N';
  printf("%c\n", res);
  return 0;
}
