#include <stdio.h>

typedef struct {
  int ind_min;
  int ind_max;
} Ind_Pair;

void troca(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort_3(int a[]) {
  if (a[0] > a[1]) troca (&a[0], &a[1]);
  if (a[0] > a[2]) troca (&a[0], &a[2]);
  if (a[1] > a[2]) troca (&a[1], &a[2]);
}

void sort_2(int a[]) {
  if (a[0] > a[1]) troca (&a[0], &a[1]);
}

int main(int argc, char *noargs[]) {
  int a[3], h[2];
  char res;
  scanf ("%d %d %d %d %d", &a[0], &a[1], &a[2], &h[0], &h[1]);
  sort_3(a);
  sort_2(h);
  if ((a[0] <= h[0]) && (a[1] <= h[1])) res = 'S';
  else res = 'N';
  printf("%c\n", res);
  return 0;
}
