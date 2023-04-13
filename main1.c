#include <stdio.h>
#include <stdlib.h>
#include <stc/cstr.h>
#define i_key cstr
#define i_val cstr
#define i_cmp(a,b) cstr_icmp((a), (b))
#define i_hash(a) cstr_hash((a))
#include <stc/cmap.h>
#include <splitfunction.h>

cmap_cstr variables;

#define TITLE " ----(my terminal) ----"
#define STARTER ">>"


// setup code, runs only once at the start of the program
static void main_setup(int argc, char **argv)
{
	variables = cmap_cstr_init();
	system("clear");

	printf("%s\n", TITLE);
}

// here goes your active constantly-running code, runs infinitely
static void main_loop(void)
{
	cstr input = cstr_init();
	printf("%s ", STARTER);

	cstr_getline(&input, stdin);
	
	csview left, right;
        splitfunction(&input, &left, &right);
	
	cstr key = cstr_from_sv(left);
	cstr value = cstr_from_sv(right);

	cmap_cstr_insert(&variables, key, value);
	
	cmap_cstr_get(&variables, input);
	
	printf("%s\n", cstr_str(&value));

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
