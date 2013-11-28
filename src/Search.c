/* IMPLEMENTATION MODULE Search */
#define M2_IMPORT_Search

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

#ifndef M2_IMPORT_Namespace
#    include "Namespace.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

void Search_0err_entry_get(int i, char **m, char **f, int *l);

/*  8*/ STRING *
/*  8*/ Search_NormalizeConstName(STRING *Search_name)
/*  8*/ {

/*  9*/ 	int
/*  9*/ 	Search_index_last(STRING *Search_q)
/*  9*/ 	{
/* 11*/ 		int Search_i = 0;
/* 11*/ 		{
/* 11*/ 			int m2runtime_for_limit_1;
/* 11*/ 			Search_i = (m2runtime_length(Search_q) - 1);
/* 11*/ 			m2runtime_for_limit_1 = 0;
/* 12*/ 			for( ; Search_i >= m2runtime_for_limit_1; Search_i -= 1 ){
/* 12*/ 				if( m2runtime_strcmp(m2runtime_substr(Search_q, Search_i, 0, 0, Search_0err_entry_get, 0), m2runtime_CHR(92)) == 0 ){
/* 13*/ 					return Search_i;
/* 16*/ 				}
/* 16*/ 			}
/* 16*/ 		}
/* 16*/ 		return -1;
/* 20*/ 	}

/* 22*/ 	int Search_i = 0;
/* 22*/ 	if( Namespace_isFullyQualified(Search_name) ){
/* 23*/ 		Search_name = m2runtime_substr(Search_name, 1, m2runtime_length(Search_name), 1, Search_0err_entry_get, 1);
/* 26*/ 	}
/* 26*/ 	if( Namespace_isIdentifier(Search_name) ){
/* 27*/ 		return Search_name;
/* 29*/ 	} else {
/* 29*/ 		Search_i = Search_index_last(Search_name);
/* 30*/ 		return m2runtime_concat_STRING(0, str_tolower(m2runtime_substr(Search_name, 0, Search_i, 1, Search_0err_entry_get, 2)), m2runtime_substr(Search_name, Search_i, m2runtime_length(Search_name), 1, Search_0err_entry_get, 3), (STRING *) 1);
/* 33*/ 	}
/* 33*/ 	m2runtime_missing_return(Search_0err_entry_get, 4);
/* 33*/ 	return NULL;
/* 35*/ }


/* 37*/ RECORD *
/* 37*/ Search_SearchConstByAbsName(STRING *Search_name, int Search_warn)
/* 37*/ {
/* 38*/ 	STRING * Search_name_normalized = NULL;
/* 39*/ 	int Search_i = 0;
/* 41*/ 	RECORD * Search_c = NULL;
/* 41*/ 	Search_name_normalized = Search_NormalizeConstName(Search_name);
/* 42*/ 	{
/* 42*/ 		int m2runtime_for_limit_1;
/* 42*/ 		Search_i = 0;
/* 42*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_consts) - 1);
/* 43*/ 		for( ; Search_i <= m2runtime_for_limit_1; Search_i += 1 ){
/* 43*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_consts, Search_i, Search_0err_entry_get, 5), 1 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 6), Search_name_normalized) == 0 ){
/* 44*/ 				Search_c = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_consts, Search_i, Search_0err_entry_get, 7);
/* 45*/ 				if( (Search_warn && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Search_c, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 8), Search_name) != 0)) ){
/* 46*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"constant `", Search_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"' was declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Search_c, 2 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 9)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" as `", (STRING *)m2runtime_dereference_rhs_RECORD(Search_c, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 10), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' that differ by upper/lower-case letters only", (STRING *) 1));
/* 50*/ 				}
/* 50*/ 				return Search_c;
/* 53*/ 			}
/* 53*/ 		}
/* 53*/ 	}
/* 53*/ 	return NULL;
/* 57*/ }


/* 59*/ RECORD *
/* 59*/ Search_SearchConst(STRING *Search_name, int Search_warn)
/* 59*/ {
/* 60*/ 	STRING * Search_q = NULL;
/* 62*/ 	RECORD * Search_c = NULL;
/* 62*/ 	Search_q = Namespace_ApplyUse(Search_name, FALSE);
/* 63*/ 	Search_c = Search_SearchConstByAbsName(Search_q, Search_warn);
/* 64*/ 	if( ((Search_c == NULL) && Namespace_isIdentifier(Search_name)) ){
/* 65*/ 		Search_c = Search_SearchConstByAbsName(Search_name, Search_warn);
/* 67*/ 	}
/* 67*/ 	return Search_c;
/* 71*/ }


/* 73*/ RECORD *
/* 73*/ Search_SearchVarInScope(STRING *Search_name, int Search_scope)
/* 73*/ {
/* 75*/ 	int Search_i = 0;
/* 75*/ 	Search_i = (Globals_vars_n - 1);
/* 77*/ 	do{
/* 77*/ 		if( (((Search_i < 0)) || (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Search_i, Search_0err_entry_get, 11), 7 * sizeof(void*) + 3 * sizeof(int), Search_0err_entry_get, 12) < Search_scope))) ){
/* 78*/ 			return NULL;
/* 80*/ 		}
/* 80*/ 		if( ((( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Search_i, Search_0err_entry_get, 13), 7 * sizeof(void*) + 3 * sizeof(int), Search_0err_entry_get, 14) == Search_scope)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Search_i, Search_0err_entry_get, 15), 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 16), Search_name) == 0)) ){
/* 81*/ 			return (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Search_i, Search_0err_entry_get, 17);
/* 83*/ 		}
/* 83*/ 		Search_i = (Search_i - 1);
/* 86*/ 	}while(TRUE);
/* 86*/ 	m2runtime_missing_return(Search_0err_entry_get, 18);
/* 86*/ 	return NULL;
/* 88*/ }


/* 90*/ RECORD *
/* 90*/ Search_SearchVar(STRING *Search_name)
/* 90*/ {
/* 92*/ 	RECORD * Search_v = NULL;
/* 93*/ 	Search_v = Search_SearchVarInScope(Search_name, Globals_scope);
/* 94*/ 	if( Search_v != NULL ){
/* 95*/ 		return Search_v;
/* 99*/ 	}
/* 99*/ 	return Search_SearchVarInScope(Search_name, -1);
/*103*/ }


/*105*/ RECORD *
/*105*/ Search_SearchFuncLower(STRING *Search_name_lower)
/*105*/ {
/*107*/ 	int Search_i = 0;
/*107*/ 	{
/*107*/ 		int m2runtime_for_limit_1;
/*107*/ 		Search_i = 0;
/*107*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_funcs) - 1);
/*108*/ 		for( ; Search_i <= m2runtime_for_limit_1; Search_i += 1 ){
/*108*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_funcs, Search_i, Search_0err_entry_get, 19), 1 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 20), Search_name_lower) == 0 ){
/*109*/ 				return (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_funcs, Search_i, Search_0err_entry_get, 21);
/*112*/ 			}
/*112*/ 		}
/*112*/ 	}
/*112*/ 	return NULL;
/*116*/ }


/*118*/ RECORD *
/*118*/ Search_SearchFuncByAbsName(STRING *Search_name, int Search_warn)
/*118*/ {
/*120*/ 	RECORD * Search_f = NULL;
/*120*/ 	Search_f = Search_SearchFuncLower(str_tolower(Search_name));
/*121*/ 	if( ((Search_f != NULL) && Search_warn && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Search_f, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 22), Search_name) != 0)) ){
/*122*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Search_f, 2 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 23) == NULL ){
/*123*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", Search_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already spelled as `", (STRING *)m2runtime_dereference_rhs_RECORD(Search_f, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 24), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' that differ by upper/lower-case letters only", (STRING *) 1));
/*127*/ 		} else {
/*127*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", Search_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"' was declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Search_f, 2 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 25)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" as `", (STRING *)m2runtime_dereference_rhs_RECORD(Search_f, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 26), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' that differ by upper/lower-case letters only", (STRING *) 1));
/*132*/ 		}
/*132*/ 	}
/*132*/ 	return Search_f;
/*136*/ }


/*138*/ RECORD *
/*138*/ Search_SearchFunc(STRING *Search_name, int Search_warn)
/*138*/ {
/*139*/ 	STRING * Search_q = NULL;
/*141*/ 	RECORD * Search_f = NULL;
/*141*/ 	Search_q = Namespace_ApplyUse(Search_name, FALSE);
/*142*/ 	Search_f = Search_SearchFuncByAbsName(Search_q, Search_warn);
/*143*/ 	if( ((Search_f == NULL) && Namespace_isIdentifier(Search_name)) ){
/*144*/ 		Search_f = Search_SearchFuncByAbsName(Search_name, Search_warn);
/*146*/ 	}
/*146*/ 	return Search_f;
/*150*/ }


/*152*/ RECORD *
/*152*/ Search_SearchClassByAbsName(STRING *Search_name, int Search_warn)
/*152*/ {
/*153*/ 	STRING * Search_name_lower = NULL;
/*154*/ 	int Search_i = 0;
/*156*/ 	RECORD * Search_class = NULL;
/*156*/ 	Search_name_lower = str_tolower(Search_name);
/*157*/ 	{
/*157*/ 		int m2runtime_for_limit_1;
/*157*/ 		Search_i = (m2runtime_count(Globals_classes) - 1);
/*157*/ 		m2runtime_for_limit_1 = 0;
/*158*/ 		for( ; Search_i >= m2runtime_for_limit_1; Search_i -= 1 ){
/*158*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, Search_i, Search_0err_entry_get, 27), 1 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 28), Search_name_lower) == 0 ){
/*159*/ 				Search_class = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, Search_i, Search_0err_entry_get, 29);
/*160*/ 				if( (Search_warn && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Search_class, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 30), Search_name) != 0)) ){
/*161*/ 					if( (RECORD *)m2runtime_dereference_rhs_RECORD(Search_class, 12 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 31) == NULL ){
/*162*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Search_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already spelled as `", (STRING *)m2runtime_dereference_rhs_RECORD(Search_class, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 32), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' that differ by upper/lower-case letters only", (STRING *) 1));
/*166*/ 					} else {
/*166*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Search_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"' was declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Search_class, 12 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 33)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" as `", (STRING *)m2runtime_dereference_rhs_RECORD(Search_class, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 34), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' that differ by upper/lower-case letters only", (STRING *) 1));
/*171*/ 					}
/*171*/ 				}
/*171*/ 				return Search_class;
/*174*/ 			}
/*174*/ 		}
/*174*/ 	}
/*174*/ 	return NULL;
/*178*/ }


/*180*/ RECORD *
/*180*/ Search_SearchClass(STRING *Search_name)
/*180*/ {
/*181*/ 	RECORD * Search_c = NULL;
/*182*/ 	STRING * Search_fn = NULL;
/*183*/ 	STRING * Search_s = NULL;
/*184*/ 	ARRAY * Search_s_vars = NULL;
/*186*/ 	int Search_i = 0;
/*186*/ 	int Search_s_vars_n = 0;
/*186*/ 	Search_name = Namespace_ApplyUse(Search_name, TRUE);
/*187*/ 	Search_c = Search_SearchClassByAbsName(Search_name, TRUE);
/*188*/ 	if( Search_c != NULL ){
/*189*/ 		return Search_c;
/*193*/ 	}
/*193*/ 	if( Globals_autoload_prepend == NULL ){
/*194*/ 		return NULL;
/*205*/ 	}
/*205*/ 	Search_fn = m2runtime_concat_STRING(0, Globals_autoload_prepend, str_substitute(Search_name, m2runtime_CHR(92), Globals_autoload_separator), Globals_autoload_append, (STRING *) 1);
/*207*/ 	Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"autoloading package ", Search_fn, (STRING *) 1));
/*216*/ 	Search_s_vars = Globals_vars;
/*217*/ 	Search_s_vars_n = Globals_vars_n;
/*218*/ 	Globals_vars = NULL;
/*219*/ 	Globals_vars_n = 0;
/*220*/ 	{
/*220*/ 		int m2runtime_for_limit_1;
/*220*/ 		Search_i = 0;
/*220*/ 		m2runtime_for_limit_1 = (Search_s_vars_n - 1);
/*221*/ 		for( ; Search_i <= m2runtime_for_limit_1; Search_i += 1 ){
/*221*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Search_s_vars, Search_i, Search_0err_entry_get, 35), 7 * sizeof(void*) + 3 * sizeof(int), Search_0err_entry_get, 36) <= 0) ){
/*222*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_vars, sizeof(void *), 1, Search_0err_entry_get, 37) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Search_s_vars, Search_i, Search_0err_entry_get, 38);
/*225*/ 			}
/*225*/ 		}
/*225*/ 	}
/*225*/ 	Globals_vars_n = m2runtime_count(Globals_vars);
   void Statements_RequirePackage(STRING *, int);
	Statements_RequirePackage(Search_fn, 0);
/*235*/ 	Globals_vars = Search_s_vars;
/*236*/ 	Globals_vars_n = Search_s_vars_n;
/*238*/ 	Search_c = Search_SearchClassByAbsName(Search_name, TRUE);
/*239*/ 	if( Search_c != NULL ){
/*241*/ 		Search_s = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__autoload";
		RECORD * Accounting_AccountFuncCall(STRING *);
		/* ignore = */ Accounting_AccountFuncCall(Search_s);
/*245*/ 	}
/*245*/ 	return Search_c;
/*249*/ }


/*279*/ void
/*279*/ Search_SearchClassProperty(RECORD *Search_class, STRING *Search_id, RECORD **Search_P, RECORD **Search_p)
/*279*/ {
/*280*/ 	ARRAY * Search_properties = NULL;
/*282*/ 	int Search_i = 0;
/*282*/ 	Search_properties = (ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 7 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 39);
/*283*/ 	{
/*283*/ 		int m2runtime_for_limit_1;
/*283*/ 		Search_i = 0;
/*283*/ 		m2runtime_for_limit_1 = (m2runtime_count(Search_properties) - 1);
/*284*/ 		for( ; Search_i <= m2runtime_for_limit_1; Search_i += 1 ){
/*284*/ 			if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Search_properties, Search_i, Search_0err_entry_get, 40), 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 41), Search_id) == 0) && (((( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Search_properties, Search_i, Search_0err_entry_get, 42), 6 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 43) == 2)) || (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Search_properties, Search_i, Search_0err_entry_get, 44), 6 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 45) == 1)) || ((( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Search_properties, Search_i, Search_0err_entry_get, 46), 6 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 47) == 0)) && ((((Globals_php_ver == 4)) || (Globals_curr_class == Search_class))))))) ){
/*290*/ 				*Search_P = Search_class;
/*291*/ 				*Search_p = (RECORD *)m2runtime_dereference_rhs_ARRAY(Search_properties, Search_i, Search_0err_entry_get, 48);
/*293*/ 				return ;
/*295*/ 			}
/*297*/ 		}
/*297*/ 	}
/*297*/ 	{
/*297*/ 		int m2runtime_for_limit_1;
/*297*/ 		Search_i = 0;
/*297*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 4 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 49)) - 1);
/*298*/ 		for( ; Search_i <= m2runtime_for_limit_1; Search_i += 1 ){
/*298*/ 			Search_SearchClassProperty((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 4 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 50), Search_i, Search_0err_entry_get, 51), Search_id, Search_P, Search_p);
/*299*/ 			if( *Search_p != NULL ){
/*301*/ 				return ;
/*303*/ 			}
/*305*/ 		}
/*305*/ 	}
/*305*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Search_class, 3 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 52) != NULL ){
/*306*/ 		Search_SearchClassProperty((RECORD *)m2runtime_dereference_rhs_RECORD(Search_class, 3 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 53), Search_id, Search_P, Search_p);
/*307*/ 		if( *Search_p != NULL ){
/*309*/ 			return ;
/*311*/ 		}
/*313*/ 	}
/*313*/ 	*Search_P = NULL;
/*314*/ 	*Search_p = NULL;
/*316*/ 	return ;
/*319*/ }


/*321*/ RECORD *
/*321*/ Search_SearchClassMethod(RECORD *Search_class, STRING *Search_name, int Search_warn)
/*321*/ {
/*322*/ 	STRING * Search_name_lower = NULL;
/*323*/ 	ARRAY * Search_methods = NULL;
/*324*/ 	int Search_i = 0;
/*326*/ 	RECORD * Search_m = NULL;
/*326*/ 	if( Search_class == NULL ){
/*327*/ 		return NULL;
/*329*/ 	}
/*329*/ 	Search_name_lower = str_tolower(Search_name);
/*330*/ 	Search_methods = (ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 8 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 54);
/*331*/ 	{
/*331*/ 		int m2runtime_for_limit_1;
/*331*/ 		Search_i = 0;
/*331*/ 		m2runtime_for_limit_1 = (m2runtime_count(Search_methods) - 1);
/*332*/ 		for( ; Search_i <= m2runtime_for_limit_1; Search_i += 1 ){
/*332*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Search_methods, Search_i, Search_0err_entry_get, 55), 1 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 56), Search_name_lower) == 0 ){
/*333*/ 				Search_m = (RECORD *)m2runtime_dereference_rhs_ARRAY(Search_methods, Search_i, Search_0err_entry_get, 57);
/*334*/ 				if( (Search_warn && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Search_m, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 58), Search_name) != 0)) ){
/*335*/ 					if( (RECORD *)m2runtime_dereference_rhs_RECORD(Search_m, 3 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 59) == NULL ){
/*336*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"method `", Search_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already spelled as `", (STRING *)m2runtime_dereference_rhs_RECORD(Search_m, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 60), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' that differ by upper/lower-case letters only", (STRING *) 1));
/*340*/ 					} else {
/*340*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"method `", Search_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"' was declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Search_m, 3 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 61)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" as `", (STRING *)m2runtime_dereference_rhs_RECORD(Search_m, 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 62), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' that differ by upper/lower-case letters only", (STRING *) 1));
/*345*/ 					}
/*345*/ 				}
/*345*/ 				return Search_m;
/*348*/ 			}
/*348*/ 		}
/*348*/ 	}
/*348*/ 	return NULL;
/*352*/ }


/*354*/ void
/*354*/ Search_ResolveClassConst(RECORD *Search_class, STRING *Search_id, RECORD **Search_res_class, RECORD **Search_res_const)
/*354*/ {
/*356*/ 	int Search_i = 0;
/*356*/ 	*Search_res_class = NULL;
/*357*/ 	*Search_res_const = NULL;
/*359*/ 	if( Search_class == NULL ){
/*361*/ 		return ;
/*366*/ 	}
/*366*/ 	{
/*366*/ 		int m2runtime_for_limit_1;
/*366*/ 		Search_i = 0;
/*366*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 6 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 63)) - 1);
/*367*/ 		for( ; Search_i <= m2runtime_for_limit_1; Search_i += 1 ){
/*367*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 6 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 64), Search_i, Search_0err_entry_get, 65), 0 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 66), Search_id) == 0 ){
/*368*/ 				*Search_res_class = Search_class;
/*369*/ 				*Search_res_const = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 6 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 67), Search_i, Search_0err_entry_get, 68);
/*371*/ 				return ;
/*373*/ 			}
/*377*/ 		}
/*377*/ 	}
/*377*/ 	Search_ResolveClassConst((RECORD *)m2runtime_dereference_rhs_RECORD(Search_class, 3 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 69), Search_id, Search_res_class, Search_res_const);
/*378*/ 	if( *Search_res_const != NULL ){
/*380*/ 		return ;
/*385*/ 	}
/*385*/ 	{
/*385*/ 		int m2runtime_for_limit_1;
/*385*/ 		Search_i = 0;
/*385*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 4 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 70)) - 1);
/*386*/ 		for( ; Search_i <= m2runtime_for_limit_1; Search_i += 1 ){
/*386*/ 			Search_ResolveClassConst((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Search_class, 4 * sizeof(void*) + 2 * sizeof(int), Search_0err_entry_get, 71), Search_i, Search_0err_entry_get, 72), Search_id, Search_res_class, Search_res_const);
/*387*/ 			if( *Search_res_const != NULL ){
/*389*/ 				return ;
/*391*/ 			}
/*392*/ 		}
/*392*/ 	}
/*395*/ }


char * Search_0func[] = {
    "index_last",
    "NormalizeConstName",
    "SearchConstByAbsName",
    "SearchVarInScope",
    "SearchFuncLower",
    "SearchFuncByAbsName",
    "SearchClassByAbsName",
    "SearchClass",
    "SearchClassProperty",
    "SearchClassMethod",
    "ResolveClassConst"
};

int Search_0err_entry[] = {
    0 /* index_last */, 12,
    1 /* NormalizeConstName */, 23,
    1 /* NormalizeConstName */, 30,
    1 /* NormalizeConstName */, 30,
    1 /* NormalizeConstName */, 32,
    2 /* SearchConstByAbsName */, 43,
    2 /* SearchConstByAbsName */, 43,
    2 /* SearchConstByAbsName */, 45,
    2 /* SearchConstByAbsName */, 45,
    2 /* SearchConstByAbsName */, 47,
    2 /* SearchConstByAbsName */, 47,
    3 /* SearchVarInScope */, 77,
    3 /* SearchVarInScope */, 77,
    3 /* SearchVarInScope */, 80,
    3 /* SearchVarInScope */, 80,
    3 /* SearchVarInScope */, 80,
    3 /* SearchVarInScope */, 80,
    3 /* SearchVarInScope */, 82,
    3 /* SearchVarInScope */, 85,
    4 /* SearchFuncLower */, 108,
    4 /* SearchFuncLower */, 108,
    4 /* SearchFuncLower */, 110,
    5 /* SearchFuncByAbsName */, 121,
    5 /* SearchFuncByAbsName */, 122,
    5 /* SearchFuncByAbsName */, 124,
    5 /* SearchFuncByAbsName */, 128,
    5 /* SearchFuncByAbsName */, 128,
    6 /* SearchClassByAbsName */, 158,
    6 /* SearchClassByAbsName */, 158,
    6 /* SearchClassByAbsName */, 160,
    6 /* SearchClassByAbsName */, 160,
    6 /* SearchClassByAbsName */, 161,
    6 /* SearchClassByAbsName */, 163,
    6 /* SearchClassByAbsName */, 167,
    6 /* SearchClassByAbsName */, 167,
    7 /* SearchClass */, 221,
    7 /* SearchClass */, 221,
    7 /* SearchClass */, 222,
    7 /* SearchClass */, 223,
    8 /* SearchClassProperty */, 282,
    8 /* SearchClassProperty */, 284,
    8 /* SearchClassProperty */, 284,
    8 /* SearchClassProperty */, 285,
    8 /* SearchClassProperty */, 285,
    8 /* SearchClassProperty */, 286,
    8 /* SearchClassProperty */, 286,
    8 /* SearchClassProperty */, 287,
    8 /* SearchClassProperty */, 287,
    8 /* SearchClassProperty */, 292,
    8 /* SearchClassProperty */, 297,
    8 /* SearchClassProperty */, 298,
    8 /* SearchClassProperty */, 298,
    8 /* SearchClassProperty */, 305,
    8 /* SearchClassProperty */, 306,
    9 /* SearchClassMethod */, 330,
    9 /* SearchClassMethod */, 332,
    9 /* SearchClassMethod */, 332,
    9 /* SearchClassMethod */, 334,
    9 /* SearchClassMethod */, 334,
    9 /* SearchClassMethod */, 335,
    9 /* SearchClassMethod */, 337,
    9 /* SearchClassMethod */, 341,
    9 /* SearchClassMethod */, 341,
    10 /* ResolveClassConst */, 366,
    10 /* ResolveClassConst */, 367,
    10 /* ResolveClassConst */, 367,
    10 /* ResolveClassConst */, 367,
    10 /* ResolveClassConst */, 369,
    10 /* ResolveClassConst */, 370,
    10 /* ResolveClassConst */, 377,
    10 /* ResolveClassConst */, 385,
    10 /* ResolveClassConst */, 386,
    10 /* ResolveClassConst */, 386
};

void Search_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Search";
    *f = Search_0func[ Search_0err_entry[2*i] ];
    *l = Search_0err_entry[2*i + 1];
}
