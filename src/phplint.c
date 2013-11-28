/* MODULE phplint */

#include "m2runtime.c"

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

#ifndef M2_IMPORT_io
#    include "io.c"
#endif

#ifndef M2_IMPORT_Accounting
#    include "Accounting.c"
#endif

#ifndef M2_IMPORT_Documentator
#    include "Documentator.c"
#endif

#ifndef M2_IMPORT_Expressions
#    include "Expressions.c"
#endif

#ifndef M2_IMPORT_FileName
#    include "FileName.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_ParseDocBlock
#    include "ParseDocBlock.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Statements
#    include "Statements.c"
#endif

#ifndef M2_IMPORT_Version
#    include "Version.c"
#endif

void phplint_0err_entry_get(int i, char **m, char **f, int *l);
/* 33*/ int phplint_mark_classes = 0;
/* 33*/ int phplint_mark_funcs = 0;
/* 33*/ int phplint_mark_vars = 0;
/* 33*/ int phplint_mark_consts = 0;

/* 35*/ void
/* 35*/ phplint_MarkUsed(void)
/* 35*/ {
/* 35*/ 	phplint_mark_consts = m2runtime_count(Globals_consts);
/* 36*/ 	phplint_mark_vars = Globals_vars_n;
/* 37*/ 	phplint_mark_funcs = m2runtime_count(Globals_funcs);
/* 38*/ 	phplint_mark_classes = m2runtime_count(Globals_classes);
/* 42*/ }


/* 44*/ void
/* 44*/ phplint_ReportUndeclaredAndUnused(void)
/* 44*/ {
/* 45*/ 	int phplint_j = 0;
/* 45*/ 	int phplint_i = 0;
/* 46*/ 	RECORD * phplint_co = NULL;
/* 47*/ 	RECORD * phplint_v = NULL;
/* 48*/ 	RECORD * phplint_f = NULL;
/* 49*/ 	RECORD * phplint_class = NULL;
/* 50*/ 	ARRAY * phplint_class_consts = NULL;
/* 51*/ 	ARRAY * phplint_properties = NULL;
/* 52*/ 	ARRAY * phplint_methods = NULL;
/* 53*/ 	RECORD * phplint_c = NULL;
/* 54*/ 	RECORD * phplint_p = NULL;
/* 55*/ 	RECORD * phplint_m = NULL;
/* 56*/ 	STRING * phplint_private_str = NULL;
/* 58*/ 	RECORD * phplint_pkg = NULL;
/* 58*/ 	if( (!Accounting_report_unused || !Scanner_print_notices) ){
/* 60*/ 		return ;
/* 62*/ 	}
/* 62*/ 	{
/* 62*/ 		int m2runtime_for_limit_1;
/* 62*/ 		phplint_i = phplint_mark_consts;
/* 62*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_consts) - 1);
/* 63*/ 		for( ; phplint_i <= m2runtime_for_limit_1; phplint_i += 1 ){
/* 63*/ 			phplint_co = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_consts, phplint_i, phplint_0err_entry_get, 0);
/* 64*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(phplint_co, 2 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 1) == NULL ){
/* 65*/ 				if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_co, 7 * sizeof(void*) + 3 * sizeof(int), phplint_0err_entry_get, 2) == 1) ){
/* 66*/ 					Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_co, 3 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 3), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"undeclared constant `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_co, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 4), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"' used only once: misspelled?", (STRING *) 1));
/* 69*/ 				} else {
/* 69*/ 					Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_co, 3 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 5), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"undeclared constant `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_co, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 6), m2runtime_CHR(39), (STRING *) 1));
/* 71*/ 				}
/* 71*/ 			} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_co, 7 * sizeof(void*) + 3 * sizeof(int), phplint_0err_entry_get, 7) == 0) ){
/* 72*/ 				Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_co, 2 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 8), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"unused constant `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_co, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 9), m2runtime_CHR(39), (STRING *) 1));
/* 75*/ 			}
/* 76*/ 		}
/* 76*/ 	}
/* 76*/ 	{
/* 76*/ 		int m2runtime_for_limit_1;
/* 76*/ 		phplint_i = phplint_mark_vars;
/* 76*/ 		m2runtime_for_limit_1 = (Globals_vars_n - 1);
/* 77*/ 		for( ; phplint_i <= m2runtime_for_limit_1; phplint_i += 1 ){
/* 77*/ 			phplint_v = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_vars, phplint_i, phplint_0err_entry_get, 10);
/* 78*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_v, 7 * sizeof(void*) + 6 * sizeof(int), phplint_0err_entry_get, 11) == 0) ){
/* 79*/ 				Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_v, 2 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 12), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"unused global variable `$", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_v, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 13), m2runtime_CHR(39), (STRING *) 1));
/* 82*/ 			}
/* 83*/ 		}
/* 83*/ 	}
/* 83*/ 	{
/* 83*/ 		int m2runtime_for_limit_1;
/* 83*/ 		phplint_i = phplint_mark_funcs;
/* 83*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_funcs) - 1);
/* 84*/ 		for( ; phplint_i <= m2runtime_for_limit_1; phplint_i += 1 ){
/* 84*/ 			phplint_f = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_funcs, phplint_i, phplint_0err_entry_get, 14);
/* 85*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(phplint_f, 2 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 15) == NULL ){
/* 86*/ 				if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_f, 10 * sizeof(void*) + 4 * sizeof(int), phplint_0err_entry_get, 16) == 1) ){
/* 87*/ 					Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_f, 4 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 17), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"undeclared function `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_f, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 18), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"()' used only once: misspelled?", (STRING *) 1));
/* 90*/ 				} else {
/* 90*/ 					Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_f, 4 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 19), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"undeclared function `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_f, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 20), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"()'", (STRING *) 1));
/* 92*/ 				}
/* 92*/ 			} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_f, 10 * sizeof(void*) + 4 * sizeof(int), phplint_0err_entry_get, 21) == 0) ){
/* 93*/ 				Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_f, 2 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 22), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"unused function `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_f, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 23), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"()'", (STRING *) 1));
/* 96*/ 			}
/* 97*/ 		}
/* 97*/ 	}
/* 97*/ 	if( (Globals_php_ver == 4) ){
/* 98*/ 		phplint_private_str = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"`/*. private .*/'";
/*100*/ 	} else {
/*100*/ 		phplint_private_str = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"`private'";
/*103*/ 	}
/*103*/ 	{
/*103*/ 		int m2runtime_for_limit_1;
/*103*/ 		phplint_i = phplint_mark_classes;
/*103*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_classes) - 1);
/*104*/ 		for( ; phplint_i <= m2runtime_for_limit_1; phplint_i += 1 ){
/*104*/ 			phplint_class = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_classes, phplint_i, phplint_0err_entry_get, 24);
/*105*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_class, 15 * sizeof(void*) + 10 * sizeof(int), phplint_0err_entry_get, 25) == 0) ){
/*106*/ 				Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_class, 12 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 26), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"unused class `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_class, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 27), m2runtime_CHR(39), (STRING *) 1));
/*108*/ 			} else {
/*108*/ 				phplint_class_consts = (ARRAY *)m2runtime_dereference_rhs_RECORD(phplint_class, 6 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 28);
/*109*/ 				{
/*109*/ 					int m2runtime_for_limit_2;
/*109*/ 					phplint_j = 0;
/*109*/ 					m2runtime_for_limit_2 = (m2runtime_count(phplint_class_consts) - 1);
/*110*/ 					for( ; phplint_j <= m2runtime_for_limit_2; phplint_j += 1 ){
/*110*/ 						phplint_c = (RECORD *)m2runtime_dereference_rhs_ARRAY(phplint_class_consts, phplint_j, phplint_0err_entry_get, 29);
/*111*/ 						if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_c, 5 * sizeof(void*) + 3 * sizeof(int), phplint_0err_entry_get, 30) == 0) ){
/*112*/ 							if(  *(int *)m2runtime_dereference_rhs_RECORD(phplint_c, 5 * sizeof(void*) + 4 * sizeof(int), phplint_0err_entry_get, 31) ){
/*113*/ 								if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_c, 5 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 32) != 0) ){
/*114*/ 									Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_c, 2 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 33), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"the constant `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_c, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 34), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\102,\0,\0,\0)"' used only inside its class, you should make it `/*. private .*/'", (STRING *) 1));
/*118*/ 								}
/*118*/ 							} else {
/*118*/ 								Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_c, 2 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 35), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"unused constant `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_class, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 36), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_c, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 37), m2runtime_CHR(39), (STRING *) 1));
/*122*/ 							}
/*123*/ 						}
/*123*/ 					}
/*123*/ 				}
/*123*/ 				phplint_properties = (ARRAY *)m2runtime_dereference_rhs_RECORD(phplint_class, 7 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 38);
/*124*/ 				{
/*124*/ 					int m2runtime_for_limit_2;
/*124*/ 					phplint_j = 0;
/*124*/ 					m2runtime_for_limit_2 = (m2runtime_count(phplint_properties) - 1);
/*125*/ 					for( ; phplint_j <= m2runtime_for_limit_2; phplint_j += 1 ){
/*125*/ 						phplint_p = (RECORD *)m2runtime_dereference_rhs_ARRAY(phplint_properties, phplint_j, phplint_0err_entry_get, 39);
/*126*/ 						if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_p, 6 * sizeof(void*) + 4 * sizeof(int), phplint_0err_entry_get, 40) == 0) ){
/*127*/ 							if(  *(int *)m2runtime_dereference_rhs_RECORD(phplint_p, 6 * sizeof(void*) + 5 * sizeof(int), phplint_0err_entry_get, 41) ){
/*128*/ 								if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_p, 6 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 42) != 0) ){
/*129*/ 									Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_p, 3 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 43), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"the property `$", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_p, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 44), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\61,\0,\0,\0)"' used only inside its class, you should make it ", phplint_private_str, (STRING *) 1));
/*133*/ 								}
/*133*/ 							} else {
/*133*/ 								Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_p, 3 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 45), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"unused property `", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_class, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 46), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(phplint_p, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 47), m2runtime_CHR(39), (STRING *) 1));
/*137*/ 							}
/*138*/ 						}
/*138*/ 					}
/*138*/ 				}
/*138*/ 				phplint_methods = (ARRAY *)m2runtime_dereference_rhs_RECORD(phplint_class, 8 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 48);
/*139*/ 				{
/*139*/ 					int m2runtime_for_limit_2;
/*139*/ 					phplint_j = 0;
/*139*/ 					m2runtime_for_limit_2 = (m2runtime_count(phplint_methods) - 1);
/*140*/ 					for( ; phplint_j <= m2runtime_for_limit_2; phplint_j += 1 ){
/*140*/ 						phplint_m = (RECORD *)m2runtime_dereference_rhs_ARRAY(phplint_methods, phplint_j, phplint_0err_entry_get, 49);
/*141*/ 						if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_m, 9 * sizeof(void*) + 7 * sizeof(int), phplint_0err_entry_get, 50) == 0) ){
/*142*/ 							if(  *(int *)m2runtime_dereference_rhs_RECORD(phplint_m, 9 * sizeof(void*) + 8 * sizeof(int), phplint_0err_entry_get, 51) ){
/*143*/ 								if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_m, 9 * sizeof(void*) + 4 * sizeof(int), phplint_0err_entry_get, 52) != 0) ){
/*144*/ 									Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_m, 3 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 53), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the method ", Scanner_mn(phplint_class, phplint_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)" is used only inside its class, you should make it as ", phplint_private_str, (STRING *) 1));
/*148*/ 								}
/*148*/ 							} else {
/*148*/ 								Scanner_Notice2((RECORD *)m2runtime_dereference_rhs_RECORD(phplint_m, 3 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 54), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"unused method ", Scanner_mn(phplint_class, phplint_m), (STRING *) 1));
/*151*/ 							}
/*152*/ 						}
/*153*/ 					}
/*153*/ 				}
/*154*/ 			}
/*155*/ 		}
/*155*/ 	}
/*155*/ 	{
/*155*/ 		int m2runtime_for_limit_1;
/*155*/ 		phplint_i = 0;
/*155*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_required_packages) - 1);
/*156*/ 		for( ; phplint_i <= m2runtime_for_limit_1; phplint_i += 1 ){
/*156*/ 			phplint_pkg = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_required_packages, phplint_i, phplint_0err_entry_get, 55);
/*157*/ 			if( ((phplint_pkg != Globals_curr_package) && (( *(int *)m2runtime_dereference_rhs_RECORD(phplint_pkg, 6 * sizeof(void*) + 4 * sizeof(int), phplint_0err_entry_get, 56) == 0))) ){
/*158*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(phplint_pkg, 6 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 57) ){
/*159*/ 					Scanner_Notice2(NULL, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"unused module `", FileName_Basename((STRING *)m2runtime_dereference_rhs_RECORD(phplint_pkg, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 58)), m2runtime_CHR(39), (STRING *) 1));
/*161*/ 				} else {
/*161*/ 					Scanner_Notice2(NULL, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"unused package `", Scanner_fmt_fn((STRING *)m2runtime_dereference_rhs_RECORD(phplint_pkg, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 59)), m2runtime_CHR(39), (STRING *) 1));
/*164*/ 				}
/*165*/ 			}
/*166*/ 		}
/*166*/ 	}
/*168*/ }


/*169*/ void
/*169*/ phplint_ReportRequiredPackages(void)
/*169*/ {
/*169*/ 	int phplint_i = 0;
/*171*/ 	RECORD * phplint_p = NULL;
/*171*/ 	if( !Scanner_print_notices ){
/*173*/ 		return ;
/*174*/ 	}
/*174*/ 	{
/*174*/ 		int m2runtime_for_limit_1;
/*174*/ 		phplint_i = 0;
/*174*/ 		m2runtime_for_limit_1 = (m2runtime_count(Globals_required_packages) - 1);
/*175*/ 		for( ; phplint_i <= m2runtime_for_limit_1; phplint_i += 1 ){
/*175*/ 			phplint_p = (RECORD *)m2runtime_dereference_rhs_ARRAY(Globals_required_packages, phplint_i, phplint_0err_entry_get, 60);
/*176*/ 			if( ( *(int *)m2runtime_dereference_rhs_RECORD(phplint_p, 6 * sizeof(void*) + 4 * sizeof(int), phplint_0err_entry_get, 61) > 0) ){
/*177*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(phplint_p, 6 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 62) ){
/*178*/ 					Scanner_Notice2(NULL, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"required module `", FileName_Basename((STRING *)m2runtime_dereference_rhs_RECORD(phplint_p, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 63)), m2runtime_CHR(39), (STRING *) 1));
/*180*/ 				} else {
/*180*/ 					Scanner_Notice2(NULL, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"required package `", Scanner_fmt_fn((STRING *)m2runtime_dereference_rhs_RECORD(phplint_p, 0 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 64)), m2runtime_CHR(39), (STRING *) 1));
/*183*/ 				}
/*184*/ 			}
/*185*/ 		}
/*185*/ 	}
/*187*/ }


/*189*/ ARRAY *
/*189*/ phplint_SplitPath(STRING *phplint_cwd, STRING *phplint_path)
/*189*/ {
/*190*/ 	ARRAY * phplint_a = NULL;
/*192*/ 	int phplint_i = 0;
/*192*/ 	phplint_a = str_split(phplint_path, m2runtime_CHR(58));
/*193*/ 	{
/*193*/ 		int m2runtime_for_limit_1;
/*193*/ 		phplint_i = 0;
/*193*/ 		m2runtime_for_limit_1 = (m2runtime_count(phplint_a) - 1);
/*194*/ 		for( ; phplint_i <= m2runtime_for_limit_1; phplint_i += 1 ){
/*194*/ 			*(STRING **)m2runtime_dereference_lhs_ARRAY(&phplint_a, sizeof(void *), 1, phplint_i, phplint_0err_entry_get, 65) = FileName_Absolute(phplint_cwd, (STRING *)m2runtime_dereference_rhs_ARRAY(phplint_a, phplint_i, phplint_0err_entry_get, 66));
/*196*/ 		}
/*196*/ 	}
/*196*/ 	return phplint_a;
/*200*/ }


/*202*/ void
/*202*/ phplint_Version(void)
/*202*/ {
/*202*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"PHPLint ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"1.1_20130803", m2runtime_CHR(10), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"Copyright 2013 by icosaedro.it di Umberto Salsi\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"This is free software; see the license for copying conditions.\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"More info: http://www.icosaedro.it/phplint/\012", m2runtime_CHR(10), (STRING *) 1));
/*211*/ }


/*213*/ void
/*213*/ phplint_Help(void)
/*213*/ {
/*213*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"Usage:   phplint [OPTION] [FILE] ...\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"A PHP language parser and validator with extended syntax.\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"\012OPTIONS:\012\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"Between round parentheses is the default value.\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"  --version               print version\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"  --help                  this help\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"  --php-version V         set PHP version V to 4 or 5 (5)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\102,\0,\0,\0)"  --modules-path PATH     set the path[s] to modules dir[s] (\042.\042)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"  --[no-]is-module        parsed file is a module (FALSE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\103,\0,\0,\0)"  --packages-path PATH    set the path[s] to packages dir[s] (\042.\042)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\102,\0,\0,\0)"  --[no-]recursive        follows require_once recursively (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\110,\0,\0,\0)"  --[no-]print-file-name  print file name along error also for the file\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)"                          currently being parsed (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\106,\0,\0,\0)"  --print-path absolute   print file names as absolute path (default)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\112,\0,\0,\0)"  --print-path relative   ...or relative to the current working directory\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)"  --print-path shortest   ...or the shortest of the two above\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\100,\0,\0,\0)"  --[no-]ctrl-check       check control chars in strings (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\107,\0,\0,\0)"  --[no-]ascii-ext-check  check extended ASCII chars in strings (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"  --[no-]print-notices    print notices  (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"  --[no-]print-warnings   print warnings (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"  --[no-]print-errors     print errors   (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)"  --[no-]parse-phpdoc     parse phpDocumentor comments (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"  --[no-]print-context    print error context (FALSE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"  --[no-]print-source     print source (FALSE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\115,\0,\0,\0)"  --[no-]print-line-numbers   print the line numbers along the source (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)"  --[no-]report-unused    report unused IDs (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\102,\0,\0,\0)"  --[no-]fails-on-warning exit status 1 also for warnings (FALSE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\71,\0,\0,\0)"  --tab-size N            set tabulation to N spaces (8)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\113,\0,\0,\0)"  --[no-]overall          displays total no. of errors and warnings (TRUE)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)"  --doc-help              help about the PHPLint Documentator\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)"  --debug                 print source with debugging info\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\115,\0,\0,\0)"Exit status 0 if no errors, 1 on errors; if the --fails-on-warning option is\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"set, exit status 1 also for warnings.\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\106,\0,\0,\0)"\012Report bugs to phplint@icosaedro.it (but read README before submit).\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"Info and updates: www.icosaedro.it/phplint/\012", m2runtime_CHR(10), (STRING *) 1));
/*255*/ }

/*256*/ ARRAY * phplint_args = NULL;
/*257*/ STRING * phplint_arg = NULL;
/*258*/ int phplint_i = 0;
/*259*/ int phplint_do_report = 0;
/*260*/ int phplint_is_module = 0;
/*261*/ int phplint_fails_on_warning = 0;
/*264*/ int phplint_overall = 0;

int phplint_0main()
{
/*265*/ 	Globals_php_ver = 5;
/*266*/ 	Globals_recursive_parsing = TRUE;
/*267*/ 	Scanner_print_errors = TRUE;
/*268*/ 	Scanner_print_warnings = TRUE;
/*269*/ 	Scanner_print_notices = TRUE;
/*270*/ 	Scanner_print_context = FALSE;
/*271*/ 	Scanner_print_source = FALSE;
/*272*/ 	Scanner_print_line_numbers = TRUE;
/*273*/ 	Scanner_print_file_name = TRUE;
/*274*/ 	Scanner_print_path_fmt = 0;
/*275*/ 	m2runtime_ERROR_CODE = 0;
/*275*/ 	Scanner_cwd = io_GetCWD(1);
/*276*/ 	switch( m2runtime_ERROR_CODE ){

/*276*/ 	case 0:  break;
/*276*/ 	default:
/*276*/ 		m2runtime_HALT(phplint_0err_entry_get, 67, m2runtime_ERROR_MESSAGE);
/*276*/ 	}
/*276*/ 	ParseDocBlock_parse_phpdoc = TRUE;
/*277*/ 	Scanner_tab_size = 8;
/*278*/ 	Scanner_ctrl_check = TRUE;
/*279*/ 	Scanner_ascii_ext_check = TRUE;
/*280*/ 	Accounting_report_unused = TRUE;
/*281*/ 	Statements_modules_abs_path = NULL;
/*282*/ 	Statements_packages_abs_path = NULL;
/*283*/ 	phplint_is_module = FALSE;
/*284*/ 	phplint_fails_on_warning = FALSE;
/*285*/ 	phplint_overall = TRUE;
/*287*/ 	Documentator_Init();
/*289*/ 	phplint_args = m2runtime_get_args();
/*290*/ 	{
/*290*/ 		int m2runtime_for_limit_1;
/*290*/ 		phplint_i = 1;
/*290*/ 		m2runtime_for_limit_1 = (m2runtime_count(phplint_args) - 1);
/*291*/ 		for( ; phplint_i <= m2runtime_for_limit_1; phplint_i += 1 ){
/*291*/ 			phplint_arg = (STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 68);
/*292*/ 			if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"--help") == 0 ){
/*292*/ 				phplint_Help();
/*293*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"--version") == 0 ){
/*293*/ 				phplint_Version();
/*294*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"--debug") == 0 ){
/*294*/ 				Globals_DEBUG = TRUE;
/*295*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"--recursive") == 0 ){
/*295*/ 				Globals_recursive_parsing = TRUE;
/*296*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"--no-recursive") == 0 ){
/*296*/ 				Globals_recursive_parsing = FALSE;
/*297*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"--print-file-name") == 0 ){
/*297*/ 				Scanner_print_file_name = TRUE;
/*298*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"--no-print-file-name") == 0 ){
/*298*/ 				Scanner_print_file_name = FALSE;
/*299*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"--ctrl-check") == 0 ){
/*299*/ 				Scanner_ctrl_check = TRUE;
/*300*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"--no-ctrl-check") == 0 ){
/*300*/ 				Scanner_ctrl_check = FALSE;
/*301*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"--ascii-ext-check") == 0 ){
/*301*/ 				Scanner_ascii_ext_check = TRUE;
/*302*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"--no-ascii-ext-check") == 0 ){
/*302*/ 				Scanner_ascii_ext_check = FALSE;
/*303*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"--print-notices") == 0 ){
/*303*/ 				Scanner_print_notices = TRUE;
/*304*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"--no-print-notices") == 0 ){
/*304*/ 				Scanner_print_notices = FALSE;
/*305*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"--print-warnings") == 0 ){
/*305*/ 				Scanner_print_warnings = TRUE;
/*306*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"--no-print-warnings") == 0 ){
/*306*/ 				Scanner_print_warnings = FALSE;
/*307*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"--print-errors") == 0 ){
/*307*/ 				Scanner_print_errors = TRUE;
/*308*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"--no-print-errors") == 0 ){
/*308*/ 				Scanner_print_errors = FALSE;
/*309*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"--print-context") == 0 ){
/*309*/ 				Scanner_print_context = TRUE;
/*310*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"--no-print-context") == 0 ){
/*310*/ 				Scanner_print_context = FALSE;
/*311*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"--print-source") == 0 ){
/*311*/ 				Scanner_print_source = TRUE;
/*312*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"--no-print-source") == 0 ){
/*312*/ 				Scanner_print_source = FALSE;
/*313*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"--print-line-numbers") == 0 ){
/*313*/ 				Scanner_print_line_numbers = TRUE;
/*314*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"--no-print-line-numbers") == 0 ){
/*314*/ 				Scanner_print_line_numbers = FALSE;
/*315*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"--parse-phpdoc") == 0 ){
/*315*/ 				ParseDocBlock_parse_phpdoc = TRUE;
/*316*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"--no-parse-phpdoc") == 0 ){
/*316*/ 				ParseDocBlock_parse_phpdoc = FALSE;
/*317*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"--mark-used") == 0 ){
/*317*/ 				phplint_MarkUsed();
/*318*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"--report-unused") == 0 ){
/*318*/ 				Accounting_report_unused = TRUE;
/*319*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"--no-report-unused") == 0 ){
/*319*/ 				Accounting_report_unused = FALSE;
/*320*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"--is-module") == 0 ){
/*320*/ 				phplint_is_module = TRUE;
/*321*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"--no-is-module") == 0 ){
/*321*/ 				phplint_is_module = FALSE;
/*322*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"--fails-on-warning") == 0 ){
/*322*/ 				phplint_fails_on_warning = TRUE;
/*323*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"--no-fails-on-warning") == 0 ){
/*323*/ 				phplint_fails_on_warning = FALSE;
/*324*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"--overall") == 0 ){
/*324*/ 				phplint_overall = TRUE;
/*325*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"--no-overall") == 0 ){
/*325*/ 				phplint_overall = FALSE;
/*326*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"--print-path") == 0 ){
/*327*/ 				m2_inc(&phplint_i, 1);
/*328*/ 				if( (phplint_i >= m2runtime_count(phplint_args)) ){
/*329*/ 					m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"phplint: missing argument for --print-path\012");
/*330*/ 					m2runtime_exit(1);
/*332*/ 				}
/*332*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 69), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"absolute") == 0 ){
/*333*/ 					Scanner_print_path_fmt = 0;
/*334*/ 				} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 70), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"relative") == 0 ){
/*335*/ 					Scanner_print_path_fmt = 1;
/*336*/ 				} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 71), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"shortest") == 0 ){
/*337*/ 					Scanner_print_path_fmt = 2;
/*339*/ 				} else {
/*339*/ 					m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"phplint: invalid argument for --print-path\012");
/*340*/ 					m2runtime_exit(1);
/*342*/ 				}
/*342*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"--php-version") == 0 ){
/*343*/ 				m2_inc(&phplint_i, 1);
/*344*/ 				if( (phplint_i >= m2runtime_count(phplint_args)) ){
/*345*/ 					m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"phplint: missing argument for --php-version\012");
/*346*/ 					m2runtime_exit(1);
/*348*/ 				}
/*348*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 72), m2runtime_CHR(52)) == 0 ){
/*349*/ 					Globals_php_ver = 4;
/*350*/ 				} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 73), m2runtime_CHR(53)) == 0 ){
/*351*/ 					Globals_php_ver = 5;
/*353*/ 				} else {
/*353*/ 					m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"phplint: invalid PHP version - must be 4 or 5\012");
/*354*/ 					m2runtime_exit(1);
/*356*/ 				}
/*356*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"--modules-path") == 0 ){
/*357*/ 				m2_inc(&phplint_i, 1);
/*358*/ 				if( (phplint_i >= m2runtime_count(phplint_args)) ){
/*359*/ 					m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"phplint: missing argument for --modules-path\012");
/*360*/ 					m2runtime_exit(1);
/*362*/ 				}
/*362*/ 				Statements_modules_abs_path = phplint_SplitPath(Scanner_cwd, (STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 74));
/*363*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"--packages-path") == 0 ){
/*364*/ 				m2_inc(&phplint_i, 1);
/*365*/ 				if( (phplint_i >= m2runtime_count(phplint_args)) ){
/*366*/ 					m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"phplint: missing argument for --packages-path\012");
/*367*/ 					m2runtime_exit(1);
/*369*/ 				}
/*369*/ 				Statements_packages_abs_path = phplint_SplitPath(Scanner_cwd, (STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 75));
/*370*/ 			} else if( m2runtime_strcmp(phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"--tab-size") == 0 ){
/*371*/ 				m2_inc(&phplint_i, 1);
/*372*/ 				if( (phplint_i >= m2runtime_count(phplint_args)) ){
/*373*/ 					m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"phplint: missing argument for --tab-size\012");
/*374*/ 					m2runtime_exit(1);
/*376*/ 				}
/*376*/ 				Scanner_tab_size = m2_stoi((STRING *)m2runtime_dereference_rhs_ARRAY(phplint_args, phplint_i, phplint_0err_entry_get, 76));
/*377*/ 			} else if( (((m2runtime_length(phplint_arg) >= 5)) && (m2runtime_strcmp(m2runtime_substr(phplint_arg, 0, 5, 1, phplint_0err_entry_get, 77), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"--doc") == 0)) ){
/*378*/ 				phplint_i = Documentator_ParseParameter(phplint_i, phplint_args);
/*379*/ 			} else if( (((m2runtime_length(phplint_arg) > 0)) && (m2runtime_strcmp(m2runtime_substr(phplint_arg, 0, 0, 0, phplint_0err_entry_get, 78), m2runtime_CHR(45)) == 0)) ){
/*380*/ 				m2_error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"phplint: unknown option `", phplint_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"'\012", (STRING *) 1));
/*381*/ 				m2runtime_exit(1);
/*383*/ 			} else {
/*383*/ 				phplint_arg = FileName_Absolute(Scanner_cwd, phplint_arg);
/*385*/ 				Globals_curr_package = Statements_ParsePackage(phplint_arg, phplint_is_module);
/*387*/ 				if( Globals_curr_package != NULL ){
/*388*/ 					Documentator_Generate(Globals_php_ver, phplint_arg, (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 2 * sizeof(void*) + 2 * sizeof(int), phplint_0err_entry_get, 79), Globals_required_packages, Statements_include_path, Globals_consts, Globals_vars, Globals_funcs, Globals_classes);
/*396*/ 				}
/*396*/ 				phplint_do_report = TRUE;
/*399*/ 			}
/*400*/ 		}
/*400*/ 	}
/*400*/ 	if( phplint_do_report ){
/*401*/ 		Expressions_CleanCurrentScope();
/*403*/ 		if( Scanner_print_notices ){
/*404*/ 			phplint_ReportUndeclaredAndUnused();
/*405*/ 			phplint_ReportRequiredPackages();
/*408*/ 		}
/*408*/ 		if( phplint_overall ){
/*409*/ 			m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"Overall test results: ", m2runtime_itos(Scanner_error_counter), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)" errors, ", m2runtime_itos(Scanner_warning_counter), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)" warnings.\012", (STRING *) 1));
/*413*/ 		}
/*413*/ 		if( (Globals_scope != 0) ){
/*414*/ 			m2_error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"phplint: INTERNAL ERROR: scope=", m2runtime_itos(Globals_scope), m2runtime_CHR(10), (STRING *) 1));
/*415*/ 			m2runtime_exit(1);
/*418*/ 		}
/*418*/ 		if( (((Scanner_error_counter == 0)) && ((!phplint_fails_on_warning || ((Scanner_warning_counter == 0))))) ){
/*419*/ 			m2runtime_exit(0);
/*421*/ 		} else {
/*421*/ 			m2runtime_exit(1);
/*424*/ 		}
/*426*/ 	}
	return 0;
}

char * phplint_0func[] = {
    "ReportUndeclaredAndUnused",
    "ReportRequiredPackages",
    "SplitPath",
    "0main"
};

int phplint_0err_entry[] = {
    0 /* ReportUndeclaredAndUnused */, 64,
    0 /* ReportUndeclaredAndUnused */, 64,
    0 /* ReportUndeclaredAndUnused */, 65,
    0 /* ReportUndeclaredAndUnused */, 66,
    0 /* ReportUndeclaredAndUnused */, 66,
    0 /* ReportUndeclaredAndUnused */, 69,
    0 /* ReportUndeclaredAndUnused */, 69,
    0 /* ReportUndeclaredAndUnused */, 71,
    0 /* ReportUndeclaredAndUnused */, 72,
    0 /* ReportUndeclaredAndUnused */, 72,
    0 /* ReportUndeclaredAndUnused */, 78,
    0 /* ReportUndeclaredAndUnused */, 78,
    0 /* ReportUndeclaredAndUnused */, 79,
    0 /* ReportUndeclaredAndUnused */, 79,
    0 /* ReportUndeclaredAndUnused */, 85,
    0 /* ReportUndeclaredAndUnused */, 85,
    0 /* ReportUndeclaredAndUnused */, 86,
    0 /* ReportUndeclaredAndUnused */, 87,
    0 /* ReportUndeclaredAndUnused */, 87,
    0 /* ReportUndeclaredAndUnused */, 90,
    0 /* ReportUndeclaredAndUnused */, 90,
    0 /* ReportUndeclaredAndUnused */, 92,
    0 /* ReportUndeclaredAndUnused */, 93,
    0 /* ReportUndeclaredAndUnused */, 93,
    0 /* ReportUndeclaredAndUnused */, 105,
    0 /* ReportUndeclaredAndUnused */, 105,
    0 /* ReportUndeclaredAndUnused */, 106,
    0 /* ReportUndeclaredAndUnused */, 106,
    0 /* ReportUndeclaredAndUnused */, 108,
    0 /* ReportUndeclaredAndUnused */, 111,
    0 /* ReportUndeclaredAndUnused */, 111,
    0 /* ReportUndeclaredAndUnused */, 112,
    0 /* ReportUndeclaredAndUnused */, 113,
    0 /* ReportUndeclaredAndUnused */, 114,
    0 /* ReportUndeclaredAndUnused */, 114,
    0 /* ReportUndeclaredAndUnused */, 118,
    0 /* ReportUndeclaredAndUnused */, 119,
    0 /* ReportUndeclaredAndUnused */, 119,
    0 /* ReportUndeclaredAndUnused */, 123,
    0 /* ReportUndeclaredAndUnused */, 126,
    0 /* ReportUndeclaredAndUnused */, 126,
    0 /* ReportUndeclaredAndUnused */, 127,
    0 /* ReportUndeclaredAndUnused */, 128,
    0 /* ReportUndeclaredAndUnused */, 129,
    0 /* ReportUndeclaredAndUnused */, 129,
    0 /* ReportUndeclaredAndUnused */, 133,
    0 /* ReportUndeclaredAndUnused */, 134,
    0 /* ReportUndeclaredAndUnused */, 134,
    0 /* ReportUndeclaredAndUnused */, 138,
    0 /* ReportUndeclaredAndUnused */, 141,
    0 /* ReportUndeclaredAndUnused */, 141,
    0 /* ReportUndeclaredAndUnused */, 142,
    0 /* ReportUndeclaredAndUnused */, 143,
    0 /* ReportUndeclaredAndUnused */, 144,
    0 /* ReportUndeclaredAndUnused */, 148,
    0 /* ReportUndeclaredAndUnused */, 157,
    0 /* ReportUndeclaredAndUnused */, 157,
    0 /* ReportUndeclaredAndUnused */, 158,
    0 /* ReportUndeclaredAndUnused */, 159,
    0 /* ReportUndeclaredAndUnused */, 161,
    1 /* ReportRequiredPackages */, 176,
    1 /* ReportRequiredPackages */, 176,
    1 /* ReportRequiredPackages */, 177,
    1 /* ReportRequiredPackages */, 178,
    1 /* ReportRequiredPackages */, 180,
    2 /* SplitPath */, 194,
    2 /* SplitPath */, 194,
    3 /* 0main */, 275,
    3 /* 0main */, 292,
    3 /* 0main */, 332,
    3 /* 0main */, 334,
    3 /* 0main */, 336,
    3 /* 0main */, 348,
    3 /* 0main */, 350,
    3 /* 0main */, 362,
    3 /* 0main */, 369,
    3 /* 0main */, 376,
    3 /* 0main */, 377,
    3 /* 0main */, 379,
    3 /* 0main */, 391
};

void phplint_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "phplint";
    *f = phplint_0func[ phplint_0err_entry[2*i] ];
    *l = phplint_0err_entry[2*i + 1];
}

int main(int argc, char *argv[])
{
	m2runtime_argc = argc;  m2runtime_argv = (char **)argv;
	GC_INIT();
	return phplint_0main();
}

/* END */
