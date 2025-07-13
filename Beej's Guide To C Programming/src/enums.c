#include <stdio.h>

int
main (void)
{
  // It's really common for enums to be defined in header files so they can be
  // #included at file scope.
  enum
  {
    SHEEP, // Value is 0
    WHEAT, // Value is 1
    WOOD,  // Value is 2
    BRICK, // Value is 3
    ORE    // Value is 4
  };

  // You could also use typedef for aliasing
  typedef enum
  {
    NIGGER1,
    NIGGER2,
    NIGGER3
  } NIGGERS;

  printf ("%d %d\n", SHEEP, BRICK);
}
