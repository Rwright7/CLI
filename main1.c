#include <stdio.h>
#include <stdlib.h>


#include <stc/cstr.h>
#define i_val cstr

#define TITLE " ----(my terminal) ----"
#define STARTER ">>"


/* main.c */

// setup code, runs only once at the start of the program
static void main_setup(int argc, char **argv)
{
	
	//clear screen 
	system("clear");

	printf("%s\n", TITLE);
	printf("%s", STARTER);
}

// here goes your active constantly-running code, runs infinitely
static void main_loop(void)
{
	cstr input = cstr_null;
	printf("%s ", STARTER);

	cstr_getline(&input, stdin);

	if (cstr_equals(&input,"hello"))
	{
		printf("Hello, world!\n");
	}

	else if (cstr_equals(&input,  (const cstr*)"name"))
	{
		printf("My name is CLI Bot!\n");
	}

	else if (cstr_equals(&input,  (const cstr*)"exit"))
	{
		printf("Goodbye!\n");
		exit(0);
	}

	else
	{
		printf("Unknown command: %s\n", cstr_data(&input));
	}

	cstr_drop(&input);

}


// You may not change `main()`
int main(int argc, char **argv)
{
	// use `exit()` in `main_setup()` or `main_loop()` to exit early with a specific exit code.
	main_setup(argc, argv);
	while (true) { main_loop(); }
	return 0;
}
