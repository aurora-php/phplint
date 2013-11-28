/* IMPLEMENTATION MODULE Exceptions */
#define M2_IMPORT_Exceptions

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Search
#    include "Search.c"
#endif

void Exceptions_0err_entry_get(int i, char **m, char **f, int *l);

/* 11*/ void
/* 11*/ Exceptions_AddExceptionToSet(RECORD *Exceptions_exception, ARRAY **Exceptions_exceptions)
/* 11*/ {
/* 13*/ 	int Exceptions_i = 0;
/* 13*/ 	{
/* 13*/ 		int m2runtime_for_limit_1;
/* 13*/ 		Exceptions_i = 0;
/* 13*/ 		m2runtime_for_limit_1 = (m2runtime_count(*Exceptions_exceptions) - 1);
/* 14*/ 		for( ; Exceptions_i <= m2runtime_for_limit_1; Exceptions_i += 1 ){
/* 14*/ 			if( (RECORD *)m2runtime_dereference_rhs_ARRAY(*Exceptions_exceptions, Exceptions_i, Exceptions_0err_entry_get, 0) == Exceptions_exception ){
/* 16*/ 				return ;
/* 18*/ 			}
/* 18*/ 		}
/* 18*/ 	}
/* 18*/ 	*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(Exceptions_exceptions, sizeof(void *), 1, Exceptions_0err_entry_get, 1) = Exceptions_exception;
/* 22*/ }


/* 24*/ void
/* 24*/ Exceptions_AddException(RECORD *Exceptions_exception)
/* 24*/ {
/* 24*/ 	if( (Globals_try_block_nesting_level == 0) ){
/* 25*/ 		if( Globals_curr_func != NULL ){
/* 26*/ 			Exceptions_AddExceptionToSet(Exceptions_exception, (ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_func, 10 * sizeof(void*) + 6 * sizeof(int), 10, 6 * sizeof(void*) + 2 * sizeof(int), Exceptions_0err_entry_get, 2));
/* 27*/ 		} else if( Globals_curr_method != NULL ){
/* 28*/ 			Exceptions_AddExceptionToSet(Exceptions_exception, (ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_method, 9 * sizeof(void*) + 10 * sizeof(int), 9, 5 * sizeof(void*) + 2 * sizeof(int), Exceptions_0err_entry_get, 3));
/* 31*/ 		}
/* 31*/ 	} else {
/* 31*/ 		Exceptions_AddExceptionToSet(Exceptions_exception, &Globals_exceptions);
/* 34*/ 	}
/* 36*/ }


/* 37*/ void
/* 37*/ Exceptions_AddExceptions(ARRAY *Exceptions_exceptions)
/* 37*/ {
/* 39*/ 	int Exceptions_i = 0;
/* 39*/ 	{
/* 39*/ 		int m2runtime_for_limit_1;
/* 39*/ 		Exceptions_i = 0;
/* 39*/ 		m2runtime_for_limit_1 = (m2runtime_count(Exceptions_exceptions) - 1);
/* 40*/ 		for( ; Exceptions_i <= m2runtime_for_limit_1; Exceptions_i += 1 ){
/* 40*/ 			Exceptions_AddException((RECORD *)m2runtime_dereference_rhs_ARRAY(Exceptions_exceptions, Exceptions_i, Exceptions_0err_entry_get, 4));
/* 43*/ 		}
/* 43*/ 	}
/* 45*/ }


/* 47*/ void
/* 47*/ Exceptions_ThrowExceptions(ARRAY *Exceptions_exceptions)
/* 47*/ {
/* 48*/ 	ARRAY * Exceptions_orphans = NULL;
/* 48*/ 	ARRAY * Exceptions_checked = NULL;
/* 48*/ 	ARRAY * Exceptions_throws = NULL;
/* 50*/ 	STRING * Exceptions_s = NULL;
/* 50*/ 	if( (m2runtime_count(Exceptions_exceptions) == 0) ){
/* 52*/ 		return ;
/* 54*/ 	}
/* 54*/ 	Exceptions_checked = Classes_CheckedExceptionsSubset(Exceptions_exceptions);
/* 55*/ 	if( (m2runtime_count(Exceptions_checked) == 0) ){
/* 57*/ 		return ;
/* 59*/ 	}
/* 59*/ 	if( Scanner_print_notices ){
/* 60*/ 		Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"here generating exception(s) ", Classes_ClassesList(Classes_Sort(Exceptions_checked)), (STRING *) 1));
/* 64*/ 	}
/* 64*/ 	if( Globals_curr_func != NULL ){
/* 66*/ 		if( (Globals_try_block_nesting_level == 0) ){
/* 67*/ 			Exceptions_throws = (ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 6 * sizeof(void*) + 2 * sizeof(int), Exceptions_0err_entry_get, 5);
/* 68*/ 			Exceptions_orphans = Classes_OrphanClasses(Exceptions_throws, Exceptions_checked);
/* 69*/ 			if( (m2runtime_count(Exceptions_orphans) > 0) ){
/* 70*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"exception(s) must be caught or declared to be thrown: ", Classes_ClassesList(Classes_Sort(Exceptions_orphans)), (STRING *) 1));
/* 72*/ 				Exceptions_AddExceptions(Exceptions_orphans);
/* 76*/ 			}
/* 76*/ 		} else {
/* 76*/ 			Exceptions_AddExceptions(Exceptions_checked);
/* 79*/ 		}
/* 79*/ 	} else if( Globals_curr_method != NULL ){
/* 81*/ 		if( (Globals_try_block_nesting_level == 0) ){
/* 82*/ 			Exceptions_throws = (ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 5 * sizeof(void*) + 2 * sizeof(int), Exceptions_0err_entry_get, 6);
/* 83*/ 			Exceptions_orphans = Classes_OrphanClasses(Exceptions_throws, Exceptions_checked);
/* 84*/ 			if( (m2runtime_count(Exceptions_orphans) > 0) ){
/* 85*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"exception(s) must be caught or declared to be thrown: ", Classes_ClassesList(Classes_Sort(Exceptions_orphans)), (STRING *) 1));
/* 87*/ 				Exceptions_AddExceptions(Exceptions_orphans);
/* 91*/ 			}
/* 91*/ 		} else {
/* 91*/ 			Exceptions_AddExceptions(Exceptions_checked);
/* 95*/ 		}
/* 96*/ 	} else {
/* 96*/ 		if( (Globals_try_block_nesting_level == 0) ){
/* 97*/ 			Exceptions_orphans = Exceptions_checked;
/* 98*/ 			if( (m2runtime_count(Exceptions_orphans) > 0) ){
/* 99*/ 				Exceptions_s = Classes_ClassesList(Classes_Sort(Exceptions_orphans));
/*100*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"uncaught exception(s): ", Exceptions_s, (STRING *) 1));
/*101*/ 				Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"Uncought exception(s) ", Exceptions_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)" at global scope in ", Scanner_reference(Scanner_here()), m2runtime_CHR(46), (STRING *) 1));
/*106*/ 			}
/*106*/ 		} else {
/*106*/ 			Exceptions_AddExceptions(Exceptions_checked);
/*110*/ 		}
/*111*/ 	}
/*113*/ }


/*115*/ void
/*115*/ Exceptions_ParseThrows(void)
/*115*/ {
/*117*/ 	RECORD * Exceptions_exception = NULL;
/*117*/ 	Scanner_ReadSym();
/*118*/ 	Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected exception name");
/*120*/ 	do{
/*120*/ 		Exceptions_exception = Search_SearchClass(Scanner_s);
/*121*/ 		if( Exceptions_exception == NULL ){
/*122*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"unknown class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*123*/ 		} else if( !Classes_IsExceptionClass(Exceptions_exception) ){
/*124*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' is not an exception", (STRING *) 1));
/*126*/ 		} else {
/*126*/ 			Exceptions_AddException(Exceptions_exception);
/*128*/ 		}
/*128*/ 		Scanner_ReadSym();
/*129*/ 		if( (Scanner_sym == 134) ){
/*130*/ 			Scanner_ReadSym();
/*133*/ 		} else {
/*134*/ 			goto m2runtime_loop_1;
/*135*/ 		}
/*136*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*138*/ }


/*141*/ int
/*141*/ Exceptions_RemoveExceptionFromSet(RECORD *Exceptions_caught_exception, ARRAY **Exceptions_thrown_exceptions)
/*141*/ {
/*142*/ 	int Exceptions_i = 0;
/*143*/ 	int Exceptions_found = 0;
/*145*/ 	ARRAY * Exceptions_shorter = NULL;
/*145*/ 	{
/*145*/ 		int m2runtime_for_limit_1;
/*145*/ 		Exceptions_i = 0;
/*145*/ 		m2runtime_for_limit_1 = (m2runtime_count(*Exceptions_thrown_exceptions) - 1);
/*146*/ 		for( ; Exceptions_i <= m2runtime_for_limit_1; Exceptions_i += 1 ){
/*146*/ 			if( (((RECORD *)m2runtime_dereference_rhs_ARRAY(*Exceptions_thrown_exceptions, Exceptions_i, Exceptions_0err_entry_get, 7) != NULL) && Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_ARRAY(*Exceptions_thrown_exceptions, Exceptions_i, Exceptions_0err_entry_get, 8), Exceptions_caught_exception)) ){
/*148*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY(Exceptions_thrown_exceptions, sizeof(void *), 1, Exceptions_i, Exceptions_0err_entry_get, 9) = NULL;
/*149*/ 				Exceptions_found = TRUE;
/*152*/ 			}
/*153*/ 		}
/*153*/ 	}
/*153*/ 	if( Exceptions_found ){
/*154*/ 		{
/*154*/ 			int m2runtime_for_limit_1;
/*154*/ 			Exceptions_i = 0;
/*154*/ 			m2runtime_for_limit_1 = (m2runtime_count(*Exceptions_thrown_exceptions) - 1);
/*155*/ 			for( ; Exceptions_i <= m2runtime_for_limit_1; Exceptions_i += 1 ){
/*155*/ 				if( (RECORD *)m2runtime_dereference_rhs_ARRAY(*Exceptions_thrown_exceptions, Exceptions_i, Exceptions_0err_entry_get, 10) != NULL ){
/*156*/ 					*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Exceptions_shorter, sizeof(void *), 1, Exceptions_0err_entry_get, 11) = (RECORD *)m2runtime_dereference_rhs_ARRAY(*Exceptions_thrown_exceptions, Exceptions_i, Exceptions_0err_entry_get, 12);
/*159*/ 				}
/*159*/ 			}
/*159*/ 		}
/*159*/ 		*Exceptions_thrown_exceptions = Exceptions_shorter;
/*162*/ 	}
/*162*/ 	return Exceptions_found;
/*167*/ }


char * Exceptions_0func[] = {
    "AddExceptionToSet",
    "AddException",
    "AddExceptions",
    "ThrowExceptions",
    "RemoveExceptionFromSet"
};

int Exceptions_0err_entry[] = {
    0 /* AddExceptionToSet */, 14,
    0 /* AddExceptionToSet */, 18,
    1 /* AddException */, 27,
    1 /* AddException */, 29,
    2 /* AddExceptions */, 40,
    3 /* ThrowExceptions */, 67,
    3 /* ThrowExceptions */, 82,
    4 /* RemoveExceptionFromSet */, 146,
    4 /* RemoveExceptionFromSet */, 147,
    4 /* RemoveExceptionFromSet */, 148,
    4 /* RemoveExceptionFromSet */, 155,
    4 /* RemoveExceptionFromSet */, 156,
    4 /* RemoveExceptionFromSet */, 157
};

void Exceptions_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Exceptions";
    *f = Exceptions_0func[ Exceptions_0err_entry[2*i] ];
    *l = Exceptions_0err_entry[2*i + 1];
}
