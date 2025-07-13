#include <stdio.h>

int
main (void)
{
  int i = 0, y = 0, x = 0;

  // Arithmetic Operator
  // These expression:
  i = i + 3;
  i = i - 8;
  i = i * 9;
  i = i / 2;
  i = i % 5;

  // Equals to these:
  i += 3;
  i -= 8;
  i *= 9;
  i /= 2;
  i %= 5;

  // Ternary Operator
  // This expression:
  y += x > 10 ? 17 : 37;

  // is equivalent to this non-expression:
  if (x > 10)
    y += 17;
  else
    y += 37;

  printf ("%d\t %d\n", i, y);

  // I can do cool things like this.
  printf ("The number %d is %s.\n", x, x % 2 == 0 ? "even" : "odd");

  // Comma operator
  for (int i = 0, j = 10; i < 100; i++, j++)
    printf ("%d, %d\n", i, j);

  // Conditional Operators
  int a = 0, b = 10;
  a == b; // True if a is equivalent to b
  a != b; // True if a is not equivalent to b
  a < b;  // True if a is less than b
  a > b;  // True if a is greater than b
  a <= b; // True if a is less than or equal to b
  a >= b; // True if a is greater than or equal to b

  if (a <= 10)
    printf ("Success!\n");

  // Boolean Operators
  if (x < 10 && y > 20)
    printf ("Doing something!\n");

  // This expression with boolean NOT
  if (!(x < 12))
    printf ("x is not less than 12\n");

  // is same as this expression
  if (x >= 12)
    printf ("x is not less than 12\n");

  // The sizeof Operator
  // This operator tells you the size (in bytes) that a
  // particular variable or data type uses in memory
  int u = 999;

  // %zu is the format specifier for type size_t
  // If your compiler balks at the "z" part, leave it off
  printf ("%zu\n", sizeof a);       // Prints 4 on my system
  printf ("%zu\n", sizeof (2 + 7)); // Prints 4 on my system
  printf ("%zu\n", sizeof 3.14);    // Prints 8 on my system

  // if you need to print out negative size_t values, use %zd

  // loop operators
  // there is while, do-while, and for.
  // here's how to make loopin forever
  // while(1) and for(;;)

  // when using switch and you forgot to put a break, it will go to next
  // expression. Not having a break is called fall through
}
