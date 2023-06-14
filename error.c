/* libjodycode error strings */

#include <stdio.h>

struct jc_error {
	char *name;
	char *desc;
};


#define JC_ERRCNT 6
static const int errcnt = JC_ERRCNT;
const struct jc_error jc_error_list[JC_ERRCNT + 1] = {
	{ "no_error",    "success" },
	{ "null_param",  "get_relative_name has NULL parameter" },
	{ "getcwd",      "couldn't get the current directory" },
	{ "cdotdot",     "jc_collapse_dotdot() call failed" },
	{ "grn_dir_end", "get_relative_name() result has directory at end" },
	{ "bad_errnum",  "invalid error number" },
	{ NULL, NULL },
};


char *jc_get_errname(int errnum)
{
	if (errnum > errcnt) return NULL;
	if (errnum < 0) errnum = -errnum;
	return jc_error_list[errnum].name;
}


char *jc_get_errdesc(int errnum)
{
	if (errnum > errcnt) return NULL;
	if (errnum < 0) errnum = -errnum;
	return jc_error_list[errnum].desc;
}


int jc_print_error(int errnum)
{
	if (errnum > errcnt) return -5;
	if (errnum < 0) errnum = -errnum;
	fprintf(stderr, "error: %s (%s)\n", jc_error_list[errnum].desc, jc_error_list[errnum].name);
	return 0;
}


#ifdef JC_TEST
int main(void)
{
	static int i;

	for (i = 0; i < errcnt; i++) printf("[%d] %s: %s\n", i, jc_get_errname(i), jc_get_errdesc(i));
	for (i = 0; i < errcnt; i++) jc_print_error(i);
}
#endif