#include <stdio.h>
#include <stdlib.h>


#include <stc/cstr.h>
#define i_val cstr

#define TITLE " ----(my terminal) ----"
#define STARTER ">>"
//#define MAX_STRING_SIZE 200

/* main.c */

// setup code, runs only once at the start of the program
static void main_setup(int argc, char **argv)
{
	//(void)argv[argc-1];
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

	if (cstr_eq_cstr(&input, "hello"))
	{
		printf("Hello, world!\n");
	}

	else if (cstr_eq_cstr(&input, "name"))
	{
		printf("My name is CLI Bot!\n");
	}

	else if (cstr_eq_cstr(&input, "exit"))
	{
		printf("Goodbye!\n");
		exit(0);
	}

	else
	{
		printf("Unknown command: %s\n", cstr_data(&input));
	}

	cstr_drop(&input);
		//check for exit command


		//copy input into stack 
	
	

}


// You may not change `main()`
int main(int argc, char **argv)
{
	    //(void)argv[argc-1];
		// use `exit()` in `main_setup()` or `main_loop()` to exit early with a specific exit code.
	main_setup(argc, argv);
	while (true) { main_loop(); }
	return 0;
}