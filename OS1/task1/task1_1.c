#include <stdio.h>
#include <math.h>

float entering_x(void)
{
  float temp_x = 0.0;
  printf("\n\tEnter x: ");
  scanf("%f", &temp_x);
  return temp_x;
}

float counting_fx(float x)
{
  return (exp(-fabs(x))*sin(x));
}

float counting_gx(float x)
{
  return (exp(-fabs(x))*cos(x));
}

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
