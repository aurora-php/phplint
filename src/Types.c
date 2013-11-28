/* IMPLEMENTATION MODULE Types */
#define M2_IMPORT_Types

void Types_0err_entry_get(int i, char **m, char **f, int *l);

/*  6*/ STRING *
/*  6*/ Types_TypeToString(RECORD *Types_t)
/*  6*/ {
/*  8*/ 	STRING * Types_x = NULL;
/*  8*/ 	if( Types_t == NULL ){
/*  9*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"unknown";
/* 12*/ 	}
/* 12*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Types_t, 2 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 0)){

/* 13*/ 	case 0:
/* 13*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"null";
/* 14*/ 	break;

/* 14*/ 	case 1:
/* 14*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"void";
/* 15*/ 	break;

/* 15*/ 	case 2:
/* 15*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"boolean";
/* 16*/ 	break;

/* 16*/ 	case 3:
/* 16*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int";
/* 17*/ 	break;

/* 17*/ 	case 4:
/* 17*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"float";
/* 18*/ 	break;

/* 18*/ 	case 5:
/* 18*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string";
/* 20*/ 	break;

/* 20*/ 	case 6:
/* 22*/ 	do {
/* 22*/ 		switch( *(int *)m2runtime_dereference_rhs_RECORD(Types_t, 2 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 1)){

/* 23*/ 		case 1:
/* 23*/ 		Types_x = m2runtime_concat_STRING(0, Types_x, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"[unknown]", (STRING *) 1);
/* 24*/ 		break;

/* 24*/ 		case 3:
/* 24*/ 		Types_x = m2runtime_concat_STRING(0, Types_x, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"[int]", (STRING *) 1);
/* 25*/ 		break;

/* 25*/ 		case 5:
/* 25*/ 		Types_x = m2runtime_concat_STRING(0, Types_x, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"[string]", (STRING *) 1);
/* 26*/ 		break;

/* 26*/ 		case 7:
/* 26*/ 		Types_x = m2runtime_concat_STRING(0, Types_x, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"[]", (STRING *) 1);
/* 28*/ 		break;

/* 28*/ 		default: m2runtime_missing_case_in_switch(Types_0err_entry_get, 2);
/* 28*/ 		}
/* 28*/ 		Types_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Types_t, 0 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 3);
/* 29*/ 	} while( !( ((Types_t == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(Types_t, 2 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 4) != 6))) ));
/* 30*/ 	return m2runtime_concat_STRING(0, Types_TypeToString(Types_t), Types_x, (STRING *) 1);
/* 32*/ 	break;

/* 32*/ 	case 7:
/* 32*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"mixed";
/* 33*/ 	break;

/* 33*/ 	case 8:
/* 33*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"resource";
/* 34*/ 	break;

/* 34*/ 	case 9:
/* 35*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Types_t, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 5) == NULL ){
/* 36*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"object";
/* 38*/ 	} else {
/* 38*/ 		return (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Types_t, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 6), 0 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 7);
/* 41*/ 	}
/* 41*/ 	break;

/* 41*/ 	default: m2runtime_missing_case_in_switch(Types_0err_entry_get, 8);
/* 42*/ 	}
/* 42*/ 	m2runtime_missing_return(Types_0err_entry_get, 9);
/* 42*/ 	return NULL;
/* 44*/ }


/* 46*/ int
/* 46*/ Types_SameType(RECORD *Types_a, RECORD *Types_b)
/* 46*/ {
/* 46*/ 	if( ((Types_a == NULL) || (Types_b == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(Types_a, 2 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 10) !=  *(int *)m2runtime_dereference_rhs_RECORD(Types_b, 2 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 11)))) ){
/* 47*/ 		return FALSE;
/* 49*/ 	}
/* 49*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Types_a, 2 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 12) == 6) ){
/* 50*/ 		return ((( *(int *)m2runtime_dereference_rhs_RECORD(Types_a, 2 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 13) ==  *(int *)m2runtime_dereference_rhs_RECORD(Types_b, 2 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 14))) && Types_SameType((RECORD *)m2runtime_dereference_rhs_RECORD(Types_a, 0 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 15), (RECORD *)m2runtime_dereference_rhs_RECORD(Types_b, 0 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 16)));
/* 52*/ 	} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Types_a, 2 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 17) == 9) ){
/* 53*/ 		return (RECORD *)m2runtime_dereference_rhs_RECORD(Types_a, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 18) == (RECORD *)m2runtime_dereference_rhs_RECORD(Types_b, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 19);
/* 55*/ 	} else {
/* 55*/ 		return TRUE;
/* 58*/ 	}
/* 58*/ 	m2runtime_missing_return(Types_0err_entry_get, 20);
/* 58*/ 	return 0;
/* 60*/ }


/* 62*/ STRING *
/* 62*/ Types_FunctionSignatureToString(RECORD *Types_s)
/* 62*/ {
/* 63*/ 	STRING * Types_t = NULL;
/* 64*/ 	int Types_i = 0;
/* 66*/ 	RECORD * Types_a = NULL;
/* 66*/ 	Types_t = Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Types_s, 0 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 21));
/* 67*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Types_s, 2 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 22) ){
/* 68*/ 		Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" &", (STRING *) 1);
/* 70*/ 	}
/* 70*/ 	Types_t = m2runtime_concat_STRING(0, Types_t, m2runtime_CHR(40), (STRING *) 1);
/* 73*/ 	{
/* 73*/ 		int m2runtime_for_limit_1;
/* 73*/ 		Types_i = 0;
/* 73*/ 		m2runtime_for_limit_1 = ( *(int *)m2runtime_dereference_rhs_RECORD(Types_s, 2 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 23) - 1);
/* 74*/ 		for( ; Types_i <= m2runtime_for_limit_1; Types_i += 1 ){
/* 74*/ 			Types_a = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Types_s, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 24), Types_i, Types_0err_entry_get, 25);
/* 75*/ 			if( (Types_i > 0) ){
/* 76*/ 				Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", (STRING *) 1);
/* 78*/ 			}
/* 78*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Types_a, 3 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 26) ){
/* 79*/ 				Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"return ", (STRING *) 1);
/* 81*/ 			}
/* 81*/ 			Types_t = m2runtime_concat_STRING(0, Types_t, Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Types_a, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 27)), (STRING *) 1);
/* 82*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Types_a, 3 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 28) ){
/* 83*/ 				Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" &", (STRING *) 1);
/* 86*/ 			}
/* 88*/ 		}
/* 88*/ 	}
/* 88*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Types_s, 2 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 29) < m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Types_s, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 30))) ){
/* 89*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Types_s, 2 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 31) > 0) ){
/* 90*/ 			Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" [", (STRING *) 1);
/* 92*/ 		} else {
/* 92*/ 			Types_t = m2runtime_concat_STRING(0, Types_t, m2runtime_CHR(91), (STRING *) 1);
/* 94*/ 		}
/* 94*/ 		{
/* 94*/ 			int m2runtime_for_limit_1;
/* 94*/ 			Types_i =  *(int *)m2runtime_dereference_rhs_RECORD(Types_s, 2 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 32);
/* 94*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Types_s, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 33)) - 1);
/* 95*/ 			for( ; Types_i <= m2runtime_for_limit_1; Types_i += 1 ){
/* 95*/ 				Types_a = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Types_s, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 34), Types_i, Types_0err_entry_get, 35);
/* 96*/ 				if( (Types_i > 0) ){
/* 97*/ 					Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", (STRING *) 1);
/* 99*/ 				}
/* 99*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Types_a, 3 * sizeof(void*) + 3 * sizeof(int), Types_0err_entry_get, 36) ){
/*100*/ 					Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"return ", (STRING *) 1);
/*102*/ 				}
/*102*/ 				Types_t = m2runtime_concat_STRING(0, Types_t, Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Types_a, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 37)), (STRING *) 1);
/*103*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Types_a, 3 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 38) ){
/*104*/ 					Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" &", (STRING *) 1);
/*107*/ 				}
/*107*/ 			}
/*107*/ 		}
/*107*/ 		Types_t = m2runtime_concat_STRING(0, Types_t, m2runtime_CHR(93), (STRING *) 1);
/*110*/ 	}
/*110*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Types_s, 2 * sizeof(void*) + 4 * sizeof(int), Types_0err_entry_get, 39) ){
/*111*/ 		if( (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Types_s, 1 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 40)) > 0) ){
/*112*/ 			Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", (STRING *) 1);
/*114*/ 		}
/*114*/ 		Types_t = m2runtime_concat_STRING(0, Types_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"...", (STRING *) 1);
/*116*/ 	}
/*116*/ 	Types_t = m2runtime_concat_STRING(0, Types_t, m2runtime_CHR(41), (STRING *) 1);
/*117*/ 	return Types_t;
/*121*/ }


/*122*/ STRING *
/*122*/ Types_MethodSignatureToString(RECORD *Types_m)
/*122*/ {
/*124*/ 	STRING * Types_s = NULL;
/*124*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Types_m, 9 * sizeof(void*) + 4 * sizeof(int), Types_0err_entry_get, 41)){

/*125*/ 	case 2:
/*125*/ 	Types_s = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"public";
/*126*/ 	break;

/*126*/ 	case 1:
/*126*/ 	Types_s = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"protected";
/*127*/ 	break;

/*127*/ 	case 0:
/*127*/ 	Types_s = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"private";
/*129*/ 	break;

/*129*/ 	default: m2runtime_missing_case_in_switch(Types_0err_entry_get, 42);
/*130*/ 	}
/*130*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Types_m, 9 * sizeof(void*) + 6 * sizeof(int), Types_0err_entry_get, 43) ){
/*130*/ 		Types_s = m2runtime_concat_STRING(0, Types_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)" final", (STRING *) 1);
/*131*/ 	}
/*131*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Types_m, 9 * sizeof(void*) + 5 * sizeof(int), Types_0err_entry_get, 44) ){
/*131*/ 		Types_s = m2runtime_concat_STRING(0, Types_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)" static", (STRING *) 1);
/*132*/ 	}
/*132*/ 	Types_s = m2runtime_concat_STRING(0, Types_s, m2runtime_CHR(32), Types_FunctionSignatureToString((RECORD *)m2runtime_dereference_rhs_RECORD(Types_m, 2 * sizeof(void*) + 2 * sizeof(int), Types_0err_entry_get, 45)), (STRING *) 1);
/*133*/ 	return Types_s;
/*138*/ }


char * Types_0func[] = {
    "TypeToString",
    "SameType",
    "FunctionSignatureToString",
    "MethodSignatureToString"
};

int Types_0err_entry[] = {
    0 /* TypeToString */, 12,
    0 /* TypeToString */, 22,
    0 /* TypeToString */, 27,
    0 /* TypeToString */, 28,
    0 /* TypeToString */, 29,
    0 /* TypeToString */, 35,
    0 /* TypeToString */, 38,
    0 /* TypeToString */, 38,
    0 /* TypeToString */, 40,
    0 /* TypeToString */, 41,
    1 /* SameType */, 46,
    1 /* SameType */, 46,
    1 /* SameType */, 49,
    1 /* SameType */, 50,
    1 /* SameType */, 50,
    1 /* SameType */, 51,
    1 /* SameType */, 51,
    1 /* SameType */, 52,
    1 /* SameType */, 53,
    1 /* SameType */, 53,
    1 /* SameType */, 57,
    2 /* FunctionSignatureToString */, 66,
    2 /* FunctionSignatureToString */, 67,
    2 /* FunctionSignatureToString */, 73,
    2 /* FunctionSignatureToString */, 74,
    2 /* FunctionSignatureToString */, 75,
    2 /* FunctionSignatureToString */, 78,
    2 /* FunctionSignatureToString */, 81,
    2 /* FunctionSignatureToString */, 82,
    2 /* FunctionSignatureToString */, 88,
    2 /* FunctionSignatureToString */, 88,
    2 /* FunctionSignatureToString */, 89,
    2 /* FunctionSignatureToString */, 94,
    2 /* FunctionSignatureToString */, 94,
    2 /* FunctionSignatureToString */, 95,
    2 /* FunctionSignatureToString */, 96,
    2 /* FunctionSignatureToString */, 99,
    2 /* FunctionSignatureToString */, 102,
    2 /* FunctionSignatureToString */, 103,
    2 /* FunctionSignatureToString */, 110,
    2 /* FunctionSignatureToString */, 111,
    3 /* MethodSignatureToString */, 124,
    3 /* MethodSignatureToString */, 128,
    3 /* MethodSignatureToString */, 130,
    3 /* MethodSignatureToString */, 131,
    3 /* MethodSignatureToString */, 132
};

void Types_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Types";
    *f = Types_0func[ Types_0err_entry[2*i] ];
    *l = Types_0err_entry[2*i + 1];
}
