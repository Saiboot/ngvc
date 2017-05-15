#include <fstream>
#include "../common.h"

#ifndef __PREPROC_H
#define __PREPROC_H

/*	Preprocessor - Stage
 *	- Includes
 *	- Macros
 *	- Decomment
 */


//	
//	is number ?
//	@param: text string
//
//	@return: true/false
//	
bool is_number(const char *string) {
	for (int i = 0; i < strlen(string); i++)
		if (!isdigit(string[i]))
			return false;

	return true;
}

//	
//	Preprocess
//	@param: address to file buffer 
//
//	@return: nothing.
//	
void Preprocess(char *aBuf) {

	char *tokens = (char*)malloc(strlen(aBuf) + 1);				// Allocate token storage
	tag *tags = (tag*)malloc(sizeof(tag) * sizeof(uint16_t));	// Allocate tag storage

	for (int i = 0; i < sizeof(uint16_t); i++)		// Loop through all elements
		tags[i] = tag(0x0, 0);						// Store empty tags

	int last = 0;		// End of token storage
	int cnt = 0;		// Amount of tags stored
	int pos = 0;		// Tag address position

	for (size_t i = 0; i < strlen(aBuf); i++)
	{
		char *token = strtok(aBuf, "\t\n");
		while (token)
		{
			/* Compiler ignore comment lines */
			char *chrloc = strchr(token, '#');
			if (chrloc)								///	# Comment
				break;								/// Skip comment line

			/* Check for tag */
			if (token[strlen(token) - 1] == ':') {				///	Tag:
				char *tag_str = (char*)malloc(sizeof(token));	// Allocate space for new tag 
				strncpy(tag_str, token, strlen(token) - 1);		// token >> tag_str (tag name)

				/* Prevent tag redefinition */
				for (size_t i = 0; i < cnt; i++) {				// Loop through every stored tag
					if (!strcmp(tags[i].string, tag_str))		// Error if new tag name equals an old tag's name
						printf("Assembler Error >> redefined tag '%s'\n", tag_str);
				}

				/* Store new tag */
				tags[cnt].string = (char*)malloc(sizeof(tag_str));	//	Allocate memory for tag name
				strcpy(tags[cnt].string, tag_str);					//	tag_str >> tag storage (tag name)
				tags[cnt++].address = pos;							//	tag address ^

				/* Replace token */
				token = "LABEL";

				free(tag_str);	// Free useless memory
			}

			/* Store new token */
			strcpy(tokens + last, token);	// token >> token storage
			last += strlen(token);			// Update end of token storage

			/* Separate tokens with ',' */
			tokens[last++] = ',';

			pos++;	// Next (Address) position

			/* numbers are 2 bytes */
			if (is_number(token))
				pos++;

			/* get next token */
			token = strtok(NULL, ",\n");
		}
	}

	/* NULL */
	tokens[last - 1] = '\0';

	last = 0;

	char *token_final = (char*)malloc(strlen(aBuf) + 1);

	char *token = strtok(tokens, ",");

}

#endif // !__PREPROC_H