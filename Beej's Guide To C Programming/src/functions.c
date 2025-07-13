#include <stdio.h>

// You need to declare the functions first
// before the main function. These called as function prototypes.
// if you don't declare your function before you use it, you're
// performing something called an implicit declaration.
int plusOne (int n);
//            ^ this one called parameter. Its a special type
//            of local variable into which the arguments are copied.
// The parameter is a copy of the argument, not the argument itself.

void increment (int a);

int
main (void)
{
  int i = 10, j;

  // so the returns value from plusOne will be use on here.
  j = plusOne (i); // The "call"
  printf ("i + 1 is %d\n", j);
}

// and here's the code
int
plusOne (int n)
{
  return n + 1;
}

// The argument is just a copy from the expression I pass to functions
// And this prints `10` not `11`. When the function completes,
// the local variables in this example is discarded and we return to main()
// where `i` is still 10
void
increment (int a)
{
  a++;
}

// Empty Parameter Lists
// NOTE: REMEMBER TO PUT `void` if the function intended to not having
// parameters
void
fooRightWay (void)
{
  printf ("This is right.");
}

void
fooWrongWay (void)
{
  printf ("This isn't right.");
}

// Leaving void out of the prototype indicates to the compiler that
// there is no additional information about the parameters to the function.
// It effectively turns off all that type checking
// With a prototype definitely use void when you have an empty parameter list.
