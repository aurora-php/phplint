/* IMPLEMENTATION MODULE Operators */
#define M2_IMPORT_Operators

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif

#ifndef M2_IMPORT_Accounting
#    include "Accounting.c"
#endif

void Operators_0err_entry_get(int i, char **m, char **f, int *l);

/* 34*/ RECORD *
/* 34*/ Operators_EvalValueConversion(RECORD *Operators_from_r, RECORD *Operators_to)
/* 34*/ {

/* 36*/ 	void
/* 36*/ 	Operators_invalid(STRING *Operators_s)
/* 36*/ 	{
/* 36*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"value conversion operator from ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 0)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)" to ", Types_TypeToString(Operators_to), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", Operators_s, (STRING *) 1));
/* 41*/ 	}

/* 42*/ 	RECORD * Operators_from = NULL;
/* 43*/ 	RECORD * Operators_C = NULL;
/* 46*/ 	RECORD * Operators_m = NULL;
/* 46*/ 	if( Operators_from_r == NULL ){
/* 47*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)"value conversion operator applied to an unknow data type");
/* 48*/ 		return (
/* 48*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 48*/ 			push((char*) Operators_to),
/* 48*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 48*/ 			push((char*) NULL),
/* 49*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 50*/ 			(RECORD*) pop()
/* 50*/ 		);
/* 51*/ 	}
/* 51*/ 	Operators_from = (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 1);
/* 52*/ 	if( Operators_from == NULL ){
/* 53*/ 		return (
/* 53*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 53*/ 			push((char*) Operators_to),
/* 53*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 53*/ 			push((char*) NULL),
/* 54*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 55*/ 			(RECORD*) pop()
/* 55*/ 		);
/* 56*/ 	}
/* 56*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_from, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 2)){

/* 58*/ 	case 2:
/* 59*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 3) == 3) ){
/* 60*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 4), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE") == 0 ){
/* 61*/ 			return (
/* 61*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 61*/ 				push((char*) Globals_int_type),
/* 61*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 61*/ 				push((char*) m2runtime_CHR(48)),
/* 62*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 62*/ 				(RECORD*) pop()
/* 62*/ 			);
/* 62*/ 		} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 5), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE") == 0 ){
/* 63*/ 			return (
/* 63*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 63*/ 				push((char*) Globals_int_type),
/* 63*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 63*/ 				push((char*) m2runtime_CHR(49)),
/* 64*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 65*/ 				(RECORD*) pop()
/* 65*/ 			);
/* 65*/ 		} else {
/* 65*/ 			return (
/* 65*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 65*/ 				push((char*) Globals_int_type),
/* 65*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 65*/ 				push((char*) NULL),
/* 66*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 67*/ 				(RECORD*) pop()
/* 67*/ 			);
/* 68*/ 		}
/* 68*/ 	} else {
/* 68*/ 		Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/* 71*/ 	}
/* 71*/ 	break;

/* 71*/ 	case 3:
/* 72*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 6)){

/* 73*/ 	case 2:
/* 73*/ 	case 4:
/* 73*/ 	case 5:
/* 75*/ 	break;

/* 75*/ 	default:
/* 75*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/* 78*/ 	}
/* 78*/ 	break;

/* 78*/ 	case 4:
/* 79*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 7)){

/* 80*/ 	case 3:
/* 80*/ 	case 5:
/* 81*/ 	break;

/* 81*/ 	default:
/* 81*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/* 84*/ 	}
/* 84*/ 	break;

/* 84*/ 	case 5:
/* 85*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 8)){

/* 86*/ 	case 3:
/* 86*/ 	case 4:
/* 87*/ 	break;

/* 87*/ 	default:
/* 87*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/* 90*/ 	}
/* 90*/ 	break;

/* 90*/ 	case 7:
/* 91*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 9)){

/* 92*/ 	case 2:
/* 92*/ 	case 3:
/* 92*/ 	case 4:
/* 92*/ 	case 5:
/* 93*/ 	break;

/* 93*/ 	default:
/* 93*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/* 96*/ 	}
/* 96*/ 	break;

/* 96*/ 	case 9:
/* 97*/ 	if( ((( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 10) == 5)) && ((Globals_php_ver == 5)) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_from, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 11) != NULL)) ){
/* 99*/ 		Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_from, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 12), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__toString", &Operators_C, &Operators_m);
/*100*/ 		if( Operators_m == NULL ){
/*101*/ 			Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*104*/ 		} else {
/*104*/ 			Accounting_AccountClassMethod(Operators_C, Operators_m);
/*107*/ 		}
/*107*/ 	} else {
/*107*/ 		Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*110*/ 	}
/*110*/ 	break;

/*110*/ 	case 0:
/*111*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 13)){

/*112*/ 	case 5:
/*112*/ 	case 6:
/*112*/ 	case 8:
/*112*/ 	case 9:
/*113*/ 	return (
/*113*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*113*/ 		push((char*) Operators_to),
/*113*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*113*/ 		push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL"),
/*114*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*114*/ 		(RECORD*) pop()
/*114*/ 	);
/*114*/ 	break;

/*114*/ 	default:
/*114*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*118*/ 	}
/*118*/ 	break;

/*118*/ 	default:
/*118*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*122*/ 	}
/*122*/ 	return (
/*122*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*122*/ 		push((char*) Operators_to),
/*122*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*122*/ 		push((char*) NULL),
/*123*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*124*/ 		(RECORD*) pop()
/*124*/ 	);
/*126*/ }


/*128*/ RECORD *
/*128*/ Operators_EvalTypeConversion(RECORD *Operators_from_r, RECORD *Operators_to)
/*128*/ {

/*130*/ 	void
/*130*/ 	Operators_invalid(STRING *Operators_s)
/*130*/ 	{
/*130*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"type conversion operator from ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 14)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)" to ", Types_TypeToString(Operators_to), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", Operators_s, (STRING *) 1));
/*135*/ 	}


/*136*/ 	void
/*136*/ 	Operators_EvalFormalTypecastArray(int Operators_fi, RECORD *Operators_fe, int Operators_ti, RECORD *Operators_te)
/*136*/ 	{
/*138*/ 		RECORD * Operators_r = NULL;
/*138*/ 		switch(Operators_fi){

/*139*/ 		case 1:
/*140*/ 		break;

/*140*/ 		case 3:
/*141*/ 		if( (Operators_ti != 3) ){
/*142*/ 			Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"incompatible index type");
/*144*/ 		}
/*144*/ 		break;

/*144*/ 		case 5:
/*145*/ 		if( (Operators_ti != 5) ){
/*146*/ 			Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"incompatible index type");
/*148*/ 		}
/*148*/ 		break;

/*148*/ 		case 7:
/*150*/ 		break;

/*150*/ 		default: m2runtime_missing_case_in_switch(Operators_0err_entry_get, 15);
/*150*/ 		}
/*150*/ 		Operators_r = Operators_EvalTypeConversion((
/*150*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*150*/ 			push((char*) Operators_fe),
/*150*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*150*/ 			push((char*) NULL),
/*150*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*150*/ 			(RECORD*) pop()
/*150*/ 		), Operators_te);
/*153*/ 	}

/*156*/ 	RECORD * Operators_from = NULL;
/*156*/ 	if( Operators_from_r == NULL ){
/*157*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\67,\0,\0,\0)"type conversion operator applied to an unknow data type");
/*158*/ 		return (
/*158*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*158*/ 			push((char*) Operators_to),
/*158*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*158*/ 			push((char*) NULL),
/*159*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*160*/ 			(RECORD*) pop()
/*160*/ 		);
/*161*/ 	}
/*161*/ 	Operators_from = (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 16);
/*162*/ 	if( Operators_from == NULL ){
/*163*/ 		return (
/*163*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*163*/ 			push((char*) Operators_to),
/*163*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*163*/ 			push((char*) NULL),
/*164*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*165*/ 			(RECORD*) pop()
/*165*/ 		);
/*166*/ 	}
/*166*/ 	if( Operators_to == NULL ){
/*167*/ 		return NULL;
/*170*/ 	}
/*170*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_from, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 17)){

/*172*/ 	case 0:
/*173*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 18)){

/*174*/ 	case 5:
/*174*/ 	case 6:
/*174*/ 	case 8:
/*174*/ 	case 9:
/*175*/ 	return (
/*175*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*175*/ 		push((char*) Operators_to),
/*175*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*175*/ 		push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL"),
/*176*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*176*/ 		(RECORD*) pop()
/*176*/ 	);
/*176*/ 	break;

/*176*/ 	default:
/*176*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*179*/ 	}
/*179*/ 	break;

/*179*/ 	case 7:
/*180*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 19)){

/*181*/ 	case 2:
/*181*/ 	case 3:
/*181*/ 	case 4:
/*181*/ 	case 5:
/*181*/ 	case 6:
/*181*/ 	case 8:
/*181*/ 	case 9:
/*182*/ 	break;

/*182*/ 	default:
/*182*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*185*/ 	}
/*185*/ 	break;

/*185*/ 	case 6:
/*186*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 20) != 6) ){
/*187*/ 		Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*188*/ 	} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 21), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"array()") == 0 ){
/*190*/ 		return (
/*190*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*190*/ 			push((char*) Operators_to),
/*190*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*190*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"array(...)"),
/*191*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*192*/ 			(RECORD*) pop()
/*192*/ 		);
/*192*/ 	} else {
/*192*/ 		Operators_EvalFormalTypecastArray( *(int *)m2runtime_dereference_rhs_RECORD(Operators_from, 2 * sizeof(void*) + 3 * sizeof(int), Operators_0err_entry_get, 22), (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_from, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 23),  *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 3 * sizeof(int), Operators_0err_entry_get, 24), (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_to, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 25));
/*196*/ 	}
/*196*/ 	break;

/*196*/ 	case 9:
/*197*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_to, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 26) == 9) ){
/*204*/ 	} else {
/*204*/ 		Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*206*/ 	}
/*206*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_from, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 27) != NULL ){
/*207*/ 		Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"the term must be a generic `object'");
/*211*/ 	}
/*211*/ 	break;

/*211*/ 	default:
/*211*/ 	Operators_invalid((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"undefined");
/*216*/ 	}
/*216*/ 	if( (STRING *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 28) == NULL ){
/*217*/ 		return (
/*217*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*217*/ 			push((char*) Operators_to),
/*217*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*217*/ 			push((char*) NULL),
/*218*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*219*/ 			(RECORD*) pop()
/*219*/ 		);
/*219*/ 	} else {
/*219*/ 		return (
/*219*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*219*/ 			push((char*) Operators_to),
/*219*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*219*/ 			push((char*) m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"/*.(", Types_TypeToString(Operators_to), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)").*/ ", (STRING *)m2runtime_dereference_rhs_RECORD(Operators_from_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 29), (STRING *) 1)),
/*220*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*221*/ 			(RECORD*) pop()
/*221*/ 		);
/*222*/ 	}
/*222*/ 	m2runtime_missing_return(Operators_0err_entry_get, 30);
/*222*/ 	return NULL;
/*224*/ }


/*236*/ void
/*236*/ Operators_eval_res_type(RECORD *Operators_a, RECORD *Operators_b, STRING *Operators_op_name, RECORD **Operators_res_type, STRING **Operators_res_as, STRING **Operators_res_bs)
/*236*/ {
/*236*/ 	RECORD * Operators_t = NULL;
/*236*/ 	RECORD * Operators_bt = NULL;
/*236*/ 	RECORD * Operators_at = NULL;
/*238*/ 	STRING * Operators_bs = NULL;
/*238*/ 	STRING * Operators_as = NULL;
/*240*/ 	if( Operators_a == NULL ){
/*244*/ 	} else {
/*244*/ 		Operators_at = (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 31);
/*245*/ 		if( Operators_at == Globals_int_type ){
/*246*/ 			Operators_as = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 32);
/*247*/ 		} else if( Operators_at == Globals_float_type ){
/*248*/ 			Operators_as = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 33);
/*249*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_at, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 34) == 6) ){
/*252*/ 		} else {
/*252*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"`EXPR ", Operators_op_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" ...'", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)": expected number or array but found ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 35)), (STRING *) 1));
/*257*/ 		}
/*259*/ 	}
/*259*/ 	if( Operators_b == NULL ){
/*262*/ 	} else {
/*262*/ 		Operators_bt = (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 36);
/*263*/ 		if( Operators_bt == Globals_int_type ){
/*264*/ 			Operators_bs = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 37);
/*265*/ 		} else if( Operators_bt == Globals_float_type ){
/*266*/ 			Operators_bs = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 38);
/*267*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_bt, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 39) == 6) ){
/*270*/ 		} else {
/*270*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"`... ", Operators_op_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)" EXPR'", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)": expected number or array but found ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 40)), (STRING *) 1));
/*275*/ 		}
/*277*/ 	}
/*277*/ 	if( Operators_at == Globals_int_type ){
/*278*/ 		if( Operators_bt == Globals_int_type ){
/*279*/ 			Operators_t = Globals_int_type;
/*280*/ 		} else if( Operators_bt == Globals_float_type ){
/*281*/ 			Operators_t = Globals_float_type;
/*283*/ 		}
/*283*/ 	} else if( Operators_at == Globals_float_type ){
/*284*/ 		if( Operators_bt == Globals_int_type ){
/*285*/ 			Operators_t = Globals_float_type;
/*286*/ 		} else if( Operators_bt == Globals_float_type ){
/*287*/ 			Operators_t = Globals_float_type;
/*289*/ 		}
/*289*/ 	} else if( ((Operators_at != NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(Operators_at, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 41) == 6)) && (Operators_bt != NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(Operators_bt, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 42) == 6))) ){
/*291*/ 		if( m2runtime_strcmp(Operators_op_name, m2runtime_CHR(43)) != 0 ){
/*292*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"undefined operator between arrays: ", Operators_op_name, (STRING *) 1));
/*293*/ 		} else if( Types_SameType(Operators_at, Operators_bt) ){
/*294*/ 			Operators_t = Operators_at;
/*295*/ 			Operators_as = NULL;
/*296*/ 			Operators_bs = NULL;
/*298*/ 		} else {
/*298*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"cannot add arrays of different types");
/*301*/ 		}
/*302*/ 	}
/*302*/ 	*Operators_res_type = Operators_t;
/*303*/ 	*Operators_res_as = Operators_as;
/*304*/ 	*Operators_res_bs = Operators_bs;
/*309*/ }


/*310*/ RECORD *
/*310*/ Operators_EvalPlus(RECORD *Operators_a, RECORD *Operators_b)
/*310*/ {
/*310*/ 	RECORD * Operators_t = NULL;
/*312*/ 	STRING * Operators_v = NULL;
/*312*/ 	STRING * Operators_bs = NULL;
/*312*/ 	STRING * Operators_as = NULL;
/*312*/ 	Operators_eval_res_type(Operators_a, Operators_b, m2runtime_CHR(43), &Operators_t, &Operators_as, &Operators_bs);
/*314*/ 	if( ((Operators_as != NULL) && (Operators_bs != NULL)) ){
/*315*/ 		if( Operators_t == Globals_int_type ){
/*316*/ 			Operators_v = m2runtime_itos((m2_stoi(Operators_as) + m2_stoi(Operators_bs)));
/*318*/ 		} else if( Operators_t == Globals_float_type ){
/*319*/ 			Operators_v = m2runtime_rtos(m2_stor(Operators_as) + m2_stor(Operators_bs));
/*322*/ 		}
/*323*/ 	}
/*323*/ 	if( Operators_t == NULL ){
/*324*/ 		return NULL;
/*326*/ 	}
/*326*/ 	return (
/*326*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*326*/ 		push((char*) Operators_t),
/*326*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*326*/ 		push((char*) Operators_v),
/*327*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*328*/ 		(RECORD*) pop()
/*328*/ 	);
/*330*/ }


/*331*/ RECORD *
/*331*/ Operators_EvalMinus(RECORD *Operators_a, RECORD *Operators_b)
/*331*/ {
/*331*/ 	RECORD * Operators_t = NULL;
/*333*/ 	STRING * Operators_v = NULL;
/*333*/ 	STRING * Operators_bs = NULL;
/*333*/ 	STRING * Operators_as = NULL;
/*333*/ 	Operators_eval_res_type(Operators_a, Operators_b, m2runtime_CHR(45), &Operators_t, &Operators_as, &Operators_bs);
/*335*/ 	if( ((Operators_as != NULL) && (Operators_bs != NULL)) ){
/*336*/ 		if( Operators_t == Globals_int_type ){
/*337*/ 			Operators_v = m2runtime_itos((m2_stoi(Operators_as) - m2_stoi(Operators_bs)));
/*339*/ 		} else if( Operators_t == Globals_float_type ){
/*340*/ 			Operators_v = m2runtime_rtos(m2_stor(Operators_as) - m2_stor(Operators_bs));
/*343*/ 		}
/*344*/ 	}
/*344*/ 	if( Operators_t == NULL ){
/*345*/ 		return NULL;
/*347*/ 	}
/*347*/ 	return (
/*347*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*347*/ 		push((char*) Operators_t),
/*347*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*347*/ 		push((char*) Operators_v),
/*348*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*349*/ 		(RECORD*) pop()
/*349*/ 	);
/*351*/ }


/*352*/ RECORD *
/*352*/ Operators_EvalMult(RECORD *Operators_a, RECORD *Operators_b)
/*352*/ {
/*352*/ 	RECORD * Operators_t = NULL;
/*354*/ 	STRING * Operators_v = NULL;
/*354*/ 	STRING * Operators_bs = NULL;
/*354*/ 	STRING * Operators_as = NULL;
/*354*/ 	Operators_eval_res_type(Operators_a, Operators_b, m2runtime_CHR(42), &Operators_t, &Operators_as, &Operators_bs);
/*356*/ 	if( ((Operators_as != NULL) && (Operators_bs != NULL)) ){
/*357*/ 		if( Operators_t == Globals_int_type ){
/*358*/ 			Operators_v = m2runtime_itos((m2_stoi(Operators_as) * m2_stoi(Operators_bs)));
/*360*/ 		} else if( Operators_t == Globals_float_type ){
/*361*/ 			Operators_v = m2runtime_rtos(m2_stor(Operators_as) * m2_stor(Operators_bs));
/*364*/ 		}
/*365*/ 	}
/*365*/ 	if( Operators_t == NULL ){
/*366*/ 		return NULL;
/*368*/ 	}
/*368*/ 	return (
/*368*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*368*/ 		push((char*) Operators_t),
/*368*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*368*/ 		push((char*) Operators_v),
/*369*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*370*/ 		(RECORD*) pop()
/*370*/ 	);
/*372*/ }


/*373*/ RECORD *
/*373*/ Operators_EvalDiv(RECORD *Operators_a, RECORD *Operators_b)
/*373*/ {
/*373*/ 	RECORD * Operators_t = NULL;
/*375*/ 	STRING * Operators_v = NULL;
/*375*/ 	STRING * Operators_bs = NULL;
/*375*/ 	STRING * Operators_as = NULL;
/*375*/ 	Operators_eval_res_type(Operators_a, Operators_b, m2runtime_CHR(47), &Operators_t, &Operators_as, &Operators_bs);
/*377*/ 	if( Operators_t == Globals_int_type ){
/*378*/ 		Operators_t = Globals_float_type;
/*382*/ 	}
/*382*/ 	if( ((Operators_t == Globals_float_type) && (Operators_as != NULL) && (Operators_bs != NULL)) ){
/*383*/ 		Operators_v = m2runtime_rtos(m2_stor(Operators_as) / m2_stor(Operators_bs));
/*386*/ 	}
/*386*/ 	if( Operators_t == NULL ){
/*387*/ 		return NULL;
/*389*/ 	}
/*389*/ 	return (
/*389*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*389*/ 		push((char*) Operators_t),
/*389*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*389*/ 		push((char*) Operators_v),
/*390*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*391*/ 		(RECORD*) pop()
/*391*/ 	);
/*393*/ }


/*394*/ RECORD *
/*394*/ Operators_EvalMod(RECORD *Operators_a, RECORD *Operators_b)
/*394*/ {
/*394*/ 	RECORD * Operators_t = NULL;
/*396*/ 	STRING * Operators_v = NULL;
/*396*/ 	STRING * Operators_bs = NULL;
/*396*/ 	STRING * Operators_as = NULL;
/*396*/ 	Operators_eval_res_type(Operators_a, Operators_b, m2runtime_CHR(37), &Operators_t, &Operators_as, &Operators_bs);
/*398*/ 	if( Operators_t == Globals_float_type ){
/*399*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"operator `%' applied to non-integer numbers might give", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)" unpredictable results", (STRING *) 1));
/*403*/ 	}
/*403*/ 	if( ((Operators_t == Globals_int_type) && (Operators_as != NULL) && (Operators_bs != NULL)) ){
/*404*/ 		Operators_v = m2runtime_itos((m2_stoi(Operators_as) % m2_stoi(Operators_bs)));
/*407*/ 	}
/*407*/ 	if( Operators_t == NULL ){
/*408*/ 		return NULL;
/*410*/ 	}
/*410*/ 	return (
/*410*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*410*/ 		push((char*) Operators_t),
/*410*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*410*/ 		push((char*) Operators_v),
/*411*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*412*/ 		(RECORD*) pop()
/*412*/ 	);
/*414*/ }


/*416*/ RECORD *
/*416*/ Operators_EvalPeriod(RECORD *Operators_a, RECORD *Operators_b)
/*416*/ {
/*417*/ 	STRING * Operators_bs = NULL;
/*417*/ 	STRING * Operators_as = NULL;
/*419*/ 	RECORD * Operators_t = NULL;
/*419*/ 	if( Operators_a != NULL ){
/*420*/ 		Operators_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 43);
/*422*/ 	}
/*422*/ 	if( Operators_a == NULL ){
/*424*/ 	} else if( Operators_t == Globals_boolean_type ){
/*425*/ 		Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\201,\0,\0,\0)"found boolean value in string concatenation: remember that FALSE gets rendered as empty string \042\042 while TRUE gets rendered as \0421\042");
/*426*/ 	} else if( Operators_t == Globals_int_type ){
/*427*/ 		Operators_as = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 44);
/*428*/ 	} else if( Operators_t == Globals_float_type ){
/*429*/ 		Operators_as = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 45);
/*430*/ 	} else if( Operators_t == Globals_string_type ){
/*431*/ 		Operators_as = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 46);
/*432*/ 	} else if( Classes_IsObjectConvertibleToString(Operators_t) ){
/*433*/ 		Operators_as = NULL;
/*435*/ 	} else {
/*435*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"`EXPR . ...': invalid value EXPR of type ", Types_TypeToString(Operators_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)", expected a string", (STRING *) 1));
/*439*/ 	}
/*439*/ 	if( Operators_b != NULL ){
/*440*/ 		Operators_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 47);
/*442*/ 	}
/*442*/ 	if( Operators_b == NULL ){
/*444*/ 	} else if( Operators_t == Globals_boolean_type ){
/*445*/ 		Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\201,\0,\0,\0)"found boolean value in string concatenation: remember that FALSE gets rendered as empty string \042\042 while TRUE gets rendered as \0421\042");
/*446*/ 	} else if( Operators_t == Globals_int_type ){
/*447*/ 		Operators_bs = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 48);
/*448*/ 	} else if( Operators_t == Globals_float_type ){
/*449*/ 		Operators_bs = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 49);
/*450*/ 	} else if( Operators_t == Globals_string_type ){
/*451*/ 		Operators_bs = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 50);
/*452*/ 	} else if( Classes_IsObjectConvertibleToString(Operators_t) ){
/*453*/ 		Operators_bs = NULL;
/*455*/ 	} else {
/*455*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"`... . EXPR': found EXPR of type ", Types_TypeToString(Operators_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)", expected a string", (STRING *) 1));
/*459*/ 	}
/*459*/ 	if( ((Operators_as == NULL) || (Operators_bs == NULL)) ){
/*460*/ 		return (
/*460*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*460*/ 			push((char*) Globals_string_type),
/*460*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*460*/ 			push((char*) NULL),
/*461*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*462*/ 			(RECORD*) pop()
/*462*/ 		);
/*462*/ 	} else {
/*462*/ 		return (
/*462*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*462*/ 			push((char*) Globals_string_type),
/*462*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*462*/ 			push((char*) m2runtime_concat_STRING(0, Operators_as, Operators_bs, (STRING *) 1)),
/*463*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*464*/ 			(RECORD*) pop()
/*464*/ 		);
/*465*/ 	}
/*465*/ 	m2runtime_missing_return(Operators_0err_entry_get, 51);
/*465*/ 	return NULL;
/*467*/ }


/*468*/ RECORD *
/*468*/ Operators_EvalNot(RECORD *Operators_x)
/*468*/ {
/*470*/ 	RECORD * Operators_r = NULL;
/*470*/ 	Operators_r = (
/*470*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*470*/ 		push((char*) Globals_boolean_type),
/*470*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*470*/ 		push((char*) NULL),
/*471*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*471*/ 		(RECORD*) pop()
/*471*/ 	);
/*471*/ 	if( Operators_x == NULL ){
/*472*/ 		return Operators_r;
/*473*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_x, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 52) != Globals_boolean_type ){
/*474*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"invalid argument of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_x, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 53)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" for the boolean operator `!'. Expected boolean value.", (STRING *) 1));
/*476*/ 		return Operators_r;
/*477*/ 	} else if( (STRING *)m2runtime_dereference_rhs_RECORD(Operators_x, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 54) == NULL ){
/*478*/ 		return Operators_r;
/*480*/ 	}
/*480*/ 	if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_x, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 55), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE") == 0 ){
/*481*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 56) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*483*/ 	} else {
/*483*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 57) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*485*/ 	}
/*485*/ 	return Operators_r;
/*489*/ }


/*490*/ RECORD *
/*490*/ Operators_EvalUnaryPlusMinus(int Operators_is_minus, RECORD *Operators_r)
/*490*/ {
/*490*/ 	RECORD * Operators_t = NULL;
/*492*/ 	STRING * Operators_v = NULL;
/*492*/ 	if( Operators_r == NULL ){
/*493*/ 		return NULL;
/*494*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 58) == Globals_int_type ){
/*495*/ 		Operators_t = Globals_int_type;
/*496*/ 		Operators_v = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 59);
/*497*/ 		if( (Operators_is_minus && (Operators_v != NULL)) ){
/*498*/ 			Operators_v = m2runtime_itos(-m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 60)));
/*500*/ 		}
/*500*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 61) == Globals_float_type ){
/*501*/ 		Operators_t = Globals_float_type;
/*502*/ 		Operators_v = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 62);
/*503*/ 		if( (Operators_is_minus && (Operators_v != NULL)) ){
/*504*/ 			Operators_v = m2runtime_rtos(-m2_stor((STRING *)m2runtime_dereference_rhs_RECORD(Operators_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 63)));
/*507*/ 		}
/*507*/ 	} else {
/*507*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"invalid value of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 64)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" for the unary operator +/-", (STRING *) 1));
/*509*/ 		return NULL;
/*511*/ 	}
/*511*/ 	return (
/*511*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*511*/ 		push((char*) Operators_t),
/*511*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*511*/ 		push((char*) Operators_v),
/*512*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*513*/ 		(RECORD*) pop()
/*513*/ 	);
/*515*/ }


/*520*/ int
/*520*/ Operators_check_args_bit_binary_op(STRING *Operators_n, RECORD *Operators_a, RECORD *Operators_b)
/*520*/ {
/*522*/ 	int Operators_good = 0;
/*522*/ 	if( ((Operators_a == NULL) || (Operators_b == NULL)) ){
/*523*/ 		return FALSE;
/*527*/ 	}
/*527*/ 	Operators_good = TRUE;
/*528*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 65) != Globals_int_type ){
/*529*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"`EXPR ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)" ...': found EXPR of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 66)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)", expected int", (STRING *) 1));
/*531*/ 		Operators_good = FALSE;
/*533*/ 	}
/*533*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 67) != Globals_int_type ){
/*534*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"`... ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" EXPR': found EXPR of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 68)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)", expected int", (STRING *) 1));
/*536*/ 		Operators_good = FALSE;
/*538*/ 	}
/*538*/ 	if( !Operators_good ){
/*539*/ 		return FALSE;
/*543*/ 	}
/*543*/ 	if( (((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 69) == NULL) || ((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 70) == NULL)) ){
/*544*/ 		return FALSE;
/*547*/ 	}
/*547*/ 	return TRUE;
/*551*/ }


/*552*/ RECORD *
/*552*/ Operators_EvalLShift(RECORD *Operators_a, RECORD *Operators_b)
/*552*/ {
/*554*/ 	RECORD * Operators_r = NULL;
/*554*/ 	Operators_r = (
/*554*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*554*/ 		push((char*) Globals_int_type),
/*554*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*554*/ 		push((char*) NULL),
/*555*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*555*/ 		(RECORD*) pop()
/*555*/ 	);
/*555*/ 	if( Operators_check_args_bit_binary_op((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"<<", Operators_a, Operators_b) ){
/*556*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 71) = m2runtime_itos(((unsigned int) m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 72)) << m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 73))));
/*558*/ 	}
/*558*/ 	return Operators_r;
/*562*/ }


/*563*/ RECORD *
/*563*/ Operators_EvalRShift(RECORD *Operators_a, RECORD *Operators_b)
/*563*/ {
/*565*/ 	RECORD * Operators_r = NULL;
/*565*/ 	Operators_r = (
/*565*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*565*/ 		push((char*) Globals_int_type),
/*565*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*565*/ 		push((char*) NULL),
/*566*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*566*/ 		(RECORD*) pop()
/*566*/ 	);
/*566*/ 	if( Operators_check_args_bit_binary_op((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"<<", Operators_a, Operators_b) ){
/*567*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 74) = m2runtime_itos(((unsigned int) m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 75)) >> m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 76))));
/*569*/ 	}
/*569*/ 	return Operators_r;
/*573*/ }


/*574*/ RECORD *
/*574*/ Operators_EvalBitNot(RECORD *Operators_r)
/*574*/ {
/*576*/ 	STRING * Operators_v = NULL;
/*576*/ 	if( Operators_r == NULL ){
/*578*/ 	} else if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 77), 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 78) == 3) ){
/*579*/ 		if( (STRING *)m2runtime_dereference_rhs_RECORD(Operators_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 79) != NULL ){
/*580*/ 			Operators_v = m2runtime_itos(~m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_r, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 80)));
/*583*/ 		}
/*583*/ 	} else {
/*583*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"invalid value of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 81)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)" for the bitwise not operator `~'", (STRING *) 1));
/*586*/ 	}
/*586*/ 	return (
/*586*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*586*/ 		push((char*) Globals_int_type),
/*586*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*586*/ 		push((char*) Operators_v),
/*587*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*588*/ 		(RECORD*) pop()
/*588*/ 	);
/*590*/ }


/*591*/ RECORD *
/*591*/ Operators_EvalBitAnd(RECORD *Operators_a, RECORD *Operators_b)
/*591*/ {
/*593*/ 	RECORD * Operators_r = NULL;
/*593*/ 	Operators_r = (
/*593*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*593*/ 		push((char*) Globals_int_type),
/*593*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*593*/ 		push((char*) NULL),
/*594*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*594*/ 		(RECORD*) pop()
/*594*/ 	);
/*594*/ 	if( Operators_check_args_bit_binary_op(m2runtime_CHR(38), Operators_a, Operators_b) ){
/*595*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 82) = m2runtime_itos((m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 83)) & m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 84))));
/*597*/ 	}
/*597*/ 	return Operators_r;
/*601*/ }


/*602*/ RECORD *
/*602*/ Operators_EvalBitXor(RECORD *Operators_a, RECORD *Operators_b)
/*602*/ {
/*604*/ 	RECORD * Operators_r = NULL;
/*604*/ 	Operators_r = (
/*604*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*604*/ 		push((char*) Globals_int_type),
/*604*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*604*/ 		push((char*) NULL),
/*605*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*605*/ 		(RECORD*) pop()
/*605*/ 	);
/*605*/ 	if( Operators_check_args_bit_binary_op(m2runtime_CHR(94), Operators_a, Operators_b) ){
/*606*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 85) = m2runtime_itos((m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 86)) ^ m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 87))));
/*608*/ 	}
/*608*/ 	return Operators_r;
/*612*/ }


/*613*/ RECORD *
/*613*/ Operators_EvalBitOr(RECORD *Operators_a, RECORD *Operators_b)
/*613*/ {
/*615*/ 	RECORD * Operators_r = NULL;
/*615*/ 	Operators_r = (
/*615*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*615*/ 		push((char*) Globals_int_type),
/*615*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*615*/ 		push((char*) NULL),
/*616*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*616*/ 		(RECORD*) pop()
/*616*/ 	);
/*616*/ 	if( Operators_check_args_bit_binary_op(m2runtime_CHR(124), Operators_a, Operators_b) ){
/*617*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 88) = m2runtime_itos((m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 89)) | m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 90))));
/*619*/ 	}
/*619*/ 	return Operators_r;
/*623*/ }


/*627*/ RECORD *
/*627*/ Operators_EvalCmp(STRING *Operators_n, RECORD *Operators_a, RECORD *Operators_b)
/*627*/ {
/*627*/ 	RECORD * Operators_r = NULL;
/*627*/ 	RECORD * Operators_bt = NULL;
/*627*/ 	RECORD * Operators_at = NULL;
/*627*/ 	STRING * Operators_rv = NULL;
/*627*/ 	STRING * Operators_bv = NULL;
/*627*/ 	STRING * Operators_av = NULL;
/*629*/ 	int Operators_x = 0;

/*631*/ 	void
/*631*/ 	Operators_W(STRING *Operators_s)
/*631*/ 	{
/*631*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"comparing (", Types_TypeToString(Operators_at), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)") ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" (", Types_TypeToString(Operators_bt), m2runtime_CHR(41), Operators_s, (STRING *) 1));
/*635*/ 	}


/*637*/ 	void
/*637*/ 	Operators_E(STRING *Operators_s)
/*637*/ 	{
/*637*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"comparing (", Types_TypeToString(Operators_at), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)") ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" (", Types_TypeToString(Operators_bt), m2runtime_CHR(41), Operators_s, (STRING *) 1));
/*642*/ 	}

/*642*/ 	Operators_r = (
/*642*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*642*/ 		push((char*) Globals_boolean_type),
/*642*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*642*/ 		push((char*) NULL),
/*643*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*645*/ 		(RECORD*) pop()
/*645*/ 	);
/*645*/ 	if( Operators_a != NULL ){
/*646*/ 		Operators_at = (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 91);
/*646*/ 		Operators_av = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 92);
/*648*/ 	}
/*648*/ 	if( Operators_b != NULL ){
/*649*/ 		Operators_bt = (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 93);
/*649*/ 		Operators_bv = (STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 94);
/*652*/ 	}
/*652*/ 	if( ((Operators_a == NULL) || (Operators_b == NULL)) ){
/*654*/ 		return Operators_r;
/*657*/ 	}
/*657*/ 	if( ((Operators_at == Globals_void_type) || (Operators_bt == Globals_void_type)) ){
/*658*/ 		Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)": `void' type cannot be compared");
/*660*/ 	} else if( ((Operators_at == Globals_mixed_type) || (Operators_bt == Globals_mixed_type)) ){
/*661*/ 		Operators_W((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\255,\0,\0,\0)": `mixed' type cannot be compared. Hint: check and convert mixed values to the appropriate type, or consider to use strict comparison operators === or !== if it is the case.");
/*663*/ 	} else if( Operators_at == Globals_boolean_type ){
/*664*/ 		if( Operators_bt == Globals_boolean_type ){
/*665*/ 			if( ((m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") != 0) && (m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") != 0)) ){
/*666*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)": invalid operator");
/*669*/ 			}
/*669*/ 		} else {
/*669*/ 			Operators_E(NULL);
/*671*/ 		}
/*671*/ 	} else if( Operators_at == Globals_int_type ){
/*672*/ 		if( Operators_bt == Globals_int_type ){
/*673*/ 		} else if( Operators_bt == Globals_float_type ){
/*674*/ 			Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\71,\0,\0,\0)" - Hint: you might use a typecast to (int) or to (float).");
/*676*/ 		} else {
/*676*/ 			Operators_E(NULL);
/*679*/ 		}
/*679*/ 	} else if( Operators_at == Globals_float_type ){
/*680*/ 		if( Operators_bt == Globals_int_type ){
/*681*/ 			Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\71,\0,\0,\0)" - Hint: you might use a typecast to (int) or to (float).");
/*682*/ 		} else if( Operators_bt == Globals_float_type ){
/*683*/ 			if( ((m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0) || (m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0)) ){
/*684*/ 				Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\71,\0,\0,\0)"comparison by equality/inequality between float numbers. ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\75,\0,\0,\0)"Remember that float numbers have limited precision, and that ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\71,\0,\0,\0)"expressions algebrically equivalent might give different ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"results. For example, 0.57-0.56==0.1 would give FALSE.", (STRING *) 1));
/*690*/ 			}
/*690*/ 		} else {
/*690*/ 			Operators_E(NULL);
/*693*/ 		}
/*693*/ 	} else if( Operators_at == Globals_null_type ){
/*694*/ 		if( Operators_bt == Globals_null_type ){
/*695*/ 			Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)": useless");
/*696*/ 		} else if( Operators_bt == Globals_string_type ){
/*697*/ 			if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*698*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `===' instead.");
/*699*/ 			} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0 ){
/*700*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `!==' instead.");
/*702*/ 			} else {
/*702*/ 				Operators_E(NULL);
/*704*/ 			}
/*704*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_bt, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 95) == 6) ){
/*705*/ 			if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*706*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `===' instead.");
/*707*/ 			} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0 ){
/*708*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `!==' instead.");
/*710*/ 			} else {
/*710*/ 				Operators_E(NULL);
/*712*/ 			}
/*712*/ 		} else if( Operators_bt == Globals_resource_type ){
/*713*/ 			if( ((m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") != 0) && (m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") != 0)) ){
/*714*/ 				Operators_E(NULL);
/*717*/ 			}
/*717*/ 		} else {
/*717*/ 			return Operators_EvalCmp(Operators_n, Operators_b, Operators_a);
/*720*/ 		}
/*720*/ 	} else if( Operators_at == Globals_string_type ){
/*721*/ 		if( Operators_bt == Globals_null_type ){
/*722*/ 			if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*723*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `===' instead.");
/*724*/ 			} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0 ){
/*725*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `!==' instead.");
/*727*/ 			} else {
/*727*/ 				Operators_E(NULL);
/*729*/ 			}
/*729*/ 		} else if( Operators_bt == Globals_string_type ){
/*730*/ 			if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*731*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `===' instead.");
/*732*/ 			} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"===") == 0 ){
/*733*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `!==' instead.");
/*734*/ 			} else if( ((m2runtime_strcmp(Operators_n, m2runtime_CHR(60)) == 0) || (m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"<=") == 0) || (m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">=") == 0) || (m2runtime_strcmp(Operators_n, m2runtime_CHR(62)) == 0)) ){
/*735*/ 				Operators_E(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)" - Hint: use safer comparison function strcmp(...) ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)" 0 instead.", (STRING *) 1));
/*739*/ 			}
/*739*/ 		} else {
/*739*/ 			Operators_E(NULL);
/*742*/ 		}
/*742*/ 	} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_at, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 96) == 6) ){
/*743*/ 		if( Operators_bt == Globals_null_type ){
/*744*/ 			if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*745*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `===' instead.");
/*746*/ 			} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0 ){
/*747*/ 				Operators_E((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `!==' instead.");
/*749*/ 			} else {
/*749*/ 				Operators_E(NULL);
/*752*/ 			}
/*752*/ 		} else {
/*752*/ 			Operators_E(NULL);
/*755*/ 		}
/*755*/ 	} else if( Operators_at == Globals_resource_type ){
/*756*/ 		if( Operators_bt == Globals_null_type ){
/*757*/ 			if( ((m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") != 0) && (m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") != 0)) ){
/*758*/ 				Operators_E(NULL);
/*760*/ 			}
/*760*/ 		} else if( Operators_bt == Globals_resource_type ){
/*761*/ 			if( ((m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") != 0) && (m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") != 0)) ){
/*762*/ 				Operators_E(NULL);
/*765*/ 			}
/*765*/ 		} else {
/*765*/ 			Operators_E(NULL);
/*768*/ 		}
/*768*/ 	} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_at, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 97) == 9) ){
/*769*/ 		if( Operators_bt == Globals_null_type ){
/*770*/ 			if( ((m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") != 0) && (m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") != 0)) ){
/*771*/ 				Operators_E(NULL);
/*773*/ 			}
/*773*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Operators_bt, 2 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 98) == 9) ){
/*774*/ 			if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*775*/ 				Operators_W((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `===' instead.");
/*776*/ 			} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0 ){
/*777*/ 				Operators_W((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" - Hint: use strict comparison operator `!==' instead.");
/*779*/ 			} else {
/*779*/ 				Operators_E(NULL);
/*782*/ 			}
/*782*/ 		} else {
/*782*/ 			Operators_E(NULL);
/*786*/ 		}
/*786*/ 	} else {
/*786*/ 		m2runtime_HALT(Operators_0err_entry_get, 99, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"unexpected types");
/*792*/ 	}
/*792*/ 	if( ((Operators_av == NULL) || (Operators_bv == NULL)) ){
/*793*/ 		return Operators_r;
/*795*/ 	}
/*795*/ 	if( ((Operators_at == Globals_int_type) && (Operators_bt == Globals_int_type)) ){
/*796*/ 		if( m2runtime_strcmp(Operators_n, m2runtime_CHR(60)) == 0 ){
/*797*/ 			Operators_x = (m2_stoi(Operators_av) < m2_stoi(Operators_bv));
/*798*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"<=") == 0 ){
/*799*/ 			Operators_x = (m2_stoi(Operators_av) <= m2_stoi(Operators_bv));
/*800*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*801*/ 			Operators_x = (m2_stoi(Operators_av) == m2_stoi(Operators_bv));
/*802*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0 ){
/*803*/ 			Operators_x = (m2_stoi(Operators_av) != m2_stoi(Operators_bv));
/*804*/ 		} else if( m2runtime_strcmp(Operators_n, m2runtime_CHR(62)) == 0 ){
/*805*/ 			Operators_x = (m2_stoi(Operators_av) > m2_stoi(Operators_bv));
/*806*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">=") == 0 ){
/*807*/ 			Operators_x = (m2_stoi(Operators_av) >= m2_stoi(Operators_bv));
/*809*/ 		}
/*809*/ 		if( Operators_x ){
/*810*/ 			Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*812*/ 		} else {
/*812*/ 			Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*814*/ 		}
/*814*/ 	} else if( (((Operators_at == Globals_int_type) && (Operators_bt == Globals_float_type)) || ((Operators_at == Globals_float_type) && (Operators_bt == Globals_int_type))) ){
/*816*/ 		if( m2runtime_strcmp(Operators_n, m2runtime_CHR(60)) == 0 ){
/*817*/ 			Operators_x = (m2_stor(Operators_av) < m2_stor(Operators_bv));
/*818*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"<=") == 0 ){
/*819*/ 			Operators_x = (m2_stor(Operators_av) <= m2_stor(Operators_bv));
/*820*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*821*/ 			return Operators_r;
/*822*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0 ){
/*823*/ 			return Operators_r;
/*824*/ 		} else if( m2runtime_strcmp(Operators_n, m2runtime_CHR(62)) == 0 ){
/*825*/ 			Operators_x = (m2_stor(Operators_av) > m2_stor(Operators_bv));
/*826*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">=") == 0 ){
/*827*/ 			Operators_x = (m2_stor(Operators_av) >= m2_stor(Operators_bv));
/*829*/ 		}
/*829*/ 		if( Operators_x ){
/*830*/ 			Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*832*/ 		} else {
/*832*/ 			Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*834*/ 		}
/*834*/ 	} else if( ((Operators_at == Globals_float_type) && (Operators_bt == Globals_float_type)) ){
/*835*/ 		if( m2runtime_strcmp(Operators_n, m2runtime_CHR(60)) == 0 ){
/*836*/ 			Operators_x = (m2_stor(Operators_av) < m2_stor(Operators_bv));
/*837*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"<=") == 0 ){
/*838*/ 			Operators_x = (m2_stor(Operators_av) <= m2_stor(Operators_bv));
/*839*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==") == 0 ){
/*840*/ 			return Operators_r;
/*841*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=") == 0 ){
/*842*/ 			return Operators_r;
/*843*/ 		} else if( m2runtime_strcmp(Operators_n, m2runtime_CHR(62)) == 0 ){
/*844*/ 			Operators_x = (m2_stor(Operators_av) > m2_stor(Operators_bv));
/*845*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">=") == 0 ){
/*846*/ 			Operators_x = (m2_stor(Operators_av) >= m2_stor(Operators_bv));
/*848*/ 		}
/*848*/ 		if( Operators_x ){
/*849*/ 			Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*851*/ 		} else {
/*851*/ 			Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*853*/ 		}
/*853*/ 	} else if( ((Operators_at == Globals_string_type) && (Operators_bt == Globals_string_type)) ){
/*854*/ 		if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"===") == 0 ){
/*855*/ 			if( m2runtime_strcmp(Operators_av, Operators_bv) == 0 ){
/*856*/ 				Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*858*/ 			} else {
/*858*/ 				Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*860*/ 			}
/*860*/ 		} else if( m2runtime_strcmp(Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"!==") == 0 ){
/*861*/ 			if( m2runtime_strcmp(Operators_av, Operators_bv) != 0 ){
/*862*/ 				Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*864*/ 			} else {
/*864*/ 				Operators_rv = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*867*/ 			}
/*868*/ 		}
/*869*/ 	}
/*869*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 100) = Operators_rv;
/*870*/ 	return Operators_r;
/*874*/ }


/*876*/ RECORD *
/*876*/ Operators_EvalEq(STRING *Operators_n, RECORD *Operators_a, RECORD *Operators_b)
/*876*/ {
/*876*/ 	return Operators_EvalCmp(Operators_n, Operators_a, Operators_b);
/*880*/ }


/*882*/ void
/*882*/ Operators_RequireBoolean(STRING *Operators_where, RECORD *Operators_r)
/*882*/ {
/*882*/ 	if( Operators_r == NULL ){
/*883*/ 		Scanner_Warning(m2runtime_concat_STRING(0, Operators_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)": undefined type of the expression", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" - expected a boolean value", (STRING *) 1));
/*885*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 101) == Globals_mixed_type ){
/*886*/ 		Scanner_Warning(m2runtime_concat_STRING(0, Operators_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)": found a value of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 102)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" - expected a boolean value", (STRING *) 1));
/*888*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 103) != Globals_boolean_type ){
/*889*/ 		Scanner_Error(m2runtime_concat_STRING(0, Operators_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)": found a value of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_r, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 104)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" - expected a boolean value", (STRING *) 1));
/*893*/ 	}
/*895*/ }


/*897*/ RECORD *
/*897*/ Operators_EvalAnd(STRING *Operators_n, RECORD *Operators_a, RECORD *Operators_b)
/*897*/ {
/*899*/ 	RECORD * Operators_r = NULL;
/*899*/ 	Operators_r = (
/*899*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*899*/ 		push((char*) Globals_boolean_type),
/*899*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*899*/ 		push((char*) NULL),
/*900*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*900*/ 		(RECORD*) pop()
/*900*/ 	);
/*900*/ 	if( ((Operators_a == NULL) || (Operators_b == NULL)) ){
/*901*/ 		return Operators_r;
/*903*/ 	}
/*903*/ 	Operators_RequireBoolean(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"`EXPR ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" ...'", (STRING *) 1), Operators_a);
/*904*/ 	Operators_RequireBoolean(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"`... ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)" EXPR'", (STRING *) 1), Operators_b);
/*905*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 105) != Globals_boolean_type) || ((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 106) != Globals_boolean_type)) ){
/*906*/ 		return Operators_r;
/*908*/ 	}
/*908*/ 	if( (((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 107) == NULL) || ((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 108) == NULL)) ){
/*909*/ 		return Operators_r;
/*911*/ 	}
/*911*/ 	if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 109), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE") == 0) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 110), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE") == 0)) ){
/*912*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 111) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*914*/ 	} else {
/*914*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 112) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*916*/ 	}
/*916*/ 	return Operators_r;
/*920*/ }


/*922*/ RECORD *
/*922*/ Operators_EvalOr(STRING *Operators_n, RECORD *Operators_a, RECORD *Operators_b)
/*922*/ {
/*924*/ 	RECORD * Operators_r = NULL;
/*924*/ 	Operators_r = (
/*924*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*924*/ 		push((char*) Globals_boolean_type),
/*924*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*924*/ 		push((char*) NULL),
/*925*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*925*/ 		(RECORD*) pop()
/*925*/ 	);
/*925*/ 	if( ((Operators_a == NULL) || (Operators_b == NULL)) ){
/*926*/ 		return Operators_r;
/*928*/ 	}
/*928*/ 	Operators_RequireBoolean(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"`EXPR ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" ...'", (STRING *) 1), Operators_a);
/*929*/ 	Operators_RequireBoolean(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"`... ", Operators_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)" EXPR' operator", (STRING *) 1), Operators_b);
/*930*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 113) != Globals_boolean_type) || ((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 114) != Globals_boolean_type)) ){
/*931*/ 		return Operators_r;
/*933*/ 	}
/*933*/ 	if( (((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 115) == NULL) || ((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 116) == NULL)) ){
/*934*/ 		return Operators_r;
/*936*/ 	}
/*936*/ 	if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 117), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE") == 0) || (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 118), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE") == 0)) ){
/*937*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 119) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*939*/ 	} else {
/*939*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 120) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*941*/ 	}
/*941*/ 	return Operators_r;
/*945*/ }


/*946*/ RECORD *
/*946*/ Operators_EvalXor(RECORD *Operators_a, RECORD *Operators_b)
/*946*/ {
/*948*/ 	RECORD * Operators_r = NULL;
/*948*/ 	Operators_r = (
/*948*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*948*/ 		push((char*) Globals_boolean_type),
/*948*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*948*/ 		push((char*) NULL),
/*949*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*949*/ 		(RECORD*) pop()
/*949*/ 	);
/*949*/ 	if( ((Operators_a == NULL) || (Operators_b == NULL)) ){
/*950*/ 		return Operators_r;
/*952*/ 	}
/*952*/ 	Operators_RequireBoolean((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"`EXPR xor ...'", Operators_a);
/*953*/ 	Operators_RequireBoolean((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"`... xor EXPR'", Operators_b);
/*954*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_a, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 121) != Globals_boolean_type) || ((RECORD *)m2runtime_dereference_rhs_RECORD(Operators_b, 0 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 122) != Globals_boolean_type)) ){
/*955*/ 		return Operators_r;
/*957*/ 	}
/*957*/ 	if( (((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 123) == NULL) || ((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 124) == NULL)) ){
/*958*/ 		return Operators_r;
/*960*/ 	}
/*960*/ 	if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_a, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 125), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE") == 0) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Operators_b, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 126), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE") == 0)) ){
/*961*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 127) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE";
/*963*/ 	} else {
/*963*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Operators_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Operators_0err_entry_get, 128) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE";
/*965*/ 	}
/*965*/ 	return Operators_r;
/*969*/ }


char * Operators_0func[] = {
    "invalid",
    "EvalValueConversion",
    "invalid",
    "EvalFormalTypecastArray",
    "EvalTypeConversion",
    "eval_res_type",
    "EvalPeriod",
    "EvalNot",
    "EvalUnaryPlusMinus",
    "check_args_bit_binary_op",
    "EvalLShift",
    "EvalRShift",
    "EvalBitNot",
    "EvalBitAnd",
    "EvalBitXor",
    "EvalBitOr",
    "EvalCmp",
    "RequireBoolean",
    "EvalAnd",
    "EvalOr",
    "EvalXor"
};

int Operators_0err_entry[] = {
    0 /* invalid */, 36,
    1 /* EvalValueConversion */, 51,
    1 /* EvalValueConversion */, 56,
    1 /* EvalValueConversion */, 59,
    1 /* EvalValueConversion */, 60,
    1 /* EvalValueConversion */, 62,
    1 /* EvalValueConversion */, 72,
    1 /* EvalValueConversion */, 79,
    1 /* EvalValueConversion */, 85,
    1 /* EvalValueConversion */, 91,
    1 /* EvalValueConversion */, 97,
    1 /* EvalValueConversion */, 98,
    1 /* EvalValueConversion */, 99,
    1 /* EvalValueConversion */, 111,
    2 /* invalid */, 130,
    3 /* EvalFormalTypecastArray */, 149,
    4 /* EvalTypeConversion */, 161,
    4 /* EvalTypeConversion */, 170,
    4 /* EvalTypeConversion */, 173,
    4 /* EvalTypeConversion */, 180,
    4 /* EvalTypeConversion */, 186,
    4 /* EvalTypeConversion */, 188,
    4 /* EvalTypeConversion */, 192,
    4 /* EvalTypeConversion */, 192,
    4 /* EvalTypeConversion */, 193,
    4 /* EvalTypeConversion */, 193,
    4 /* EvalTypeConversion */, 197,
    4 /* EvalTypeConversion */, 206,
    4 /* EvalTypeConversion */, 216,
    4 /* EvalTypeConversion */, 219,
    4 /* EvalTypeConversion */, 221,
    5 /* eval_res_type */, 244,
    5 /* eval_res_type */, 246,
    5 /* eval_res_type */, 248,
    5 /* eval_res_type */, 249,
    5 /* eval_res_type */, 254,
    5 /* eval_res_type */, 262,
    5 /* eval_res_type */, 264,
    5 /* eval_res_type */, 266,
    5 /* eval_res_type */, 267,
    5 /* eval_res_type */, 272,
    5 /* eval_res_type */, 289,
    5 /* eval_res_type */, 290,
    6 /* EvalPeriod */, 420,
    6 /* EvalPeriod */, 427,
    6 /* EvalPeriod */, 429,
    6 /* EvalPeriod */, 431,
    6 /* EvalPeriod */, 440,
    6 /* EvalPeriod */, 447,
    6 /* EvalPeriod */, 449,
    6 /* EvalPeriod */, 451,
    6 /* EvalPeriod */, 464,
    7 /* EvalNot */, 473,
    7 /* EvalNot */, 474,
    7 /* EvalNot */, 477,
    7 /* EvalNot */, 480,
    7 /* EvalNot */, 481,
    7 /* EvalNot */, 483,
    8 /* EvalUnaryPlusMinus */, 494,
    8 /* EvalUnaryPlusMinus */, 496,
    8 /* EvalUnaryPlusMinus */, 498,
    8 /* EvalUnaryPlusMinus */, 500,
    8 /* EvalUnaryPlusMinus */, 502,
    8 /* EvalUnaryPlusMinus */, 504,
    8 /* EvalUnaryPlusMinus */, 507,
    9 /* check_args_bit_binary_op */, 528,
    9 /* check_args_bit_binary_op */, 529,
    9 /* check_args_bit_binary_op */, 533,
    9 /* check_args_bit_binary_op */, 534,
    9 /* check_args_bit_binary_op */, 543,
    9 /* check_args_bit_binary_op */, 543,
    10 /* EvalLShift */, 556,
    10 /* EvalLShift */, 556,
    10 /* EvalLShift */, 556,
    11 /* EvalRShift */, 567,
    11 /* EvalRShift */, 567,
    11 /* EvalRShift */, 567,
    12 /* EvalBitNot */, 578,
    12 /* EvalBitNot */, 578,
    12 /* EvalBitNot */, 579,
    12 /* EvalBitNot */, 580,
    12 /* EvalBitNot */, 583,
    13 /* EvalBitAnd */, 595,
    13 /* EvalBitAnd */, 595,
    13 /* EvalBitAnd */, 595,
    14 /* EvalBitXor */, 606,
    14 /* EvalBitXor */, 606,
    14 /* EvalBitXor */, 606,
    15 /* EvalBitOr */, 617,
    15 /* EvalBitOr */, 617,
    15 /* EvalBitOr */, 617,
    16 /* EvalCmp */, 646,
    16 /* EvalCmp */, 646,
    16 /* EvalCmp */, 649,
    16 /* EvalCmp */, 649,
    16 /* EvalCmp */, 704,
    16 /* EvalCmp */, 742,
    16 /* EvalCmp */, 768,
    16 /* EvalCmp */, 773,
    16 /* EvalCmp */, 786,
    16 /* EvalCmp */, 869,
    17 /* RequireBoolean */, 885,
    17 /* RequireBoolean */, 886,
    17 /* RequireBoolean */, 888,
    17 /* RequireBoolean */, 889,
    18 /* EvalAnd */, 905,
    18 /* EvalAnd */, 905,
    18 /* EvalAnd */, 908,
    18 /* EvalAnd */, 908,
    18 /* EvalAnd */, 911,
    18 /* EvalAnd */, 911,
    18 /* EvalAnd */, 912,
    18 /* EvalAnd */, 914,
    19 /* EvalOr */, 930,
    19 /* EvalOr */, 930,
    19 /* EvalOr */, 933,
    19 /* EvalOr */, 933,
    19 /* EvalOr */, 936,
    19 /* EvalOr */, 936,
    19 /* EvalOr */, 937,
    19 /* EvalOr */, 939,
    20 /* EvalXor */, 954,
    20 /* EvalXor */, 954,
    20 /* EvalXor */, 957,
    20 /* EvalXor */, 957,
    20 /* EvalXor */, 960,
    20 /* EvalXor */, 960,
    20 /* EvalXor */, 961,
    20 /* EvalXor */, 963
};

void Operators_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Operators";
    *f = Operators_0func[ Operators_0err_entry[2*i] ];
    *l = Operators_0err_entry[2*i + 1];
}
