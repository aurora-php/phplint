/* IMPLEMENTATION MODULE Accounting */
#define M2_IMPORT_Accounting

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif
/*  8*/ int Accounting_report_unused = 0;

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
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

#ifndef M2_IMPORT_MagicConstants
#    include "MagicConstants.c"
#endif

void Accounting_0err_entry_get(int i, char **m, char **f, int *l);

/* 12*/ void
/* 12*/ Accounting_AccountModule(RECORD *Accounting_decl_in)
/* 12*/ {
/* 13*/ 	STRING * Accounting_m = NULL;
/* 14*/ 	int Accounting_i = 0;
/* 16*/ 	RECORD * Accounting_pkg = NULL;
/* 16*/ 	if( Accounting_decl_in == NULL ){
/* 19*/ 		return ;
/* 20*/ 	}
/* 20*/ 	Accounting_m = (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_decl_in, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 0);
/* 21*/ 	if( m2runtime_strcmp(Accounting_m, Scanner_fn) == 0 ){
/* 23*/ 		return ;
/* 24*/ 	}
/* 24*/ 	{
/* 24*/ 		int m2runtime_for_limit_1;
/* 24*/ 		Accounting_i = 0;
/* 24*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_required_packages) - 1);
/* 25*/ 		for( ; Accounting_i <= m2runtime_for_limit_1; Accounting_i += 1 ){
/* 25*/ 			Accounting_pkg = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_required_packages, Accounting_i, Accounting_0err_entry_get, 1);
/* 26*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_pkg, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 2), Accounting_m) == 0 ){
/* 27*/ 				m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_pkg, 6 * sizeof(void*) + 5 * sizeof(int), 6, 6 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 3), 1);
/* 29*/ 				return ;
/* 31*/ 			}
/* 32*/ 		}
/* 32*/ 	}
/* 34*/ }


/* 35*/ RECORD *
/* 35*/ Accounting_AddConst(STRING *Accounting_abs_name, int Accounting_private, RECORD *Accounting_value)
/* 35*/ {
/* 37*/ 	RECORD * Accounting_c = NULL;
/* 37*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 4) = Accounting_abs_name;
/* 38*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 5) = Search_NormalizeConstName(Accounting_abs_name);
/* 39*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 6) = Accounting_private;
/* 40*/ 	if( Accounting_report_unused ){
/* 41*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 7) = 0;
/* 43*/ 	} else {
/* 43*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 8) = 100;
/* 45*/ 	}
/* 45*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 4 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 9) = Accounting_value;
/* 46*/ 	*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_consts, sizeof(void *), 1, Accounting_0err_entry_get, 10) = Accounting_c;
/* 47*/ 	return Accounting_c;
/* 51*/ }


/* 52*/ RECORD *
/* 52*/ Accounting_AccountConstLHS(STRING *Accounting_abs_name, int Accounting_private, RECORD *Accounting_value)
/* 52*/ {
/* 54*/ 	RECORD * Accounting_c = NULL;
/* 54*/ 	Accounting_c = Search_SearchConstByAbsName(Accounting_abs_name, FALSE);
/* 55*/ 	if( Accounting_c == NULL ){
/* 56*/ 		Accounting_c = Accounting_AddConst(Accounting_abs_name, Accounting_private, Accounting_value);
/* 57*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 11) = Scanner_here();
/* 58*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 12) = Scanner_here();
/* 59*/ 		if( (Globals_scope > 0) ){
/* 60*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"constant defined inside a function:", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)" still constants have global scope;", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)" this constant will exists only if the function is executed;", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)" if the function is called once more, PHP will raise", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" a notice and the re-definition itself will be ignored", (STRING *) 1));
/* 67*/ 		}
/* 67*/ 	} else {
/* 67*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_c, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 13) != NULL ){
/* 68*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"constant `", Accounting_abs_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_c, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 14)), (STRING *) 1));
/* 71*/ 		} else {
/* 71*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"constant `", Accounting_abs_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"' declared after use in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_c, 3 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 15)), (STRING *) 1));
/* 75*/ 		}
/* 75*/ 	}
/* 75*/ 	return Accounting_c;
/* 79*/ }


/* 80*/ RECORD *
/* 80*/ Accounting_AccountConstRHS(STRING *Accounting_name)
/* 80*/ {
/* 82*/ 	RECORD * Accounting_c = NULL;
/* 82*/ 	Accounting_c = Search_SearchConst(Accounting_name, TRUE);
/* 83*/ 	if( Accounting_c == NULL ){
/* 84*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"undeclared constant `", Accounting_name, m2runtime_CHR(39), (STRING *) 1));
/* 87*/ 		Accounting_c = Accounting_AddConst(Accounting_name, FALSE, NULL);
/* 88*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 16) = 1;
/* 89*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 17) = Scanner_here();
/* 90*/ 		return NULL;
/* 92*/ 	} else {
/* 92*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_c, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 18) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_c, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 19) != NULL) && (m2runtime_strcmp(Scanner_fn, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_c, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 20), 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 21)) != 0)) ){
/* 93*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"access forbidden to private constant `", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"' declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_c, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 22)), (STRING *) 1));
/* 96*/ 		}
/* 96*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_c, 6 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 23), EMPTY_STRING) > 0 ){
/* 97*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"using deprecated constant `", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_c, 6 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 24), (STRING *) 1));
/*100*/ 		}
/*100*/ 		m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 25), 1);
/*101*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 26) = Scanner_here();
/*102*/ 		Accounting_AccountModule((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_c, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 27));
/*103*/ 		return MagicConstants_Resolve(Accounting_c);
/*106*/ 	}
/*106*/ 	m2runtime_missing_return(Accounting_0err_entry_get, 28);
/*106*/ 	return NULL;
/*108*/ }


/*114*/ void
/*114*/ Accounting_AccountGlobalVar(STRING *Accounting_name)
/*114*/ {
/*116*/ 	RECORD * Accounting_g = NULL;
/*116*/ 	RECORD * Accounting_v = NULL;
/*116*/ 	Accounting_v = Search_SearchVar(Accounting_name);
/*117*/ 	if( Accounting_v == NULL ){
/*119*/ 		Accounting_g = Search_SearchVarInScope(Accounting_name, 0);
/*120*/ 		if( Accounting_g == NULL ){
/*121*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"global `$", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"': variable still not found in global scope.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\71,\0,\0,\0)" Hint: declare this variable in global scope assigning it", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)" a value.", (STRING *) 1));
/*125*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 29) = NULL;
/*126*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 30) = FALSE;
/*128*/ 		} else {
/*128*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_g, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 31) && (m2runtime_strcmp(Scanner_fn, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_g, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 32), 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 33)) != 0)) ){
/*129*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"access forbidden to private variable `$", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"' declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_g, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 34)), (STRING *) 1));
/*132*/ 			}
/*132*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 35) = (RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_g, 3 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 36);
/*133*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 37) =  *(int *)m2runtime_dereference_rhs_RECORD(Accounting_g, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 38);
/*135*/ 		}
/*135*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 39) = Accounting_name;
/*136*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 40) = Scanner_here();
/*137*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 41) = Globals_scope;
/*138*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 42) = TRUE;
/*139*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 43) = NULL;
/*140*/ 		if( Accounting_report_unused ){
/*141*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Accounting_0err_entry_get, 44) = 0;
/*143*/ 		} else {
/*143*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Accounting_0err_entry_get, 45) = 100;
/*145*/ 		}
/*145*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Accounting_0err_entry_get, 46) = TRUE;
/*146*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY(&Globals_vars, sizeof(void *), 1, Globals_vars_n, Accounting_0err_entry_get, 47) = Accounting_v;
/*147*/ 		m2_inc(&Globals_vars_n, 1);
/*148*/ 	} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_v, 7 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 48) == -1) ){
/*149*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"global $", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)": this variable is a superglobal", (STRING *) 1));
/*151*/ 	} else {
/*151*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"global $", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)": declaration shadows local variable ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"or formal argument with the same name", (STRING *) 1));
/*155*/ 	}
/*157*/ }


/*158*/ void
/*158*/ Accounting_AccountVarLHS2(RECORD *Accounting_v)
/*158*/ {
/*160*/ 	RECORD * Accounting_g = NULL;
/*160*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_v, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 49) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_v, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 50) != NULL) && (m2runtime_strcmp(Scanner_fn, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_v, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 51), 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 52)) != 0)) ){
/*161*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"access forbidden to private variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 53), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"' declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_v, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 54)), (STRING *) 1));
/*165*/ 	}
/*165*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 55) = Scanner_here();
/*167*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Accounting_0err_entry_get, 56) = TRUE;
/*169*/ 	Accounting_AccountModule((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_v, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 57));
/*171*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Accounting_v, 7 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 58) ){
/*172*/ 		Accounting_g = Search_SearchVarInScope((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 59), 0);
/*173*/ 		if( Accounting_g != NULL ){
/*174*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_g, 7 * sizeof(void*) + 7 * sizeof(int), 7, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 60) = Scanner_here();
/*175*/ 			Accounting_AccountModule((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_g, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 61));
/*178*/ 		}
/*179*/ 	}
/*179*/ 	if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 6 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 62), EMPTY_STRING) > 0 ){
/*180*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"using deprecated variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 63), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 6 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 64), (STRING *) 1));
/*187*/ 	}
/*187*/ 	if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 65), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"this") != 0 ){
/*189*/ 		return ;
/*190*/ 	}
/*190*/ 	if( Globals_curr_method == NULL ){
/*191*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)"using of the variable name `$this' outside of any class method");
/*192*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 9 * sizeof(void*) + 5 * sizeof(int), Accounting_0err_entry_get, 66) ){
/*193*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"using variable `$this' inside static method `", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 67), m2runtime_CHR(39), (STRING *) 1));
/*196*/ 	} else {
/*196*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"assignment forbidden to `$this'");
/*200*/ 	}
/*202*/ }


/*207*/ void
/*207*/ Accounting_AccountVarLHS(STRING *Accounting_name, int Accounting_private)
/*207*/ {
/*209*/ 	RECORD * Accounting_v = NULL;
/*209*/ 	Accounting_v = Search_SearchVar(Accounting_name);
/*210*/ 	if( Accounting_v == NULL ){
/*211*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 68) = Accounting_name;
/*212*/ 		if( (Accounting_private && ((Globals_scope > 0))) ){
/*213*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"useless `private' qualifier for local variable");
/*214*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 69) = FALSE;
/*216*/ 		} else {
/*216*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 70) = Accounting_private;
/*218*/ 		}
/*218*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 71) = Scanner_here();
/*219*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 72) = Globals_scope;
/*220*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 73) = FALSE;
/*221*/ 		if( Accounting_report_unused ){
/*222*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Accounting_0err_entry_get, 74) = 0;
/*224*/ 		} else {
/*224*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Accounting_0err_entry_get, 75) = 100;
/*226*/ 		}
/*226*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY(&Globals_vars, sizeof(void *), 1, Globals_vars_n, Accounting_0err_entry_get, 76) = Accounting_v;
/*227*/ 		m2_inc(&Globals_vars_n, 1);
/*228*/ 	} else if( Accounting_private ){
/*229*/ 		if( (Globals_scope == 0) ){
/*230*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"invalid `private' qualifier: variable already set as public in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_v, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 77)), (STRING *) 1));
/*232*/ 		} else {
/*232*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"useless `private' qualifier for local variable");
/*235*/ 		}
/*235*/ 	}
/*235*/ 	Accounting_AccountVarLHS2(Accounting_v);
/*239*/ }


/*243*/ void
/*243*/ Accounting_AccountVarRHS2(RECORD *Accounting_v)
/*243*/ {
/*245*/ 	RECORD * Accounting_g = NULL;
/*245*/ 	if( ! *(int *)m2runtime_dereference_rhs_RECORD(Accounting_v, 7 * sizeof(void*) + 5 * sizeof(int), Accounting_0err_entry_get, 78) ){
/*246*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"variable $", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 79), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)" might not have been assigned", (STRING *) 1));
/*247*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Accounting_0err_entry_get, 80) = TRUE;
/*249*/ 	}
/*249*/ 	m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Accounting_0err_entry_get, 81), 1);
/*250*/ 	Accounting_AccountModule((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_v, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 82));
/*251*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Accounting_v, 7 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 83) ){
/*252*/ 		Accounting_g = Search_SearchVarInScope((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 84), 0);
/*253*/ 		if( Accounting_g != NULL ){
/*254*/ 			m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_g, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Accounting_0err_entry_get, 85), 1);
/*255*/ 			Accounting_AccountModule((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_g, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 86));
/*258*/ 		}
/*259*/ 	}
/*259*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_v, 7 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 87) && (m2runtime_strcmp(Scanner_fn, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_v, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 88), 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 89)) != 0)) ){
/*260*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"access forbidden to private variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 90), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"' declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_v, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 91)), (STRING *) 1));
/*264*/ 	}
/*264*/ 	if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 6 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 92), EMPTY_STRING) > 0 ){
/*265*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"using deprecated variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 93), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 6 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 94), (STRING *) 1));
/*272*/ 	}
/*272*/ 	if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_v, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 95), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"this") != 0 ){
/*274*/ 		return ;
/*275*/ 	}
/*275*/ 	if( Globals_curr_method == NULL ){
/*276*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)"using variable `$this' outside of any class method");
/*277*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 9 * sizeof(void*) + 5 * sizeof(int), Accounting_0err_entry_get, 96) ){
/*278*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"using variable `$this' inside static method `", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 97), m2runtime_CHR(39), (STRING *) 1));
/*282*/ 	}
/*284*/ }


/*291*/ void
/*291*/ Accounting_AccountVarRHS(STRING *Accounting_name)
/*291*/ {
/*293*/ 	RECORD * Accounting_v = NULL;
/*293*/ 	Accounting_v = Search_SearchVar(Accounting_name);
/*294*/ 	if( Accounting_v == NULL ){
/*295*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"variable `$", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"' has not been assigned", (STRING *) 1));
/*296*/ 		Accounting_AccountVarLHS(Accounting_name, FALSE);
/*297*/ 		Accounting_v = Search_SearchVar(Accounting_name);
/*299*/ 	}
/*299*/ 	Accounting_AccountVarRHS2(Accounting_v);
/*303*/ }


/*304*/ RECORD *
/*304*/ Accounting_AccountFuncCall(STRING *Accounting_name)
/*304*/ {
/*306*/ 	RECORD * Accounting_f = NULL;
/*306*/ 	Accounting_f = Search_SearchFunc(Accounting_name, TRUE);
/*307*/ 	if( Accounting_f == NULL ){
/*308*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Accounting_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 98) = Accounting_name;
/*309*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Accounting_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 1 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 99) = str_tolower(Accounting_name);
/*310*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 100) = NULL;
/*311*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 101) = 1;
/*312*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 4 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 102) = Scanner_here();
/*313*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Accounting_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 5 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 103) = NULL;
/*314*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_funcs, sizeof(void *), 1, Accounting_0err_entry_get, 104) = Accounting_f;
/*316*/ 	} else {
/*316*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_f, 10 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 105) && (m2runtime_strcmp(Scanner_fn, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_f, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 106), 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 107)) != 0)) ){
/*317*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"access forbidden to private function `", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"' declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_f, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 108)), (STRING *) 1));
/*320*/ 		}
/*320*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_f, 9 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 109), EMPTY_STRING) > 0 ){
/*321*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"using deprecated function `", Accounting_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_f, 9 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 110), (STRING *) 1));
/*324*/ 		}
/*324*/ 		m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 111), 1);
/*325*/ 		Accounting_AccountModule((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_f, 2 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 112));
/*327*/ 	}
/*327*/ 	return Accounting_f;
/*331*/ }


/*333*/ void
/*333*/ Accounting_AccountClass(RECORD *Accounting_class)
/*333*/ {
/*333*/ 	if( Accounting_class != Globals_curr_class ){
/*334*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_class, 15 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 113) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_class, 12 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 114), 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 115), Scanner_fn) != 0)) ){
/*335*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"access forbidden to private class `", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 116), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"' declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_class, 12 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 117)), (STRING *) 1));
/*338*/ 		}
/*338*/ 		m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 10 * sizeof(int), Accounting_0err_entry_get, 118), 1);
/*339*/ 		Accounting_AccountModule((RECORD *)m2runtime_dereference_rhs_RECORD(Accounting_class, 12 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 119));
/*342*/ 	}
/*344*/ }


/*346*/ void
/*346*/ Accounting_AccountClassConst(RECORD *Accounting_class, RECORD *Accounting_c)
/*346*/ {
/*346*/ 	if( Globals_curr_class == Accounting_class ){
/*347*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_c, 5 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 120) == 0) ){
/*348*/ 			m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 121), 1);
/*350*/ 		} else {
/*350*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 122) = TRUE;
/*353*/ 		}
/*353*/ 	} else {
/*353*/ 		Accounting_AccountClass(Accounting_class);
/*354*/ 		m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 123), 1);
/*355*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_c, 4 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 124), EMPTY_STRING) > 0 ){
/*356*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"using deprecated class constant `", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 125), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_c, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 126), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_c, 4 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 127), (STRING *) 1));
/*358*/ 		} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 14 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 128), EMPTY_STRING) > 0 ){
/*359*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"using class constant `", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 129), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_c, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 130), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"' from deprecated class: ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 14 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 131), (STRING *) 1));
/*363*/ 		}
/*364*/ 	}
/*366*/ }


/*368*/ void
/*368*/ Accounting_AccountClassProperty(RECORD *Accounting_class, RECORD *Accounting_p)
/*368*/ {
/*368*/ 	if( Globals_curr_class == Accounting_class ){
/*369*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_p, 6 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 132) == 0) ){
/*370*/ 			m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 6 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 133), 1);
/*372*/ 		} else {
/*372*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 6 * sizeof(void*) + 5 * sizeof(int), Accounting_0err_entry_get, 134) = TRUE;
/*375*/ 		}
/*375*/ 	} else {
/*375*/ 		Accounting_AccountClass(Accounting_class);
/*376*/ 		m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 6 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 135), 1);
/*377*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_p, 5 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 136), EMPTY_STRING) > 0 ){
/*378*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"using deprecated property `", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 137), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_p, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 138), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_p, 5 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 139), (STRING *) 1));
/*380*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_p, 6 * sizeof(void*) + 3 * sizeof(int), Accounting_0err_entry_get, 140) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 14 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 141), EMPTY_STRING) > 0)) ){
/*381*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"using static property `", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 142), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_p, 0 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 143), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"' from deprecated class: ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 14 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 144), (STRING *) 1));
/*385*/ 		}
/*386*/ 	}
/*388*/ }


/*390*/ void
/*390*/ Accounting_AccountClassMethod(RECORD *Accounting_class, RECORD *Accounting_m)
/*390*/ {
/*390*/ 	if( Globals_curr_class == Accounting_class ){
/*391*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_m, 9 * sizeof(void*) + 4 * sizeof(int), Accounting_0err_entry_get, 145) == 0) ){
/*392*/ 			m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 7 * sizeof(int), Accounting_0err_entry_get, 146), 1);
/*394*/ 		} else {
/*394*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Accounting_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 8 * sizeof(int), Accounting_0err_entry_get, 147) = TRUE;
/*397*/ 		}
/*397*/ 	} else {
/*397*/ 		Accounting_AccountClass(Accounting_class);
/*398*/ 		m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Accounting_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 7 * sizeof(int), Accounting_0err_entry_get, 148), 1);
/*399*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_m, 8 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 149), EMPTY_STRING) > 0 ){
/*400*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"using deprecated method ", Scanner_mn(Accounting_class, Accounting_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_m, 8 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 150), (STRING *) 1));
/*402*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Accounting_m, 9 * sizeof(void*) + 5 * sizeof(int), Accounting_0err_entry_get, 151) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 14 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 152), EMPTY_STRING) > 0)) ){
/*403*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"using static method ", Scanner_mn(Accounting_class, Accounting_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)" from deprecated class: ", (STRING *)m2runtime_dereference_rhs_RECORD(Accounting_class, 14 * sizeof(void*) + 2 * sizeof(int), Accounting_0err_entry_get, 153), (STRING *) 1));
/*407*/ 		}
/*408*/ 	}
/*411*/ }


char * Accounting_0func[] = {
    "AccountModule",
    "AddConst",
    "AccountConstLHS",
    "AccountConstRHS",
    "AccountGlobalVar",
    "AccountVarLHS2",
    "AccountVarLHS",
    "AccountVarRHS2",
    "AccountFuncCall",
    "AccountClass",
    "AccountClassConst",
    "AccountClassProperty",
    "AccountClassMethod"
};

int Accounting_0err_entry[] = {
    0 /* AccountModule */, 20,
    0 /* AccountModule */, 26,
    0 /* AccountModule */, 26,
    0 /* AccountModule */, 27,
    1 /* AddConst */, 37,
    1 /* AddConst */, 38,
    1 /* AddConst */, 39,
    1 /* AddConst */, 41,
    1 /* AddConst */, 43,
    1 /* AddConst */, 45,
    1 /* AddConst */, 46,
    2 /* AccountConstLHS */, 57,
    2 /* AccountConstLHS */, 58,
    2 /* AccountConstLHS */, 67,
    2 /* AccountConstLHS */, 69,
    2 /* AccountConstLHS */, 72,
    3 /* AccountConstRHS */, 88,
    3 /* AccountConstRHS */, 89,
    3 /* AccountConstRHS */, 92,
    3 /* AccountConstRHS */, 92,
    3 /* AccountConstRHS */, 92,
    3 /* AccountConstRHS */, 92,
    3 /* AccountConstRHS */, 94,
    3 /* AccountConstRHS */, 96,
    3 /* AccountConstRHS */, 98,
    3 /* AccountConstRHS */, 100,
    3 /* AccountConstRHS */, 101,
    3 /* AccountConstRHS */, 102,
    3 /* AccountConstRHS */, 105,
    4 /* AccountGlobalVar */, 125,
    4 /* AccountGlobalVar */, 126,
    4 /* AccountGlobalVar */, 128,
    4 /* AccountGlobalVar */, 128,
    4 /* AccountGlobalVar */, 128,
    4 /* AccountGlobalVar */, 130,
    4 /* AccountGlobalVar */, 132,
    4 /* AccountGlobalVar */, 132,
    4 /* AccountGlobalVar */, 133,
    4 /* AccountGlobalVar */, 133,
    4 /* AccountGlobalVar */, 135,
    4 /* AccountGlobalVar */, 136,
    4 /* AccountGlobalVar */, 137,
    4 /* AccountGlobalVar */, 138,
    4 /* AccountGlobalVar */, 139,
    4 /* AccountGlobalVar */, 141,
    4 /* AccountGlobalVar */, 143,
    4 /* AccountGlobalVar */, 145,
    4 /* AccountGlobalVar */, 146,
    4 /* AccountGlobalVar */, 148,
    5 /* AccountVarLHS2 */, 160,
    5 /* AccountVarLHS2 */, 160,
    5 /* AccountVarLHS2 */, 160,
    5 /* AccountVarLHS2 */, 160,
    5 /* AccountVarLHS2 */, 161,
    5 /* AccountVarLHS2 */, 162,
    5 /* AccountVarLHS2 */, 165,
    5 /* AccountVarLHS2 */, 167,
    5 /* AccountVarLHS2 */, 169,
    5 /* AccountVarLHS2 */, 171,
    5 /* AccountVarLHS2 */, 172,
    5 /* AccountVarLHS2 */, 174,
    5 /* AccountVarLHS2 */, 175,
    5 /* AccountVarLHS2 */, 179,
    5 /* AccountVarLHS2 */, 180,
    5 /* AccountVarLHS2 */, 181,
    5 /* AccountVarLHS2 */, 187,
    5 /* AccountVarLHS2 */, 192,
    5 /* AccountVarLHS2 */, 194,
    6 /* AccountVarLHS */, 211,
    6 /* AccountVarLHS */, 214,
    6 /* AccountVarLHS */, 216,
    6 /* AccountVarLHS */, 218,
    6 /* AccountVarLHS */, 219,
    6 /* AccountVarLHS */, 220,
    6 /* AccountVarLHS */, 222,
    6 /* AccountVarLHS */, 224,
    6 /* AccountVarLHS */, 226,
    6 /* AccountVarLHS */, 230,
    7 /* AccountVarRHS2 */, 245,
    7 /* AccountVarRHS2 */, 246,
    7 /* AccountVarRHS2 */, 247,
    7 /* AccountVarRHS2 */, 249,
    7 /* AccountVarRHS2 */, 250,
    7 /* AccountVarRHS2 */, 251,
    7 /* AccountVarRHS2 */, 252,
    7 /* AccountVarRHS2 */, 254,
    7 /* AccountVarRHS2 */, 255,
    7 /* AccountVarRHS2 */, 259,
    7 /* AccountVarRHS2 */, 259,
    7 /* AccountVarRHS2 */, 259,
    7 /* AccountVarRHS2 */, 260,
    7 /* AccountVarRHS2 */, 261,
    7 /* AccountVarRHS2 */, 264,
    7 /* AccountVarRHS2 */, 265,
    7 /* AccountVarRHS2 */, 266,
    7 /* AccountVarRHS2 */, 272,
    7 /* AccountVarRHS2 */, 277,
    7 /* AccountVarRHS2 */, 279,
    8 /* AccountFuncCall */, 308,
    8 /* AccountFuncCall */, 309,
    8 /* AccountFuncCall */, 310,
    8 /* AccountFuncCall */, 311,
    8 /* AccountFuncCall */, 312,
    8 /* AccountFuncCall */, 313,
    8 /* AccountFuncCall */, 314,
    8 /* AccountFuncCall */, 316,
    8 /* AccountFuncCall */, 316,
    8 /* AccountFuncCall */, 316,
    8 /* AccountFuncCall */, 318,
    8 /* AccountFuncCall */, 320,
    8 /* AccountFuncCall */, 322,
    8 /* AccountFuncCall */, 324,
    8 /* AccountFuncCall */, 325,
    9 /* AccountClass */, 334,
    9 /* AccountClass */, 334,
    9 /* AccountClass */, 334,
    9 /* AccountClass */, 335,
    9 /* AccountClass */, 336,
    9 /* AccountClass */, 338,
    9 /* AccountClass */, 339,
    10 /* AccountClassConst */, 347,
    10 /* AccountClassConst */, 348,
    10 /* AccountClassConst */, 350,
    10 /* AccountClassConst */, 354,
    10 /* AccountClassConst */, 355,
    10 /* AccountClassConst */, 356,
    10 /* AccountClassConst */, 357,
    10 /* AccountClassConst */, 357,
    10 /* AccountClassConst */, 358,
    10 /* AccountClassConst */, 359,
    10 /* AccountClassConst */, 360,
    10 /* AccountClassConst */, 360,
    11 /* AccountClassProperty */, 369,
    11 /* AccountClassProperty */, 370,
    11 /* AccountClassProperty */, 372,
    11 /* AccountClassProperty */, 376,
    11 /* AccountClassProperty */, 377,
    11 /* AccountClassProperty */, 378,
    11 /* AccountClassProperty */, 379,
    11 /* AccountClassProperty */, 379,
    11 /* AccountClassProperty */, 380,
    11 /* AccountClassProperty */, 380,
    11 /* AccountClassProperty */, 381,
    11 /* AccountClassProperty */, 382,
    11 /* AccountClassProperty */, 382,
    12 /* AccountClassMethod */, 391,
    12 /* AccountClassMethod */, 392,
    12 /* AccountClassMethod */, 394,
    12 /* AccountClassMethod */, 398,
    12 /* AccountClassMethod */, 399,
    12 /* AccountClassMethod */, 401,
    12 /* AccountClassMethod */, 402,
    12 /* AccountClassMethod */, 402,
    12 /* AccountClassMethod */, 404
};

void Accounting_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Accounting";
    *f = Accounting_0func[ Accounting_0err_entry[2*i] ];
    *l = Accounting_0err_entry[2*i + 1];
}
