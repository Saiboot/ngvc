#ifndef __INSTRUCTIONS_H
#define __INSTRUCTIONS_H

#include <fstream>
#include "../common.h"

/*
//	label:
//	
//	Mnemonic
//	
//	operand (argument1, argument2, argument3)
//	
 */


//	
//	Aquire size of file
//	@param: FILE*
//
//	@return: Size of file
//	
uint32_t getFileSize(FILE *file) {
	if (fseek(file, 0L, SEEK_END) == 0) {
		uint32_t sz = ftell(file);
		fseek(file, 0L, SEEK_SET);
		return sz;
	}
	return 0;
}


//	
//	Inspect file content
//	@param: file path
//	
//	@return: file content
//	
char* inspectFile(char* file_path) {

	FILE *pFile = fopen(file_path, "rb");
	long size = getFileSize(pFile);

	char *aBuf = (char*) malloc(sizeof(char) * size + 1);

	if (pFile != NULL && size != 0) {

		size_t len = fread(aBuf, 1, size, pFile);

		if (ferror(pFile))
			exit(EXIT_FAILURE);
		else
			aBuf[len] = '\0';
	} else 
		exit(EXIT_FAILURE);

	fclose(pFile);

	return aBuf;
}


#endif // !__INSTRUCTIONS_H