#include <stdio.h>
#include <stdlib.h>


#define i_key char
#define i_type variables
#define i_val cstr
#include <stc/cmap.h>
#include <stc/cstr.h>


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
cmap variables = cmap_init();
static void main_loop(void)
{
	cstr input = cstr_null;
	printf("%s ", STARTER);

	cstr_getline(&input, stdin);

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
