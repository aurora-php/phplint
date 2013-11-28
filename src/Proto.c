/* IMPLEMENTATION MODULE Proto */
#define M2_IMPORT_Proto

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

#ifndef M2_IMPORT_Accounting
#    include "Accounting.c"
#endif

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_Exceptions
#    include "Exceptions.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Expressions
#    include "Expressions.c"
#endif

#ifndef M2_IMPORT_Namespace
#    include "Namespace.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Search
#    include "Search.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif

void Proto_0err_entry_get(int i, char **m, char **f, int *l);

/* 16*/ void
/* 16*/ Proto_ParseArgsListDecl(RECORD *Proto_sign, STRING *Proto_function_or_method)
/* 16*/ {
/* 17*/ 	RECORD * Proto_a = NULL;
/* 19*/ 	int Proto_opt_arg = 0;
/* 19*/ 	Scanner_Expect(157, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"expected '(' in ", Proto_function_or_method, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" declaration", (STRING *) 1));
/* 20*/ 	Scanner_ReadSym();
/* 23*/ 	do{
/* 23*/ 		if( (Scanner_sym == 158) ){
/* 26*/ 			goto m2runtime_loop_1;
/* 27*/ 		}
/* 27*/ 		if( (Scanner_sym == 156) ){
/* 28*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 4 * sizeof(int), Proto_0err_entry_get, 0) = TRUE;
/* 29*/ 			Scanner_ReadSym();
/* 32*/ 			goto m2runtime_loop_1;
/* 33*/ 		}
/* 33*/ 		Proto_a = NULL;
/* 38*/ 		if( (Scanner_sym == 179) ){
/* 39*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Proto_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 1) = TRUE;
/* 40*/ 			Scanner_ReadSym();
/* 46*/ 		}
/* 46*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 2) = Expressions_ParseType(FALSE);
/* 47*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Proto_a, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 3) == NULL ){
/* 48*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"missing type of the argument");
/* 49*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 4) = Globals_mixed_type;
/* 50*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Proto_a, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 5) == Globals_void_type ){
/* 51*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"argument of type `void' not allowed");
/* 57*/ 		}
/* 57*/ 		if( (Scanner_sym == 155) ){
/* 58*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Proto_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 6) = TRUE;
/* 59*/ 			Scanner_ReadSym();
/* 61*/ 		} else {
/* 61*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Proto_a, 3 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 7) ){
/* 62*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\67,\0,\0,\0)"invalid `return' attribute for argument passed by value");
/* 63*/ 				*(int *)m2runtime_dereference_lhs_RECORD(&Proto_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 8) = FALSE;
/* 66*/ 			}
/* 71*/ 		}
/* 71*/ 		Scanner_Expect(154, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"expected name of the formal argument in ", Proto_function_or_method, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" declaration", (STRING *) 1));
/* 73*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 9) = Scanner_s;
/* 74*/ 		Scanner_ReadSym();
/* 79*/ 		if( (Scanner_sym == 135) ){
/* 80*/ 			if( (((Globals_php_ver == 4)) &&  *(int *)m2runtime_dereference_rhs_RECORD(Proto_a, 3 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 10)) ){
/* 81*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\111,\0,\0,\0)"can't assign default value to formal argument passed by reference (PHP 5)");
/* 83*/ 			}
/* 83*/ 			Proto_opt_arg = TRUE;
/* 84*/ 			Scanner_ReadSym();
/* 85*/ 		} else if( Proto_opt_arg ){
/* 86*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"missing default value for argument `$", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_a, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 11), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"'. Hint: mandatory arguments can't follow the default ones.", (STRING *) 1));
/* 89*/ 		}
/* 89*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 12), sizeof(void *), 1, Proto_0err_entry_get, 13) = Proto_a;
/* 90*/ 		if( !Proto_opt_arg ){
/* 91*/ 			m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 14), 1);
/* 94*/ 		}
/* 94*/ 		if( (Scanner_sym == 134) ){
/* 95*/ 			Scanner_ReadSym();
/* 96*/ 			if( (Scanner_sym == 156) ){
/* 97*/ 				*(int *)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 4 * sizeof(int), Proto_0err_entry_get, 15) = TRUE;
/* 98*/ 				Scanner_ReadSym();
/*101*/ 				goto m2runtime_loop_1;
/*103*/ 			}
/*104*/ 		} else {
/*106*/ 			goto m2runtime_loop_1;
/*107*/ 		}
/*107*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*107*/ 	Scanner_Expect(158, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected ')' or ',' in ", Proto_function_or_method, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" declaration", (STRING *) 1));
/*109*/ 	Scanner_ReadSym();
/*113*/ }


/*115*/ void
/*115*/ Proto_ForwFuncDecl(int Proto_private, RECORD *Proto_t)
/*115*/ {
/*116*/ 	RECORD * Proto_sign = NULL;
/*118*/ 	RECORD * Proto_parent_func = NULL;
/*118*/ 	RECORD * Proto_f = NULL;
/*119*/ 	if( Proto_t == NULL ){
/*120*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"missing or invalid return type in function prototype");
/*122*/ 	}
/*122*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 16) = Proto_t;
/*123*/ 	Scanner_ReadSym();
/*125*/ 	if( (Scanner_sym == 155) ){
/*126*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 17) = TRUE;
/*127*/ 		if( (Globals_php_ver == 5) ){
/*128*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"obsolete syntax `function &func()', don't use in PHP 5");
/*130*/ 		}
/*130*/ 		Scanner_ReadSym();
/*137*/ 	}
/*137*/ 	Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"expected function name after `function'");
/*138*/ 	Scanner_s = Namespace_CheckBareID(Scanner_s);
/*139*/ 	Scanner_s = Namespace_Absolute(Scanner_s);
/*140*/ 	Proto_f = Search_SearchFuncByAbsName(Scanner_s, FALSE);
/*141*/ 	if( Proto_f == NULL ){
/*142*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 18) = Scanner_s;
/*143*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 19) = str_tolower(Scanner_s);
/*144*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 20) = TRUE;
/*145*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 21) = Proto_private;
/*146*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 2 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 22) = Scanner_here();
/*147*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 4 * sizeof(int), Proto_0err_entry_get, 23) = 0;
/*148*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 4 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 24) = NULL;
/*149*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 5 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 25) = Proto_sign;
/*150*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_funcs, sizeof(void *), 1, Proto_0err_entry_get, 26) = Proto_f;
/*152*/ 	} else {
/*152*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Proto_f, 2 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 27)), (STRING *) 1));
/*154*/ 	}
/*154*/ 	Proto_parent_func = Globals_curr_func;
/*155*/ 	Globals_curr_func = Proto_f;
/*156*/ 	m2_inc(&Globals_scope, 1);
/*157*/ 	Scanner_ReadSym();
/*162*/ 	Proto_ParseArgsListDecl(Proto_sign, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"function");
/*168*/ 	if( (Scanner_sym == 178) ){
/*169*/ 		Exceptions_ParseThrows();
/*172*/ 	}
/*172*/ 	Scanner_Expect(132, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"expected `;' after function prototype");
/*173*/ 	Scanner_ReadSym();
/*175*/ 	Expressions_CleanCurrentScope();
/*176*/ 	m2_inc(&Globals_scope, -1);
/*177*/ 	Globals_curr_func = Proto_parent_func;
/*195*/ }


/*198*/ void
/*198*/ Proto_ParseMethodProto(int Proto_visibility, int Proto_abstract, int Proto_final, int Proto_static, RECORD *Proto_t)
/*198*/ {
/*199*/ 	RECORD * Proto_old_m = NULL;
/*199*/ 	RECORD * Proto_m = NULL;
/*200*/ 	int Proto_i = 0;
/*201*/ 	RECORD * Proto_sign = NULL;
/*202*/ 	RECORD * Proto_this = NULL;
/*203*/ 	int Proto_guess = 0;
/*239*/ 	int Proto_is_destructor = 0;
/*239*/ 	int Proto_is_constructor = 0;
/*242*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 15 * sizeof(void*) + 7 * sizeof(int), Proto_0err_entry_get, 28) ){
/*243*/ 		Proto_abstract = TRUE;
/*244*/ 		if( (Proto_visibility != 2) ){
/*245*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"interface methods must be `public'");
/*246*/ 			Proto_visibility = 2;
/*248*/ 		}
/*248*/ 		if( Proto_final ){
/*249*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"interface methods cannot be `final'");
/*250*/ 			Proto_final = FALSE;
/*253*/ 		}
/*253*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 15 * sizeof(void*) + 6 * sizeof(int), Proto_0err_entry_get, 29) ){
/*254*/ 		if( Proto_abstract ){
/*255*/ 			if( (Proto_visibility == 0) ){
/*256*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"abstract methods cannot be `private'");
/*257*/ 				Proto_visibility = 1;
/*259*/ 			}
/*259*/ 			if( Proto_static ){
/*260*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"abstract methods cannot be static");
/*261*/ 				Proto_static = FALSE;
/*263*/ 			}
/*263*/ 			if( Proto_final ){
/*264*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"abstract methods cannot be `final'");
/*265*/ 				Proto_final = FALSE;
/*268*/ 			}
/*268*/ 		} else {
/*268*/ 			if( (Proto_final && ((Proto_visibility == 0))) ){
/*269*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"a private method is implicitly `final'");
/*270*/ 				Proto_final = FALSE;
/*273*/ 			}
/*274*/ 		}
/*275*/ 	} else {
/*275*/ 		if( Proto_abstract ){
/*276*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"abstract method in non-abstract class");
/*277*/ 			Proto_abstract = FALSE;
/*279*/ 		}
/*279*/ 		if( (Proto_final && ((Proto_visibility == 0))) ){
/*280*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"a private method is implicitly `final'");
/*281*/ 			Proto_final = FALSE;
/*285*/ 		}
/*286*/ 	}
/*286*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 30) = TRUE;
/*287*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 31) = Proto_abstract;
/*288*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 4 * sizeof(int), Proto_0err_entry_get, 32) = Proto_visibility;
/*289*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 5 * sizeof(int), Proto_0err_entry_get, 33) = Proto_static;
/*290*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 6 * sizeof(int), Proto_0err_entry_get, 34) = Proto_final;
/*292*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 35) = Proto_t;
/*293*/ 	if( Proto_t == NULL ){
/*294*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\130,\0,\0,\0)"missing return type in method prototype -- assuming `void' and trying to continue anyway");
/*295*/ 		Proto_guess = TRUE;
/*296*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 36) = Globals_void_type;
/*299*/ 	}
/*299*/ 	Scanner_ReadSym();
/*304*/ 	if( (Scanner_sym == 155) ){
/*305*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 37) = TRUE;
/*306*/ 		if( (Globals_php_ver == 5) ){
/*307*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"obsolete syntax `function &func()', don't use in PHP 5");
/*309*/ 		}
/*309*/ 		Scanner_ReadSym();
/*315*/ 	}
/*315*/ 	Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"expected method name");
/*316*/ 	Proto_old_m = Search_SearchClassMethod(Globals_curr_class, Scanner_s, FALSE);
/*317*/ 	if( Proto_old_m != NULL ){
/*318*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Proto_old_m, 3 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 38) != NULL ){
/*319*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"method `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"()' already defined in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Proto_old_m, 3 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 39)), (STRING *) 1));
/*324*/ 		}
/*324*/ 		Proto_i = 0;
/*325*/ 		while( (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 8 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 40), Proto_i, Proto_0err_entry_get, 41) != Proto_old_m ){
/*326*/ 			m2_inc(&Proto_i, 1);
/*328*/ 		}
/*328*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 8 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 42), sizeof(void *), 1, Proto_i, Proto_0err_entry_get, 43) = Proto_m;
/*331*/ 	} else {
/*331*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 8 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 44), sizeof(void *), 1, Proto_0err_entry_get, 45) = Proto_m;
/*333*/ 	}
/*333*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 46) = Scanner_s;
/*334*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 47) = str_tolower(Scanner_s);
/*336*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 3 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 48) = Scanner_here();
/*337*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 2 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 49) = Proto_sign;
/*342*/ 	if( (Globals_php_ver == 4) ){
/*344*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 50), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"__construct") == 0 ){
/*345*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 51), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"': this name is reserved for PHP 5 constructors", (STRING *) 1));
/*348*/ 		}
/*348*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 52), (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 53)) == 0 ){
/*349*/ 			Proto_is_constructor = TRUE;
/*350*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 54) == NULL ){
/*351*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 9 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 55) = Proto_m;
/*353*/ 			} else {
/*353*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 56), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"': constructor already declared as `", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 57), 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 58), m2runtime_CHR(39), (STRING *) 1));
/*358*/ 			}
/*359*/ 		}
/*361*/ 	} else {
/*361*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 59), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"__construct") == 0 ){
/*362*/ 			Proto_is_constructor = TRUE;
/*364*/ 		} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 60), (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 61)) == 0 ){
/*365*/ 			Proto_is_constructor = TRUE;
/*366*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"the constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 62), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' has the same name of the class. PHP 5 states", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)" it should be called `__construct()'", (STRING *) 1));
/*369*/ 			Proto_is_constructor = TRUE;
/*371*/ 		} else if( (Namespace_inNamespace() && str_ends_with((STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 63), m2runtime_concat_STRING(0, m2runtime_CHR(92), (STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 64), (STRING *) 1))) ){
/*373*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"the method `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 65), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\212,\0,\0,\0)"' has the same name of the class inside a namespace: if it is intended to be a constructor, call it `__construct()' instead (PHP >= 5.3.3)", (STRING *) 1));
/*377*/ 		}
/*377*/ 		if( Proto_is_constructor ){
/*378*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 66) == NULL ){
/*379*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 9 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 67) = Proto_m;
/*381*/ 			} else {
/*381*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 68), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"': constructor already declared as `", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 69), 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 70), m2runtime_CHR(39), (STRING *) 1));
/*386*/ 			}
/*388*/ 		}
/*392*/ 	}
/*392*/ 	Proto_is_destructor = (((Globals_php_ver == 5)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 71), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__DESTRUCT") == 0));
/*393*/ 	if( Proto_is_destructor ){
/*394*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 11 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 72) = Proto_m;
/*397*/ 	}
/*397*/ 	if( (!Accounting_report_unused || Proto_is_constructor || Proto_is_destructor || Proto_abstract) ){
/*398*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 7 * sizeof(int), Proto_0err_entry_get, 73) = 100;
/*401*/ 	}
/*401*/ 	Globals_curr_method = Proto_m;
/*402*/ 	m2_inc(&Globals_scope, 1);
/*403*/ 	Scanner_ReadSym();
/*409*/ 	Accounting_AccountVarLHS(m2runtime_CHR(42), FALSE);
/*410*/ 	Proto_this = Search_SearchVar(m2runtime_CHR(42));
/*411*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_this, 7 * sizeof(void*) + 7 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 74) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"this";
/*412*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_this, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 75) = (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 5 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 76);
/*417*/ 	Proto_ParseArgsListDecl(Proto_sign, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"method");
/*419*/ 	if( !Proto_is_constructor ){
/*430*/ 	} else {
/*430*/ 		if(  *(int *)m2runtime_dereference_rhs_RECORD(Proto_m, 9 * sizeof(void*) + 5 * sizeof(int), Proto_0err_entry_get, 77) ){
/*431*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 78), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"': a constructor cannot be `static'", (STRING *) 1));
/*433*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Proto_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 5 * sizeof(int), Proto_0err_entry_get, 79) = FALSE;
/*435*/ 		}
/*435*/ 		if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Proto_sign, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 80) != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Proto_sign, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 81) != Globals_void_type)) ){
/*436*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_m, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 82), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"': a constructor cannot", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)" return a value. It must be declared `void'.", (STRING *) 1));
/*439*/ 		}
/*439*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 83) = Globals_void_type;
/*446*/ 	}
/*446*/ 	if( (Scanner_sym == 178) ){
/*447*/ 		Exceptions_ParseThrows();
/*450*/ 	}
/*450*/ 	Scanner_Expect(132, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"expected `;' at the end of the method prototype");
/*451*/ 	Scanner_ReadSym();
/*453*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Proto_this, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Proto_0err_entry_get, 84) = 100;
/*458*/ 	Expressions_CleanCurrentScope();
/*459*/ 	m2_inc(&Globals_scope, -1);
/*460*/ 	Globals_curr_method = NULL;
/*464*/ }


/*466*/ void
/*466*/ Proto_ParseClassConstProto(void)
/*466*/ {
/*467*/ 	RECORD * Proto_cl = NULL;
/*469*/ 	RECORD * Proto_c = NULL;
/*469*/ 	Scanner_ReadSym();
/*472*/ 	do{
/*472*/ 		Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"expected constant name");
/*477*/ 		Search_ResolveClassConst(Globals_curr_class, Scanner_s, &Proto_cl, &Proto_c);
/*478*/ 		if( Proto_c != NULL ){
/*479*/ 			if( Proto_cl == Globals_curr_class ){
/*480*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"class constant `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' already defined in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Proto_c, 2 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 85)), (STRING *) 1));
/*482*/ 			} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Proto_cl, 15 * sizeof(void*) + 6 * sizeof(int), Proto_0err_entry_get, 86) ||  *(int *)m2runtime_dereference_rhs_RECORD(Proto_cl, 15 * sizeof(void*) + 7 * sizeof(int), Proto_0err_entry_get, 87)) ){
/*483*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"cannot re-define the constant `", Classes_pc(Globals_curr_class, Proto_cl), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"' inherited from interface or abstract class", (STRING *) 1));
/*488*/ 			}
/*489*/ 		}
/*489*/ 		Proto_c = NULL;
/*490*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 88) = Scanner_s;
/*491*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 5 * sizeof(int), Proto_0err_entry_get, 89) = TRUE;
/*492*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 90) = 2;
/*493*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 2 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 91) = Scanner_here();
/*494*/ 		if( !Accounting_report_unused ){
/*495*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 92) = 100;
/*497*/ 		}
/*497*/ 		Scanner_ReadSym();
/*498*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 93) = NULL;
/*499*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 6 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 94), sizeof(void *), 1, Proto_0err_entry_get, 95) = Proto_c;
/*501*/ 		if( (Scanner_sym == 134) ){
/*502*/ 			Scanner_ReadSym();
/*505*/ 		} else {
/*506*/ 			goto m2runtime_loop_1;
/*507*/ 		}
/*508*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*508*/ 	Scanner_Expect(132, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"missing `;'");
/*509*/ 	Scanner_ReadSym();
/*514*/ }


/*521*/ void
/*521*/ Proto_ParseAttributes(int *Proto_visibility, int *Proto_abstract, int *Proto_final, int *Proto_static, int *Proto_unchecked)
/*521*/ {
/*521*/ 	*Proto_visibility = 2;
/*522*/ 	*Proto_abstract = FALSE;
/*523*/ 	*Proto_final = FALSE;
/*524*/ 	*Proto_static = FALSE;
/*525*/ 	*Proto_unchecked = FALSE;
/*528*/ 	do{
/*528*/ 		if( (Scanner_sym == 172) ){
/*529*/ 			*Proto_visibility = 0;
/*530*/ 			Scanner_ReadSym();
/*532*/ 		} else if( (Scanner_sym == 171) ){
/*533*/ 			*Proto_visibility = 1;
/*534*/ 			Scanner_ReadSym();
/*536*/ 		} else if( (Scanner_sym == 170) ){
/*537*/ 			*Proto_visibility = 2;
/*538*/ 			Scanner_ReadSym();
/*540*/ 		} else if( (Scanner_sym == 173) ){
/*541*/ 			*Proto_abstract = TRUE;
/*542*/ 			Scanner_ReadSym();
/*544*/ 		} else if( (Scanner_sym == 175) ){
/*545*/ 			*Proto_final = TRUE;
/*546*/ 			Scanner_ReadSym();
/*548*/ 		} else if( (Scanner_sym == 174) ){
/*549*/ 			*Proto_static = TRUE;
/*550*/ 			Scanner_ReadSym();
/*552*/ 		} else if( (Scanner_sym == 143) ){
/*553*/ 			*Proto_unchecked = TRUE;
/*554*/ 			Scanner_ReadSym();
/*558*/ 		} else {
/*559*/ 			goto m2runtime_loop_1;
/*560*/ 		}
/*561*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*563*/ }


/*565*/ void
/*565*/ Proto_ForwInterfaceDecl(int Proto_private)
/*565*/ {
/*566*/ 	RECORD * Proto_c = NULL;
/*567*/ 	int Proto_visibility = 0;
/*568*/ 	int Proto_unchecked = 0;
/*568*/ 	int Proto_static = 0;
/*568*/ 	int Proto_final = 0;
/*568*/ 	int Proto_abstract = 0;
/*570*/ 	RECORD * Proto_t = NULL;
/*570*/ 	Scanner_ReadSym();
/*571*/ 	Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected interface name");
/*572*/ 	Scanner_s = Namespace_CheckBareID(Scanner_s);
/*573*/ 	Scanner_s = Namespace_Absolute(Scanner_s);
/*574*/ 	Proto_c = Search_SearchClassByAbsName(Scanner_s, FALSE);
/*575*/ 	if( Proto_c != NULL ){
/*577*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Proto_c, 12 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 96)), (STRING *) 1));
/*582*/ 	} else {
/*582*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 97) = Scanner_s;
/*583*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 98) = str_tolower(Scanner_s);
/*584*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 99) = TRUE;
/*585*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 7 * sizeof(int), Proto_0err_entry_get, 100) = TRUE;
/*586*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 5 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 101) = (
/*586*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*586*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 9,
/*586*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*586*/ 			push((char*) NULL),
/*586*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*586*/ 			push((char*) Proto_c),
/*587*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*587*/ 			(RECORD*) pop()
/*587*/ 		);
/*587*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 4 * sizeof(int), Proto_0err_entry_get, 102) = Proto_private;
/*588*/ 		if( !Accounting_report_unused ){
/*589*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 10 * sizeof(int), Proto_0err_entry_get, 103) = 100;
/*591*/ 		}
/*591*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_classes, sizeof(void *), 1, Proto_0err_entry_get, 104) = Proto_c;
/*593*/ 	}
/*593*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 12 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 105) = Scanner_here();
/*594*/ 	Scanner_ReadSym();
/*596*/ 	if( (Scanner_sym == 139) ){
/*598*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\103,\0,\0,\0)"`extends' keyword still unimplemented in interface prototype, sorry");
/*601*/ 	}
/*601*/ 	Scanner_Expect(161, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"expected '{' in interface prototype");
/*602*/ 	Scanner_ReadSym();
/*604*/ 	Globals_curr_class = Proto_c;
/*605*/ 	while( (Scanner_sym != 162) ){
/*606*/ 		if( (Scanner_sym == 141) ){
/*607*/ 			Proto_ParseClassConstProto();
/*609*/ 		} else {
/*609*/ 			Proto_ParseAttributes(&Proto_visibility, &Proto_abstract, &Proto_final, &Proto_static, &Proto_unchecked);
/*610*/ 			if( Proto_unchecked ){
/*611*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"invalid `unchecked' attribute for method");
/*613*/ 			}
/*613*/ 			Proto_t = Expressions_ParseType(FALSE);
/*614*/ 			Proto_ParseMethodProto(Proto_visibility, Proto_abstract, Proto_final, Proto_static, Proto_t);
/*617*/ 		}
/*617*/ 	}
/*617*/ 	Globals_curr_class = NULL;
/*619*/ 	Scanner_Expect(162, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"expected `}' in interface prototype");
/*620*/ 	Scanner_ReadSym();
/*624*/ }


/*627*/ void
/*627*/ Proto_ForwClassDecl(int Proto_private, int Proto_abstract, int Proto_final, int Proto_unchecked)
/*627*/ {
/*628*/ 	RECORD * Proto_if = NULL;
/*628*/ 	RECORD * Proto_parent = NULL;
/*628*/ 	RECORD * Proto_c = NULL;
/*629*/ 	int Proto_visibility = 0;
/*630*/ 	int Proto_static = 0;
/*632*/ 	RECORD * Proto_t = NULL;
/*632*/ 	Scanner_ReadSym();
/*633*/ 	Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"expected class name");
/*634*/ 	Scanner_s = Namespace_CheckBareID(Scanner_s);
/*635*/ 	Scanner_s = Namespace_Absolute(Scanner_s);
/*636*/ 	Proto_c = Search_SearchClassByAbsName(Scanner_s, FALSE);
/*637*/ 	if( Proto_c != NULL ){
/*639*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Proto_c, 12 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 106)), (STRING *) 1));
/*644*/ 	} else {
/*644*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 107) = Scanner_s;
/*645*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 1 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 108) = str_tolower(Scanner_s);
/*646*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 3 * sizeof(int), Proto_0err_entry_get, 109) = TRUE;
/*647*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 6 * sizeof(int), Proto_0err_entry_get, 110) = Proto_abstract;
/*648*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 5 * sizeof(int), Proto_0err_entry_get, 111) = Proto_final;
/*649*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 5 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 112) = (
/*649*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*649*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 9,
/*649*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*649*/ 			push((char*) NULL),
/*649*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*649*/ 			push((char*) Proto_c),
/*650*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*650*/ 			(RECORD*) pop()
/*650*/ 		);
/*650*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 4 * sizeof(int), Proto_0err_entry_get, 113) = Proto_private;
/*651*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 114) = Proto_unchecked;
/*652*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_classes, sizeof(void *), 1, Proto_0err_entry_get, 115) = Proto_c;
/*654*/ 	}
/*654*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 12 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 116) = Scanner_here();
/*655*/ 	Scanner_ReadSym();
/*657*/ 	if( (Scanner_sym == 139) ){
/*658*/ 		Scanner_ReadSym();
/*659*/ 		Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"expected parent class name after `extend'");
/*660*/ 		Proto_parent = Search_SearchClass(Scanner_s);
/*661*/ 		if( Proto_parent == NULL ){
/*662*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"undeclared parent class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*663*/ 		} else if( Classes_IsSubclassOf(Proto_parent, Proto_c) ){
/*664*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_c, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 117), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" cannot extend child class ", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_parent, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 118), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)": forbidden circular reference", (STRING *) 1));
/*666*/ 		} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Proto_parent, 15 * sizeof(void*) + 5 * sizeof(int), Proto_0err_entry_get, 119) ){
/*667*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"can't extend final class `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_parent, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 120), m2runtime_CHR(39), (STRING *) 1));
/*668*/ 		} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Proto_parent, 15 * sizeof(void*) + 7 * sizeof(int), Proto_0err_entry_get, 121) ){
/*669*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"can't extend interface class `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_parent, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 122), m2runtime_CHR(39), (STRING *) 1));
/*671*/ 		} else {
/*671*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 3 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 123) = Proto_parent;
/*674*/ 			if( Proto_unchecked ){
/*675*/ 				if( !Classes_IsExceptionClass(Proto_parent) ){
/*676*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"invalid `unchecked' attribute for non-exception class ", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_parent, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 124), (STRING *) 1));
/*680*/ 				}
/*680*/ 			} else if( (Classes_IsSubclassOf(Proto_parent, Classes_ExceptionClass) &&  *(int *)m2runtime_dereference_rhs_RECORD(Proto_parent, 15 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 125)) ){
/*682*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"missing `unchecked' attribute extending unchecked exception ", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_parent, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 126), (STRING *) 1));
/*686*/ 			}
/*686*/ 		}
/*686*/ 		Scanner_ReadSym();
/*689*/ 	}
/*689*/ 	if( (Scanner_sym == 140) ){
/*690*/ 		Scanner_ReadSym();
/*692*/ 		do{
/*692*/ 			Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected interface name");
/*693*/ 			Proto_if = Search_SearchClass(Scanner_s);
/*694*/ 			if( Proto_if == NULL ){
/*695*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"undeclared interface class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*696*/ 			} else if( ! *(int *)m2runtime_dereference_rhs_RECORD(Proto_if, 15 * sizeof(void*) + 7 * sizeof(int), Proto_0err_entry_get, 127) ){
/*697*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"' isn't an interface", (STRING *) 1));
/*698*/ 			} else if( (((Globals_php_ver == 5)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Proto_if, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 128), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"Traversable") == 0)) ){
/*699*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\137,\0,\0,\0)"can't implement abstract interface `Traversable', use `Iterator' or `IteratorAggregate' instead");
/*700*/ 			} else if( Classes_IsSubclassOf(Proto_c, Proto_if) ){
/*701*/ 				Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_c, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 129), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)" redundantly extends interface ", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_if, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 130), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" -- ignoring", (STRING *) 1));
/*705*/ 			} else {
/*705*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Proto_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 4 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 131), sizeof(void *), 1, Proto_0err_entry_get, 132) = Proto_if;
/*708*/ 				Accounting_AccountClass(Proto_if);
/*709*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Proto_if, 14 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 133), EMPTY_STRING) > 0 ){
/*710*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"implementing deprecated interface `", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_if, 0 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 134), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Proto_if, 14 * sizeof(void*) + 2 * sizeof(int), Proto_0err_entry_get, 135), (STRING *) 1));
/*714*/ 				}
/*714*/ 			}
/*714*/ 			Scanner_ReadSym();
/*715*/ 			if( (Scanner_sym == 134) ){
/*716*/ 				Scanner_ReadSym();
/*719*/ 			} else {
/*720*/ 				goto m2runtime_loop_1;
/*721*/ 			}
/*722*/ 		}while(TRUE);
m2runtime_loop_1: ;
/*723*/ 	}
/*723*/ 	Scanner_Expect(161, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"expected `{' in class prototype");
/*724*/ 	Scanner_ReadSym();
/*726*/ 	Globals_curr_class = Proto_c;
/*727*/ 	while( (Scanner_sym != 162) ){
/*728*/ 		if( (Scanner_sym == 141) ){
/*729*/ 			Proto_ParseClassConstProto();
/*731*/ 		} else {
/*731*/ 			Proto_ParseAttributes(&Proto_visibility, &Proto_abstract, &Proto_final, &Proto_static, &Proto_unchecked);
/*732*/ 			if( Proto_unchecked ){
/*733*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"invalid `unchecked' attribute for method");
/*735*/ 			}
/*735*/ 			Proto_t = Expressions_ParseType(FALSE);
/*736*/ 			Proto_ParseMethodProto(Proto_visibility, Proto_abstract, Proto_final, Proto_static, Proto_t);
/*739*/ 		}
/*739*/ 	}
/*739*/ 	Globals_curr_class = NULL;
/*741*/ 	Scanner_Expect(162, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"expected `}' in class prototype");
/*742*/ 	Scanner_ReadSym();
/*746*/ }


/*748*/ void
/*748*/ Proto_ParseForwardDecl(void)
/*748*/ {
/*749*/ 	int Proto_visibility = 0;
/*750*/ 	int Proto_unchecked = 0;
/*750*/ 	int Proto_static = 0;
/*750*/ 	int Proto_final = 0;
/*750*/ 	int Proto_abstract = 0;
/*752*/ 	RECORD * Proto_t = NULL;
/*752*/ 	if( (Globals_scope > 0) ){
/*753*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\61,\0,\0,\0)"forward declarations allowed only in global scope");
/*756*/ 	}
/*756*/ 	Scanner_ReadSym();
/*758*/ 	Proto_ParseAttributes(&Proto_visibility, &Proto_abstract, &Proto_final, &Proto_static, &Proto_unchecked);
/*759*/ 	Proto_t = Expressions_ParseType(FALSE);
/*761*/ 	if( ((Globals_curr_class == NULL) && ((Globals_scope == 0))) ){
/*764*/ 		if( (Scanner_sym == 137) ){
/*766*/ 			if( (((Proto_visibility == 1)) || Proto_static || Proto_final || Proto_abstract || Proto_unchecked) ){
/*768*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"invalid attributes for function prototype");
/*770*/ 			}
/*770*/ 			Proto_ForwFuncDecl((Proto_visibility == 0), Proto_t);
/*772*/ 		} else if( (Scanner_sym == 142) ){
/*773*/ 			if( (((Proto_visibility == 1)) || Proto_static || Proto_final || Proto_abstract || Proto_unchecked) ){
/*775*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"invalid attributes for interface prototype");
/*777*/ 			}
/*777*/ 			if( Proto_t != NULL ){
/*778*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"invalid return type in interface prototype");
/*780*/ 			}
/*780*/ 			Proto_ForwInterfaceDecl((Proto_visibility == 0));
/*782*/ 		} else if( (Scanner_sym == 138) ){
/*783*/ 			if( (((Proto_visibility == 1)) || Proto_static) ){
/*784*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"invalid attributes for class prototype");
/*786*/ 			}
/*786*/ 			if( Proto_t != NULL ){
/*787*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"invalid return type in class prototype");
/*789*/ 			}
/*789*/ 			Proto_ForwClassDecl((Proto_visibility == 0), Proto_abstract, Proto_final, Proto_unchecked);
/*792*/ 		} else {
/*792*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"expected function, interface or class prototype");
/*795*/ 		}
/*795*/ 	} else if( ((Globals_curr_class != NULL) && ((Globals_scope == 0))) ){
/*798*/ 		if( (Scanner_sym != 137) ){
/*799*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"expected method prototype");
/*802*/ 		}
/*802*/ 		Proto_ParseMethodProto(Proto_visibility, Proto_abstract, Proto_final, Proto_static, Proto_t);
/*805*/ 	} else {
/*805*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"forward declaration not allowed here");
/*810*/ 	}
/*812*/ }


char * Proto_0func[] = {
    "ParseArgsListDecl",
    "ForwFuncDecl",
    "ParseMethodProto",
    "ParseClassConstProto",
    "ForwInterfaceDecl",
    "ForwClassDecl"
};

int Proto_0err_entry[] = {
    0 /* ParseArgsListDecl */, 28,
    0 /* ParseArgsListDecl */, 39,
    0 /* ParseArgsListDecl */, 46,
    0 /* ParseArgsListDecl */, 47,
    0 /* ParseArgsListDecl */, 49,
    0 /* ParseArgsListDecl */, 50,
    0 /* ParseArgsListDecl */, 58,
    0 /* ParseArgsListDecl */, 61,
    0 /* ParseArgsListDecl */, 63,
    0 /* ParseArgsListDecl */, 73,
    0 /* ParseArgsListDecl */, 80,
    0 /* ParseArgsListDecl */, 86,
    0 /* ParseArgsListDecl */, 89,
    0 /* ParseArgsListDecl */, 89,
    0 /* ParseArgsListDecl */, 91,
    0 /* ParseArgsListDecl */, 97,
    1 /* ForwFuncDecl */, 122,
    1 /* ForwFuncDecl */, 126,
    1 /* ForwFuncDecl */, 142,
    1 /* ForwFuncDecl */, 143,
    1 /* ForwFuncDecl */, 144,
    1 /* ForwFuncDecl */, 145,
    1 /* ForwFuncDecl */, 146,
    1 /* ForwFuncDecl */, 147,
    1 /* ForwFuncDecl */, 148,
    1 /* ForwFuncDecl */, 149,
    1 /* ForwFuncDecl */, 150,
    1 /* ForwFuncDecl */, 152,
    2 /* ParseMethodProto */, 242,
    2 /* ParseMethodProto */, 253,
    2 /* ParseMethodProto */, 286,
    2 /* ParseMethodProto */, 287,
    2 /* ParseMethodProto */, 288,
    2 /* ParseMethodProto */, 289,
    2 /* ParseMethodProto */, 290,
    2 /* ParseMethodProto */, 292,
    2 /* ParseMethodProto */, 296,
    2 /* ParseMethodProto */, 305,
    2 /* ParseMethodProto */, 318,
    2 /* ParseMethodProto */, 320,
    2 /* ParseMethodProto */, 325,
    2 /* ParseMethodProto */, 325,
    2 /* ParseMethodProto */, 328,
    2 /* ParseMethodProto */, 328,
    2 /* ParseMethodProto */, 331,
    2 /* ParseMethodProto */, 331,
    2 /* ParseMethodProto */, 333,
    2 /* ParseMethodProto */, 334,
    2 /* ParseMethodProto */, 336,
    2 /* ParseMethodProto */, 337,
    2 /* ParseMethodProto */, 344,
    2 /* ParseMethodProto */, 345,
    2 /* ParseMethodProto */, 348,
    2 /* ParseMethodProto */, 348,
    2 /* ParseMethodProto */, 350,
    2 /* ParseMethodProto */, 351,
    2 /* ParseMethodProto */, 353,
    2 /* ParseMethodProto */, 355,
    2 /* ParseMethodProto */, 355,
    2 /* ParseMethodProto */, 361,
    2 /* ParseMethodProto */, 364,
    2 /* ParseMethodProto */, 364,
    2 /* ParseMethodProto */, 366,
    2 /* ParseMethodProto */, 372,
    2 /* ParseMethodProto */, 372,
    2 /* ParseMethodProto */, 373,
    2 /* ParseMethodProto */, 378,
    2 /* ParseMethodProto */, 379,
    2 /* ParseMethodProto */, 381,
    2 /* ParseMethodProto */, 383,
    2 /* ParseMethodProto */, 383,
    2 /* ParseMethodProto */, 392,
    2 /* ParseMethodProto */, 394,
    2 /* ParseMethodProto */, 398,
    2 /* ParseMethodProto */, 411,
    2 /* ParseMethodProto */, 412,
    2 /* ParseMethodProto */, 412,
    2 /* ParseMethodProto */, 430,
    2 /* ParseMethodProto */, 431,
    2 /* ParseMethodProto */, 433,
    2 /* ParseMethodProto */, 435,
    2 /* ParseMethodProto */, 435,
    2 /* ParseMethodProto */, 436,
    2 /* ParseMethodProto */, 439,
    2 /* ParseMethodProto */, 453,
    3 /* ParseClassConstProto */, 481,
    3 /* ParseClassConstProto */, 482,
    3 /* ParseClassConstProto */, 482,
    3 /* ParseClassConstProto */, 490,
    3 /* ParseClassConstProto */, 491,
    3 /* ParseClassConstProto */, 492,
    3 /* ParseClassConstProto */, 493,
    3 /* ParseClassConstProto */, 495,
    3 /* ParseClassConstProto */, 498,
    3 /* ParseClassConstProto */, 499,
    3 /* ParseClassConstProto */, 499,
    4 /* ForwInterfaceDecl */, 578,
    4 /* ForwInterfaceDecl */, 582,
    4 /* ForwInterfaceDecl */, 583,
    4 /* ForwInterfaceDecl */, 584,
    4 /* ForwInterfaceDecl */, 585,
    4 /* ForwInterfaceDecl */, 586,
    4 /* ForwInterfaceDecl */, 587,
    4 /* ForwInterfaceDecl */, 589,
    4 /* ForwInterfaceDecl */, 591,
    4 /* ForwInterfaceDecl */, 593,
    5 /* ForwClassDecl */, 640,
    5 /* ForwClassDecl */, 644,
    5 /* ForwClassDecl */, 645,
    5 /* ForwClassDecl */, 646,
    5 /* ForwClassDecl */, 647,
    5 /* ForwClassDecl */, 648,
    5 /* ForwClassDecl */, 649,
    5 /* ForwClassDecl */, 650,
    5 /* ForwClassDecl */, 651,
    5 /* ForwClassDecl */, 652,
    5 /* ForwClassDecl */, 654,
    5 /* ForwClassDecl */, 664,
    5 /* ForwClassDecl */, 665,
    5 /* ForwClassDecl */, 666,
    5 /* ForwClassDecl */, 667,
    5 /* ForwClassDecl */, 668,
    5 /* ForwClassDecl */, 669,
    5 /* ForwClassDecl */, 671,
    5 /* ForwClassDecl */, 677,
    5 /* ForwClassDecl */, 680,
    5 /* ForwClassDecl */, 682,
    5 /* ForwClassDecl */, 696,
    5 /* ForwClassDecl */, 698,
    5 /* ForwClassDecl */, 701,
    5 /* ForwClassDecl */, 703,
    5 /* ForwClassDecl */, 705,
    5 /* ForwClassDecl */, 705,
    5 /* ForwClassDecl */, 709,
    5 /* ForwClassDecl */, 711,
    5 /* ForwClassDecl */, 711
};

void Proto_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Proto";
    *f = Proto_0func[ Proto_0err_entry[2*i] ];
    *l = Proto_0err_entry[2*i + 1];
}
