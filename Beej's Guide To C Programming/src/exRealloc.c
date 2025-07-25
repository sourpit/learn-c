#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
char *readline (FILE *fp);
void *aligned_realloc (void *ptr, size_t old_size, size_t alignment,
                       size_t size);

int
main (void)
{
  FILE *fp = fopen ("foo.txt", "r");
  char *line;

  while ((line = readline (fp)) != NULL)
    {
      printf ("%s\n", line);
      free (line);
    }

  fclose (fp);
}

// Read a line of arbitrary size from a file
//
// Returns a pointer to the line.
// Returns a NULL on EOF or error.
//
// It's up to the caller to free() this pointer when done with it.
//
// Note that this strips the newline from the result. If you need
// it in there, probably best to switch this to a do-while

char *
readline (FILE *fp)
{
  int offset = 0;  // Index next char goes in the buffer
  int bufsize = 4; // Preferably power of 2 initial size
  char *buf;       // The buffer
  int c;           // The character we've read in

  buf = malloc (bufsize); // Allocate initial buffer

  if (buf == NULL) // Error check
    return NULL;

  // Main loop--read until newline or EOF
  while (c = fgetc (fp), c != '\n' && c != EOF)
    {
      // Check if we're out of room in the buffer accounting
      // for the extra byte for the NUL terminator
      if (offset == bufsize - 1) // -1 for the NULL terminator
        {
          bufsize *= 2; // 2x the space

          char *new_buf = realloc (buf, bufsize);

          if (new_buf == NULL)
            {
              free (buf); // On error, free and bail
              return NULL;
            }

          buf = new_buf; // Successful realloc
        }
      buf[offset++] = c; // Add the byte onto the buffer
    }

  // We hit newline or EOF
  //
  // If at EOF and we read not bytes, free the buffer and
  // return NULL to indicate we're at EOF
  if (c == EOF && offset == 0)
    {
      free (buf);
      return NULL;
    }

  // Shrink to fit
  if (offset < bufsize - 1) // If we're short of the end
    {
      char *new_buf = realloc (buf, offset + 1); // +1 for NUL terminator

      // If successful, point buf to new_buf;
      // otherwise we'll just leave buf where it is
      if (new_buf != NULL)
        buf = new_buf;
    }

  // Add the NUL terminator
  buf[offset] = '\0';

  return buf;
}

// NOTE: it always copies data, taking time, while real realloc() will avoid
// that if it can. So this is hardly efficient. Avoid needing to reallocate
// custom-aligned data.
void *
aligned_realloc (void *ptr, size_t old_size, size_t alignment, size_t size)
{
  char *new_ptr = aligned_alloc (alignment, size);

  if (new_ptr == NULL)
    return NULL;

  size_t copy_size = old_size < size ? old_size : size; // get min

  if (ptr != NULL)
    memcpy (new_ptr, ptr, copy_size);

  free (ptr);

  return new_ptr;
}
