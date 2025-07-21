#define NULL (void *)0

int main(void)
{
  /* A runtime error is likely to occur because no storage
   * has been allocated for tptr. When we dereference tptr,
   * we cannot be sure where it points*/
  char *sptr = "abc", *tptr;
  *tptr = *sptr;

  /* A compile-time error occurs because when we dereference tptr,
   * we get a character, whereas sptr is a pointer to a character.
   * Thus, the code is trying to assign a character pointer to a
   * character, which is a type conflict*/
  char *another_sptr = "abc", *another_tptr;
  *another_tptr = sptr;

  /* A runtime error is likely to occur because assigning
   * an integer pointer a fixed address is dangerous.
   * When dereferencing iptr, we try to write 11 at address 10,
   * which is probably invalid */
  int *iptr = (int *)10;
  *iptr = 11;

  /* A compile-time error or warning occurs because the code is
   * trying to initialize an integer pointer to an integer,
   * which is a type conflict*/
  int *another_iptr = 10;
  *another_iptr = 11;

  /* No error occurs because both tptr and sptr are character
   * pointers */
  char *other_sptr = "abc", *other_tptr;
  other_tptr = other_sptr;

  /* No error occurs because although the code first performs
   * the dangerous step of initializing iptr to a fixed address,
   * it is then immediately reset to NULL, which is valid */
  int *other_iptr = (int *)10;
  other_iptr = NULL;
}
