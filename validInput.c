#include <stdio.h>
#include <stc/cstr.h>
#include <stc/cregex.h>
#include <validInput.h>

bool validInput(const cstr *input)
{
	//Initialize cregex object 
	cregex regex = cregex_init();

	//compile regular expression pattern
	int result = cregex_compile(&regex, "[_$a-zA-Z][_$a-zA-Z0-9]*");


	//check if the first and every character is valid
	if (cstr_starts_with(input, "1") || cstr_starts_with(input, "$")) {
		fprintf(stderr, "Invalid variable name\n");
	}else if (cregex_is_match(&regex, cstr_str(input))){
		;
	}
	cregex_drop(&regex);
}
