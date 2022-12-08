#include <stdio.h>
#include "fx.c"
#include "gx.c"
#include "entering.c"

int main()
{
  printf("\n\tf(x) = exp(-|x|)*sin(x)\n\tg(x) = exp(-|x|)*cos(x)");
  float x = entering_x();
  float fx = counting_fx(x);
  float gx = counting_gx(x);
  printf("\tf(x) = %f, x = %f", fx, x);
  printf("\n\tg(x) = %f, x = %f\n\t", gx, x);
  return 0;
}
