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

	size_t len;

//	
//	Aquire size of file
//	@param: FILE*
//
//	@return: Size of file
//	
uint32_t getFileSize(FILE *file) {
	if(fseek(file, 0L, SEEK_END) == 0) {
		uint32_t sz = ftell(file);
		fseek(file, 0L, SEEK_SET);
		return sz;
	}

	return 0;
}


// TODO: -InspectFile-
//	Function needs rework
//	Issue: Doesn't buff the whole file, only first word

//	
//	Inspect file content
//	@param: file path
//	
//	@return: file content
//
char* inspectFile(char* file_path) {

	FILE *pFile = fopen(file_path, "r");
	char *aBuf = (char*) malloc(sizeof(char) * (getFileSize(pFile) + 1));

	if (pFile != NULL && sizeof(aBuf) > sizeof(char) * 1) {

		len = fread(aBuf, 1, sizeof(aBuf), pFile);

		if (ferror(pFile))
			exit(-1);
		else
			*(aBuf + len++) = '\0';
	} else 
		exit(-1);

	fclose(pFile);

	return aBuf;
}

size_t getFileLength() {
	return len;
}

#endif // !__INSTRUCTIONS_H