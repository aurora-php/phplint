/* IMPLEMENTATION MODULE Typecast */
#define M2_IMPORT_Typecast

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Search
#    include "Search.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif
 RECORD * Expressions_ParseExpr(void);
 RECORD * Expressions_ParseStaticExpr(void);

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

void Typecast_0err_entry_get(int i, char **m, char **f, int *l);

/* 34*/ RECORD *
/* 34*/ Typecast_ParseType(STRING *Typecast_s)
/* 34*/ {
/* 35*/ 	int Typecast_i = 0;
/* 36*/ 	STRING * Typecast_token = NULL;
/* 39*/ 	STRING * Typecast_token_lc = NULL;

/* 45*/ 	void
/* 45*/ 	Typecast_nextToken(void)
/* 45*/ 	{
/* 47*/ 		STRING * Typecast_c = NULL;
/* 49*/ 		int Typecast_j = 0;
/* 49*/ 		if( (Typecast_i >= m2runtime_length(Typecast_s)) ){
/* 50*/ 			Typecast_token = NULL;
/* 51*/ 			Typecast_token_lc = NULL;
/* 53*/ 			return ;
/* 54*/ 		}
/* 54*/ 		Typecast_c = m2runtime_substr(Typecast_s, Typecast_i, 0, 0, Typecast_0err_entry_get, 0);
/* 55*/ 		if( ((m2runtime_strcmp(Typecast_c, m2runtime_CHR(91)) == 0) || (m2runtime_strcmp(Typecast_c, m2runtime_CHR(93)) == 0)) ){
/* 56*/ 			Typecast_token = Typecast_c;
/* 57*/ 			Typecast_token_lc = Typecast_token;
/* 58*/ 			Typecast_i = (Typecast_i + 1);
/* 60*/ 			return ;
/* 61*/ 		}
/* 61*/ 		Typecast_j = str_index(Typecast_s, Typecast_i, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"[]");
/* 62*/ 		if( (Typecast_j < 0) ){
/* 63*/ 			Typecast_token = m2runtime_substr(Typecast_s, Typecast_i, m2runtime_length(Typecast_s), 1, Typecast_0err_entry_get, 1);
/* 64*/ 			Typecast_token_lc = str_tolower(Typecast_token);
/* 65*/ 			Typecast_i = m2runtime_length(Typecast_s);
/* 67*/ 			return ;
/* 68*/ 		}
/* 68*/ 		Typecast_token = m2runtime_substr(Typecast_s, Typecast_i, Typecast_j, 1, Typecast_0err_entry_get, 2);
/* 69*/ 		Typecast_token_lc = str_tolower(Typecast_token);
/* 70*/ 		Typecast_i = Typecast_j;
/* 74*/ 	}


/* 81*/ 	int
/* 81*/ 	Typecast_isKeyword(STRING *Typecast_k)
/* 81*/ 	{
/* 81*/ 		if( m2runtime_strcmp(Typecast_k, Typecast_token_lc) == 0 ){
/* 82*/ 			if( m2runtime_strcmp(Typecast_k, Typecast_token) != 0 ){
/* 83*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"spelling check: expected ", Typecast_k, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)" but found ", Typecast_token, (STRING *) 1));
/* 85*/ 			}
/* 85*/ 			return TRUE;
/* 87*/ 		} else {
/* 87*/ 			return FALSE;
/* 90*/ 		}
/* 90*/ 		m2runtime_missing_return(Typecast_0err_entry_get, 3);
/* 90*/ 		return 0;
/* 92*/ 	}


/* 98*/ 	RECORD *
/* 98*/ 	Typecast_ParseTypeName(void)
/* 98*/ 	{
/*100*/ 		RECORD * Typecast_c = NULL;
/*100*/ 		if( Typecast_token == NULL ){
/*101*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"missing type");
/*102*/ 			return NULL;
/*103*/ 		} else if( (Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"boolean") || Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"bool")) ){
/*104*/ 			Typecast_nextToken();
/*105*/ 			return Globals_boolean_type;
/*106*/ 		} else if( (Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int") || Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"integer")) ){
/*107*/ 			Typecast_nextToken();
/*108*/ 			return Globals_int_type;
/*109*/ 		} else if( (Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"float") || Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"double") || Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"real")) ){
/*110*/ 			Typecast_nextToken();
/*111*/ 			return Globals_float_type;
/*112*/ 		} else if( Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string") ){
/*113*/ 			Typecast_nextToken();
/*114*/ 			return Globals_string_type;
/*115*/ 		} else if( Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"resource") ){
/*116*/ 			Typecast_nextToken();
/*117*/ 			return Globals_resource_type;
/*118*/ 		} else if( Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"object") ){
/*119*/ 			Typecast_nextToken();
/*120*/ 			return Globals_object_type;
/*121*/ 		} else if( m2_match(Typecast_token, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"^\134\134?[_a-zA-Z\200-\377]+(\134\134[_0-9a-zA-Z\200-\377]+)*$") ){
/*122*/ 			if( m2runtime_strcmp(m2runtime_substr(Typecast_token, 0, 0, 0, Typecast_0err_entry_get, 4), m2runtime_CHR(92)) != 0 ){
/*125*/ 				Typecast_token = m2runtime_concat_STRING(0, m2runtime_CHR(92), Typecast_token, (STRING *) 1);
/*127*/ 			}
/*127*/ 			Typecast_c = Search_SearchClass(Typecast_token);
/*128*/ 			if( Typecast_c == NULL ){
/*129*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"class not found: ", Typecast_token, (STRING *) 1));
/*130*/ 				return NULL;
/*132*/ 			} else {
/*132*/ 				Typecast_nextToken();
/*133*/ 				return (RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_c, 5 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 5);
/*136*/ 			}
/*136*/ 		} else {
/*136*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"invalid syntax in type: ", Typecast_token, (STRING *) 1));
/*137*/ 			return NULL;
/*140*/ 		}
/*140*/ 		m2runtime_missing_return(Typecast_0err_entry_get, 6);
/*140*/ 		return NULL;
/*142*/ 	}


/*147*/ 	RECORD *
/*147*/ 	Typecast_ParseArray(void)
/*147*/ 	{
/*149*/ 		RECORD * Typecast_a = NULL;
/*149*/ 		if( m2runtime_strcmp(Typecast_token, m2runtime_CHR(91)) != 0 ){
/*150*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"missing `[' after array");
/*151*/ 			return NULL;
/*153*/ 		}
/*153*/ 		Typecast_nextToken();
/*154*/ 		Typecast_a = (
/*154*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*154*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*154*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*154*/ 			push((char*) NULL),
/*154*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*154*/ 			push((char*) NULL),
/*155*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*155*/ 			(RECORD*) pop()
/*155*/ 		);
/*155*/ 		if( Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int") ){
/*156*/ 			Typecast_nextToken();
/*157*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Typecast_0err_entry_get, 7) = 3;
/*158*/ 		} else if( Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string") ){
/*159*/ 			Typecast_nextToken();
/*160*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Typecast_0err_entry_get, 8) = 5;
/*161*/ 		} else if( m2runtime_strcmp(Typecast_token, m2runtime_CHR(93)) == 0 ){
/*162*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Typecast_0err_entry_get, 9) = 7;
/*164*/ 		} else {
/*164*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"invalid index: ", Typecast_token, (STRING *) 1));
/*165*/ 			return NULL;
/*167*/ 		}
/*167*/ 		if( m2runtime_strcmp(Typecast_token, m2runtime_CHR(93)) != 0 ){
/*168*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"missing `]'");
/*169*/ 			return NULL;
/*171*/ 		}
/*171*/ 		Typecast_nextToken();
/*172*/ 		if( m2runtime_strcmp(Typecast_token, m2runtime_CHR(91)) == 0 ){
/*173*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 10) = Typecast_ParseArray();
/*175*/ 		} else {
/*175*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 11) = Typecast_ParseTypeName();
/*177*/ 		}
/*177*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_a, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 12) == NULL ){
/*178*/ 			return NULL;
/*180*/ 		}
/*180*/ 		return Typecast_a;
/*184*/ 	}


/*191*/ 	RECORD *
/*191*/ 	Typecast_ParseIndeces(RECORD *Typecast_t)
/*191*/ 	{
/*193*/ 		RECORD * Typecast_a = NULL;
/*193*/ 		Typecast_a = (
/*193*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*193*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*193*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*193*/ 			push((char*) NULL),
/*193*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*193*/ 			push((char*) NULL),
/*194*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*194*/ 			(RECORD*) pop()
/*194*/ 		);
/*194*/ 		Typecast_nextToken();
/*195*/ 		if( Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int") ){
/*196*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Typecast_0err_entry_get, 13) = 3;
/*197*/ 			Typecast_nextToken();
/*198*/ 		} else if( Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string") ){
/*199*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Typecast_0err_entry_get, 14) = 5;
/*200*/ 			Typecast_nextToken();
/*201*/ 		} else if( m2runtime_strcmp(Typecast_token, m2runtime_CHR(93)) == 0 ){
/*202*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Typecast_0err_entry_get, 15) = 7;
/*204*/ 		}
/*204*/ 		if( m2runtime_strcmp(Typecast_token, m2runtime_CHR(93)) != 0 ){
/*205*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"missing `]'");
/*206*/ 			return NULL;
/*208*/ 		}
/*208*/ 		Typecast_nextToken();
/*209*/ 		if( m2runtime_strcmp(Typecast_token, m2runtime_CHR(91)) == 0 ){
/*210*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 16) = Typecast_ParseIndeces(Typecast_t);
/*211*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_a, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 17) == NULL ){
/*212*/ 				return NULL;
/*215*/ 			}
/*215*/ 		} else {
/*215*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Typecast_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 18) = Typecast_t;
/*217*/ 		}
/*217*/ 		return Typecast_a;
/*222*/ 	}

/*224*/ 	RECORD * Typecast_t = NULL;
/*224*/ 	Typecast_i = 0;
/*225*/ 	Typecast_nextToken();
/*227*/ 	if( Typecast_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"array") ){
/*229*/ 		Typecast_nextToken();
/*230*/ 		Typecast_t = Typecast_ParseArray();
/*233*/ 	} else {
/*233*/ 		Typecast_t = Typecast_ParseTypeName();
/*234*/ 		if( Typecast_t == NULL ){
/*235*/ 			return NULL;
/*237*/ 		}
/*237*/ 		if( m2runtime_strcmp(Typecast_token, m2runtime_CHR(91)) == 0 ){
/*238*/ 			Typecast_t = Typecast_ParseIndeces(Typecast_t);
/*241*/ 		}
/*242*/ 	}
/*242*/ 	if( Typecast_t == NULL ){
/*244*/ 		return NULL;
/*245*/ 	} else if( Typecast_token != NULL ){
/*246*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"unexpected symbol: ", Typecast_token, (STRING *) 1));
/*249*/ 	}
/*249*/ 	return Typecast_t;
/*253*/ }


/*255*/ void
/*255*/ Typecast_err(RECORD *Typecast_to, RECORD *Typecast_from)
/*255*/ {
/*255*/ 	Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"cast(", Types_TypeToString(Typecast_to), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", Types_TypeToString(Typecast_from), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"): invalid typecast", (STRING *) 1));
/*260*/ }


/*282*/ void
/*282*/ Typecast_check_cast_types(RECORD *Typecast_to, RECORD *Typecast_from)
/*282*/ {
/*283*/ 	int Typecast_from_idx = 0;
/*283*/ 	int Typecast_to_idx = 0;
/*285*/ 	RECORD * Typecast_from_elem = NULL;
/*285*/ 	RECORD * Typecast_to_elem = NULL;
/*287*/ 	if( ((Typecast_to == NULL) || (Typecast_from == NULL)) ){
/*289*/ 		return ;
/*291*/ 	}
/*291*/ 	if( Types_SameType(Typecast_to, Typecast_from) ){
/*294*/ 		return ;
/*296*/ 	}
/*296*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Typecast_from, 2 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 19)){

/*298*/ 	case 2:
/*299*/ 	Typecast_err(Typecast_to, Typecast_from);
/*301*/ 	break;

/*301*/ 	case 3:
/*302*/ 	if( Typecast_to == Globals_float_type ){
/*303*/ 		Typecast_err(Typecast_to, Typecast_from);
/*304*/ 	} else if( Typecast_to == Globals_string_type ){
/*305*/ 		Typecast_err(Typecast_to, Typecast_from);
/*307*/ 	} else {
/*307*/ 		Typecast_err(Typecast_to, Typecast_from);
/*310*/ 	}
/*310*/ 	break;

/*310*/ 	case 4:
/*311*/ 	if( Typecast_to == Globals_int_type ){
/*312*/ 		Typecast_err(Typecast_to, Typecast_from);
/*313*/ 	} else if( Typecast_to == Globals_string_type ){
/*314*/ 		Typecast_err(Typecast_to, Typecast_from);
/*316*/ 	} else {
/*316*/ 		Typecast_err(Typecast_to, Typecast_from);
/*319*/ 	}
/*319*/ 	break;

/*319*/ 	case 5:
/*320*/ 	if( Typecast_to == Globals_int_type ){
/*321*/ 		Typecast_err(Typecast_to, Typecast_from);
/*322*/ 	} else if( Typecast_to == Globals_float_type ){
/*323*/ 		Typecast_err(Typecast_to, Typecast_from);
/*325*/ 	} else {
/*325*/ 		Typecast_err(Typecast_to, Typecast_from);
/*328*/ 	}
/*328*/ 	break;

/*328*/ 	case 8:
/*329*/ 	Typecast_err(Typecast_to, Typecast_from);
/*331*/ 	break;

/*331*/ 	case 9:
/*332*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Typecast_to, 2 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 20) == 9) ){
/*333*/ 		if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_from, 1 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 21) == NULL) || Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_to, 1 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 22), (RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_from, 1 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 23))) ){
/*336*/ 		} else {
/*336*/ 			Typecast_err(Typecast_to, Typecast_from);
/*339*/ 		}
/*339*/ 	} else {
/*339*/ 		Typecast_err(Typecast_to, Typecast_from);
/*342*/ 	}
/*342*/ 	break;

/*342*/ 	case 6:
/*343*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Typecast_to, 2 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 24) == 6) ){
/*347*/ 		Typecast_to_idx =  *(int *)m2runtime_dereference_rhs_RECORD(Typecast_to, 2 * sizeof(void*) + 3 * sizeof(int), Typecast_0err_entry_get, 25);
/*348*/ 		Typecast_from_idx =  *(int *)m2runtime_dereference_rhs_RECORD(Typecast_from, 2 * sizeof(void*) + 3 * sizeof(int), Typecast_0err_entry_get, 26);
/*349*/ 		switch(Typecast_from_idx){

/*350*/ 		case 1:
/*352*/ 		break;

/*352*/ 		case 3:
/*353*/ 		if( (Typecast_to_idx == 5) ){
/*354*/ 			Typecast_err(Typecast_to, Typecast_from);
/*356*/ 		}
/*356*/ 		break;

/*356*/ 		case 5:
/*357*/ 		if( (Typecast_to_idx == 3) ){
/*358*/ 			Typecast_err(Typecast_to, Typecast_from);
/*360*/ 		}
/*360*/ 		break;

/*360*/ 		case 7:
/*363*/ 		break;

/*363*/ 		default: m2runtime_missing_case_in_switch(Typecast_0err_entry_get, 27);
/*366*/ 		}
/*366*/ 		Typecast_to_elem = (RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_to, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 28);
/*367*/ 		Typecast_from_elem = (RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_from, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 29);
/*369*/ 		if( Typecast_from_elem == NULL ){
/*372*/ 		} else if( Typecast_to_elem == NULL ){
/*376*/ 		} else {
/*376*/ 			Typecast_check_cast_types(Typecast_to_elem, Typecast_from_elem);
/*381*/ 		}
/*381*/ 	} else {
/*381*/ 		Typecast_err(Typecast_to, Typecast_from);
/*384*/ 	}
/*384*/ 	break;

/*384*/ 	case 7:
/*388*/ 	break;

/*388*/ 	default:
/*388*/ 	Typecast_err(Typecast_to, Typecast_from);
/*392*/ 	}
/*394*/ }


/*396*/ RECORD *
/*396*/ Typecast_EvaluateCastCall(void)
/*396*/ {
/*397*/ 	RECORD * Typecast_type = NULL;
/*398*/ 	int Typecast_inside_call = 0;
/*399*/ 	RECORD * Typecast_to_result = NULL;
/*401*/ 	RECORD * Typecast_from_result = NULL;
/*401*/ 	Scanner_ReadSym();
/*412*/ 	Typecast_type = NULL;
/*413*/ 	Typecast_inside_call = ((Globals_curr_func != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 30), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"cast") == 0));
/*414*/ 	if( Typecast_inside_call ){
		Typecast_to_result = Expressions_ParseExpr();
/*416*/ 		Typecast_type = NULL;
/*418*/ 	} else {
		Typecast_to_result = Expressions_ParseStaticExpr();
/*419*/ 		if( Typecast_to_result == NULL ){
/*421*/ 			Typecast_type = NULL;
/*423*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_to_result, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 31) != Globals_string_type ){
/*424*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"invalid type: expected string but found ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_to_result, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 32)), (STRING *) 1));
/*426*/ 			Typecast_type = NULL;
/*428*/ 		} else if( (STRING *)m2runtime_dereference_rhs_RECORD(Typecast_to_result, 1 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 33) == NULL ){
/*430*/ 			Typecast_type = NULL;
/*433*/ 		} else {
/*433*/ 			Typecast_type = Typecast_ParseType((STRING *)m2runtime_dereference_rhs_RECORD(Typecast_to_result, 1 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 34));
/*436*/ 		}
/*437*/ 	}
/*437*/ 	Scanner_Expect(16, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `,'");
/*438*/ 	Scanner_ReadSym();
	Typecast_from_result = Expressions_ParseExpr();
/*442*/ 	if( Typecast_from_result != NULL ){
/*443*/ 		Typecast_check_cast_types(Typecast_type, (RECORD *)m2runtime_dereference_rhs_RECORD(Typecast_from_result, 0 * sizeof(void*) + 2 * sizeof(int), Typecast_0err_entry_get, 35));
/*446*/ 	}
/*446*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `)'");
/*447*/ 	Scanner_ReadSym();
/*449*/ 	return Typecast_type;
/*453*/ }


char * Typecast_0func[] = {
    "nextToken",
    "isKeyword",
    "ParseTypeName",
    "ParseArray",
    "ParseIndeces",
    "check_cast_types",
    "EvaluateCastCall"
};

int Typecast_0err_entry[] = {
    0 /* nextToken */, 54,
    0 /* nextToken */, 63,
    0 /* nextToken */, 68,
    1 /* isKeyword */, 89,
    2 /* ParseTypeName */, 122,
    2 /* ParseTypeName */, 133,
    2 /* ParseTypeName */, 139,
    3 /* ParseArray */, 157,
    3 /* ParseArray */, 160,
    3 /* ParseArray */, 162,
    3 /* ParseArray */, 173,
    3 /* ParseArray */, 175,
    3 /* ParseArray */, 177,
    4 /* ParseIndeces */, 196,
    4 /* ParseIndeces */, 199,
    4 /* ParseIndeces */, 202,
    4 /* ParseIndeces */, 210,
    4 /* ParseIndeces */, 211,
    4 /* ParseIndeces */, 215,
    5 /* check_cast_types */, 296,
    5 /* check_cast_types */, 332,
    5 /* check_cast_types */, 333,
    5 /* check_cast_types */, 333,
    5 /* check_cast_types */, 333,
    5 /* check_cast_types */, 343,
    5 /* check_cast_types */, 347,
    5 /* check_cast_types */, 348,
    5 /* check_cast_types */, 362,
    5 /* check_cast_types */, 366,
    5 /* check_cast_types */, 367,
    6 /* EvaluateCastCall */, 413,
    6 /* EvaluateCastCall */, 423,
    6 /* EvaluateCastCall */, 425,
    6 /* EvaluateCastCall */, 428,
    6 /* EvaluateCastCall */, 433,
    6 /* EvaluateCastCall */, 443
};

void Typecast_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Typecast";
    *f = Typecast_0func[ Typecast_0err_entry[2*i] ];
    *l = Typecast_0err_entry[2*i + 1];
}
