/* IMPLEMENTATION MODULE Namespace */
#define M2_IMPORT_Namespace

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

void Namespace_0err_entry_get(int i, char **m, char **f, int *l);

/* 11*/ int
/* 11*/ Namespace_inNamespace(void)
/* 11*/ {
/* 11*/ 	return (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 0) != NULL;
/* 15*/ }


/* 17*/ int
/* 17*/ Namespace_isFullyQualified(STRING *Namespace_name)
/* 17*/ {
/* 17*/ 	return m2runtime_strcmp(m2runtime_substr(Namespace_name, 0, 0, 0, Namespace_0err_entry_get, 1), m2runtime_CHR(92)) == 0;
/* 21*/ }


/* 23*/ int
/* 23*/ Namespace_isQualified(STRING *Namespace_name)
/* 23*/ {
/* 23*/ 	return (str_find(Namespace_name, m2runtime_CHR(92)) > 0);
/* 27*/ }


/* 29*/ int
/* 29*/ Namespace_isIdentifier(STRING *Namespace_name)
/* 29*/ {
/* 29*/ 	return (str_find(Namespace_name, m2runtime_CHR(92)) < 0);
/* 33*/ }


/* 35*/ STRING *
/* 35*/ Namespace_Absolute(STRING *Namespace_id)
/* 35*/ {
/* 35*/ 	if( Namespace_inNamespace() ){
/* 36*/ 		return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 2), m2runtime_CHR(92), Namespace_id, (STRING *) 1);
/* 38*/ 	} else {
/* 38*/ 		return Namespace_id;
/* 41*/ 	}
/* 41*/ 	m2runtime_missing_return(Namespace_0err_entry_get, 3);
/* 41*/ 	return NULL;
/* 43*/ }


/* 45*/ STRING *
/* 45*/ Namespace_CheckBareID(STRING *Namespace_id)
/* 45*/ {
/* 45*/ 	if( Namespace_isIdentifier(Namespace_id) ){
/* 46*/ 		return Namespace_id;
/* 48*/ 	}
/* 48*/ 	Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"qualified identifier not allowed in declaration");
/* 49*/ 	return str_substitute(Namespace_id, m2runtime_CHR(92), m2runtime_CHR(95));
/* 53*/ }


/* 54*/ int
/* 54*/ Namespace_index_last_sept(STRING *Namespace_q)
/* 54*/ {
/* 56*/ 	int Namespace_i = 0;
/* 56*/ 	{
/* 56*/ 		int m2runtime_for_limit_1;
/* 56*/ 		Namespace_i = (m2runtime_length(Namespace_q) - 1);
/* 56*/ 		m2runtime_for_limit_1 = 0;
/* 57*/ 		for( ; Namespace_i >= m2runtime_for_limit_1; Namespace_i -= 1 ){
/* 57*/ 			if( m2runtime_strcmp(m2runtime_substr(Namespace_q, Namespace_i, 0, 0, Namespace_0err_entry_get, 4), m2runtime_CHR(92)) == 0 ){
/* 58*/ 				return Namespace_i;
/* 61*/ 			}
/* 61*/ 		}
/* 61*/ 	}
/* 61*/ 	return -1;
/* 65*/ }


/* 67*/ void
/* 67*/ Namespace_AddUse(STRING *Namespace_target, STRING *Namespace_alias)
/* 67*/ {
/* 68*/ 	int Namespace_i = 0;
/* 70*/ 	RECORD * Namespace_use = NULL;
/* 70*/ 	if( Namespace_alias == NULL ){
/* 71*/ 		Namespace_i = Namespace_index_last_sept(Namespace_target);
/* 72*/ 		if( (Namespace_i < 0) ){
/* 73*/ 			Namespace_alias = Namespace_target;
/* 75*/ 		} else {
/* 75*/ 			Namespace_alias = m2runtime_substr(Namespace_target, (Namespace_i + 1), m2runtime_length(Namespace_target), 1, Namespace_0err_entry_get, 5);
/* 78*/ 		}
/* 78*/ 	}
/* 78*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Namespace_use, 3 * sizeof(void*) + 3 * sizeof(int), 3, 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 6) = Namespace_target;
/* 79*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Namespace_use, 3 * sizeof(void*) + 3 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 7) = Namespace_alias;
/* 80*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Namespace_use, 3 * sizeof(void*) + 3 * sizeof(int), 3, 3 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 8) = 0;
/* 81*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Namespace_use, 3 * sizeof(void*) + 3 * sizeof(int), 3, 2 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 9) = Scanner_here();
/* 82*/ 	*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 5 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 10), sizeof(void *), 1, Namespace_0err_entry_get, 11) = Namespace_use;
/* 86*/ }


/* 88*/ STRING *
/* 88*/ Namespace_ApplyUse(STRING *Namespace_name, int Namespace_is_class)
/* 88*/ {
/* 89*/ 	int Namespace_j = 0;
/* 89*/ 	int Namespace_i = 0;
/* 90*/ 	RECORD * Namespace_use = NULL;
/* 92*/ 	STRING * Namespace_leading = NULL;
/* 92*/ 	if( Namespace_isFullyQualified(Namespace_name) ){
/* 93*/ 		return m2runtime_substr(Namespace_name, 1, m2runtime_length(Namespace_name), 1, Namespace_0err_entry_get, 12);
/* 95*/ 	} else if( Namespace_isQualified(Namespace_name) ){
/* 96*/ 		Namespace_i = str_find(Namespace_name, m2runtime_CHR(92));
/* 97*/ 		Namespace_leading = m2runtime_substr(Namespace_name, 0, Namespace_i, 1, Namespace_0err_entry_get, 13);
/* 98*/ 		{
/* 98*/ 			int m2runtime_for_limit_1;
/* 98*/ 			Namespace_j = 0;
/* 98*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 5 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 14)) - 1);
/* 99*/ 			for( ; Namespace_j <= m2runtime_for_limit_1; Namespace_j += 1 ){
/* 99*/ 				Namespace_use = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 5 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 15), Namespace_j, Namespace_0err_entry_get, 16);
/*100*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Namespace_use, 1 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 17), Namespace_leading) == 0 ){
/*101*/ 					m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Namespace_use, 3 * sizeof(void*) + 3 * sizeof(int), 3, 3 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 18), 1);
/*102*/ 					return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Namespace_use, 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 19), m2runtime_substr(Namespace_name, Namespace_i, m2runtime_length(Namespace_name), 1, Namespace_0err_entry_get, 20), (STRING *) 1);
/*105*/ 				}
/*106*/ 			}
/*106*/ 		}
/*106*/ 	} else if( Namespace_is_class ){
/*108*/ 		{
/*108*/ 			int m2runtime_for_limit_1;
/*108*/ 			Namespace_j = 0;
/*108*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 5 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 21)) - 1);
/*109*/ 			for( ; Namespace_j <= m2runtime_for_limit_1; Namespace_j += 1 ){
/*109*/ 				Namespace_use = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 5 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 22), Namespace_j, Namespace_0err_entry_get, 23);
/*110*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Namespace_use, 1 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 24), Namespace_name) == 0 ){
/*111*/ 					m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Namespace_use, 3 * sizeof(void*) + 3 * sizeof(int), 3, 3 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 25), 1);
/*112*/ 					return (STRING *)m2runtime_dereference_rhs_RECORD(Namespace_use, 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 26);
/*115*/ 				}
/*117*/ 			}
/*117*/ 		}
/*120*/ 	}
/*120*/ 	if( Namespace_inNamespace() ){
/*121*/ 		return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 27), m2runtime_CHR(92), Namespace_name, (STRING *) 1);
/*123*/ 	} else {
/*123*/ 		return Namespace_name;
/*126*/ 	}
/*126*/ 	m2runtime_missing_return(Namespace_0err_entry_get, 28);
/*126*/ 	return NULL;
/*128*/ }


/*130*/ void
/*130*/ Namespace_ReportUnusedUseClauses(void)
/*130*/ {
/*131*/ 	int Namespace_i = 0;
/*133*/ 	RECORD * Namespace_use = NULL;
/*133*/ 	{
/*133*/ 		int m2runtime_for_limit_1;
/*133*/ 		Namespace_i = 0;
/*133*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 5 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 29)) - 1);
/*134*/ 		for( ; Namespace_i <= m2runtime_for_limit_1; Namespace_i += 1 ){
/*134*/ 			Namespace_use = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 5 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 30), Namespace_i, Namespace_0err_entry_get, 31);
/*135*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD(Namespace_use, 3 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 32) == 0) ){
/*136*/ 				Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(Namespace_use, 2 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 33), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"unused clause `use ", (STRING *)m2runtime_dereference_rhs_RECORD(Namespace_use, 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 34), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)" as ", (STRING *)m2runtime_dereference_rhs_RECORD(Namespace_use, 1 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 35), m2runtime_CHR(39), (STRING *) 1));
/*140*/ 			}
/*141*/ 		}
/*141*/ 	}
/*143*/ }


/*145*/ void
/*145*/ Namespace_CheckSpelling(STRING *Namespace_ns)
/*145*/ {
/*146*/ 	STRING * Namespace_path = NULL;
/*146*/ 	STRING * Namespace_ns_lower = NULL;
/*148*/ 	int Namespace_i = 0;
/*148*/ 	if( Namespace_isFullyQualified(Namespace_ns) ){
/*149*/ 		Namespace_ns = m2runtime_substr(Namespace_ns, 1, m2runtime_length(Namespace_ns), 1, Namespace_0err_entry_get, 36);
/*151*/ 	}
/*151*/ 	Namespace_ns_lower = str_tolower(Namespace_ns);
/*152*/ 	Namespace_path = m2runtime_concat_STRING(0, Namespace_ns_lower, m2runtime_CHR(92), (STRING *) 1);
/*155*/ 	{
/*155*/ 		int m2runtime_for_limit_1;
/*155*/ 		Namespace_i = 0;
/*155*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_consts) - 1);
/*156*/ 		for( ; Namespace_i <= m2runtime_for_limit_1; Namespace_i += 1 ){
/*156*/ 			if( str_starts_with((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_consts, Namespace_i, Namespace_0err_entry_get, 37), 1 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 38), Namespace_path) ){
/*157*/ 				if( !str_starts_with((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_consts, Namespace_i, Namespace_0err_entry_get, 39), 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 40), Namespace_ns) ){
/*158*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"namespace was declared `", m2runtime_substr((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_consts, Namespace_i, Namespace_0err_entry_get, 41), 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 42), 0, m2runtime_length(Namespace_ns), 1, Namespace_0err_entry_get, 43), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"' near ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_consts, Namespace_i, Namespace_0err_entry_get, 44), 2 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 45)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)" that differ by upper/lower-case letters only", (STRING *) 1));
/*164*/ 				}
/*164*/ 				return ;
/*166*/ 			}
/*168*/ 		}
/*168*/ 	}
/*168*/ 	{
/*168*/ 		int m2runtime_for_limit_1;
/*168*/ 		Namespace_i = 0;
/*168*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_funcs) - 1);
/*169*/ 		for( ; Namespace_i <= m2runtime_for_limit_1; Namespace_i += 1 ){
/*169*/ 			if( str_starts_with((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_funcs, Namespace_i, Namespace_0err_entry_get, 46), 1 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 47), Namespace_path) ){
/*170*/ 				if( !str_starts_with((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_funcs, Namespace_i, Namespace_0err_entry_get, 48), 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 49), Namespace_ns) ){
/*171*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"namespace was declared `", m2runtime_substr((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_funcs, Namespace_i, Namespace_0err_entry_get, 50), 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 51), 0, m2runtime_length(Namespace_ns), 1, Namespace_0err_entry_get, 52), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"' near ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_funcs, Namespace_i, Namespace_0err_entry_get, 53), 2 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 54)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)" that differ by upper/lower-case letters only", (STRING *) 1));
/*177*/ 				}
/*177*/ 				return ;
/*179*/ 			}
/*181*/ 		}
/*181*/ 	}
/*181*/ 	{
/*181*/ 		int m2runtime_for_limit_1;
/*181*/ 		Namespace_i = 0;
/*181*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_classes) - 1);
/*182*/ 		for( ; Namespace_i <= m2runtime_for_limit_1; Namespace_i += 1 ){
/*182*/ 			if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, Namespace_i, Namespace_0err_entry_get, 55), 1 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 56), Namespace_ns_lower) == 0) || str_starts_with((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, Namespace_i, Namespace_0err_entry_get, 57), 1 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 58), Namespace_path)) ){
/*184*/ 				if( !str_starts_with((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, Namespace_i, Namespace_0err_entry_get, 59), 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 60), Namespace_ns) ){
/*185*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"namespace was declared `", m2runtime_substr((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, Namespace_i, Namespace_0err_entry_get, 61), 0 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 62), 0, m2runtime_length(Namespace_ns), 1, Namespace_0err_entry_get, 63), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"' near ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, Namespace_i, Namespace_0err_entry_get, 64), 12 * sizeof(void*) + 2 * sizeof(int), Namespace_0err_entry_get, 65)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)" that differ by upper/lower-case letters only", (STRING *) 1));
/*191*/ 				}
/*191*/ 				return ;
/*193*/ 			}
/*195*/ 		}
/*195*/ 	}
/*197*/ }


char * Namespace_0func[] = {
    "inNamespace",
    "isFullyQualified",
    "Absolute",
    "index_last_sept",
    "AddUse",
    "ApplyUse",
    "ReportUnusedUseClauses",
    "CheckSpelling"
};

int Namespace_0err_entry[] = {
    0 /* inNamespace */, 11,
    1 /* isFullyQualified */, 17,
    2 /* Absolute */, 36,
    2 /* Absolute */, 40,
    3 /* index_last_sept */, 57,
    4 /* AddUse */, 75,
    4 /* AddUse */, 78,
    4 /* AddUse */, 79,
    4 /* AddUse */, 80,
    4 /* AddUse */, 81,
    4 /* AddUse */, 82,
    4 /* AddUse */, 82,
    5 /* ApplyUse */, 93,
    5 /* ApplyUse */, 97,
    5 /* ApplyUse */, 98,
    5 /* ApplyUse */, 99,
    5 /* ApplyUse */, 100,
    5 /* ApplyUse */, 100,
    5 /* ApplyUse */, 101,
    5 /* ApplyUse */, 102,
    5 /* ApplyUse */, 102,
    5 /* ApplyUse */, 108,
    5 /* ApplyUse */, 109,
    5 /* ApplyUse */, 110,
    5 /* ApplyUse */, 110,
    5 /* ApplyUse */, 111,
    5 /* ApplyUse */, 112,
    5 /* ApplyUse */, 121,
    5 /* ApplyUse */, 125,
    6 /* ReportUnusedUseClauses */, 133,
    6 /* ReportUnusedUseClauses */, 134,
    6 /* ReportUnusedUseClauses */, 135,
    6 /* ReportUnusedUseClauses */, 135,
    6 /* ReportUnusedUseClauses */, 136,
    6 /* ReportUnusedUseClauses */, 136,
    6 /* ReportUnusedUseClauses */, 137,
    7 /* CheckSpelling */, 149,
    7 /* CheckSpelling */, 156,
    7 /* CheckSpelling */, 156,
    7 /* CheckSpelling */, 157,
    7 /* CheckSpelling */, 157,
    7 /* CheckSpelling */, 159,
    7 /* CheckSpelling */, 159,
    7 /* CheckSpelling */, 159,
    7 /* CheckSpelling */, 160,
    7 /* CheckSpelling */, 160,
    7 /* CheckSpelling */, 169,
    7 /* CheckSpelling */, 169,
    7 /* CheckSpelling */, 170,
    7 /* CheckSpelling */, 170,
    7 /* CheckSpelling */, 172,
    7 /* CheckSpelling */, 172,
    7 /* CheckSpelling */, 172,
    7 /* CheckSpelling */, 173,
    7 /* CheckSpelling */, 173,
    7 /* CheckSpelling */, 182,
    7 /* CheckSpelling */, 182,
    7 /* CheckSpelling */, 183,
    7 /* CheckSpelling */, 183,
    7 /* CheckSpelling */, 184,
    7 /* CheckSpelling */, 184,
    7 /* CheckSpelling */, 186,
    7 /* CheckSpelling */, 186,
    7 /* CheckSpelling */, 186,
    7 /* CheckSpelling */, 187,
    7 /* CheckSpelling */, 187
};

void Namespace_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Namespace";
    *f = Namespace_0func[ Namespace_0err_entry[2*i] ];
    *l = Namespace_0err_entry[2*i + 1];
}
