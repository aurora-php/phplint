/* IMPLEMENTATION MODULE Expressions */
#define M2_IMPORT_Expressions

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_Accounting
#    include "Accounting.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif

#ifndef M2_IMPORT_Errors
#    include "Errors.c"
#endif

#ifndef M2_IMPORT_Exceptions
#    include "Exceptions.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Operators
#    include "Operators.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Search
#    include "Search.c"
#endif

#ifndef M2_IMPORT_Typecast
#    include "Typecast.c"
#endif

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

void Expressions_0err_entry_get(int i, char **m, char **f, int *l);

/* 22*/ void
/* 22*/ Expressions_map_namespace_operator_into_id(void)
/* 22*/ {
/* 22*/ 	if( (Globals_php_ver == 4) ){
/* 23*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"using reserved keyword `namespace' (PHP 5)");
/* 25*/ 	}
/* 25*/ 	Scanner_ReadSym();
/* 26*/ 	Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"expected identifier");
/* 27*/ 	if( m2runtime_strcmp(m2runtime_substr(Scanner_s, 0, 0, 0, Expressions_0err_entry_get, 0), m2runtime_CHR(92)) != 0 ){
/* 28*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"expected path after namespace operator");
/* 30*/ 	}
/* 30*/ 	if( (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 1) != NULL ){
/* 31*/ 		Scanner_s = m2runtime_concat_STRING(0, m2runtime_CHR(92), (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 2), Scanner_s, (STRING *) 1);
/* 34*/ 	}
/* 36*/ }


/* 41*/ void
/* 41*/ Expressions_map_x_namespace_operator_into_id(void)
/* 41*/ {
/* 41*/ 	if( (Globals_php_ver == 4) ){
/* 42*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"using reserved keyword `namespace' (PHP 5)");
/* 44*/ 	}
/* 44*/ 	Scanner_ReadSym();
/* 45*/ 	Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"expected meta-code identifier");
/* 46*/ 	if( m2runtime_strcmp(m2runtime_substr(Scanner_s, 0, 0, 0, Expressions_0err_entry_get, 3), m2runtime_CHR(92)) != 0 ){
/* 47*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"expected path after namespace operator");
/* 49*/ 	}
/* 49*/ 	if( (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 4) != NULL ){
/* 50*/ 		Scanner_s = m2runtime_concat_STRING(0, m2runtime_CHR(92), (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 5), Scanner_s, (STRING *) 1);
/* 53*/ 	}
/* 55*/ }


/* 57*/ void
/* 57*/ Expressions_CleanCurrentScope(void)
/* 57*/ {
/* 58*/ 	int Expressions_i = 0;
/* 60*/ 	RECORD * Expressions_v = NULL;
/* 60*/ 	Expressions_i = (Globals_vars_n - 1);
/* 61*/ 	while( (((Expressions_i >= 0)) && (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Expressions_i, Expressions_0err_entry_get, 6), 7 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 7) == Globals_scope))) ){
/* 62*/ 		Expressions_v = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Expressions_i, Expressions_0err_entry_get, 8);
/* 63*/ 		if( (! *(int *)m2runtime_dereference_rhs_RECORD(Expressions_v, 7 * sizeof(void*) + 4 * sizeof(int), Expressions_0err_entry_get, 9) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_v, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 10) != NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_v, 7 * sizeof(void*) + 6 * sizeof(int), Expressions_0err_entry_get, 11) == 0))) ){
/* 64*/ 			Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_v, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 12), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_v, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 13), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"' assigned but never used", (STRING *) 1));
/* 66*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_v, 7 * sizeof(void*) + 4 * sizeof(int), Expressions_0err_entry_get, 14) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_v, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 15) == NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_v, 7 * sizeof(void*) + 6 * sizeof(int), Expressions_0err_entry_get, 16) == 0))) ){
/* 67*/ 			Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"in the last function, variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_v, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 17), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"' declared global but not used", (STRING *) 1));
/* 70*/ 		}
/* 70*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY(&Globals_vars, sizeof(void *), 1, Expressions_i, Expressions_0err_entry_get, 18) = NULL;
/* 71*/ 		m2_inc(&Expressions_i, -1);
/* 73*/ 	}
/* 73*/ 	Globals_vars_n = (Expressions_i + 1);
/* 82*/ }


/* 91*/ void
/* 91*/ Expressions_ResolveClassProperty(RECORD *Expressions_class, int Expressions_static, STRING *Expressions_id, RECORD **Expressions_P, RECORD **Expressions_p)
/* 91*/ {
/* 91*/ 	Search_SearchClassProperty(Expressions_class, Expressions_id, Expressions_P, Expressions_p);
/* 92*/ 	if( *Expressions_p == NULL ){
/* 93*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"property `", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 19), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", Expressions_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"' does not exist or not visible", (STRING *) 1));
/* 96*/ 		return ;
/* 97*/ 	}
/* 97*/ 	Accounting_AccountClassProperty(*Expressions_P, *Expressions_p);
/*100*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_p, 6 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 20)){

/*102*/ 	case 2:
/*105*/ 	break;

/*105*/ 	case 1:
/*106*/ 	if( ((Globals_curr_class == NULL) || !Classes_IsSubclassOf(Globals_curr_class, *Expressions_P)) ){
/*107*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"access forbidden to protected property `", Classes_pc(Expressions_class, *Expressions_P), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(*Expressions_p, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 21), m2runtime_CHR(39), (STRING *) 1));
/*111*/ 	}
/*111*/ 	break;

/*111*/ 	case 0:
/*114*/ 	if( Globals_curr_class != *Expressions_P ){
/*115*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"access forbidden to private property `", Classes_pc(Expressions_class, *Expressions_P), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(*Expressions_p, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 22), m2runtime_CHR(39), (STRING *) 1));
/*120*/ 	}
/*120*/ 	break;

/*120*/ 	default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 23);
/*122*/ 	}
/*122*/ 	if( Expressions_static ){
/*123*/ 		if( ! *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_p, 6 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 24) ){
/*124*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"static access to non-static property `", Classes_pc(Expressions_class, *Expressions_P), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(*Expressions_p, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 25), m2runtime_CHR(39), (STRING *) 1));
/*128*/ 		}
/*128*/ 	} else {
/*128*/ 		if(  *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_p, 6 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 26) ){
/*129*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"non-static access to static property `", Classes_pc(Expressions_class, *Expressions_P), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(*Expressions_p, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 27), m2runtime_CHR(39), (STRING *) 1));
/*133*/ 		}
/*134*/ 	}
/*136*/ }

 RECORD * Expressions_ParseExpr();

/*140*/ void
/*140*/ Expressions_SkipFuncCall(void)
/*140*/ {
/*142*/ 	RECORD * Expressions_r = NULL;
/*142*/ 	Scanner_ReadSym();
/*143*/ 	if( (Scanner_sym == 13) ){
/*144*/ 		Scanner_ReadSym();
/*146*/ 		return ;
/*148*/ 	}
/*148*/ 	do{
/*148*/ 		Expressions_r = Expressions_ParseExpr();
/*149*/ 		if( (Scanner_sym == 16) ){
/*150*/ 			Scanner_ReadSym();
/*151*/ 		} else if( (Scanner_sym == 13) ){
/*152*/ 			Scanner_ReadSym();
/*154*/ 			return ;
/*156*/ 		}
/*157*/ 	}while(TRUE);
/*159*/ }


/*167*/ void
/*167*/ Expressions_DereferenceClassMethod(RECORD *Expressions_class, int Expressions_static, STRING *Expressions_id, RECORD **Expressions_res_class, RECORD **Expressions_res_method)
/*167*/ {
/*168*/ 	RECORD * Expressions_M = NULL;
/*170*/ 	RECORD * Expressions_m = NULL;
/*171*/ 	Classes_ResolveClassMethod(Expressions_class, Expressions_id, &Expressions_M, &Expressions_m);
/*172*/ 	*Expressions_res_class = Expressions_M;
/*173*/ 	*Expressions_res_method = Expressions_m;
/*174*/ 	if( Expressions_m == NULL ){
/*175*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the method ", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 28), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Expressions_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"() does not exist", (STRING *) 1));
/*177*/ 		return ;
/*178*/ 	} else {
/*178*/ 		Accounting_AccountClassMethod(Expressions_M, Expressions_m);
/*179*/ 		Errors_RaiseErrors( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_m, 9 * sizeof(void*) + 9 * sizeof(int), Expressions_0err_entry_get, 29));
/*180*/ 		Exceptions_ThrowExceptions((ARRAY *)m2runtime_dereference_rhs_RECORD(Expressions_m, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 30));
/*184*/ 	}
/*184*/ 	if( ((Expressions_m == (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_M, 9 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 31)) && (((Globals_curr_class == NULL) || (Globals_curr_method != (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 32)) || !Classes_IsSubclassOf(Globals_curr_class, Expressions_M)))) ){
/*190*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the method ", Scanner_mn(Expressions_class, Expressions_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" is a class ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\104,\0,\0,\0)"constructor, it can be called explicity only inside the constructor ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"of an extending class", (STRING *) 1));
/*196*/ 	}
/*196*/ 	if( ((Expressions_m == (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_M, 9 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 33)) && (Globals_curr_class != NULL) && (Globals_curr_method == (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 34))) ){
/*200*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 8 * sizeof(int), Expressions_0err_entry_get, 35) = TRUE;
/*204*/ 	}
/*204*/ 	if( ((Expressions_m == (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_M, 11 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 36)) && (((Globals_curr_class == NULL) || (Globals_curr_method != (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 11 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 37)) || !Classes_IsSubclassOf(Globals_curr_class, Expressions_M)))) ){
/*210*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the method ", Scanner_mn(Expressions_class, Expressions_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" is a class ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\103,\0,\0,\0)"destructor, it can be called explicity only inside the constructor ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"of an extending class", (STRING *) 1));
/*216*/ 	}
/*216*/ 	if( ((Expressions_m == (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_M, 11 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 38)) && (Globals_curr_class != NULL) && (Globals_curr_method == (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 11 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 39))) ){
/*220*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 9 * sizeof(int), Expressions_0err_entry_get, 40) = TRUE;
/*224*/ 	}
/*224*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_m, 9 * sizeof(void*) + 4 * sizeof(int), Expressions_0err_entry_get, 41)){

/*225*/ 	case 2:
/*226*/ 	break;

/*226*/ 	case 1:
/*227*/ 	if( ((Globals_curr_class == NULL) || !Classes_IsSubclassOf(Globals_curr_class, Expressions_M)) ){
/*228*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"access forbidden to protected method ", Classes_pc(Expressions_class, Expressions_M), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_m, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 42), (STRING *) 1));
/*231*/ 	}
/*231*/ 	break;

/*231*/ 	case 0:
/*232*/ 	if( Globals_curr_class != Expressions_M ){
/*233*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"access forbidden to private method ", Classes_pc(Expressions_class, Expressions_M), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_m, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 43), (STRING *) 1));
/*237*/ 	}
/*237*/ 	break;

/*237*/ 	default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 44);
/*239*/ 	}
/*239*/ 	if( Expressions_static ){
/*240*/ 		if(  *(int *)m2runtime_dereference_rhs_RECORD(Expressions_m, 9 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 45) ){
/*241*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Expressions_m, 9 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 46) ){
/*242*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"cannot call abstract static method ", Scanner_mn(Expressions_M, Expressions_m), (STRING *) 1));
/*245*/ 			}
/*245*/ 		} else {
/*245*/ 			if( ((Globals_curr_method != NULL) && ! *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 9 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 47) && Classes_IsSubclassOf(Globals_curr_class, Expressions_M)) ){
/*249*/ 			} else {
/*249*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"static access to non-static method ", Classes_pc(Expressions_class, Expressions_M), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_m, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 48), (STRING *) 1));
/*253*/ 			}
/*254*/ 		}
/*254*/ 	} else {
/*254*/ 		if(  *(int *)m2runtime_dereference_rhs_RECORD(Expressions_m, 9 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 49) ){
/*255*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"non-static access to static method ", Classes_pc(Expressions_class, Expressions_M), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_m, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 50), (STRING *) 1));
/*259*/ 		}
/*261*/ 	}
/*263*/ }


/*281*/ RECORD *
/*281*/ Expressions_ParseType(int Expressions_allow_type_hinting)
/*281*/ {

/*286*/ 	RECORD *
/*286*/ 	Expressions_ParseTypeName(int Expressions_allow_type_hinting)
/*286*/ 	{
/*288*/ 		RECORD * Expressions_class = NULL;
/*288*/ 		if( (Globals_php_ver == 4) ){
/*289*/ 			Expressions_allow_type_hinting = FALSE;
/*292*/ 		}
/*292*/ 		if( (Scanner_sym == 127) ){
/*293*/ 			Expressions_map_namespace_operator_into_id();
/*294*/ 		} else if( (Scanner_sym == 180) ){
/*295*/ 			Expressions_map_x_namespace_operator_into_id();
/*298*/ 		}
/*298*/ 		switch(Scanner_sym){

/*299*/ 		case 144:
/*299*/ 		Scanner_ReadSym();
/*299*/ 		return Globals_void_type;
/*300*/ 		break;

/*300*/ 		case 145:
/*300*/ 		Scanner_ReadSym();
/*300*/ 		return Globals_boolean_type;
/*301*/ 		break;

/*301*/ 		case 146:
/*301*/ 		Scanner_ReadSym();
/*301*/ 		return Globals_int_type;
/*302*/ 		break;

/*302*/ 		case 147:
/*302*/ 		Scanner_ReadSym();
/*302*/ 		return Globals_float_type;
/*303*/ 		break;

/*303*/ 		case 148:
/*303*/ 		Scanner_ReadSym();
/*303*/ 		return Globals_string_type;
/*304*/ 		break;

/*304*/ 		case 150:
/*304*/ 		Scanner_ReadSym();
/*304*/ 		return Globals_mixed_type;
/*305*/ 		break;

/*305*/ 		case 151:
/*305*/ 		Scanner_ReadSym();
/*305*/ 		return Globals_resource_type;
/*306*/ 		break;

/*306*/ 		case 152:
/*306*/ 		Scanner_ReadSym();
/*306*/ 		return Globals_object_type;
/*307*/ 		break;

/*307*/ 		case 71:
/*308*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\111,\0,\0,\0)"`object' keyword not allowed as type, allowed only as typecast `(object)'");
/*309*/ 		if( !Expressions_allow_type_hinting ){
/*310*/ 			return NULL;
/*312*/ 		}
/*312*/ 		Scanner_ReadSym();
/*313*/ 		return Globals_object_type;
/*314*/ 		break;

/*314*/ 		case 153:
/*315*/ 		Expressions_class = Search_SearchClass(Scanner_s);
/*316*/ 		if( Expressions_class == NULL ){
/*317*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"undefined identifier `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*318*/ 			Scanner_ReadSym();
/*319*/ 			return NULL;
/*321*/ 		} else {
/*321*/ 			Accounting_AccountClass(Expressions_class);
/*322*/ 			Scanner_ReadSym();
/*323*/ 			return (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_class, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 51);
/*325*/ 		}
/*325*/ 		break;

/*325*/ 		case 29:
/*326*/ 		if( !Expressions_allow_type_hinting ){
/*327*/ 			return NULL;
/*329*/ 		}
/*329*/ 		Expressions_class = Search_SearchClass(Scanner_s);
/*330*/ 		if( Expressions_class == NULL ){
/*331*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"undefined identifier `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*332*/ 			Scanner_ReadSym();
/*333*/ 			return NULL;
/*335*/ 		} else {
/*335*/ 			Scanner_ReadSym();
/*336*/ 			return (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_class, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 52);
/*338*/ 		}
/*338*/ 		break;

/*338*/ 		case 103:
/*338*/ 		case 176:
/*339*/ 		if( (((Scanner_sym == 103)) && !Expressions_allow_type_hinting) ){
/*340*/ 			return NULL;
/*342*/ 		}
/*342*/ 		if( Globals_curr_class == NULL ){
/*343*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"`self': not inside a class");
/*344*/ 			return NULL;
/*346*/ 		}
/*346*/ 		Scanner_ReadSym();
/*347*/ 		return (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 53);
/*348*/ 		break;

/*348*/ 		case 104:
/*348*/ 		case 177:
/*349*/ 		if( (((Scanner_sym == 104)) && !Expressions_allow_type_hinting) ){
/*350*/ 			return NULL;
/*352*/ 		}
/*352*/ 		if( Globals_curr_class == NULL ){
/*353*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"`parent': not inside a class");
/*354*/ 			return NULL;
/*356*/ 		}
/*356*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 54) == NULL ){
/*357*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"`parent': no parent class");
/*358*/ 			return NULL;
/*360*/ 		}
/*360*/ 		Scanner_ReadSym();
/*361*/ 		return (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 55), 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 56);
/*363*/ 		break;

/*363*/ 		default:
/*363*/ 		return NULL;
/*366*/ 		}
/*366*/ 		m2runtime_missing_return(Expressions_0err_entry_get, 57);
/*366*/ 		return NULL;
/*368*/ 	}


/*374*/ 	RECORD *
/*374*/ 	Expressions_ParseArray(void)
/*374*/ 	{
/*376*/ 		RECORD * Expressions_a = NULL;
/*376*/ 		Scanner_ReadSym();
/*377*/ 		Expressions_a = (
/*377*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*377*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*377*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 7,
/*377*/ 			push((char*) NULL),
/*377*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*377*/ 			push((char*) NULL),
/*378*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*378*/ 			(RECORD*) pop()
/*378*/ 		);
/*378*/ 		if( (Scanner_sym == 146) ){
/*379*/ 			Scanner_ReadSym();
/*380*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 58) = 3;
/*381*/ 		} else if( (Scanner_sym == 148) ){
/*382*/ 			Scanner_ReadSym();
/*383*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 59) = 5;
/*384*/ 		} else if( (Scanner_sym == 160) ){
/*385*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 60) = 7;
/*387*/ 		} else {
/*387*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"expected `[]' or `[int]' or `[string]'");
/*388*/ 			return NULL;
/*390*/ 		}
/*390*/ 		Scanner_Expect(160, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*391*/ 		Scanner_ReadSym();
/*392*/ 		if( (Scanner_sym == 159) ){
/*393*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 61) = Expressions_ParseArray();
/*394*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 62) == NULL ){
/*395*/ 				return NULL;
/*398*/ 			}
/*398*/ 		} else {
/*398*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 63) = Expressions_ParseTypeName(FALSE);
/*399*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 64) == NULL ){
/*400*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 65) = Globals_mixed_type;
/*403*/ 			}
/*403*/ 		}
/*403*/ 		return Expressions_a;
/*407*/ 	}


/*414*/ 	RECORD *
/*414*/ 	Expressions_ParseIndeces(RECORD *Expressions_t)
/*414*/ 	{
/*416*/ 		RECORD * Expressions_a = NULL;
/*416*/ 		Expressions_a = (
/*416*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*416*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*416*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*416*/ 			push((char*) NULL),
/*416*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*416*/ 			push((char*) NULL),
/*417*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*417*/ 			(RECORD*) pop()
/*417*/ 		);
/*417*/ 		Scanner_ReadSym();
/*418*/ 		if( (Scanner_sym == 146) ){
/*419*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 66) = 3;
/*420*/ 			Scanner_ReadSym();
/*421*/ 		} else if( (Scanner_sym == 148) ){
/*422*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 67) = 5;
/*423*/ 			Scanner_ReadSym();
/*424*/ 		} else if( (Scanner_sym == 160) ){
/*425*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 68) = 7;
/*427*/ 		}
/*427*/ 		Scanner_Expect(160, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*428*/ 		Scanner_ReadSym();
/*429*/ 		if( (Scanner_sym == 159) ){
/*430*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 69) = Expressions_ParseIndeces(Expressions_t);
/*431*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 70) == NULL ){
/*432*/ 				return NULL;
/*435*/ 			}
/*435*/ 		} else {
/*435*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 71) = Expressions_t;
/*437*/ 		}
/*437*/ 		return Expressions_a;
/*442*/ 	}

/*444*/ 	RECORD * Expressions_t = NULL;
/*444*/ 	if( (((Scanner_sym == 149)) || ((Scanner_sym == 70))) ){
/*446*/ 		if( (((Scanner_sym == 70)) && !Expressions_allow_type_hinting) ){
/*447*/ 			return NULL;
/*449*/ 		}
/*449*/ 		Scanner_ReadSym();
/*450*/ 		if( (Scanner_sym != 159) ){
/*452*/ 			return (
/*452*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*452*/ 				*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*452*/ 				*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 7,
/*452*/ 				push((char*) Globals_mixed_type),
/*452*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*452*/ 				push((char*) NULL),
/*453*/ 				*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*454*/ 				(RECORD*) pop()
/*454*/ 			);
/*454*/ 		}
/*454*/ 		return Expressions_ParseArray();
/*457*/ 	} else {
/*457*/ 		Expressions_t = Expressions_ParseTypeName(Expressions_allow_type_hinting);
/*458*/ 		if( Expressions_t == NULL ){
/*459*/ 			return NULL;
/*461*/ 		}
/*461*/ 		if( (Scanner_sym == 159) ){
/*462*/ 			Expressions_t = Expressions_ParseIndeces(Expressions_t);
/*464*/ 		}
/*464*/ 		return Expressions_t;
/*467*/ 	}
/*467*/ 	m2runtime_missing_return(Expressions_0err_entry_get, 72);
/*467*/ 	return NULL;
/*470*/ }


/*472*/ int
/*472*/ Expressions_LhsMatchRhs(RECORD *Expressions_lhs, RECORD *Expressions_rhs)
/*472*/ {

/*474*/ 	int
/*474*/ 	Expressions_MatchArray(int Expressions_li, RECORD *Expressions_le, int Expressions_ri, RECORD *Expressions_re)
/*474*/ 	{
/*476*/ 		int Expressions_idx = 0;
/*477*/ 		Expressions_idx = 0;
/*478*/ 		switch(Expressions_li){

/*479*/ 		case 1:
/*480*/ 		break;

/*480*/ 		case 3:
/*481*/ 		switch(Expressions_ri){

/*482*/ 		case 1:
/*482*/ 		Expressions_idx = 1;
/*483*/ 		break;

/*483*/ 		case 3:
/*483*/ 		Expressions_idx = 0;
/*484*/ 		break;

/*484*/ 		case 5:
/*484*/ 		return 2;
/*485*/ 		break;

/*485*/ 		case 7:
/*485*/ 		return 2;
/*487*/ 		break;

/*487*/ 		default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 73);
/*487*/ 		}
/*487*/ 		break;

/*487*/ 		case 5:
/*488*/ 		switch(Expressions_ri){

/*489*/ 		case 1:
/*489*/ 		Expressions_idx = 1;
/*490*/ 		break;

/*490*/ 		case 3:
/*490*/ 		return 2;
/*491*/ 		break;

/*491*/ 		case 5:
/*491*/ 		Expressions_idx = 0;
/*492*/ 		break;

/*492*/ 		case 7:
/*492*/ 		return 2;
/*494*/ 		break;

/*494*/ 		default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 74);
/*494*/ 		}
/*494*/ 		break;

/*494*/ 		case 7:
/*495*/ 		Expressions_idx = 0;
/*497*/ 		break;

/*497*/ 		default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 75);
/*499*/ 		}
/*499*/ 		if( Expressions_le == NULL ){
/*500*/ 			return m2_max(Expressions_idx, 0);
/*501*/ 		} else if( Expressions_re == NULL ){
/*502*/ 			return m2_max(Expressions_idx, 1);
/*504*/ 		} else {
/*504*/ 			return m2_max(Expressions_idx, Expressions_LhsMatchRhs(Expressions_le, Expressions_re));
/*507*/ 		}
/*507*/ 		m2runtime_missing_return(Expressions_0err_entry_get, 76);
/*507*/ 		return 0;
/*509*/ 	}

/*509*/ 	if( Expressions_lhs == NULL ){
/*510*/ 		if( ((Expressions_rhs != NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 77) == 1))) ){
/*511*/ 			return 2;
/*513*/ 		} else {
/*513*/ 			return 1;
/*516*/ 		}
/*516*/ 	}
/*516*/ 	if( Expressions_rhs == NULL ){
/*517*/ 		if( ((Expressions_lhs != NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_lhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 78) == 1))) ){
/*518*/ 			return 2;
/*520*/ 		} else {
/*520*/ 			return 1;
/*523*/ 		}
/*523*/ 	}
/*523*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_lhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 79)){

/*524*/ 	case 0:
/*525*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 80)){

/*526*/ 	case 0:
/*526*/ 	return 0;
/*527*/ 	break;

/*527*/ 	case 5:
/*527*/ 	case 6:
/*527*/ 	case 7:
/*527*/ 	case 8:
/*527*/ 	case 9:
/*527*/ 	return 1;
/*528*/ 	break;

/*528*/ 	default:
/*528*/ 	return 2;
/*530*/ 	}
/*530*/ 	break;

/*530*/ 	case 1:
/*530*/ 	return 2;
/*531*/ 	break;

/*531*/ 	case 2:
/*532*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 81)){

/*533*/ 	case 2:
/*533*/ 	return 0;
/*534*/ 	break;

/*534*/ 	case 7:
/*534*/ 	return 1;
/*535*/ 	break;

/*535*/ 	default:
/*535*/ 	return 2;
/*537*/ 	}
/*537*/ 	break;

/*537*/ 	case 3:
/*538*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 82)){

/*539*/ 	case 3:
/*539*/ 	return 0;
/*540*/ 	break;

/*540*/ 	case 7:
/*540*/ 	return 1;
/*541*/ 	break;

/*541*/ 	default:
/*541*/ 	return 2;
/*543*/ 	}
/*543*/ 	break;

/*543*/ 	case 4:
/*544*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 83)){

/*545*/ 	case 3:
/*545*/ 	case 4:
/*545*/ 	return 0;
/*546*/ 	break;

/*546*/ 	case 7:
/*546*/ 	return 1;
/*547*/ 	break;

/*547*/ 	default:
/*547*/ 	return 2;
/*549*/ 	}
/*549*/ 	break;

/*549*/ 	case 5:
/*550*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 84)){

/*551*/ 	case 0:
/*551*/ 	case 5:
/*551*/ 	return 0;
/*552*/ 	break;

/*552*/ 	case 7:
/*552*/ 	return 1;
/*553*/ 	break;

/*553*/ 	default:
/*553*/ 	return 2;
/*555*/ 	}
/*555*/ 	break;

/*555*/ 	case 6:
/*556*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 85)){

/*557*/ 	case 0:
/*557*/ 	return 0;
/*558*/ 	break;

/*558*/ 	case 7:
/*558*/ 	return 1;
/*559*/ 	break;

/*559*/ 	case 6:
/*559*/ 	return Expressions_MatchArray( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_lhs, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 86), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_lhs, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 87),  *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 88), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 89));
/*561*/ 	break;

/*561*/ 	default:
/*561*/ 	return 2;
/*563*/ 	}
/*563*/ 	break;

/*563*/ 	case 7:
/*564*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 90) == 1) ){
/*565*/ 		return 2;
/*567*/ 	} else {
/*567*/ 		return 0;
/*569*/ 	}
/*569*/ 	break;

/*569*/ 	case 8:
/*570*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 91)){

/*571*/ 	case 0:
/*571*/ 	case 8:
/*571*/ 	return 0;
/*572*/ 	break;

/*572*/ 	case 7:
/*572*/ 	return 1;
/*573*/ 	break;

/*573*/ 	default:
/*573*/ 	return 2;
/*575*/ 	}
/*575*/ 	break;

/*575*/ 	case 9:
/*576*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 92)){

/*577*/ 	case 0:
/*577*/ 	return 0;
/*578*/ 	break;

/*578*/ 	case 7:
/*578*/ 	return 1;
/*579*/ 	break;

/*579*/ 	case 9:
/*580*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_lhs, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 93) == NULL ){
/*581*/ 		return 0;
/*582*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 94) == NULL ){
/*583*/ 		return 1;
/*584*/ 	} else if( Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_rhs, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 95), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_lhs, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 96)) ){
/*585*/ 		return 0;
/*587*/ 	} else {
/*587*/ 		return 2;
/*589*/ 	}
/*589*/ 	break;

/*589*/ 	default:
/*589*/ 	return 2;
/*592*/ 	}
/*592*/ 	break;

/*592*/ 	default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 97);
/*592*/ 	}
/*592*/ 	return 0;
/*596*/ }

 RECORD *
 Expressions_ParseClassMethodCall(RECORD *, int, STRING *);

/*611*/ void
/*611*/ Expressions_DereferenceLHS(RECORD *Expressions_expect, RECORD **Expressions_found)
/*611*/ {
/*612*/ 	RECORD * Expressions_r = NULL;
/*613*/ 	RECORD * Expressions_unk = NULL;
/*613*/ 	RECORD * Expressions_t = NULL;
/*614*/ 	STRING * Expressions_id = NULL;
/*615*/ 	RECORD * Expressions_cl = NULL;
/*617*/ 	RECORD * Expressions_p = NULL;
/*619*/ 	if( (Scanner_sym == 14) ){
/*621*/ 		if( *Expressions_found == NULL ){
/*622*/ 			*Expressions_found = (
/*622*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*622*/ 				*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*622*/ 				*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*622*/ 				push((char*) NULL),
/*622*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*622*/ 				push((char*) NULL),
/*623*/ 				*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*623*/ 				(RECORD*) pop()
/*623*/ 			);
/*623*/ 			Scanner_ReadSym();
/*624*/ 			if( (Scanner_sym == 15) ){
/*625*/ 				*(int *)m2runtime_dereference_lhs_RECORD(Expressions_found, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 98) = 3;
/*626*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(Expressions_found, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 99) = Expressions_expect;
/*627*/ 				Scanner_ReadSym();
/*629*/ 				return ;
/*630*/ 			}
/*630*/ 			Expressions_r = Expressions_ParseExpr();
/*631*/ 			if( Expressions_r == NULL ){
/*633*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 100) == Globals_int_type ){
/*634*/ 				*(int *)m2runtime_dereference_lhs_RECORD(Expressions_found, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 101) = 3;
/*635*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 102) == Globals_string_type ){
/*636*/ 				*(int *)m2runtime_dereference_lhs_RECORD(Expressions_found, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 103) = 5;
/*638*/ 			} else {
/*638*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"invalid array index of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 104)), (STRING *) 1));
/*640*/ 			}
/*640*/ 			Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*641*/ 			Scanner_ReadSym();
/*642*/ 			Expressions_DereferenceLHS(Expressions_expect, (RECORD **)m2runtime_dereference_lhs_RECORD(Expressions_found, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 105));
/*644*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 106) == 6) ){
/*645*/ 			Scanner_ReadSym();
/*646*/ 			if( (Scanner_sym == 15) ){
/*647*/ 				switch( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 107)){

/*648*/ 				case 1:
/*649*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\71,\0,\0,\0)"`[]' operator applied to an array of undefined index type");
/*650*/ 				break;

/*650*/ 				case 3:
/*651*/ 				break;

/*651*/ 				case 5:
/*652*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"applying the `[]' operator to array ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"with index of type string", (STRING *) 1));
/*654*/ 				break;

/*654*/ 				case 7:
/*655*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"applying the `[]' operator to array ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"whose index can be either int and string", (STRING *) 1));
/*658*/ 				break;

/*658*/ 				default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 108);
/*658*/ 				}
/*658*/ 				Scanner_ReadSym();
/*659*/ 				*Expressions_found = (RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 109);
/*660*/ 				switch(Expressions_LhsMatchRhs(*Expressions_found, Expressions_expect)){

/*661*/ 				case 0:
/*662*/ 				break;

/*662*/ 				case 1:
/*663*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"found ", Types_TypeToString(*Expressions_found), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)", expected ", Types_TypeToString(Expressions_expect), (STRING *) 1));
/*665*/ 				break;

/*665*/ 				case 2:
/*666*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"found ", Types_TypeToString(*Expressions_found), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)", expected ", Types_TypeToString(Expressions_expect), (STRING *) 1));
/*669*/ 				break;

/*669*/ 				default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 110);
/*670*/ 				}
/*670*/ 				return ;
/*671*/ 			} else {
/*671*/ 				Expressions_r = Expressions_ParseExpr();
/*672*/ 				if( Expressions_r == NULL ){
/*674*/ 				} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 111) == Globals_int_type ){
/*675*/ 					if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 112) == 5) ){
/*676*/ 						Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"invalid index of type int, expected string");
/*678*/ 					}
/*678*/ 				} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 113) == Globals_string_type ){
/*679*/ 					if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 114) == 3) ){
/*680*/ 						Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"invalid index of type string, expected int");
/*683*/ 					}
/*683*/ 				} else {
/*683*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"invalid array index of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 115)), (STRING *) 1));
/*685*/ 				}
/*685*/ 				Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*686*/ 				Scanner_ReadSym();
/*687*/ 				Expressions_DereferenceLHS(Expressions_expect, (RECORD **)m2runtime_dereference_lhs_RECORD(Expressions_found, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 116));
/*691*/ 			}
/*691*/ 		} else {
/*691*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"can't check usage of `[' applied to a value of type ", Types_TypeToString(*Expressions_found), (STRING *) 1));
/*694*/ 			Scanner_ReadSym();
/*695*/ 			if( (Scanner_sym == 15) ){
/*696*/ 				Scanner_ReadSym();
/*698*/ 				return ;
/*699*/ 			}
/*699*/ 			Expressions_r = Expressions_ParseExpr();
/*700*/ 			Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*701*/ 			Scanner_ReadSym();
/*702*/ 			Expressions_t = NULL;
/*703*/ 			Expressions_DereferenceLHS(Expressions_expect, &Expressions_t);
/*707*/ 		}
/*707*/ 	} else if( (Scanner_sym == 61) ){
/*708*/ 		if( *Expressions_found == NULL ){
/*709*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"`->' operator applied to a value of type unknown");
/*710*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 117) != 9) ){
/*711*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"`->' operator applied to a value of type ", Types_TypeToString(*Expressions_found), (STRING *) 1));
/*713*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 118) == NULL ){
/*714*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"`->' operator applied to an object of unknown class");
/*716*/ 		}
/*716*/ 		if( ((*Expressions_found != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 119) != NULL)) ){
/*717*/ 			Scanner_ReadSym();
/*718*/ 			if( (Scanner_sym == 29) ){
/*720*/ 			} else if( (Scanner_sym == 20) ){
/*721*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\160,\0,\0,\0)"expected property name or method name after `->'. Variable-name properties/methods are not supported by PHPLint.");
/*722*/ 				Scanner_s = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"UNKNOWN_", Scanner_s, (STRING *) 1);
/*724*/ 			} else {
/*724*/ 				Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"expected property name or method name after `->'");
/*726*/ 			}
/*726*/ 			Expressions_id = Scanner_s;
/*727*/ 			Scanner_ReadSym();
/*728*/ 			if( (Scanner_sym == 12) ){
/*729*/ 				Expressions_cl = (RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 120);
				Expressions_t = Expressions_ParseClassMethodCall(Expressions_cl, FALSE, Expressions_id);
/*731*/ 				if( (((Globals_php_ver == 4)) && ((Scanner_sym == 61))) ){
/*732*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"cannot dereference object returned by method.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)" That's a limitation of PHP 4.", (STRING *) 1));
/*736*/ 				}
/*736*/ 			} else {
/*736*/ 				Expressions_ResolveClassProperty((RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_found, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 121), FALSE, Expressions_id, &Expressions_cl, &Expressions_p);
/*737*/ 				if( Expressions_p == NULL ){
/*738*/ 					Expressions_t = NULL;
/*740*/ 				} else {
/*740*/ 					Expressions_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_p, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 122);
/*743*/ 				}
/*743*/ 			}
/*743*/ 			Expressions_DereferenceLHS(Expressions_expect, &Expressions_t);
/*746*/ 		} else {
/*746*/ 			Scanner_ReadSym();
/*747*/ 			if( (Scanner_sym == 20) ){
/*748*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\160,\0,\0,\0)"expected property name or method name after `->'. Variable-name properties/methods are not supported by PHPLint.");
/*750*/ 			} else {
/*750*/ 				Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"expected property name or method name after `->'");
/*753*/ 			}
/*753*/ 			Scanner_ReadSym();
/*754*/ 			if( (Scanner_sym == 12) ){
/*755*/ 				Expressions_SkipFuncCall();
/*756*/ 				if( (((Globals_php_ver == 4)) && ((Scanner_sym == 61))) ){
/*757*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"cannot dereference object returned by method.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)" That's a limitation of the PHP 4.", (STRING *) 1));
/*761*/ 				}
/*761*/ 			}
/*761*/ 			Expressions_DereferenceLHS(Expressions_expect, &Expressions_unk);
/*764*/ 		}
/*764*/ 	} else if( *Expressions_found == NULL ){
/*765*/ 		*Expressions_found = Expressions_expect;
/*766*/ 	} else if( Expressions_expect == NULL ){
/*769*/ 	} else {
/*769*/ 		switch(Expressions_LhsMatchRhs(*Expressions_found, Expressions_expect)){

/*770*/ 		case 0:
/*771*/ 		break;

/*771*/ 		case 1:
/*772*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"invalid type ", Types_TypeToString(Expressions_expect), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" assigned to ", Types_TypeToString(*Expressions_found), (STRING *) 1));
/*774*/ 		break;

/*774*/ 		case 2:
/*775*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"invalid type ", Types_TypeToString(Expressions_expect), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" assigned to ", Types_TypeToString(*Expressions_found), (STRING *) 1));
/*778*/ 		break;

/*778*/ 		default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 123);
/*779*/ 		}
/*781*/ 	}
/*783*/ }


/*799*/ void
/*799*/ Expressions_ParseLHS(RECORD *Expressions_expect)
/*799*/ {
/*800*/ 	STRING * Expressions_v_name = NULL;
/*801*/ 	RECORD * Expressions_v = NULL;
/*802*/ 	RECORD * Expressions_res_cl = NULL;
/*802*/ 	RECORD * Expressions_cl = NULL;
/*803*/ 	RECORD * Expressions_res_p = NULL;
/*805*/ 	RECORD * Expressions_t = NULL;
/*805*/ 	if( (Scanner_sym == 127) ){
/*806*/ 		Expressions_map_namespace_operator_into_id();
/*810*/ 	}
/*810*/ 	if( (Scanner_sym == 20) ){
/*811*/ 		Expressions_v_name = Scanner_s;
/*812*/ 		Expressions_v = Search_SearchVar(Expressions_v_name);
/*813*/ 		Scanner_ReadSym();
/*816*/ 		if( (((Scanner_sym == 14)) || ((Scanner_sym == 61))) ){
/*817*/ 			if( Expressions_v == NULL ){
/*818*/ 				Accounting_AccountVarLHS(Expressions_v_name, FALSE);
/*819*/ 				Expressions_v = Search_SearchVar(Expressions_v_name);
/*821*/ 			} else {
/*821*/ 				Accounting_AccountVarRHS2(Expressions_v);
/*825*/ 			}
/*825*/ 		} else {
/*825*/ 			if( Expressions_v == NULL ){
/*826*/ 				Accounting_AccountVarLHS(Expressions_v_name, FALSE);
/*827*/ 				Expressions_v = Search_SearchVar(Expressions_v_name);
/*829*/ 			} else {
/*829*/ 				Accounting_AccountVarLHS2(Expressions_v);
/*832*/ 			}
/*833*/ 		}
/*833*/ 		Expressions_DereferenceLHS(Expressions_expect, (RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 124));
/*836*/ 	} else if( (Scanner_sym == 29) ){
/*837*/ 		Expressions_cl = Search_SearchClass(Scanner_s);
/*838*/ 		if( Expressions_cl == NULL ){
/*839*/ 			Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"invalid syntax in LHS. Undeclared class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"'?", (STRING *) 1));
/*841*/ 		}
/*841*/ 		Scanner_ReadSym();
/*842*/ 		Scanner_Expect(19, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"expected `::'");
/*843*/ 		Scanner_ReadSym();
/*844*/ 		Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"expected property");
/*845*/ 		Expressions_ResolveClassProperty(Expressions_cl, TRUE, Scanner_s, &Expressions_res_cl, &Expressions_res_p);
/*846*/ 		if( Expressions_res_p == NULL ){
/*847*/ 			Scanner_ReadSym();
/*848*/ 			Expressions_DereferenceLHS(Expressions_expect, &Expressions_t);
/*850*/ 		} else {
/*850*/ 			Scanner_ReadSym();
/*851*/ 			Expressions_DereferenceLHS(Expressions_expect, (RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_res_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 125));
/*855*/ 		}
/*855*/ 	} else if( (Scanner_sym == 103) ){
/*856*/ 		if( (Globals_php_ver == 4) ){
/*857*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"invalid `self::' (PHP 5)");
/*859*/ 		}
/*859*/ 		Expressions_cl = Globals_curr_class;
/*860*/ 		if( Expressions_cl == NULL ){
/*861*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"`self::': not inside a class");
/*863*/ 		}
/*863*/ 		Scanner_ReadSym();
/*864*/ 		Scanner_Expect(19, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"expected `::'");
/*865*/ 		Scanner_ReadSym();
/*866*/ 		Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"expected property");
/*867*/ 		Expressions_ResolveClassProperty(Expressions_cl, TRUE, Scanner_s, &Expressions_res_cl, &Expressions_res_p);
/*868*/ 		if( Expressions_res_p == NULL ){
/*869*/ 			Scanner_ReadSym();
/*870*/ 			Expressions_DereferenceLHS(Expressions_expect, &Expressions_t);
/*872*/ 		} else {
/*872*/ 			Scanner_ReadSym();
/*873*/ 			Expressions_DereferenceLHS(Expressions_expect, (RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_res_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 126));
/*877*/ 		}
/*877*/ 	} else if( (Scanner_sym == 104) ){
/*878*/ 		if( (Globals_php_ver == 4) ){
/*879*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"invalid `parent::' (PHP 5)");
/*881*/ 		}
/*881*/ 		Expressions_cl = Globals_curr_class;
/*882*/ 		if( Expressions_cl == NULL ){
/*883*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"`parent::': not inside a class");
/*885*/ 		}
/*885*/ 		Expressions_cl = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_cl, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 127);
/*886*/ 		if( Expressions_cl == NULL ){
/*887*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"`parent::': no parent class");
/*889*/ 		}
/*889*/ 		Scanner_ReadSym();
/*890*/ 		Scanner_Expect(19, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"expected `::'");
/*891*/ 		Scanner_ReadSym();
/*892*/ 		Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected class property");
/*893*/ 		Expressions_ResolveClassProperty(Expressions_cl, TRUE, Scanner_s, &Expressions_res_cl, &Expressions_res_p);
/*894*/ 		if( Expressions_res_p == NULL ){
/*895*/ 			Scanner_ReadSym();
/*896*/ 			Expressions_DereferenceLHS(Expressions_expect, &Expressions_t);
/*898*/ 		} else {
/*898*/ 			Scanner_ReadSym();
/*899*/ 			Expressions_DereferenceLHS(Expressions_expect, (RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_res_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 128));
/*903*/ 		}
/*903*/ 	} else {
/*903*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"invalid syntax in LHS");
/*907*/ 	}
/*909*/ }


/*916*/ void
/*916*/ Expressions_ParseArgsListCall(int Expressions_guess, STRING *Expressions_n, RECORD *Expressions_sign, RECORD *Expressions_decl_in)
/*916*/ {

/*922*/ 	void
/*922*/ 	Expressions_CheckActualArgument(STRING *Expressions_n, int Expressions_i, RECORD *Expressions_a, RECORD *Expressions_r)
/*922*/ 	{

/*924*/ 		STRING *
/*924*/ 		Expressions_base(void)
/*924*/ 		{
/*924*/ 			return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"calling `", Expressions_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"()' declared in ", Scanner_reference(Expressions_decl_in), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)", argument no. ", m2runtime_itos(((Expressions_i + 1))), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", (STRING *) 1);
/*929*/ 		}

/*931*/ 		RECORD * Expressions_b = NULL;
/*931*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 129) == NULL ){
/*934*/ 			return ;
/*936*/ 		}
/*936*/ 		if( Expressions_r == NULL ){
/*939*/ 			return ;
/*941*/ 		}
/*941*/ 		Expressions_b = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 130);
/*943*/ 		switch(Expressions_LhsMatchRhs((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 131), Expressions_b)){

/*944*/ 		case 0:
/*945*/ 		break;

/*945*/ 		case 1:
/*946*/ 		Scanner_Warning(m2runtime_concat_STRING(0, Expressions_base(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"found type `", Types_TypeToString(Expressions_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"', required type `", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 132)), m2runtime_CHR(39), (STRING *) 1));
/*948*/ 		break;

/*948*/ 		case 2:
/*949*/ 		Scanner_Error(m2runtime_concat_STRING(0, Expressions_base(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"found type `", Types_TypeToString(Expressions_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"', required type `", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 133)), m2runtime_CHR(39), (STRING *) 1));
/*952*/ 		break;

/*952*/ 		default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 134);
/*953*/ 		}
/*955*/ 	}

/*956*/ 	int Expressions_i = 0;
/*957*/ 	RECORD * Expressions_r = NULL;
/*958*/ 	RECORD * Expressions_a = NULL;
/*960*/ 	RECORD * Expressions_v = NULL;
/*960*/ 	Scanner_ReadSym();
/*962*/ 	if( (Scanner_sym == 13) ){
/*963*/ 		Scanner_ReadSym();
/*964*/ 		if( (!Expressions_guess && (( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_sign, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 135) > 0))) ){
/*965*/ 			Scanner_Error(m2runtime_concat_STRING(0, m2runtime_CHR(96), Expressions_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"()' declared in ", Scanner_reference(Expressions_decl_in), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)" requires arguments", (STRING *) 1));
/*968*/ 		}
/*968*/ 		return ;
/*969*/ 	}
/*969*/ 	Expressions_i = 0;
/*971*/ 	do{
/*971*/ 		if( Expressions_guess ){
/*972*/ 			Expressions_r = Expressions_ParseExpr();
/*973*/ 			Expressions_a = NULL;
/*974*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Expressions_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 136) = m2runtime_CHR(63);
/*975*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 137) = FALSE;
/*976*/ 			if( Expressions_r == NULL ){
/*977*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 138) = NULL;
/*979*/ 			} else {
/*979*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 139) = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 140);
/*981*/ 			}
/*981*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Expressions_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 141), sizeof(void *), 1, Expressions_0err_entry_get, 142) = Expressions_a;
/*982*/ 			m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Expressions_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 143), 1);
/*983*/ 		} else if( (Expressions_i < m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Expressions_sign, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 144))) ){
/*984*/ 			Expressions_a = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Expressions_sign, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 145), Expressions_i, Expressions_0err_entry_get, 146);
/*985*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Expressions_a, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 147) ){
/*986*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Expressions_a, 3 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 148) ){
/*987*/ 					Expressions_ParseLHS((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 149));
/*991*/ 				} else {
/*991*/ 					if( (Scanner_sym == 20) ){
/*992*/ 						Expressions_v = Search_SearchVar(Scanner_s);
/*993*/ 						if( ((Expressions_v == NULL) || ! *(int *)m2runtime_dereference_rhs_RECORD(Expressions_v, 7 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 150)) ){
/*994*/ 							Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"invalid actual argument $", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)" passed by reference: the variable might not have been assigned", (STRING *) 1));
/*1011*/ 						}
/*1011*/ 					}
/*1011*/ 					Expressions_ParseLHS((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 151));
/*1014*/ 				}
/*1014*/ 			} else {
/*1014*/ 				Expressions_r = Expressions_ParseExpr();
/*1015*/ 				Expressions_CheckActualArgument(Expressions_n, Expressions_i, Expressions_a, Expressions_r);
/*1018*/ 			}
/*1018*/ 		} else {
/*1018*/ 			if( (((Expressions_i == m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Expressions_sign, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 152)))) && ! *(int *)m2runtime_dereference_rhs_RECORD(Expressions_sign, 2 * sizeof(void*) + 4 * sizeof(int), Expressions_0err_entry_get, 153)) ){
/*1019*/ 				Scanner_Error(m2runtime_concat_STRING(0, m2runtime_CHR(96), Expressions_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"()' declared in ", Scanner_reference(Expressions_decl_in), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)": too many arguments", (STRING *) 1));
/*1021*/ 			}
/*1021*/ 			Expressions_r = Expressions_ParseExpr();
/*1023*/ 		}
/*1023*/ 		if( (Scanner_sym == 16) ){
/*1024*/ 			Scanner_ReadSym();
/*1025*/ 			m2_inc(&Expressions_i, 1);
/*1028*/ 		} else {
/*1029*/ 			goto m2runtime_loop_1;
/*1030*/ 		}
/*1030*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1030*/ 	if( Expressions_guess ){
/*1031*/ 		Scanner_Expect(13, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)"expected ')'  or ',' in argument list of unknown `", Expressions_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"()'", (STRING *) 1));
/*1033*/ 		Scanner_ReadSym();
/*1035*/ 	} else {
/*1035*/ 		if( (Scanner_sym == 13) ){
/*1036*/ 			if( ((Expressions_i + 1) <  *(int *)m2runtime_dereference_rhs_RECORD(Expressions_sign, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 154)) ){
/*1037*/ 				Scanner_Error(m2runtime_concat_STRING(0, m2runtime_CHR(96), Expressions_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"()' declared in ", Scanner_reference(Expressions_decl_in), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)" requires more arguments", (STRING *) 1));
/*1039*/ 			}
/*1039*/ 			Scanner_ReadSym();
/*1041*/ 		} else {
/*1041*/ 			Scanner_UnexpectedSymbol();
/*1044*/ 		}
/*1045*/ 	}
/*1047*/ }


/*1059*/ RECORD *
/*1059*/ Expressions_ParseClassMethodCall(RECORD *Expressions_class, int Expressions_static, STRING *Expressions_name)
/*1059*/ {
/*1060*/ 	RECORD * Expressions_m = NULL;
/*1061*/ 	RECORD * Expressions_sign = NULL;
/*1063*/ 	RECORD * Expressions_c2 = NULL;
/*1063*/ 	if( Expressions_class == NULL ){
/*1064*/ 		Expressions_SkipFuncCall();
/*1065*/ 		return NULL;
/*1068*/ 	}
/*1068*/ 	Expressions_DereferenceClassMethod(Expressions_class, Expressions_static, Expressions_name, &Expressions_c2, &Expressions_m);
/*1070*/ 	if( Expressions_m == NULL ){
/*1071*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 155) = NULL;
/*1072*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 156) = Expressions_name;
/*1073*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 157) = str_tolower(Expressions_name);
/*1074*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 4 * sizeof(int), Expressions_0err_entry_get, 158) = 2;
/*1075*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 159) = Expressions_static;
/*1076*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 160) = Expressions_sign;
/*1077*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 161) = NULL;
/*1078*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 4 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 162) = Scanner_here();
/*1079*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 7 * sizeof(int), Expressions_0err_entry_get, 163) = 1;
/*1081*/ 		Expressions_ParseArgsListCall(TRUE, m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 164), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Expressions_name, (STRING *) 1), Expressions_sign, (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_m, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 165));
/*1082*/ 		Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"guessed signature of the method `", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 166), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Expressions_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"()' as ", Types_MethodSignatureToString(Expressions_m), (STRING *) 1));
/*1085*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Expressions_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 8 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 167), sizeof(void *), 1, Expressions_0err_entry_get, 168) = Expressions_m;
/*1088*/ 	} else {
/*1088*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_m, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 169) == NULL ){
/*1090*/ 			Expressions_sign = (
/*1091*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 5 * sizeof(int), 2)),
/*1091*/ 				push((char*) NULL),
/*1091*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1092*/ 				*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*1093*/ 				*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 0,
/*1094*/ 				push((char*) NULL),
/*1094*/ 				*(ARRAY**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (ARRAY*) tos(), pop(),
/*1095*/ 				*(int*) (tos()+2 * sizeof(void*) + 4 * sizeof(int)) = FALSE,
/*1097*/ 				(RECORD*) pop()
/*1097*/ 			);
/*1097*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 170) = Expressions_sign;
/*1099*/ 		} else {
/*1099*/ 			Expressions_sign = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_m, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 171);
/*1102*/ 		}
/*1102*/ 		Expressions_ParseArgsListCall(FALSE, m2runtime_concat_STRING(0, Classes_pc(Expressions_class, Expressions_c2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_m, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 172), (STRING *) 1), Expressions_sign, (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_m, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 173));
/*1105*/ 	}
/*1105*/ 	return (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_sign, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 174);
/*1109*/ }


/*1111*/ int
/*1111*/ Expressions_IsAssignOp(int Expressions_sym)
/*1111*/ {
/*1111*/ 	return (((Expressions_sym == 31)) || ((Expressions_sym == 76)) || ((Expressions_sym == 77)) || ((Expressions_sym == 78)) || ((Expressions_sym == 79)) || ((Expressions_sym == 75)) || ((Expressions_sym == 80)) || ((Expressions_sym == 81)) || ((Expressions_sym == 82)) || ((Expressions_sym == 83)) || ((Expressions_sym == 84)) || ((Expressions_sym == 85)));
/*1120*/ }


/*1149*/ RECORD *
/*1149*/ Expressions_Dereference(RECORD **Expressions_t)
/*1149*/ {

/*1155*/ 	RECORD *
/*1155*/ 	Expressions_DereferenceArray(RECORD **Expressions_t)
/*1155*/ 	{
/*1156*/ 		RECORD * Expressions_r = NULL;
/*1157*/ 		RECORD * Expressions_c = NULL;
/*1159*/ 		RECORD * Expressions_m = NULL;
/*1159*/ 		if( *Expressions_t == NULL ){
/*1160*/ 			*Expressions_t = (
/*1160*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*1160*/ 				*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*1160*/ 				*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*1160*/ 				push((char*) NULL),
/*1160*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1160*/ 				push((char*) NULL),
/*1161*/ 				*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1161*/ 				(RECORD*) pop()
/*1161*/ 			);
/*1161*/ 			Scanner_ReadSym();
/*1162*/ 			if( (Scanner_sym == 15) ){
/*1163*/ 				*(int *)m2runtime_dereference_lhs_RECORD(Expressions_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 175) = 3;
/*1164*/ 				Scanner_ReadSym();
/*1165*/ 				Scanner_Expect(31, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"required `=' after the operator `[]'");
/*1166*/ 				return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(Expressions_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 176));
/*1169*/ 			}
/*1169*/ 			Expressions_r = Expressions_ParseExpr();
/*1170*/ 			if( Expressions_r == NULL ){
/*1172*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 177) == Globals_int_type ){
/*1173*/ 				*(int *)m2runtime_dereference_lhs_RECORD(Expressions_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 178) = 3;
/*1174*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 179) == Globals_string_type ){
/*1175*/ 				*(int *)m2runtime_dereference_lhs_RECORD(Expressions_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 180) = 5;
/*1177*/ 			} else {
/*1177*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"invalid array index of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 181)), (STRING *) 1));
/*1179*/ 			}
/*1179*/ 			Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*1180*/ 			Scanner_ReadSym();
/*1181*/ 			return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(Expressions_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 182));
/*1183*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 183) == 5) ){
/*1184*/ 			Scanner_ReadSym();
/*1185*/ 			if( (Scanner_sym == 15) ){
/*1186*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"undefined last element `[]' operator for a value of type string");
/*1187*/ 				Scanner_ReadSym();
/*1188*/ 				return Globals_string_type;
/*1190*/ 			}
/*1190*/ 			Expressions_r = Expressions_ParseExpr();
/*1191*/ 			if( Expressions_r == NULL ){
/*1193*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 184) == Globals_int_type ){
/*1195*/ 			} else {
/*1195*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"invalid array index of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 185)), (STRING *) 1));
/*1197*/ 			}
/*1197*/ 			Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*1198*/ 			Scanner_ReadSym();
/*1199*/ 			return Globals_string_type;
/*1201*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 186) == 6) ){
/*1202*/ 			Scanner_ReadSym();
/*1203*/ 			if( (Scanner_sym == 15) ){
/*1204*/ 				if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 187) == 1) ){
/*1205*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"applying the `[]' operator to array ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"of undefined index type", (STRING *) 1));
/*1207*/ 				} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 188) == 5) ){
/*1208*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"applying the `[]' operator to array ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"with index of type string", (STRING *) 1));
/*1211*/ 				}
/*1211*/ 				Scanner_ReadSym();
/*1212*/ 				Scanner_Expect(31, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"required `=' after the operator `[]'");
/*1213*/ 				return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(Expressions_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 189));
/*1215*/ 			}
/*1215*/ 			Expressions_r = Expressions_ParseExpr();
/*1216*/ 			if( Expressions_r == NULL ){
/*1218*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 190) == Globals_int_type ){
/*1219*/ 				if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 191) == 5) ){
/*1220*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"invalid index of type int, expected string");
/*1222*/ 				}
/*1222*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 192) == Globals_string_type ){
/*1223*/ 				if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 193) == 3) ){
/*1224*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"invalid index of type string, expected int");
/*1227*/ 				}
/*1227*/ 			} else {
/*1227*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"invalid array index of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 194)), (STRING *) 1));
/*1229*/ 			}
/*1229*/ 			Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*1230*/ 			Scanner_ReadSym();
/*1231*/ 			return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(Expressions_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 195));
/*1233*/ 		} else if( ((( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 196) == 9)) && Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 197), Classes_ArrayAccessClass)) ){
/*1236*/ 			Scanner_ReadSym();
/*1237*/ 			Expressions_r = Expressions_ParseExpr();
/*1238*/ 			Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*1239*/ 			Scanner_ReadSym();
/*1242*/ 			Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 198), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"offsetGet", &Expressions_c, &Expressions_m);
/*1243*/ 			return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 199), 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 200));
/*1246*/ 		} else {
/*1246*/ 			if( ((( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 201) == 9)) && ((Globals_php_ver == 5))) ){
/*1247*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\110,\0,\0,\0)"`[' operator not applicable to object without implementing `ArrayAccess'");
/*1248*/ 			} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 202) == 7) ){
/*1249*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\71,\0,\0,\0)"can't check usage of `[' applied to a value of type mixed");
/*1251*/ 			} else {
/*1251*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"`[' operator not applicable to a value of type ", Types_TypeToString(*Expressions_t), (STRING *) 1));
/*1254*/ 			}
/*1254*/ 			Scanner_ReadSym();
/*1255*/ 			if( (Scanner_sym == 15) ){
/*1256*/ 				Scanner_ReadSym();
/*1257*/ 				Scanner_Expect(31, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"required `=' after the operator `[]'");
/*1258*/ 				*Expressions_t = (
/*1258*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*1258*/ 					*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*1258*/ 					*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*1258*/ 					push((char*) NULL),
/*1258*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1258*/ 					push((char*) NULL),
/*1259*/ 					*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1259*/ 					(RECORD*) pop()
/*1259*/ 				);
/*1259*/ 				return Expressions_Dereference(Expressions_t);
/*1261*/ 			}
/*1261*/ 			Expressions_r = Expressions_ParseExpr();
/*1262*/ 			Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*1263*/ 			Scanner_ReadSym();
/*1264*/ 			return Expressions_Dereference(Expressions_t);
/*1268*/ 		}
/*1268*/ 		m2runtime_missing_return(Expressions_0err_entry_get, 203);
/*1268*/ 		return NULL;
/*1271*/ 	}

/*1272*/ 	STRING * Expressions_id = NULL;
/*1273*/ 	RECORD * Expressions_class = NULL;
/*1274*/ 	RECORD * Expressions_p = NULL;
/*1275*/ 	RECORD * Expressions_r = NULL;
/*1276*/ 	RECORD * Expressions_t2 = NULL;
/*1276*/ 	RECORD * Expressions_unk = NULL;
/*1277*/ 	int Expressions_op = 0;
/*1278*/ 	int Expressions_left_inval = 0;
/*1280*/ 	RECORD * Expressions_v = NULL;
/*1280*/ 	if( (Scanner_sym == 14) ){
/*1281*/ 		return Expressions_DereferenceArray(Expressions_t);
/*1283*/ 	} else if( (Scanner_sym == 10) ){
/*1284*/ 		if( ((*Expressions_t == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 204) != 5))) ){
/*1285*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"`{' operator applied to a value of type ", Types_TypeToString(*Expressions_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)". Expected a string.", (STRING *) 1));
/*1288*/ 		} else {
/*1288*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\166,\0,\0,\0)"using deprecated character selector operator `{'. Support for this operator deprecated since PHP 5.1. Use `[' instead.");
/*1290*/ 		}
/*1290*/ 		Scanner_ReadSym();
/*1291*/ 		Expressions_r = Expressions_ParseExpr();
/*1292*/ 		if( Expressions_r == NULL ){
/*1295*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 205) != Globals_int_type ){
/*1296*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"invalid character selector {EXPR} of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 206)), (STRING *) 1));
/*1299*/ 		}
/*1299*/ 		Scanner_Expect(11, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"expected closing '}' in character selector");
/*1300*/ 		Scanner_ReadSym();
/*1301*/ 		return Globals_string_type;
/*1303*/ 	} else if( (Scanner_sym == 61) ){
/*1304*/ 		if( *Expressions_t == NULL ){
/*1305*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"`->' operator applied to a value of type unknown");
/*1306*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 207) != 9) ){
/*1307*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"`->' operator applied to a value of type ", Types_TypeToString(*Expressions_t), (STRING *) 1));
/*1309*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 208) == NULL ){
/*1310*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"`->' operator applied to an object of unknown class");
/*1312*/ 		}
/*1312*/ 		if( ((*Expressions_t == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 209) != 9)) || ((RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 210) == NULL)) ){
/*1313*/ 			Scanner_ReadSym();
/*1314*/ 			Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"expected property name or method name after `->'");
/*1316*/ 			Scanner_ReadSym();
/*1317*/ 			if( (Scanner_sym == 12) ){
/*1318*/ 				Expressions_SkipFuncCall();
/*1319*/ 				if( (((Globals_php_ver == 4)) && ((Scanner_sym == 61))) ){
/*1320*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"cannot dereference object returned by method.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)" That's a limitation of the PHP 4.", (STRING *) 1));
/*1324*/ 				}
/*1324*/ 			}
/*1324*/ 			return Expressions_Dereference(&Expressions_unk);
/*1326*/ 		} else {
/*1326*/ 			Scanner_ReadSym();
/*1327*/ 			if( (Scanner_sym == 29) ){
/*1329*/ 			} else if( (Scanner_sym == 20) ){
/*1330*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"expected property name or method name after `->'");
/*1331*/ 				Scanner_s = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"UNKNOWN";
/*1333*/ 			} else {
/*1333*/ 				Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"expected property name or method name after `->'");
/*1335*/ 			}
/*1335*/ 			Expressions_id = Scanner_s;
/*1336*/ 			Scanner_ReadSym();
/*1337*/ 			if( (Scanner_sym == 12) ){
/*1338*/ 				Expressions_t2 = Expressions_ParseClassMethodCall((RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 211), FALSE, Expressions_id);
/*1339*/ 				if( (((Globals_php_ver == 4)) && ((Scanner_sym == 61))) ){
/*1340*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"cannot dereference object returned by method.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)" That's a limitation of the PHP 4.", (STRING *) 1));
/*1344*/ 				}
/*1344*/ 			} else {
/*1344*/ 				Expressions_ResolveClassProperty((RECORD *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 212), FALSE, Expressions_id, &Expressions_class, &Expressions_p);
/*1345*/ 				if( Expressions_p == NULL ){
/*1346*/ 					Expressions_t2 = NULL;
/*1348*/ 				} else {
/*1348*/ 					Expressions_t2 = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_p, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 213);
/*1351*/ 				}
/*1351*/ 			}
/*1351*/ 			return Expressions_Dereference(&Expressions_t2);
/*1354*/ 		}
/*1354*/ 	} else if( Expressions_IsAssignOp(Scanner_sym) ){
/*1355*/ 		Expressions_op = Scanner_sym;
/*1356*/ 		if( *Expressions_t != NULL ){
/*1361*/ 			switch(Expressions_op){

/*1362*/ 			case 76:
/*1362*/ 			case 77:
/*1362*/ 			case 78:
/*1363*/ 			if( ((*Expressions_t != Globals_int_type) && (*Expressions_t != Globals_float_type)) ){
/*1364*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid LHS type ", Types_TypeToString(*Expressions_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" for the operator", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)" += -= *=", (STRING *) 1));
/*1366*/ 				Expressions_left_inval = TRUE;
/*1368*/ 			}
/*1368*/ 			break;

/*1368*/ 			case 79:
/*1369*/ 			if( *Expressions_t != Globals_float_type ){
/*1370*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid LHS type ", Types_TypeToString(*Expressions_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" for the operator", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)" /=, required float", (STRING *) 1));
/*1372*/ 				Expressions_left_inval = TRUE;
/*1374*/ 			}
/*1374*/ 			break;

/*1374*/ 			case 75:
/*1375*/ 			if( ((*Expressions_t == Globals_string_type) || Classes_IsObjectConvertibleToString(*Expressions_t)) ){
/*1378*/ 			} else {
/*1378*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid LHS type ", Types_TypeToString(*Expressions_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" for the operator", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)" .=, required string", (STRING *) 1));
/*1380*/ 				Expressions_left_inval = TRUE;
/*1382*/ 			}
/*1382*/ 			break;

/*1382*/ 			case 80:
/*1382*/ 			case 81:
/*1382*/ 			case 82:
/*1383*/ 			case 83:
/*1383*/ 			case 84:
/*1383*/ 			case 85:
/*1384*/ 			if( *Expressions_t != Globals_int_type ){
/*1385*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid LHS type ", Types_TypeToString(*Expressions_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)" for the operator %= &= |= ^= <<= >>=, required int", (STRING *) 1));
/*1387*/ 				Expressions_left_inval = TRUE;
/*1390*/ 			}
/*1390*/ 			break;
/*1392*/ 			}
/*1392*/ 		}
/*1392*/ 		Scanner_ReadSym();
/*1397*/ 		Expressions_r = Expressions_ParseExpr();
/*1398*/ 		if( Expressions_r == NULL ){
/*1400*/ 			return NULL;
/*1406*/ 		}
/*1406*/ 		Expressions_t2 = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 214);
/*1407*/ 		switch(Expressions_op){

/*1408*/ 		case 76:
/*1408*/ 		case 77:
/*1408*/ 		case 78:
/*1409*/ 		if( ((Expressions_t2 != Globals_int_type) && (Expressions_t2 != Globals_float_type)) ){
/*1410*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid RHS type ", Types_TypeToString(Expressions_t2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" for the operator", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)" += -= *=", (STRING *) 1));
/*1412*/ 			Expressions_left_inval = TRUE;
/*1414*/ 		}
/*1414*/ 		break;

/*1414*/ 		case 79:
/*1415*/ 		if( ((Expressions_t2 != Globals_int_type) && (Expressions_t2 != Globals_float_type)) ){
/*1416*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid RHS type ", Types_TypeToString(Expressions_t2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" for the operator", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)" /=, required float", (STRING *) 1));
/*1418*/ 			Expressions_left_inval = TRUE;
/*1420*/ 		}
/*1420*/ 		break;

/*1420*/ 		case 75:
/*1421*/ 		if( !(((Expressions_t2 == Globals_string_type) || Classes_IsObjectConvertibleToString(Expressions_t2))) ){
/*1422*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid RHS type ", Types_TypeToString(Expressions_t2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" for the operator", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)" .=, required string", (STRING *) 1));
/*1424*/ 			Expressions_left_inval = TRUE;
/*1426*/ 		}
/*1426*/ 		break;

/*1426*/ 		case 80:
/*1426*/ 		case 81:
/*1426*/ 		case 82:
/*1427*/ 		case 83:
/*1427*/ 		case 84:
/*1427*/ 		case 85:
/*1428*/ 		if( Expressions_t2 != Globals_int_type ){
/*1429*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid RHS type ", Types_TypeToString(Expressions_t2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)" for the operator %= &= |= ^= <<= >>=, required int", (STRING *) 1));
/*1431*/ 			Expressions_left_inval = TRUE;
/*1434*/ 		}
/*1434*/ 		break;
/*1439*/ 		}
/*1439*/ 		if( *Expressions_t == NULL ){
/*1440*/ 			*Expressions_t = Expressions_t2;
/*1441*/ 			return Expressions_t2;
/*1444*/ 		}
/*1444*/ 		if( (Expressions_op == 31) ){
/*1445*/ 			switch(Expressions_LhsMatchRhs(*Expressions_t, Expressions_t2)){

/*1446*/ 			case 0:
/*1447*/ 			break;

/*1447*/ 			case 1:
/*1448*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"cannot assign a value of type ", Types_TypeToString(Expressions_t2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)" to a variable of type ", Types_TypeToString(*Expressions_t), (STRING *) 1));
/*1450*/ 			break;

/*1450*/ 			case 2:
/*1451*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"cannot assign a value of type ", Types_TypeToString(Expressions_t2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)" to a variable of type ", Types_TypeToString(*Expressions_t), (STRING *) 1));
/*1454*/ 			break;

/*1454*/ 			default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 215);
/*1454*/ 			}
/*1454*/ 			return *Expressions_t;
/*1457*/ 		}
/*1457*/ 		if( ((*Expressions_t == Globals_int_type) && (Expressions_t2 == Globals_float_type)) ){
/*1458*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"can't assign float to int in assignment operator");
/*1460*/ 		}
/*1460*/ 		return *Expressions_t;
/*1462*/ 	} else if( (Scanner_sym == 107) ){
/*1463*/ 		if( (Globals_php_ver == 4) ){
/*1464*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"invalid operator `instanceof' (PHP 5). Hint: use `is_a()'.");
/*1466*/ 		}
/*1466*/ 		if( ((*Expressions_t != NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 216) != 9)) && (( *(int *)m2runtime_dereference_rhs_RECORD(*Expressions_t, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 217) != 7))) ){
/*1468*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"the left side of `instanceof' is of type ", Types_TypeToString(*Expressions_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)", expected object or mixed", (STRING *) 1));
/*1471*/ 		}
/*1471*/ 		Scanner_ReadSym();
/*1472*/ 		if( (Scanner_sym == 127) ){
/*1473*/ 			Expressions_map_namespace_operator_into_id();
/*1475*/ 		}
/*1475*/ 		if( (Scanner_sym == 29) ){
/*1476*/ 			if( Search_SearchClass(Scanner_s) == NULL ){
/*1477*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"' (still) undefined", (STRING *) 1));
/*1479*/ 			}
/*1479*/ 		} else if( (Scanner_sym == 103) ){
/*1480*/ 			if( Globals_curr_class == NULL ){
/*1481*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"`self' undefined outside class body");
/*1483*/ 			}
/*1483*/ 		} else if( (Scanner_sym == 104) ){
/*1484*/ 			if( Globals_curr_class == NULL ){
/*1485*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"`parent' undefined outside class body");
/*1486*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 218) == NULL ){
/*1487*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"current class has no parent");
/*1489*/ 			}
/*1489*/ 		} else if( (Scanner_sym == 20) ){
/*1490*/ 			Expressions_v = Search_SearchVar(Scanner_s);
/*1491*/ 			if( (Expressions_v == NULL) ){
/*1492*/ 				Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"unknown variable `$", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"' after `instanceof'", (STRING *) 1));
/*1494*/ 			}
/*1494*/ 			if( ((( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_v, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 219), 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 220) != 5)) && (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_v, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 221), 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 222) != 9))) ){
/*1495*/ 				Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"variable after `instanceof' must be string or object, ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_v, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 223)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" found for `$", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*1499*/ 			}
/*1499*/ 		} else {
/*1499*/ 			Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"expected class name or variable, found symbol ", Scanner_SymToName(Scanner_sym), (STRING *) 1));
/*1501*/ 		}
/*1501*/ 		Scanner_ReadSym();
/*1502*/ 		return Globals_boolean_type;
/*1504*/ 	} else if( (Scanner_sym == 52) ){
/*1505*/ 		if( ((*Expressions_t != NULL) && (*Expressions_t != Globals_int_type)) ){
/*1506*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"`++' applied to ", Types_TypeToString(*Expressions_t), (STRING *) 1));
/*1508*/ 		}
/*1508*/ 		Scanner_ReadSym();
/*1509*/ 		return Globals_int_type;
/*1511*/ 	} else if( (Scanner_sym == 53) ){
/*1512*/ 		if( ((*Expressions_t != NULL) && (*Expressions_t != Globals_int_type)) ){
/*1513*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"`--' applied to ", Types_TypeToString(*Expressions_t), (STRING *) 1));
/*1515*/ 		}
/*1515*/ 		Scanner_ReadSym();
/*1516*/ 		return Globals_int_type;
/*1519*/ 	} else {
/*1519*/ 		return *Expressions_t;
/*1522*/ 	}
/*1522*/ 	m2runtime_missing_return(Expressions_0err_entry_get, 224);
/*1522*/ 	return NULL;
/*1524*/ }


/*1537*/ RECORD *
/*1537*/ Expressions_ParseFuncCall(STRING *Expressions_func_name, int Expressions_inside_expr)
/*1537*/ {
/*1538*/ 	int Expressions_guess = 0;
/*1539*/ 	RECORD * Expressions_f = NULL;
/*1540*/ 	RECORD * Expressions_sign = NULL;
/*1542*/ 	RECORD * Expressions_return_type = NULL;
/*1543*/ 	Expressions_f = Accounting_AccountFuncCall(Expressions_func_name);
/*1545*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_f, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 225) == NULL ){
/*1547*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_f, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 226) == NULL ){
/*1548*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", Expressions_func_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"()' (still) not declared. Guessing signature from its usage.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)" Hint: it's better to declare the functions before their usage.", (STRING *) 1));
/*1551*/ 			Expressions_guess = TRUE;
/*1552*/ 			if( Expressions_inside_expr ){
/*1553*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 227) = Globals_mixed_type;
/*1555*/ 			} else {
/*1555*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 228) = Globals_void_type;
/*1557*/ 			}
/*1557*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 229) = Expressions_sign;
/*1558*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 230) = Scanner_here();
/*1559*/ 			Expressions_return_type = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_sign, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 231);
/*1561*/ 		} else {
/*1561*/ 			Expressions_return_type = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_f, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 232), 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 233);
/*1564*/ 		}
/*1564*/ 	} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Expressions_f, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 234), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"cast") == 0 ){
/*1566*/ 		return Typecast_EvaluateCastCall();
/*1570*/ 	} else {
/*1570*/ 		Expressions_return_type = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_f, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 235), 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 236);
/*1573*/ 	}
/*1573*/ 	Errors_RaiseErrors( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_f, 10 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 237));
/*1574*/ 	Exceptions_ThrowExceptions((ARRAY *)m2runtime_dereference_rhs_RECORD(Expressions_f, 6 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 238));
/*1576*/ 	Expressions_ParseArgsListCall(Expressions_guess, (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_f, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 239), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_f, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 240), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_f, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 241));
/*1578*/ 	return Expressions_return_type;
/*1583*/ }

  RECORD * Expressions_ParseStaticExpr();

/*1590*/ RECORD *
/*1590*/ Expressions_ParseArray(int Expressions_static)
/*1590*/ {
/*1592*/ 	RECORD * Expressions_e = NULL;
/*1592*/ 	RECORD * Expressions_k = NULL;
/*1592*/ 	RECORD * Expressions_r = NULL;
/*1593*/ 	Expressions_r = (
/*1593*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*1593*/ 		push((char*) (
/*1593*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*1593*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*1593*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*1593*/ 			push((char*) NULL),
/*1593*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1593*/ 			push((char*) NULL),
/*1593*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1593*/ 			(RECORD*) pop()
/*1593*/ 		)),
/*1593*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1593*/ 		push((char*) NULL),
/*1594*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*1596*/ 		(RECORD*) pop()
/*1596*/ 	);
/*1596*/ 	Scanner_ReadSym();
/*1597*/ 	if( (Scanner_sym == 13) ){
/*1598*/ 		Scanner_ReadSym();
/*1600*/ 		*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 242), 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 243) = 7;
/*1601*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 244), 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 245) = Globals_mixed_type;
/*1603*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 246) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"array()";
/*1604*/ 		return Expressions_r;
/*1606*/ 	}
/*1606*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 247) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"array(...)";
/*1609*/ 	if( Expressions_static ){
/*1610*/ 		Expressions_k = Expressions_ParseStaticExpr();
/*1612*/ 	} else {
/*1612*/ 		Expressions_k = Expressions_ParseExpr();
/*1614*/ 	}
/*1614*/ 	if( (Scanner_sym == 32) ){
/*1615*/ 		if( Expressions_k == NULL ){
/*1617*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_k, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 248) == Globals_int_type ){
/*1618*/ 			*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 249), 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 250) = 3;
/*1619*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_k, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 251) == Globals_string_type ){
/*1620*/ 			*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 252), 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 253) = 5;
/*1622*/ 		} else {
/*1622*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"invalid key of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_k, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 254)), (STRING *) 1));
/*1624*/ 		}
/*1624*/ 		Scanner_ReadSym();
/*1625*/ 		if( Expressions_static ){
/*1626*/ 			Expressions_e = Expressions_ParseStaticExpr();
/*1628*/ 		} else {
/*1628*/ 			Expressions_e = Expressions_ParseExpr();
/*1631*/ 		}
/*1631*/ 	} else {
/*1631*/ 		*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 255), 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 256) = 3;
/*1632*/ 		Expressions_e = Expressions_k;
/*1634*/ 	}
/*1634*/ 	if( Expressions_e == NULL ){
/*1637*/ 	} else {
/*1637*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 257), 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 258) = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_e, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 259);
/*1642*/ 	}
/*1642*/ 	while( (Scanner_sym == 16) ){
/*1643*/ 		Scanner_ReadSym();
/*1645*/ 		if( (Scanner_sym == 13) ){
/*1647*/ 			Scanner_ReadSym();
/*1648*/ 			return Expressions_r;
/*1651*/ 		}
/*1651*/ 		if( Expressions_static ){
/*1652*/ 			Expressions_k = Expressions_ParseStaticExpr();
/*1654*/ 		} else {
/*1654*/ 			Expressions_k = Expressions_ParseExpr();
/*1656*/ 		}
/*1656*/ 		if( (Scanner_sym == 32) ){
/*1657*/ 			if( Expressions_k == NULL ){
/*1659*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_k, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 260) == Globals_int_type ){
/*1660*/ 				if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 261), 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 262) == 5) ){
/*1661*/ 					Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing keys of different types in array");
/*1662*/ 					*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 263), 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 264) = 7;
/*1664*/ 				}
/*1664*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_k, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 265) == Globals_string_type ){
/*1665*/ 				if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 266), 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 267) == 3) ){
/*1666*/ 					Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing keys of different types in array");
/*1667*/ 					*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 268), 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 269) = 7;
/*1670*/ 				}
/*1670*/ 			} else {
/*1670*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"invalid array key of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_k, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 270)), (STRING *) 1));
/*1672*/ 			}
/*1672*/ 			Scanner_ReadSym();
/*1673*/ 			if( Expressions_static ){
/*1674*/ 				Expressions_e = Expressions_ParseStaticExpr();
/*1676*/ 			} else {
/*1676*/ 				Expressions_e = Expressions_ParseExpr();
/*1679*/ 			}
/*1681*/ 		} else {
/*1681*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 271), 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 272) == 5) ){
/*1682*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing keys of different types in array");
/*1683*/ 				*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 273), 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 274) = 7;
/*1685*/ 			}
/*1685*/ 			Expressions_e = Expressions_k;
/*1687*/ 		}
/*1687*/ 		if( Expressions_e == NULL ){
/*1689*/ 		} else if( (Expressions_LhsMatchRhs((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 275), 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 276), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_e, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 277)) != 0) ){
/*1690*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"mixing elements of different types in array: found ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_e, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 278)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)", expected ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 279), 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 280)), (STRING *) 1));
/*1693*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 281), 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 282) = Globals_mixed_type;
/*1696*/ 		}
/*1697*/ 	}
/*1697*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `)'");
/*1698*/ 	Scanner_ReadSym();
/*1699*/ 	return Expressions_r;
/*1703*/ }


/*1707*/ RECORD *
/*1707*/ Expressions_ParseDoubleQuotedStringWithEmbeddedVars(int Expressions_staticExpr)
/*1707*/ {
/*1707*/ 	RECORD * Expressions_r = NULL;
/*1709*/ 	int Expressions_err = 0;
/*1709*/ 	Expressions_r = (
/*1709*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*1709*/ 		push((char*) Globals_string_type),
/*1709*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1709*/ 		push((char*) Scanner_s),
/*1710*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*1710*/ 		(RECORD*) pop()
/*1710*/ 	);
/*1710*/ 	Scanner_ReadSym();
/*1711*/ 	while( (Scanner_sym == 35) ){
/*1712*/ 		if( (Expressions_staticExpr && !Expressions_err) ){
/*1713*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"variables forbidden in static expression");
/*1714*/ 			Expressions_err = TRUE;
/*1717*/ 		}
/*1717*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Expressions_r, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 283) = NULL;
/*1718*/ 		Accounting_AccountVarRHS(Scanner_s);
/*1719*/ 		Scanner_ReadSym();
/*1720*/ 		if( (Scanner_sym == 36) ){
/*1721*/ 			Scanner_ReadSym();
/*1724*/ 		}
/*1724*/ 	}
/*1724*/ 	return Expressions_r;
/*1728*/ }


/*1730*/ RECORD *
/*1730*/ Expressions_ParseList(void)
/*1730*/ {
/*1731*/ 	RECORD * Expressions_r = NULL;
/*1733*/ 	RECORD * Expressions_t = NULL;
/*1733*/ 	Scanner_ReadSym();
/*1734*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"expected '(' after 'list'");
/*1736*/ 	do{
/*1736*/ 		Scanner_ReadSym();
/*1737*/ 		if( (Scanner_sym == 20) ){
/*1738*/ 			Expressions_t = NULL;
/*1739*/ 			Expressions_ParseLHS(Expressions_t);
/*1742*/ 		}
/*1742*/ 		if( (Scanner_sym == 16) ){
/*1744*/ 		} else if( (Scanner_sym == 13) ){
/*1745*/ 			Scanner_ReadSym();
/*1748*/ 			goto m2runtime_loop_1;
/*1748*/ 		} else {
/*1748*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"expected variable name or closing ')' inside list()");
/*1751*/ 		}
/*1751*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1751*/ 	Scanner_Expect(31, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"expected '=' after list()");
/*1752*/ 	Scanner_ReadSym();
/*1753*/ 	Expressions_r = Expressions_ParseExpr();
/*1754*/ 	if( Expressions_r == NULL ){
/*1755*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"unknown type assigned to the list()");
/*1756*/ 	} else if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 284), 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 285) != 6) ){
/*1757*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"invalid value assigned to list(): ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 286)), (STRING *) 1));
/*1759*/ 	}
/*1759*/ 	return (
/*1759*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*1759*/ 		push((char*) (
/*1759*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*1759*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*1759*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*1759*/ 			push((char*) NULL),
/*1759*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1759*/ 			push((char*) NULL),
/*1759*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1759*/ 			(RECORD*) pop()
/*1759*/ 		)),
/*1759*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1759*/ 		push((char*) NULL),
/*1759*/ 		*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*1761*/ 		(RECORD*) pop()
/*1761*/ 	);
/*1763*/ }


/*1778*/ RECORD *
/*1778*/ Expressions_ParseClassStaticAccess(RECORD *Expressions_class)
/*1778*/ {
/*1779*/ 	STRING * Expressions_id = NULL;
/*1780*/ 	RECORD * Expressions_c = NULL;
/*1781*/ 	RECORD * Expressions_c2 = NULL;
/*1782*/ 	RECORD * Expressions_p = NULL;
/*1784*/ 	RECORD * Expressions_t = NULL;
/*1784*/ 	Scanner_ReadSym();
/*1786*/ 	if( (Scanner_sym == 20) ){
/*1787*/ 		if( Expressions_class != NULL ){
/*1788*/ 			Expressions_ResolveClassProperty(Expressions_class, TRUE, Scanner_s, &Expressions_c2, &Expressions_p);
/*1790*/ 		}
/*1790*/ 		Scanner_ReadSym();
/*1791*/ 		if( (((Scanner_sym == 14)) || ((Scanner_sym == 10)) || ((Scanner_sym == 61)) || ((Scanner_sym == 52)) || ((Scanner_sym == 53)) || ((Scanner_sym == 107)) || Expressions_IsAssignOp(Scanner_sym)) ){
/*1798*/ 			if( Expressions_p == NULL ){
/*1799*/ 				Expressions_t = Expressions_Dereference(&Expressions_t);
/*1801*/ 			} else {
/*1801*/ 				Expressions_t = Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 287));
/*1803*/ 			}
/*1803*/ 		} else if( Expressions_p != NULL ){
/*1804*/ 			Expressions_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_p, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 288);
/*1806*/ 		}
/*1806*/ 		if( Expressions_t == NULL ){
/*1807*/ 			return NULL;
/*1809*/ 		} else {
/*1809*/ 			return (
/*1809*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*1809*/ 				push((char*) Expressions_t),
/*1809*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1809*/ 				push((char*) NULL),
/*1810*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*1811*/ 				(RECORD*) pop()
/*1811*/ 			);
/*1812*/ 		}
/*1812*/ 	} else if( (Scanner_sym == 29) ){
/*1813*/ 		Expressions_id = Scanner_s;
/*1814*/ 		Scanner_ReadSym();
/*1815*/ 		if( (Scanner_sym == 12) ){
/*1816*/ 			if( Expressions_class == NULL ){
/*1817*/ 				Expressions_SkipFuncCall();
/*1818*/ 				Expressions_t = NULL;
/*1820*/ 			} else {
/*1820*/ 				Expressions_t = Expressions_ParseClassMethodCall(Expressions_class, TRUE, Expressions_id);
/*1822*/ 			}
/*1822*/ 			if( (Scanner_sym == 61) ){
/*1823*/ 				if( (Globals_php_ver == 4) ){
/*1824*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"cannot dereference object returned by method");
/*1826*/ 				}
/*1826*/ 				Expressions_t = Expressions_Dereference(&Expressions_t);
/*1828*/ 			}
/*1828*/ 			if( Expressions_t == NULL ){
/*1829*/ 				return NULL;
/*1831*/ 			} else {
/*1831*/ 				return (
/*1831*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*1831*/ 					push((char*) Expressions_t),
/*1831*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1831*/ 					push((char*) NULL),
/*1832*/ 					*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*1833*/ 					(RECORD*) pop()
/*1833*/ 				);
/*1834*/ 			}
/*1835*/ 		} else {
/*1835*/ 			if( Expressions_class == NULL ){
/*1836*/ 				return NULL;
/*1838*/ 			} else {
/*1838*/ 				Search_ResolveClassConst(Expressions_class, Expressions_id, &Expressions_c2, &Expressions_c);
/*1839*/ 				if( Expressions_c == NULL ){
/*1840*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"constant `", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 289), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Expressions_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"' does not exist", (STRING *) 1));
/*1842*/ 					return NULL;
/*1844*/ 				} else {
/*1844*/ 					Accounting_AccountClassConst(Expressions_c2, Expressions_c);
/*1845*/ 					if( ((( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_c, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 290) == 0)) && (Globals_curr_class != Expressions_c2)) ){
/*1846*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"access forbidden to private constant `", Classes_pc(Expressions_class, Expressions_c2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Expressions_id, m2runtime_CHR(39), (STRING *) 1));
/*1848*/ 					} else if( ((( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_c, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 291) == 1)) && (!Classes_IsSubclassOf(Globals_curr_class, Expressions_c2))) ){
/*1849*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"access forbidden to protected constant `", Classes_pc(Expressions_class, Expressions_c2), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Expressions_id, m2runtime_CHR(39), (STRING *) 1));
/*1852*/ 					}
/*1852*/ 					return (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_c, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 292);
/*1855*/ 				}
/*1856*/ 			}
/*1858*/ 		}
/*1858*/ 	} else {
/*1858*/ 		Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"expected class item after `::', found ", Scanner_SymToName(Scanner_sym), (STRING *) 1));
/*1861*/ 	}
/*1861*/ 	m2runtime_missing_return(Expressions_0err_entry_get, 293);
/*1861*/ 	return NULL;
/*1863*/ }


/*1865*/ RECORD *
/*1865*/ Expressions_ParseSelf(void)
/*1865*/ {
/*1865*/ 	Scanner_ReadSym();
/*1866*/ 	Scanner_Expect(19, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"expected `::' after `self'");
/*1867*/ 	if( (Globals_php_ver == 4) ){
/*1868*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"invalid `self::' (PHP 5)");
/*1870*/ 	}
/*1870*/ 	if( Globals_curr_class == NULL ){
/*1871*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"invalid `self::': not inside a class");
/*1873*/ 	} else {
/*1873*/ 		return Expressions_ParseClassStaticAccess(Globals_curr_class);
/*1876*/ 	}
/*1876*/ 	m2runtime_missing_return(Expressions_0err_entry_get, 294);
/*1876*/ 	return NULL;
/*1878*/ }


/*1880*/ RECORD *
/*1880*/ Expressions_ParseStatic(void)
/*1880*/ {
/*1880*/ 	Scanner_ReadSym();
/*1881*/ 	Scanner_Expect(19, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"expected `::' after `static'");
/*1882*/ 	if( (Globals_php_ver == 4) ){
/*1883*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"invalid `static::' (PHP 5)");
/*1885*/ 	}
/*1885*/ 	if( Globals_curr_class == NULL ){
/*1886*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"invalid `static::': not inside a class");
/*1888*/ 	} else {
/*1888*/ 		return Expressions_ParseClassStaticAccess(Globals_curr_class);
/*1891*/ 	}
/*1891*/ 	m2runtime_missing_return(Expressions_0err_entry_get, 295);
/*1891*/ 	return NULL;
/*1893*/ }


/*1895*/ RECORD *
/*1895*/ Expressions_ParseParent(void)
/*1895*/ {
/*1897*/ 	RECORD * Expressions_parent = NULL;
/*1897*/ 	Scanner_ReadSym();
/*1898*/ 	Scanner_Expect(19, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"expected `::' after `parent'");
/*1899*/ 	if( Globals_curr_class == NULL ){
/*1900*/ 		Expressions_parent = NULL;
/*1901*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"invalid `parent::': not inside a class");
/*1903*/ 	} else {
/*1903*/ 		Expressions_parent = (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 296);
/*1904*/ 		if( Expressions_parent == NULL ){
/*1905*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"invalid `parent::': class `", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 297), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' do not has a parent", (STRING *) 1));
/*1909*/ 		}
/*1909*/ 	}
/*1909*/ 	return Expressions_ParseClassStaticAccess(Expressions_parent);
/*1913*/ }


/*1923*/ void
/*1923*/ Expressions_ParseExit(void)
/*1923*/ {
/*1925*/ 	RECORD * Expressions_r = NULL;
/*1925*/ 	Scanner_ReadSym();
/*1926*/ 	if( (Scanner_sym == 12) ){
/*1927*/ 		Scanner_ReadSym();
/*1928*/ 		if( (Scanner_sym != 13) ){
/*1929*/ 			Expressions_r = Expressions_ParseExpr();
/*1930*/ 			if( Expressions_r == NULL ){
/*1932*/ 			} else if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 298) != Globals_int_type) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 299) != Globals_string_type)) ){
/*1933*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"the exit status must be int or string");
/*1937*/ 			}
/*1937*/ 		}
/*1937*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `)'");
/*1938*/ 		Scanner_ReadSym();
/*1941*/ 	}
/*1943*/ }


/*1945*/ void
/*1945*/ Expressions_CheckBoolean(STRING *Expressions_where, RECORD *Expressions_r)
/*1945*/ {
/*1945*/ 	if( Expressions_r == NULL ){
/*1949*/ 		return ;
/*1950*/ 	}
/*1950*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 300), 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 301)){

/*1951*/ 	case 2:
/*1952*/ 	return ;
/*1952*/ 	break;

/*1952*/ 	case 3:
/*1953*/ 	Scanner_Error(m2runtime_concat_STRING(0, Expressions_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)": expected expression of the type boolean, but found ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"an integer value. Remember that 0 evaluates to FALSE, and ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"any other integer value evaluates to TRUE.", (STRING *) 1));
/*1956*/ 	break;

/*1956*/ 	case 4:
/*1957*/ 	Scanner_Error(m2runtime_concat_STRING(0, Expressions_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)": expected expression of the type boolean, but found ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\102,\0,\0,\0)"a float value. Remember that 0.0 evaluates to FALSE and any other ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"value evaluates to TRUE.", (STRING *) 1));
/*1960*/ 	break;

/*1960*/ 	case 5:
/*1961*/ 	Scanner_Error(m2runtime_concat_STRING(0, Expressions_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)": expected expression of the type boolean, but found ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)"a string value. Remember that the empty string \042\042, the string ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"\0420\042 and the NULL string all evaluate to FALSE and any other ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"string evaluates to TRUE.", (STRING *) 1));
/*1965*/ 	break;

/*1965*/ 	case 6:
/*1966*/ 	Scanner_Error(m2runtime_concat_STRING(0, Expressions_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)": expected expression of the type boolean, but found ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 302)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)". Remember that an array with zero elements ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"evaluates to FALSE, and an array with one or more elements ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"evaluates to TRUE.", (STRING *) 1));
/*1970*/ 	break;

/*1970*/ 	case 7:
/*1971*/ 	Scanner_Error(m2runtime_concat_STRING(0, Expressions_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)": expected expression of the type boolean, but found ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"a mixed value", (STRING *) 1));
/*1973*/ 	break;

/*1973*/ 	case 8:
/*1974*/ 	Scanner_Error(m2runtime_concat_STRING(0, Expressions_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)": expected expression of the type boolean, but found ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\102,\0,\0,\0)"a resource. Remember that a resource evaluates always to TRUE, so ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\103,\0,\0,\0)"that this expression is useless. Remember too that some functions, ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\101,\0,\0,\0)"formally declared to return a resource, might return the boolean ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\107,\0,\0,\0)"value FALSE on error; if this is the case, rewrite as (EXPR) !== FALSE.", (STRING *) 1));
/*1979*/ 	break;

/*1979*/ 	case 9:
/*1980*/ 	Scanner_Error(m2runtime_concat_STRING(0, Expressions_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)": expected expression of the type boolean, but found ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 303)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)". Remember that an object evaluates to FALSE if it has no ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\100,\0,\0,\0)"properties, and evaluates to TRUE if it has at least a property.", (STRING *) 1));
/*1985*/ 	break;

/*1985*/ 	default:
/*1985*/ 	Scanner_Error(m2runtime_concat_STRING(0, Expressions_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)": invalid type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 304)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)", expected expression of type boolean", (STRING *) 1));
/*1989*/ 	}
/*1991*/ }


/*1994*/ RECORD *
/*1994*/ Expressions_ParseExpr(void)
/*1994*/ {

/*1999*/ 	RECORD *
/*1999*/ 	Expressions_ParseVarRHS(void)
/*1999*/ 	{

/*2000*/ 		STRING *
/*2000*/ 		Expressions_DereferenceGLOBALS(void)
/*2000*/ 		{
/*2000*/ 			RECORD * Expressions_r = NULL;
/*2002*/ 			STRING * Expressions_n = NULL;
/*2002*/ 			Scanner_ReadSym();
/*2003*/ 			Expressions_r = Expressions_ParseExpr();
/*2004*/ 			Scanner_Expect(15, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `]'");
/*2005*/ 			Scanner_ReadSym();
/*2006*/ 			if( Expressions_r == NULL ){
/*2007*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"can't parse the name of the global variable");
/*2008*/ 				return NULL;
/*2009*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 305) != Globals_string_type ){
/*2010*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"$GLOBALS[?]: required string, found ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 306)), (STRING *) 1));
/*2012*/ 				return NULL;
/*2014*/ 			}
/*2014*/ 			Expressions_n = (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_r, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 307);
/*2015*/ 			if( Expressions_n == NULL ){
/*2016*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"$GLOBALS[?]: undetermined variable name");
/*2017*/ 				return NULL;
/*2018*/ 			} else if( (m2runtime_length(Expressions_n) == 0) ){
/*2019*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"$GLOBALS['']: invalid empty string");
/*2020*/ 				return NULL;
/*2021*/ 			} else if( !m2_match(Expressions_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"^[a-zA-Z_\200-\377][a-zA-Z_0-9\200-\377]*$") ){
/*2022*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"$GLOBALS['", Expressions_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"']: invalid name, can't be a variable!", (STRING *) 1));
/*2023*/ 				return NULL;
/*2025*/ 			}
/*2025*/ 			return Expressions_n;
/*2029*/ 		}

/*2030*/ 		STRING * Expressions_id = NULL;
/*2031*/ 		RECORD * Expressions_v = NULL;
/*2033*/ 		RECORD * Expressions_t = NULL;
/*2033*/ 		Expressions_id = Scanner_s;
/*2034*/ 		Scanner_ReadSym();
/*2037*/ 		if( ((m2runtime_strcmp(Expressions_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"GLOBALS") == 0) && ((Scanner_sym == 14))) ){
/*2038*/ 			Expressions_id = Expressions_DereferenceGLOBALS();
/*2039*/ 			if( Expressions_id == NULL ){
/*2040*/ 				Expressions_v = NULL;
/*2041*/ 				Expressions_id = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"UNDETERMINED_GLOBAL_VAR";
/*2043*/ 			} else {
/*2043*/ 				Expressions_v = Search_SearchVarInScope(Expressions_id, 0);
/*2044*/ 				if( ((Expressions_v == NULL) && ((Globals_scope > 0))) ){
/*2045*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"$GLOBALS['", Expressions_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"']: undefined global variable", (STRING *) 1));
/*2046*/ 					Expressions_id = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"UNDEFINED_GLOBAL_VAR_", Expressions_id, (STRING *) 1);
/*2050*/ 				}
/*2051*/ 			}
/*2051*/ 		} else {
/*2051*/ 			Expressions_v = Search_SearchVar(Expressions_id);
/*2059*/ 		}
/*2059*/ 		if( (Scanner_sym == 12) ){
/*2060*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"invalid variable-name function (PHPLint restriction)");
/*2061*/ 			Expressions_SkipFuncCall();
/*2062*/ 			return NULL;
/*2065*/ 		} else if( (Scanner_sym == 14) ){
/*2069*/ 			if( Expressions_v == NULL ){
/*2072*/ 				Accounting_AccountVarLHS(Expressions_id, FALSE);
/*2073*/ 				Expressions_v = Search_SearchVar(Expressions_id);
/*2074*/ 				return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 308));
/*2075*/ 			} else if( ! *(int *)m2runtime_dereference_rhs_RECORD(Expressions_v, 7 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 309) ){
/*2078*/ 				Accounting_AccountVarLHS2(Expressions_v);
/*2079*/ 				return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 310));
/*2086*/ 			} else {
/*2086*/ 				Accounting_AccountVarRHS2(Expressions_v);
/*2087*/ 				return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 311));
/*2091*/ 			}
/*2091*/ 		} else if( (((Scanner_sym == 10)) || ((Scanner_sym == 61))) ){
/*2092*/ 			if( Expressions_v == NULL ){
/*2093*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"using unassigned variable `$", Expressions_id, m2runtime_CHR(39), (STRING *) 1));
/*2094*/ 				Accounting_AccountVarLHS(Expressions_id, FALSE);
/*2095*/ 				Expressions_v = Search_SearchVar(Expressions_id);
/*2097*/ 			} else {
/*2097*/ 				Accounting_AccountVarRHS2(Expressions_v);
/*2099*/ 			}
/*2099*/ 			return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 312));
/*2102*/ 		} else if( (Scanner_sym == 31) ){
/*2103*/ 			if( Expressions_v == NULL ){
/*2104*/ 				Accounting_AccountVarLHS(Expressions_id, FALSE);
/*2105*/ 				Expressions_v = Search_SearchVar(Expressions_id);
/*2106*/ 				*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 313) = FALSE;
/*2108*/ 			} else {
/*2108*/ 				Accounting_AccountVarLHS2(Expressions_v);
/*2110*/ 			}
/*2110*/ 			Expressions_t = Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 314));
/*2111*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Expressions_0err_entry_get, 315) = TRUE;
/*2112*/ 			return Expressions_t;
/*2115*/ 		} else if( Expressions_IsAssignOp(Scanner_sym) ){
/*2116*/ 			if( Expressions_v == NULL ){
/*2117*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"using unassigned variable `$", Expressions_id, m2runtime_CHR(39), (STRING *) 1));
/*2118*/ 				Accounting_AccountVarLHS(Expressions_id, FALSE);
/*2119*/ 				Expressions_v = Search_SearchVar(Expressions_id);
/*2121*/ 			} else {
/*2121*/ 				Accounting_AccountVarRHS2(Expressions_v);
/*2123*/ 			}
/*2123*/ 			return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 316));
/*2126*/ 		} else if( (((Scanner_sym == 52)) || ((Scanner_sym == 53))) ){
/*2127*/ 			if( Expressions_v == NULL ){
/*2128*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"using unassigned variable `$", Expressions_id, m2runtime_CHR(39), (STRING *) 1));
/*2129*/ 				Accounting_AccountVarLHS(Expressions_id, FALSE);
/*2130*/ 				Expressions_v = Search_SearchVar(Expressions_id);
/*2131*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 317) = Globals_int_type;
/*2133*/ 			} else {
/*2133*/ 				Accounting_AccountVarRHS2(Expressions_v);
/*2135*/ 			}
/*2135*/ 			return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 318));
/*2138*/ 		} else if( (Scanner_sym == 107) ){
/*2139*/ 			if( Expressions_v == NULL ){
/*2140*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"using unassigned variable `$", Expressions_id, m2runtime_CHR(39), (STRING *) 1));
/*2141*/ 				Accounting_AccountVarLHS(Expressions_id, FALSE);
/*2142*/ 				Expressions_v = Search_SearchVar(Expressions_id);
/*2144*/ 			} else {
/*2144*/ 				Accounting_AccountVarRHS2(Expressions_v);
/*2146*/ 			}
/*2146*/ 			return Expressions_Dereference((RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 319));
/*2149*/ 		} else if( Expressions_v != NULL ){
/*2150*/ 			Accounting_AccountVarRHS2(Expressions_v);
/*2151*/ 			return (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_v, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 320);
/*2155*/ 		} else {
/*2155*/ 			Accounting_AccountVarRHS(Expressions_id);
/*2156*/ 			Expressions_v = Search_SearchVar(Expressions_id);
/*2157*/ 			return (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_v, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 321);
/*2162*/ 		}
/*2162*/ 		m2runtime_missing_return(Expressions_0err_entry_get, 322);
/*2162*/ 		return NULL;
/*2164*/ 	}


/*2166*/ 	RECORD *
/*2166*/ 	Expressions_ParseTerm(void)
/*2166*/ 	{

/*2168*/ 		void
/*2168*/ 		Expressions_ParseIsset(void)
/*2168*/ 		{
/*2168*/ 			Scanner_ReadSym();
/*2169*/ 			Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"expected `(' after `isset'");
/*2171*/ 			do{
/*2171*/ 				Scanner_ReadSym();
/*2172*/ 				Expressions_ParseLHS(NULL);
/*2173*/ 				if( (Scanner_sym == 16) ){
/*2175*/ 				} else if( (Scanner_sym == 13) ){
/*2176*/ 					Scanner_ReadSym();
/*2178*/ 					return ;
/*2179*/ 				} else {
/*2179*/ 					Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\100,\0,\0,\0)"expected variable name or closing ')' after isset() args, found ", Scanner_SymToName(Scanner_sym), (STRING *) 1));
/*2182*/ 				}
/*2183*/ 			}while(TRUE);
/*2185*/ 		}


/*2187*/ 		RECORD *
/*2187*/ 		Expressions_ParseNew(void)
/*2187*/ 		{
/*2188*/ 			RECORD * Expressions_class = NULL;
/*2189*/ 			RECORD * Expressions_C = NULL;
/*2190*/ 			RECORD * Expressions_c = NULL;
/*2191*/ 			RECORD * Expressions_r = NULL;
/*2193*/ 			RECORD * Expressions_here_ = NULL;
/*2193*/ 			Scanner_ReadSym();
/*2195*/ 			if( (Scanner_sym == 127) ){
/*2196*/ 				Expressions_map_namespace_operator_into_id();
/*2199*/ 			}
/*2199*/ 			if( (Scanner_sym == 29) ){
/*2200*/ 				Expressions_class = Search_SearchClass(Scanner_s);
/*2201*/ 				if( Expressions_class == NULL ){
/*2202*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"unknown class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*2203*/ 					Scanner_ReadSym();
/*2204*/ 					if( (Scanner_sym == 12) ){
/*2205*/ 						Expressions_SkipFuncCall();
/*2207*/ 					}
/*2207*/ 					return NULL;
/*2210*/ 				}
/*2210*/ 			} else if( (Scanner_sym == 103) ){
/*2211*/ 				Expressions_class = Globals_curr_class;
/*2212*/ 				if( Expressions_class == NULL ){
/*2213*/ 					Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"`self': not inside a class");
/*2216*/ 				}
/*2216*/ 			} else if( (Scanner_sym == 101) ){
/*2217*/ 				Expressions_class = Globals_curr_class;
/*2218*/ 				if( Expressions_class == NULL ){
/*2219*/ 					Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"`static': not inside a class");
/*2221*/ 				}
/*2221*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"`new static' is not supported by PHPLint");
/*2223*/ 			} else if( (Scanner_sym == 104) ){
/*2224*/ 				if( Globals_curr_class == NULL ){
/*2225*/ 					Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"`parent': we are not inside a class");
/*2227*/ 				}
/*2227*/ 				Expressions_class = (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 323);
/*2228*/ 				if( Expressions_class == NULL ){
/*2229*/ 					Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"`parent': no parent class");
/*2233*/ 				}
/*2233*/ 			} else if( (Scanner_sym == 20) ){
/*2234*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\135,\0,\0,\0)"expected static class name after `new', variable class name not allowed (PHPLint restriction)");
/*2235*/ 				Scanner_ReadSym();
/*2236*/ 				if( (Scanner_sym == 12) ){
/*2237*/ 					Expressions_SkipFuncCall();
/*2239*/ 				}
/*2239*/ 				return NULL;
/*2241*/ 			} else {
/*2241*/ 				Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"expected class name or `self', `static' or `parent' after `new'");
/*2244*/ 			}
/*2244*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_class, 15 * sizeof(void*) + 6 * sizeof(int), Expressions_0err_entry_get, 324) && ((Scanner_sym != 101))) ){
/*2245*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"cannot instantiate abstract class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*2248*/ 			}
/*2248*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Expressions_class, 15 * sizeof(void*) + 7 * sizeof(int), Expressions_0err_entry_get, 325) ){
/*2249*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"cannot instantiate interface class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*2252*/ 			}
/*2252*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 14 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 326), EMPTY_STRING) > 0 ){
/*2253*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"instantiating object from deprecated class `", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 327), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 14 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 328), (STRING *) 1));
/*2257*/ 			}
/*2257*/ 			Accounting_AccountClass(Expressions_class);
/*2265*/ 			Expressions_C = Expressions_class;
/*2266*/ 			Expressions_here_ = Scanner_here();
/*2268*/ 			do{
/*2268*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Expressions_C, 15 * sizeof(void*) + 11 * sizeof(int), 15, 10 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 329) = Expressions_here_;
/*2269*/ 				if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_C, 9 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 330) != NULL ){
/*2272*/ 					goto m2runtime_loop_1;
/*2272*/ 				}
/*2272*/ 				Expressions_C = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_C, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 331);
/*2273*/ 				if( Expressions_C == NULL ){
/*2276*/ 					goto m2runtime_loop_1;
/*2277*/ 				}
/*2278*/ 			}while(TRUE);
m2runtime_loop_1: ;
/*2278*/ 			if( Expressions_C == NULL ){
/*2280*/ 				Accounting_AccountClass(Expressions_class);
/*2281*/ 				Scanner_ReadSym();
/*2282*/ 				if( (Scanner_sym == 12) ){
/*2283*/ 					Scanner_ReadSym();
/*2284*/ 					if( (Scanner_sym != 13) ){
/*2285*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"Expected `)', found ", Scanner_SymToName(Scanner_sym), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)". The class `", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 332), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"' do not has a constructor, so no arguments are", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)" required", (STRING *) 1));
/*2291*/ 						do{
/*2291*/ 							Expressions_r = Expressions_ParseExpr();
/*2292*/ 							if( (Scanner_sym == 16) ){
/*2293*/ 								Scanner_ReadSym();
/*2296*/ 							} else {
/*2297*/ 								goto m2runtime_loop_2;
/*2298*/ 							}
/*2299*/ 						}while(TRUE);
m2runtime_loop_2: ;
/*2299*/ 					}
/*2299*/ 					Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `)'");
/*2300*/ 					Scanner_ReadSym();
/*2303*/ 				}
/*2304*/ 			} else {
/*2304*/ 				Expressions_c = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_C, 9 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 333);
/*2305*/ 				if( ((( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_c, 9 * sizeof(void*) + 4 * sizeof(int), Expressions_0err_entry_get, 334) == 0)) && (Globals_curr_class != Expressions_C)) ){
/*2306*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"the constructor of the class `", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_C, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 335), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"' is private", (STRING *) 1));
/*2309*/ 				}
/*2309*/ 				if( ((( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_c, 9 * sizeof(void*) + 4 * sizeof(int), Expressions_0err_entry_get, 336) == 1)) && !Classes_IsSubclassOf(Globals_curr_class, Expressions_C)) ){
/*2311*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"the constructor of the class `", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_C, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 337), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"' is protected", (STRING *) 1));
/*2314*/ 				}
/*2314*/ 				Scanner_ReadSym();
/*2315*/ 				if( (Scanner_sym == 12) ){
/*2316*/ 					Expressions_ParseArgsListCall(FALSE, m2runtime_concat_STRING(0, Classes_pc(Expressions_class, Expressions_C), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_c, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 338), (STRING *) 1), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_c, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 339), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_c, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 340));
/*2318*/ 				} else if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_c, 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 341), 2 * sizeof(void*) + 3 * sizeof(int), Expressions_0err_entry_get, 342) > 0) ){
/*2319*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"missing required arguments for constructor ", Classes_pc(Expressions_class, Expressions_C), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_c, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 343), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_c, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 344)), (STRING *) 1));
/*2323*/ 				} else {
/*2323*/ 					Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"missing parentheses after class name. Although ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"the constructor ", Classes_pc(Expressions_class, Expressions_C), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Expressions_c, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 345), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)" has no mandatory arguments, it's a good habit", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)" to provide these parentheses.", (STRING *) 1));
/*2329*/ 				}
/*2329*/ 				Errors_RaiseErrors( *(int *)m2runtime_dereference_rhs_RECORD(Expressions_c, 9 * sizeof(void*) + 9 * sizeof(int), Expressions_0err_entry_get, 346));
/*2330*/ 				Exceptions_ThrowExceptions((ARRAY *)m2runtime_dereference_rhs_RECORD(Expressions_c, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 347));
/*2333*/ 			}
/*2333*/ 			return (
/*2333*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2333*/ 				push((char*) (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_class, 5 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 348)),
/*2333*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2333*/ 				push((char*) NULL),
/*2334*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2335*/ 				(RECORD*) pop()
/*2335*/ 			);
/*2337*/ 		}


/*2339*/ 		RECORD *
/*2339*/ 		Expressions_ParseClone(void)
/*2339*/ 		{
/*2340*/ 			RECORD * Expressions_r = NULL;
/*2341*/ 			RECORD * Expressions_C = NULL;
/*2343*/ 			RECORD * Expressions_m = NULL;
/*2343*/ 			Scanner_ReadSym();
/*2344*/ 			Expressions_r = Expressions_ParseTerm();
/*2345*/ 			if( Expressions_r == NULL ){
/*2347*/ 			} else if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 349), 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 350) == 9) ){
/*2349*/ 				Expressions_C = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 351), 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 352);
/*2350*/ 				if( Expressions_C != NULL ){
/*2351*/ 					Classes_ResolveClassMethod(Expressions_C, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__clone", &Expressions_C, &Expressions_m);
/*2352*/ 					if( Expressions_m != NULL ){
/*2353*/ 						Accounting_AccountClassMethod(Expressions_C, Expressions_m);
/*2356*/ 					}
/*2358*/ 				}
/*2358*/ 			} else {
/*2358*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"invalid type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 353)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" for `clone'", (STRING *) 1));
/*2359*/ 				Expressions_r = NULL;
/*2362*/ 			}
/*2362*/ 			return Expressions_r;
/*2367*/ 		}

/*2368*/ 		STRING * Expressions_id = NULL;
/*2369*/ 		RECORD * Expressions_r = NULL;
/*2370*/ 		RECORD * Expressions_t = NULL;
/*2371*/ 		RECORD * Expressions_class = NULL;
/*2373*/ 		int Expressions_forced_typecast = 0;
/*2373*/ 		if( (Scanner_sym == 127) ){
/*2374*/ 			Expressions_map_namespace_operator_into_id();
/*2377*/ 		}
/*2377*/ 		switch(Scanner_sym){

/*2379*/ 		case 63:
/*2380*/ 		Expressions_r = (
/*2380*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2380*/ 			push((char*) Globals_null_type),
/*2380*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2380*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL"),
/*2381*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2381*/ 			(RECORD*) pop()
/*2381*/ 		);
/*2381*/ 		Scanner_ReadSym();
/*2383*/ 		break;

/*2383*/ 		case 65:
/*2384*/ 		Expressions_r = (
/*2384*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2384*/ 			push((char*) Globals_boolean_type),
/*2384*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2384*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE"),
/*2385*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2385*/ 			(RECORD*) pop()
/*2385*/ 		);
/*2385*/ 		Scanner_ReadSym();
/*2387*/ 		break;

/*2387*/ 		case 66:
/*2388*/ 		Expressions_r = (
/*2388*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2388*/ 			push((char*) Globals_boolean_type),
/*2388*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2388*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE"),
/*2389*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2389*/ 			(RECORD*) pop()
/*2389*/ 		);
/*2389*/ 		Scanner_ReadSym();
/*2391*/ 		break;

/*2391*/ 		case 38:
/*2392*/ 		Expressions_r = (
/*2392*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2392*/ 			push((char*) Globals_int_type),
/*2392*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2392*/ 			push((char*) Scanner_s),
/*2393*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2393*/ 			(RECORD*) pop()
/*2393*/ 		);
/*2393*/ 		Scanner_ReadSym();
/*2395*/ 		break;

/*2395*/ 		case 39:
/*2396*/ 		Expressions_r = (
/*2396*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2396*/ 			push((char*) Globals_float_type),
/*2396*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2396*/ 			push((char*) Scanner_s),
/*2397*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2397*/ 			(RECORD*) pop()
/*2397*/ 		);
/*2397*/ 		Scanner_ReadSym();
/*2399*/ 		break;

/*2399*/ 		case 33:
/*2400*/ 		Expressions_r = (
/*2400*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2400*/ 			push((char*) Globals_string_type),
/*2400*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2400*/ 			push((char*) Scanner_s),
/*2401*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2401*/ 			(RECORD*) pop()
/*2401*/ 		);
/*2401*/ 		Scanner_ReadSym();
/*2403*/ 		break;

/*2403*/ 		case 34:
/*2404*/ 		Expressions_r = Expressions_ParseDoubleQuotedStringWithEmbeddedVars(FALSE);
/*2406*/ 		break;

/*2406*/ 		case 37:
/*2407*/ 		Expressions_r = Expressions_ParseDoubleQuotedStringWithEmbeddedVars(FALSE);
/*2409*/ 		break;

/*2409*/ 		case 73:
/*2410*/ 		Scanner_ReadSym();
/*2411*/ 		Expressions_r = Expressions_ParseTerm();
/*2413*/ 		break;

/*2413*/ 		case 20:
/*2414*/ 		Expressions_t = Expressions_ParseVarRHS();
/*2415*/ 		if( Expressions_t == NULL ){
/*2416*/ 			Expressions_r = NULL;
/*2418*/ 		} else {
/*2418*/ 			Expressions_r = (
/*2418*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2418*/ 				push((char*) Expressions_t),
/*2418*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2418*/ 				push((char*) NULL),
/*2419*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2420*/ 				(RECORD*) pop()
/*2420*/ 			);
/*2421*/ 		}
/*2421*/ 		break;

/*2421*/ 		case 29:
/*2422*/ 		Expressions_id = Scanner_s;
/*2423*/ 		Scanner_ReadSym();
/*2424*/ 		if( (Scanner_sym == 12) ){
/*2425*/ 			Expressions_t = Expressions_ParseFuncCall(Expressions_id, TRUE);
/*2426*/ 			if( (Scanner_sym == 61) ){
/*2427*/ 				if( (Globals_php_ver == 4) ){
/*2428*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"cannot dereference object returned by function");
/*2430*/ 				}
/*2430*/ 				Expressions_t = Expressions_Dereference(&Expressions_t);
/*2432*/ 			}
/*2432*/ 			if( Expressions_t == NULL ){
/*2433*/ 				Expressions_r = NULL;
/*2435*/ 			} else {
/*2435*/ 				Expressions_r = (
/*2435*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2435*/ 					push((char*) Expressions_t),
/*2435*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2435*/ 					push((char*) NULL),
/*2436*/ 					*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2437*/ 					(RECORD*) pop()
/*2437*/ 				);
/*2438*/ 			}
/*2438*/ 		} else if( (Scanner_sym == 19) ){
/*2439*/ 			Expressions_class = Search_SearchClass(Expressions_id);
/*2440*/ 			if( Expressions_class == NULL ){
/*2441*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"unknown class `", Expressions_id, m2runtime_CHR(39), (STRING *) 1));
/*2443*/ 			}
/*2443*/ 			return Expressions_ParseClassStaticAccess(Expressions_class);
/*2446*/ 		} else {
/*2446*/ 			Expressions_r = Accounting_AccountConstRHS(Expressions_id);
/*2449*/ 		}
/*2449*/ 		break;

/*2449*/ 		case 113:
/*2450*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\233,\0,\0,\0)"`exit()' (aka `die()') isn't a function, it is a statement. Trying to continue anyway, but probably the result of the expression will be of the wrong type.");
/*2451*/ 		Expressions_ParseExit();
/*2452*/ 		Expressions_r = NULL;
/*2454*/ 		break;

/*2454*/ 		case 103:
/*2455*/ 		Expressions_r = Expressions_ParseSelf();
/*2457*/ 		break;

/*2457*/ 		case 101:
/*2458*/ 		Expressions_r = Expressions_ParseStatic();
/*2460*/ 		break;

/*2460*/ 		case 104:
/*2461*/ 		Expressions_r = Expressions_ParseParent();
/*2463*/ 		break;

/*2463*/ 		case 105:
/*2464*/ 		Expressions_r = Expressions_ParseNew();
/*2466*/ 		break;

/*2466*/ 		case 106:
/*2467*/ 		Expressions_r = Expressions_ParseClone();
/*2469*/ 		break;

/*2469*/ 		case 122:
/*2470*/ 		Expressions_ParseIsset();
/*2471*/ 		Expressions_r = (
/*2471*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2471*/ 			push((char*) Globals_boolean_type),
/*2471*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2471*/ 			push((char*) NULL),
/*2472*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2473*/ 			(RECORD*) pop()
/*2473*/ 		);
/*2473*/ 		break;

/*2473*/ 		case 70:
/*2474*/ 		Scanner_ReadSym();
/*2475*/ 		Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"expected `(' after `array'");
/*2476*/ 		Expressions_r = Expressions_ParseArray(FALSE);
/*2478*/ 		break;

/*2478*/ 		case 108:
/*2479*/ 		Expressions_r = Expressions_ParseList();
/*2481*/ 		break;

/*2481*/ 		case 12:
/*2483*/ 		Scanner_ReadSym();
/*2484*/ 		switch(Scanner_sym){

/*2486*/ 		case 64:
/*2487*/ 		Scanner_ReadSym();
/*2488*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"expected closing `)' in typecast");
/*2489*/ 		Scanner_ReadSym();
/*2490*/ 		Expressions_r = Expressions_ParseTerm();
/*2491*/ 		Expressions_r = Operators_EvalValueConversion(Expressions_r, Globals_boolean_type);
/*2493*/ 		break;

/*2493*/ 		case 67:
/*2494*/ 		Scanner_ReadSym();
/*2495*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"expected closing `)' in typecast");
/*2496*/ 		Scanner_ReadSym();
/*2497*/ 		Expressions_r = Expressions_ParseTerm();
/*2498*/ 		Expressions_r = Operators_EvalValueConversion(Expressions_r, Globals_int_type);
/*2500*/ 		break;

/*2500*/ 		case 68:
/*2501*/ 		Scanner_ReadSym();
/*2502*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"expected closing `)' in typecast");
/*2503*/ 		Scanner_ReadSym();
/*2504*/ 		Expressions_r = Expressions_ParseTerm();
/*2505*/ 		Expressions_r = Operators_EvalValueConversion(Expressions_r, Globals_float_type);
/*2507*/ 		break;

/*2507*/ 		case 69:
/*2508*/ 		Scanner_ReadSym();
/*2509*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"expected closing `)' in typecast");
/*2510*/ 		Scanner_ReadSym();
/*2511*/ 		Expressions_r = Expressions_ParseTerm();
/*2512*/ 		Expressions_r = Operators_EvalValueConversion(Expressions_r, Globals_string_type);
/*2514*/ 		break;

/*2514*/ 		case 70:
/*2516*/ 		Scanner_ReadSym();
/*2517*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"expected closing `)' in typecast");
/*2518*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"forbidden `(array)' typecast");
/*2519*/ 		Scanner_ReadSym();
/*2520*/ 		Expressions_r = Expressions_ParseTerm();
/*2521*/ 		Expressions_r = (
/*2521*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2521*/ 			push((char*) (
/*2521*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*2521*/ 				*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*2521*/ 				*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*2521*/ 				push((char*) NULL),
/*2521*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2521*/ 				push((char*) NULL),
/*2521*/ 				*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2521*/ 				(RECORD*) pop()
/*2521*/ 			)),
/*2521*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2521*/ 			push((char*) NULL),
/*2522*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2523*/ 			(RECORD*) pop()
/*2523*/ 		);
/*2523*/ 		break;

/*2523*/ 		case 71:
/*2524*/ 		Scanner_ReadSym();
/*2525*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"expected `)' after typecast");
/*2526*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"forbidden `(object)' typecast");
/*2527*/ 		Scanner_ReadSym();
/*2528*/ 		Expressions_r = Expressions_ParseTerm();
/*2529*/ 		Expressions_r = (
/*2529*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2529*/ 			push((char*) Globals_object_type),
/*2529*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2529*/ 			push((char*) NULL),
/*2530*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2531*/ 			(RECORD*) pop()
/*2531*/ 		);
/*2531*/ 		break;

/*2532*/ 		default:
/*2532*/ 		Expressions_r = Expressions_ParseExpr();
/*2533*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"missing `)'");
/*2534*/ 		Scanner_ReadSym();
/*2537*/ 		}
/*2537*/ 		break;

/*2537*/ 		case 157:
/*2539*/ 		Expressions_forced_typecast = FALSE;
/*2540*/ 		Scanner_ReadSym();
/*2541*/ 		if( (((Scanner_sym == 153)) && (m2runtime_strcmp(Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"__phplint_forced_typecast__") == 0)) ){
/*2542*/ 			Expressions_forced_typecast = TRUE;
/*2543*/ 			Scanner_ReadSym();
/*2545*/ 		}
/*2545*/ 		Expressions_t = Expressions_ParseType(FALSE);
/*2546*/ 		Scanner_Expect(158, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"expected closing `)' in formal typecast");
/*2547*/ 		Scanner_ReadSym();
/*2548*/ 		Expressions_r = Expressions_ParseTerm();
/*2556*/ 		if( (((Globals_php_ver == 5)) && (Expressions_r != NULL) && !Expressions_forced_typecast) ){
/*2557*/ 			if( (((( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 354), 2 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 355) == 6)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Expressions_r, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 356), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"array()") == 0)) || (((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 357) == Globals_null_type) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Expressions_r, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 358), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL") == 0))) ){
/*2561*/ 			} else {
/*2561*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\230,\0,\0,\0)"formal typecast in non-static expression allowed only if applied to NULL or empty array array(). Hint: have a look at the PHPLint magic function cast().");
/*2564*/ 			}
/*2564*/ 		}
/*2564*/ 		Expressions_r = Operators_EvalTypeConversion(Expressions_r, Expressions_t);
/*2567*/ 		break;

/*2567*/ 		default:
/*2567*/ 		Scanner_UnexpectedSymbol();
/*2571*/ 		}
/*2571*/ 		return Expressions_r;
/*2576*/ 	}


/*2578*/ 	RECORD *
/*2578*/ 	Expressions_e18(void)
/*2578*/ 	{
/*2580*/ 		RECORD * Expressions_r = NULL;
/*2580*/ 		if( (((Scanner_sym == 52)) || ((Scanner_sym == 53))) ){
/*2581*/ 			Scanner_ReadSym();
/*2582*/ 			Expressions_ParseLHS(Globals_int_type);
/*2583*/ 			Expressions_r = (
/*2583*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2583*/ 				push((char*) Globals_int_type),
/*2583*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2583*/ 				push((char*) NULL),
/*2584*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2585*/ 				(RECORD*) pop()
/*2585*/ 			);
/*2585*/ 		} else {
/*2585*/ 			Expressions_r = Expressions_ParseTerm();
/*2587*/ 		}
/*2587*/ 		return Expressions_r;
/*2591*/ 	}


/*2593*/ 	RECORD *
/*2593*/ 	Expressions_e17(void)
/*2593*/ 	{
/*2595*/ 		RECORD * Expressions_r = NULL;
/*2595*/ 		if( (Scanner_sym == 54) ){
/*2596*/ 			Scanner_ReadSym();
/*2597*/ 			Expressions_r = Operators_EvalNot(Expressions_e17());
/*2598*/ 		} else if( (Scanner_sym == 40) ){
/*2599*/ 			Scanner_ReadSym();
/*2600*/ 			Expressions_r = Operators_EvalUnaryPlusMinus(FALSE, Expressions_e17());
/*2601*/ 		} else if( (Scanner_sym == 41) ){
/*2602*/ 			Scanner_ReadSym();
/*2603*/ 			Expressions_r = Operators_EvalUnaryPlusMinus(TRUE, Expressions_e17());
/*2604*/ 		} else if( (Scanner_sym == 90) ){
/*2605*/ 			Scanner_ReadSym();
/*2606*/ 			Expressions_r = Operators_EvalBitNot(Expressions_e17());
/*2607*/ 		} else if( (Scanner_sym == 59) ){
/*2608*/ 			Errors_EnteringSilencer();
/*2609*/ 			Scanner_ReadSym();
/*2610*/ 			Expressions_r = Expressions_e17();
/*2611*/ 			Errors_ExitingSilencer();
/*2613*/ 		} else {
/*2613*/ 			Expressions_r = Expressions_e18();
/*2615*/ 		}
/*2615*/ 		return Expressions_r;
/*2619*/ 	}


/*2620*/ 	RECORD *
/*2620*/ 	Expressions_e16(void)
/*2620*/ 	{
/*2620*/ 		RECORD * Expressions_t = NULL;
/*2620*/ 		RECORD * Expressions_r = NULL;
/*2622*/ 		int Expressions_op = 0;
/*2622*/ 		Expressions_r = Expressions_e17();
/*2623*/ 		while( (((Scanner_sym == 42)) || ((Scanner_sym == 43)) || ((Scanner_sym == 74))) ){
/*2624*/ 			Expressions_op = Scanner_sym;
/*2625*/ 			Scanner_ReadSym();
/*2626*/ 			Expressions_t = Expressions_e17();
/*2627*/ 			switch(Expressions_op){

/*2628*/ 			case 42:
/*2628*/ 			Expressions_r = Operators_EvalMult(Expressions_r, Expressions_t);
/*2629*/ 			break;

/*2629*/ 			case 43:
/*2629*/ 			Expressions_r = Operators_EvalDiv(Expressions_r, Expressions_t);
/*2630*/ 			break;

/*2630*/ 			case 74:
/*2630*/ 			Expressions_r = Operators_EvalMod(Expressions_r, Expressions_t);
/*2632*/ 			break;

/*2632*/ 			default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 359);
/*2633*/ 			}
/*2633*/ 		}
/*2633*/ 		return Expressions_r;
/*2637*/ 	}


/*2638*/ 	RECORD *
/*2638*/ 	Expressions_e15(void)
/*2638*/ 	{
/*2638*/ 		RECORD * Expressions_q = NULL;
/*2638*/ 		RECORD * Expressions_r = NULL;
/*2640*/ 		int Expressions_op = 0;
/*2640*/ 		Expressions_r = Expressions_e16();
/*2641*/ 		while( (((Scanner_sym == 40)) || ((Scanner_sym == 41)) || ((Scanner_sym == 60))) ){
/*2642*/ 			Expressions_op = Scanner_sym;
/*2643*/ 			Scanner_ReadSym();
/*2644*/ 			Expressions_q = Expressions_e16();
/*2645*/ 			switch(Expressions_op){

/*2646*/ 			case 40:
/*2646*/ 			Expressions_r = Operators_EvalPlus(Expressions_r, Expressions_q);
/*2647*/ 			break;

/*2647*/ 			case 41:
/*2647*/ 			Expressions_r = Operators_EvalMinus(Expressions_r, Expressions_q);
/*2648*/ 			break;

/*2648*/ 			case 60:
/*2648*/ 			Expressions_r = Operators_EvalPeriod(Expressions_r, Expressions_q);
/*2650*/ 			break;

/*2650*/ 			default: m2runtime_missing_case_in_switch(Expressions_0err_entry_get, 360);
/*2651*/ 			}
/*2651*/ 		}
/*2651*/ 		return Expressions_r;
/*2655*/ 	}


/*2656*/ 	RECORD *
/*2656*/ 	Expressions_e14(void)
/*2656*/ 	{
/*2656*/ 		RECORD * Expressions_t = NULL;
/*2656*/ 		RECORD * Expressions_r = NULL;
/*2658*/ 		int Expressions_op = 0;
/*2658*/ 		Expressions_r = Expressions_e15();
/*2659*/ 		while( (((Scanner_sym == 86)) || ((Scanner_sym == 87))) ){
/*2660*/ 			Expressions_op = Scanner_sym;
/*2661*/ 			Scanner_ReadSym();
/*2662*/ 			Expressions_t = Expressions_e15();
/*2663*/ 			if( (Expressions_op == 86) ){
/*2664*/ 				Expressions_r = Operators_EvalLShift(Expressions_r, Expressions_t);
/*2666*/ 			} else {
/*2666*/ 				Expressions_r = Operators_EvalRShift(Expressions_r, Expressions_t);
/*2669*/ 			}
/*2669*/ 		}
/*2669*/ 		return Expressions_r;
/*2673*/ 	}


/*2674*/ 	RECORD *
/*2674*/ 	Expressions_e13(void)
/*2674*/ 	{
/*2674*/ 		RECORD * Expressions_r = NULL;
/*2676*/ 		STRING * Expressions_n = NULL;
/*2676*/ 		Expressions_r = Expressions_e14();
/*2677*/ 		switch(Scanner_sym){

/*2678*/ 		case 50:
/*2678*/ 		Expressions_n = m2runtime_CHR(60);
/*2679*/ 		break;

/*2679*/ 		case 51:
/*2679*/ 		Expressions_n = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"<=";
/*2680*/ 		break;

/*2680*/ 		case 48:
/*2680*/ 		Expressions_n = m2runtime_CHR(62);
/*2681*/ 		break;

/*2681*/ 		case 49:
/*2681*/ 		Expressions_n = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">=";
/*2682*/ 		break;

/*2682*/ 		default:
/*2682*/ 		return Expressions_r;
/*2684*/ 		}
/*2684*/ 		Scanner_ReadSym();
/*2685*/ 		return Operators_EvalCmp(Expressions_n, Expressions_r, Expressions_e14());
/*2689*/ 	}


/*2690*/ 	RECORD *
/*2690*/ 	Expressions_e12(void)
/*2690*/ 	{
/*2692*/ 		RECORD * Expressions_r = NULL;
/*2692*/ 		Expressions_r = Expressions_e13();
/*2693*/ 		switch(Scanner_sym){

/*2695*/ 		case 44:
/*2696*/ 		Scanner_ReadSym();
/*2697*/ 		return Operators_EvalEq((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"==", Expressions_r, Expressions_e13());
/*2699*/ 		break;

/*2699*/ 		case 46:
/*2700*/ 		Scanner_ReadSym();
/*2701*/ 		return Operators_EvalEq((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"!=", Expressions_r, Expressions_e13());
/*2703*/ 		break;

/*2703*/ 		case 45:
/*2703*/ 		case 47:
/*2704*/ 		if( Expressions_r == NULL ){
/*2706*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 361) == Globals_void_type ){
/*2707*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"invalid operand of the type void");
/*2709*/ 		}
/*2709*/ 		Scanner_ReadSym();
/*2710*/ 		if( Expressions_r == NULL ){
/*2712*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 362) == Globals_void_type ){
/*2713*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"invalid operand of the type void");
/*2715*/ 		}
/*2715*/ 		Expressions_r = Expressions_e13();
/*2716*/ 		return (
/*2716*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2716*/ 			push((char*) Globals_boolean_type),
/*2716*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2716*/ 			push((char*) NULL),
/*2717*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2719*/ 			(RECORD*) pop()
/*2719*/ 		);
/*2719*/ 		break;

/*2719*/ 		default:
/*2719*/ 		return Expressions_r;
/*2722*/ 		}
/*2722*/ 		m2runtime_missing_return(Expressions_0err_entry_get, 363);
/*2722*/ 		return NULL;
/*2724*/ 	}


/*2725*/ 	RECORD *
/*2725*/ 	Expressions_e11(void)
/*2725*/ 	{
/*2727*/ 		RECORD * Expressions_r = NULL;
/*2727*/ 		Expressions_r = Expressions_e12();
/*2728*/ 		while( (Scanner_sym == 73) ){
/*2729*/ 			Scanner_ReadSym();
/*2730*/ 			Expressions_r = Operators_EvalBitAnd(Expressions_r, Expressions_e12());
/*2732*/ 		}
/*2732*/ 		return Expressions_r;
/*2736*/ 	}


/*2737*/ 	RECORD *
/*2737*/ 	Expressions_e10(void)
/*2737*/ 	{
/*2739*/ 		RECORD * Expressions_r = NULL;
/*2739*/ 		Expressions_r = Expressions_e11();
/*2740*/ 		while( (Scanner_sym == 88) ){
/*2741*/ 			Scanner_ReadSym();
/*2742*/ 			Expressions_r = Operators_EvalBitXor(Expressions_r, Expressions_e11());
/*2744*/ 		}
/*2744*/ 		return Expressions_r;
/*2748*/ 	}


/*2749*/ 	RECORD *
/*2749*/ 	Expressions_e9(void)
/*2749*/ 	{
/*2751*/ 		RECORD * Expressions_r = NULL;
/*2751*/ 		Expressions_r = Expressions_e10();
/*2752*/ 		while( (Scanner_sym == 72) ){
/*2753*/ 			Scanner_ReadSym();
/*2754*/ 			Expressions_r = Operators_EvalBitOr(Expressions_r, Expressions_e10());
/*2756*/ 		}
/*2756*/ 		return Expressions_r;
/*2760*/ 	}


/*2761*/ 	RECORD *
/*2761*/ 	Expressions_e8(void)
/*2761*/ 	{
/*2763*/ 		RECORD * Expressions_r = NULL;
/*2763*/ 		Expressions_r = Expressions_e9();
/*2764*/ 		while( (Scanner_sym == 57) ){
/*2765*/ 			Scanner_ReadSym();
/*2766*/ 			Expressions_r = Operators_EvalAnd((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"&&", Expressions_r, Expressions_e9());
/*2768*/ 		}
/*2768*/ 		return Expressions_r;
/*2772*/ 	}


/*2773*/ 	RECORD *
/*2773*/ 	Expressions_e7(void)
/*2773*/ 	{
/*2775*/ 		RECORD * Expressions_r = NULL;
/*2775*/ 		Expressions_r = Expressions_e8();
/*2776*/ 		while( (Scanner_sym == 55) ){
/*2777*/ 			Scanner_ReadSym();
/*2778*/ 			Expressions_r = Operators_EvalOr((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"||", Expressions_r, Expressions_e8());
/*2780*/ 		}
/*2780*/ 		return Expressions_r;
/*2784*/ 	}


/*2785*/ 	RECORD *
/*2785*/ 	Expressions_e6(void)
/*2785*/ 	{
/*2785*/ 		RECORD * Expressions_b = NULL;
/*2785*/ 		RECORD * Expressions_a = NULL;
/*2785*/ 		RECORD * Expressions_r = NULL;
/*2787*/ 		RECORD * Expressions_t = NULL;
/*2788*/ 		if( (Scanner_sym == 115) ){
/*2789*/ 			Scanner_ReadSym();
/*2790*/ 			Expressions_r = Expressions_e6();
/*2791*/ 			if( Expressions_r == NULL ){
/*2794*/ 			} else {
/*2794*/ 				Expressions_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 364);
/*2795*/ 				if( ((Expressions_t == Globals_int_type) || (Expressions_t == Globals_float_type) || (Expressions_t == Globals_string_type) || Classes_IsObjectConvertibleToString(Expressions_t)) ){
/*2799*/ 				} else if( Expressions_t == Globals_boolean_type ){
/*2800*/ 					Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\151,\0,\0,\0)"found boolean value: remember that FALSE gets rendered as empty string \042\042 while TRUE gets rendered as \0421\042");
/*2802*/ 				} else {
/*2802*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"found argument of the type ", Types_TypeToString(Expressions_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)". The arguments of the `print' function must be of", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)" type int, float, string.", (STRING *) 1));
/*2807*/ 				}
/*2807*/ 			}
/*2807*/ 			return (
/*2807*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2807*/ 				push((char*) Globals_int_type),
/*2807*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2807*/ 				push((char*) m2runtime_CHR(49)),
/*2808*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2809*/ 				(RECORD*) pop()
/*2809*/ 			);
/*2810*/ 		}
/*2810*/ 		Expressions_r = Expressions_e7();
/*2811*/ 		while( (Scanner_sym == 30) ){
/*2812*/ 			Expressions_CheckBoolean((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"EXPR ? ...:...", Expressions_r);
/*2813*/ 			Scanner_ReadSym();
/*2814*/ 			if( (Scanner_sym == 18) ){
/*2815*/ 				Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"unsupported short ternary operator ?:");
/*2817*/ 			}
/*2817*/ 			Expressions_a = Expressions_ParseExpr();
/*2818*/ 			Scanner_Expect(18, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `:'");
/*2819*/ 			Scanner_ReadSym();
/*2820*/ 			Expressions_b = Expressions_ParseExpr();
/*2821*/ 			if( ((Expressions_a != NULL) && (Expressions_b != NULL) && !Types_SameType((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 365), (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_b, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 366))) ){
/*2822*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"`...? EXPR1 : EXPR2': type mismatch: EXPR1 is ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_a, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 367)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)", EXPR2 is ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_b, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 368)), (STRING *) 1));
/*2826*/ 			}
/*2826*/ 			Expressions_r = Expressions_a;
/*2828*/ 		}
/*2828*/ 		return Expressions_r;
/*2832*/ 	}


/*2833*/ 	RECORD *
/*2833*/ 	Expressions_e5(void)
/*2833*/ 	{
/*2835*/ 		RECORD * Expressions_r = NULL;
/*2835*/ 		Expressions_r = Expressions_e6();
/*2836*/ 		if( Expressions_IsAssignOp(Scanner_sym) ){
/*2837*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\151,\0,\0,\0)"invalid left hand side in assignment. Hint: you might want to use the comparison operators `==' or `==='.");
/*2838*/ 			Scanner_ReadSym();
/*2839*/ 			Expressions_r = Expressions_e6();
/*2841*/ 		}
/*2841*/ 		return Expressions_r;
/*2845*/ 	}


/*2846*/ 	RECORD *
/*2846*/ 	Expressions_e4(void)
/*2846*/ 	{
/*2848*/ 		RECORD * Expressions_r = NULL;
/*2848*/ 		Expressions_r = Expressions_e5();
/*2849*/ 		while( (Scanner_sym == 58) ){
/*2850*/ 			Scanner_ReadSym();
/*2851*/ 			Expressions_r = Operators_EvalAnd((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"and", Expressions_r, Expressions_e5());
/*2853*/ 		}
/*2853*/ 		return Expressions_r;
/*2857*/ 	}


/*2858*/ 	RECORD *
/*2858*/ 	Expressions_e3(void)
/*2858*/ 	{
/*2860*/ 		RECORD * Expressions_r = NULL;
/*2860*/ 		Expressions_r = Expressions_e4();
/*2861*/ 		while( (Scanner_sym == 89) ){
/*2862*/ 			Scanner_ReadSym();
/*2863*/ 			Expressions_r = Operators_EvalXor(Expressions_r, Expressions_e4());
/*2865*/ 		}
/*2865*/ 		return Expressions_r;
/*2869*/ 	}

/*2871*/ 	RECORD * Expressions_r = NULL;
/*2871*/ 	Expressions_r = Expressions_e3();
/*2872*/ 	while( (Scanner_sym == 56) ){
/*2873*/ 		Scanner_ReadSym();
/*2874*/ 		Expressions_r = Operators_EvalOr((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"or", Expressions_r, Expressions_e3());
/*2876*/ 	}
/*2876*/ 	return Expressions_r;
/*2880*/ }


/*2881*/ RECORD *
/*2881*/ Expressions_ParseExprList(void)
/*2881*/ {
/*2883*/ 	RECORD * Expressions_r = NULL;
/*2884*/ 	do{
/*2884*/ 		Expressions_r = Expressions_ParseExpr();
/*2885*/ 		if( (Scanner_sym != 16) ){
/*2886*/ 			return Expressions_r;
/*2888*/ 		}
/*2888*/ 		Scanner_ReadSym();
/*2891*/ 	}while(TRUE);
/*2891*/ 	m2runtime_missing_return(Expressions_0err_entry_get, 369);
/*2891*/ 	return NULL;
/*2893*/ }


/*2895*/ RECORD *
/*2895*/ Expressions_ParseStaticExpr(void)
/*2895*/ {

/*2897*/ 	RECORD *
/*2897*/ 	Expressions_ParseStaticExpr_ClassConst(RECORD *Expressions_cl)
/*2897*/ 	{
/*2899*/ 		return Expressions_ParseClassStaticAccess(Expressions_cl);
/*2903*/ 	}

/*2904*/ 	int Expressions_sign = 0;
/*2905*/ 	RECORD * Expressions_r = NULL;
/*2906*/ 	STRING * Expressions_id = NULL;
/*2907*/ 	RECORD * Expressions_parent = NULL;
/*2907*/ 	RECORD * Expressions_class = NULL;
/*2909*/ 	RECORD * Expressions_t = NULL;
/*2909*/ 	if( (Scanner_sym == 127) ){
/*2910*/ 		Expressions_map_namespace_operator_into_id();
/*2913*/ 	}
/*2913*/ 	if( (Scanner_sym == 63) ){
/*2914*/ 		Expressions_r = (
/*2914*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2914*/ 			push((char*) Globals_null_type),
/*2914*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2914*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL"),
/*2915*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2916*/ 			(RECORD*) pop()
/*2916*/ 		);
/*2916*/ 		Scanner_ReadSym();
/*2918*/ 	} else if( (Scanner_sym == 65) ){
/*2919*/ 		Expressions_r = (
/*2919*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2919*/ 			push((char*) Globals_boolean_type),
/*2919*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2919*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE"),
/*2920*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2920*/ 			(RECORD*) pop()
/*2920*/ 		);
/*2920*/ 		Scanner_ReadSym();
/*2922*/ 	} else if( (Scanner_sym == 66) ){
/*2923*/ 		Expressions_r = (
/*2923*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2923*/ 			push((char*) Globals_boolean_type),
/*2923*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2923*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE"),
/*2924*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2924*/ 			(RECORD*) pop()
/*2924*/ 		);
/*2924*/ 		Scanner_ReadSym();
/*2926*/ 	} else if( (((Scanner_sym == 40)) || ((Scanner_sym == 41))) ){
/*2927*/ 		if( (Scanner_sym == 41) ){
/*2928*/ 			Expressions_sign = TRUE;
/*2930*/ 		}
/*2930*/ 		Scanner_ReadSym();
/*2931*/ 		Expressions_r = Expressions_ParseStaticExpr();
/*2932*/ 		if( Expressions_r != NULL ){
/*2933*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 370) == Globals_int_type ){
/*2934*/ 				if( Expressions_sign ){
/*2935*/ 					Expressions_r = (
/*2935*/ 						push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2935*/ 						push((char*) Globals_int_type),
/*2935*/ 						*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2935*/ 						push((char*) m2runtime_itos(-m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Expressions_r, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 371)))),
/*2936*/ 						*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2937*/ 						(RECORD*) pop()
/*2937*/ 					);
/*2937*/ 				}
/*2937*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 372) == Globals_float_type ){
/*2938*/ 				if( Expressions_sign ){
/*2939*/ 					Expressions_r = (
/*2939*/ 						push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2939*/ 						push((char*) Globals_float_type),
/*2939*/ 						*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2939*/ 						push((char*) m2runtime_rtos(-m2_stor((STRING *)m2runtime_dereference_rhs_RECORD(Expressions_r, 1 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 373)))),
/*2940*/ 						*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2941*/ 						(RECORD*) pop()
/*2941*/ 					);
/*2942*/ 				}
/*2942*/ 			} else {
/*2942*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"unary minus on non numeric value");
/*2945*/ 			}
/*2946*/ 		}
/*2946*/ 	} else if( (Scanner_sym == 38) ){
/*2947*/ 		Expressions_r = (
/*2947*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2947*/ 			push((char*) Globals_int_type),
/*2947*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2947*/ 			push((char*) Scanner_s),
/*2948*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2948*/ 			(RECORD*) pop()
/*2948*/ 		);
/*2948*/ 		Scanner_ReadSym();
/*2950*/ 	} else if( (Scanner_sym == 39) ){
/*2951*/ 		Expressions_r = (
/*2951*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2951*/ 			push((char*) Globals_float_type),
/*2951*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2951*/ 			push((char*) Scanner_s),
/*2952*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2952*/ 			(RECORD*) pop()
/*2952*/ 		);
/*2952*/ 		Scanner_ReadSym();
/*2954*/ 	} else if( (Scanner_sym == 33) ){
/*2955*/ 		Expressions_r = (
/*2955*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*2955*/ 			push((char*) Globals_string_type),
/*2955*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2955*/ 			push((char*) Scanner_s),
/*2956*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2956*/ 			(RECORD*) pop()
/*2956*/ 		);
/*2956*/ 		Scanner_ReadSym();
/*2958*/ 	} else if( (Scanner_sym == 34) ){
/*2959*/ 		Expressions_r = Expressions_ParseDoubleQuotedStringWithEmbeddedVars(TRUE);
/*2961*/ 	} else if( (Scanner_sym == 37) ){
/*2962*/ 		Expressions_r = Expressions_ParseDoubleQuotedStringWithEmbeddedVars(TRUE);
/*2964*/ 	} else if( (Scanner_sym == 29) ){
/*2965*/ 		Expressions_id = Scanner_s;
/*2966*/ 		Scanner_ReadSym();
/*2967*/ 		if( (Scanner_sym == 19) ){
/*2968*/ 			Expressions_class = Search_SearchClass(Expressions_id);
/*2969*/ 			if( Expressions_class == NULL ){
/*2970*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"unknown class `", Expressions_id, m2runtime_CHR(39), (STRING *) 1));
/*2972*/ 			}
/*2972*/ 			Expressions_r = Expressions_ParseStaticExpr_ClassConst(Expressions_class);
/*2975*/ 		} else {
/*2975*/ 			Expressions_r = Accounting_AccountConstRHS(Expressions_id);
/*2979*/ 		}
/*2979*/ 	} else if( (Scanner_sym == 103) ){
/*2980*/ 		if( (Globals_php_ver == 4) ){
/*2981*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"invalid `self::' (PHP 5)");
/*2983*/ 		}
/*2983*/ 		if( Globals_curr_class == NULL ){
/*2984*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"`self::': not inside a class");
/*2986*/ 		}
/*2986*/ 		Scanner_ReadSym();
/*2987*/ 		Scanner_Expect(19, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"expected `::'");
/*2988*/ 		Expressions_r = Expressions_ParseStaticExpr_ClassConst(Globals_curr_class);
/*2990*/ 	} else if( (Scanner_sym == 104) ){
/*2991*/ 		if( (Globals_php_ver == 4) ){
/*2992*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"invalid `parent::' (PHP 5)");
/*2994*/ 		}
/*2994*/ 		if( Globals_curr_class == NULL ){
/*2995*/ 			Expressions_parent = NULL;
/*2996*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"`parent::': not inside a class");
/*2997*/ 			Expressions_r = NULL;
/*2999*/ 		} else {
/*2999*/ 			Expressions_parent = (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 3 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 374);
/*3000*/ 			if( Expressions_parent == NULL ){
/*3001*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"invalid `parent::': class `", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 375), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' do not has a parent", (STRING *) 1));
/*3004*/ 			}
/*3004*/ 			Scanner_ReadSym();
/*3005*/ 			Scanner_Expect(19, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"expected `::'");
/*3006*/ 			Expressions_r = Expressions_ParseStaticExpr_ClassConst(Expressions_parent);
/*3009*/ 		}
/*3009*/ 	} else if( (Scanner_sym == 70) ){
/*3010*/ 		Scanner_ReadSym();
/*3011*/ 		if( (Scanner_sym != 12) ){
/*3012*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"expected `(' after `array'");
/*3014*/ 		}
/*3014*/ 		Expressions_r = Expressions_ParseArray(TRUE);
/*3016*/ 	} else if( (Scanner_sym == 157) ){
/*3018*/ 		Scanner_ReadSym();
/*3019*/ 		Expressions_t = Expressions_ParseType(FALSE);
/*3020*/ 		Scanner_Expect(158, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"expected closing `)' in formal typecast");
/*3021*/ 		Scanner_ReadSym();
/*3022*/ 		Expressions_r = Expressions_ParseStaticExpr();
/*3023*/ 		Expressions_r = Operators_EvalTypeConversion(Expressions_r, Expressions_t);
/*3026*/ 	} else {
/*3026*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\106,\0,\0,\0)"invalid static expression -- expected string, constant or static array");
/*3030*/ 	}
/*3030*/ 	return Expressions_r;
/*3034*/ }


/*3035*/ RECORD *
/*3035*/ Expressions_ParseExprOfType(RECORD *Expressions_t)
/*3035*/ {
/*3037*/ 	RECORD * Expressions_r = NULL;
/*3037*/ 	Expressions_r = Expressions_ParseExpr();
/*3038*/ 	if( Expressions_r == NULL ){
/*3039*/ 		return NULL;
/*3040*/ 	} else if( Types_SameType(Expressions_t, (RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 376)) ){
/*3041*/ 		return Expressions_r;
/*3043*/ 	} else {
/*3043*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"found expression of the type `", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Expressions_r, 0 * sizeof(void*) + 2 * sizeof(int), Expressions_0err_entry_get, 377)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"', expected type `", Types_TypeToString(Expressions_t), m2runtime_CHR(39), (STRING *) 1));
/*3045*/ 		return NULL;
/*3048*/ 	}
/*3048*/ 	m2runtime_missing_return(Expressions_0err_entry_get, 378);
/*3048*/ 	return NULL;
/*3050*/ }


char * Expressions_0func[] = {
    "map_namespace_operator_into_id",
    "map_x_namespace_operator_into_id",
    "CleanCurrentScope",
    "ResolveClassProperty",
    "DereferenceClassMethod",
    "ParseTypeName",
    "ParseArray",
    "ParseIndeces",
    "ParseType",
    "MatchArray",
    "LhsMatchRhs",
    "DereferenceLHS",
    "ParseLHS",
    "CheckActualArgument",
    "ParseArgsListCall",
    "ParseClassMethodCall",
    "DereferenceArray",
    "Dereference",
    "ParseFuncCall",
    "ParseArray",
    "ParseDoubleQuotedStringWithEmbeddedVars",
    "ParseList",
    "ParseClassStaticAccess",
    "ParseSelf",
    "ParseStatic",
    "ParseParent",
    "ParseExit",
    "CheckBoolean",
    "DereferenceGLOBALS",
    "ParseVarRHS",
    "ParseNew",
    "ParseClone",
    "ParseTerm",
    "e16",
    "e15",
    "e12",
    "e6",
    "ParseExprList",
    "ParseStaticExpr",
    "ParseExprOfType"
};

int Expressions_0err_entry[] = {
    0 /* map_namespace_operator_into_id */, 27,
    0 /* map_namespace_operator_into_id */, 30,
    0 /* map_namespace_operator_into_id */, 31,
    1 /* map_x_namespace_operator_into_id */, 46,
    1 /* map_x_namespace_operator_into_id */, 49,
    1 /* map_x_namespace_operator_into_id */, 50,
    2 /* CleanCurrentScope */, 61,
    2 /* CleanCurrentScope */, 61,
    2 /* CleanCurrentScope */, 63,
    2 /* CleanCurrentScope */, 63,
    2 /* CleanCurrentScope */, 63,
    2 /* CleanCurrentScope */, 63,
    2 /* CleanCurrentScope */, 64,
    2 /* CleanCurrentScope */, 64,
    2 /* CleanCurrentScope */, 66,
    2 /* CleanCurrentScope */, 66,
    2 /* CleanCurrentScope */, 66,
    2 /* CleanCurrentScope */, 67,
    2 /* CleanCurrentScope */, 70,
    3 /* ResolveClassProperty */, 93,
    3 /* ResolveClassProperty */, 100,
    3 /* ResolveClassProperty */, 108,
    3 /* ResolveClassProperty */, 116,
    3 /* ResolveClassProperty */, 119,
    3 /* ResolveClassProperty */, 123,
    3 /* ResolveClassProperty */, 125,
    3 /* ResolveClassProperty */, 128,
    3 /* ResolveClassProperty */, 130,
    4 /* DereferenceClassMethod */, 175,
    4 /* DereferenceClassMethod */, 179,
    4 /* DereferenceClassMethod */, 180,
    4 /* DereferenceClassMethod */, 184,
    4 /* DereferenceClassMethod */, 187,
    4 /* DereferenceClassMethod */, 196,
    4 /* DereferenceClassMethod */, 198,
    4 /* DereferenceClassMethod */, 200,
    4 /* DereferenceClassMethod */, 204,
    4 /* DereferenceClassMethod */, 207,
    4 /* DereferenceClassMethod */, 216,
    4 /* DereferenceClassMethod */, 218,
    4 /* DereferenceClassMethod */, 220,
    4 /* DereferenceClassMethod */, 224,
    4 /* DereferenceClassMethod */, 229,
    4 /* DereferenceClassMethod */, 234,
    4 /* DereferenceClassMethod */, 236,
    4 /* DereferenceClassMethod */, 240,
    4 /* DereferenceClassMethod */, 241,
    4 /* DereferenceClassMethod */, 245,
    4 /* DereferenceClassMethod */, 250,
    4 /* DereferenceClassMethod */, 254,
    4 /* DereferenceClassMethod */, 256,
    5 /* ParseTypeName */, 323,
    5 /* ParseTypeName */, 336,
    5 /* ParseTypeName */, 347,
    5 /* ParseTypeName */, 356,
    5 /* ParseTypeName */, 361,
    5 /* ParseTypeName */, 361,
    5 /* ParseTypeName */, 365,
    6 /* ParseArray */, 380,
    6 /* ParseArray */, 383,
    6 /* ParseArray */, 385,
    6 /* ParseArray */, 393,
    6 /* ParseArray */, 394,
    6 /* ParseArray */, 398,
    6 /* ParseArray */, 399,
    6 /* ParseArray */, 400,
    7 /* ParseIndeces */, 419,
    7 /* ParseIndeces */, 422,
    7 /* ParseIndeces */, 425,
    7 /* ParseIndeces */, 430,
    7 /* ParseIndeces */, 431,
    7 /* ParseIndeces */, 435,
    8 /* ParseType */, 466,
    9 /* MatchArray */, 486,
    9 /* MatchArray */, 493,
    9 /* MatchArray */, 496,
    9 /* MatchArray */, 506,
    10 /* LhsMatchRhs */, 510,
    10 /* LhsMatchRhs */, 517,
    10 /* LhsMatchRhs */, 523,
    10 /* LhsMatchRhs */, 525,
    10 /* LhsMatchRhs */, 532,
    10 /* LhsMatchRhs */, 538,
    10 /* LhsMatchRhs */, 544,
    10 /* LhsMatchRhs */, 550,
    10 /* LhsMatchRhs */, 556,
    10 /* LhsMatchRhs */, 559,
    10 /* LhsMatchRhs */, 559,
    10 /* LhsMatchRhs */, 560,
    10 /* LhsMatchRhs */, 560,
    10 /* LhsMatchRhs */, 564,
    10 /* LhsMatchRhs */, 570,
    10 /* LhsMatchRhs */, 576,
    10 /* LhsMatchRhs */, 580,
    10 /* LhsMatchRhs */, 582,
    10 /* LhsMatchRhs */, 584,
    10 /* LhsMatchRhs */, 584,
    10 /* LhsMatchRhs */, 591,
    11 /* DereferenceLHS */, 625,
    11 /* DereferenceLHS */, 626,
    11 /* DereferenceLHS */, 633,
    11 /* DereferenceLHS */, 634,
    11 /* DereferenceLHS */, 635,
    11 /* DereferenceLHS */, 636,
    11 /* DereferenceLHS */, 638,
    11 /* DereferenceLHS */, 643,
    11 /* DereferenceLHS */, 644,
    11 /* DereferenceLHS */, 647,
    11 /* DereferenceLHS */, 657,
    11 /* DereferenceLHS */, 659,
    11 /* DereferenceLHS */, 668,
    11 /* DereferenceLHS */, 674,
    11 /* DereferenceLHS */, 675,
    11 /* DereferenceLHS */, 678,
    11 /* DereferenceLHS */, 679,
    11 /* DereferenceLHS */, 683,
    11 /* DereferenceLHS */, 688,
    11 /* DereferenceLHS */, 710,
    11 /* DereferenceLHS */, 713,
    11 /* DereferenceLHS */, 716,
    11 /* DereferenceLHS */, 729,
    11 /* DereferenceLHS */, 736,
    11 /* DereferenceLHS */, 740,
    11 /* DereferenceLHS */, 777,
    12 /* ParseLHS */, 834,
    12 /* ParseLHS */, 852,
    12 /* ParseLHS */, 874,
    12 /* ParseLHS */, 885,
    12 /* ParseLHS */, 900,
    13 /* CheckActualArgument */, 931,
    13 /* CheckActualArgument */, 941,
    13 /* CheckActualArgument */, 943,
    13 /* CheckActualArgument */, 947,
    13 /* CheckActualArgument */, 950,
    13 /* CheckActualArgument */, 951,
    14 /* ParseArgsListCall */, 964,
    14 /* ParseArgsListCall */, 974,
    14 /* ParseArgsListCall */, 975,
    14 /* ParseArgsListCall */, 977,
    14 /* ParseArgsListCall */, 979,
    14 /* ParseArgsListCall */, 979,
    14 /* ParseArgsListCall */, 981,
    14 /* ParseArgsListCall */, 981,
    14 /* ParseArgsListCall */, 982,
    14 /* ParseArgsListCall */, 983,
    14 /* ParseArgsListCall */, 984,
    14 /* ParseArgsListCall */, 985,
    14 /* ParseArgsListCall */, 985,
    14 /* ParseArgsListCall */, 986,
    14 /* ParseArgsListCall */, 987,
    14 /* ParseArgsListCall */, 993,
    14 /* ParseArgsListCall */, 1011,
    14 /* ParseArgsListCall */, 1018,
    14 /* ParseArgsListCall */, 1018,
    14 /* ParseArgsListCall */, 1036,
    15 /* ParseClassMethodCall */, 1071,
    15 /* ParseClassMethodCall */, 1072,
    15 /* ParseClassMethodCall */, 1073,
    15 /* ParseClassMethodCall */, 1074,
    15 /* ParseClassMethodCall */, 1075,
    15 /* ParseClassMethodCall */, 1076,
    15 /* ParseClassMethodCall */, 1077,
    15 /* ParseClassMethodCall */, 1078,
    15 /* ParseClassMethodCall */, 1079,
    15 /* ParseClassMethodCall */, 1081,
    15 /* ParseClassMethodCall */, 1081,
    15 /* ParseClassMethodCall */, 1082,
    15 /* ParseClassMethodCall */, 1085,
    15 /* ParseClassMethodCall */, 1085,
    15 /* ParseClassMethodCall */, 1088,
    15 /* ParseClassMethodCall */, 1097,
    15 /* ParseClassMethodCall */, 1099,
    15 /* ParseClassMethodCall */, 1102,
    15 /* ParseClassMethodCall */, 1102,
    15 /* ParseClassMethodCall */, 1105,
    16 /* DereferenceArray */, 1163,
    16 /* DereferenceArray */, 1167,
    16 /* DereferenceArray */, 1172,
    16 /* DereferenceArray */, 1173,
    16 /* DereferenceArray */, 1174,
    16 /* DereferenceArray */, 1175,
    16 /* DereferenceArray */, 1177,
    16 /* DereferenceArray */, 1182,
    16 /* DereferenceArray */, 1183,
    16 /* DereferenceArray */, 1193,
    16 /* DereferenceArray */, 1195,
    16 /* DereferenceArray */, 1201,
    16 /* DereferenceArray */, 1204,
    16 /* DereferenceArray */, 1207,
    16 /* DereferenceArray */, 1214,
    16 /* DereferenceArray */, 1218,
    16 /* DereferenceArray */, 1219,
    16 /* DereferenceArray */, 1222,
    16 /* DereferenceArray */, 1223,
    16 /* DereferenceArray */, 1227,
    16 /* DereferenceArray */, 1232,
    16 /* DereferenceArray */, 1233,
    16 /* DereferenceArray */, 1234,
    16 /* DereferenceArray */, 1242,
    16 /* DereferenceArray */, 1243,
    16 /* DereferenceArray */, 1244,
    16 /* DereferenceArray */, 1246,
    16 /* DereferenceArray */, 1248,
    16 /* DereferenceArray */, 1267,
    17 /* Dereference */, 1284,
    17 /* Dereference */, 1295,
    17 /* Dereference */, 1297,
    17 /* Dereference */, 1306,
    17 /* Dereference */, 1309,
    17 /* Dereference */, 1312,
    17 /* Dereference */, 1312,
    17 /* Dereference */, 1338,
    17 /* Dereference */, 1344,
    17 /* Dereference */, 1348,
    17 /* Dereference */, 1406,
    17 /* Dereference */, 1453,
    17 /* Dereference */, 1466,
    17 /* Dereference */, 1467,
    17 /* Dereference */, 1486,
    17 /* Dereference */, 1494,
    17 /* Dereference */, 1494,
    17 /* Dereference */, 1494,
    17 /* Dereference */, 1494,
    17 /* Dereference */, 1496,
    17 /* Dereference */, 1521,
    18 /* ParseFuncCall */, 1545,
    18 /* ParseFuncCall */, 1547,
    18 /* ParseFuncCall */, 1553,
    18 /* ParseFuncCall */, 1555,
    18 /* ParseFuncCall */, 1557,
    18 /* ParseFuncCall */, 1558,
    18 /* ParseFuncCall */, 1559,
    18 /* ParseFuncCall */, 1561,
    18 /* ParseFuncCall */, 1561,
    18 /* ParseFuncCall */, 1564,
    18 /* ParseFuncCall */, 1570,
    18 /* ParseFuncCall */, 1570,
    18 /* ParseFuncCall */, 1573,
    18 /* ParseFuncCall */, 1574,
    18 /* ParseFuncCall */, 1576,
    18 /* ParseFuncCall */, 1576,
    18 /* ParseFuncCall */, 1576,
    19 /* ParseArray */, 1600,
    19 /* ParseArray */, 1600,
    19 /* ParseArray */, 1601,
    19 /* ParseArray */, 1601,
    19 /* ParseArray */, 1603,
    19 /* ParseArray */, 1606,
    19 /* ParseArray */, 1617,
    19 /* ParseArray */, 1618,
    19 /* ParseArray */, 1618,
    19 /* ParseArray */, 1619,
    19 /* ParseArray */, 1620,
    19 /* ParseArray */, 1620,
    19 /* ParseArray */, 1622,
    19 /* ParseArray */, 1631,
    19 /* ParseArray */, 1631,
    19 /* ParseArray */, 1637,
    19 /* ParseArray */, 1637,
    19 /* ParseArray */, 1637,
    19 /* ParseArray */, 1659,
    19 /* ParseArray */, 1660,
    19 /* ParseArray */, 1660,
    19 /* ParseArray */, 1662,
    19 /* ParseArray */, 1662,
    19 /* ParseArray */, 1664,
    19 /* ParseArray */, 1665,
    19 /* ParseArray */, 1665,
    19 /* ParseArray */, 1667,
    19 /* ParseArray */, 1667,
    19 /* ParseArray */, 1670,
    19 /* ParseArray */, 1681,
    19 /* ParseArray */, 1681,
    19 /* ParseArray */, 1683,
    19 /* ParseArray */, 1683,
    19 /* ParseArray */, 1689,
    19 /* ParseArray */, 1689,
    19 /* ParseArray */, 1689,
    19 /* ParseArray */, 1691,
    19 /* ParseArray */, 1692,
    19 /* ParseArray */, 1692,
    19 /* ParseArray */, 1693,
    19 /* ParseArray */, 1693,
    20 /* ParseDoubleQuotedStringWithEmbeddedVars */, 1717,
    21 /* ParseList */, 1756,
    21 /* ParseList */, 1756,
    21 /* ParseList */, 1757,
    22 /* ParseClassStaticAccess */, 1802,
    22 /* ParseClassStaticAccess */, 1804,
    22 /* ParseClassStaticAccess */, 1840,
    22 /* ParseClassStaticAccess */, 1845,
    22 /* ParseClassStaticAccess */, 1848,
    22 /* ParseClassStaticAccess */, 1852,
    22 /* ParseClassStaticAccess */, 1860,
    23 /* ParseSelf */, 1875,
    24 /* ParseStatic */, 1890,
    25 /* ParseParent */, 1903,
    25 /* ParseParent */, 1905,
    26 /* ParseExit */, 1932,
    26 /* ParseExit */, 1932,
    27 /* CheckBoolean */, 1950,
    27 /* CheckBoolean */, 1950,
    27 /* CheckBoolean */, 1967,
    27 /* CheckBoolean */, 1981,
    27 /* CheckBoolean */, 1985,
    28 /* DereferenceGLOBALS */, 2009,
    28 /* DereferenceGLOBALS */, 2011,
    28 /* DereferenceGLOBALS */, 2014,
    29 /* ParseVarRHS */, 2075,
    29 /* ParseVarRHS */, 2075,
    29 /* ParseVarRHS */, 2080,
    29 /* ParseVarRHS */, 2088,
    29 /* ParseVarRHS */, 2100,
    29 /* ParseVarRHS */, 2106,
    29 /* ParseVarRHS */, 2111,
    29 /* ParseVarRHS */, 2111,
    29 /* ParseVarRHS */, 2124,
    29 /* ParseVarRHS */, 2131,
    29 /* ParseVarRHS */, 2136,
    29 /* ParseVarRHS */, 2147,
    29 /* ParseVarRHS */, 2151,
    29 /* ParseVarRHS */, 2157,
    29 /* ParseVarRHS */, 2161,
    30 /* ParseNew */, 2227,
    30 /* ParseNew */, 2244,
    30 /* ParseNew */, 2248,
    30 /* ParseNew */, 2252,
    30 /* ParseNew */, 2254,
    30 /* ParseNew */, 2254,
    30 /* ParseNew */, 2268,
    30 /* ParseNew */, 2269,
    30 /* ParseNew */, 2272,
    30 /* ParseNew */, 2286,
    30 /* ParseNew */, 2304,
    30 /* ParseNew */, 2305,
    30 /* ParseNew */, 2306,
    30 /* ParseNew */, 2309,
    30 /* ParseNew */, 2311,
    30 /* ParseNew */, 2316,
    30 /* ParseNew */, 2317,
    30 /* ParseNew */, 2317,
    30 /* ParseNew */, 2318,
    30 /* ParseNew */, 2318,
    30 /* ParseNew */, 2320,
    30 /* ParseNew */, 2321,
    30 /* ParseNew */, 2324,
    30 /* ParseNew */, 2329,
    30 /* ParseNew */, 2330,
    30 /* ParseNew */, 2333,
    31 /* ParseClone */, 2347,
    31 /* ParseClone */, 2347,
    31 /* ParseClone */, 2349,
    31 /* ParseClone */, 2349,
    31 /* ParseClone */, 2358,
    32 /* ParseTerm */, 2557,
    32 /* ParseTerm */, 2557,
    32 /* ParseTerm */, 2557,
    32 /* ParseTerm */, 2558,
    32 /* ParseTerm */, 2558,
    33 /* e16 */, 2631,
    34 /* e15 */, 2649,
    35 /* e12 */, 2706,
    35 /* e12 */, 2712,
    35 /* e12 */, 2721,
    36 /* e6 */, 2794,
    36 /* e6 */, 2821,
    36 /* e6 */, 2821,
    36 /* e6 */, 2823,
    36 /* e6 */, 2824,
    37 /* ParseExprList */, 2890,
    38 /* ParseStaticExpr */, 2933,
    38 /* ParseStaticExpr */, 2935,
    38 /* ParseStaticExpr */, 2937,
    38 /* ParseStaticExpr */, 2939,
    38 /* ParseStaticExpr */, 2999,
    38 /* ParseStaticExpr */, 3001,
    39 /* ParseExprOfType */, 3040,
    39 /* ParseExprOfType */, 3043,
    39 /* ParseExprOfType */, 3047
};

void Expressions_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Expressions";
    *f = Expressions_0func[ Expressions_0err_entry[2*i] ];
    *l = Expressions_0err_entry[2*i + 1];
}
