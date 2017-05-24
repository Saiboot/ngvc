#include <iostream>

#ifndef __ERROR_CODES_H
#define __ERROR_CODES_H


/* Lexisis */
	
#define SYMBOL_ILLEGAL 

typedef struct Symbol
{
	char *sym;
	__int32 addr;

} Symbol;

void sym_errmsg(const char *sym) {
	char *err = "Illegal Symbol: ";
	strcat(err, sym);
	std::perror(err);
}

/* Linker */



/* Preproc */



#endif // !__ERROR_CODES_H
