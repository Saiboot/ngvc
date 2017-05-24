#include <fstream>
#include "../common.h"
#include "err.h"

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
void asm_Preprocess(char *aBuf) {

	//	
	//	Assembler init:
	//	

	Symbol *iSymbol_table = (Symbol*)malloc(sizeof(char) * 25);
	int _symp = NULL;

	//
	//
	//

	char *tokens = (char*)malloc(strlen(aBuf) + 1);                     // Allocate token storage
	label *labels = (label*)malloc(sizeof(label) * sizeof(uint16_t));   // Allocate label storage

	for (int i = 0; i < sizeof(uint16_t); i++)      // Loop through all elements
		*(labels + i) = label(nullptr, NULL);       // Clear labels

	int last	= NULL;		// End of token storage
	int labcnt	= NULL;		// Amount of labels stored
	int labadr	= NULL;		// label address position

	for (size_t i = 0; i < strlen(aBuf); i++)
	{
		char *token = strtok(aBuf, "\t\n");		/// Remove new line & tabs from file line buffer >> token 
		while (token)
		{

#pragma region Comment Indication

			//	
			//	TODO: Expand Commenting functionallity
			//	- Available to comment on lines with code
			//

			int chrloc;	// Comment location
			char* chrfound = strstr(token, ";");

			if (chrfound) {
				chrloc = token - chrfound;
			}

			if (token[chrloc] == token[strlen(token) - 1])		// Completely ignore stand-alone comments
				break;

			/* Compiler ignore comment lines
			char *chrloc = strchr(token, ';');
			if (chrloc)								///	; Comment
			break;									/// Skip comment line
			*/

#pragma endregion
#pragma region Macro Indication

			//	
			//	TODO: Write Macro indication section
			//	
			//	- Macro structure:
			//
			//	%macro <name> <number_of_params>
			//	<macro_body>
			//	%endmacro
			//

			if (!strcmp(token, "%macro")) {
				char *tag_str = (char*)malloc(sizeof(token));
				strncpy(tag_str, token, strlen(token) - 1);

				strtok(tag_str, "macro ");		// %<name>



			}

#pragma endregion
#pragma region Label Indication

			//	
			//	TODO: Label Indication: Make more safe!
			//	NOTE: Label Indication >> lexisis.h
			//

			/* Check for label */
			if (token[strlen(token) - 1] == ':') {              ///	label:
				char *label_str = (char*)malloc(sizeof(token)); // Allocate temporary space for new label
				strncpy(label_str, token, strlen(token) - 1);   // token >> label_str (label name)
				
				/* Make sure the lable doesn't start with a number */
				if (isdigit(token[strlen(token)])) {
					iSymbol_table[_symp].sym = token;
					iSymbol_table[_symp].addr = labadr;
				}

				/* Prevent label redefinition */
				for (size_t i = 0; i < labcnt; i++) {				// Loop through every stored label
					if (!strcmp(labels[i].id, label_str))		// Error if new label name equals an old label's name
						printf("Assembler Error >> redefined tag '%s'\n", label_str);
				}

				/* Store new tag */
				labels[labcnt].id = (char*)malloc(sizeof(label_str));	//	Allocate memory for label name
				strcpy(labels[labcnt].id, label_str);					//	label_str >> label storage (label name)
				labels[labcnt++].address = labadr;						//	label address ^

				/* Replace token */
				token = "NOP";			// no operation

				free(label_str);
			}

#pragma endregion

			/* Store new token */
			strcpy(tokens + last, token);	// token >> token storage
			last += strlen(token);			// Update end of token storage

			/* Separate tokens with ',' */
			tokens[last++] = ',';

			if (!is_number(token))
				labadr++;					// Next (Address) position

			/* get next token */
			token = strtok(NULL, ",\n");
		}
	}

	tokens[last - 1] = '\0';

	last = NULL;

	char *token_final = (char*)malloc(strlen(aBuf) + 1);

	char *token = strtok(tokens, ",");

}

#endif // !__PREPROC_H