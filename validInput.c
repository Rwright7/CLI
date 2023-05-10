#include <stdio.h>
#include <stc/cstr.h>
#include <stc/cregex.h>
#include <validInput.h>
#include <stc/csview.h>

bool validInput(const cstr *input){

	//Initialize cregex object 
	cregex regex = cregex_init();

	//compile regular expression pattern
	int result = cregex_compile(&regex, "[_$a-zA-Z][_$a-zA-Z0-9]*");

	csview match[4];

	//check if the first and every character is valid
	if (cregex_is_match(&regex, cstr_str(input))) {
		;
	}else if (cregex_find(&regex, cstr_str(input), match) != CREG_OK){
			
			fprintf(stderr, "Invalid variable name\n");
	}
	return 0;
	cregex_drop(&regex);
}

/*

	Validate input. If the user enters an invalid name for a variable, 
	the program will report the error (and NOT abort). Valid variable 
	names must follow these rules:

 1. Every character must be one of _$abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789. 

2. The very first character cannot be a number or a dollar sign. eg 1a, $age, etc are invalid variable name.

*/