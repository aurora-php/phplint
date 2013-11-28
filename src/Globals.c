/* IMPLEMENTATION MODULE Globals */
#define M2_IMPORT_Globals

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif
/* 20*/ int Globals_DEBUG = 0;
/* 26*/ int Globals_php_ver = 0;
/* 35*/ RECORD * Globals_resource_type = NULL;
/* 35*/ RECORD * Globals_object_type = NULL;
/* 35*/ RECORD * Globals_function_type = NULL;
/* 35*/ RECORD * Globals_mixed_type = NULL;
/* 35*/ RECORD * Globals_string_type = NULL;
/* 35*/ RECORD * Globals_float_type = NULL;
/* 35*/ RECORD * Globals_int_type = NULL;
/* 35*/ RECORD * Globals_boolean_type = NULL;
/* 35*/ RECORD * Globals_void_type = NULL;
/* 35*/ RECORD * Globals_null_type = NULL;
/* 38*/ ARRAY * Globals_required_packages = NULL;
/* 41*/ RECORD * Globals_curr_package = NULL;
/* 43*/ ARRAY * Globals_consts = NULL;
/* 44*/ int Globals_vars_n = 0;
/* 46*/ ARRAY * Globals_vars = NULL;
/* 48*/ ARRAY * Globals_funcs = NULL;
/* 55*/ ARRAY * Globals_classes = NULL;
/* 61*/ int Globals_scope = 0;
/* 64*/ RECORD * Globals_curr_func = NULL;
/* 67*/ RECORD * Globals_curr_class = NULL;
/* 70*/ RECORD * Globals_curr_method = NULL;
/* 73*/ int Globals_recursive_parsing = 0;
/* 82*/ int Globals_loop_level = 0;
/* 85*/ RECORD * Globals_autoload_function = NULL;
/* 88*/ STRING * Globals_autoload_append = NULL;
/* 88*/ STRING * Globals_autoload_separator = NULL;
/* 88*/ STRING * Globals_autoload_prepend = NULL;
/* 92*/ int Globals_try_block_nesting_level = 0;
/*100*/ ARRAY * Globals_exceptions = NULL;

void Globals_0err_entry_get(int i, char **m, char **f, int *l);

/*  5*/ void
/*  5*/ Globals_CurrPackageNotLibrary(STRING *Globals_descr)
/*  5*/ {
/*  5*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 6 * sizeof(void*) + 3 * sizeof(int), Globals_0err_entry_get, 0) = FALSE;
/*  6*/ 	if( (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 1 * sizeof(void*) + 2 * sizeof(int), Globals_0err_entry_get, 1) == NULL ){
/*  7*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 1 * sizeof(void*) + 2 * sizeof(int), Globals_0err_entry_get, 2) = Globals_descr;
/* 10*/ 	}
/* 12*/ }


char * Globals_0func[] = {
    "CurrPackageNotLibrary"
};

int Globals_0err_entry[] = {
    0 /* CurrPackageNotLibrary */, 5,
    0 /* CurrPackageNotLibrary */, 6,
    0 /* CurrPackageNotLibrary */, 7
};

void Globals_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Globals";
    *f = Globals_0func[ Globals_0err_entry[2*i] ];
    *l = Globals_0err_entry[2*i + 1];
}
