#include <stdio.h>

int main (void)
{
  int lower, upper, step;
  float fahr, celsius;
  lower = 0;   /* Lower limit of temperature table */
  upper = 300; /* upper limit */
  step = 20;   /* step size */
  fahr = lower;

  fprintf(stdout, "Celsius to Fahrenheit\n" \
                  "-----------------------\n");

  while(fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%6.1f | %4.0f\n", celsius, fahr);
    fahr = fahr + step;
  }
}
