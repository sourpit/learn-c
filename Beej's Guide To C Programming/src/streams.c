#include <stdio.h>

// Function prototypes
void openFiles (void);
void readFiles (void);
void writeBinary (void);
void readBinary (void);

int
main (void)
{
  readBinary ();
}

// Write a files
void
openFiles (void)
{
  FILE *fp;
  int x = 32;

  // Opening files or streams.
  fp = stdout;

  fputc ('B', fp);
  fputc ('\n', fp);
  fprintf (fp, "x = %d\n", x);
  fputs ("Hello, World!\n", fp);

  // Close the files/streams
  fclose (fp);
}

void
readFiles (void)
{
  FILE *fp;
  int c;

  fp = fopen ("hello.txt", "r");

  while ((c = fgetc (fp)) != EOF)
    printf ("%c\n", c);

  fclose (fp);
}

void
writeBinary (void)
{
  FILE *fp;
  unsigned char bytes[6] = { 5, 37, 0, 88, 255, 12 };

  fp = fopen ("output.bin", "wb");

  // In the call to fwrite, the arguments are:
  //
  // * Pointer to data to write
  // * Size of each "piece" of data
  // * Count of each "piece" of data
  // * FILE*
  fwrite (bytes, sizeof (char), 6, fp);

  fclose (fp);
}

void
readBinary (void)
{
  FILE *fp;
  unsigned char c;

  fp = fopen ("output.bin", "rb");

  while (fread (&c, sizeof (char), 1, fp) > 0)
    printf ("%d\n", c);

  fclose (fp);
}
