#ifndef LEX_H
#define LEX_H

#include "chtbl.h"

typedef enum Token_ {
  lexit,
  error,
  digit,
  other
} Token;

Token lex(const char *istream, struct CHTbl *symtbl);

#endif /* ifndef LEX_H */
