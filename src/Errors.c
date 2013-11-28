/* IMPLEMENTATION MODULE Errors */
#define M2_IMPORT_Errors

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif

#ifndef M2_IMPORT_Exceptions
#    include "Exceptions.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Search
#    include "Search.c"
#endif

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

void Errors_0err_entry_get(int i, char **m, char **f, int *l);
/* 17*/ ARRAY * Errors_errors = NULL;
/* 24*/ int Errors_handle_error = 0;
/* 28*/ RECORD * Errors_error_throws_exception = NULL;
/* 38*/ RECORD * Errors_first_error_source_found = NULL;

/* 40*/ void
/* 40*/ Errors_init(void)
/* 40*/ {
/* 40*/ 	if( Errors_errors != NULL ){
/* 42*/ 		return ;
/* 43*/ 	}
/* 43*/ 	Errors_errors = (
/* 44*/ 		push((char*) alloc_ARRAY(sizeof(void *), 1)),
/* 44*/ 		push((char*) (
/* 44*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 44*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"E_ERROR"),
/* 44*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 44*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 1,
/* 44*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 45*/ 			(RECORD*) pop()
/* 45*/ 		)),
/* 45*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/* 45*/ 		push((char*) (
/* 45*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 45*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"E_WARNING"),
/* 45*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 45*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 2,
/* 45*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 46*/ 			(RECORD*) pop()
/* 46*/ 		)),
/* 46*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),1) = (RECORD*) tos(), pop(),
/* 46*/ 		push((char*) (
/* 46*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 46*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"E_PARSE"),
/* 46*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 46*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 4,
/* 46*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 47*/ 			(RECORD*) pop()
/* 47*/ 		)),
/* 47*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),2) = (RECORD*) tos(), pop(),
/* 47*/ 		push((char*) (
/* 47*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 47*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"E_NOTICE"),
/* 47*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 47*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 8,
/* 47*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 48*/ 			(RECORD*) pop()
/* 48*/ 		)),
/* 48*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),3) = (RECORD*) tos(), pop(),
/* 48*/ 		push((char*) (
/* 48*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 48*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"E_CORE_ERROR"),
/* 48*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 48*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 16,
/* 48*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 49*/ 			(RECORD*) pop()
/* 49*/ 		)),
/* 49*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),4) = (RECORD*) tos(), pop(),
/* 49*/ 		push((char*) (
/* 49*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 49*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"E_CORE_WARNING"),
/* 49*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 49*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 32,
/* 49*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 50*/ 			(RECORD*) pop()
/* 50*/ 		)),
/* 50*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),5) = (RECORD*) tos(), pop(),
/* 50*/ 		push((char*) (
/* 50*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 50*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"E_COMPILE_ERROR"),
/* 50*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 50*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 64,
/* 50*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 51*/ 			(RECORD*) pop()
/* 51*/ 		)),
/* 51*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),6) = (RECORD*) tos(), pop(),
/* 51*/ 		push((char*) (
/* 51*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 51*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"E_COMPILE_WARNING"),
/* 51*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 51*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 128,
/* 51*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 52*/ 			(RECORD*) pop()
/* 52*/ 		)),
/* 52*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),7) = (RECORD*) tos(), pop(),
/* 52*/ 		push((char*) (
/* 52*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 52*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"E_USER_ERROR"),
/* 52*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 52*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 256,
/* 52*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/* 53*/ 			(RECORD*) pop()
/* 53*/ 		)),
/* 53*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),8) = (RECORD*) tos(), pop(),
/* 53*/ 		push((char*) (
/* 53*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 53*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"E_USER_WARNING"),
/* 53*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 53*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 512,
/* 53*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/* 54*/ 			(RECORD*) pop()
/* 54*/ 		)),
/* 54*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),9) = (RECORD*) tos(), pop(),
/* 54*/ 		push((char*) (
/* 54*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 54*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"E_USER_NOTICE"),
/* 54*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 54*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 1024,
/* 54*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/* 55*/ 			(RECORD*) pop()
/* 55*/ 		)),
/* 55*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),10) = (RECORD*) tos(), pop(),
/* 55*/ 		push((char*) (
/* 55*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 55*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"E_STRICT"),
/* 55*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 55*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 2048,
/* 55*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 56*/ 			(RECORD*) pop()
/* 56*/ 		)),
/* 56*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),11) = (RECORD*) tos(), pop(),
/* 56*/ 		push((char*) (
/* 56*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 56*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"E_RECOVERABLE_ERROR"),
/* 56*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 56*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 4096,
/* 56*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 57*/ 			(RECORD*) pop()
/* 57*/ 		)),
/* 57*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),12) = (RECORD*) tos(), pop(),
/* 57*/ 		push((char*) (
/* 57*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 57*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"E_DEPRECATED"),
/* 57*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 57*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 8192,
/* 57*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/* 58*/ 			(RECORD*) pop()
/* 58*/ 		)),
/* 58*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),13) = (RECORD*) tos(), pop(),
/* 58*/ 		push((char*) (
/* 58*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 4 * sizeof(int), 1)),
/* 58*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"E_USER_DEPRECATED"),
/* 58*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 58*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 16384,
/* 58*/ 			*(int*) (tos()+1 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/* 60*/ 			(RECORD*) pop()
/* 60*/ 		)),
/* 60*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),14) = (RECORD*) tos(), pop(),
/* 61*/ 		(ARRAY*) pop()
/* 61*/ 	);
/* 63*/ }


/* 65*/ int
/* 65*/ Errors_SearchByCode(int Errors_code)
/* 65*/ {
/* 67*/ 	int Errors_i = 0;
/* 67*/ 	Errors_init();
/* 68*/ 	{
/* 68*/ 		int m2runtime_for_limit_1;
/* 68*/ 		Errors_i = 0;
/* 68*/ 		m2runtime_for_limit_1 = (m2runtime_count(Errors_errors) - 1);
/* 69*/ 		for( ; Errors_i <= m2runtime_for_limit_1; Errors_i += 1 ){
/* 69*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Errors_errors, Errors_i, Errors_0err_entry_get, 0), 1 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 1) == Errors_code) ){
/* 70*/ 				return Errors_i;
/* 73*/ 			}
/* 73*/ 		}
/* 73*/ 	}
/* 73*/ 	return -1;
/* 77*/ }


/* 79*/ int
/* 79*/ Errors_NameToCode(STRING *Errors_name)
/* 79*/ {
/* 81*/ 	int Errors_i = 0;
/* 81*/ 	Errors_init();
/* 82*/ 	{
/* 82*/ 		int m2runtime_for_limit_1;
/* 82*/ 		Errors_i = 0;
/* 82*/ 		m2runtime_for_limit_1 = (m2runtime_count(Errors_errors) - 1);
/* 83*/ 		for( ; Errors_i <= m2runtime_for_limit_1; Errors_i += 1 ){
/* 83*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Errors_errors, Errors_i, Errors_0err_entry_get, 2), 0 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 3), Errors_name) == 0 ){
/* 84*/ 				return  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Errors_errors, Errors_i, Errors_0err_entry_get, 4), 1 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 5);
/* 87*/ 			}
/* 87*/ 		}
/* 87*/ 	}
/* 87*/ 	return -1;
/* 91*/ }


/* 93*/ STRING *
/* 93*/ Errors_CodeToName(int Errors_code)
/* 93*/ {
/* 95*/ 	int Errors_i = 0;
/* 95*/ 	Errors_i = Errors_SearchByCode(Errors_code);
/* 96*/ 	if( (Errors_i >= 0) ){
/* 97*/ 		return (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Errors_errors, Errors_i, Errors_0err_entry_get, 6), 0 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 7);
/* 99*/ 	} else {
/* 99*/ 		return NULL;
/*102*/ 	}
/*102*/ 	m2runtime_missing_return(Errors_0err_entry_get, 8);
/*102*/ 	return NULL;
/*104*/ }


/*106*/ ARRAY *
/*106*/ Errors_ErrorsSetToNames(int Errors_set)
/*106*/ {
/*107*/ 	int Errors_i = 0;
/*109*/ 	ARRAY * Errors_a = NULL;
/*109*/ 	Errors_init();
/*110*/ 	{
/*110*/ 		int m2runtime_for_limit_1;
/*110*/ 		Errors_i = 0;
/*110*/ 		m2runtime_for_limit_1 = (m2runtime_count(Errors_errors) - 1);
/*111*/ 		for( ; Errors_i <= m2runtime_for_limit_1; Errors_i += 1 ){
/*111*/ 			if( (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Errors_errors, Errors_i, Errors_0err_entry_get, 9), 1 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 10) & Errors_set) != 0) ){
/*112*/ 				*(STRING **)m2runtime_dereference_lhs_ARRAY_next(&Errors_a, sizeof(void *), 1, Errors_0err_entry_get, 11) = (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Errors_errors, Errors_i, Errors_0err_entry_get, 12), 0 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 13);
/*113*/ 				Errors_set = (Errors_set & ~ *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Errors_errors, Errors_i, Errors_0err_entry_get, 14), 1 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 15));
/*116*/ 			}
/*116*/ 		}
/*116*/ 	}
/*116*/ 	if( (Errors_set != 0) ){
/*117*/ 		*(STRING **)m2runtime_dereference_lhs_ARRAY_next(&Errors_a, sizeof(void *), 1, Errors_0err_entry_get, 16) = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"FIXME_UNKNOWN_ERROR_", m2runtime_itos(Errors_set), (STRING *) 1);
/*119*/ 	}
/*119*/ 	return Errors_a;
/*123*/ }


/*125*/ STRING *
/*125*/ Errors_ErrorsSetToString(int Errors_set)
/*125*/ {
/*126*/ 	ARRAY * Errors_a = NULL;
/*127*/ 	int Errors_i = 0;
/*129*/ 	STRING * Errors_s = NULL;
/*129*/ 	Errors_a = Errors_ErrorsSetToNames(Errors_set);
/*130*/ 	{
/*130*/ 		int m2runtime_for_limit_1;
/*130*/ 		Errors_i = 0;
/*130*/ 		m2runtime_for_limit_1 = (m2runtime_count(Errors_a) - 1);
/*131*/ 		for( ; Errors_i <= m2runtime_for_limit_1; Errors_i += 1 ){
/*131*/ 			if( Errors_s != NULL ){
/*132*/ 				Errors_s = m2runtime_concat_STRING(0, Errors_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", (STRING *) 1);
/*134*/ 			}
/*134*/ 			Errors_s = m2runtime_concat_STRING(0, Errors_s, (STRING *)m2runtime_dereference_rhs_ARRAY(Errors_a, Errors_i, Errors_0err_entry_get, 17), (STRING *) 1);
/*136*/ 		}
/*136*/ 	}
/*136*/ 	return Errors_s;
/*140*/ }


/*142*/ int
/*142*/ Errors_IsUserError(int Errors_code)
/*142*/ {
/*144*/ 	int Errors_i = 0;
/*144*/ 	Errors_i = Errors_SearchByCode(Errors_code);
/*145*/ 	if( (Errors_i >= 0) ){
/*146*/ 		return  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Errors_errors, Errors_i, Errors_0err_entry_get, 18), 1 * sizeof(void*) + 3 * sizeof(int), Errors_0err_entry_get, 19);
/*148*/ 	} else {
/*148*/ 		return FALSE;
/*151*/ 	}
/*151*/ 	m2runtime_missing_return(Errors_0err_entry_get, 20);
/*151*/ 	return 0;
/*153*/ }


/*155*/ void
/*155*/ Errors_RaiseErrors(int Errors_set)
/*155*/ {
/*155*/ 	if( (Errors_set == 0) ){
/*157*/ 		return ;
/*159*/ 	}
/*159*/ 	if( Errors_error_throws_exception == NULL ){
/*162*/ 		if( ((Errors_first_error_source_found == NULL) && ! *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 6 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 21)) ){
/*164*/ 			Errors_first_error_source_found = Scanner_here();
/*167*/ 		}
/*167*/ 		if( ((Errors_error_throws_exception == NULL) && ((Errors_handle_error > 0))) ){
/*170*/ 			return ;
/*172*/ 		}
/*172*/ 		if( Scanner_print_notices ){
/*173*/ 			Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"unhandled error(s): ", Errors_ErrorsSetToString(Errors_set), (STRING *) 1));
/*177*/ 		}
/*177*/ 		if( Globals_curr_func != NULL ){
/*178*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Globals_curr_func, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 5 * sizeof(int), Errors_0err_entry_get, 22) = ( *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 10 * sizeof(void*) + 5 * sizeof(int), Errors_0err_entry_get, 23) | Errors_set);
/*179*/ 		} else if( Globals_curr_method != NULL ){
/*180*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Globals_curr_method, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 9 * sizeof(int), Errors_0err_entry_get, 24) = ( *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 9 * sizeof(void*) + 9 * sizeof(int), Errors_0err_entry_get, 25) | Errors_set);
/*182*/ 		} else {
/*182*/ 			Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"Might raise unchecked error(s) in ", Scanner_reference(Scanner_here()), m2runtime_CHR(46), (STRING *) 1));
/*186*/ 		}
/*186*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 6 * sizeof(void*) + 2 * sizeof(int), Errors_0err_entry_get, 26) ){
/*188*/ 		Exceptions_AddExceptions((
/*188*/ 			push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*188*/ 			push((char*) Errors_error_throws_exception),
/*188*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/*189*/ 			(ARRAY*) pop()
/*189*/ 		));
/*192*/ 	} else {
/*192*/ 		Exceptions_ThrowExceptions((
/*192*/ 			push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*192*/ 			push((char*) Errors_error_throws_exception),
/*192*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/*193*/ 			(ARRAY*) pop()
/*193*/ 		));
/*196*/ 	}
/*198*/ }


/*200*/ void
/*200*/ Errors_ParseErrorThrowsExceptionPragma(RECORD *Errors_where, ARRAY *Errors_a)
/*200*/ {
/*202*/ 	RECORD * Errors_c = NULL;
/*202*/ 	if( (m2runtime_count(Errors_a) != 2) ){
/*203*/ 		Scanner_Error2(Errors_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)"expected 1 argument for pragma error_throws_exception");
/*205*/ 		return ;
/*206*/ 	}
/*206*/ 	if( Errors_error_throws_exception != NULL ){
/*207*/ 		Scanner_Error2(Errors_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"pragma already set before");
/*209*/ 		return ;
/*210*/ 	}
/*210*/ 	if( Errors_first_error_source_found != NULL ){
/*211*/ 		Scanner_Error2(Errors_where, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"error mapping into exception cannot be applied here", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)" because an error source was already encountered", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)" in source code before, the first one seen in ", Scanner_reference(Errors_first_error_source_found), (STRING *) 1));
/*216*/ 	}
/*216*/ 	if( !m2_match((STRING *)m2runtime_dereference_rhs_ARRAY(Errors_a, 1, Errors_0err_entry_get, 27), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"^\134\134?[_a-zA-Z\200-\377]+(\134\134[_0-9a-zA-Z\200-\377]+)*$") ){
/*217*/ 		Scanner_Error2(Errors_where, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"invalid class name: ", (STRING *)m2runtime_dereference_rhs_ARRAY(Errors_a, 1, Errors_0err_entry_get, 28), (STRING *) 1));
/*219*/ 		return ;
/*220*/ 	}
/*220*/ 	Errors_c = Search_SearchClass((STRING *)m2runtime_dereference_rhs_ARRAY(Errors_a, 1, Errors_0err_entry_get, 29));
/*221*/ 	if( Errors_c == NULL ){
/*222*/ 		Scanner_Error2(Errors_where, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"unknown class `", (STRING *)m2runtime_dereference_rhs_ARRAY(Errors_a, 1, Errors_0err_entry_get, 30), m2runtime_CHR(39), (STRING *) 1));
/*224*/ 		return ;
/*225*/ 	}
/*225*/ 	if( !Classes_IsExceptionClass(Errors_c) ){
/*226*/ 		Scanner_Error2(Errors_where, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", (STRING *)m2runtime_dereference_rhs_ARRAY(Errors_a, 1, Errors_0err_entry_get, 31), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' is not an exception", (STRING *) 1));
/*228*/ 		return ;
/*229*/ 	}
/*229*/ 	Errors_error_throws_exception = Errors_c;
/*233*/ }


/*235*/ void
/*235*/ Errors_EnteringSilencer(void)
/*235*/ {
/*235*/ 	Errors_handle_error = (Errors_handle_error + 1);
/*236*/ 	if( Errors_error_throws_exception != NULL ){
/*237*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\134,\0,\0,\0)"errors mapping into exception is in effect, the silencer operator `@' cannot be used anymore");
/*240*/ 	}
/*242*/ }


/*244*/ void
/*244*/ Errors_ExitingSilencer(void)
/*244*/ {
/*244*/ 	Errors_handle_error = (Errors_handle_error - 1);
/*249*/ }


char * Errors_0func[] = {
    "SearchByCode",
    "NameToCode",
    "CodeToName",
    "ErrorsSetToNames",
    "ErrorsSetToString",
    "IsUserError",
    "RaiseErrors",
    "ParseErrorThrowsExceptionPragma"
};

int Errors_0err_entry[] = {
    0 /* SearchByCode */, 69,
    0 /* SearchByCode */, 69,
    1 /* NameToCode */, 83,
    1 /* NameToCode */, 83,
    1 /* NameToCode */, 84,
    1 /* NameToCode */, 84,
    2 /* CodeToName */, 97,
    2 /* CodeToName */, 97,
    2 /* CodeToName */, 101,
    3 /* ErrorsSetToNames */, 111,
    3 /* ErrorsSetToNames */, 111,
    3 /* ErrorsSetToNames */, 112,
    3 /* ErrorsSetToNames */, 112,
    3 /* ErrorsSetToNames */, 112,
    3 /* ErrorsSetToNames */, 113,
    3 /* ErrorsSetToNames */, 113,
    3 /* ErrorsSetToNames */, 117,
    4 /* ErrorsSetToString */, 135,
    5 /* IsUserError */, 146,
    5 /* IsUserError */, 146,
    5 /* IsUserError */, 150,
    6 /* RaiseErrors */, 163,
    6 /* RaiseErrors */, 178,
    6 /* RaiseErrors */, 178,
    6 /* RaiseErrors */, 180,
    6 /* RaiseErrors */, 180,
    6 /* RaiseErrors */, 186,
    7 /* ParseErrorThrowsExceptionPragma */, 216,
    7 /* ParseErrorThrowsExceptionPragma */, 217,
    7 /* ParseErrorThrowsExceptionPragma */, 220,
    7 /* ParseErrorThrowsExceptionPragma */, 222,
    7 /* ParseErrorThrowsExceptionPragma */, 226
};

void Errors_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Errors";
    *f = Errors_0func[ Errors_0err_entry[2*i] ];
    *l = Errors_0err_entry[2*i + 1];
}
