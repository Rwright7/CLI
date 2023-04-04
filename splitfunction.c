#include <stdio.h>
#include <stc/cstr.h>
#include <splitfunction.h>


void splitfunction(cstr *input)
{
	//Find the position of the "=" character in the input string
	ptrdiff_t splitIndex = cstr_find_at(input, 0, "=");

	csview left = c_sv(cstr_str(input), splitIndex - 0);
	csview right = c_sv(cstr_str(input) + splitIndex + 1 , cstr_size(input) - splitIndex);
}
