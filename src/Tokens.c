/* IMPLEMENTATION MODULE Tokens */
#define M2_IMPORT_Tokens

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

void Tokens_0err_entry_get(int i, char **m, char **f, int *l);
/*  9*/ ARRAY * Tokens_tokens = NULL;

/* 11*/ void
/* 11*/ Tokens_Init(void)
/* 11*/ {
/* 11*/ 	if( Tokens_tokens != NULL ){
/* 13*/ 		return ;
/* 14*/ 	}
/* 14*/ 	Tokens_tokens = str_split(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\247,\1,\0,\0)"eof unknown unimplemented_keyword text open_tag open_tag_with_echo close_tag define function declare lbrace rbrace lround rround lsquare rsquare comma semicolon colon double_colon variable for foreach as while if else elseif return identifier question assign rarrow single_quoted_string double_quoted_string embedded_variable continuing_double_quoted_string here_doc lit_int lit_float plus minus times div eq eeq ne nee gt ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\170,\1,\0,\0)"ge lt le incr decr not or or2 and and2 at period arrow global null boolean false true int float string array object bit_or bit_and mod period_assign plus_assign minus_assign times_assign div_assign mod_assign bit_and_assign bit_or_assign bit_xor_assign lshift_assign rshift_assign lshift rshift bit_xor xor bit_not abstract interface class extends implements const var public ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\245,\1,\0,\0)"private protected static final self parent new clone instanceof list switch case break default exit echo print trigger_error do try catch throw continue isset include include_once require require_once namespace use goto x_require_module x_single_quoted_string x_semicolon x_colon x_comma x_assign x_forward x_function x_class x_extends x_implements x_const x_interface x_unchecked x_void x_boolean x_int x_float x_string ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\152,\1,\0,\0)"x_array x_mixed x_resource x_object x_identifier x_variable x_bit_and x_args x_lround x_rround x_lsquare x_rsquare x_lbrace x_rbrace x_pragma x_if_php_ver_4 x_if_php_ver_5 x_else x_end_if_php_ver x_missing_break x_missing_default x_public x_protected x_private x_abstract x_static x_final x_self x_parent x_throws x_return x_namespace x_lt x_gt x_doc x_docBlock ", (STRING *) 1), m2runtime_CHR(32));
/* 21*/ }


/* 23*/ STRING *
/* 23*/ Tokens_CodeToName(int Tokens_code)
/* 23*/ {
/* 23*/ 	Tokens_Init();
/* 24*/ 	if( (((Tokens_code >= 0)) && ((Tokens_code < (m2runtime_count(Tokens_tokens) - 1)))) ){
/* 25*/ 		return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"sym_", (STRING *)m2runtime_dereference_rhs_ARRAY(Tokens_tokens, Tokens_code, Tokens_0err_entry_get, 0), (STRING *) 1);
/* 27*/ 	} else {
/* 27*/ 		return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"sym_", m2runtime_itos(Tokens_code), (STRING *) 1);
/* 30*/ 	}
/* 30*/ 	m2runtime_missing_return(Tokens_0err_entry_get, 1);
/* 30*/ 	return NULL;
/* 32*/ }


char * Tokens_0func[] = {
    "CodeToName"
};

int Tokens_0err_entry[] = {
    0 /* CodeToName */, 26,
    0 /* CodeToName */, 29
};

void Tokens_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Tokens";
    *f = Tokens_0func[ Tokens_0err_entry[2*i] ];
    *l = Tokens_0err_entry[2*i + 1];
}
