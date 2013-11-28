/* IMPLEMENTATION MODULE Statements */
#define M2_IMPORT_Statements

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_ParseDocBlock
#    include "ParseDocBlock.c"
#endif
/* 13*/ ARRAY * Statements_include_path = NULL;
/* 16*/ ARRAY * Statements_modules_abs_path = NULL;
/* 20*/ ARRAY * Statements_packages_abs_path = NULL;

#ifndef M2_IMPORT_Accounting
#    include "Accounting.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif

#ifndef M2_IMPORT_Documentator
#    include "Documentator.c"
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

#ifndef M2_IMPORT_Expressions
#    include "Expressions.c"
#endif

#ifndef M2_IMPORT_FileName
#    include "FileName.c"
#endif

#ifndef M2_IMPORT_Namespace
#    include "Namespace.c"
#endif

#ifndef M2_IMPORT_Proto
#    include "Proto.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Search
#    include "Search.c"
#endif

#ifndef M2_IMPORT_Template
#    include "Template.c"
#endif

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_io
#    include "io.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

void Statements_0err_entry_get(int i, char **m, char **f, int *l);
/* 99*/ RECORD * Statements_pdb = NULL;
/*106*/ int Statements_recursion_level = 0;

/*108*/ void
/*108*/ Statements_ParseEcho(void)
/*108*/ {
/*109*/ 	RECORD * Statements_r = NULL;
/*111*/ 	RECORD * Statements_t = NULL;
/*111*/ 	Scanner_ReadSym();
/*113*/ 	do{
/*113*/ 		Statements_r = Expressions_ParseExpr();
/*114*/ 		if( Statements_r == NULL ){
/*117*/ 		} else {
/*117*/ 			Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 0);
/*118*/ 			if( ((Statements_t == Globals_int_type) || (Statements_t == Globals_float_type) || (Statements_t == Globals_string_type)) ){
/*121*/ 			} else if( Statements_t == Globals_boolean_type ){
/*122*/ 				Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\151,\0,\0,\0)"found boolean value: remember that FALSE gets rendered as empty string \042\042 while TRUE gets rendered as \0421\042");
/*123*/ 			} else if( Classes_IsObjectConvertibleToString(Statements_t) ){
/*126*/ 			} else {
/*126*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"found argument of the type ", Types_TypeToString(Statements_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)". The arguments of the `echo' statement must be of", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)" type int, float, string.", (STRING *) 1));
/*131*/ 			}
/*131*/ 		}
/*131*/ 		if( (Scanner_sym != 16) ){
/*134*/ 			goto m2runtime_loop_1;
/*134*/ 		}
/*134*/ 		Scanner_ReadSym();
/*137*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*139*/ }


/*150*/ void
/*150*/ Statements_CheckFormalArgsByReference(int Statements_on_return)
/*150*/ {
/*151*/ 	ARRAY * Statements_args = NULL;
/*152*/ 	int Statements_i = 0;
/*153*/ 	RECORD * Statements_v = NULL;
/*154*/ 	STRING * Statements_where = NULL;
/*156*/ 	STRING * Statements_msg = NULL;
/*156*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 1) ){
/*158*/ 		return ;
/*159*/ 	}
/*159*/ 	if( Globals_curr_func != NULL ){
/*160*/ 		Statements_args = (ARRAY *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 2), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 3);
/*161*/ 		Statements_where = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"function ", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 4), (STRING *) 1);
/*162*/ 	} else if( Globals_curr_method != NULL ){
/*163*/ 		Statements_args = (ARRAY *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 5), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 6);
/*164*/ 		Statements_where = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"method ", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 7), (STRING *) 1);
/*168*/ 	} else {
/*168*/ 		if( (Globals_scope == 0) ){
/*169*/ 			m2runtime_HALT(Statements_0err_entry_get, 8, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"invalid scope");
/*172*/ 		}
/*172*/ 		return ;
/*173*/ 	}
/*173*/ 	{
/*173*/ 		int m2runtime_for_limit_1;
/*173*/ 		Statements_i = 0;
/*173*/ 		m2runtime_for_limit_1 = (m2runtime_count(Statements_args) - 1);
/*174*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*174*/ 			Statements_v = Search_SearchVarInScope((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_args, Statements_i, Statements_0err_entry_get, 9), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 10), Globals_scope);
/*175*/ 			if( ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_v, 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 11) ){
/*176*/ 				Statements_msg = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"returning from ", Statements_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"(): the formal argument that returns by reference $", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_v, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 12), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)" might not have been assigned", (STRING *) 1);
/*179*/ 				if( Statements_on_return ){
/*180*/ 					Scanner_Error(Statements_msg);
/*182*/ 				} else {
/*182*/ 					Scanner_Error2(Scanner_here(), Statements_msg);
/*185*/ 				}
/*186*/ 			}
/*187*/ 		}
/*187*/ 	}
/*189*/ }


/*191*/ void
/*191*/ Statements_ParseReturn(void)
/*191*/ {
/*192*/ 	RECORD * Statements_r = NULL;
/*193*/ 	RECORD * Statements_found = NULL;
/*193*/ 	RECORD * Statements_expected = NULL;
/*194*/ 	STRING * Statements_n = NULL;
/*195*/ 	RECORD * Statements_sign = NULL;
/*197*/ 	int Statements_no_expr = 0;
/*197*/ 	Scanner_ReadSym();
/*198*/ 	if( Globals_curr_func != NULL ){
/*199*/ 		Statements_sign = (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 13);
/*200*/ 		Statements_expected = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 14);
/*201*/ 		Statements_n = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 15), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"()'", (STRING *) 1);
/*202*/ 	} else if( Globals_curr_method != NULL ){
/*203*/ 		Statements_sign = (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 16);
/*204*/ 		Statements_expected = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 17);
/*205*/ 		Statements_n = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"method ", Scanner_mn(Globals_curr_class, Globals_curr_method), (STRING *) 1);
/*207*/ 	} else {
/*207*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"`return' in global scope");
/*208*/ 		Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"Contains `return' statement in global scope in ", Scanner_reference(Scanner_here()), m2runtime_CHR(46), (STRING *) 1));
/*210*/ 		if( (Scanner_sym != 17) ){
/*211*/ 			Statements_r = Expressions_ParseExpr();
/*214*/ 		}
/*214*/ 		return ;
/*216*/ 	}
/*216*/ 	if( (Scanner_sym == 17) ){
/*217*/ 		Statements_found = NULL;
/*218*/ 		Statements_no_expr = TRUE;
/*220*/ 	} else {
/*220*/ 		Statements_r = Expressions_ParseExpr();
/*221*/ 		if( Statements_r == NULL ){
/*222*/ 			Statements_found = NULL;
/*223*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 18) == Globals_void_type ){
/*224*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"the expression does not return a value");
/*225*/ 			Statements_found = NULL;
/*227*/ 		} else {
/*227*/ 			Statements_found = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 19);
/*229*/ 		}
/*229*/ 		Statements_no_expr = FALSE;
/*232*/ 	}
/*232*/ 	if( Statements_expected == NULL ){
/*233*/ 		if( Statements_no_expr ){
/*234*/ 			Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"from this `return;' we guess the ", Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)" is of type void", (STRING *) 1));
/*236*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 20) = Globals_void_type;
/*237*/ 		} else if( Statements_found == NULL ){
/*238*/ 			Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"cannot determine the type of the returned ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"expression. Assuming `mixed' and trying to continue anyway.", (STRING *) 1));
/*240*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 21) = Globals_mixed_type;
/*242*/ 		} else {
/*242*/ 			Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"from this `return' we guess the ", Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)" returns a value of type ", Types_TypeToString(Statements_found), (STRING *) 1));
/*244*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 22) = Statements_found;
/*247*/ 		}
/*247*/ 	} else {
/*247*/ 		if( Statements_no_expr ){
/*248*/ 			if( Statements_expected != Globals_void_type ){
/*249*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"missing returned value for ", Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)" declared of type ", Types_TypeToString(Statements_expected), (STRING *) 1));
/*252*/ 			}
/*252*/ 		} else if( Statements_found == NULL ){
/*253*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"cannot determine the type of the returned ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)"expression. The type of the value returned by the ", Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)" should be ", Types_TypeToString(Statements_expected), (STRING *) 1));
/*257*/ 		} else {
/*257*/ 			switch(Expressions_LhsMatchRhs(Statements_expected, Statements_found)){

/*258*/ 			case 0:
/*259*/ 			break;

/*259*/ 			case 1:
/*260*/ 			Scanner_Warning(m2runtime_concat_STRING(0, Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)": expected return type ", Types_TypeToString(Statements_expected), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)", found expression of type ", Types_TypeToString(Statements_found), (STRING *) 1));
/*264*/ 			break;

/*264*/ 			case 2:
/*265*/ 			Scanner_Error(m2runtime_concat_STRING(0, Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)": expected return type ", Types_TypeToString(Statements_expected), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)", found expression of type ", Types_TypeToString(Statements_found), (STRING *) 1));
/*270*/ 			break;

/*270*/ 			default: m2runtime_missing_case_in_switch(Statements_0err_entry_get, 23);
/*271*/ 			}
/*272*/ 		}
/*273*/ 	}
/*273*/ 	Statements_CheckFormalArgsByReference(TRUE);
/*277*/ }


/*279*/ void
/*279*/ Statements_ParseTriggerError(void)
/*279*/ {
/*282*/ 	RECORD * Statements_r = NULL;
/*283*/ 	int Statements_err = 0;
/*285*/ 	STRING * Statements_err_name = NULL;
/*285*/ 	Scanner_ReadSym();
/*286*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `('");
/*287*/ 	Scanner_ReadSym();
/*293*/ 	Statements_r = Expressions_ParseExprOfType(Globals_string_type);
/*296*/ 	if( (Scanner_sym == 16) ){
/*297*/ 		Scanner_ReadSym();
/*298*/ 		Statements_r = Expressions_ParseExprOfType(Globals_int_type);
/*299*/ 		if( Statements_r == NULL ){
/*301*/ 			Statements_err = 0;
/*302*/ 		} else if( (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 24) == NULL ){
/*304*/ 			Statements_err = 0;
/*306*/ 		} else {
/*306*/ 			Statements_err = m2_stoi((STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 25));
/*307*/ 			Statements_err_name = Errors_CodeToName(Statements_err);
/*308*/ 			if( Statements_err_name == NULL ){
/*309*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"invalid error code: ", m2runtime_itos(Statements_err), (STRING *) 1));
/*310*/ 				Statements_err = 0;
/*311*/ 			} else if( (! *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 26) && !Errors_IsUserError(Statements_err)) ){
/*312*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"error code forbidden in user's program: ", Statements_err_name, (STRING *) 1));
/*315*/ 			}
/*317*/ 		}
/*317*/ 	} else {
/*317*/ 		Statements_err = 1024;
/*320*/ 	}
/*320*/ 	Errors_RaiseErrors(Statements_err);
/*322*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `)'");
/*323*/ 	Scanner_ReadSym();
/*328*/ }


/*346*/ void
/*346*/ Statements_DocBlockCheckAllowedLineTags(int Statements_allow, STRING *Statements_documenting_what)
/*346*/ {

/*348*/ 	void
/*348*/ 	Statements_err(STRING *Statements_tag)
/*348*/ 	{
/*348*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"invalid DocBlock line tag `", Statements_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"': not allowed for ", Statements_documenting_what, (STRING *) 1));
/*353*/ 	}

/*353*/ 	if( Statements_pdb == NULL ){
/*355*/ 		return ;
/*357*/ 	}
/*357*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 27) != NULL) && (((Statements_allow & 2) == 0))) ){
/*358*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"@var");
/*360*/ 	}
/*360*/ 	if( (((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 28) != NULL) && (((Statements_allow & 4) == 0))) ){
/*361*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"@param");
/*363*/ 	}
/*363*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 29) != NULL) && (((Statements_allow & 8) == 0))) ){
/*364*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@return");
/*366*/ 	}
/*366*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 30) && (((Statements_allow & 16) == 0))) ){
/*367*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"@abstract");
/*369*/ 	}
/*369*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 8 * sizeof(int), Statements_0err_entry_get, 31) && (((Statements_allow & 32) == 0))) ){
/*370*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@static");
/*372*/ 	}
/*372*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 32) && (((Statements_allow & 64) == 0))) ){
/*373*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"@final");
/*375*/ 	}
/*375*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 33) && (((Statements_allow & 128) == 0))) ){
/*376*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"@access private");
/*378*/ 	}
/*378*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 34) && (((Statements_allow & 256) == 0))) ){
/*379*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"@access protected");
/*381*/ 	}
/*381*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 35) && (((Statements_allow & 512) == 0))) ){
/*382*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"@access public");
/*384*/ 	}
/*384*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 36) && (((Statements_allow & 1) == 0))) ){
/*385*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"@package");
/*387*/ 	}
/*387*/ 	if( (((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 37) != NULL) && (((Statements_allow & 1024) == 0))) ){
/*388*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@global");
/*390*/ 	}
/*390*/ 	if( (((m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 38)) > 0)) && (((Statements_allow & 2048) == 0))) ){
/*391*/ 		Statements_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@throws");
/*394*/ 	}
/*396*/ }


/*398*/ void
/*398*/ Statements_FatalUnsupportedOldStyleSyntax(void)
/*398*/ {
/*398*/ 	Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\67,\0,\0,\0)"unsupported old-style syntax. Please use {...} instead.");
/*403*/ }

	static int Statements_ForwardParseStatement(void);
	static RECORD * Statements_ParsePackage(STRING *s, int module);

/*408*/ int
/*408*/ Statements_ParseStatement(void)
/*408*/ {
	return Statements_ForwardParseStatement();
/*410*/ 	m2runtime_missing_return(Statements_0err_entry_get, 39);
/*410*/ 	return 0;
/*412*/ }


/*414*/ void
/*414*/ Statements_ParseNamespace(void)
/*414*/ {
/*416*/ 	int Statements_res = 0;
/*416*/ 	if( (Globals_php_ver == 4) ){
/*417*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"namespace not available (PHP 5)");
/*419*/ 	}
/*419*/ 	Scanner_ReadSym();
/*421*/ 	if( (Scanner_sym == 29) ){
/*425*/ 		if( Namespace_isFullyQualified(Scanner_s) ){
/*426*/ 			if( (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 40) != NULL ){
/*427*/ 				Scanner_s = m2runtime_concat_STRING(0, m2runtime_CHR(92), (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 41), Scanner_s, (STRING *) 1);
/*430*/ 			}
/*430*/ 			return ;
/*432*/ 		}
/*432*/ 		Namespace_CheckSpelling(Scanner_s);
/*433*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 42) = Scanner_s;
/*434*/ 		*(ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 43) = NULL;
/*435*/ 		Scanner_ReadSym();
/*437*/ 	} else if( (Scanner_sym == 10) ){
/*439*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 44) = NULL;
/*440*/ 		*(ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 45) = NULL;
/*443*/ 	} else {
/*443*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected namespace name");
/*446*/ 	}
/*446*/ 	if( (Scanner_sym == 17) ){
/*447*/ 		Scanner_ReadSym();
/*449*/ 		return ;
/*449*/ 	} else if( (Scanner_sym == 10) ){
/*450*/ 		Statements_res = Statements_ParseStatement();
/*451*/ 		Namespace_ReportUnusedUseClauses();
/*452*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 46) = NULL;
/*453*/ 		*(ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 47) = NULL;
/*455*/ 	} else {
/*455*/ 		Scanner_UnexpectedSymbol();
/*458*/ 	}
/*460*/ }


/*467*/ void
/*467*/ Statements_ParseUse(void)
/*467*/ {
/*469*/ 	STRING * Statements_path = NULL;
/*469*/ 	if( (Globals_php_ver == 4) ){
/*470*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"`use' not available (PHP 5)");
/*472*/ 	}
/*472*/ 	Scanner_ReadSym();
/*475*/ 	do{
/*475*/ 		Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected namespace name");
/*476*/ 		Statements_path = Scanner_s;
/*477*/ 		if( Namespace_isFullyQualified(Statements_path) ){
/*478*/ 			Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\112,\0,\0,\0)"useless leading `\134' in path namespace: path namespaces are always absolute");
/*479*/ 			Statements_path = m2runtime_substr(Statements_path, 1, m2runtime_length(Statements_path), 1, Statements_0err_entry_get, 48);
/*481*/ 		}
/*481*/ 		Scanner_ReadSym();
/*484*/ 		if( (Scanner_sym == 23) ){
/*485*/ 			Scanner_ReadSym();
/*486*/ 			Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"expected identifier");
/*487*/ 			Scanner_s = Namespace_CheckBareID(Scanner_s);
/*488*/ 			Namespace_AddUse(Statements_path, Scanner_s);
/*489*/ 			Scanner_ReadSym();
/*491*/ 		} else {
/*491*/ 			Namespace_AddUse(Statements_path, NULL);
/*494*/ 		}
/*494*/ 		if( (Scanner_sym == 16) ){
/*495*/ 			Scanner_ReadSym();
/*498*/ 		} else {
/*499*/ 			goto m2runtime_loop_1;
/*500*/ 		}
/*500*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*500*/ 	Scanner_Expect(17, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `;'");
/*501*/ 	Scanner_ReadSym();
/*505*/ }


/*513*/ int
/*513*/ Statements_ParseBlock(void)
/*513*/ {
/*513*/ 	if( (Scanner_sym == 18) ){
/*514*/ 		Statements_FatalUnsupportedOldStyleSyntax();
/*516*/ 	} else {
/*516*/ 		return Statements_ParseStatement();
/*519*/ 	}
/*519*/ 	m2runtime_missing_return(Statements_0err_entry_get, 49);
/*519*/ 	return 0;
/*521*/ }


/*529*/ RECORD *
/*529*/ Statements_ParseArg(int Statements_opt_arg)
/*529*/ {
/*530*/ 	RECORD * Statements_a = NULL;
/*531*/ 	RECORD * Statements_v = NULL;
/*532*/ 	RECORD * Statements_p = NULL;
/*534*/ 	RECORD * Statements_r = NULL;
/*537*/ 	if( (Scanner_sym == 179) ){
/*538*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 50) = TRUE;
/*539*/ 		Scanner_ReadSym();
/*545*/ 	}
/*545*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 51) = Expressions_ParseType(TRUE);
/*546*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 52) == Globals_void_type ){
/*547*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"argument of type `void' not allowed");
/*553*/ 	}
/*553*/ 	if( (Scanner_sym == 73) ){
/*554*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 53) = TRUE;
/*555*/ 		Scanner_ReadSym();
/*557*/ 	} else {
/*557*/ 		if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 54) ){
/*558*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\67,\0,\0,\0)"invalid `return' attribute for argument passed by value");
/*559*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 55) = FALSE;
/*562*/ 		}
/*566*/ 	}
/*566*/ 	Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"expected name of the formal argument in function declaration");
/*567*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 56) = Scanner_s;
/*569*/ 	if( Statements_pdb != NULL ){
/*571*/ 		Statements_p = ParseDocBlock_SearchParam(Statements_pdb, Scanner_s);
/*572*/ 		if( Statements_p == NULL ){
/*573*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"missing `@param TYPE $", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"' in DocBlock above", (STRING *) 1));
/*575*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 57) == NULL ){
/*577*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 58) = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_p, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 59);
/*583*/ 		} else {
/*583*/ 			if( !Types_SameType((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 60), (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_p, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 61)) ){
/*584*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"conflicting types between DocBlock @param", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)" and actual PHP code for parameter `$", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*589*/ 			}
/*589*/ 			if( !m2runtime_eq( *(int *)m2runtime_dereference_rhs_RECORD(Statements_p, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 62),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 63)) ){
/*590*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)"conflicting passing method between DocBlock @param", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)" and actual PHP code for parameter `$", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"': must be both by value or both by reference", (STRING *) 1));
/*596*/ 			}
/*597*/ 		}
/*597*/ 		if( Statements_p != NULL ){
/*598*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_p, 3 * sizeof(void*) + 4 * sizeof(int), 3, 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 64) = TRUE;
/*602*/ 		}
/*606*/ 	}
/*606*/ 	Statements_v = Search_SearchVar(Scanner_s);
/*607*/ 	if( Statements_v != NULL ){
/*608*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"duplicated formal argument $", Scanner_s, (STRING *) 1));
/*610*/ 	}
/*610*/ 	Accounting_AccountVarLHS(Scanner_s, FALSE);
/*611*/ 	Statements_v = Search_SearchVar(Scanner_s);
/*612*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 65) || ((Globals_curr_method != NULL) &&  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 9 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 66)) ||  *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 67)) ){
/*616*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 68) = 100;
/*618*/ 	}
/*618*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 69) ){
/*619*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 70) = FALSE;
/*621*/ 	}
/*621*/ 	Scanner_ReadSym();
/*626*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 71) = TRUE;
/*627*/ 	if( (Scanner_sym == 31) ){
/*628*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 3 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 72) = FALSE;
/*629*/ 		if( (((Globals_php_ver == 4)) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 73)) ){
/*630*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\111,\0,\0,\0)"can't assign default value to formal argument passed by reference (PHP 5)");
/*632*/ 		}
/*632*/ 		Scanner_ReadSym();
/*633*/ 		Statements_r = Expressions_ParseStaticExpr();
/*634*/ 		if( Statements_r == NULL ){
/*636*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 74) == NULL ){
/*637*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 75) = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 76);
/*638*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 77) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 78);
/*640*/ 		} else {
/*640*/ 			switch(Expressions_LhsMatchRhs((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 79), (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 80))){

/*641*/ 			case 1:
/*642*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"type mismatch: formal argument of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 81)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)", default expression of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 82)), (STRING *) 1));
/*645*/ 			break;

/*645*/ 			case 2:
/*646*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"type mismatch: formal argument of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 83)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)", default expression of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 84)), (STRING *) 1));
/*650*/ 			break;
/*651*/ 			}
/*651*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_a, 3 * sizeof(void*) + 5 * sizeof(int), 3, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 85) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 86);
/*653*/ 		}
/*653*/ 	} else if( Statements_opt_arg ){
/*654*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"missing default value for argument `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_a, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 87), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"'. Hint: mandatory arguments can't follow the default ones.", (STRING *) 1));
/*658*/ 	}
/*658*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 88) == NULL ){
/*659*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"undefined type for argument `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_a, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 89), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"'. Hint: you may", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\61,\0,\0,\0)" indicate an explicit type (example: `/*.int.*/ $", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_a, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 90), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"')", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)" or assign a default value (example: `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_a, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 91), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"=123')", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)" or add a DocBlock line tag (example: `@param int $", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_a, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 92), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"').", (STRING *) 1));
/*666*/ 	}
/*666*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 93) = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 94);
/*667*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 95) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_a, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 96);
/*673*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 97) = ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 98);
/*674*/ 	return Statements_a;
/*678*/ }


/*689*/ void
/*689*/ Statements_ParseArgsListDecl(RECORD *Statements_sign)
/*689*/ {
/*690*/ 	RECORD * Statements_a = NULL;
/*692*/ 	int Statements_opt_arg = 0;
/*692*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"expected '(' in function declaration");
/*693*/ 	Scanner_ReadSym();
/*695*/ 	if( (Scanner_sym == 13) ){
/*698*/ 	} else if( (Scanner_sym == 156) ){
/*700*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 99) = TRUE;
/*701*/ 		Scanner_ReadSym();
/*706*/ 	} else {
/*707*/ 		do{
/*707*/ 			if( (Scanner_sym == 156) ){
/*708*/ 				Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\137,\0,\0,\0)"there must be a meta-code comma `,' separating the special symbol args from the other arguments");
/*711*/ 			}
/*711*/ 			Statements_a = Statements_ParseArg(Statements_opt_arg);
/*712*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 100), sizeof(void *), 1, Statements_0err_entry_get, 101) = Statements_a;
/*713*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 3 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 102) ){
/*714*/ 				m2_inc((int *)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 103), 1);
/*716*/ 			} else {
/*716*/ 				Statements_opt_arg = TRUE;
/*719*/ 			}
/*719*/ 			if( (Scanner_sym == 16) ){
/*720*/ 				Scanner_ReadSym();
/*722*/ 			} else if( (Scanner_sym == 134) ){
/*723*/ 				Scanner_ReadSym();
/*724*/ 				Scanner_Expect(156, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"expected `args'");
/*725*/ 				*(int *)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 104) = TRUE;
/*726*/ 				Scanner_ReadSym();
/*730*/ 				goto m2runtime_loop_1;
/*731*/ 			} else {
/*733*/ 				goto m2runtime_loop_1;
/*734*/ 			}
/*736*/ 		}while(TRUE);
m2runtime_loop_1: ;
/*737*/ 	}
/*737*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"expected ')' or ',' in function declaration");
/*738*/ 	ParseDocBlock_ReportUnusedParams(Statements_pdb);
/*739*/ 	Scanner_ReadSym();
/*743*/ }


/*744*/ int
/*744*/ Statements_SameSign(RECORD *Statements_a, RECORD *Statements_b)
/*744*/ {
/*746*/ 	int Statements_i = 0;
/*746*/ 	if( (!Types_SameType((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_a, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 105), (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_b, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 106)) || !m2runtime_eq( *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 107),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_b, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 108))) ){
/*749*/ 		return FALSE;
/*751*/ 	}
/*751*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 2 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 109) !=  *(int *)m2runtime_dereference_rhs_RECORD(Statements_b, 2 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 110)) ){
/*752*/ 		return FALSE;
/*754*/ 	}
/*754*/ 	if( (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 111)) != m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_b, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 112))) ){
/*755*/ 		return FALSE;
/*757*/ 	}
/*757*/ 	{
/*757*/ 		int m2runtime_for_limit_1;
/*757*/ 		Statements_i = 0;
/*757*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 113)) - 1);
/*758*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*758*/ 			if( (!Types_SameType((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 114), Statements_i, Statements_0err_entry_get, 115), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 116), (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_b, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 117), Statements_i, Statements_0err_entry_get, 118), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 119)) || !m2runtime_eq( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 120), Statements_i, Statements_0err_entry_get, 121), 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 122),  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_b, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 123), Statements_i, Statements_0err_entry_get, 124), 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 125)) || !m2runtime_eq( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 126), Statements_i, Statements_0err_entry_get, 127), 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 128),  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_b, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 129), Statements_i, Statements_0err_entry_get, 130), 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 131))) ){
/*762*/ 				return FALSE;
/*765*/ 			}
/*765*/ 		}
/*765*/ 	}
/*765*/ 	return TRUE;
/*769*/ }


/*775*/ void
/*775*/ Statements_ParseFuncDecl(int Statements_private, RECORD *Statements_t)
/*775*/ {

/*777*/ 	void
/*777*/ 	Statements_CheckSpecialFunc(RECORD *Statements_f)
/*777*/ 	{
/*777*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 132), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"cast") == 0 ){
/*778*/ 			if( (Globals_php_ver == 4) ){
/*779*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"function name `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 133), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"' is reserved for special use by PHPLint under PHP 5", (STRING *) 1));
/*782*/ 			}
/*782*/ 		} else if( (((m2runtime_length((STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 134)) >= 2)) && (m2runtime_strcmp(m2runtime_substr((STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 135), 0, 2, 1, Statements_0err_entry_get, 136), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"__") == 0)) ){
/*783*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 137), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__autoload") == 0 ){
/*784*/ 				if( (Globals_php_ver == 4) ){
/*785*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"function name `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 138), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"' is reserved for special use in PHP 5", (STRING *) 1));
/*788*/ 				} else {
/*788*/ 					Globals_autoload_function = Statements_f;
/*791*/ 				}
/*791*/ 			} else {
/*791*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 139), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\146,\0,\0,\0)"': names beginning with two underscores are reserved for future extensions of the language, do not use", (STRING *) 1));
/*795*/ 			}
/*796*/ 		}
/*798*/ 	}


/*799*/ 	void
/*799*/ 	Statements_CheckAutoloadSignature(RECORD *Statements_f)
/*799*/ 	{
/*802*/ 		STRING * Statements_sign_actual = NULL;
/*802*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 140), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__autoload") != 0 ){
/*804*/ 			return ;
/*805*/ 		}
/*805*/ 		Statements_sign_actual = Types_FunctionSignatureToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 141));
/*806*/ 		if( m2runtime_strcmp(Statements_sign_actual, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"void(string)") != 0 ){
/*807*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 142), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"invalid signature ", Statements_sign_actual, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)" for special function __autoload(), expected signature is ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"void(string)", (STRING *) 1));
/*812*/ 		}
/*814*/ 	}


/*815*/ 	void
/*815*/ 	Statements_CheckCastSignature(RECORD *Statements_f)
/*815*/ 	{
/*818*/ 		STRING * Statements_sign_actual = NULL;
/*818*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 143), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"cast") != 0 ){
/*820*/ 			return ;
/*821*/ 		}
/*821*/ 		Statements_sign_actual = Types_FunctionSignatureToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 144));
/*822*/ 		if( m2runtime_strcmp(Statements_sign_actual, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"mixed(string, mixed)") != 0 ){
/*823*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 145), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"invalid signature ", Statements_sign_actual, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)" for special function cast(), expected signature is ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"mixed(string, mixed)", (STRING *) 1));
/*828*/ 		}
/*831*/ 	}

/*832*/ 	RECORD * Statements_f = NULL;
/*833*/ 	RECORD * Statements_parent_func = NULL;
/*834*/ 	RECORD * Statements_old_sign = NULL;
/*834*/ 	RECORD * Statements_sign = NULL;
/*835*/ 	int Statements_guess = 0;
/*836*/ 	RECORD * Statements_proto_in = NULL;
/*837*/ 	ARRAY * Statements_proto_exceptions = NULL;
/*838*/ 	STRING * Statements_err = NULL;
/*840*/ 	int Statements_res = 0;
/*841*/ 	Statements_DocBlockCheckAllowedLineTags((((4 | 8) | 128) | 2048), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"function");
/*844*/ 	if( (!Statements_private && (Statements_pdb != NULL) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 146)) ){
/*845*/ 		Statements_private = TRUE;
/*848*/ 	}
/*848*/ 	if( ((Statements_t == NULL) && (Statements_pdb != NULL)) ){
/*849*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 147) == NULL ){
/*850*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"missing `@return TYPE' declaration in DocBlock above");
/*852*/ 		} else {
/*852*/ 			Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 148);
/*855*/ 		}
/*855*/ 	}
/*855*/ 	if( Statements_t == NULL ){
/*856*/ 		Statements_guess = TRUE;
/*858*/ 	}
/*858*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 149) = Statements_t;
/*860*/ 	Scanner_ReadSym();
/*862*/ 	if( (Scanner_sym == 73) ){
/*863*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 150) = TRUE;
/*864*/ 		if( (Globals_php_ver == 5) ){
/*865*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"obsolete syntax `function &func()', don't use in PHP 5");
/*867*/ 		}
/*867*/ 		Scanner_ReadSym();
/*874*/ 	}
/*874*/ 	Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"expected function name after `function'");
/*876*/ 	if( (Globals_scope > 0) ){
/*877*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"' nested inside another function.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)" The scope of this function is global but it will exist only if", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)" the parent function will be called. If the parent function is", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)" called once more, this will give a fatal error.", (STRING *) 1));
/*883*/ 	}
/*883*/ 	Scanner_s = Namespace_CheckBareID(Scanner_s);
/*884*/ 	Scanner_s = Namespace_Absolute(Scanner_s);
/*885*/ 	Statements_f = Search_SearchFuncByAbsName(Scanner_s, TRUE);
/*886*/ 	if( Statements_f == NULL ){
/*888*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 151) = Scanner_s;
/*889*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 152) = str_tolower(Scanner_s);
/*890*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 153) = Statements_private;
/*891*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 154) = Scanner_here();
/*892*/ 		if( !Accounting_report_unused ){
/*893*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 155) = 100;
/*895*/ 		}
/*895*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 156) = NULL;
/*896*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 157) = NULL;
/*897*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_funcs, sizeof(void *), 1, Statements_0err_entry_get, 158) = Statements_f;
/*898*/ 		Statements_CheckSpecialFunc(Statements_f);
/*900*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_f, 10 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 159) ){
/*902*/ 		Statements_old_sign = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 160);
/*903*/ 		Statements_proto_in = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 161);
/*904*/ 		Statements_proto_exceptions = (ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_f, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 162);
/*905*/ 		*(ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 163) = NULL;
/*907*/ 		if( (( *(int *)m2runtime_dereference_rhs_RECORD(Statements_f, 10 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 164) && !Statements_private) || (! *(int *)m2runtime_dereference_rhs_RECORD(Statements_f, 10 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 165) && Statements_private)) ){
/*909*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)"mismatch on the `private' attribute, check prototype in ", Scanner_reference(Statements_proto_in), (STRING *) 1));
/*912*/ 		}
/*912*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_f, 10 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 166) == 0) ){
/*913*/ 			Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 167), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"()' declared forward in ", Scanner_reference(Statements_proto_in), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)" but never used before implementation", (STRING *) 1));
/*917*/ 		}
/*917*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 168) == NULL ){
/*920*/ 		if( (Statements_private && (m2runtime_strcmp(Scanner_fn, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 169), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 170)) != 0)) ){
/*921*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)"' declared private after being used in external package ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 171)), (STRING *) 1));
/*927*/ 		}
/*927*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 172) = Scanner_s;
/*928*/ 		Statements_old_sign = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 173);
/*929*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 174) = Statements_private;
/*932*/ 	} else {
/*932*/ 		Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 175)), (STRING *) 1));
/*937*/ 	}
/*937*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 176) = Statements_sign;
/*938*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 177) = Scanner_here();
/*939*/ 	Statements_parent_func = Globals_curr_func;
/*940*/ 	Globals_curr_func = Statements_f;
/*941*/ 	m2_inc(&Globals_scope, 1);
/*942*/ 	Scanner_ReadSym();
/*947*/ 	Statements_ParseArgsListDecl(Statements_sign);
/*952*/ 	if( (Scanner_sym == 178) ){
/*953*/ 		Exceptions_ParseThrows();
/*960*/ 	}
/*960*/ 	if( Statements_pdb != NULL ){
/*961*/ 		Exceptions_AddExceptions((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 178));
/*968*/ 	}
/*968*/ 	if( Statements_pdb != NULL ){
/*969*/ 		*(ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 179) = (ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 180);
/*972*/ 	}
/*972*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_f, 10 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 181) ){
/*976*/ 		Statements_err = Classes_ClassesList(Classes_Sort(Classes_OrphanClasses(Classes_CheckedExceptionsSubset(Statements_proto_exceptions), Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_f, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 182)))));
/*984*/ 		if( m2runtime_strcmp(Statements_err, NULL) > 0 ){
/*985*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 183), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 184), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\112,\0,\0,\0)"()' throws more exceptions than those listed in the prototype declared in ", Scanner_reference(Statements_proto_in), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", Statements_err, (STRING *) 1));
/*989*/ 		}
/*989*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 185) != NULL ){
/*993*/ 		if( Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_f, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 186)) != NULL ){
/*994*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 187), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 188), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"()' already guessed in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 189)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)" cannot throw unexpected exception(s): ", Classes_ClassesList(Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_f, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 190))), (STRING *) 1));
/*1000*/ 		}
/*1004*/ 	}
/*1004*/ 	if( (Scanner_sym == 183) ){
/*1005*/ 		if( Statements_pdb != NULL ){
/*1006*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing PhpDoc and DOC documenting style");
/*1007*/ 			Statements_pdb = NULL;
/*1009*/ 		}
/*1009*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 191) = Scanner_s;
/*1010*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 192) = Documentator_ExtractDeprecated(Scanner_s);
/*1011*/ 		Scanner_ReadSym();
/*1012*/ 	} else if( Statements_pdb != NULL ){
/*1013*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 193) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 194);
/*1014*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 195) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 196));
/*1015*/ 		Statements_pdb = NULL;
/*1021*/ 	}
/*1021*/ 	Scanner_Expect(10, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"expected '{' in function body declaration");
/*1022*/ 	Statements_res = Statements_ParseBlock();
/*1023*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 197) == NULL ){
/*1025*/ 		Statements_guess = TRUE;
/*1026*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 198) = Globals_void_type;
/*1027*/ 	} else if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 199) != Globals_void_type) && (((Statements_res & 1) != 0)) && ! *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 200)) ){
/*1033*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 201), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\105,\0,\0,\0)"missing `return' in at least one execution path in non-void function ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 202), (STRING *) 1));
/*1035*/ 	}
/*1035*/ 	Statements_CheckFormalArgsByReference(FALSE);
/*1037*/ 	Expressions_CleanCurrentScope();
/*1038*/ 	m2_inc(&Globals_scope, -1);
/*1039*/ 	Globals_curr_func = Statements_parent_func;
/*1041*/ 	if( Statements_guess ){
/*1042*/ 		Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 203), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"guessed signature of the function `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 204), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"()' as ", Types_FunctionSignatureToString(Statements_sign), (STRING *) 1));
/*1046*/ 	}
/*1046*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_f, 10 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 205) ){
/*1050*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_f, 10 * sizeof(void*) + 6 * sizeof(int), 10, 10 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 206) = FALSE;
/*1051*/ 		if( !Statements_SameSign(Statements_old_sign, Statements_sign) ){
/*1052*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 207), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 208), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"()': the actual signature ", Types_FunctionSignatureToString(Statements_sign), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)" does not match the prototype ", Types_FunctionSignatureToString(Statements_old_sign), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)" as declared in ", Scanner_reference(Statements_proto_in), (STRING *) 1));
/*1058*/ 		}
/*1058*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 209) != NULL ){
/*1062*/ 		if( !Statements_SameSign(Statements_old_sign, Statements_sign) ){
/*1063*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 210), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"function `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 211), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"()': declared signature ", Types_FunctionSignatureToString(Statements_sign), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)" differs from signature ", Types_FunctionSignatureToString(Statements_old_sign), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)" as guessed in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 212)), (STRING *) 1));
/*1070*/ 		}
/*1071*/ 	}
/*1071*/ 	Statements_CheckAutoloadSignature(Statements_f);
/*1072*/ 	Statements_CheckCastSignature(Statements_f);
/*1076*/ }


/*1077*/ void
/*1077*/ Statements_ParseBreak(void)
/*1077*/ {
/*1079*/ 	RECORD * Statements_r = NULL;
/*1079*/ 	if( (Globals_loop_level == 0) ){
/*1080*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"`break' MUST be inside a loop or a switch");
/*1082*/ 	}
/*1082*/ 	Scanner_ReadSym();
/*1083*/ 	if( (Scanner_sym != 17) ){
/*1084*/ 		Statements_r = Expressions_ParseExprOfType(Globals_int_type);
/*1085*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"`break EXPR'", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)": unadvised programming practice; can't check", (STRING *) 1));
/*1089*/ 	}
/*1091*/ }


/*1092*/ void
/*1092*/ Statements_ParseContinue(void)
/*1092*/ {
/*1094*/ 	RECORD * Statements_r = NULL;
/*1094*/ 	if( (Globals_loop_level == 0) ){
/*1095*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"`continue' MUST be inside a loop or a switch");
/*1097*/ 	}
/*1097*/ 	Scanner_ReadSym();
/*1098*/ 	if( (Scanner_sym != 17) ){
/*1099*/ 		Statements_r = Expressions_ParseExprOfType(Globals_int_type);
/*1100*/ 		Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"'continue EXPR'", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)": unadvised programming practice", (STRING *) 1));
/*1104*/ 	}
/*1108*/ }


/*1135*/ int
/*1135*/ Statements_inSet(int Statements_i, RECORD *Statements_s)
/*1135*/ {
/*1135*/ 	return (((Statements_i <  *(int *)m2runtime_dereference_rhs_RECORD(Statements_s, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 213))) || ((((Statements_i < ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_s, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 214) + m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_s, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 215))))) &&  *(int *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_s, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 216), (Statements_i -  *(int *)m2runtime_dereference_rhs_RECORD(Statements_s, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 217)), Statements_0err_entry_get, 218))));
/*1157*/ }


/*1181*/ RECORD *
/*1181*/ Statements_GrabAssignedVars(void)
/*1181*/ {
/*1182*/ 	int Statements_i = 0;
/*1182*/ 	int Statements_first = 0;
/*1184*/ 	RECORD * Statements_s = NULL;
/*1186*/ 	Statements_first = Globals_vars_n;
/*1187*/ 	Statements_i = (Globals_vars_n - 1);
/*1189*/ 	do{
/*1189*/ 		if( (((Statements_i < 0)) || (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Statements_i, Statements_0err_entry_get, 219), 7 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 220) != Globals_scope))) ){
/*1192*/ 			goto m2runtime_loop_1;
/*1192*/ 		}
/*1192*/ 		if( ! *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Statements_i, Statements_0err_entry_get, 221), 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 222) ){
/*1193*/ 			Statements_first = Statements_i;
/*1195*/ 		}
/*1195*/ 		Statements_i = (Statements_i - 1);
/*1197*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1197*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_s, 1 * sizeof(void*) + 3 * sizeof(int), 1, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 223) = Statements_first;
/*1202*/ 	{
/*1202*/ 		int m2runtime_for_limit_1;
/*1202*/ 		Statements_i = Statements_first;
/*1202*/ 		m2runtime_for_limit_1 = (Globals_vars_n - 1);
/*1203*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*1203*/ 			*(int *)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_s, 1 * sizeof(void*) + 3 * sizeof(int), 1, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 224), sizeof(int), 0, Statements_0err_entry_get, 225) =  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Statements_i, Statements_0err_entry_get, 226), 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 227);
/*1206*/ 		}
/*1206*/ 	}
/*1206*/ 	return Statements_s;
/*1210*/ }


/*1216*/ void
/*1216*/ Statements_SetAssignedVars(RECORD *Statements_s)
/*1216*/ {
/*1218*/ 	int Statements_i = 0;
/*1218*/ 	int Statements_last = 0;
/*1218*/ 	int Statements_first = 0;
/*1218*/ 	Statements_first =  *(int *)m2runtime_dereference_rhs_RECORD(Statements_s, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 228);
/*1219*/ 	Statements_last = (Statements_first + m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_s, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 229)));
/*1222*/ 	Statements_i = (Statements_first - 1);
/*1224*/ 	do{
/*1224*/ 		if( (((Statements_i < 0)) || (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, Statements_i, Statements_0err_entry_get, 230), 7 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 231) != Globals_scope))) ){
/*1227*/ 			goto m2runtime_loop_1;
/*1227*/ 		}
/*1227*/ 		*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_ARRAY(&Globals_vars, sizeof(void *), 1, Statements_i, Statements_0err_entry_get, 232), 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 233) = TRUE;
/*1228*/ 		Statements_i = (Statements_i - 1);
/*1232*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1232*/ 	{
/*1232*/ 		int m2runtime_for_limit_1;
/*1232*/ 		Statements_i = Statements_first;
/*1232*/ 		m2runtime_for_limit_1 = (Statements_last - 1);
/*1233*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*1233*/ 			*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_ARRAY(&Globals_vars, sizeof(void *), 1, Statements_i, Statements_0err_entry_get, 234), 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 235) =  *(int *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_s, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 236), (Statements_i - Statements_first), Statements_0err_entry_get, 237);
/*1237*/ 		}
/*1237*/ 	}
/*1237*/ 	{
/*1237*/ 		int m2runtime_for_limit_1;
/*1237*/ 		Statements_i = Statements_last;
/*1237*/ 		m2runtime_for_limit_1 = (Globals_vars_n - 1);
/*1238*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*1238*/ 			*(int *)m2runtime_dereference_lhs_RECORD((RECORD **)m2runtime_dereference_lhs_ARRAY(&Globals_vars, sizeof(void *), 1, Statements_i, Statements_0err_entry_get, 238), 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 239) = FALSE;
/*1241*/ 		}
/*1241*/ 	}
/*1243*/ }


/*1249*/ RECORD *
/*1249*/ Statements_IntersectAssignedVars(RECORD *Statements_a, RECORD *Statements_b)
/*1249*/ {
/*1250*/ 	int Statements_i = 0;
/*1250*/ 	int Statements_i2 = 0;
/*1250*/ 	int Statements_i1 = 0;
/*1252*/ 	RECORD * Statements_c = NULL;
/*1255*/ 	Statements_i1 = m2_min( *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 240),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_b, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 241));
/*1256*/ 	Statements_i2 = m2_max(( *(int *)m2runtime_dereference_rhs_RECORD(Statements_a, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 242) + m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_a, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 243))), ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_b, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 244) + m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_b, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 245))));
/*1259*/ 	while( (((Statements_i1 < Statements_i2)) && Statements_inSet(Statements_i1, Statements_a) && Statements_inSet(Statements_i1, Statements_b)) ){
/*1260*/ 		Statements_i1 = (Statements_i1 + 1);
/*1264*/ 	}
/*1264*/ 	while( (((Statements_i2 > Statements_i1)) && ((!Statements_inSet((Statements_i2 - 1), Statements_a) || !Statements_inSet((Statements_i2 - 1), Statements_b)))) ){
/*1265*/ 		Statements_i2 = (Statements_i2 - 1);
/*1270*/ 	}
/*1270*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_c, 1 * sizeof(void*) + 3 * sizeof(int), 1, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 246) = Statements_i1;
/*1271*/ 	{
/*1271*/ 		int m2runtime_for_limit_1;
/*1271*/ 		Statements_i = Statements_i1;
/*1271*/ 		m2runtime_for_limit_1 = (Statements_i2 - 1);
/*1272*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*1272*/ 			*(int *)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_c, 1 * sizeof(void*) + 3 * sizeof(int), 1, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 247), sizeof(int), 0, Statements_0err_entry_get, 248) = (Statements_inSet(Statements_i, Statements_a) && Statements_inSet(Statements_i, Statements_b));
/*1275*/ 		}
/*1275*/ 	}
/*1275*/ 	return Statements_c;
/*1279*/ }


/*1284*/ int
/*1284*/ Statements_ParseCompound(void)
/*1284*/ {
/*1286*/ 	int Statements_p = 0;
/*1286*/ 	int Statements_res = 0;
/*1286*/ 	Scanner_ReadSym();
/*1287*/ 	Statements_res = 1;
/*1288*/ 	while( (Scanner_sym != 11) ){
/*1289*/ 		if( ((Statements_res & 1) == 0) ){
/*1290*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"unreachable statement");
/*1292*/ 		}
/*1292*/ 		Statements_p = Statements_ParseStatement();
/*1293*/ 		Statements_res = (((Statements_res & ~1)) | Statements_p);
/*1295*/ 	}
/*1295*/ 	Scanner_ReadSym();
/*1296*/ 	return Statements_res;
/*1300*/ }


/*1302*/ int
/*1302*/ Statements_isTrue(RECORD *Statements_r)
/*1302*/ {
/*1302*/ 	return ((Statements_r != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 249) == Globals_boolean_type) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 250), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE") == 0));
/*1306*/ }


/*1308*/ int
/*1308*/ Statements_isFalse(RECORD *Statements_r)
/*1308*/ {
/*1308*/ 	return ((Statements_r != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 251) == Globals_boolean_type) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 252), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE") == 0));
/*1312*/ }


/*1314*/ int
/*1314*/ Statements_ParseWhile(void)
/*1314*/ {
/*1315*/ 	RECORD * Statements_r = NULL;
/*1316*/ 	int Statements_p = 0;
/*1316*/ 	int Statements_res = 0;
/*1318*/ 	RECORD * Statements_s = NULL;
/*1318*/ 	Scanner_ReadSym();
/*1319*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected '('");
/*1320*/ 	Scanner_ReadSym();
/*1321*/ 	Statements_r = Expressions_ParseExpr();
/*1322*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"expected closing ')' of the 'while' statement");
/*1323*/ 	Expressions_CheckBoolean((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"`while(EXPR)'", Statements_r);
/*1324*/ 	Scanner_ReadSym();
/*1342*/ 	if( Statements_isTrue(Statements_r) ){
/*1343*/ 		Statements_res = 1;
/*1344*/ 	} else if( Statements_isFalse(Statements_r) ){
/*1345*/ 		Statements_res = 2;
/*1347*/ 	} else {
/*1347*/ 		Statements_res = (1 | 2);
/*1351*/ 	}
/*1351*/ 	if( ((Statements_res & 1) == 0) ){
/*1352*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"unreachable statement");
/*1354*/ 	}
/*1354*/ 	m2_inc(&Globals_loop_level, 1);
/*1355*/ 	Statements_s = Statements_GrabAssignedVars();
/*1356*/ 	Statements_p = Statements_ParseBlock();
/*1357*/ 	Statements_SetAssignedVars(Statements_s);
/*1358*/ 	m2_inc(&Globals_loop_level, -1);
/*1359*/ 	Statements_res = (Statements_res | Statements_p);
/*1362*/ 	if( ((Statements_res & 1) != 0) ){
/*1363*/ 		Statements_res = (((Statements_res & ~1)) | 4);
/*1367*/ 	}
/*1367*/ 	if( ((Statements_res & 2) != 0) ){
/*1368*/ 		Statements_res = (Statements_res | 1);
/*1370*/ 	}
/*1370*/ 	Statements_res = (Statements_res & ((8 | 1)));
/*1372*/ 	return Statements_res;
/*1376*/ }


/*1378*/ int
/*1378*/ Statements_ParseDo(void)
/*1378*/ {
/*1379*/ 	RECORD * Statements_r = NULL;
/*1381*/ 	int Statements_res = 0;
/*1398*/ 	Scanner_ReadSym();
/*1399*/ 	m2_inc(&Globals_loop_level, 1);
/*1400*/ 	Statements_res = Statements_ParseBlock();
/*1401*/ 	m2_inc(&Globals_loop_level, -1);
/*1402*/ 	Scanner_Expect(24, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"expected 'while' in do...while() statement");
/*1403*/ 	Scanner_ReadSym();
/*1404*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected '('");
/*1405*/ 	Scanner_ReadSym();
/*1406*/ 	Statements_r = Expressions_ParseExpr();
/*1407*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"expected closing ')' of while(...)");
/*1408*/ 	Expressions_CheckBoolean((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"`do ... while(EXPR)'", Statements_r);
/*1409*/ 	Scanner_ReadSym();
/*1412*/ 	if( ((Statements_res & 1) == 0) ){
/*1414*/ 	} else if( Statements_isTrue(Statements_r) ){
/*1416*/ 		Statements_res = ((Statements_res & ~1) | 4);
/*1417*/ 	} else if( Statements_isFalse(Statements_r) ){
/*1419*/ 		Statements_res = ((Statements_res & ~1) | 2);
/*1422*/ 	} else {
/*1422*/ 		Statements_res = (Statements_res | ((4 | 2)));
/*1426*/ 	}
/*1426*/ 	Statements_res = (Statements_res & ~((1 | 4)));
/*1427*/ 	if( ((Statements_res & 2) != 0) ){
/*1428*/ 		Statements_res = ((Statements_res & ~2) | 1);
/*1430*/ 	}
/*1430*/ 	return Statements_res;
/*1434*/ }


/*1439*/ int
/*1439*/ Statements_ParseFor(void)
/*1439*/ {
/*1440*/ 	RECORD * Statements_expr2 = NULL;
/*1440*/ 	RECORD * Statements_r = NULL;
/*1441*/ 	int Statements_p = 0;
/*1441*/ 	int Statements_res = 0;
/*1443*/ 	RECORD * Statements_before = NULL;
/*1443*/ 	Scanner_ReadSym();
/*1444*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected '('");
/*1445*/ 	Scanner_ReadSym();
/*1448*/ 	if( (Scanner_sym != 17) ){
/*1449*/ 		Statements_r = Expressions_ParseExprList();
/*1451*/ 	}
/*1451*/ 	Scanner_Expect(17, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `;'");
/*1452*/ 	Scanner_ReadSym();
/*1455*/ 	if( (Scanner_sym != 17) ){
/*1456*/ 		Statements_expr2 = Expressions_ParseExprList();
/*1457*/ 		Expressions_CheckBoolean((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"`for(...; EXPR; ...)'", Statements_expr2);
/*1459*/ 	}
/*1459*/ 	Scanner_Expect(17, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `;'");
/*1460*/ 	Scanner_ReadSym();
/*1462*/ 	Statements_before = Statements_GrabAssignedVars();
/*1465*/ 	if( (Scanner_sym != 13) ){
/*1466*/ 		Statements_r = Expressions_ParseExprList();
/*1468*/ 	}
/*1468*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"expected closing `)' of the `for' statement");
/*1469*/ 	Scanner_ReadSym();
/*1471*/ 	m2_inc(&Globals_loop_level, 1);
/*1472*/ 	Statements_p = Statements_ParseBlock();
/*1473*/ 	m2_inc(&Globals_loop_level, -1);
/*1475*/ 	if( ((Statements_expr2 == NULL) || Statements_isTrue(Statements_expr2)) ){
/*1479*/ 		if( ((Statements_p & 2) != 0) ){
/*1480*/ 			Statements_res = 1;
/*1483*/ 		}
/*1483*/ 		Statements_res = (Statements_res | ((Statements_p & 8)));
/*1486*/ 	} else {
/*1486*/ 		Statements_res = 1;
/*1488*/ 		Statements_res = (Statements_res | ((Statements_p & 8)));
/*1489*/ 		Statements_SetAssignedVars(Statements_before);
/*1492*/ 	}
/*1492*/ 	return Statements_res;
/*1496*/ }


/*1503*/ int
/*1503*/ Statements_ParseForeach(void)
/*1503*/ {
/*1504*/ 	RECORD * Statements_r = NULL;
/*1505*/ 	RECORD * Statements_elem_type = NULL;
/*1505*/ 	RECORD * Statements_index_type = NULL;
/*1506*/ 	RECORD * Statements_v = NULL;
/*1506*/ 	RECORD * Statements_k = NULL;
/*1507*/ 	int Statements_by_addr = 0;
/*1508*/ 	int Statements_p = 0;
/*1508*/ 	int Statements_res = 0;
/*1509*/ 	RECORD * Statements_before = NULL;
/*1510*/ 	RECORD * Statements_iterator = NULL;
/*1511*/ 	RECORD * Statements_c = NULL;
/*1513*/ 	RECORD * Statements_m = NULL;
/*1513*/ 	Scanner_ReadSym();
/*1514*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"required `(' after `foreach'");
/*1515*/ 	Scanner_ReadSym();
/*1518*/ 	Statements_r = Expressions_ParseExpr();
/*1519*/ 	Statements_index_type = Globals_mixed_type;
/*1520*/ 	Statements_elem_type = Globals_mixed_type;
/*1521*/ 	if( Statements_r == NULL ){
/*1524*/ 	} else if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 253), 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 254) == 6) ){
/*1525*/ 		switch( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 255), 2 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 256)){

/*1526*/ 		case 1:
/*1526*/ 		Statements_index_type = Globals_mixed_type;
/*1527*/ 		break;

/*1527*/ 		case 3:
/*1527*/ 		Statements_index_type = Globals_int_type;
/*1528*/ 		break;

/*1528*/ 		case 5:
/*1528*/ 		Statements_index_type = Globals_string_type;
/*1529*/ 		break;

/*1529*/ 		case 7:
/*1529*/ 		Statements_index_type = Globals_mixed_type;
/*1531*/ 		break;

/*1531*/ 		default: m2runtime_missing_case_in_switch(Statements_0err_entry_get, 257);
/*1531*/ 		}
/*1531*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 258), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 259) != NULL ){
/*1532*/ 			Statements_elem_type = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 260), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 261);
/*1535*/ 		}
/*1535*/ 	} else if( (((Globals_php_ver == 5)) && (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 262), 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 263) == 9))) ){
/*1537*/ 		if( Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 264), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 265), Classes_IteratorClass) ){
/*1539*/ 			Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 266), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 267), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"key", &Statements_c, &Statements_m);
/*1540*/ 			Statements_index_type = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 268), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 269);
/*1542*/ 			Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 270), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 271), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"current", &Statements_c, &Statements_m);
/*1543*/ 			Statements_elem_type = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 272), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 273);
/*1545*/ 		} else if( Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 274), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 275), Classes_IteratorAggregateClass) ){
/*1546*/ 			Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 276), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 277), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"getIterator", &Statements_c, &Statements_m);
/*1547*/ 			Statements_iterator = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 278), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 279), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 280);
/*1548*/ 			if( Classes_IsSubclassOf(Statements_iterator, Classes_IteratorClass) ){
/*1550*/ 				Classes_ResolveClassMethod(Statements_iterator, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"key", &Statements_c, &Statements_m);
/*1551*/ 				Statements_index_type = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 281), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 282);
/*1553*/ 				Classes_ResolveClassMethod(Statements_iterator, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"current", &Statements_c, &Statements_m);
/*1554*/ 				Statements_elem_type = (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 283), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 284);
/*1559*/ 			} else {
/*1561*/ 			}
/*1563*/ 		} else {
/*1565*/ 		}
/*1565*/ 	} else {
/*1565*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)"`foreach(EXPR' requires an array or an object, found ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 285)), (STRING *) 1));
/*1569*/ 	}
/*1569*/ 	Statements_before = Statements_GrabAssignedVars();
/*1572*/ 	Scanner_Expect(23, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\75,\0,\0,\0)"expected `as'. Hint: check `foreach( ARRAY_EXPRESSION as ...'");
/*1573*/ 	Scanner_ReadSym();
/*1576*/ 	if( (Scanner_sym == 73) ){
/*1577*/ 		if( (Globals_php_ver == 4) ){
/*1578*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"can't use `&' in `foreach' (PHP 5)");
/*1580*/ 		}
/*1580*/ 		Statements_by_addr = TRUE;
/*1581*/ 		Scanner_ReadSym();
/*1585*/ 	}
/*1585*/ 	Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"`foreach': expected variable name");
/*1586*/ 	Accounting_AccountVarLHS(Scanner_s, FALSE);
/*1587*/ 	Statements_v = Search_SearchVar(Scanner_s);
/*1588*/ 	Scanner_ReadSym();
/*1591*/ 	if( (Scanner_sym == 32) ){
/*1592*/ 		if( Statements_by_addr ){
/*1593*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"the key cannot be passed by reference");
/*1594*/ 			Statements_by_addr = FALSE;
/*1596*/ 		}
/*1596*/ 		Statements_k = Statements_v;
/*1597*/ 		Scanner_ReadSym();
/*1598*/ 		if( (Scanner_sym == 73) ){
/*1599*/ 			Statements_by_addr = TRUE;
/*1600*/ 			Scanner_ReadSym();
/*1602*/ 		}
/*1602*/ 		Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"`foreach': expected variable name after `=>'");
/*1603*/ 		Accounting_AccountVarLHS(Scanner_s, FALSE);
/*1604*/ 		Statements_v = Search_SearchVar(Scanner_s);
/*1605*/ 		Scanner_ReadSym();
/*1608*/ 	}
/*1608*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"expected closing `)' of the `foreach' statement");
/*1609*/ 	Scanner_ReadSym();
/*1614*/ 	if( Statements_k == NULL ){
/*1616*/ 	} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_k, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 286) == NULL ){
/*1618*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_k, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 287) = Statements_index_type;
/*1621*/ 	} else {
/*1621*/ 		switch(Expressions_LhsMatchRhs((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_k, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 288), Statements_index_type)){

/*1622*/ 		case 0:
/*1623*/ 		break;

/*1623*/ 		case 1:
/*1624*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"foreach(): the type of the variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_k, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 289), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"' ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_k, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 290)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)" does not match the index of ", Types_TypeToString(Statements_index_type), (STRING *) 1));
/*1627*/ 		break;

/*1627*/ 		case 2:
/*1628*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"foreach(): the type of the variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_k, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 291), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"' ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_k, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 292)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)" does not match the index of ", Types_TypeToString(Statements_index_type), (STRING *) 1));
/*1632*/ 		break;

/*1632*/ 		default: m2runtime_missing_case_in_switch(Statements_0err_entry_get, 293);
/*1633*/ 		}
/*1644*/ 	}
/*1644*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_v, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 294) == NULL ){
/*1645*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 295) = Statements_elem_type;
/*1647*/ 	} else {
/*1647*/ 		switch(Expressions_LhsMatchRhs((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_v, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 296), Statements_elem_type)){

/*1648*/ 		case 0:
/*1649*/ 		break;

/*1649*/ 		case 1:
/*1650*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"foreach(): the type of the variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_v, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 297), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"' ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_v, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 298)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)" does not match the elements of the array ", Types_TypeToString(Statements_elem_type), (STRING *) 1));
/*1654*/ 		break;

/*1654*/ 		case 2:
/*1655*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"foreach(): the type of the variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_v, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 299), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"' ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_v, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 300)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)" does not match the elements of the array ", Types_TypeToString(Statements_elem_type), (STRING *) 1));
/*1660*/ 		break;

/*1660*/ 		default: m2runtime_missing_case_in_switch(Statements_0err_entry_get, 301);
/*1661*/ 		}
/*1662*/ 	}
/*1662*/ 	m2_inc(&Globals_loop_level, 1);
/*1663*/ 	Statements_p = Statements_ParseBlock();
/*1664*/ 	m2_inc(&Globals_loop_level, -1);
/*1666*/ 	Statements_SetAssignedVars(Statements_before);
/*1668*/ 	Statements_res = (1 | (Statements_p & 8));
/*1669*/ 	return Statements_res;
/*1673*/ }


/*1675*/ int
/*1675*/ Statements_ParseSwitch(void)
/*1675*/ {

/*1677*/ 	void
/*1677*/ 	Statements_CheckAndDiscardUnreachableStatements(void)
/*1677*/ 	{
/*1679*/ 		int Statements_res = 0;
/*1679*/ 		if( (((Scanner_sym == 110)) || ((Scanner_sym == 112)) || ((Scanner_sym == 169)) || ((Scanner_sym == 11))) ){
/*1686*/ 			return ;
/*1688*/ 		}
/*1688*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"unreachable statement");
/*1691*/ 		do {
/*1691*/ 			Statements_res = Statements_ParseStatement();
/*1692*/ 		} while( !( (((Scanner_sym == 110)) || ((Scanner_sym == 112)) || ((Scanner_sym == 169)) || ((Scanner_sym == 11))) ));
/*1699*/ 	}

/*1701*/ 	ARRAY * Statements_labels = NULL;

/*1706*/ 	void
/*1706*/ 	Statements_checkLabel(RECORD *Statements_l)
/*1706*/ 	{
/*1708*/ 		int Statements_i = 0;
/*1708*/ 		if( ((Statements_l == NULL) || ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_l, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 302) == NULL) || ((STRING *)m2runtime_dereference_rhs_RECORD(Statements_l, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 303) == NULL)) ){
/*1710*/ 			return ;
/*1712*/ 		}
/*1712*/ 		{
/*1712*/ 			int m2runtime_for_limit_1;
/*1712*/ 			Statements_i = 0;
/*1712*/ 			m2runtime_for_limit_1 = (m2runtime_count(Statements_labels) - 1);
/*1713*/ 			for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*1713*/ 				if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_l, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 304) == (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_labels, Statements_i, Statements_0err_entry_get, 305), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 306)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_l, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 307), (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_labels, Statements_i, Statements_0err_entry_get, 308), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 309)) == 0)) ){
/*1714*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"duplicate `case' value: ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_l, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 310), (STRING *) 1));
/*1717*/ 				}
/*1717*/ 			}
/*1717*/ 		}
/*1717*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Statements_labels, sizeof(void *), 1, Statements_0err_entry_get, 311) = Statements_l;
/*1721*/ 	}

/*1722*/ 	RECORD * Statements_r = NULL;
/*1723*/ 	RECORD * Statements_t = NULL;
/*1724*/ 	int Statements_found_statements = 0;
/*1724*/ 	int Statements_found_default = 0;
/*1725*/ 	int Statements_res = 0;
/*1726*/ 	int Statements_b = 0;
/*1727*/ 	int Statements_p = 0;
/*1729*/ 	RECORD * Statements_result_set = NULL;
/*1729*/ 	RECORD * Statements_branch_set = NULL;
/*1729*/ 	RECORD * Statements_before_set = NULL;
/*1729*/ 	Scanner_ReadSym();
/*1730*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `('");
/*1731*/ 	Scanner_ReadSym();
/*1732*/ 	Statements_r = Expressions_ParseExpr();
/*1733*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `)'");
/*1734*/ 	if( Statements_r == NULL ){
/*1737*/ 	} else {
/*1737*/ 		Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 312);
/*1738*/ 		if( ((Statements_t != Globals_int_type) && (Statements_t != Globals_string_type)) ){
/*1739*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"switch(EXPR): invalid expression of type ", Types_TypeToString(Statements_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)". Expected int or string.", (STRING *) 1));
/*1741*/ 			Statements_t = NULL;
/*1744*/ 		}
/*1744*/ 	}
/*1744*/ 	Scanner_ReadSym();
/*1745*/ 	if( (Scanner_sym == 18) ){
/*1746*/ 		Statements_FatalUnsupportedOldStyleSyntax();
/*1748*/ 	}
/*1748*/ 	Scanner_Expect(10, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `{'");
/*1749*/ 	Scanner_ReadSym();
/*1750*/ 	m2_inc(&Globals_loop_level, 1);
/*1751*/ 	Statements_before_set = Statements_GrabAssignedVars();
/*1753*/ 	do{
/*1753*/ 		if( (((Scanner_sym == 110)) || ((Scanner_sym == 112))) ){
/*1755*/ 			if( (Scanner_sym == 110) ){
/*1757*/ 				do {
/*1757*/ 					Scanner_ReadSym();
/*1758*/ 					Statements_r = Expressions_ParseStaticExpr();
/*1759*/ 					if( Statements_t != NULL ){
/*1760*/ 						if( Statements_r == NULL ){
/*1763*/ 						} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 313) != Statements_t ){
/*1764*/ 							Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"invalid type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 314)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)" for the `case' branch. Expected ", Types_TypeToString(Statements_t), (STRING *) 1));
/*1769*/ 						}
/*1769*/ 					}
/*1769*/ 					Statements_checkLabel(Statements_r);
/*1770*/ 					Scanner_Expect(18, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"expected `:' after `case' expression");
/*1771*/ 					Scanner_ReadSym();
/*1772*/ 				} while( !( (Scanner_sym != 110) ));
/*1775*/ 			} else {
/*1775*/ 				if( Statements_found_default ){
/*1776*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"multiple default branches");
/*1778*/ 				}
/*1778*/ 				Statements_found_default = TRUE;
/*1779*/ 				Scanner_ReadSym();
/*1780*/ 				Scanner_Expect(18, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"expected `:' after `default'");
/*1781*/ 				Scanner_ReadSym();
/*1792*/ 			}
/*1792*/ 			Statements_found_statements = FALSE;
/*1794*/ 			Statements_b = 1;
/*1795*/ 			while( ((((Statements_b & 1) != 0)) && ((Scanner_sym != 110)) && ((Scanner_sym != 112)) && ((Scanner_sym != 168)) && ((Scanner_sym != 169)) && ((Scanner_sym != 11))) ){
/*1802*/ 				Statements_found_statements = TRUE;
/*1803*/ 				Statements_p = Statements_ParseStatement();
/*1804*/ 				Statements_b = (((Statements_b & ~1)) | Statements_p);
/*1807*/ 			}
/*1807*/ 			if( ((Statements_b & 1) == 0) ){
/*1808*/ 				Statements_CheckAndDiscardUnreachableStatements();
/*1810*/ 			} else if( (((Scanner_sym == 110)) || ((Scanner_sym == 112))) ){
/*1811*/ 				if( Statements_found_statements ){
/*1812*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"improperly terminated non-empty `switch' branch", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)" -- missing `break;'?", (STRING *) 1));
/*1816*/ 				}
/*1816*/ 			} else if( (Scanner_sym == 168) ){
/*1817*/ 				Scanner_ReadSym();
/*1818*/ 				Scanner_Expect(132, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `;'");
/*1819*/ 				Scanner_ReadSym();
/*1820*/ 				Statements_CheckAndDiscardUnreachableStatements();
/*1822*/ 			} else if( (((Scanner_sym == 11)) || ((Scanner_sym == 169))) ){
/*1823*/ 				Statements_b = (Statements_b | 2);
/*1827*/ 			}
/*1827*/ 			Statements_res = (Statements_res | (Statements_b & ((8 | 4))));
/*1829*/ 			if( ((Statements_b & 2) != 0) ){
/*1830*/ 				Statements_res = (Statements_res | 1);
/*1833*/ 			}
/*1833*/ 			if( ((Statements_b & 2) != 0) ){
/*1834*/ 				Statements_branch_set = Statements_GrabAssignedVars();
/*1835*/ 				if( Statements_result_set == NULL ){
/*1836*/ 					Statements_result_set = Statements_branch_set;
/*1838*/ 				} else {
/*1838*/ 					Statements_result_set = Statements_IntersectAssignedVars(Statements_result_set, Statements_branch_set);
/*1841*/ 				}
/*1841*/ 			}
/*1841*/ 			Statements_SetAssignedVars(Statements_before_set);
/*1843*/ 		} else if( (Scanner_sym == 169) ){
/*1844*/ 			if( Statements_found_default ){
/*1845*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"multiple default branches");
/*1847*/ 			}
/*1847*/ 			Statements_found_default = TRUE;
/*1848*/ 			Scanner_ReadSym();
/*1849*/ 			Scanner_Expect(133, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"expected `:' in meta-code");
/*1850*/ 			Scanner_ReadSym();
/*1851*/ 			Statements_res = (Statements_res | 1);
/*1852*/ 			Statements_result_set = Statements_before_set;
/*1854*/ 		} else if( (Scanner_sym == 11) ){
/*1855*/ 			if( Statements_found_default ){
/*1856*/ 				if( Statements_result_set == NULL ){
/*1857*/ 					Statements_SetAssignedVars(Statements_before_set);
/*1859*/ 				} else {
/*1859*/ 					Statements_SetAssignedVars(Statements_result_set);
/*1862*/ 				}
/*1862*/ 			} else {
/*1862*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"missing `default:' branch in `switch'");
/*1863*/ 				Statements_res = (Statements_res | 1);
/*1864*/ 				Statements_SetAssignedVars(Statements_before_set);
/*1866*/ 			}
/*1866*/ 			Scanner_ReadSym();
/*1870*/ 			goto m2runtime_loop_1;
/*1870*/ 		} else {
/*1870*/ 			Scanner_UnexpectedSymbol();
/*1874*/ 		}
/*1874*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1874*/ 	m2_inc(&Globals_loop_level, -1);
/*1876*/ 	return Statements_res;
/*1880*/ }


/*1882*/ void
/*1882*/ Statements_ParseClassConstDecl(int Statements_visibility)
/*1882*/ {
/*1883*/ 	RECORD * Statements_cl = NULL;
/*1884*/ 	RECORD * Statements_c = NULL;
/*1886*/ 	RECORD * Statements_r = NULL;
/*1888*/ 	Statements_DocBlockCheckAllowedLineTags(((128 | 256) | 512), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"class constant");
/*1891*/ 	Scanner_ReadSym();
/*1894*/ 	do{
/*1894*/ 		Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"expected constant name");
/*1899*/ 		Search_ResolveClassConst(Globals_curr_class, Scanner_s, &Statements_cl, &Statements_c);
/*1900*/ 		if( Statements_c != NULL ){
/*1901*/ 			if( ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_c, 5 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 315) ){
/*1902*/ 				if( Statements_cl == Globals_curr_class ){
/*1903*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"class constant `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' already defined in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 316)), (STRING *) 1));
/*1905*/ 				} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_cl, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 317) ||  *(int *)m2runtime_dereference_rhs_RECORD(Statements_cl, 15 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 318)) ){
/*1906*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"cannot re-define the constant `", Classes_pc(Globals_curr_class, Statements_cl), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"' inherited from interface or abstract class", (STRING *) 1));
/*1910*/ 				}
/*1910*/ 				Statements_c = NULL;
/*1911*/ 				*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 319) = Scanner_s;
/*1912*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 320), sizeof(void *), 1, Statements_0err_entry_get, 321) = Statements_c;
/*1915*/ 			}
/*1915*/ 		} else {
/*1915*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 322) = Scanner_s;
/*1916*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 323), sizeof(void *), 1, Statements_0err_entry_get, 324) = Statements_c;
/*1919*/ 		}
/*1919*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 325) = FALSE;
/*1920*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 326) = Statements_visibility;
/*1921*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 327) = Scanner_here();
/*1922*/ 		if( !Accounting_report_unused ){
/*1923*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 5 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 328) = 100;
/*1925*/ 		}
/*1925*/ 		Scanner_ReadSym();
/*1926*/ 		Scanner_Expect(31, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"expected `=' after constant name");
/*1927*/ 		Scanner_ReadSym();
/*1928*/ 		Statements_r = Expressions_ParseStaticExpr();
/*1929*/ 		if( Statements_r == NULL ){
/*1932*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 329), 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 330) == 6) ){
/*1933*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"arrays are not allowed in class constants");
/*1935*/ 		}
/*1935*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 331) = Statements_r;
/*1937*/ 		if( (Scanner_sym == 16) ){
/*1938*/ 			Scanner_ReadSym();
/*1941*/ 		} else {
/*1942*/ 			goto m2runtime_loop_1;
/*1943*/ 		}
/*1944*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1944*/ 	Scanner_Expect(17, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"missing `;'");
/*1945*/ 	Scanner_ReadSym();
/*1947*/ 	if( (Scanner_sym == 183) ){
/*1948*/ 		if( Statements_pdb != NULL ){
/*1949*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing PhpDoc and DOC documenting style");
/*1950*/ 			Statements_pdb = NULL;
/*1952*/ 		}
/*1952*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 332) = Scanner_s;
/*1953*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 333) = Documentator_ExtractDeprecated(Scanner_s);
/*1954*/ 		Scanner_ReadSym();
/*1955*/ 	} else if( Statements_pdb != NULL ){
/*1956*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 334) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 335);
/*1957*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 5 * sizeof(void*) + 6 * sizeof(int), 5, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 336) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 337));
/*1958*/ 		Statements_pdb = NULL;
/*1962*/ 	}
/*1964*/ }


/*1966*/ void
/*1966*/ Statements_ParseClassPropertyDecl(int Statements_visibility, int Statements_static, RECORD *Statements_t)
/*1966*/ {
/*1967*/ 	RECORD * Statements_P = NULL;
/*1968*/ 	RECORD * Statements_p = NULL;
/*1970*/ 	RECORD * Statements_r = NULL;
/*1973*/ 	if( (Globals_php_ver == 4) ){
/*1974*/ 		Statements_DocBlockCheckAllowedLineTags(((((2 | 32) | 128) | 256) | 512), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"property");
/*1978*/ 	} else {
/*1978*/ 		Statements_DocBlockCheckAllowedLineTags(2, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"property");
/*1982*/ 	}
/*1984*/ 	do{
/*1984*/ 		if( (Scanner_sym != 20) ){
/*1985*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"expected property name $NAME");
/*1989*/ 		}
/*1989*/ 		Search_SearchClassProperty(Globals_curr_class, Scanner_s, &Statements_P, &Statements_p);
/*1990*/ 		if( Statements_p != NULL ){
/*1991*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"property `$", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' already defined in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_p, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 338)), (STRING *) 1));
/*1996*/ 		}
/*1996*/ 		Statements_p = NULL;
/*1997*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 339) = Scanner_s;
/*1999*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 340) = Statements_visibility;
/*2002*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 6 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 341) = Statements_static;
/*2004*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 342) = Statements_t;
/*2006*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 343) = Scanner_here();
/*2007*/ 		if( !Accounting_report_unused ){
/*2008*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 6 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 344) = 100;
/*2010*/ 		}
/*2010*/ 		Scanner_ReadSym();
/*2013*/ 		if( (Scanner_sym == 31) ){
/*2014*/ 			Scanner_ReadSym();
/*2015*/ 			Statements_r = Expressions_ParseStaticExpr();
/*2016*/ 			if( Statements_r == NULL ){
/*2018*/ 			} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_p, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 345) == NULL ){
/*2019*/ 				if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 346) == Globals_null_type ){
/*2020*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\243,\0,\0,\0)"NULL value must be cast to some specific type, for example /*.(resource).*/ NULL or /*.(string).*/ NULL or /*.(array[int]string).*/ NULL or /*.(CLASSNAME).*/ NULL.");
/*2022*/ 				} else {
/*2022*/ 					*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 347) = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 348);
/*2023*/ 					*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 349) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 350);
/*2026*/ 				}
/*2026*/ 			} else {
/*2026*/ 				switch(Expressions_LhsMatchRhs((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_p, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 351), (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 352))){

/*2027*/ 				case 0:
/*2028*/ 				break;

/*2028*/ 				case 1:
/*2029*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"property `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_p, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 353), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"' of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_p, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 354)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)", expression of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 355)), (STRING *) 1));
/*2032*/ 				break;

/*2032*/ 				case 2:
/*2033*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"property `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_p, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 356), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"' of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_p, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 357)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)", expression of type ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 358)), (STRING *) 1));
/*2037*/ 				break;

/*2037*/ 				default: m2runtime_missing_case_in_switch(Statements_0err_entry_get, 359);
/*2037*/ 				}
/*2037*/ 				*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 360) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 361);
/*2039*/ 			}
/*2039*/ 		} else if( Statements_t == NULL ){
/*2040*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"undefined type for property `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_p, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 362), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"'. Hint: you may", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\61,\0,\0,\0)" indicate an explicit type (example: `/*.int.*/ $", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_p, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 363), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"')", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)" or assign a default value (example: `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_p, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 364), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"=123')", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)" or add a DocBlock line tag (example: `@var int').", (STRING *) 1));
/*2046*/ 		} else {
/*2046*/ 			if( (Expressions_LhsMatchRhs(Statements_t, Globals_null_type) != 0) ){
/*2047*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"property $", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_p, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 365), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)" of type ", Types_TypeToString(Statements_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\170,\0,\0,\0)" requires an initial value, otherwise it would be initialized to the invalid value NULL at runtime (PHPLint restriction)", (STRING *) 1));
/*2051*/ 			}
/*2052*/ 		}
/*2052*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 366), sizeof(void *), 1, Statements_0err_entry_get, 367) = Statements_p;
/*2055*/ 		if( (Scanner_sym == 16) ){
/*2056*/ 			Scanner_ReadSym();
/*2059*/ 		} else {
/*2060*/ 			goto m2runtime_loop_1;
/*2062*/ 		}
/*2063*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*2063*/ 	Scanner_Expect(17, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected ';'");
/*2064*/ 	Scanner_ReadSym();
/*2066*/ 	if( (Scanner_sym == 183) ){
/*2067*/ 		if( Statements_pdb != NULL ){
/*2068*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing PhpDoc and DOC documenting style");
/*2069*/ 			Statements_pdb = NULL;
/*2071*/ 		}
/*2071*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 368) = Scanner_s;
/*2072*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 369) = Documentator_ExtractDeprecated(Scanner_s);
/*2073*/ 		Scanner_ReadSym();
/*2074*/ 	} else if( Statements_pdb != NULL ){
/*2075*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 370) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 371);
/*2076*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_p, 6 * sizeof(void*) + 6 * sizeof(int), 6, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 372) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 373));
/*2077*/ 		Statements_pdb = NULL;
/*2081*/ 	}
/*2084*/ }

/*2090*/ ARRAY * Statements_specialMethods = NULL;

/*2091*/ void
/*2091*/ Statements_CheckSpecialMethodSignature(RECORD *Statements_m)
/*2091*/ {
/*2091*/ 	int Statements_i = 0;
/*2093*/ 	STRING * Statements_sign = NULL;
/*2093*/ 	if( (((m2runtime_length((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 374)) <= 2)) || (m2runtime_strcmp(m2runtime_substr((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 375), 0, 2, 1, Statements_0err_entry_get, 376), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"__") != 0)) ){
/*2095*/ 		return ;
/*2097*/ 	}
/*2097*/ 	if( Statements_specialMethods == NULL ){
/*2098*/ 		Statements_specialMethods = (
/*2101*/ 			push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*2101*/ 			push((char*) (
/*2101*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2101*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__destruct"),
/*2101*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2101*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__destruct"),
/*2101*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2101*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"public void()"),
/*2101*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2101*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2101*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/*2102*/ 				(RECORD*) pop()
/*2102*/ 			)),
/*2102*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/*2104*/ 			push((char*) (
/*2104*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2104*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__clone"),
/*2104*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2104*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__clone"),
/*2104*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2104*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"public void()"),
/*2104*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2104*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2104*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/*2105*/ 				(RECORD*) pop()
/*2105*/ 			)),
/*2105*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),1) = (RECORD*) tos(), pop(),
/*2106*/ 			push((char*) (
/*2106*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2106*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"__set_static"),
/*2106*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2106*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"__set_static"),
/*2106*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2106*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"public static void(mixed[string])"),
/*2106*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2106*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2106*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/*2107*/ 				(RECORD*) pop()
/*2107*/ 			)),
/*2107*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),2) = (RECORD*) tos(), pop(),
/*2109*/ 			push((char*) (
/*2109*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2109*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__sleep"),
/*2109*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2109*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__sleep"),
/*2109*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2109*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"public string[int]()"),
/*2109*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2109*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = TRUE,
/*2109*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/*2110*/ 				(RECORD*) pop()
/*2110*/ 			)),
/*2110*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),3) = (RECORD*) tos(), pop(),
/*2110*/ 			push((char*) (
/*2110*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2110*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"__wakeup"),
/*2110*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2110*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"__wakeup"),
/*2110*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2110*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"public void()"),
/*2110*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2110*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = TRUE,
/*2110*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/*2111*/ 				(RECORD*) pop()
/*2111*/ 			)),
/*2111*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),4) = (RECORD*) tos(), pop(),
/*2112*/ 			push((char*) (
/*2112*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2112*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__toString"),
/*2112*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2112*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__tostring"),
/*2112*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2112*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"public string()"),
/*2112*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2112*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2112*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/*2113*/ 				(RECORD*) pop()
/*2113*/ 			)),
/*2113*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),5) = (RECORD*) tos(), pop(),
/*2115*/ 			push((char*) (
/*2115*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2115*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"__set"),
/*2115*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2115*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"__set"),
/*2115*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2115*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"public void(string, mixed)"),
/*2115*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2115*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2115*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/*2116*/ 				(RECORD*) pop()
/*2116*/ 			)),
/*2116*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),6) = (RECORD*) tos(), pop(),
/*2116*/ 			push((char*) (
/*2116*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2116*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"__get"),
/*2116*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2116*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"__get"),
/*2116*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2116*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"public mixed(string)"),
/*2116*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2116*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2116*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/*2117*/ 				(RECORD*) pop()
/*2117*/ 			)),
/*2117*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),7) = (RECORD*) tos(), pop(),
/*2117*/ 			push((char*) (
/*2117*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2117*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__isset"),
/*2117*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2117*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__isset"),
/*2117*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2117*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"public boolean(string)"),
/*2117*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2117*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2117*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/*2118*/ 				(RECORD*) pop()
/*2118*/ 			)),
/*2118*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),8) = (RECORD*) tos(), pop(),
/*2118*/ 			push((char*) (
/*2118*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2118*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__unset"),
/*2118*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2118*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__unset"),
/*2118*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2118*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"public void(string)"),
/*2118*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2118*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2118*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/*2119*/ 				(RECORD*) pop()
/*2119*/ 			)),
/*2119*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),9) = (RECORD*) tos(), pop(),
/*2119*/ 			push((char*) (
/*2119*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2119*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"__call"),
/*2119*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2119*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"__call"),
/*2119*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2119*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"public mixed(string, mixed[])"),
/*2119*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2119*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2119*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/*2120*/ 				(RECORD*) pop()
/*2120*/ 			)),
/*2120*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),10) = (RECORD*) tos(), pop(),
/*2120*/ 			push((char*) (
/*2120*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2120*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"__invoke"),
/*2120*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2120*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"__invoke"),
/*2120*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2120*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"public void(...)"),
/*2120*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2120*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2120*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = FALSE,
/*2121*/ 				(RECORD*) pop()
/*2121*/ 			)),
/*2121*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),11) = (RECORD*) tos(), pop(),
/*2121*/ 			push((char*) (
/*2121*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2121*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"__callStatic"),
/*2121*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2121*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"__callstatic"),
/*2121*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2121*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"public static mixed(string, mixed[])"),
/*2121*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2121*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2121*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/*2122*/ 				(RECORD*) pop()
/*2122*/ 			)),
/*2122*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),12) = (RECORD*) tos(), pop(),
/*2122*/ 			push((char*) (
/*2122*/ 				push((char*) alloc_RECORD(3 * sizeof(void*) + 4 * sizeof(int), 3)),
/*2122*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"__set_state"),
/*2122*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2122*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"__set_state"),
/*2122*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2122*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"public object(mixed[string])"),
/*2122*/ 				*(STRING**) (tosn(1)+2 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*2122*/ 				*(int*) (tos()+3 * sizeof(void*) + 2 * sizeof(int)) = FALSE,
/*2122*/ 				*(int*) (tos()+3 * sizeof(void*) + 3 * sizeof(int)) = TRUE,
/*2125*/ 				(RECORD*) pop()
/*2125*/ 			)),
/*2125*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),13) = (RECORD*) tos(), pop(),
/*2126*/ 			(ARRAY*) pop()
/*2126*/ 		);
/*2128*/ 	}
/*2128*/ 	Statements_i = (m2runtime_count(Statements_specialMethods) - 1);
/*2130*/ 	do{
/*2130*/ 		if( (Statements_i < 0) ){
/*2133*/ 			goto m2runtime_loop_1;
/*2133*/ 		}
/*2133*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 377), (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 378), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 379)) == 0 ){
/*2134*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 380), (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 381), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 382)) != 0 ){
/*2135*/ 				Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"the special method `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 383), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"' should be written as `", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 384), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 385), m2runtime_CHR(39), (STRING *) 1));
/*2139*/ 			}
/*2140*/ 			goto m2runtime_loop_1;
/*2140*/ 		}
/*2140*/ 		m2_inc(&Statements_i, -1);
/*2143*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*2143*/ 	if( (Statements_i < 0) ){
/*2144*/ 		if( (((m2runtime_length((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 386)) >= 2)) && (m2runtime_strcmp(m2runtime_substr((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 387), 0, 2, 1, Statements_0err_entry_get, 388), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"__") == 0)) ){
/*2145*/ 			Scanner_Warning2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 389), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"unknown special method `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 390), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\122,\0,\0,\0)"'. Methods whose name begins with `__' are reserved for future use by the language", (STRING *) 1));
/*2149*/ 		}
/*2149*/ 		return ;
/*2153*/ 	}
/*2153*/ 	if( (((Globals_php_ver == 4)) && ! *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 391), 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 392)) ){
/*2154*/ 		Scanner_Warning2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 393), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"the name `", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 394), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 395), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\107,\0,\0,\0)"' is reserved for a special method in PHP5, use another name under PHP4", (STRING *) 1));
/*2156*/ 		return ;
/*2156*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 396), 3 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 397) ){
/*2157*/ 		Scanner_Warning2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 398), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"special method `", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 399), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 400), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"' not supported by PHPLint", (STRING *) 1));
/*2162*/ 	}
/*2162*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_m, 9 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 401) ){
/*2164*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 402) = FALSE;
/*2165*/ 		Statements_sign = Types_MethodSignatureToString(Statements_m);
/*2166*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 403) = TRUE;
/*2168*/ 	} else {
/*2168*/ 		Statements_sign = Types_MethodSignatureToString(Statements_m);
/*2171*/ 	}
/*2171*/ 	if( m2runtime_strcmp(Statements_sign, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 404), 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 405)) != 0 ){
/*2172*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 406), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"special method `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 407), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"': invalid signature `", Statements_sign, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"', expected `", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_specialMethods, Statements_i, Statements_0err_entry_get, 408), 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 409), m2runtime_CHR(39), (STRING *) 1));
/*2177*/ 	}
/*2179*/ }


/*2181*/ int
/*2181*/ Statements_SameMethodSignature(RECORD *Statements_m1, RECORD *Statements_m2)
/*2181*/ {
/*2181*/ 	return (m2runtime_eq( *(int *)m2runtime_dereference_rhs_RECORD(Statements_m1, 9 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 410),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_m2, 9 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 411)) && m2runtime_eq( *(int *)m2runtime_dereference_rhs_RECORD(Statements_m1, 9 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 412),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_m2, 9 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 413)) && (( *(int *)m2runtime_dereference_rhs_RECORD(Statements_m1, 9 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 414) ==  *(int *)m2runtime_dereference_rhs_RECORD(Statements_m2, 9 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 415))) && Statements_SameSign((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m1, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 416), (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m2, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 417)));
/*2188*/ }


/*2191*/ void
/*2191*/ Statements_ParseClassMethodDecl(int Statements_abstract, int Statements_visibility, int Statements_static, int Statements_final, RECORD *Statements_t)
/*2191*/ {
/*2192*/ 	RECORD * Statements_m = NULL;
/*2193*/ 	RECORD * Statements_old_m = NULL;
/*2194*/ 	int Statements_old_m_index = 0;
/*2195*/ 	RECORD * Statements_sign = NULL;
/*2196*/ 	RECORD * Statements_this = NULL;
/*2197*/ 	int Statements_guess = 0;
/*2198*/ 	int Statements_is_destructor = 0;
/*2198*/ 	int Statements_is_constructor = 0;
/*2199*/ 	STRING * Statements_err = NULL;
/*2201*/ 	int Statements_res = 0;

/*2207*/ 	RECORD *
/*2207*/ 	Statements_ParentConstructor(RECORD *Statements_c)
/*2207*/ 	{
/*2207*/ 		Statements_c = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 418);
/*2208*/ 		while( ((Statements_c != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 419) == NULL)) ){
/*2209*/ 			Statements_c = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 420);
/*2211*/ 		}
/*2211*/ 		return Statements_c;
/*2214*/ 	}


/*2220*/ 	RECORD *
/*2220*/ 	Statements_ParentDestructor(RECORD *Statements_c)
/*2220*/ 	{
/*2220*/ 		Statements_c = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 421);
/*2221*/ 		while( ((Statements_c != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 11 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 422) == NULL)) ){
/*2222*/ 			Statements_c = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 423);
/*2224*/ 		}
/*2224*/ 		return Statements_c;
/*2228*/ 	}

/*2235*/ 	if( ((Statements_pdb != NULL) && ((Globals_php_ver == 4))) ){
/*2236*/ 		Statements_DocBlockCheckAllowedLineTags((((((((4 | 8) | 16) | 32) | 64) | 128) | 256) | 512), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"method");
/*2240*/ 	} else if( ((Statements_pdb != NULL) && ((Globals_php_ver == 5))) ){
/*2241*/ 		Statements_DocBlockCheckAllowedLineTags(((4 | 8) | 2048), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"method");
/*2249*/ 	}
/*2249*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 15 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 424) ){
/*2250*/ 		Statements_abstract = TRUE;
/*2251*/ 		if( (Statements_visibility != 2) ){
/*2252*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"interface methods must be `public'");
/*2253*/ 			Statements_visibility = 2;
/*2255*/ 		}
/*2255*/ 		if( Statements_final ){
/*2256*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"interface methods cannot be `final'");
/*2257*/ 			Statements_final = FALSE;
/*2260*/ 		}
/*2260*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 425) ){
/*2261*/ 		if( Statements_abstract ){
/*2262*/ 			if( (Statements_visibility == 0) ){
/*2263*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"abstract methods cannot be `private'");
/*2264*/ 				Statements_visibility = 1;
/*2266*/ 			}
/*2266*/ 			if( Statements_static ){
/*2267*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"abstract methods cannot be static");
/*2268*/ 				Statements_static = FALSE;
/*2270*/ 			}
/*2270*/ 			if( Statements_final ){
/*2271*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"abstract methods cannot be `final'");
/*2272*/ 				Statements_final = FALSE;
/*2275*/ 			}
/*2275*/ 		} else {
/*2275*/ 			if( (Statements_final && ((Statements_visibility == 0))) ){
/*2276*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"a private method is implicitly `final'");
/*2277*/ 				Statements_final = FALSE;
/*2280*/ 			}
/*2281*/ 		}
/*2282*/ 	} else {
/*2282*/ 		if( Statements_abstract ){
/*2283*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"abstract method in non-abstract class");
/*2284*/ 			Statements_abstract = FALSE;
/*2286*/ 		}
/*2286*/ 		if( (Statements_final && ((Statements_visibility == 0))) ){
/*2287*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"a private method is implicitly `final'");
/*2288*/ 			Statements_final = FALSE;
/*2292*/ 		}
/*2296*/ 	}
/*2296*/ 	if( ((Statements_t == NULL) && (Statements_pdb != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 426) == NULL)) ){
/*2297*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"missing `@return TYPE' declaration in DocBlock above");
/*2299*/ 	}
/*2299*/ 	if( Statements_t == NULL ){
/*2300*/ 		Statements_guess = TRUE;
/*2302*/ 	}
/*2302*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 427) = Statements_t;
/*2304*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 428) = Statements_abstract;
/*2305*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 429) = Statements_visibility;
/*2306*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 430) = Statements_static;
/*2307*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 431) = Statements_final;
/*2309*/ 	Scanner_ReadSym();
/*2314*/ 	if( (Scanner_sym == 73) ){
/*2315*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 432) = TRUE;
/*2316*/ 		if( (Globals_php_ver == 5) ){
/*2317*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"obsolete syntax `function &func()', don't use in PHP 5");
/*2319*/ 		}
/*2319*/ 		Scanner_ReadSym();
/*2325*/ 	}
/*2325*/ 	Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"expected method name");
/*2333*/ 	Statements_old_m = Search_SearchClassMethod(Globals_curr_class, Scanner_s, FALSE);
/*2334*/ 	if( ((Statements_old_m != NULL) && ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 433) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 434) != NULL)) ){
/*2335*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"method `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"()' already defined in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 435)), (STRING *) 1));
/*2338*/ 	}
/*2338*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 436) = Scanner_s;
/*2339*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 437) = str_tolower(Scanner_s);
/*2341*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 438) = Scanner_here();
/*2342*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 439) = Statements_sign;
/*2347*/ 	if( (Globals_php_ver == 4) ){
/*2349*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 440), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"__construct") == 0 ){
/*2350*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 441), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"': this name is reserved for PHP 5 constructors", (STRING *) 1));
/*2351*/ 		} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 442), (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 443)) == 0 ){
/*2352*/ 			Statements_is_constructor = TRUE;
/*2355*/ 		}
/*2357*/ 	} else {
/*2357*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 444), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"__construct") == 0 ){
/*2358*/ 			Statements_is_constructor = TRUE;
/*2360*/ 		} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 445), (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 446)) == 0 ){
/*2361*/ 			Statements_is_constructor = TRUE;
/*2362*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"the constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 447), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"' has the same name of the class. PHP 5 states", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)" it should be called `__construct()'", (STRING *) 1));
/*2366*/ 		} else if( (Namespace_inNamespace() && str_ends_with((STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 448), m2runtime_concat_STRING(0, m2runtime_CHR(92), (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 449), (STRING *) 1))) ){
/*2368*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"the method `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 450), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\212,\0,\0,\0)"' has the same name of the class inside a namespace: if it is intended to be a constructor, call it `__construct()' instead (PHP >= 5.3.3)", (STRING *) 1));
/*2373*/ 		}
/*2384*/ 	}
/*2384*/ 	if( (Statements_is_constructor && (Statements_old_m == NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 10 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 451) != NULL)) ){
/*2386*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\136,\0,\0,\0)"the default or inherited constructor for this class was already invoked before declaration in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 10 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 452)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\225,\0,\0,\0)". Hint: change the order of the declarations or declare a `forward' class or `forward' constructor, ensuring that everything be defined before usage.", (STRING *) 1));
/*2392*/ 	}
/*2392*/ 	Statements_is_destructor = (((Globals_php_ver == 5)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 453), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__destruct") == 0));
/*2394*/ 	if( (!Accounting_report_unused || Statements_is_constructor || Statements_is_destructor || Statements_abstract) ){
/*2395*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 454) = 100;
/*2398*/ 	}
/*2398*/ 	Globals_curr_method = Statements_m;
/*2399*/ 	m2_inc(&Globals_scope, 1);
/*2400*/ 	Scanner_ReadSym();
/*2406*/ 	Accounting_AccountVarLHS(m2runtime_CHR(42), FALSE);
/*2407*/ 	Statements_this = Search_SearchVar(m2runtime_CHR(42));
/*2408*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_this, 7 * sizeof(void*) + 7 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 455) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"this";
/*2409*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_this, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 456) = (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 457);
/*2414*/ 	Statements_ParseArgsListDecl(Statements_sign);
/*2416*/ 	if( !Statements_is_constructor ){
/*2423*/ 		if( !Statements_guess ){
/*2424*/ 			Statements_CheckSpecialMethodSignature(Statements_m);
/*2428*/ 		}
/*2434*/ 	} else {
/*2434*/ 		if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_m, 9 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 458) ){
/*2435*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 459), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"': a constructor cannot be `static'", (STRING *) 1));
/*2437*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 9 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 460) = FALSE;
/*2439*/ 		}
/*2439*/ 		if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 461) != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 462) != Globals_void_type)) ){
/*2440*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 463), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"': a constructor cannot", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)" return a value. It must be declared `void'.", (STRING *) 1));
/*2443*/ 		}
/*2443*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 464) = Globals_void_type;
/*2450*/ 	}
/*2450*/ 	if( Statements_pdb != NULL ){
/*2451*/ 		Exceptions_AddExceptions((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 465));
/*2458*/ 	}
/*2458*/ 	if( Statements_pdb != NULL ){
/*2459*/ 		*(ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 466) = (ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 467);
/*2465*/ 	}
/*2465*/ 	if( (Scanner_sym == 178) ){
/*2466*/ 		Exceptions_ParseThrows();
/*2469*/ 	}
/*2469*/ 	if( ((Statements_old_m != NULL) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 468)) ){
/*2473*/ 		Statements_err = Classes_ClassesList(Classes_Sort(Classes_OrphanClasses(Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 469)), Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_m, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 470)))));
/*2481*/ 		if( m2runtime_strcmp(Statements_err, NULL) > 0 ){
/*2482*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 471), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"method `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 472), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\112,\0,\0,\0)"()' throws more exceptions than those listed in the prototype declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 473)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", Statements_err, (STRING *) 1));
/*2486*/ 		}
/*2486*/ 	} else if( ((Statements_old_m != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 474) != NULL)) ){
/*2490*/ 		if( Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_m, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 475)) != NULL ){
/*2491*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 476), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"method `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 477), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"()' already guessed in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 478)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)" cannot throw unexpected exception(s): ", Classes_ClassesList(Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_m, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 479))), (STRING *) 1));
/*2497*/ 		}
/*2498*/ 	}
/*2498*/ 	if( (Scanner_sym == 183) ){
/*2499*/ 		if( Statements_pdb != NULL ){
/*2500*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing PhpDoc and DOC documenting style");
/*2501*/ 			Statements_pdb = NULL;
/*2503*/ 		}
/*2503*/ 		if( (((Globals_php_ver == 5)) && Statements_abstract) ){
/*2504*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)"the DOC description for abstract methods must follow `;'");
/*2506*/ 		}
/*2506*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 480) = Scanner_s;
/*2507*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 481) = Documentator_ExtractDeprecated(Scanner_s);
/*2508*/ 		Scanner_ReadSym();
/*2509*/ 	} else if( Statements_pdb != NULL ){
/*2510*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 482) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 483);
/*2511*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 484) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 485));
/*2517*/ 	}
/*2517*/ 	if( Statements_old_m == NULL ){
/*2519*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 486), sizeof(void *), 1, Statements_0err_entry_get, 487) = Statements_m;
/*2522*/ 	} else {
/*2522*/ 		Statements_old_m_index = 0;
/*2523*/ 		while( (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 488), Statements_old_m_index, Statements_0err_entry_get, 489) != Statements_old_m ){
/*2524*/ 			m2_inc(&Statements_old_m_index, 1);
/*2526*/ 		}
/*2526*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY((ARRAY **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 490), sizeof(void *), 1, Statements_old_m_index, Statements_0err_entry_get, 491) = Statements_m;
/*2528*/ 	}
/*2528*/ 	if( Statements_is_constructor ){
/*2529*/ 		if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 492) == NULL) || ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 493), 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 494))) ){
/*2530*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 495) = Statements_m;
/*2532*/ 		} else {
/*2532*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"constructor `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 496), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"': constructor already declared as `", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 497), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 498), m2runtime_CHR(39), (STRING *) 1));
/*2537*/ 		}
/*2537*/ 	}
/*2537*/ 	if( Statements_is_destructor ){
/*2538*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Globals_curr_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 11 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 499) = Statements_m;
/*2545*/ 	}
/*2545*/ 	if( (Scanner_sym == 17) ){
/*2547*/ 		if( (Globals_php_ver == 4) ){
/*2548*/ 			if( Statements_abstract ){
/*2549*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"expected empty body `{}' for abstract method");
/*2551*/ 			} else {
/*2551*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"expected method body");
/*2554*/ 			}
/*2554*/ 		} else {
/*2554*/ 			if( !Statements_abstract ){
/*2555*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"missing method body in non abstract method");
/*2558*/ 			}
/*2559*/ 		}
/*2559*/ 		Scanner_ReadSym();
/*2561*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_this, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 500) = 100;
/*2563*/ 		if( (Scanner_sym == 183) ){
/*2564*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 501) = Scanner_s;
/*2565*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 502) = Documentator_ExtractDeprecated(Scanner_s);
/*2566*/ 			Scanner_ReadSym();
/*2567*/ 		} else if( Statements_pdb != NULL ){
/*2568*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_m, 9 * sizeof(void*) + 10 * sizeof(int), 9, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 503) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 504);
/*2571*/ 		}
/*2571*/ 		Statements_pdb = NULL;
/*2573*/ 	} else if( (Scanner_sym == 10) ){
/*2575*/ 		Statements_pdb = NULL;
/*2577*/ 		if( (Globals_php_ver == 4) ){
/*2578*/ 			if( Statements_abstract ){
/*2579*/ 				Scanner_ReadSym();
/*2580*/ 				Scanner_Expect(11, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"expected `}'. The body of an abstract method must be empty.");
/*2581*/ 				Scanner_ReadSym();
/*2582*/ 				if( !Statements_static ){
/*2583*/ 					*(int *)m2runtime_dereference_lhs_RECORD(&Statements_this, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 505) = 100;
/*2586*/ 				}
/*2586*/ 			} else {
/*2586*/ 				Statements_res = Statements_ParseBlock();
/*2590*/ 			}
/*2590*/ 		} else {
/*2590*/ 			if( Statements_abstract ){
/*2591*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"expected `;'. Abstract method cannot contain a body.");
/*2593*/ 			}
/*2593*/ 			Statements_res = Statements_ParseBlock();
/*2600*/ 		}
/*2600*/ 		if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 506) != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 507) != Globals_void_type) && ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_m, 9 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 508) && (((Statements_res & 1) != 0)) && ! *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 509)) ){
/*2607*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 510), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\103,\0,\0,\0)"missing `return' in at least one execution path in non-void method ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 511), (STRING *) 1));
/*2613*/ 		}
/*2613*/ 		if( (Statements_is_constructor && (Statements_ParentConstructor(Globals_curr_class) != NULL) && ! *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 15 * sizeof(void*) + 8 * sizeof(int), Statements_0err_entry_get, 512)) ){
/*2617*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 513), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\102,\0,\0,\0)"missing call to the parent constructor in overridding constructor ", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 514), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 515), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1));
/*2623*/ 		}
/*2623*/ 		if( (Statements_is_destructor && (Statements_ParentDestructor(Globals_curr_class) != NULL) && ! *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 15 * sizeof(void*) + 9 * sizeof(int), Statements_0err_entry_get, 516)) ){
/*2627*/ 			Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 517), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\100,\0,\0,\0)"missing call to the parent destructor in overridding destructor ", (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 518), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 519), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1));
/*2631*/ 		}
/*2631*/ 	} else {
/*2631*/ 		Scanner_UnexpectedSymbol();
/*2635*/ 	}
/*2635*/ 	Statements_pdb = NULL;
/*2637*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_sign, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 520) == NULL ){
/*2639*/ 		Statements_guess = TRUE;
/*2640*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_sign, 2 * sizeof(void*) + 5 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 521) = Globals_void_type;
/*2647*/ 	}
/*2647*/ 	if( (Statements_guess && !Statements_is_constructor) ){
/*2648*/ 		Statements_CheckSpecialMethodSignature(Statements_m);
/*2675*/ 	}
/*2675*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_this, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 522) = 100;
/*2677*/ 	if( Statements_guess ){
/*2678*/ 		Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 523), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"guessed signature of the method ", Scanner_mn(Globals_curr_class, Statements_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)" as ", Types_MethodSignatureToString(Statements_m), (STRING *) 1));
/*2682*/ 	}
/*2682*/ 	Classes_CheckOverriddenMethod(Globals_curr_class, Statements_m);
/*2684*/ 	if( ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_m, 9 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 524) ){
/*2685*/ 		Statements_CheckFormalArgsByReference(FALSE);
/*2688*/ 	}
/*2688*/ 	Expressions_CleanCurrentScope();
/*2689*/ 	m2_inc(&Globals_scope, -1);
/*2690*/ 	Globals_curr_method = NULL;
/*2692*/ 	if( Statements_old_m != NULL ){
/*2693*/ 		if( !Statements_SameMethodSignature(Statements_m, Statements_old_m) ){
/*2694*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 525) ){
/*2695*/ 				Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 526), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"method ", Scanner_mn(Globals_curr_class, Statements_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" with signature `", Types_MethodSignatureToString(Statements_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"' does not match forward signature `", Types_MethodSignatureToString(Statements_old_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"' as declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 527)), (STRING *) 1));
/*2702*/ 			} else {
/*2702*/ 				Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 528), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"method ", Scanner_mn(Globals_curr_class, Statements_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" with signature `", Types_MethodSignatureToString(Statements_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"' does not match the signature `", Types_MethodSignatureToString(Statements_old_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"' as guessed in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_old_m, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 529)), (STRING *) 1));
/*2710*/ 			}
/*2711*/ 		}
/*2712*/ 	}
/*2714*/ }


/*2716*/ void
/*2716*/ Statements_ParseClass(int Statements_private_class)
/*2716*/ {

/*2728*/ 	void
/*2728*/ 	Statements_CheckForwardAttribute(RECORD *Statements_c, int Statements_a_attribute, int Statements_b_attribute, STRING *Statements_attribute)
/*2728*/ 	{
/*2728*/ 		if( ((Statements_a_attribute && Statements_b_attribute) || (!Statements_a_attribute && !Statements_b_attribute)) ){
/*2731*/ 			return ;
/*2732*/ 		}
/*2732*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_c, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 530), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)": attribute `", Statements_attribute, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"' does not match the forward declaration in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 531)), (STRING *) 1));
/*2738*/ 	}

/*2739*/ 	RECORD * Statements_if = NULL;
/*2739*/ 	RECORD * Statements_parent = NULL;
/*2739*/ 	RECORD * Statements_forward = NULL;
/*2739*/ 	RECORD * Statements_colliding = NULL;
/*2739*/ 	RECORD * Statements_class = NULL;
/*2740*/ 	STRING * Statements_class_name_lower = NULL;
/*2740*/ 	STRING * Statements_class_name = NULL;
/*2741*/ 	RECORD * Statements_t = NULL;
/*2742*/ 	ARRAY * Statements_surrogates = NULL;
/*2745*/ 	ARRAY * Statements_should_implement = NULL;
/*2745*/ 	int Statements_x_visibility_set = 0;
/*2746*/ 	int Statements_x_visibility = 0;
/*2747*/ 	int Statements_x_abstract = 0;
/*2748*/ 	int Statements_x_final = 0;
/*2749*/ 	int Statements_x_static = 0;
/*2750*/ 	int Statements_abstract = 0;
/*2750*/ 	int Statements_visibility_set = 0;
/*2751*/ 	int Statements_visibility = 0;
/*2752*/ 	int Statements_static = 0;
/*2754*/ 	int Statements_final = 0;
/*2755*/ 	int Statements_i = 0;
/*2756*/ 	RECORD * Statements_m = NULL;
/*2759*/ 	RECORD * Statements_class_decl_in = NULL;
/*2759*/ 	if( (Globals_php_ver == 4) ){
/*2760*/ 		Statements_DocBlockCheckAllowedLineTags(((64 | 16) | 128), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"class");
/*2763*/ 	} else {
/*2763*/ 		Statements_DocBlockCheckAllowedLineTags(128, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"class");
/*2766*/ 	}
/*2766*/ 	if( (Globals_scope > 0) ){
/*2767*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\171,\0,\0,\0)"class declaration inside a function. The namespace of the classes is still global so the function cannot be called twice.");
/*2770*/ 	}
/*2770*/ 	Statements_class_decl_in = Scanner_here();
/*2771*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 532) = Statements_class_decl_in;
/*2773*/ 	if( !Accounting_report_unused ){
/*2774*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 10 * sizeof(int), Statements_0err_entry_get, 533) = 100;
/*2780*/ 	}
/*2780*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 534) = (Statements_private_class || ((Statements_pdb != NULL) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 535)));
/*2781*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 536) = ((Statements_pdb != NULL) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 537));
/*2782*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 538) = ((Statements_pdb != NULL) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 539));
/*2788*/ 	do{
/*2788*/ 		if( (Scanner_sym == 173) ){
/*2789*/ 			if( (Globals_php_ver == 5) ){
/*2790*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"invalid attribute `/*.abstract.*/', use `abstract' instead");
/*2792*/ 			}
/*2792*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 540) ){
/*2793*/ 				Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"`abstract' attribute already set");
/*2795*/ 			}
/*2795*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 541) = TRUE;
/*2796*/ 			Scanner_ReadSym();
/*2798*/ 		} else if( (Scanner_sym == 175) ){
/*2799*/ 			if( (Globals_php_ver == 5) ){
/*2800*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"invalid attribute `/*.final.*/', use `final' instead");
/*2802*/ 			}
/*2802*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 542) ){
/*2803*/ 				Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"`final' attribute already set");
/*2805*/ 			}
/*2805*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 543) = TRUE;
/*2806*/ 			Scanner_ReadSym();
/*2808*/ 		} else if( (Scanner_sym == 91) ){
/*2809*/ 			if( (Globals_php_ver == 4) ){
/*2810*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"invalid attribute `abstract', use `/*.abstract.*/' instead");
/*2812*/ 			}
/*2812*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 544) ){
/*2813*/ 				Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"`abstract' attribute already set");
/*2815*/ 			}
/*2815*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 545) = TRUE;
/*2816*/ 			Scanner_ReadSym();
/*2818*/ 		} else if( (Scanner_sym == 102) ){
/*2819*/ 			if( (Globals_php_ver == 4) ){
/*2820*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"invalid attribute `final', use `/*.final.*/' instead");
/*2822*/ 			}
/*2822*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 546) ){
/*2823*/ 				Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"`final' attribute already set");
/*2825*/ 			}
/*2825*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 547) = TRUE;
/*2826*/ 			Scanner_ReadSym();
/*2828*/ 		} else if( (Scanner_sym == 143) ){
/*2829*/ 			if( (Globals_php_ver == 4) ){
/*2830*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"invalid attribute `unchecked' (PHP 5)");
/*2832*/ 			}
/*2832*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 548) ){
/*2833*/ 				Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"`unchecked' attribute already set");
/*2835*/ 			}
/*2835*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 549) = TRUE;
/*2836*/ 			Scanner_ReadSym();
/*2840*/ 		} else {
/*2842*/ 			goto m2runtime_loop_1;
/*2843*/ 		}
/*2844*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*2844*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 550) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 551)) ){
/*2845*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"a class cannot be both final and abstract");
/*2848*/ 	}
/*2848*/ 	Scanner_Expect(93, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"expected `class'");
/*2849*/ 	Scanner_ReadSym();
/*2854*/ 	Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"expected class name");
/*2855*/ 	Scanner_s = Namespace_CheckBareID(Scanner_s);
/*2856*/ 	Statements_class_name = Namespace_Absolute(Scanner_s);
/*2857*/ 	Statements_class_name_lower = str_tolower(Statements_class_name);
/*2866*/ 	Statements_colliding = Search_SearchClassByAbsName(Namespace_ApplyUse(Scanner_s, TRUE), FALSE);
/*2867*/ 	if( ((Statements_colliding != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_colliding, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 552), Statements_class_name_lower) != 0)) ){
/*2868*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"cannot declare ", Statements_class_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)" because the name is already accessible as ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_colliding, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 553), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_colliding, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 554)), (STRING *) 1));
/*2877*/ 	}
/*2877*/ 	Statements_forward = Search_SearchClassByAbsName(Statements_class_name, FALSE);
/*2878*/ 	if( Statements_forward == NULL ){
/*2879*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 555) = Statements_class_name;
/*2880*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 556) = Statements_class_name_lower;
/*2881*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 557) = (
/*2881*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*2881*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 9,
/*2881*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*2881*/ 			push((char*) NULL),
/*2881*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2881*/ 			push((char*) Statements_class),
/*2882*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*2882*/ 			(RECORD*) pop()
/*2882*/ 		);
/*2882*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_classes, sizeof(void *), 1, Statements_0err_entry_get, 558) = Statements_class;
/*2884*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_forward, 15 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 559) ){
/*2885*/ 		Statements_CheckForwardAttribute(Statements_forward,  *(int *)m2runtime_dereference_rhs_RECORD(Statements_forward, 15 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 560),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 561), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"private");
/*2886*/ 		Statements_CheckForwardAttribute(Statements_forward,  *(int *)m2runtime_dereference_rhs_RECORD(Statements_forward, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 562),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 563), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"abstract");
/*2887*/ 		Statements_CheckForwardAttribute(Statements_forward,  *(int *)m2runtime_dereference_rhs_RECORD(Statements_forward, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 564),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 565), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"final");
/*2888*/ 		Statements_CheckForwardAttribute(Statements_forward,  *(int *)m2runtime_dereference_rhs_RECORD(Statements_forward, 15 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 566),  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 567), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"unchecked");
/*2891*/ 		Statements_should_implement = (ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_forward, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 568);
/*2892*/ 		*(ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_forward, 15 * sizeof(void*) + 11 * sizeof(int), 15, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 569) = NULL;
/*2893*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_forward, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 10 * sizeof(int), Statements_0err_entry_get, 570) =  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 10 * sizeof(int), Statements_0err_entry_get, 571);
/*2894*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_forward, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 572) = FALSE;
/*2895*/ 		Statements_class = Statements_forward;
/*2898*/ 	} else {
/*2898*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Statements_class_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_forward, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 573)), (STRING *) 1));
/*2902*/ 	}
/*2902*/ 	Globals_curr_class = Statements_class;
/*2905*/ 	if( (((Globals_php_ver == 5)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 574), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"Exception") == 0)) ){
/*2906*/ 		Classes_ExceptionClass = Statements_class;
/*2909*/ 	}
/*2909*/ 	Scanner_ReadSym();
/*2914*/ 	if( (Scanner_sym == 181) ){
/*2915*/ 		Statements_surrogates = Template_ParseClassDeclTemplate();
/*2921*/ 	}
/*2921*/ 	if( (Scanner_sym == 94) ){
/*2922*/ 		Scanner_ReadSym();
/*2923*/ 		Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"expected parent class name after `extends'");
/*2924*/ 		Statements_parent = Search_SearchClass(Scanner_s);
/*2925*/ 		if( Statements_parent == NULL ){
/*2926*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"undeclared parent class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*2927*/ 		} else if( Classes_IsSubclassOf(Statements_parent, Statements_class) ){
/*2928*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 575), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" cannot extend child class ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_parent, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 576), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)": forbidden circular reference", (STRING *) 1));
/*2930*/ 		} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_parent, 15 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 577) ){
/*2931*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"can't extend final class `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_parent, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 578), m2runtime_CHR(39), (STRING *) 1));
/*2932*/ 		} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_parent, 15 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 579) ){
/*2933*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"can't extend interface class `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_parent, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 580), m2runtime_CHR(39), (STRING *) 1));
/*2935*/ 		} else {
/*2935*/ 			if( ((Statements_forward != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_forward, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 581) != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_forward, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 582) != Statements_parent)) ){
/*2939*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 583), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)": actual implementation must extend ", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_class, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 584), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 585), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)" according to the forward declaration", (STRING *) 1));
/*2943*/ 			}
/*2943*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 586) = Statements_parent;
/*2944*/ 			Accounting_AccountClass(Statements_parent);
/*2945*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_parent, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 587), EMPTY_STRING) > 0 ){
/*2946*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"extending deprecated class `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_parent, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 588), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_parent, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 589), (STRING *) 1));
/*2951*/ 			}
/*2951*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 590) ){
/*2952*/ 				if( Statements_parent == NULL ){
/*2953*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"unchecked attribute allowed only if class extends exception");
/*2955*/ 				} else if( !Classes_IsExceptionClass(Statements_parent) ){
/*2956*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"invalid `unchecked' attribute for non-exception class ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_parent, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 591), (STRING *) 1));
/*2960*/ 				}
/*2960*/ 			} else if( (Classes_IsSubclassOf(Statements_parent, Classes_ExceptionClass) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_parent, 15 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 592)) ){
/*2962*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"missing `unchecked' attribute extending unchecked exception ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_parent, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 593), (STRING *) 1));
/*2966*/ 			}
/*2966*/ 		}
/*2966*/ 		Scanner_ReadSym();
/*2969*/ 	} else {
/*2969*/ 		if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 594) ){
/*2970*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\61,\0,\0,\0)"cannot use `unchecked' attribute on non-exception");
/*2973*/ 		}
/*2977*/ 	}
/*2977*/ 	if( (Scanner_sym == 95) ){
/*2978*/ 		Scanner_ReadSym();
/*2980*/ 		do{
/*2980*/ 			Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected interface name");
/*2981*/ 			Statements_if = Search_SearchClass(Scanner_s);
/*2982*/ 			if( Statements_if == NULL ){
/*2983*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"undeclared interface class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*2984*/ 			} else if( ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_if, 15 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 595) ){
/*2985*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"' isn't an interface", (STRING *) 1));
/*2986*/ 			} else if( (((Globals_php_ver == 5)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 596), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"Traversable") == 0) && ! *(int *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 597)) ){
/*2987*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\137,\0,\0,\0)"can't implement abstract interface `Traversable', use `Iterator' or `IteratorAggregate' instead");
/*2988*/ 			} else if( Classes_IsSubclassOf(Statements_class, Statements_if) ){
/*2989*/ 				Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 598), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)" redundantly extends interface ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 599), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" -- ignoring", (STRING *) 1));
/*2993*/ 			} else {
/*2993*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 600), sizeof(void *), 1, Statements_0err_entry_get, 601) = Statements_if;
/*2996*/ 				Accounting_AccountClass(Statements_if);
/*2997*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 602), EMPTY_STRING) > 0 ){
/*2998*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"implementing deprecated interface `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 603), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 604), (STRING *) 1));
/*3002*/ 				}
/*3002*/ 			}
/*3002*/ 			Scanner_ReadSym();
/*3003*/ 			if( (Scanner_sym == 16) ){
/*3004*/ 				Scanner_ReadSym();
/*3007*/ 			} else {
/*3008*/ 				goto m2runtime_loop_2;
/*3009*/ 			}
/*3010*/ 		}while(TRUE);
m2runtime_loop_2: ;
/*3010*/ 	}
/*3010*/ 	{
/*3010*/ 		int m2runtime_for_limit_1;
/*3010*/ 		Statements_i = 0;
/*3010*/ 		m2runtime_for_limit_1 = (m2runtime_count(Statements_should_implement) - 1);
/*3011*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*3011*/ 			Statements_if = (RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_should_implement, Statements_i, Statements_0err_entry_get, 605);
/*3012*/ 			if( !Classes_IsSubclassOf(Statements_class, Statements_if) ){
/*3013*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 606), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)" must implement ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 607), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)" according to the forward declaration", (STRING *) 1));
/*3017*/ 			}
/*3020*/ 		}
/*3020*/ 	}
/*3020*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 608) = Statements_class_decl_in;
/*3022*/ 	Classes_CheckCollisionsBetweenExtendedAndImplementedClasses(Statements_class);
/*3023*/ 	Classes_CheckTraversableUsage(Statements_class);
/*3025*/ 	if( (Scanner_sym == 183) ){
/*3026*/ 		if( Statements_pdb != NULL ){
/*3027*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing PhpDoc and DOC documenting style");
/*3028*/ 			Statements_pdb = NULL;
/*3030*/ 		}
/*3030*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 13 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 609) = Scanner_s;
/*3031*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 610) = Documentator_ExtractDeprecated(Scanner_s);
/*3032*/ 		Scanner_ReadSym();
/*3033*/ 	} else if( Statements_pdb != NULL ){
/*3034*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 13 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 611) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 612);
/*3035*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 613) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 614));
/*3036*/ 		Statements_pdb = NULL;
/*3039*/ 	}
/*3039*/ 	Scanner_Expect(10, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"expected '{' in class declaration");
/*3040*/ 	Scanner_ReadSym();
/*3044*/ 	do{
/*3044*/ 		if( (Scanner_sym == 11) ){
/*3045*/ 			Scanner_ReadSym();
/*3048*/ 			goto m2runtime_loop_3;
/*3050*/ 		}
/*3050*/ 		Statements_x_visibility_set = FALSE;
/*3051*/ 		Statements_x_visibility = 2;
/*3052*/ 		Statements_x_abstract = FALSE;
/*3053*/ 		Statements_x_final = FALSE;
/*3054*/ 		Statements_x_static = FALSE;
/*3057*/ 		Statements_abstract = FALSE;
/*3058*/ 		Statements_visibility_set = FALSE;
/*3059*/ 		Statements_visibility = 2;
/*3060*/ 		Statements_static = FALSE;
/*3061*/ 		Statements_final = FALSE;
/*3066*/ 		while( (Scanner_sym == 184) ){
/*3067*/ 			Statements_pdb = ParseDocBlock_ParseDocBlock(Scanner_s);
/*3068*/ 			if( Statements_pdb != NULL ){
/*3069*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 615) ){
/*3070*/ 					Statements_x_visibility = 0;
/*3071*/ 					Statements_x_visibility_set = TRUE;
/*3072*/ 				} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 616) ){
/*3073*/ 					Statements_x_visibility = 1;
/*3074*/ 					Statements_x_visibility_set = TRUE;
/*3075*/ 				} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 617) ){
/*3076*/ 					Statements_x_visibility = 2;
/*3077*/ 					Statements_x_visibility_set = TRUE;
/*3079*/ 				}
/*3079*/ 				Statements_x_abstract =  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 618);
/*3080*/ 				Statements_x_final =  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 619);
/*3081*/ 				Statements_x_static =  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 8 * sizeof(int), Statements_0err_entry_get, 620);
/*3083*/ 			}
/*3083*/ 			Scanner_ReadSym();
/*3088*/ 		}
/*3114*/ 		do{
/*3114*/ 			switch(Scanner_sym){

/*3116*/ 			case 170:
/*3117*/ 			if( Statements_x_visibility_set ){
/*3118*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"visibility attribute already set");
/*3120*/ 			}
/*3120*/ 			Statements_x_visibility_set = TRUE;
/*3121*/ 			Statements_x_visibility = 2;
/*3123*/ 			break;

/*3123*/ 			case 171:
/*3124*/ 			if( Statements_x_visibility_set ){
/*3125*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"visibility attribute already set");
/*3127*/ 			}
/*3127*/ 			Statements_x_visibility_set = TRUE;
/*3128*/ 			Statements_x_visibility = 1;
/*3130*/ 			break;

/*3130*/ 			case 172:
/*3131*/ 			if( Statements_x_visibility_set ){
/*3132*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"visibility attribute already set");
/*3134*/ 			}
/*3134*/ 			Statements_x_visibility_set = TRUE;
/*3135*/ 			Statements_x_visibility = 0;
/*3137*/ 			break;

/*3137*/ 			case 173:
/*3138*/ 			if( Statements_x_abstract ){
/*3139*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"abstract attribute already set");
/*3141*/ 			}
/*3141*/ 			Statements_x_abstract = TRUE;
/*3143*/ 			break;

/*3143*/ 			case 175:
/*3144*/ 			if( Statements_x_final ){
/*3145*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"final attribute already set");
/*3147*/ 			}
/*3147*/ 			Statements_x_final = TRUE;
/*3149*/ 			break;

/*3149*/ 			case 174:
/*3150*/ 			if( Statements_x_static ){
/*3151*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"static attribute already set");
/*3153*/ 			}
/*3153*/ 			Statements_x_static = TRUE;
/*3155*/ 			break;

/*3155*/ 			case 91:
/*3156*/ 			if( Statements_abstract ){
/*3157*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"abstract attribute already set");
/*3159*/ 			}
/*3159*/ 			Statements_abstract = TRUE;
/*3161*/ 			break;

/*3161*/ 			case 98:
/*3162*/ 			if( Statements_visibility_set ){
/*3163*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"visibility attribute already set");
/*3165*/ 			}
/*3165*/ 			Statements_visibility = 2;
/*3166*/ 			Statements_visibility_set = TRUE;
/*3168*/ 			break;

/*3168*/ 			case 100:
/*3169*/ 			if( Statements_visibility_set ){
/*3170*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"visibility attribute already set");
/*3172*/ 			}
/*3172*/ 			Statements_visibility = 1;
/*3173*/ 			Statements_visibility_set = TRUE;
/*3175*/ 			break;

/*3175*/ 			case 99:
/*3176*/ 			if( Statements_visibility_set ){
/*3177*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"visibility attribute already set");
/*3179*/ 			}
/*3179*/ 			Statements_visibility = 0;
/*3180*/ 			Statements_visibility_set = TRUE;
/*3182*/ 			break;

/*3182*/ 			case 101:
/*3183*/ 			if( Statements_static ){
/*3184*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"static attribute already set");
/*3186*/ 			}
/*3186*/ 			Statements_static = TRUE;
/*3188*/ 			break;

/*3188*/ 			case 102:
/*3189*/ 			if( Statements_final ){
/*3190*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"final attribute already set");
/*3192*/ 			}
/*3192*/ 			Statements_final = TRUE;
/*3195*/ 			break;

/*3196*/ 			default:
/*3198*/ 			goto m2runtime_loop_4;
/*3199*/ 			}
/*3199*/ 			Scanner_ReadSym();
/*3203*/ 		}while(TRUE);
m2runtime_loop_4: ;
/*3203*/ 		Statements_t = Expressions_ParseType(FALSE);
/*3204*/ 		if( Statements_t == NULL ){
/*3205*/ 			if( Statements_pdb != NULL ){
/*3206*/ 				if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 621) != NULL ){
/*3207*/ 					Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 622);
/*3208*/ 				} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 623) != NULL ){
/*3209*/ 					Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 624);
/*3212*/ 				}
/*3213*/ 			}
/*3213*/ 		} else {
/*3213*/ 			if( ((Statements_pdb != NULL) && ((((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 625) != NULL) || ((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 626) != NULL)))) ){
/*3215*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\67,\0,\0,\0)"type declaration both in DocBlock and PHPLint meta-code");
/*3218*/ 			}
/*3219*/ 		}
/*3219*/ 		if( (Scanner_sym == 136) ){
/*3220*/ 			if( Statements_pdb != NULL ){
/*3221*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"unexpected DocBlock for forward declaration");
/*3223*/ 			}
/*3223*/ 			if( Statements_t != NULL ){
/*3224*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"unexpected type for forward declaration");
/*3226*/ 			}
/*3226*/ 			if( (Statements_x_visibility_set || Statements_x_abstract || Statements_x_final || Statements_x_static || Statements_abstract || Statements_visibility_set || Statements_static || Statements_final) ){
/*3228*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"unexpected attribute for forward declaration");
/*3230*/ 			}
/*3230*/ 			Proto_ParseForwardDecl();
/*3233*/ 		} else if( (Scanner_sym == 96) ){
/*3234*/ 			if( (Globals_php_ver == 4) ){
/*3235*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"invalid `const' declaration (PHP5)");
/*3237*/ 			}
/*3237*/ 			if( Statements_t != NULL ){
/*3238*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)"explicit type declaration not allowed for class constant");
/*3240*/ 			}
/*3240*/ 			if( (Statements_x_abstract || Statements_x_final || Statements_x_static || Statements_abstract || Statements_visibility_set || Statements_static || Statements_final) ){
/*3242*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\125,\0,\0,\0)"invalid attribute. Only /*.public|protected|private.*/ is allowed for class constant.");
/*3244*/ 			}
/*3244*/ 			Statements_ParseClassConstDecl(Statements_x_visibility);
/*3247*/ 		} else if( (Scanner_sym == 97) ){
/*3248*/ 			if( (Globals_php_ver == 4) ){
/*3249*/ 				if( (Statements_x_abstract || Statements_x_final || Statements_x_static || Statements_abstract || Statements_visibility_set || Statements_static || Statements_final) ){
/*3251*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\122,\0,\0,\0)"invalid attribute. Only /*.public|protected|private.*/ are allowed for a property.");
/*3254*/ 				}
/*3254*/ 			} else {
/*3254*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"invalid attribute `var' (PHP 4), use `public'");
/*3256*/ 			}
/*3256*/ 			Scanner_ReadSym();
/*3257*/ 			if( Statements_t == NULL ){
/*3258*/ 				Statements_t = Expressions_ParseType(FALSE);
/*3260*/ 			}
/*3260*/ 			Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"expected property name $xxx");
/*3261*/ 			if( Statements_x_visibility_set ){
/*3262*/ 				Statements_visibility = Statements_x_visibility;
/*3264*/ 			}
/*3264*/ 			Statements_ParseClassPropertyDecl(Statements_visibility, (Statements_x_static || Statements_static), Statements_t);
/*3267*/ 		} else if( (Scanner_sym == 20) ){
/*3268*/ 			if( (Globals_php_ver == 4) ){
/*3269*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"missing `var' before property name");
/*3271*/ 			} else {
/*3271*/ 				if( (Statements_x_visibility_set || Statements_x_abstract || Statements_x_final || Statements_x_static) ){
/*3272*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\152,\0,\0,\0)"cannot use meta-code or DocBlock to set visibility|abstract|final attributes, use proper language keywords");
/*3273*/ 				} else if( (Statements_abstract || Statements_final) ){
/*3274*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"properties cannot be abstract nor final");
/*3275*/ 				} else if( (!Statements_visibility_set && !Statements_static) ){
/*3276*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"property requires visibility attribute or static attribute");
/*3279*/ 				}
/*3279*/ 			}
/*3279*/ 			Statements_ParseClassPropertyDecl(Statements_visibility, Statements_static, Statements_t);
/*3282*/ 		} else if( (Scanner_sym == 8) ){
/*3283*/ 			if( (Globals_php_ver == 4) ){
/*3284*/ 				if( (Statements_abstract || Statements_visibility_set || Statements_static || Statements_final) ){
/*3285*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\146,\0,\0,\0)"invalid attribute. Only /*.abstract public|protected|private final static.*/ are allowed for a method.");
/*3287*/ 				}
/*3287*/ 				if( (Statements_x_abstract && ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 627)) ){
/*3288*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"abstract method in non-abstract class");
/*3289*/ 					Statements_x_abstract = FALSE;
/*3291*/ 				}
/*3291*/ 				Statements_ParseClassMethodDecl(Statements_x_abstract, Statements_x_visibility, Statements_x_static, Statements_x_final, Statements_t);
/*3293*/ 			} else {
/*3293*/ 				if( (Statements_x_visibility_set || Statements_x_abstract || Statements_x_static || Statements_x_final) ){
/*3294*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\146,\0,\0,\0)"invalid meta-code or DocBlock visibility|abstract|static|final attribute, use proper language keywords");
/*3296*/ 				}
/*3296*/ 				if( (Statements_abstract && ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 628)) ){
/*3297*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"abstract method in non-abstract class");
/*3298*/ 					Statements_abstract = FALSE;
/*3300*/ 				}
/*3300*/ 				Statements_ParseClassMethodDecl(Statements_abstract, Statements_visibility, Statements_static, Statements_final, Statements_t);
/*3304*/ 			}
/*3304*/ 		} else {
/*3304*/ 			Scanner_UnexpectedSymbol();
/*3308*/ 		}
/*3309*/ 	}while(TRUE);
m2runtime_loop_3: ;
/*3309*/ 	if( ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 629) ){
/*3310*/ 		Classes_CheckImplementedMethods(Statements_class);
/*3313*/ 	}
/*3313*/ 	{
/*3313*/ 		int m2runtime_for_limit_1;
/*3313*/ 		Statements_i = 0;
/*3313*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_class, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 630)) - 1);
/*3314*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*3314*/ 			Statements_m = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Statements_class, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 631), Statements_i, Statements_0err_entry_get, 632);
/*3315*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_m, 9 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 633) ){
/*3316*/ 				Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"missing method `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_m, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 634), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"()' declared forward in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_m, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 635)), (STRING *) 1));
/*3320*/ 			}
/*3321*/ 		}
/*3321*/ 	}
/*3321*/ 	Template_MangleNamesOfSurrogateClasses(Statements_class, Statements_surrogates);
/*3323*/ 	Globals_curr_class = NULL;
/*3327*/ }


/*3330*/ void
/*3330*/ Statements_ParseInterface(int Statements_private_class)
/*3330*/ {
/*3331*/ 	RECORD * Statements_if = NULL;
/*3331*/ 	RECORD * Statements_forward = NULL;
/*3331*/ 	RECORD * Statements_class = NULL;
/*3332*/ 	int Statements_static = 0;
/*3334*/ 	RECORD * Statements_t = NULL;
/*3334*/ 	if( (Globals_scope > 0) ){
/*3335*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\171,\0,\0,\0)"class declaration inside a function. The namespace of the classes is still global so the function cannot be called twice.");
/*3337*/ 	}
/*3337*/ 	if( (Globals_php_ver == 4) ){
/*3338*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"invalid keyword `interface' (PHP 5)");
/*3344*/ 	}
/*3344*/ 	Statements_DocBlockCheckAllowedLineTags(128, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"interface");
/*3345*/ 	if( ((Statements_pdb != NULL) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 636)) ){
/*3346*/ 		Statements_private_class = TRUE;
/*3349*/ 	}
/*3349*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 637) = Statements_private_class;
/*3350*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 638) = Scanner_here();
/*3351*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 639) = TRUE;
/*3352*/ 	if( !Accounting_report_unused ){
/*3353*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 10 * sizeof(int), Statements_0err_entry_get, 640) = 100;
/*3359*/ 	}
/*3359*/ 	Scanner_ReadSym();
/*3360*/ 	Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"expected class name");
/*3361*/ 	Scanner_s = Namespace_CheckBareID(Scanner_s);
/*3362*/ 	Scanner_s = Namespace_Absolute(Scanner_s);
/*3363*/ 	Statements_forward = Search_SearchClassByAbsName(Scanner_s, FALSE);
/*3364*/ 	if( Statements_forward != NULL ){
/*3365*/ 		if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_forward, 15 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 641) ){
/*3366*/ 			if( (( *(int *)m2runtime_dereference_rhs_RECORD(Statements_forward, 15 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 642) && !Statements_private_class) || (! *(int *)m2runtime_dereference_rhs_RECORD(Statements_forward, 15 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 643) && Statements_private_class)) ){
/*3368*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"interface ", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\100,\0,\0,\0)": attribute `private' does not match the forward declaration in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_forward, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 644)), (STRING *) 1));
/*3371*/ 			}
/*3371*/ 			Statements_class = Statements_forward;
/*3372*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 645) = FALSE;
/*3374*/ 		} else {
/*3374*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_forward, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 646)), (STRING *) 1));
/*3378*/ 		}
/*3381*/ 	} else {
/*3381*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 647) = Scanner_s;
/*3382*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 648) = str_tolower(Scanner_s);
/*3383*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 649) = (
/*3383*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*3383*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 9,
/*3383*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*3383*/ 			push((char*) NULL),
/*3383*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*3383*/ 			push((char*) Statements_class),
/*3384*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*3384*/ 			(RECORD*) pop()
/*3384*/ 		);
/*3384*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_classes, sizeof(void *), 1, Statements_0err_entry_get, 650) = Statements_class;
/*3387*/ 	}
/*3387*/ 	Globals_curr_class = Statements_class;
/*3388*/ 	Scanner_ReadSym();
/*3393*/ 	if( (Scanner_sym == 94) ){
/*3394*/ 		Scanner_ReadSym();
/*3396*/ 		do{
/*3396*/ 			Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"expected interface class name");
/*3397*/ 			Statements_if = Search_SearchClass(Scanner_s);
/*3398*/ 			if( Statements_if == NULL ){
/*3399*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"undeclared interface class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*3400*/ 			} else if( Classes_IsSubclassOf(Statements_if, Statements_class) ){
/*3401*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"interface ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 651), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)" cannot extend interface ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 652), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)": forbidden circular reference", (STRING *) 1));
/*3403*/ 			} else if( ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_if, 15 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 653) ){
/*3404*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"interface cannot extend non-interface class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*3405*/ 			} else if( Classes_IsSubclassOf(Statements_class, Statements_if) ){
/*3406*/ 				Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"interface ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_class, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 654), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)" redundantly extends interface ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 655), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" -- ignoring", (STRING *) 1));
/*3410*/ 			} else {
/*3410*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 656), sizeof(void *), 1, Statements_0err_entry_get, 657) = Statements_if;
/*3411*/ 				Accounting_AccountClass(Statements_if);
/*3412*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 658), EMPTY_STRING) > 0 ){
/*3413*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"extending deprecated class `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 659), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_if, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 660), (STRING *) 1));
/*3417*/ 				}
/*3417*/ 			}
/*3417*/ 			Scanner_ReadSym();
/*3418*/ 			if( (Scanner_sym == 16) ){
/*3419*/ 				Scanner_ReadSym();
/*3422*/ 			} else {
/*3423*/ 				goto m2runtime_loop_1;
/*3424*/ 			}
/*3425*/ 		}while(TRUE);
m2runtime_loop_1: ;
/*3425*/ 	}
/*3425*/ 	Classes_CheckCollisionsBetweenExtendedAndImplementedClasses(Statements_class);
/*3427*/ 	if( (Scanner_sym == 183) ){
/*3428*/ 		if( Statements_pdb != NULL ){
/*3429*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"mixing PhpDoc and DOC documenting style");
/*3430*/ 			Statements_pdb = NULL;
/*3432*/ 		}
/*3432*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 13 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 661) = Scanner_s;
/*3433*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 662) = Documentator_ExtractDeprecated(Scanner_s);
/*3434*/ 		Scanner_ReadSym();
/*3435*/ 	} else if( Statements_pdb != NULL ){
/*3436*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 13 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 663) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 664);
/*3437*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_class, 15 * sizeof(void*) + 11 * sizeof(int), 15, 14 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 665) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 666));
/*3438*/ 		Statements_pdb = NULL;
/*3441*/ 	}
/*3441*/ 	Scanner_Expect(10, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"expected '{' in class declaration");
/*3442*/ 	Scanner_ReadSym();
/*3445*/ 	do{
/*3445*/ 		if( (Scanner_sym == 11) ){
/*3446*/ 			Scanner_ReadSym();
/*3449*/ 			goto m2runtime_loop_2;
/*3450*/ 		}
/*3450*/ 		Statements_static = FALSE;
/*3452*/ 		Statements_pdb = NULL;
/*3453*/ 		if( (Scanner_sym == 184) ){
/*3454*/ 			Statements_pdb = ParseDocBlock_ParseDocBlock(Scanner_s);
/*3455*/ 			if( Statements_pdb != NULL ){
/*3456*/ 				if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 667) ||  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 668) ||  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 669)) ){
/*3457*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"in DocBlock: visibility attributes not allowed in interface");
/*3459*/ 				}
/*3459*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 7 * sizeof(int), Statements_0err_entry_get, 670) ){
/*3460*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)"in DocBlock: final attribute not allowed in interface");
/*3462*/ 				}
/*3462*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 8 * sizeof(int), Statements_0err_entry_get, 671) ){
/*3463*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\127,\0,\0,\0)"in DocBlock: static attribute not allowed, use proper language keyword `static' instead");
/*3466*/ 				}
/*3466*/ 			}
/*3466*/ 			Scanner_ReadSym();
/*3469*/ 		}
/*3469*/ 		if( (Scanner_sym == 96) ){
/*3470*/ 			Statements_ParseClassConstDecl(2);
/*3477*/ 		} else {
/*3477*/ 			Statements_static = FALSE;
/*3479*/ 			do{
/*3479*/ 				if( (Scanner_sym == 98) ){
/*3480*/ 					Scanner_ReadSym();
/*3481*/ 				} else if( (((Scanner_sym == 100)) || ((Scanner_sym == 99))) ){
/*3482*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\130,\0,\0,\0)"invalid visibility attribute for interface method. Abstract methods are always `public'.");
/*3483*/ 					Scanner_ReadSym();
/*3484*/ 				} else if( (Scanner_sym == 102) ){
/*3485*/ 					Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"invalid `final' attribute for abstract method");
/*3486*/ 					Scanner_ReadSym();
/*3487*/ 				} else if( (Scanner_sym == 101) ){
/*3488*/ 					Statements_static = TRUE;
/*3489*/ 					Scanner_ReadSym();
/*3492*/ 				} else {
/*3493*/ 					goto m2runtime_loop_3;
/*3494*/ 				}
/*3498*/ 			}while(TRUE);
m2runtime_loop_3: ;
/*3498*/ 			if( Statements_pdb != NULL ){
/*3499*/ 				Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 672);
/*3501*/ 			} else {
/*3501*/ 				Statements_t = Expressions_ParseType(FALSE);
/*3504*/ 			}
/*3504*/ 			if( (Scanner_sym == 20) ){
/*3505*/ 				Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"properties cannot be defined in interfaces");
/*3508*/ 			}
/*3508*/ 			Scanner_Expect(8, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)"expected `function' declaration in interface class");
/*3509*/ 			Statements_ParseClassMethodDecl(TRUE, 2, Statements_static, FALSE, Statements_t);
/*3513*/ 		}
/*3514*/ 	}while(TRUE);
m2runtime_loop_2: ;
/*3514*/ 	Globals_curr_class = NULL;
/*3518*/ }


/*3520*/ void
/*3520*/ Statements_ParseStatic(void)
/*3520*/ {
/*3521*/ 	RECORD * Statements_r = NULL;
/*3522*/ 	STRING * Statements_id = NULL;
/*3523*/ 	RECORD * Statements_v = NULL;
/*3525*/ 	RECORD * Statements_t = NULL;
/*3525*/ 	if( (Globals_scope == 0) ){
/*3526*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"static declaration at global scope has no effect");
/*3528*/ 	}
/*3528*/ 	Scanner_ReadSym();
/*3530*/ 	if( (Scanner_sym == 19) ){
/*3531*/ 		Scanner_ReadSym();
/*3532*/ 		if( (Globals_php_ver == 4) ){
/*3533*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"invalid `static::' (PHP 5)");
/*3535*/ 		}
/*3535*/ 		if( Globals_curr_class == NULL ){
/*3536*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"invalid `static::': not inside a class");
/*3538*/ 		} else {
/*3538*/ 			Statements_r = Expressions_ParseClassStaticAccess(Globals_curr_class);
/*3540*/ 			return ;
/*3542*/ 		}
/*3543*/ 	}
/*3543*/ 	Statements_t = Expressions_ParseType(FALSE);
/*3546*/ 	do{
/*3546*/ 		Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"expected variable name in static declaration");
/*3547*/ 		Statements_id = Scanner_s;
/*3550*/ 		Statements_v = Search_SearchVar(Statements_id);
/*3551*/ 		if( ((Statements_v != NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(Statements_v, 7 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 673) == Globals_scope))) ){
/*3552*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"`static $", Statements_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"': variable already exists", (STRING *) 1));
/*3555*/ 		}
/*3555*/ 		Accounting_AccountVarLHS(Statements_id, FALSE);
/*3556*/ 		Statements_v = Search_SearchVar(Statements_id);
/*3558*/ 		if( Statements_t != NULL ){
/*3559*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 674) = Statements_t;
/*3562*/ 		}
/*3562*/ 		Scanner_ReadSym();
/*3563*/ 		if( (Scanner_sym == 31) ){
/*3564*/ 			Scanner_ReadSym();
/*3565*/ 			Statements_r = Expressions_ParseStaticExpr();
/*3566*/ 			if( Statements_r == NULL ){
/*3570*/ 			}
/*3570*/ 			if( Statements_r != NULL ){
/*3571*/ 				if( Statements_t == NULL ){
/*3572*/ 					Statements_v = Search_SearchVar(Statements_id);
/*3573*/ 					*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 675) = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 676);
/*3575*/ 				} else {
/*3575*/ 					switch(Expressions_LhsMatchRhs(Statements_t, (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 677))){

/*3576*/ 					case 1:
/*3577*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"the type of the expression ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 678)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)" does not match the ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"type of the variable `", Statements_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"' ", Types_TypeToString(Statements_t), (STRING *) 1));
/*3581*/ 					break;

/*3581*/ 					case 2:
/*3582*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"the type of the expression ", Types_TypeToString((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 679)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)" does not match the ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"type of the variable `", Statements_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"' ", Types_TypeToString(Statements_t), (STRING *) 1));
/*3587*/ 					break;
/*3589*/ 					}
/*3590*/ 				}
/*3590*/ 			}
/*3590*/ 		} else if( Statements_t == NULL ){
/*3591*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"undefined type for static variable `$", Statements_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"'. Hint: you may", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)" indicate an explicit type (example: `static /*.int.*/ $", Statements_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"')", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)" or assign a default value (example: `static $", Statements_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"=123').", (STRING *) 1));
/*3595*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 680) = NULL;
/*3597*/ 		} else {
/*3597*/ 			if( (Expressions_LhsMatchRhs(Statements_t, Globals_null_type) != 0) ){
/*3598*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"static local variable $", Statements_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)" of type ", Types_TypeToString(Statements_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\170,\0,\0,\0)" requires an initial value, otherwise it would be initialized to the invalid value NULL at runtime (PHPLint restriction)", (STRING *) 1));
/*3602*/ 			}
/*3602*/ 		}
/*3602*/ 		if( (Scanner_sym == 16) ){
/*3603*/ 			Scanner_ReadSym();
/*3604*/ 		} else if( (Scanner_sym == 17) ){
/*3607*/ 			goto m2runtime_loop_1;
/*3607*/ 		} else {
/*3607*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)"expected `=' or `,' or `;' in static declaration, found ", Scanner_SymToName(Scanner_sym), (STRING *) 1));
/*3610*/ 		}
/*3611*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*3613*/ }


/*3615*/ int
/*3615*/ Statements_ParseIf(void)
/*3615*/ {
/*3616*/ 	RECORD * Statements_r = NULL;
/*3617*/ 	int Statements_res = 0;
/*3617*/ 	int Statements_q = 0;
/*3617*/ 	int Statements_p = 0;
/*3619*/ 	RECORD * Statements_b = NULL;
/*3619*/ 	RECORD * Statements_a = NULL;
/*3619*/ 	RECORD * Statements_before = NULL;
/*3619*/ 	Scanner_ReadSym();
/*3620*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected '(' after `if'");
/*3621*/ 	Scanner_ReadSym();
/*3622*/ 	Statements_r = Expressions_ParseExpr();
/*3623*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"expected closing ')' after 'if' condition");
/*3624*/ 	Expressions_CheckBoolean((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"`if(EXPR)'", Statements_r);
/*3625*/ 	Scanner_ReadSym();
/*3628*/ 	Statements_before = Statements_GrabAssignedVars();
/*3629*/ 	Statements_p = Statements_ParseBlock();
/*3632*/ 	if( (((Scanner_sym == 26)) || ((Scanner_sym == 27))) ){
/*3634*/ 		if( ((Statements_p & 1) == 0) ){
/*3635*/ 			Statements_a = Statements_before;
/*3637*/ 		} else {
/*3637*/ 			Statements_a = Statements_GrabAssignedVars();
/*3639*/ 		}
/*3639*/ 		Statements_SetAssignedVars(Statements_before);
/*3641*/ 		if( (Scanner_sym == 27) ){
/*3642*/ 			Statements_q = Statements_ParseIf();
/*3644*/ 		} else {
/*3644*/ 			Scanner_ReadSym();
/*3645*/ 			Statements_q = Statements_ParseBlock();
/*3647*/ 		}
/*3647*/ 		if( ((Statements_q & 1) == 0) ){
/*3648*/ 			Statements_b = Statements_before;
/*3650*/ 		} else {
/*3650*/ 			Statements_b = Statements_GrabAssignedVars();
/*3653*/ 		}
/*3653*/ 		if( Statements_isTrue(Statements_r) ){
/*3654*/ 			Statements_SetAssignedVars(Statements_a);
/*3655*/ 			Statements_res = Statements_p;
/*3656*/ 		} else if( Statements_isFalse(Statements_r) ){
/*3657*/ 			Statements_SetAssignedVars(Statements_b);
/*3658*/ 			Statements_res = Statements_q;
/*3660*/ 		} else {
/*3660*/ 			if( ((Statements_p & 1) == 0) ){
/*3661*/ 				Statements_SetAssignedVars(Statements_b);
/*3662*/ 			} else if( ((Statements_q & 1) == 0) ){
/*3663*/ 				Statements_SetAssignedVars(Statements_a);
/*3665*/ 			} else {
/*3665*/ 				Statements_SetAssignedVars(Statements_IntersectAssignedVars(Statements_a, Statements_b));
/*3667*/ 			}
/*3667*/ 			Statements_res = (Statements_p | Statements_q);
/*3670*/ 		}
/*3670*/ 	} else {
/*3670*/ 		if( Statements_isTrue(Statements_r) ){
/*3672*/ 			Statements_res = Statements_p;
/*3674*/ 		} else {
/*3674*/ 			Statements_SetAssignedVars(Statements_before);
/*3675*/ 			Statements_res = (Statements_p | 1);
/*3678*/ 		}
/*3679*/ 	}
/*3679*/ 	return Statements_res;
/*3683*/ }


/*3685*/ void
/*3685*/ Statements_ParseDefine(int Statements_private)
/*3685*/ {
/*3686*/ 	STRING * Statements_name = NULL;
/*3687*/ 	RECORD * Statements_r = NULL;
/*3688*/ 	RECORD * Statements_t = NULL;
/*3689*/ 	RECORD * Statements_c = NULL;
/*3691*/ 	STRING * Statements_descr = NULL;
/*3692*/ 	Statements_DocBlockCheckAllowedLineTags(128, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"define()");
/*3694*/ 	Scanner_ReadSym();
/*3695*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"missing '(' after 'define'");
/*3698*/ 	Scanner_ReadSym();
/*3699*/ 	Statements_r = Expressions_ParseExprOfType(Globals_string_type);
/*3700*/ 	if( Statements_r == NULL ){
/*3702*/ 	} else if( (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 681) == NULL ){
/*3703*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\126,\0,\0,\0)"unable to parse the name of the constant as a value statically determined, will ignore");
/*3705*/ 	} else {
/*3705*/ 		Statements_name = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 682);
/*3706*/ 		if( !m2_match(Statements_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"^[a-zA-Z_\200-\377][a-zA-Z_0-9\200-\377]*$") ){
/*3707*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"invalid characters in constant name `", Statements_name, m2runtime_CHR(39), (STRING *) 1));
/*3708*/ 		} else if( (Scanner_SearchPhpKeyword(Statements_name) != 1) ){
/*3709*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"constant name `", Statements_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"' is a keyword", (STRING *) 1));
/*3712*/ 		}
/*3713*/ 	}
/*3713*/ 	Scanner_Expect(16, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"expexted `,' in define()");
/*3714*/ 	Scanner_ReadSym();
/*3717*/ 	Statements_r = Expressions_ParseExpr();
/*3718*/ 	if( Statements_r == NULL ){
/*3721*/ 	} else {
/*3721*/ 		Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 683);
/*3722*/ 		if( !(((Statements_t == Globals_null_type) || (Statements_t == Globals_boolean_type) || (Statements_t == Globals_int_type) || (Statements_t == Globals_float_type) || (Statements_t == Globals_string_type))) ){
/*3723*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"invalid constant value of type ", Types_TypeToString(Statements_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)". It must be boolean, int, float or string", (STRING *) 1));
/*3725*/ 		} else if( (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 684) == NULL ){
/*3726*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\110,\0,\0,\0)"can't parse the value of the constant as a statically determinable value");
/*3729*/ 		}
/*3730*/ 	}
/*3730*/ 	if( Statements_name != NULL ){
/*3731*/ 		Statements_c = Accounting_AccountConstLHS(Statements_name, Statements_private, Statements_r);
/*3734*/ 	}
/*3734*/ 	if( (Scanner_sym == 16) ){
/*3735*/ 		Scanner_ReadSym();
/*3736*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\113,\0,\0,\0)"will ignore third argument of define(): constants are always case-sensitive");
/*3737*/ 		Statements_r = Expressions_ParseExprOfType(Globals_boolean_type);
/*3740*/ 	}
/*3740*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"expected closing ')' in 'define'");
/*3741*/ 	Scanner_ReadSym();
/*3752*/ 	if( (Scanner_sym == 17) ){
/*3753*/ 		Scanner_ReadSym();
/*3754*/ 		if( (Scanner_sym == 183) ){
/*3755*/ 			Statements_descr = Scanner_s;
/*3756*/ 			Scanner_ReadSym();
/*3759*/ 		}
/*3759*/ 	} else if( (((Scanner_sym == 6)) || ((Scanner_sym == 0))) ){
/*3766*/ 	} else {
/*3771*/ 	}
/*3771*/ 	if( Statements_descr != NULL ){
/*3772*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 685) = Statements_descr;
/*3773*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 686) = Documentator_ExtractDeprecated(Statements_descr);
/*3774*/ 	} else if( Statements_pdb != NULL ){
/*3775*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 687) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 688);
/*3776*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 689) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 690));
/*3777*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 691) = ((Statements_private ||  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 692)));
/*3778*/ 		Statements_pdb = NULL;
/*3782*/ 	}
/*3784*/ }


/*3786*/ void
/*3786*/ Statements_ParseConst(int Statements_private)
/*3786*/ {
/*3787*/ 	STRING * Statements_name = NULL;
/*3788*/ 	RECORD * Statements_r = NULL;
/*3789*/ 	RECORD * Statements_t = NULL;
/*3791*/ 	RECORD * Statements_c = NULL;
/*3791*/ 	if( (Globals_php_ver == 4) ){
/*3792*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"`const' keyword is reserved by PHP 5");
/*3793*/ 	} else if( (Globals_scope > 0) ){
/*3794*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"`const' declaration allowed only in classes and in global scope");
/*3797*/ 	}
/*3797*/ 	Statements_DocBlockCheckAllowedLineTags(128, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"const");
/*3799*/ 	Scanner_ReadSym();
/*3804*/ 	do{
/*3804*/ 		Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"expected name of the constant");
/*3805*/ 		Statements_name = Namespace_CheckBareID(Scanner_s);
/*3806*/ 		Statements_name = Namespace_Absolute(Statements_name);
/*3807*/ 		Scanner_ReadSym();
/*3809*/ 		Scanner_Expect(31, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `='");
/*3810*/ 		Scanner_ReadSym();
/*3813*/ 		Statements_r = Expressions_ParseStaticExpr();
/*3814*/ 		if( Statements_r == NULL ){
/*3817*/ 		} else {
/*3817*/ 			Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 693);
/*3818*/ 			if( !(((Statements_t == Globals_null_type) || (Statements_t == Globals_boolean_type) || (Statements_t == Globals_int_type) || (Statements_t == Globals_float_type) || (Statements_t == Globals_string_type))) ){
/*3819*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"invalid constant value of type ", Types_TypeToString(Statements_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)". It must be boolean, int, float or string", (STRING *) 1));
/*3821*/ 			} else if( (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 694) == NULL ){
/*3822*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\110,\0,\0,\0)"can't parse the value of the constant as a statically determinable value");
/*3825*/ 			}
/*3826*/ 		}
/*3826*/ 		Statements_c = Accounting_AccountConstLHS(Statements_name, Statements_private, Statements_r);
/*3828*/ 		if( Statements_pdb != NULL ){
/*3829*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 695) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 696);
/*3830*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 697) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 698));
/*3831*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 699) = ((Statements_private ||  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 700)));
/*3844*/ 		}
/*3844*/ 		if( (Scanner_sym == 16) ){
/*3845*/ 			Scanner_ReadSym();
/*3847*/ 		} else if( (Scanner_sym == 17) ){
/*3848*/ 			Scanner_ReadSym();
/*3849*/ 			if( (Scanner_sym == 183) ){
/*3850*/ 				*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 701) = Scanner_s;
/*3851*/ 				*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 702) = Documentator_ExtractDeprecated(Scanner_s);
/*3852*/ 				Scanner_ReadSym();
/*3855*/ 			}
/*3856*/ 			goto m2runtime_loop_1;
/*3856*/ 		} else if( (((Scanner_sym == 6)) || ((Scanner_sym == 0))) ){
/*3860*/ 			goto m2runtime_loop_1;
/*3862*/ 		} else {
/*3864*/ 			goto m2runtime_loop_1;
/*3866*/ 		}
/*3867*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*3867*/ 	Statements_pdb = NULL;
/*3872*/ }


/*3874*/ int
/*3874*/ Statements_ParseDeclare(void)
/*3874*/ {

/*3875*/ 	void
/*3875*/ 	Statements_ParseDirective(void)
/*3875*/ 	{
/*3877*/ 		RECORD * Statements_r = NULL;
/*3877*/ 		if( (Scanner_sym != 29) ){
/*3878*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"expected identifier");
/*3880*/ 		}
/*3880*/ 		if( ((m2runtime_strcmp(Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"ticks") != 0) && (m2runtime_strcmp(Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"encoding") != 0)) ){
/*3881*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"unknown directive \042", Scanner_s, m2runtime_CHR(34), (STRING *) 1));
/*3883*/ 		}
/*3883*/ 		Scanner_ReadSym();
/*3885*/ 		Scanner_Expect(31, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `='");
/*3886*/ 		Scanner_ReadSym();
/*3888*/ 		Statements_r = Expressions_ParseStaticExpr();
/*3892*/ 	}

/*3892*/ 	Scanner_ReadSym();
/*3893*/ 	Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `('");
/*3894*/ 	Scanner_ReadSym();
/*3896*/ 	do{
/*3896*/ 		Statements_ParseDirective();
/*3897*/ 		if( (Scanner_sym == 16) ){
/*3898*/ 			Scanner_ReadSym();
/*3901*/ 		} else {
/*3902*/ 			goto m2runtime_loop_1;
/*3903*/ 		}
/*3903*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*3903*/ 	Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"expected `,' or `)'");
/*3904*/ 	Scanner_ReadSym();
/*3905*/ 	return Statements_ParseBlock();
/*3909*/ }


/*3910*/ int
/*3910*/ Statements_readable(STRING *Statements_f)
/*3910*/ {
/*3912*/ 	void * Statements_fd = NULL;
/*3912*/ 	m2runtime_ERROR_CODE = 0;
/*3912*/ 	io_Open(1, (void *)&Statements_fd, Statements_f, m2runtime_CHR(114));
/*3913*/ 	switch( m2runtime_ERROR_CODE ){

/*3913*/ 	case 0:
/*3914*/ 		m2runtime_ERROR_CODE = 0;
/*3914*/ 		io_Close(1, (void *)&Statements_fd);
/*3915*/ 		switch( m2runtime_ERROR_CODE ){

/*3915*/ 		case 0:  break;
/*3915*/ 		default:
/*3915*/ 			m2runtime_HALT(Statements_0err_entry_get, 703, m2runtime_ERROR_MESSAGE);
/*3915*/ 		}
/*3915*/ 		return TRUE;
/*3917*/ 		break;

/*3917*/ 	default:
/*3917*/ 		return FALSE;
/*3920*/ 	}
/*3920*/ 	m2runtime_missing_return(Statements_0err_entry_get, 704);
/*3920*/ 	return 0;
/*3922*/ }


/*3927*/ void
/*3927*/ Statements_AddPackageToIncludePath(STRING *Statements_p)
/*3927*/ {
/*3929*/ 	int Statements_i = 0;
/*3929*/ 	{
/*3929*/ 		int m2runtime_for_limit_1;
/*3929*/ 		Statements_i = 0;
/*3929*/ 		m2runtime_for_limit_1 = (m2runtime_count(Statements_include_path) - 1);
/*3930*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*3930*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(Statements_include_path, Statements_i, Statements_0err_entry_get, 705), Statements_p) == 0 ){
/*3932*/ 				return ;
/*3934*/ 			}
/*3934*/ 		}
/*3934*/ 	}
/*3934*/ 	*(STRING **)m2runtime_dereference_lhs_ARRAY_next(&Statements_include_path, sizeof(void *), 1, Statements_0err_entry_get, 706) = Statements_p;
/*3938*/ }


/*3944*/ STRING *
/*3944*/ Statements_SearchFileOnPaths(STRING *Statements_name, int Statements_module)
/*3944*/ {
/*3945*/ 	STRING * Statements_n = NULL;
/*3946*/ 	ARRAY * Statements_a = NULL;
/*3948*/ 	int Statements_i = 0;
/*3949*/ 	if( !Statements_module ){
/*3951*/ 		Statements_n = FileName_Absolute(NULL, Statements_name);
/*3952*/ 		if( Statements_readable(Statements_n) ){
/*3953*/ 			return Statements_n;
/*3956*/ 		}
/*3957*/ 	}
/*3957*/ 	if( !FileName_IsAbsolute(Statements_name) ){
/*3958*/ 		if( Statements_module ){
/*3959*/ 			Statements_a = Statements_modules_abs_path;
/*3961*/ 		} else {
/*3961*/ 			Statements_a = Statements_packages_abs_path;
/*3963*/ 		}
/*3963*/ 		{
/*3963*/ 			int m2runtime_for_limit_1;
/*3963*/ 			Statements_i = 0;
/*3963*/ 			m2runtime_for_limit_1 = (m2runtime_count(Statements_a) - 1);
/*3964*/ 			for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*3964*/ 				Statements_n = FileName_Absolute(NULL, m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, Statements_i, Statements_0err_entry_get, 707), m2runtime_CHR(47), Statements_name, (STRING *) 1));
/*3965*/ 				if( Statements_readable(Statements_n) ){
/*3966*/ 					if( !Statements_module ){
/*3967*/ 						Statements_AddPackageToIncludePath(FileName_Basename(Statements_name));
/*3969*/ 					}
/*3969*/ 					return Statements_n;
/*3972*/ 				}
/*3973*/ 			}
/*3973*/ 		}
/*3974*/ 	}
/*3974*/ 	if( Statements_module ){
/*3975*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"module `", Statements_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"' not found", (STRING *) 1));
/*3977*/ 	} else {
/*3977*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"package `", Statements_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"' not found", (STRING *) 1));
/*3980*/ 	}
/*3980*/ 	return NULL;
/*3985*/ }


/*3993*/ RECORD *
/*3993*/ Statements_SearchPackage(STRING *Statements_abs_pathfile)
/*3993*/ {
/*3995*/ 	int Statements_i = 0;
/*3995*/ 	{
/*3995*/ 		int m2runtime_for_limit_1;
/*3995*/ 		Statements_i = 0;
/*3995*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_required_packages) - 1);
/*3996*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*3996*/ 			if( m2runtime_strcmp(Statements_abs_pathfile, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_required_packages, Statements_i, Statements_0err_entry_get, 708), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 709)) == 0 ){
/*3997*/ 				return (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_required_packages, Statements_i, Statements_0err_entry_get, 710);
/*4000*/ 			}
/*4000*/ 		}
/*4000*/ 	}
/*4000*/ 	return NULL;
/*4004*/ }


/*4017*/ void
/*4017*/ Statements_RequirePackage(STRING *Statements_pathfile, int Statements_module)
/*4017*/ {
/*4018*/ 	STRING * Statements_abs_pathfile = NULL;
/*4019*/ 	void * Statements_sc = NULL;
/*4020*/ 	int Statements_s_scope = 0;
/*4021*/ 	int Statements_s_loop_level = 0;
/*4022*/ 	int Statements_s_try_block_nesting_level = 0;
/*4023*/ 	int Statements_s_print_notices = 0;
/*4023*/ 	int Statements_s_print_source = 0;
/*4023*/ 	int Statements_s_report_unused = 0;
/*4024*/ 	RECORD * Statements_s_curr_package = NULL;
/*4025*/ 	RECORD * Statements_s_curr_func = NULL;
/*4026*/ 	RECORD * Statements_s_curr_class = NULL;
/*4027*/ 	RECORD * Statements_s_curr_method = NULL;
/*4028*/ 	RECORD * Statements_s_pdb = NULL;
/*4029*/ 	ARRAY * Statements_s_exceptions = NULL;
/*4030*/ 	void * Statements_pdb_status = NULL;
/*4031*/ 	STRING * Statements_s = NULL;
/*4033*/ 	RECORD * Statements_loaded_package = NULL;
/*4033*/ 	Statements_abs_pathfile = Statements_SearchFileOnPaths(Statements_pathfile, Statements_module);
/*4034*/ 	if( Statements_abs_pathfile == NULL ){
/*4036*/ 		return ;
/*4038*/ 	}
/*4038*/ 	if( Statements_SearchPackage(Statements_abs_pathfile) != NULL ){
/*4040*/ 		return ;
/*4043*/ 	}
/*4043*/ 	Statements_s_scope = Globals_scope;
/*4043*/ 	Globals_scope = 0;
/*4044*/ 	Statements_s_loop_level = Globals_loop_level;
/*4044*/ 	Globals_loop_level = 0;
/*4045*/ 	Statements_s_try_block_nesting_level = Globals_try_block_nesting_level;
/*4045*/ 	Globals_try_block_nesting_level = 0;
/*4046*/ 	Statements_s_pdb = Statements_pdb;
/*4046*/ 	Statements_pdb = NULL;
/*4047*/ 	Statements_pdb_status = ParseDocBlock_Suspend();
/*4048*/ 	Statements_sc = Scanner_Suspend();
/*4049*/ 	Statements_s_report_unused = Accounting_report_unused;
/*4050*/ 	Accounting_report_unused = FALSE;
/*4051*/ 	Statements_s_print_source = Scanner_print_source;
/*4052*/ 	Scanner_print_source = FALSE;
/*4053*/ 	Statements_s_print_notices = Scanner_print_notices;
/*4054*/ 	Scanner_print_notices = FALSE;
/*4055*/ 	Statements_s_curr_func = Globals_curr_func;
/*4055*/ 	Globals_curr_func = NULL;
/*4056*/ 	Statements_s_curr_class = Globals_curr_class;
/*4056*/ 	Globals_curr_class = NULL;
/*4057*/ 	Statements_s_curr_method = Globals_curr_method;
/*4057*/ 	Globals_curr_method = NULL;
/*4058*/ 	Statements_s_curr_package = Globals_curr_package;
/*4058*/ 	Globals_curr_package = NULL;
/*4059*/ 	Statements_s_exceptions = Globals_exceptions;
/*4059*/ 	Globals_exceptions = NULL;
	Globals_curr_package = Statements_ParsePackage(Statements_abs_pathfile, Statements_module);
/*4062*/ 	Statements_loaded_package = Globals_curr_package;
/*4065*/ 	Globals_exceptions = Statements_s_exceptions;
/*4066*/ 	Globals_curr_func = Statements_s_curr_func;
/*4067*/ 	Globals_curr_class = Statements_s_curr_class;
/*4068*/ 	Globals_curr_method = Statements_s_curr_method;
/*4069*/ 	Globals_curr_package = Statements_s_curr_package;
/*4070*/ 	Accounting_report_unused = Statements_s_report_unused;
/*4071*/ 	Scanner_print_source = Statements_s_print_source;
/*4072*/ 	Scanner_print_notices = Statements_s_print_notices;
/*4073*/ 	Globals_try_block_nesting_level = Statements_s_try_block_nesting_level;
/*4074*/ 	Globals_loop_level = Statements_s_loop_level;
/*4075*/ 	Globals_scope = Statements_s_scope;
/*4076*/ 	Scanner_Resume(Statements_sc);
/*4077*/ 	ParseDocBlock_Resume(Statements_pdb_status);
/*4078*/ 	Statements_pdb = Statements_s_pdb;
/*4080*/ 	if( ! *(int *)m2runtime_dereference_rhs_RECORD(Statements_loaded_package, 6 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 711) ){
/*4081*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"loaded package ", Statements_pathfile, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)" is not a library: ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_loaded_package, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 712), (STRING *) 1));
/*4085*/ 	}
/*4085*/ 	if( ((Statements_loaded_package != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Statements_loaded_package, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 713), EMPTY_STRING) > 0)) ){
/*4086*/ 		if( Statements_module ){
/*4087*/ 			Statements_s = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"module";
/*4089*/ 		} else {
/*4089*/ 			Statements_s = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"package";
/*4091*/ 		}
/*4091*/ 		Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"using deprecated ", Statements_s, m2runtime_CHR(32), Statements_abs_pathfile, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_loaded_package, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 714), (STRING *) 1));
/*4095*/ 	}
/*4095*/ 	if( (Statements_module && (m2runtime_strcmp(Statements_pathfile, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"spl") == 0)) ){
/*4096*/ 		Classes_PreloadBuiltinSplClasses();
/*4099*/ 	}
/*4101*/ }


/*4106*/ void
/*4106*/ Statements_ParseRequireModule(void)
/*4106*/ {
/*4106*/ 	if( (Globals_scope > 0) ){
/*4107*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"found `require_module' in scope level > 0");
/*4109*/ 	}
/*4109*/ 	Scanner_ReadSym();
/*4110*/ 	Scanner_Expect(131, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"expected single quoted string after `require_module'");
/*4111*/ 	if( !m2_match(Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"^[a-zA-Z0-9_]+$") ){
/*4112*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"require_module '", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\160,\0,\0,\0)"': module name contains invalid characters. Hint: only letters, digits and underscore allowed; path not allowed.", (STRING *) 1));
/*4114*/ 	} else {
/*4114*/ 		Statements_RequirePackage(Scanner_s, TRUE);
/*4116*/ 	}
/*4116*/ 	Scanner_ReadSym();
/*4117*/ 	Scanner_Expect(132, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"missing `;'");
/*4118*/ 	Scanner_ReadSym();
/*4122*/ }


/*4129*/ void
/*4129*/ Statements_ParseRequireOnce(void)
/*4129*/ {
/*4130*/ 	int Statements_autoload = 0;
/*4132*/ 	RECORD * Statements_r = NULL;
/*4132*/ 	Statements_autoload = ((Globals_curr_func != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 715), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__autoload") == 0));
/*4133*/ 	if( (!Statements_autoload && ((Globals_scope > 0))) ){
/*4134*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"found `require_once' in scope level > 0");
/*4136*/ 	}
/*4136*/ 	Scanner_ReadSym();
/*4138*/ 	Statements_r = Expressions_ParseExprOfType(Globals_string_type);
/*4139*/ 	if( Statements_r == NULL ){
/*4141*/ 	} else if( (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 716) == NULL ){
/*4142*/ 		if( !Statements_autoload ){
/*4143*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\67,\0,\0,\0)"require_once: can't check file name, value undetermined");
/*4145*/ 		}
/*4145*/ 	} else if( (m2runtime_length((STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 717)) == 0) ){
/*4146*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"require_once: empty file name");
/*4148*/ 	} else {
/*4148*/ 		if( !FileName_IsAbsolute((STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 718)) ){
/*4149*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"file path \042", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 719), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\207,\0,\0,\0)"\042 must be absolute (PHPLint safety restriction). Hint: under PHP5 the magic constant __DIR__ gives the directory of the current source.", (STRING *) 1));
/*4154*/ 		} else if( (!Globals_recursive_parsing && ((Statements_recursion_level == 1))) ){
/*4155*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\110,\0,\0,\0)"cannot load package: recursive parsing disabled by --no-recursive option");
/*4157*/ 		} else {
/*4157*/ 			Statements_RequirePackage((STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 720), FALSE);
/*4160*/ 		}
/*4161*/ 	}
/*4163*/ }


/*4164*/ void
/*4164*/ Statements_ParseInclude(STRING *Statements_n)
/*4164*/ {
/*4166*/ 	RECORD * Statements_r = NULL;
/*4166*/ 	Scanner_ReadSym();
/*4167*/ 	Statements_r = Expressions_ParseExprOfType(Globals_string_type);
/*4168*/ 	if( Statements_r == NULL ){
/*4170*/ 	} else if( (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 721) == NULL ){
/*4171*/ 		Scanner_Warning(m2runtime_concat_STRING(0, Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)": can't check file name, value undetermined", (STRING *) 1));
/*4172*/ 	} else if( (m2runtime_length((STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 722)) == 0) ){
/*4173*/ 		Scanner_Error(m2runtime_concat_STRING(0, Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)": empty file name", (STRING *) 1));
/*4174*/ 	} else if( !FileName_IsAbsolute((STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 723)) ){
/*4175*/ 		Scanner_Warning(m2runtime_concat_STRING(0, Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" \042", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 724), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\221,\0,\0,\0)"\042 uses relative pathfile, check `include_path' in php.ini. Hint: under PHP5 the magic constant __DIR__ gives the directory of the current source.", (STRING *) 1));
/*4178*/ 	} else {
/*4178*/ 		Scanner_Notice(m2runtime_concat_STRING(0, Statements_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" \042", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_r, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 725), m2runtime_CHR(34), (STRING *) 1));
/*4181*/ 	}
/*4183*/ }


/*4185*/ void
/*4185*/ Statements_ParseThrow(void)
/*4185*/ {
/*4186*/ 	RECORD * Statements_r = NULL;
/*4187*/ 	RECORD * Statements_t = NULL;
/*4189*/ 	RECORD * Statements_e = NULL;
/*4189*/ 	Scanner_ReadSym();
/*4190*/ 	Statements_r = Expressions_ParseExpr();
/*4191*/ 	if( Statements_r == NULL ){
/*4194*/ 		return ;
/*4195*/ 	}
/*4195*/ 	Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 726);
/*4196*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_t, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 727) == 9) ){
/*4197*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_t, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 728) == NULL ){
/*4199*/ 		} else if( Classes_IsExceptionClass((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_t, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 729)) ){
/*4200*/ 			Statements_e = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_t, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 730);
/*4201*/ 			Exceptions_ThrowExceptions((
/*4201*/ 				push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*4201*/ 				push((char*) Statements_e),
/*4201*/ 				*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/*4202*/ 				(ARRAY*) pop()
/*4202*/ 			));
/*4203*/ 		} else {
/*4203*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the class `", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_t, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 731), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 732), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"' isn't an extension of the `Exception' class", (STRING *) 1));
/*4207*/ 		}
/*4207*/ 	} else {
/*4207*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"expected an object, found ", Types_TypeToString(Statements_t), (STRING *) 1));
/*4210*/ 	}
/*4210*/ 	if( (((Globals_scope == 0)) && (Statements_e != NULL)) ){
/*4211*/ 		Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"Uncaught exception ", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_e, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 733), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)" in global scope in ", Scanner_reference(Scanner_here()), m2runtime_CHR(46), (STRING *) 1));
/*4215*/ 	}
/*4217*/ }


/*4219*/ int
/*4219*/ Statements_ParseTry(void)
/*4219*/ {
/*4220*/ 	RECORD * Statements_try_location = NULL;
/*4221*/ 	RECORD * Statements_class = NULL;
/*4222*/ 	RECORD * Statements_v = NULL;
/*4223*/ 	RECORD * Statements_t = NULL;
/*4224*/ 	ARRAY * Statements_caught = NULL;
/*4224*/ 	ARRAY * Statements_thrown = NULL;
/*4224*/ 	ARRAY * Statements_saved_exceptions = NULL;
/*4225*/ 	int Statements_p = 0;
/*4225*/ 	int Statements_res = 0;
/*4226*/ 	RECORD * Statements_after = NULL;
/*4226*/ 	RECORD * Statements_before = NULL;
/*4228*/ 	STRING * Statements_dummy_var_name = NULL;
/*4231*/ 	static int Statements_catch_nesting_level = 0;
/*4231*/ 	Statements_try_location = Scanner_here();
/*4232*/ 	Scanner_ReadSym();
/*4233*/ 	Scanner_Expect(10, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"expected `{' after try");
/*4236*/ 	m2_inc(&Globals_try_block_nesting_level, 1);
/*4237*/ 	Statements_saved_exceptions = Globals_exceptions;
/*4238*/ 	Globals_exceptions = NULL;
/*4241*/ 	Statements_before = Statements_GrabAssignedVars();
/*4242*/ 	Statements_res = Statements_ParseBlock();
/*4243*/ 	if( ((Statements_res & 1) == 0) ){
/*4244*/ 		Statements_after = Statements_before;
/*4246*/ 	} else {
/*4246*/ 		Statements_after = Statements_GrabAssignedVars();
/*4250*/ 	}
/*4250*/ 	m2_inc(&Globals_try_block_nesting_level, -1);
/*4251*/ 	Statements_thrown = Globals_exceptions;
/*4252*/ 	Globals_exceptions = Statements_saved_exceptions;
/*4259*/ 	Scanner_Expect(119, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"expected `catch'");
/*4260*/ 	Statements_dummy_var_name = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"catch#", m2runtime_itos(Statements_catch_nesting_level), (STRING *) 1);
/*4261*/ 	m2_inc(&Statements_catch_nesting_level, 1);
/*4263*/ 	do {
/*4263*/ 		Scanner_ReadSym();
/*4265*/ 		Scanner_Expect(12, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"expected `(' after `catch'");
/*4266*/ 		Scanner_ReadSym();
/*4272*/ 		Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected exception name");
/*4273*/ 		Statements_class = Search_SearchClass(Scanner_s);
/*4274*/ 		if( Statements_class == NULL ){
/*4275*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"undefined class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/*4276*/ 		} else if( Classes_IsExceptionClass(Statements_class) ){
/*4277*/ 			if( Exceptions_RemoveExceptionFromSet(Statements_class, &Statements_thrown) ){
/*4278*/ 				Exceptions_AddExceptionToSet(Statements_class, &Statements_caught);
/*4280*/ 			} else {
/*4280*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Statements_class, 15 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 734) ){
/*4281*/ 					if( Classes_IsSubclassOfSet(Statements_class, Statements_caught) ){
/*4282*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"exception `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"' already caught", (STRING *) 1));
/*4285*/ 					}
/*4285*/ 				} else {
/*4285*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"exception `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"' not thrown or already caught", (STRING *) 1));
/*4288*/ 				}
/*4289*/ 			}
/*4289*/ 		} else {
/*4289*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"' isn't an extension of the `Exception' class", (STRING *) 1));
/*4291*/ 		}
/*4291*/ 		Scanner_ReadSym();
/*4325*/ 		Statements_SetAssignedVars(Statements_before);
/*4326*/ 		Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"expected variable name");
/*4327*/ 		Statements_v = Search_SearchVar(Scanner_s);
/*4328*/ 		if( Statements_v == NULL ){
/*4329*/ 			Statements_v = Search_SearchVar(Statements_dummy_var_name);
/*4330*/ 			if( Statements_v == NULL ){
/*4331*/ 				Accounting_AccountVarLHS(Statements_dummy_var_name, FALSE);
/*4332*/ 				Statements_v = Search_SearchVar(Statements_dummy_var_name);
/*4335*/ 			}
/*4335*/ 		} else {
/*4335*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"variable `$", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\116,\0,\0,\0)"' is already in use, it cannot be used in catch() branch (PHPLint restriction)", (STRING *) 1));
/*4342*/ 		}
/*4342*/ 		if( Statements_class == NULL ){
/*4343*/ 			Statements_t = NULL;
/*4345*/ 		} else {
/*4345*/ 			Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_class, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 735);
/*4347*/ 		}
/*4347*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 736) = Scanner_s;
/*4348*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 737) = Statements_t;
/*4349*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 738) = TRUE;
/*4350*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 739) = Scanner_here();
/*4351*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 740) = 0;
/*4352*/ 		Accounting_AccountVarLHS2(Statements_v);
/*4353*/ 		Scanner_ReadSym();
/*4355*/ 		Scanner_Expect(13, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `)'");
/*4356*/ 		Scanner_ReadSym();
/*4358*/ 		Scanner_Expect(10, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `{'");
/*4359*/ 		Statements_p = Statements_ParseBlock();
/*4364*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_v, 7 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 741) == 0) ){
/*4365*/ 			if( Accounting_report_unused ){
/*4366*/ 				Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_v, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 742), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"caught exception variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_v, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 743), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"' assigned but never used", (STRING *) 1));
/*4369*/ 			}
/*4369*/ 			Accounting_AccountVarRHS2(Statements_v);
/*4375*/ 		}
/*4375*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 744) = Statements_dummy_var_name;
/*4376*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 745) = NULL;
/*4378*/ 		Statements_res = (Statements_res | Statements_p);
/*4379*/ 		if( ((Statements_p & 1) != 0) ){
/*4380*/ 			Statements_after = Statements_IntersectAssignedVars(Statements_after, Statements_GrabAssignedVars());
/*4383*/ 		}
/*4383*/ 	} while( !( (Scanner_sym != 119) ));
/*4385*/ 	m2_inc(&Statements_catch_nesting_level, -1);
/*4388*/ 	Exceptions_ThrowExceptions(Statements_thrown);
/*4390*/ 	Statements_SetAssignedVars(Statements_after);
/*4392*/ 	return Statements_res;
/*4396*/ }


/*4398*/ void
/*4398*/ Statements_ParseEchoBlock(void)
/*4398*/ {
/*4398*/ 	RECORD * Statements_r = NULL;
/*4400*/ 	RECORD * Statements_t = NULL;
/*4400*/ 	Scanner_ReadSym();
/*4402*/ 	do{
/*4402*/ 		Statements_r = Expressions_ParseExpr();
/*4403*/ 		if( Statements_r == NULL ){
/*4406*/ 		} else {
/*4406*/ 			Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_r, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 746);
/*4407*/ 			if( !(((Statements_t == Globals_int_type) || (Statements_t == Globals_float_type) || (Statements_t == Globals_string_type))) ){
/*4409*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"found ", Types_TypeToString(Statements_t), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)". The arguments of the `<?= ... ?>' block must be of", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" type int, float or string.", (STRING *) 1));
/*4414*/ 			}
/*4414*/ 		}
/*4414*/ 		if( (Scanner_sym == 16) ){
/*4415*/ 			Scanner_ReadSym();
/*4416*/ 		} else if( (Scanner_sym == 6) ){
/*4417*/ 			Scanner_ReadSym();
/*4419*/ 			return ;
/*4419*/ 		} else if( (Scanner_sym == 0) ){
/*4421*/ 			return ;
/*4421*/ 		} else if( (Scanner_sym == 17) ){
/*4422*/ 			Scanner_Notice((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"useless `;' symbol");
/*4423*/ 			Scanner_ReadSym();
/*4424*/ 			Scanner_Expect(6, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"missing closing tag");
/*4425*/ 			Scanner_ReadSym();
/*4427*/ 			return ;
/*4428*/ 		} else {
/*4428*/ 			Scanner_UnexpectedSymbol();
/*4431*/ 		}
/*4432*/ 	}while(TRUE);
/*4434*/ }


/*4437*/ void
/*4437*/ Statements_ParseTextBlock(void)
/*4437*/ {
/*4437*/ 	Scanner_ReadSym();
/*4439*/ 	do{
/*4439*/ 		if( (Scanner_sym == 3) ){
/*4440*/ 			if( (((Globals_scope == 0)) && (m2runtime_strcmp(Scanner_s, EMPTY_STRING) > 0) && !(((m2runtime_strcmp(Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\015\012") == 0) || (m2runtime_strcmp(Scanner_s, m2runtime_CHR(10)) == 0)))) ){
/*4442*/ 				Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"Found text in ", Scanner_reference(Scanner_here()), m2runtime_CHR(46), (STRING *) 1));
/*4445*/ 			}
/*4445*/ 			Scanner_ReadSym();
/*4446*/ 		} else if( (Scanner_sym == 5) ){
/*4447*/ 			Statements_ParseEchoBlock();
/*4448*/ 		} else if( (Scanner_sym == 4) ){
/*4449*/ 			Scanner_ReadSym();
/*4451*/ 			return ;
/*4452*/ 		} else {
/*4452*/ 			Scanner_UnexpectedSymbol();
/*4455*/ 		}
/*4456*/ 	}while(TRUE);
/*4458*/ }


/*4463*/ int
/*4463*/ Statements_ParseCodeBlock(void)
/*4463*/ {
/*4465*/ 	int Statements_res = 0;
/*4465*/ 	Scanner_ReadSym();
/*4466*/ 	Statements_res = 1;
/*4468*/ 	do{
/*4468*/ 		if( (Scanner_sym == 6) ){
/*4469*/ 			Scanner_ReadSym();
/*4470*/ 			return Statements_res;
/*4471*/ 		} else if( (Scanner_sym == 0) ){
/*4472*/ 			return Statements_res;
/*4474*/ 		} else {
/*4474*/ 			if( ((Statements_res & 1) == 0) ){
/*4475*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"unreachable statement");
/*4477*/ 			}
/*4477*/ 			Statements_res = (((Statements_res & ~1)) | Statements_ParseStatement());
/*4480*/ 		}
/*4481*/ 	}while(TRUE);
/*4481*/ 	m2runtime_missing_return(Statements_0err_entry_get, 747);
/*4481*/ 	return 0;
/*4483*/ }


/*4486*/ void
/*4486*/ Statements_ParserInit(void)
/*4486*/ {
/*4487*/ 	static int Statements_parser_init = 0;
/*4488*/ 	static RECORD * Statements_here = NULL;
/*4491*/ 	static RECORD * Statements_ass = NULL;
/*4491*/ 	static RECORD * Statements_asm = NULL;

/*4495*/ 	void
/*4495*/ 	Statements_addVar(STRING *Statements_s, RECORD *Statements_t)
/*4495*/ 	{
/*4497*/ 		RECORD * Statements_v = NULL;
/*4497*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 748) = Statements_s;
/*4498*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 749) = Statements_here;
/*4499*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 750) = -1;
/*4500*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 751) = TRUE;
/*4501*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 752) = Statements_here;
/*4502*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 6 * sizeof(int), Statements_0err_entry_get, 753) = 100;
/*4503*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 5 * sizeof(int), Statements_0err_entry_get, 754) = TRUE;
/*4504*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 755) = Statements_t;
/*4505*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY(&Globals_vars, sizeof(void *), 1, Globals_vars_n, Statements_0err_entry_get, 756) = Statements_v;
/*4506*/ 		m2_inc(&Globals_vars_n, 1);
/*4510*/ 	}


/*4514*/ 	void
/*4514*/ 	Statements_addConst(STRING *Statements_name, RECORD *Statements_type)
/*4514*/ 	{
/*4516*/ 		RECORD * Statements_c = NULL;
/*4517*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 757) = Statements_name;
/*4518*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 758) = Statements_name;
/*4519*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 759) = FALSE;
/*4520*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 760) = Statements_here;
/*4521*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 761) = 100;
/*4522*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 762) = Statements_here;
/*4523*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_c, 7 * sizeof(void*) + 4 * sizeof(int), 7, 4 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 763) = (
/*4523*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*4523*/ 			push((char*) Statements_type),
/*4523*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4523*/ 			push((char*) NULL),
/*4524*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4524*/ 			(RECORD*) pop()
/*4524*/ 		);
/*4524*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_consts, sizeof(void *), 1, Statements_0err_entry_get, 764) = Statements_c;
/*4529*/ 	}

/*4529*/ 	if( Statements_parser_init ){
/*4531*/ 		return ;
/*4532*/ 	}
/*4532*/ 	Statements_parser_init = TRUE;
/*4534*/ 	Scanner_InitScanner();
/*4541*/ 	Globals_null_type = (
/*4541*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4541*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 0,
/*4541*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4541*/ 		push((char*) NULL),
/*4541*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4541*/ 		push((char*) NULL),
/*4542*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4542*/ 		(RECORD*) pop()
/*4542*/ 	);
/*4542*/ 	Globals_void_type = (
/*4542*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4542*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 1,
/*4542*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4542*/ 		push((char*) NULL),
/*4542*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4542*/ 		push((char*) NULL),
/*4543*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4543*/ 		(RECORD*) pop()
/*4543*/ 	);
/*4543*/ 	Globals_boolean_type = (
/*4543*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4543*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 2,
/*4543*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4543*/ 		push((char*) NULL),
/*4543*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4543*/ 		push((char*) NULL),
/*4544*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4544*/ 		(RECORD*) pop()
/*4544*/ 	);
/*4544*/ 	Globals_int_type = (
/*4544*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4544*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 3,
/*4544*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4544*/ 		push((char*) NULL),
/*4544*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4544*/ 		push((char*) NULL),
/*4545*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4545*/ 		(RECORD*) pop()
/*4545*/ 	);
/*4545*/ 	Globals_float_type = (
/*4545*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4545*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 4,
/*4545*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4545*/ 		push((char*) NULL),
/*4545*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4545*/ 		push((char*) NULL),
/*4546*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4546*/ 		(RECORD*) pop()
/*4546*/ 	);
/*4546*/ 	Globals_string_type = (
/*4546*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4546*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 5,
/*4546*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4546*/ 		push((char*) NULL),
/*4546*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4546*/ 		push((char*) NULL),
/*4547*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4547*/ 		(RECORD*) pop()
/*4547*/ 	);
/*4547*/ 	Globals_mixed_type = (
/*4547*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4547*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 7,
/*4547*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4547*/ 		push((char*) NULL),
/*4547*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4547*/ 		push((char*) NULL),
/*4548*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4548*/ 		(RECORD*) pop()
/*4548*/ 	);
/*4548*/ 	Globals_resource_type = (
/*4548*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4548*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 8,
/*4548*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4548*/ 		push((char*) NULL),
/*4548*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4548*/ 		push((char*) NULL),
/*4549*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4549*/ 		(RECORD*) pop()
/*4549*/ 	);
/*4549*/ 	Globals_object_type = (
/*4549*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4549*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 9,
/*4549*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*4549*/ 		push((char*) NULL),
/*4549*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4549*/ 		push((char*) NULL),
/*4550*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4551*/ 		(RECORD*) pop()
/*4551*/ 	);
/*4551*/ 	Statements_here = (
/*4551*/ 		push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*4551*/ 		push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"standard"),
/*4551*/ 		*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4551*/ 		*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 0,
/*4557*/ 		(RECORD*) pop()
/*4557*/ 	);
/*4557*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"STDIN", Globals_resource_type);
/*4558*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"STDOUT", Globals_resource_type);
/*4559*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"STDERR", Globals_resource_type);
/*4564*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__DIR__", Globals_string_type);
/*4565*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"__CLASS__", Globals_string_type);
/*4566*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"__FILE__", Globals_string_type);
/*4567*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"__FUNCTION__", Globals_string_type);
/*4568*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"__LINE__", Globals_int_type);
/*4569*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__METHOD__", Globals_string_type);
/*4570*/ 	Statements_addConst((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"__NAMESPACE__", Globals_string_type);
/*4575*/ 	Statements_asm = (
/*4575*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4575*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*4575*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 5,
/*4575*/ 		push((char*) Globals_mixed_type),
/*4575*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4575*/ 		push((char*) NULL),
/*4576*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4576*/ 		(RECORD*) pop()
/*4576*/ 	);
/*4576*/ 	Statements_ass = (
/*4576*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4576*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*4576*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 5,
/*4576*/ 		push((char*) Globals_string_type),
/*4576*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4576*/ 		push((char*) NULL),
/*4577*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4577*/ 		(RECORD*) pop()
/*4577*/ 	);
/*4577*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"GLOBALS", Statements_asm);
/*4578*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"_SERVER", Statements_ass);
/*4579*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"_GET", Statements_asm);
/*4580*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"_POST", Statements_asm);
/*4581*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"_COOKIE", Statements_asm);
/*4582*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"_REQUEST", Statements_asm);
/*4583*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"_FILES", (
/*4583*/ 		push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*4583*/ 		*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*4583*/ 		*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 5,
/*4583*/ 		push((char*) Statements_asm),
/*4583*/ 		*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4583*/ 		push((char*) NULL),
/*4583*/ 		*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*4584*/ 		(RECORD*) pop()
/*4584*/ 	));
/*4584*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"_ENV", Statements_ass);
/*4585*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"_SESSION", Statements_asm);
/*4587*/ 	Statements_addVar((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"php_errormsg", Globals_string_type);
/*4594*/ }


/*4600*/ STRING *
/*4600*/ Statements_DetectBOM(STRING *Statements_s)
/*4600*/ {
/*4601*/ 	static ARRAY * Statements_patterns = NULL;
/*4603*/ 	static int Statements_i = 0;
/*4603*/ 	if( Statements_patterns == NULL ){
/*4604*/ 		Statements_patterns = (
/*4605*/ 			push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*4605*/ 			push((char*) (
/*4605*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*4605*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\376\377"),
/*4605*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4605*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"UTF-16 BE"),
/*4605*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4606*/ 				(RECORD*) pop()
/*4606*/ 			)),
/*4606*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/*4606*/ 			push((char*) (
/*4606*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*4606*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\377\376"),
/*4606*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4606*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"UTF-16 LE"),
/*4606*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4607*/ 				(RECORD*) pop()
/*4607*/ 			)),
/*4607*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),1) = (RECORD*) tos(), pop(),
/*4607*/ 			push((char*) (
/*4607*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*4607*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"\357\273\277"),
/*4607*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4607*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"UTF-8"),
/*4607*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4608*/ 				(RECORD*) pop()
/*4608*/ 			)),
/*4608*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),2) = (RECORD*) tos(), pop(),
/*4608*/ 			push((char*) (
/*4608*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*4608*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"\000\000\376\377"),
/*4608*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4608*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"UTF-32 BE"),
/*4608*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4609*/ 				(RECORD*) pop()
/*4609*/ 			)),
/*4609*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),3) = (RECORD*) tos(), pop(),
/*4609*/ 			push((char*) (
/*4609*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*4609*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"\377\376\000\000"),
/*4609*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4609*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"UTF-32 LE"),
/*4610*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*4611*/ 				(RECORD*) pop()
/*4611*/ 			)),
/*4611*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),4) = (RECORD*) tos(), pop(),
/*4612*/ 			(ARRAY*) pop()
/*4612*/ 		);
/*4613*/ 	}
/*4613*/ 	{
/*4613*/ 		int m2runtime_for_limit_1;
/*4613*/ 		Statements_i = 0;
/*4613*/ 		m2runtime_for_limit_1 = (m2runtime_count(Statements_patterns) - 1);
/*4614*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*4614*/ 			if( str_starts_with(Statements_s, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_patterns, Statements_i, Statements_0err_entry_get, 765), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 766)) ){
/*4615*/ 				return (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Statements_patterns, Statements_i, Statements_0err_entry_get, 767), 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 768);
/*4618*/ 			}
/*4619*/ 		}
/*4619*/ 	}
/*4619*/ 	return NULL;
/*4623*/ }


/*4625*/ RECORD *
/*4625*/ Statements_ParsePackage(STRING *Statements_abs_pathfile, int Statements_module)
/*4625*/ {

/*4627*/ 	STRING *
/*4627*/ 	Statements_ShortLiteral(STRING *Statements_s)
/*4627*/ 	{
/*4627*/ 		if( (m2runtime_length(Statements_s) > 35) ){
/*4628*/ 			Statements_s = m2runtime_concat_STRING(0, m2runtime_substr(Statements_s, 0, 35, 1, Statements_0err_entry_get, 769), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"...", (STRING *) 1);
/*4630*/ 		}
/*4630*/ 		return m2runtime_StringToLiteral(Statements_s);
/*4634*/ 	}

/*4635*/ 	RECORD * Statements_package = NULL;
/*4636*/ 	STRING * Statements_saved_cwd = NULL;
/*4637*/ 	int Statements_code_found = 0;
/*4638*/ 	int Statements_i = 0;
/*4639*/ 	RECORD * Statements_f = NULL;
/*4640*/ 	RECORD * Statements_c = NULL;
/*4641*/ 	int Statements_res = 0;
/*4643*/ 	STRING * Statements_bom = NULL;
/*4643*/ 	Statements_package = Statements_SearchPackage(Statements_abs_pathfile);
/*4644*/ 	if( Statements_package != NULL ){
/*4645*/ 		return Statements_package;
/*4648*/ 	}
/*4648*/ 	if( !Statements_readable(Statements_abs_pathfile) ){
/*4649*/ 		Scanner_Error2(NULL, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"can't read `", Scanner_fmt_fn(Statements_abs_pathfile), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", m2runtime_ERROR_MESSAGE, (STRING *) 1));
/*4651*/ 		return NULL;
/*4654*/ 	}
/*4654*/ 	m2runtime_ERROR_CODE = 0;
/*4654*/ 	Statements_saved_cwd = io_GetCWD(1);
/*4655*/ 	switch( m2runtime_ERROR_CODE ){

/*4655*/ 	case 0:  break;
/*4655*/ 	default:
/*4655*/ 		m2runtime_HALT(Statements_0err_entry_get, 770, m2runtime_ERROR_MESSAGE);
/*4655*/ 	}
/*4655*/ 	m2runtime_ERROR_CODE = 0;
/*4655*/ 	io_ChDir(1, FileName_Dirname(Statements_abs_pathfile));
/*4657*/ 	switch( m2runtime_ERROR_CODE ){

/*4657*/ 	case 0:  break;
/*4657*/ 	default:
/*4657*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"can't move to the dir. of ", Statements_abs_pathfile, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", m2runtime_ERROR_MESSAGE, (STRING *) 1));
/*4659*/ 		return NULL;
/*4661*/ 	}
/*4661*/ 	if( !Scanner_Open(Statements_abs_pathfile) ){
/*4662*/ 		m2runtime_ERROR_CODE = 0;
/*4662*/ 		io_ChDir(1, Statements_saved_cwd);
/*4663*/ 		switch( m2runtime_ERROR_CODE ){

/*4663*/ 		case 0:  break;
/*4663*/ 		default:
/*4663*/ 			m2runtime_HALT(Statements_0err_entry_get, 771, m2runtime_ERROR_MESSAGE);
/*4663*/ 		}
/*4663*/ 		return NULL;
/*4666*/ 	}
/*4666*/ 	Statements_ParserInit();
/*4668*/ 	m2_inc(&Statements_recursion_level, 1);
/*4670*/ 	Globals_curr_package = NULL;
/*4671*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 772) = Statements_abs_pathfile;
/*4672*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 773) = Statements_module;
/*4673*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 6 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 774) = TRUE;
/*4681*/ 	*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_required_packages, sizeof(void *), 1, Statements_0err_entry_get, 775) = Globals_curr_package;
/*4683*/ 	if( (Scanner_sym == 3) ){
/*4684*/ 		if( Statements_module ){
/*4685*/ 			Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"Found leading text in file before opening PHP tag: ", Statements_ShortLiteral(Scanner_s), m2runtime_CHR(46), (STRING *) 1));
/*4687*/ 		} else if( m2_match(Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"^#!/[ -\377]+\012$") ){
/*4688*/ 			Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"Unix CGI executable script detected: ", Statements_ShortLiteral(Scanner_s), m2runtime_CHR(46), (STRING *) 1));
/*4691*/ 		} else {
/*4691*/ 			Statements_bom = Statements_DetectBOM(Scanner_s);
/*4692*/ 			if( Statements_bom == NULL ){
/*4693*/ 				Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"Bare textual content detected before PHP opening tag: ", Statements_ShortLiteral(Scanner_s), m2runtime_CHR(46), (STRING *) 1));
/*4696*/ 			} else {
/*4696*/ 				Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"Unicode ", Statements_bom, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)" BOM sequence detected: ", Statements_ShortLiteral(Scanner_s), m2runtime_CHR(46), (STRING *) 1));
/*4698*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"unsupported Unicode ", Statements_bom, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)" BOM sequence detected: ", Statements_ShortLiteral(Scanner_s), m2runtime_CHR(46), (STRING *) 1));
/*4702*/ 			}
/*4702*/ 		}
/*4702*/ 		Scanner_ReadSym();
/*4705*/ 	}
/*4705*/ 	while( (Scanner_sym != 0) ){
/*4706*/ 		if( (Scanner_sym == 4) ){
/*4707*/ 			Statements_code_found = TRUE;
/*4708*/ 			Statements_res = Statements_ParseCodeBlock();
/*4709*/ 			if( ((Statements_res & 8) != 0) ){
/*4712*/ 			}
/*4712*/ 		} else if( (Scanner_sym == 5) ){
/*4713*/ 			Statements_code_found = TRUE;
/*4714*/ 			Statements_ParseEchoBlock();
/*4715*/ 		} else if( (Scanner_sym == 3) ){
/*4716*/ 			Globals_CurrPackageNotLibrary(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"Bare textual content detected in ", Scanner_reference(Scanner_here()), m2runtime_CHR(46), (STRING *) 1));
/*4718*/ 			Scanner_ReadSym();
/*4720*/ 		} else {
/*4720*/ 			Scanner_UnexpectedSymbol();
/*4723*/ 		}
/*4723*/ 	}
/*4723*/ 	if( !Statements_code_found ){
/*4724*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"no PHP code found at all");
/*4727*/ 	}
/*4727*/ 	Namespace_ReportUnusedUseClauses();
/*4733*/ 	{
/*4733*/ 		int m2runtime_for_limit_1;
/*4733*/ 		Statements_i = 0;
/*4733*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_funcs) - 1);
/*4734*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*4734*/ 			Statements_f = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_funcs, Statements_i, Statements_0err_entry_get, 776);
/*4735*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_f, 10 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 777) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 778), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 779), Statements_abs_pathfile) == 0)) ){
/*4736*/ 				Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"missing function `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_f, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 780), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"()' declared forward in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_f, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 781)), (STRING *) 1));
/*4740*/ 			}
/*4745*/ 		}
/*4745*/ 	}
/*4745*/ 	{
/*4745*/ 		int m2runtime_for_limit_1;
/*4745*/ 		Statements_i = 0;
/*4745*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_classes) - 1);
/*4746*/ 		for( ; Statements_i <= m2runtime_for_limit_1; Statements_i += 1 ){
/*4746*/ 			Statements_c = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, Statements_i, Statements_0err_entry_get, 782);
/*4747*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD(Statements_c, 15 * sizeof(void*) + 3 * sizeof(int), Statements_0err_entry_get, 783) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 784), 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 785), Statements_abs_pathfile) == 0)) ){
/*4748*/ 				Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"missing class `", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_c, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 786), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' declared forward in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_c, 12 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 787)), (STRING *) 1));
/*4752*/ 			}
/*4753*/ 		}
/*4753*/ 	}
/*4753*/ 	Scanner_Close();
/*4754*/ 	m2runtime_ERROR_CODE = 0;
/*4754*/ 	io_ChDir(1, Statements_saved_cwd);
/*4755*/ 	switch( m2runtime_ERROR_CODE ){

/*4755*/ 	case 0:  break;
/*4755*/ 	default:
/*4755*/ 		m2runtime_HALT(Statements_0err_entry_get, 788, m2runtime_ERROR_MESSAGE);
/*4756*/ 	}
/*4756*/ 	if( (Globals_loop_level != 0) ){
/*4757*/ 		m2_error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"phplint: INTERNAL ERROR: loop_level=", m2runtime_itos(Globals_loop_level), m2runtime_CHR(10), (STRING *) 1));
/*4758*/ 		m2runtime_exit(1);
/*4761*/ 	}
/*4761*/ 	m2_inc(&Statements_recursion_level, -1);
/*4762*/ 	return Globals_curr_package;
/*4766*/ }


/*4768*/ void
/*4768*/ Statements_ParsePragma(void)
/*4768*/ {
/*4769*/ 	ARRAY * Statements_a = NULL;
/*4771*/ 	RECORD * Statements_where = NULL;
/*4771*/ 	Statements_where = Scanner_here();
/*4773*/ 	Scanner_ReadSym();
/*4774*/ 	while( (Scanner_sym == 131) ){
/*4775*/ 		*(STRING **)m2runtime_dereference_lhs_ARRAY_next(&Statements_a, sizeof(void *), 1, Statements_0err_entry_get, 789) = Scanner_s;
/*4776*/ 		Scanner_ReadSym();
/*4778*/ 	}
/*4778*/ 	if( (m2runtime_count(Statements_a) == 0) ){
/*4779*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\75,\0,\0,\0)"expected one or more pragma arguments in single quoted string");
/*4781*/ 	}
/*4781*/ 	Scanner_Expect(132, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `;'");
/*4782*/ 	Scanner_ReadSym();
/*4785*/ 	if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, 0, Statements_0err_entry_get, 790), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"autoload") == 0 ){
/*4786*/ 		if( ((Globals_curr_func == NULL) || (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 791), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__autoload") != 0)) ){
/*4787*/ 			Scanner_Error2(Statements_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"autoload pragma allowed only inside __autoload() magic function");
/*4789*/ 		}
/*4789*/ 		if( (m2runtime_count(Statements_a) == 1) ){
/*4790*/ 			Scanner_Error2(Statements_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"missing required arguments in autoload pragma");
/*4791*/ 		} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, 1, Statements_0err_entry_get, 792), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"schema1") == 0 ){
/*4792*/ 			if( (m2runtime_count(Statements_a) != 5) ){
/*4793*/ 				Scanner_Error2(Statements_where, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"expected 5 arguments for pragma autoload, but ", m2runtime_itos(m2runtime_count(Statements_a)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)" found", (STRING *) 1));
/*4795*/ 				return ;
/*4796*/ 			}
/*4796*/ 			if( Globals_autoload_prepend != NULL ){
/*4797*/ 				Scanner_Error2(Statements_where, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"pragma already set before");
/*4799*/ 				return ;
/*4800*/ 			}
/*4800*/ 			if( Globals_recursive_parsing ){
/*4801*/ 				Globals_autoload_prepend = m2runtime_concat_STRING(0, FileName_Absolute(NULL, (STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, 2, Statements_0err_entry_get, 793)), m2runtime_CHR(47), (STRING *) 1);
/*4802*/ 				Globals_autoload_separator = (STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, 3, Statements_0err_entry_get, 794);
/*4803*/ 				Globals_autoload_append = (STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, 4, Statements_0err_entry_get, 795);
/*4805*/ 			} else {
/*4805*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"recursive parsing disabled by --no-recursive option");
/*4808*/ 			}
/*4808*/ 		} else {
/*4808*/ 			Scanner_Error2(Statements_where, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"undefined autoload schema: ", (STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, 1, Statements_0err_entry_get, 796), (STRING *) 1));
/*4811*/ 		}
/*4811*/ 	} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, 0, Statements_0err_entry_get, 797), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"error_throws_exception") == 0 ){
/*4812*/ 		Errors_ParseErrorThrowsExceptionPragma(Statements_where, Statements_a);
/*4815*/ 	} else {
/*4815*/ 		Scanner_Error2(Statements_where, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"unknown pragma: ", (STRING *)m2runtime_dereference_rhs_ARRAY(Statements_a, 0, Statements_0err_entry_get, 798), (STRING *) 1));
/*4818*/ 	}
/*4820*/ }

/*4823*/ int Statements_skip_else_php_ver = 0;

/*4831*/ int
/*4831*/ Statements_ForwardParseStatement(void)
/*4831*/ {

/*4848*/ 	void
/*4848*/ 	Statements_ParseSimpleStatementBeginningWithVar(int Statements_private, RECORD *Statements_t)
/*4848*/ 	{
/*4849*/ 		RECORD * Statements_v = NULL;
/*4850*/ 		RECORD * Statements_r = NULL;
/*4852*/ 		STRING * Statements_vn = NULL;
/*4853*/ 		if( (((Statements_private || (Statements_t != NULL) || (Statements_pdb != NULL))) && (m2runtime_strcmp(Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"GLOBALS") == 0)) ){
/*4855*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\260,\0,\0,\0)"defining private attribute or type for $GLOBALS[] variables not supported (PHPLint limitation). Global variables can be declared in global scope in usual way `$varName = EXPR'.");
/*4858*/ 		}
/*4858*/ 		if( Statements_pdb != NULL ){
/*4859*/ 			Statements_DocBlockCheckAllowedLineTags((1024 | 128), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"variable");
/*4860*/ 			Statements_private = (Statements_private ||  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 4 * sizeof(int), Statements_0err_entry_get, 799));
/*4862*/ 			if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 800) != NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 801), 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 802) != 6))) ){
/*4864*/ 				Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 803);
/*4867*/ 			}
/*4867*/ 			if( (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 804) != NULL ){
/*4868*/ 				if( m2runtime_strcmp(Scanner_s, (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 805)) != 0 ){
/*4869*/ 					Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"the name of the assigned variable `$", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"' does not match `$", (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 806), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"' as indicated in @global", (STRING *) 1));
/*4873*/ 				}
/*4873*/ 				if( Statements_t == NULL ){
/*4874*/ 					Statements_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 1 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 807);
/*4876*/ 				}
/*4876*/ 				if( (Globals_scope > 0) ){
/*4877*/ 					Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"@global line in inner scope level, must be at global scope");
/*4880*/ 				}
/*4882*/ 			}
/*4887*/ 		}
/*4887*/ 		if( (Statements_private || (Statements_t != NULL)) ){
/*4888*/ 			Statements_v = Search_SearchVar(Scanner_s);
/*4889*/ 			if( Statements_v == NULL ){
/*4890*/ 				Accounting_AccountVarLHS(Scanner_s, Statements_private);
/*4891*/ 				Statements_v = Search_SearchVar(Scanner_s);
/*4892*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 808) = Statements_t;
/*4893*/ 				*(int *)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 809) = Statements_private;
/*4896*/ 			}
/*4897*/ 		}
/*4897*/ 		Statements_vn = Scanner_s;
/*4898*/ 		Statements_r = Expressions_ParseExpr();
/*4899*/ 		Scanner_Expect(17, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `;'");
/*4900*/ 		Scanner_ReadSym();
/*4905*/ 		if( (((Scanner_sym == 183)) || (Statements_pdb != NULL)) ){
/*4906*/ 			if( Statements_v == NULL ){
/*4907*/ 				Statements_v = Search_SearchVar(Statements_vn);
/*4909*/ 			}
/*4909*/ 			if( Statements_v == NULL ){
/*4910*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"can't apply documentation to unknown variable `$", Statements_vn, m2runtime_CHR(39), (STRING *) 1));
/*4913*/ 			} else if( (Scanner_sym == 183) ){
/*4914*/ 				*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 810) = Scanner_s;
/*4915*/ 				*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 811) = Documentator_ExtractDeprecated(Scanner_s);
/*4916*/ 				Scanner_ReadSym();
/*4918*/ 			} else if( Statements_pdb != NULL ){
/*4919*/ 				*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 5 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 812) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 813);
/*4920*/ 				*(STRING **)m2runtime_dereference_lhs_RECORD(&Statements_v, 7 * sizeof(void*) + 7 * sizeof(int), 7, 6 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 814) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 815));
/*4922*/ 			}
/*4922*/ 			Statements_pdb = NULL;
/*4926*/ 		}
/*4928*/ 	}


/*4930*/ 	void
/*4930*/ 	Statements_ParseGlobalStatement(void)
/*4930*/ 	{
/*4930*/ 		if( (Globals_scope == 0) ){
/*4931*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"`global' declaration at global scope has no effect.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)" Accounting variables as mixed type, and continuing anyway.", (STRING *) 1));
/*4934*/ 		}
/*4934*/ 		Scanner_ReadSym();
/*4936*/ 		do{
/*4936*/ 			Scanner_Expect(20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"expected variable name in global declaration");
/*4937*/ 			if( (Globals_scope == 0) ){
/*4938*/ 				Accounting_AccountVarLHS(Scanner_s, FALSE);
/*4940*/ 			} else {
/*4940*/ 				Accounting_AccountGlobalVar(Scanner_s);
/*4942*/ 			}
/*4942*/ 			Scanner_ReadSym();
/*4943*/ 			if( (Scanner_sym == 16) ){
/*4944*/ 				Scanner_ReadSym();
/*4947*/ 			} else {
/*4948*/ 				goto m2runtime_loop_1;
/*4949*/ 			}
/*4950*/ 		}while(TRUE);
m2runtime_loop_1: ;
/*4952*/ 	}


/*4959*/ 	void
/*4959*/ 	Statements_ParseStatementTerminator(void)
/*4959*/ 	{
/*4959*/ 		if( (Scanner_sym == 17) ){
/*4960*/ 			Scanner_ReadSym();
/*4961*/ 		} else if( (((Scanner_sym == 6)) || ((Scanner_sym == 0))) ){
/*4964*/ 		} else {
/*4964*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"missing statement terminator `;' or `?>'");
/*4967*/ 		}
/*4970*/ 	}

/*4971*/ 	int Statements_private = 0;
/*4972*/ 	RECORD * Statements_r = NULL;
/*4973*/ 	RECORD * Statements_t = NULL;
/*4976*/ 	int Statements_res = 0;
/*4977*/ 	switch(Scanner_sym){

/*4979*/ 	case 10:
/*4980*/ 	return Statements_ParseCompound();
/*4982*/ 	break;

/*4982*/ 	case 127:
/*4983*/ 	Statements_ParseNamespace();
/*4984*/ 	return 1;
/*4986*/ 	break;

/*4986*/ 	case 128:
/*4987*/ 	Statements_ParseUse();
/*4988*/ 	return 1;
/*4990*/ 	break;

/*4990*/ 	case 130:
/*4991*/ 	Statements_ParseRequireModule();
/*4992*/ 	return 1;
/*4994*/ 	break;

/*4994*/ 	case 126:
/*4995*/ 	Statements_ParseRequireOnce();
/*4996*/ 	Statements_ParseStatementTerminator();
/*4997*/ 	return 1;
/*4999*/ 	break;

/*4999*/ 	case 125:
/*5000*/ 	if( (Globals_scope > 0) ){
/*5001*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"`require' inside a function. Suggest `require_once' instead");
/*5003*/ 	}
/*5003*/ 	Statements_ParseInclude((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"require");
/*5004*/ 	Statements_ParseStatementTerminator();
/*5005*/ 	return 1;
/*5007*/ 	break;

/*5007*/ 	case 123:
/*5008*/ 	if( (Globals_scope > 0) ){
/*5009*/ 		Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"include() inside a function. Suggest include_once() instead");
/*5011*/ 	}
/*5011*/ 	Statements_ParseInclude((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"include");
/*5012*/ 	Statements_ParseStatementTerminator();
/*5013*/ 	return 1;
/*5015*/ 	break;

/*5015*/ 	case 124:
/*5016*/ 	Statements_ParseInclude((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"include_once");
/*5017*/ 	Statements_ParseStatementTerminator();
/*5018*/ 	return 1;
/*5020*/ 	break;

/*5020*/ 	case 183:
/*5021*/ 	if( (Globals_scope > 0) ){
/*5022*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"invalid scope for documentation");
/*5024*/ 	}
/*5024*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 816) = Scanner_s;
/*5025*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 817) = Documentator_ExtractDeprecated(Scanner_s);
/*5026*/ 	Scanner_ReadSym();
/*5027*/ 	return 1;
/*5029*/ 	break;

/*5029*/ 	case 184:
/*5030*/ 	if( (Globals_scope > 0) ){
/*5031*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"invalid scope for documentation");
/*5033*/ 	}
/*5033*/ 	Statements_pdb = ParseDocBlock_ParseDocBlock(Scanner_s);
/*5037*/ 	if( ((Statements_pdb != NULL) &&  *(int *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 8 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 818)) ){
/*5039*/ 		Statements_DocBlockCheckAllowedLineTags(1, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"package");
/*5040*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 2 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 819) = (STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 820);
/*5041*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Globals_curr_package, 6 * sizeof(void*) + 5 * sizeof(int), 6, 3 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 821) = Documentator_ExtractDeprecated((STRING *)m2runtime_dereference_rhs_RECORD(Statements_pdb, 0 * sizeof(void*) + 2 * sizeof(int), Statements_0err_entry_get, 822));
/*5042*/ 		Statements_pdb = NULL;
/*5046*/ 	} else {
/*5046*/ 	}
/*5046*/ 	Scanner_ReadSym();
/*5047*/ 	return 1;
/*5049*/ 	break;

/*5049*/ 	case 136:
/*5050*/ 	if( Statements_pdb != NULL ){
/*5051*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"unexpected DocBlock for forward declaration");
/*5053*/ 	}
/*5053*/ 	Proto_ParseForwardDecl();
/*5054*/ 	return 1;
/*5056*/ 	break;

/*5056*/ 	case 163:
/*5057*/ 	Statements_ParsePragma();
/*5058*/ 	return 1;
/*5060*/ 	break;

/*5060*/ 	case 164:
/*5061*/ 	if( (Globals_php_ver == 4) ){
/*5062*/ 		Statements_skip_else_php_ver = TRUE;
/*5063*/ 		Scanner_ReadSym();
/*5065*/ 	} else {
/*5065*/ 		Statements_skip_else_php_ver = FALSE;
/*5067*/ 		do{
/*5067*/ 			Scanner_ReadSym();
/*5068*/ 			switch(Scanner_sym){

/*5070*/ 			case 166:
/*5071*/ 			Scanner_ReadSym();
/*5074*/ 			goto m2runtime_loop_1;
/*5074*/ 			break;

/*5074*/ 			case 167:
/*5075*/ 			Scanner_ReadSym();
/*5078*/ 			goto m2runtime_loop_1;
/*5078*/ 			break;

/*5078*/ 			case 0:
/*5079*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)"premature end of the file. Expected closing of `if_php_ver_4'.");
/*5082*/ 			break;
/*5085*/ 			}
/*5086*/ 		}while(TRUE);
m2runtime_loop_1: ;
/*5086*/ 	}
/*5086*/ 	return 1;
/*5088*/ 	break;

/*5088*/ 	case 165:
/*5089*/ 	if( (Globals_php_ver == 5) ){
/*5090*/ 		Statements_skip_else_php_ver = TRUE;
/*5091*/ 		Scanner_ReadSym();
/*5093*/ 	} else {
/*5093*/ 		Statements_skip_else_php_ver = FALSE;
/*5095*/ 		do{
/*5095*/ 			Scanner_ReadSym();
/*5096*/ 			switch(Scanner_sym){

/*5098*/ 			case 166:
/*5099*/ 			Scanner_ReadSym();
/*5102*/ 			goto m2runtime_loop_2;
/*5102*/ 			break;

/*5102*/ 			case 167:
/*5103*/ 			Scanner_ReadSym();
/*5106*/ 			goto m2runtime_loop_2;
/*5106*/ 			break;

/*5106*/ 			case 0:
/*5107*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)"premature end of the file. Expected closing of `if_php_ver_5'.");
/*5110*/ 			break;
/*5113*/ 			}
/*5114*/ 		}while(TRUE);
m2runtime_loop_2: ;
/*5114*/ 	}
/*5114*/ 	return 1;
/*5116*/ 	break;

/*5116*/ 	case 166:
/*5117*/ 	if( Statements_skip_else_php_ver ){
/*5118*/ 		Statements_skip_else_php_ver = FALSE;
/*5119*/ 		do {
/*5119*/ 			Scanner_ReadSym();
/*5120*/ 		} while( !( (((Scanner_sym == 167)) || ((Scanner_sym == 0))) ));
/*5121*/ 		if( (Scanner_sym == 167) ){
/*5122*/ 			Scanner_ReadSym();
/*5124*/ 		} else {
/*5124*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"missing closing `end_if_php_ver'");
/*5127*/ 		}
/*5127*/ 	} else {
/*5127*/ 		Scanner_ReadSym();
/*5129*/ 	}
/*5129*/ 	return 1;
/*5131*/ 	break;

/*5131*/ 	case 167:
/*5132*/ 	Scanner_ReadSym();
/*5133*/ 	return 1;
/*5135*/ 	break;

/*5135*/ 	case 7:
/*5136*/ 	Statements_ParseDefine(FALSE);
/*5137*/ 	return 1;
/*5139*/ 	break;

/*5139*/ 	case 96:
/*5140*/ 	Statements_ParseConst(FALSE);
/*5141*/ 	return 1;
/*5143*/ 	break;

/*5143*/ 	case 9:
/*5144*/ 	return Statements_ParseDeclare();
/*5146*/ 	break;

/*5146*/ 	case 101:
/*5147*/ 	Statements_ParseStatic();
/*5148*/ 	Statements_ParseStatementTerminator();
/*5149*/ 	return 1;
/*5151*/ 	break;

/*5151*/ 	case 62:
/*5152*/ 	Statements_ParseGlobalStatement();
/*5153*/ 	Statements_ParseStatementTerminator();
/*5154*/ 	return 1;
/*5156*/ 	break;

/*5156*/ 	case 114:
/*5157*/ 	Statements_ParseEcho();
/*5158*/ 	Statements_ParseStatementTerminator();
/*5159*/ 	return 1;
/*5161*/ 	break;

/*5161*/ 	case 116:
/*5162*/ 	Statements_ParseTriggerError();
/*5163*/ 	Statements_ParseStatementTerminator();
/*5164*/ 	return 1;
/*5166*/ 	break;

/*5166*/ 	case 29:
/*5166*/ 	case 59:
/*5166*/ 	case 108:
/*5166*/ 	case 115:
/*5166*/ 	case 103:
/*5167*/ 	case 104:
/*5167*/ 	case 12:
/*5167*/ 	case 52:
/*5167*/ 	case 53:
/*5167*/ 	case 105:
/*5167*/ 	case 122:
/*5168*/ 	Statements_r = Expressions_ParseExpr();
/*5169*/ 	Statements_ParseStatementTerminator();
/*5170*/ 	return 1;
/*5172*/ 	break;

/*5172*/ 	case 113:
/*5173*/ 	Expressions_ParseExit();
/*5174*/ 	Statements_ParseStatementTerminator();
/*5175*/ 	return 8;
/*5177*/ 	break;

/*5177*/ 	case 20:
/*5178*/ 	Statements_ParseSimpleStatementBeginningWithVar(FALSE, NULL);
/*5179*/ 	return 1;
/*5181*/ 	break;

/*5181*/ 	case 25:
/*5182*/ 	return Statements_ParseIf();
/*5184*/ 	break;

/*5184*/ 	case 21:
/*5185*/ 	return Statements_ParseFor();
/*5187*/ 	break;

/*5187*/ 	case 22:
/*5188*/ 	return Statements_ParseForeach();
/*5190*/ 	break;

/*5190*/ 	case 109:
/*5191*/ 	return Statements_ParseSwitch();
/*5193*/ 	break;

/*5193*/ 	case 111:
/*5194*/ 	Statements_ParseBreak();
/*5195*/ 	Statements_ParseStatementTerminator();
/*5196*/ 	return 2;
/*5198*/ 	break;

/*5198*/ 	case 93:
/*5198*/ 	case 173:
/*5198*/ 	case 175:
/*5198*/ 	case 91:
/*5198*/ 	case 102:
/*5198*/ 	case 143:
/*5199*/ 	Statements_ParseClass(FALSE);
/*5200*/ 	return 1;
/*5202*/ 	break;

/*5202*/ 	case 92:
/*5203*/ 	Statements_ParseInterface(FALSE);
/*5204*/ 	return 1;
/*5206*/ 	break;

/*5206*/ 	case 24:
/*5207*/ 	return Statements_ParseWhile();
/*5209*/ 	break;

/*5209*/ 	case 117:
/*5210*/ 	Statements_res = Statements_ParseDo();
/*5211*/ 	Statements_ParseStatementTerminator();
/*5212*/ 	return Statements_res;
/*5214*/ 	break;

/*5214*/ 	case 121:
/*5215*/ 	Statements_ParseContinue();
/*5216*/ 	Statements_ParseStatementTerminator();
/*5217*/ 	return 4;
/*5219*/ 	break;

/*5219*/ 	case 28:
/*5220*/ 	Statements_ParseReturn();
/*5221*/ 	Statements_ParseStatementTerminator();
/*5222*/ 	return 8;
/*5224*/ 	break;

/*5224*/ 	case 17:
/*5226*/ 	Statements_ParseStatementTerminator();
/*5227*/ 	return 1;
/*5229*/ 	break;

/*5229*/ 	case 8:
/*5230*/ 	Statements_ParseFuncDecl(FALSE, NULL);
/*5231*/ 	return 1;
/*5233*/ 	break;

/*5233*/ 	case 144:
/*5233*/ 	case 145:
/*5233*/ 	case 146:
/*5233*/ 	case 147:
/*5234*/ 	case 148:
/*5234*/ 	case 149:
/*5234*/ 	case 150:
/*5235*/ 	case 151:
/*5235*/ 	case 152:
/*5235*/ 	case 153:
/*5236*/ 	case 172:
/*5237*/ 	if( (Scanner_sym == 172) ){
/*5238*/ 		Statements_private = TRUE;
/*5239*/ 		Scanner_ReadSym();
/*5241*/ 	}
/*5241*/ 	if( (Scanner_sym == 7) ){
/*5242*/ 		Statements_ParseDefine(Statements_private);
/*5243*/ 		return 1;
/*5244*/ 	} else if( (Scanner_sym == 96) ){
/*5245*/ 		Statements_ParseConst(Statements_private);
/*5246*/ 		return 1;
/*5247*/ 	} else if( (((Scanner_sym == 93)) || ((Scanner_sym == 91)) || ((Scanner_sym == 102))) ){
/*5249*/ 		Statements_ParseClass(Statements_private);
/*5250*/ 		return 1;
/*5251*/ 	} else if( (Scanner_sym == 92) ){
/*5252*/ 		Statements_ParseInterface(TRUE);
/*5253*/ 		return 1;
/*5255*/ 	}
/*5255*/ 	Statements_t = Expressions_ParseType(FALSE);
/*5256*/ 	if( (Scanner_sym == 20) ){
/*5257*/ 		Statements_ParseSimpleStatementBeginningWithVar(Statements_private, Statements_t);
/*5258*/ 		return 1;
/*5259*/ 	} else if( (Scanner_sym == 8) ){
/*5260*/ 		Statements_ParseFuncDecl(Statements_private, Statements_t);
/*5261*/ 		return 1;
/*5263*/ 	} else {
/*5263*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"expected variable or `function' after type");
/*5266*/ 	}
/*5266*/ 	break;

/*5266*/ 	case 120:
/*5267*/ 	Statements_ParseThrow();
/*5268*/ 	Statements_ParseStatementTerminator();
/*5269*/ 	return 8;
/*5271*/ 	break;

/*5271*/ 	case 118:
/*5272*/ 	return Statements_ParseTry();
/*5274*/ 	break;

/*5274*/ 	case 6:
/*5275*/ 	Statements_ParseTextBlock();
/*5276*/ 	return 1;
/*5278*/ 	break;

/*5278*/ 	case 129:
/*5279*/ 	Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"goto: unimplemented statement -- trying to continue anyway");
/*5280*/ 	Scanner_ReadSym();
/*5281*/ 	Scanner_Expect(29, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"expected identifier after `goto'");
/*5282*/ 	Scanner_ReadSym();
/*5283*/ 	Scanner_Expect(17, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"expected `;'");
/*5284*/ 	Scanner_ReadSym();
/*5285*/ 	return 8;
/*5288*/ 	break;

/*5288*/ 	default:
/*5288*/ 	Scanner_UnexpectedSymbol();
/*5291*/ 	}
/*5291*/ 	if( (FALSE && ((Statements_ForwardParseStatement() == 0))) ){
/*5295*/ 	}
/*5295*/ 	m2runtime_missing_return(Statements_0err_entry_get, 823);
/*5295*/ 	return 0;
/*5298*/ }


char * Statements_0func[] = {
    "ParseEcho",
    "CheckFormalArgsByReference",
    "ParseReturn",
    "ParseTriggerError",
    "DocBlockCheckAllowedLineTags",
    "ParseStatement",
    "ParseNamespace",
    "ParseUse",
    "ParseBlock",
    "ParseArg",
    "ParseArgsListDecl",
    "SameSign",
    "CheckSpecialFunc",
    "CheckAutoloadSignature",
    "CheckCastSignature",
    "ParseFuncDecl",
    "inSet",
    "GrabAssignedVars",
    "SetAssignedVars",
    "IntersectAssignedVars",
    "isTrue",
    "isFalse",
    "ParseForeach",
    "checkLabel",
    "ParseSwitch",
    "ParseClassConstDecl",
    "ParseClassPropertyDecl",
    "CheckSpecialMethodSignature",
    "SameMethodSignature",
    "ParentConstructor",
    "ParentDestructor",
    "ParseClassMethodDecl",
    "CheckForwardAttribute",
    "ParseClass",
    "ParseInterface",
    "ParseStatic",
    "ParseDefine",
    "ParseConst",
    "readable",
    "AddPackageToIncludePath",
    "SearchFileOnPaths",
    "SearchPackage",
    "RequirePackage",
    "ParseRequireOnce",
    "ParseInclude",
    "ParseThrow",
    "ParseTry",
    "ParseEchoBlock",
    "ParseCodeBlock",
    "addVar",
    "addConst",
    "DetectBOM",
    "ShortLiteral",
    "ParsePackage",
    "ParsePragma",
    "ParseSimpleStatementBeginningWithVar",
    "ForwardParseStatement"
};

int Statements_0err_entry[] = {
    0 /* ParseEcho */, 117,
    1 /* CheckFormalArgsByReference */, 156,
    1 /* CheckFormalArgsByReference */, 160,
    1 /* CheckFormalArgsByReference */, 160,
    1 /* CheckFormalArgsByReference */, 161,
    1 /* CheckFormalArgsByReference */, 163,
    1 /* CheckFormalArgsByReference */, 163,
    1 /* CheckFormalArgsByReference */, 164,
    1 /* CheckFormalArgsByReference */, 169,
    1 /* CheckFormalArgsByReference */, 174,
    1 /* CheckFormalArgsByReference */, 174,
    1 /* CheckFormalArgsByReference */, 175,
    1 /* CheckFormalArgsByReference */, 178,
    2 /* ParseReturn */, 199,
    2 /* ParseReturn */, 200,
    2 /* ParseReturn */, 201,
    2 /* ParseReturn */, 203,
    2 /* ParseReturn */, 204,
    2 /* ParseReturn */, 223,
    2 /* ParseReturn */, 227,
    2 /* ParseReturn */, 236,
    2 /* ParseReturn */, 240,
    2 /* ParseReturn */, 244,
    2 /* ParseReturn */, 269,
    3 /* ParseTriggerError */, 302,
    3 /* ParseTriggerError */, 306,
    3 /* ParseTriggerError */, 311,
    4 /* DocBlockCheckAllowedLineTags */, 357,
    4 /* DocBlockCheckAllowedLineTags */, 360,
    4 /* DocBlockCheckAllowedLineTags */, 363,
    4 /* DocBlockCheckAllowedLineTags */, 366,
    4 /* DocBlockCheckAllowedLineTags */, 369,
    4 /* DocBlockCheckAllowedLineTags */, 372,
    4 /* DocBlockCheckAllowedLineTags */, 375,
    4 /* DocBlockCheckAllowedLineTags */, 378,
    4 /* DocBlockCheckAllowedLineTags */, 381,
    4 /* DocBlockCheckAllowedLineTags */, 384,
    4 /* DocBlockCheckAllowedLineTags */, 387,
    4 /* DocBlockCheckAllowedLineTags */, 390,
    5 /* ParseStatement */, 409,
    6 /* ParseNamespace */, 426,
    6 /* ParseNamespace */, 427,
    6 /* ParseNamespace */, 433,
    6 /* ParseNamespace */, 434,
    6 /* ParseNamespace */, 439,
    6 /* ParseNamespace */, 440,
    6 /* ParseNamespace */, 452,
    6 /* ParseNamespace */, 453,
    7 /* ParseUse */, 479,
    8 /* ParseBlock */, 518,
    9 /* ParseArg */, 538,
    9 /* ParseArg */, 545,
    9 /* ParseArg */, 546,
    9 /* ParseArg */, 554,
    9 /* ParseArg */, 557,
    9 /* ParseArg */, 559,
    9 /* ParseArg */, 567,
    9 /* ParseArg */, 575,
    9 /* ParseArg */, 577,
    9 /* ParseArg */, 577,
    9 /* ParseArg */, 583,
    9 /* ParseArg */, 583,
    9 /* ParseArg */, 589,
    9 /* ParseArg */, 589,
    9 /* ParseArg */, 598,
    9 /* ParseArg */, 612,
    9 /* ParseArg */, 613,
    9 /* ParseArg */, 614,
    9 /* ParseArg */, 616,
    9 /* ParseArg */, 618,
    9 /* ParseArg */, 619,
    9 /* ParseArg */, 626,
    9 /* ParseArg */, 628,
    9 /* ParseArg */, 629,
    9 /* ParseArg */, 636,
    9 /* ParseArg */, 637,
    9 /* ParseArg */, 637,
    9 /* ParseArg */, 638,
    9 /* ParseArg */, 638,
    9 /* ParseArg */, 640,
    9 /* ParseArg */, 640,
    9 /* ParseArg */, 643,
    9 /* ParseArg */, 644,
    9 /* ParseArg */, 647,
    9 /* ParseArg */, 648,
    9 /* ParseArg */, 651,
    9 /* ParseArg */, 651,
    9 /* ParseArg */, 654,
    9 /* ParseArg */, 658,
    9 /* ParseArg */, 659,
    9 /* ParseArg */, 661,
    9 /* ParseArg */, 662,
    9 /* ParseArg */, 664,
    9 /* ParseArg */, 666,
    9 /* ParseArg */, 666,
    9 /* ParseArg */, 667,
    9 /* ParseArg */, 667,
    9 /* ParseArg */, 673,
    9 /* ParseArg */, 673,
    10 /* ParseArgsListDecl */, 700,
    10 /* ParseArgsListDecl */, 712,
    10 /* ParseArgsListDecl */, 712,
    10 /* ParseArgsListDecl */, 713,
    10 /* ParseArgsListDecl */, 714,
    10 /* ParseArgsListDecl */, 725,
    11 /* SameSign */, 746,
    11 /* SameSign */, 746,
    11 /* SameSign */, 747,
    11 /* SameSign */, 747,
    11 /* SameSign */, 751,
    11 /* SameSign */, 751,
    11 /* SameSign */, 754,
    11 /* SameSign */, 754,
    11 /* SameSign */, 757,
    11 /* SameSign */, 758,
    11 /* SameSign */, 758,
    11 /* SameSign */, 758,
    11 /* SameSign */, 758,
    11 /* SameSign */, 758,
    11 /* SameSign */, 758,
    11 /* SameSign */, 759,
    11 /* SameSign */, 759,
    11 /* SameSign */, 759,
    11 /* SameSign */, 759,
    11 /* SameSign */, 759,
    11 /* SameSign */, 759,
    11 /* SameSign */, 760,
    11 /* SameSign */, 760,
    11 /* SameSign */, 760,
    11 /* SameSign */, 760,
    11 /* SameSign */, 760,
    11 /* SameSign */, 760,
    12 /* CheckSpecialFunc */, 777,
    12 /* CheckSpecialFunc */, 779,
    12 /* CheckSpecialFunc */, 782,
    12 /* CheckSpecialFunc */, 782,
    12 /* CheckSpecialFunc */, 782,
    12 /* CheckSpecialFunc */, 783,
    12 /* CheckSpecialFunc */, 785,
    12 /* CheckSpecialFunc */, 791,
    13 /* CheckAutoloadSignature */, 802,
    13 /* CheckAutoloadSignature */, 805,
    13 /* CheckAutoloadSignature */, 807,
    14 /* CheckCastSignature */, 818,
    14 /* CheckCastSignature */, 821,
    14 /* CheckCastSignature */, 823,
    15 /* ParseFuncDecl */, 844,
    15 /* ParseFuncDecl */, 849,
    15 /* ParseFuncDecl */, 852,
    15 /* ParseFuncDecl */, 858,
    15 /* ParseFuncDecl */, 863,
    15 /* ParseFuncDecl */, 888,
    15 /* ParseFuncDecl */, 889,
    15 /* ParseFuncDecl */, 890,
    15 /* ParseFuncDecl */, 891,
    15 /* ParseFuncDecl */, 893,
    15 /* ParseFuncDecl */, 895,
    15 /* ParseFuncDecl */, 896,
    15 /* ParseFuncDecl */, 897,
    15 /* ParseFuncDecl */, 900,
    15 /* ParseFuncDecl */, 902,
    15 /* ParseFuncDecl */, 903,
    15 /* ParseFuncDecl */, 904,
    15 /* ParseFuncDecl */, 905,
    15 /* ParseFuncDecl */, 907,
    15 /* ParseFuncDecl */, 908,
    15 /* ParseFuncDecl */, 912,
    15 /* ParseFuncDecl */, 913,
    15 /* ParseFuncDecl */, 917,
    15 /* ParseFuncDecl */, 920,
    15 /* ParseFuncDecl */, 920,
    15 /* ParseFuncDecl */, 923,
    15 /* ParseFuncDecl */, 927,
    15 /* ParseFuncDecl */, 928,
    15 /* ParseFuncDecl */, 929,
    15 /* ParseFuncDecl */, 933,
    15 /* ParseFuncDecl */, 937,
    15 /* ParseFuncDecl */, 938,
    15 /* ParseFuncDecl */, 961,
    15 /* ParseFuncDecl */, 969,
    15 /* ParseFuncDecl */, 969,
    15 /* ParseFuncDecl */, 972,
    15 /* ParseFuncDecl */, 980,
    15 /* ParseFuncDecl */, 985,
    15 /* ParseFuncDecl */, 985,
    15 /* ParseFuncDecl */, 989,
    15 /* ParseFuncDecl */, 993,
    15 /* ParseFuncDecl */, 994,
    15 /* ParseFuncDecl */, 994,
    15 /* ParseFuncDecl */, 995,
    15 /* ParseFuncDecl */, 997,
    15 /* ParseFuncDecl */, 1009,
    15 /* ParseFuncDecl */, 1010,
    15 /* ParseFuncDecl */, 1013,
    15 /* ParseFuncDecl */, 1013,
    15 /* ParseFuncDecl */, 1014,
    15 /* ParseFuncDecl */, 1014,
    15 /* ParseFuncDecl */, 1023,
    15 /* ParseFuncDecl */, 1026,
    15 /* ParseFuncDecl */, 1027,
    15 /* ParseFuncDecl */, 1031,
    15 /* ParseFuncDecl */, 1033,
    15 /* ParseFuncDecl */, 1033,
    15 /* ParseFuncDecl */, 1042,
    15 /* ParseFuncDecl */, 1042,
    15 /* ParseFuncDecl */, 1046,
    15 /* ParseFuncDecl */, 1050,
    15 /* ParseFuncDecl */, 1052,
    15 /* ParseFuncDecl */, 1052,
    15 /* ParseFuncDecl */, 1058,
    15 /* ParseFuncDecl */, 1063,
    15 /* ParseFuncDecl */, 1063,
    15 /* ParseFuncDecl */, 1067,
    16 /* inSet */, 1135,
    16 /* inSet */, 1136,
    16 /* inSet */, 1136,
    16 /* inSet */, 1136,
    16 /* inSet */, 1136,
    16 /* inSet */, 1136,
    17 /* GrabAssignedVars */, 1189,
    17 /* GrabAssignedVars */, 1189,
    17 /* GrabAssignedVars */, 1192,
    17 /* GrabAssignedVars */, 1192,
    17 /* GrabAssignedVars */, 1197,
    17 /* GrabAssignedVars */, 1203,
    17 /* GrabAssignedVars */, 1203,
    17 /* GrabAssignedVars */, 1203,
    17 /* GrabAssignedVars */, 1203,
    18 /* SetAssignedVars */, 1218,
    18 /* SetAssignedVars */, 1219,
    18 /* SetAssignedVars */, 1224,
    18 /* SetAssignedVars */, 1224,
    18 /* SetAssignedVars */, 1227,
    18 /* SetAssignedVars */, 1227,
    18 /* SetAssignedVars */, 1233,
    18 /* SetAssignedVars */, 1233,
    18 /* SetAssignedVars */, 1233,
    18 /* SetAssignedVars */, 1234,
    18 /* SetAssignedVars */, 1238,
    18 /* SetAssignedVars */, 1238,
    19 /* IntersectAssignedVars */, 1255,
    19 /* IntersectAssignedVars */, 1255,
    19 /* IntersectAssignedVars */, 1256,
    19 /* IntersectAssignedVars */, 1256,
    19 /* IntersectAssignedVars */, 1256,
    19 /* IntersectAssignedVars */, 1256,
    19 /* IntersectAssignedVars */, 1270,
    19 /* IntersectAssignedVars */, 1272,
    19 /* IntersectAssignedVars */, 1272,
    20 /* isTrue */, 1302,
    20 /* isTrue */, 1302,
    21 /* isFalse */, 1308,
    21 /* isFalse */, 1308,
    22 /* ParseForeach */, 1524,
    22 /* ParseForeach */, 1524,
    22 /* ParseForeach */, 1525,
    22 /* ParseForeach */, 1525,
    22 /* ParseForeach */, 1530,
    22 /* ParseForeach */, 1531,
    22 /* ParseForeach */, 1531,
    22 /* ParseForeach */, 1532,
    22 /* ParseForeach */, 1532,
    22 /* ParseForeach */, 1535,
    22 /* ParseForeach */, 1535,
    22 /* ParseForeach */, 1537,
    22 /* ParseForeach */, 1537,
    22 /* ParseForeach */, 1539,
    22 /* ParseForeach */, 1539,
    22 /* ParseForeach */, 1540,
    22 /* ParseForeach */, 1540,
    22 /* ParseForeach */, 1542,
    22 /* ParseForeach */, 1542,
    22 /* ParseForeach */, 1543,
    22 /* ParseForeach */, 1543,
    22 /* ParseForeach */, 1545,
    22 /* ParseForeach */, 1545,
    22 /* ParseForeach */, 1546,
    22 /* ParseForeach */, 1546,
    22 /* ParseForeach */, 1547,
    22 /* ParseForeach */, 1547,
    22 /* ParseForeach */, 1547,
    22 /* ParseForeach */, 1551,
    22 /* ParseForeach */, 1551,
    22 /* ParseForeach */, 1554,
    22 /* ParseForeach */, 1554,
    22 /* ParseForeach */, 1566,
    22 /* ParseForeach */, 1616,
    22 /* ParseForeach */, 1618,
    22 /* ParseForeach */, 1621,
    22 /* ParseForeach */, 1624,
    22 /* ParseForeach */, 1625,
    22 /* ParseForeach */, 1628,
    22 /* ParseForeach */, 1629,
    22 /* ParseForeach */, 1631,
    22 /* ParseForeach */, 1644,
    22 /* ParseForeach */, 1645,
    22 /* ParseForeach */, 1647,
    22 /* ParseForeach */, 1650,
    22 /* ParseForeach */, 1651,
    22 /* ParseForeach */, 1655,
    22 /* ParseForeach */, 1656,
    22 /* ParseForeach */, 1659,
    23 /* checkLabel */, 1708,
    23 /* checkLabel */, 1708,
    23 /* checkLabel */, 1713,
    23 /* checkLabel */, 1713,
    23 /* checkLabel */, 1713,
    23 /* checkLabel */, 1713,
    23 /* checkLabel */, 1713,
    23 /* checkLabel */, 1713,
    23 /* checkLabel */, 1714,
    23 /* checkLabel */, 1717,
    24 /* ParseSwitch */, 1737,
    24 /* ParseSwitch */, 1763,
    24 /* ParseSwitch */, 1764,
    25 /* ParseClassConstDecl */, 1901,
    25 /* ParseClassConstDecl */, 1904,
    25 /* ParseClassConstDecl */, 1905,
    25 /* ParseClassConstDecl */, 1905,
    25 /* ParseClassConstDecl */, 1911,
    25 /* ParseClassConstDecl */, 1912,
    25 /* ParseClassConstDecl */, 1912,
    25 /* ParseClassConstDecl */, 1915,
    25 /* ParseClassConstDecl */, 1916,
    25 /* ParseClassConstDecl */, 1916,
    25 /* ParseClassConstDecl */, 1919,
    25 /* ParseClassConstDecl */, 1920,
    25 /* ParseClassConstDecl */, 1921,
    25 /* ParseClassConstDecl */, 1923,
    25 /* ParseClassConstDecl */, 1932,
    25 /* ParseClassConstDecl */, 1932,
    25 /* ParseClassConstDecl */, 1935,
    25 /* ParseClassConstDecl */, 1952,
    25 /* ParseClassConstDecl */, 1953,
    25 /* ParseClassConstDecl */, 1956,
    25 /* ParseClassConstDecl */, 1956,
    25 /* ParseClassConstDecl */, 1957,
    25 /* ParseClassConstDecl */, 1957,
    26 /* ParseClassPropertyDecl */, 1992,
    26 /* ParseClassPropertyDecl */, 1997,
    26 /* ParseClassPropertyDecl */, 1999,
    26 /* ParseClassPropertyDecl */, 2002,
    26 /* ParseClassPropertyDecl */, 2004,
    26 /* ParseClassPropertyDecl */, 2006,
    26 /* ParseClassPropertyDecl */, 2008,
    26 /* ParseClassPropertyDecl */, 2018,
    26 /* ParseClassPropertyDecl */, 2019,
    26 /* ParseClassPropertyDecl */, 2022,
    26 /* ParseClassPropertyDecl */, 2022,
    26 /* ParseClassPropertyDecl */, 2023,
    26 /* ParseClassPropertyDecl */, 2023,
    26 /* ParseClassPropertyDecl */, 2026,
    26 /* ParseClassPropertyDecl */, 2026,
    26 /* ParseClassPropertyDecl */, 2029,
    26 /* ParseClassPropertyDecl */, 2030,
    26 /* ParseClassPropertyDecl */, 2031,
    26 /* ParseClassPropertyDecl */, 2033,
    26 /* ParseClassPropertyDecl */, 2034,
    26 /* ParseClassPropertyDecl */, 2035,
    26 /* ParseClassPropertyDecl */, 2036,
    26 /* ParseClassPropertyDecl */, 2037,
    26 /* ParseClassPropertyDecl */, 2037,
    26 /* ParseClassPropertyDecl */, 2040,
    26 /* ParseClassPropertyDecl */, 2042,
    26 /* ParseClassPropertyDecl */, 2043,
    26 /* ParseClassPropertyDecl */, 2047,
    26 /* ParseClassPropertyDecl */, 2052,
    26 /* ParseClassPropertyDecl */, 2052,
    26 /* ParseClassPropertyDecl */, 2071,
    26 /* ParseClassPropertyDecl */, 2072,
    26 /* ParseClassPropertyDecl */, 2075,
    26 /* ParseClassPropertyDecl */, 2075,
    26 /* ParseClassPropertyDecl */, 2076,
    26 /* ParseClassPropertyDecl */, 2076,
    27 /* CheckSpecialMethodSignature */, 2093,
    27 /* CheckSpecialMethodSignature */, 2093,
    27 /* CheckSpecialMethodSignature */, 2093,
    27 /* CheckSpecialMethodSignature */, 2133,
    27 /* CheckSpecialMethodSignature */, 2133,
    27 /* CheckSpecialMethodSignature */, 2133,
    27 /* CheckSpecialMethodSignature */, 2134,
    27 /* CheckSpecialMethodSignature */, 2134,
    27 /* CheckSpecialMethodSignature */, 2134,
    27 /* CheckSpecialMethodSignature */, 2135,
    27 /* CheckSpecialMethodSignature */, 2136,
    27 /* CheckSpecialMethodSignature */, 2136,
    27 /* CheckSpecialMethodSignature */, 2144,
    27 /* CheckSpecialMethodSignature */, 2144,
    27 /* CheckSpecialMethodSignature */, 2144,
    27 /* CheckSpecialMethodSignature */, 2145,
    27 /* CheckSpecialMethodSignature */, 2145,
    27 /* CheckSpecialMethodSignature */, 2153,
    27 /* CheckSpecialMethodSignature */, 2153,
    27 /* CheckSpecialMethodSignature */, 2154,
    27 /* CheckSpecialMethodSignature */, 2154,
    27 /* CheckSpecialMethodSignature */, 2154,
    27 /* CheckSpecialMethodSignature */, 2156,
    27 /* CheckSpecialMethodSignature */, 2156,
    27 /* CheckSpecialMethodSignature */, 2157,
    27 /* CheckSpecialMethodSignature */, 2157,
    27 /* CheckSpecialMethodSignature */, 2157,
    27 /* CheckSpecialMethodSignature */, 2162,
    27 /* CheckSpecialMethodSignature */, 2164,
    27 /* CheckSpecialMethodSignature */, 2166,
    27 /* CheckSpecialMethodSignature */, 2171,
    27 /* CheckSpecialMethodSignature */, 2171,
    27 /* CheckSpecialMethodSignature */, 2172,
    27 /* CheckSpecialMethodSignature */, 2172,
    27 /* CheckSpecialMethodSignature */, 2174,
    27 /* CheckSpecialMethodSignature */, 2174,
    28 /* SameMethodSignature */, 2181,
    28 /* SameMethodSignature */, 2181,
    28 /* SameMethodSignature */, 2182,
    28 /* SameMethodSignature */, 2182,
    28 /* SameMethodSignature */, 2183,
    28 /* SameMethodSignature */, 2183,
    28 /* SameMethodSignature */, 2184,
    28 /* SameMethodSignature */, 2184,
    29 /* ParentConstructor */, 2207,
    29 /* ParentConstructor */, 2208,
    29 /* ParentConstructor */, 2209,
    30 /* ParentDestructor */, 2220,
    30 /* ParentDestructor */, 2221,
    30 /* ParentDestructor */, 2222,
    31 /* ParseClassMethodDecl */, 2249,
    31 /* ParseClassMethodDecl */, 2260,
    31 /* ParseClassMethodDecl */, 2296,
    31 /* ParseClassMethodDecl */, 2302,
    31 /* ParseClassMethodDecl */, 2304,
    31 /* ParseClassMethodDecl */, 2305,
    31 /* ParseClassMethodDecl */, 2306,
    31 /* ParseClassMethodDecl */, 2307,
    31 /* ParseClassMethodDecl */, 2315,
    31 /* ParseClassMethodDecl */, 2334,
    31 /* ParseClassMethodDecl */, 2334,
    31 /* ParseClassMethodDecl */, 2335,
    31 /* ParseClassMethodDecl */, 2338,
    31 /* ParseClassMethodDecl */, 2339,
    31 /* ParseClassMethodDecl */, 2341,
    31 /* ParseClassMethodDecl */, 2342,
    31 /* ParseClassMethodDecl */, 2349,
    31 /* ParseClassMethodDecl */, 2350,
    31 /* ParseClassMethodDecl */, 2351,
    31 /* ParseClassMethodDecl */, 2351,
    31 /* ParseClassMethodDecl */, 2357,
    31 /* ParseClassMethodDecl */, 2360,
    31 /* ParseClassMethodDecl */, 2360,
    31 /* ParseClassMethodDecl */, 2362,
    31 /* ParseClassMethodDecl */, 2367,
    31 /* ParseClassMethodDecl */, 2367,
    31 /* ParseClassMethodDecl */, 2368,
    31 /* ParseClassMethodDecl */, 2385,
    31 /* ParseClassMethodDecl */, 2386,
    31 /* ParseClassMethodDecl */, 2392,
    31 /* ParseClassMethodDecl */, 2395,
    31 /* ParseClassMethodDecl */, 2408,
    31 /* ParseClassMethodDecl */, 2409,
    31 /* ParseClassMethodDecl */, 2409,
    31 /* ParseClassMethodDecl */, 2434,
    31 /* ParseClassMethodDecl */, 2435,
    31 /* ParseClassMethodDecl */, 2437,
    31 /* ParseClassMethodDecl */, 2439,
    31 /* ParseClassMethodDecl */, 2439,
    31 /* ParseClassMethodDecl */, 2440,
    31 /* ParseClassMethodDecl */, 2443,
    31 /* ParseClassMethodDecl */, 2451,
    31 /* ParseClassMethodDecl */, 2459,
    31 /* ParseClassMethodDecl */, 2459,
    31 /* ParseClassMethodDecl */, 2469,
    31 /* ParseClassMethodDecl */, 2476,
    31 /* ParseClassMethodDecl */, 2477,
    31 /* ParseClassMethodDecl */, 2482,
    31 /* ParseClassMethodDecl */, 2482,
    31 /* ParseClassMethodDecl */, 2484,
    31 /* ParseClassMethodDecl */, 2486,
    31 /* ParseClassMethodDecl */, 2490,
    31 /* ParseClassMethodDecl */, 2491,
    31 /* ParseClassMethodDecl */, 2491,
    31 /* ParseClassMethodDecl */, 2492,
    31 /* ParseClassMethodDecl */, 2494,
    31 /* ParseClassMethodDecl */, 2506,
    31 /* ParseClassMethodDecl */, 2507,
    31 /* ParseClassMethodDecl */, 2510,
    31 /* ParseClassMethodDecl */, 2510,
    31 /* ParseClassMethodDecl */, 2511,
    31 /* ParseClassMethodDecl */, 2511,
    31 /* ParseClassMethodDecl */, 2519,
    31 /* ParseClassMethodDecl */, 2519,
    31 /* ParseClassMethodDecl */, 2523,
    31 /* ParseClassMethodDecl */, 2523,
    31 /* ParseClassMethodDecl */, 2526,
    31 /* ParseClassMethodDecl */, 2526,
    31 /* ParseClassMethodDecl */, 2529,
    31 /* ParseClassMethodDecl */, 2529,
    31 /* ParseClassMethodDecl */, 2529,
    31 /* ParseClassMethodDecl */, 2530,
    31 /* ParseClassMethodDecl */, 2532,
    31 /* ParseClassMethodDecl */, 2534,
    31 /* ParseClassMethodDecl */, 2534,
    31 /* ParseClassMethodDecl */, 2538,
    31 /* ParseClassMethodDecl */, 2561,
    31 /* ParseClassMethodDecl */, 2564,
    31 /* ParseClassMethodDecl */, 2565,
    31 /* ParseClassMethodDecl */, 2568,
    31 /* ParseClassMethodDecl */, 2568,
    31 /* ParseClassMethodDecl */, 2583,
    31 /* ParseClassMethodDecl */, 2600,
    31 /* ParseClassMethodDecl */, 2600,
    31 /* ParseClassMethodDecl */, 2601,
    31 /* ParseClassMethodDecl */, 2605,
    31 /* ParseClassMethodDecl */, 2607,
    31 /* ParseClassMethodDecl */, 2607,
    31 /* ParseClassMethodDecl */, 2615,
    31 /* ParseClassMethodDecl */, 2617,
    31 /* ParseClassMethodDecl */, 2617,
    31 /* ParseClassMethodDecl */, 2617,
    31 /* ParseClassMethodDecl */, 2625,
    31 /* ParseClassMethodDecl */, 2627,
    31 /* ParseClassMethodDecl */, 2627,
    31 /* ParseClassMethodDecl */, 2627,
    31 /* ParseClassMethodDecl */, 2637,
    31 /* ParseClassMethodDecl */, 2640,
    31 /* ParseClassMethodDecl */, 2675,
    31 /* ParseClassMethodDecl */, 2678,
    31 /* ParseClassMethodDecl */, 2684,
    31 /* ParseClassMethodDecl */, 2694,
    31 /* ParseClassMethodDecl */, 2695,
    31 /* ParseClassMethodDecl */, 2700,
    31 /* ParseClassMethodDecl */, 2702,
    31 /* ParseClassMethodDecl */, 2707,
    32 /* CheckForwardAttribute */, 2732,
    32 /* CheckForwardAttribute */, 2734,
    33 /* ParseClass */, 2771,
    33 /* ParseClass */, 2774,
    33 /* ParseClass */, 2780,
    33 /* ParseClass */, 2780,
    33 /* ParseClass */, 2781,
    33 /* ParseClass */, 2781,
    33 /* ParseClass */, 2782,
    33 /* ParseClass */, 2782,
    33 /* ParseClass */, 2792,
    33 /* ParseClass */, 2795,
    33 /* ParseClass */, 2802,
    33 /* ParseClass */, 2805,
    33 /* ParseClass */, 2812,
    33 /* ParseClass */, 2815,
    33 /* ParseClass */, 2822,
    33 /* ParseClass */, 2825,
    33 /* ParseClass */, 2832,
    33 /* ParseClass */, 2835,
    33 /* ParseClass */, 2844,
    33 /* ParseClass */, 2844,
    33 /* ParseClass */, 2867,
    33 /* ParseClass */, 2869,
    33 /* ParseClass */, 2870,
    33 /* ParseClass */, 2879,
    33 /* ParseClass */, 2880,
    33 /* ParseClass */, 2881,
    33 /* ParseClass */, 2882,
    33 /* ParseClass */, 2884,
    33 /* ParseClass */, 2885,
    33 /* ParseClass */, 2885,
    33 /* ParseClass */, 2886,
    33 /* ParseClass */, 2886,
    33 /* ParseClass */, 2887,
    33 /* ParseClass */, 2887,
    33 /* ParseClass */, 2888,
    33 /* ParseClass */, 2888,
    33 /* ParseClass */, 2891,
    33 /* ParseClass */, 2892,
    33 /* ParseClass */, 2893,
    33 /* ParseClass */, 2893,
    33 /* ParseClass */, 2894,
    33 /* ParseClass */, 2899,
    33 /* ParseClass */, 2905,
    33 /* ParseClass */, 2928,
    33 /* ParseClass */, 2929,
    33 /* ParseClass */, 2930,
    33 /* ParseClass */, 2931,
    33 /* ParseClass */, 2932,
    33 /* ParseClass */, 2933,
    33 /* ParseClass */, 2936,
    33 /* ParseClass */, 2937,
    33 /* ParseClass */, 2939,
    33 /* ParseClass */, 2940,
    33 /* ParseClass */, 2940,
    33 /* ParseClass */, 2943,
    33 /* ParseClass */, 2945,
    33 /* ParseClass */, 2946,
    33 /* ParseClass */, 2947,
    33 /* ParseClass */, 2951,
    33 /* ParseClass */, 2957,
    33 /* ParseClass */, 2960,
    33 /* ParseClass */, 2962,
    33 /* ParseClass */, 2969,
    33 /* ParseClass */, 2984,
    33 /* ParseClass */, 2986,
    33 /* ParseClass */, 2986,
    33 /* ParseClass */, 2989,
    33 /* ParseClass */, 2991,
    33 /* ParseClass */, 2993,
    33 /* ParseClass */, 2993,
    33 /* ParseClass */, 2997,
    33 /* ParseClass */, 2999,
    33 /* ParseClass */, 2999,
    33 /* ParseClass */, 3012,
    33 /* ParseClass */, 3013,
    33 /* ParseClass */, 3013,
    33 /* ParseClass */, 3020,
    33 /* ParseClass */, 3030,
    33 /* ParseClass */, 3031,
    33 /* ParseClass */, 3034,
    33 /* ParseClass */, 3034,
    33 /* ParseClass */, 3035,
    33 /* ParseClass */, 3035,
    33 /* ParseClass */, 3069,
    33 /* ParseClass */, 3072,
    33 /* ParseClass */, 3075,
    33 /* ParseClass */, 3079,
    33 /* ParseClass */, 3080,
    33 /* ParseClass */, 3081,
    33 /* ParseClass */, 3206,
    33 /* ParseClass */, 3207,
    33 /* ParseClass */, 3208,
    33 /* ParseClass */, 3209,
    33 /* ParseClass */, 3214,
    33 /* ParseClass */, 3214,
    33 /* ParseClass */, 3287,
    33 /* ParseClass */, 3296,
    33 /* ParseClass */, 3309,
    33 /* ParseClass */, 3313,
    33 /* ParseClass */, 3314,
    33 /* ParseClass */, 3315,
    33 /* ParseClass */, 3315,
    33 /* ParseClass */, 3316,
    33 /* ParseClass */, 3317,
    34 /* ParseInterface */, 3345,
    34 /* ParseInterface */, 3349,
    34 /* ParseInterface */, 3350,
    34 /* ParseInterface */, 3351,
    34 /* ParseInterface */, 3353,
    34 /* ParseInterface */, 3365,
    34 /* ParseInterface */, 3366,
    34 /* ParseInterface */, 3367,
    34 /* ParseInterface */, 3369,
    34 /* ParseInterface */, 3372,
    34 /* ParseInterface */, 3375,
    34 /* ParseInterface */, 3381,
    34 /* ParseInterface */, 3382,
    34 /* ParseInterface */, 3383,
    34 /* ParseInterface */, 3384,
    34 /* ParseInterface */, 3401,
    34 /* ParseInterface */, 3402,
    34 /* ParseInterface */, 3403,
    34 /* ParseInterface */, 3406,
    34 /* ParseInterface */, 3408,
    34 /* ParseInterface */, 3410,
    34 /* ParseInterface */, 3410,
    34 /* ParseInterface */, 3412,
    34 /* ParseInterface */, 3414,
    34 /* ParseInterface */, 3414,
    34 /* ParseInterface */, 3432,
    34 /* ParseInterface */, 3433,
    34 /* ParseInterface */, 3436,
    34 /* ParseInterface */, 3436,
    34 /* ParseInterface */, 3437,
    34 /* ParseInterface */, 3437,
    34 /* ParseInterface */, 3456,
    34 /* ParseInterface */, 3456,
    34 /* ParseInterface */, 3456,
    34 /* ParseInterface */, 3459,
    34 /* ParseInterface */, 3462,
    34 /* ParseInterface */, 3499,
    35 /* ParseStatic */, 3551,
    35 /* ParseStatic */, 3559,
    35 /* ParseStatic */, 3573,
    35 /* ParseStatic */, 3573,
    35 /* ParseStatic */, 3575,
    35 /* ParseStatic */, 3578,
    35 /* ParseStatic */, 3583,
    35 /* ParseStatic */, 3595,
    36 /* ParseDefine */, 3702,
    36 /* ParseDefine */, 3705,
    36 /* ParseDefine */, 3721,
    36 /* ParseDefine */, 3725,
    36 /* ParseDefine */, 3772,
    36 /* ParseDefine */, 3773,
    36 /* ParseDefine */, 3775,
    36 /* ParseDefine */, 3775,
    36 /* ParseDefine */, 3776,
    36 /* ParseDefine */, 3776,
    36 /* ParseDefine */, 3777,
    36 /* ParseDefine */, 3777,
    37 /* ParseConst */, 3817,
    37 /* ParseConst */, 3821,
    37 /* ParseConst */, 3829,
    37 /* ParseConst */, 3829,
    37 /* ParseConst */, 3830,
    37 /* ParseConst */, 3830,
    37 /* ParseConst */, 3831,
    37 /* ParseConst */, 3831,
    37 /* ParseConst */, 3850,
    37 /* ParseConst */, 3851,
    38 /* readable */, 3914,
    38 /* readable */, 3919,
    39 /* AddPackageToIncludePath */, 3930,
    39 /* AddPackageToIncludePath */, 3934,
    40 /* SearchFileOnPaths */, 3964,
    41 /* SearchPackage */, 3996,
    41 /* SearchPackage */, 3996,
    41 /* SearchPackage */, 3998,
    42 /* RequirePackage */, 4080,
    42 /* RequirePackage */, 4082,
    42 /* RequirePackage */, 4085,
    42 /* RequirePackage */, 4092,
    43 /* ParseRequireOnce */, 4132,
    43 /* ParseRequireOnce */, 4141,
    43 /* ParseRequireOnce */, 4145,
    43 /* ParseRequireOnce */, 4148,
    43 /* ParseRequireOnce */, 4149,
    43 /* ParseRequireOnce */, 4157,
    44 /* ParseInclude */, 4170,
    44 /* ParseInclude */, 4172,
    44 /* ParseInclude */, 4174,
    44 /* ParseInclude */, 4175,
    44 /* ParseInclude */, 4178,
    45 /* ParseThrow */, 4195,
    45 /* ParseThrow */, 4196,
    45 /* ParseThrow */, 4197,
    45 /* ParseThrow */, 4199,
    45 /* ParseThrow */, 4200,
    45 /* ParseThrow */, 4203,
    45 /* ParseThrow */, 4203,
    45 /* ParseThrow */, 4211,
    46 /* ParseTry */, 4280,
    46 /* ParseTry */, 4345,
    46 /* ParseTry */, 4347,
    46 /* ParseTry */, 4348,
    46 /* ParseTry */, 4349,
    46 /* ParseTry */, 4350,
    46 /* ParseTry */, 4351,
    46 /* ParseTry */, 4364,
    46 /* ParseTry */, 4366,
    46 /* ParseTry */, 4366,
    46 /* ParseTry */, 4375,
    46 /* ParseTry */, 4376,
    47 /* ParseEchoBlock */, 4406,
    48 /* ParseCodeBlock */, 4480,
    49 /* addVar */, 4497,
    49 /* addVar */, 4498,
    49 /* addVar */, 4499,
    49 /* addVar */, 4500,
    49 /* addVar */, 4501,
    49 /* addVar */, 4502,
    49 /* addVar */, 4503,
    49 /* addVar */, 4504,
    49 /* addVar */, 4505,
    50 /* addConst */, 4517,
    50 /* addConst */, 4518,
    50 /* addConst */, 4519,
    50 /* addConst */, 4520,
    50 /* addConst */, 4521,
    50 /* addConst */, 4522,
    50 /* addConst */, 4523,
    50 /* addConst */, 4524,
    51 /* DetectBOM */, 4614,
    51 /* DetectBOM */, 4614,
    51 /* DetectBOM */, 4615,
    51 /* DetectBOM */, 4615,
    52 /* ShortLiteral */, 4628,
    53 /* ParsePackage */, 4654,
    53 /* ParsePackage */, 4662,
    53 /* ParsePackage */, 4671,
    53 /* ParsePackage */, 4672,
    53 /* ParsePackage */, 4673,
    53 /* ParsePackage */, 4681,
    53 /* ParsePackage */, 4735,
    53 /* ParsePackage */, 4735,
    53 /* ParsePackage */, 4735,
    53 /* ParsePackage */, 4735,
    53 /* ParsePackage */, 4736,
    53 /* ParsePackage */, 4737,
    53 /* ParsePackage */, 4747,
    53 /* ParsePackage */, 4747,
    53 /* ParsePackage */, 4747,
    53 /* ParsePackage */, 4747,
    53 /* ParsePackage */, 4748,
    53 /* ParsePackage */, 4749,
    53 /* ParsePackage */, 4754,
    54 /* ParsePragma */, 4775,
    54 /* ParsePragma */, 4785,
    54 /* ParsePragma */, 4786,
    54 /* ParsePragma */, 4791,
    54 /* ParsePragma */, 4801,
    54 /* ParsePragma */, 4803,
    54 /* ParsePragma */, 4804,
    54 /* ParsePragma */, 4808,
    54 /* ParsePragma */, 4811,
    54 /* ParsePragma */, 4815,
    55 /* ParseSimpleStatementBeginningWithVar */, 4860,
    55 /* ParseSimpleStatementBeginningWithVar */, 4862,
    55 /* ParseSimpleStatementBeginningWithVar */, 4863,
    55 /* ParseSimpleStatementBeginningWithVar */, 4863,
    55 /* ParseSimpleStatementBeginningWithVar */, 4864,
    55 /* ParseSimpleStatementBeginningWithVar */, 4867,
    55 /* ParseSimpleStatementBeginningWithVar */, 4868,
    55 /* ParseSimpleStatementBeginningWithVar */, 4871,
    55 /* ParseSimpleStatementBeginningWithVar */, 4874,
    55 /* ParseSimpleStatementBeginningWithVar */, 4892,
    55 /* ParseSimpleStatementBeginningWithVar */, 4893,
    55 /* ParseSimpleStatementBeginningWithVar */, 4914,
    55 /* ParseSimpleStatementBeginningWithVar */, 4915,
    55 /* ParseSimpleStatementBeginningWithVar */, 4919,
    55 /* ParseSimpleStatementBeginningWithVar */, 4919,
    55 /* ParseSimpleStatementBeginningWithVar */, 4920,
    55 /* ParseSimpleStatementBeginningWithVar */, 4920,
    56 /* ForwardParseStatement */, 5024,
    56 /* ForwardParseStatement */, 5025,
    56 /* ForwardParseStatement */, 5037,
    56 /* ForwardParseStatement */, 5040,
    56 /* ForwardParseStatement */, 5040,
    56 /* ForwardParseStatement */, 5041,
    56 /* ForwardParseStatement */, 5041,
    56 /* ForwardParseStatement */, 5294
};

void Statements_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Statements";
    *f = Statements_0func[ Statements_0err_entry[2*i] ];
    *l = Statements_0err_entry[2*i + 1];
}
