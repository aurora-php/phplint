/* IMPLEMENTATION MODULE Template */
#define M2_IMPORT_Template

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

#ifndef M2_IMPORT_Accounting
#    include "Accounting.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
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

void Template_0err_entry_get(int i, char **m, char **f, int *l);

/* 18*/ RECORD *
/* 18*/ Template_ParseSurrogate(void)
/* 18*/ {
/* 19*/ 	RECORD * Template_if = NULL;
/* 19*/ 	RECORD * Template_parent = NULL;
/* 19*/ 	RECORD * Template_c = NULL;
/* 21*/ 	int Template_unchecked = 0;
/* 21*/ 	if( (Scanner_sym == 143) ){
/* 22*/ 		Template_unchecked = TRUE;
/* 23*/ 		Scanner_ReadSym();
/* 26*/ 	}
/* 26*/ 	Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"expected surrogate class name");
/* 27*/ 	Scanner_s = Namespace_CheckBareID(Scanner_s);
/* 28*/ 	Scanner_s = Namespace_Absolute(Scanner_s);
/* 29*/ 	Template_c = Search_SearchClassByAbsName(Scanner_s, FALSE);
/* 30*/ 	if( Template_c != NULL ){
/* 31*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"' already declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Template_c, 12 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 0)), (STRING *) 1));
/* 34*/ 	} else {
/* 34*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 1) = Scanner_s;
/* 35*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 1 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 2) = str_tolower(Scanner_s);
/* 36*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 3 * sizeof(int), Template_0err_entry_get, 3) = FALSE;
/* 37*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 6 * sizeof(int), Template_0err_entry_get, 4) = FALSE;
/* 38*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 5 * sizeof(int), Template_0err_entry_get, 5) = TRUE;
/* 39*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 5 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 6) = (
/* 39*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/* 39*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 9,
/* 39*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/* 39*/ 			push((char*) NULL),
/* 39*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 39*/ 			push((char*) Template_c),
/* 40*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 40*/ 			(RECORD*) pop()
/* 40*/ 		);
/* 40*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 4 * sizeof(int), Template_0err_entry_get, 7) = TRUE;
/* 41*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 15 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 8) = Template_unchecked;
/* 42*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Globals_classes, sizeof(void *), 1, Template_0err_entry_get, 9) = Template_c;
/* 44*/ 	}
/* 44*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 12 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 10) = Scanner_here();
/* 45*/ 	Scanner_ReadSym();
/* 47*/ 	if( (Scanner_sym == 139) ){
/* 48*/ 		Scanner_ReadSym();
/* 49*/ 		Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\51,\0,\0,\0)"expected parent class name after `extend'");
/* 50*/ 		Template_parent = Search_SearchClass(Scanner_s);
/* 51*/ 		if( Template_parent == NULL ){
/* 52*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"undeclared parent class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/* 53*/ 		} else if( Classes_IsSubclassOf(Template_parent, Template_c) ){
/* 54*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Template_c, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 11), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" cannot extend child class ", (STRING *)m2runtime_dereference_rhs_RECORD(Template_parent, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 12), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)": forbidden circular reference", (STRING *) 1));
/* 56*/ 		} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Template_parent, 15 * sizeof(void*) + 5 * sizeof(int), Template_0err_entry_get, 13) ){
/* 57*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"can't extend final class `", (STRING *)m2runtime_dereference_rhs_RECORD(Template_parent, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 14), m2runtime_CHR(39), (STRING *) 1));
/* 58*/ 		} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Template_parent, 15 * sizeof(void*) + 7 * sizeof(int), Template_0err_entry_get, 15) ){
/* 59*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"can't extend interface class `", (STRING *)m2runtime_dereference_rhs_RECORD(Template_parent, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 16), m2runtime_CHR(39), (STRING *) 1));
/* 61*/ 		} else {
/* 61*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 3 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 17) = Template_parent;
/* 64*/ 			if( Template_unchecked ){
/* 65*/ 				if( !Classes_IsExceptionClass(Template_parent) ){
/* 66*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"invalid `unchecked' attribute for non-exception class ", (STRING *)m2runtime_dereference_rhs_RECORD(Template_parent, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 18), (STRING *) 1));
/* 70*/ 				}
/* 70*/ 			} else if( (Classes_IsSubclassOf(Template_parent, Classes_ExceptionClass) &&  *(int *)m2runtime_dereference_rhs_RECORD(Template_parent, 15 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 19)) ){
/* 72*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"missing `unchecked' attribute extending unchecked exception ", (STRING *)m2runtime_dereference_rhs_RECORD(Template_parent, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 20), (STRING *) 1));
/* 76*/ 			}
/* 76*/ 		}
/* 76*/ 		Scanner_ReadSym();
/* 79*/ 	}
/* 79*/ 	if( (Scanner_sym == 140) ){
/* 80*/ 		Scanner_ReadSym();
/* 82*/ 		do{
/* 82*/ 			Scanner_Expect(153, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected interface name");
/* 83*/ 			Template_if = Search_SearchClass(Scanner_s);
/* 84*/ 			if( Template_if == NULL ){
/* 85*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"undeclared interface class `", Scanner_s, m2runtime_CHR(39), (STRING *) 1));
/* 86*/ 			} else if( ! *(int *)m2runtime_dereference_rhs_RECORD(Template_if, 15 * sizeof(void*) + 7 * sizeof(int), Template_0err_entry_get, 21) ){
/* 87*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the class `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"' isn't an interface", (STRING *) 1));
/* 88*/ 			} else if( (((Globals_php_ver == 5)) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Template_if, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 22), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"Traversable") == 0)) ){
/* 89*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\137,\0,\0,\0)"can't implement abstract interface `Traversable', use `Iterator' or `IteratorAggregate' instead");
/* 90*/ 			} else if( Classes_IsSubclassOf(Template_c, Template_if) ){
/* 91*/ 				Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ", (STRING *)m2runtime_dereference_rhs_RECORD(Template_c, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 23), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)" redundantly extends interface ", (STRING *)m2runtime_dereference_rhs_RECORD(Template_if, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 24), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)" -- ignoring", (STRING *) 1));
/* 95*/ 			} else {
/* 95*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 4 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 25), sizeof(void *), 1, Template_0err_entry_get, 26) = Template_if;
/* 98*/ 				Accounting_AccountClass(Template_if);
/* 99*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Template_if, 14 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 27), EMPTY_STRING) > 0 ){
/*100*/ 					Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"implementing deprecated interface `", (STRING *)m2runtime_dereference_rhs_RECORD(Template_if, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 28), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", (STRING *)m2runtime_dereference_rhs_RECORD(Template_if, 14 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 29), (STRING *) 1));
/*104*/ 				}
/*104*/ 			}
/*104*/ 			Scanner_ReadSym();
/*105*/ 			if( (Scanner_sym == 134) ){
/*106*/ 				Scanner_ReadSym();
/*109*/ 			} else {
/*110*/ 				goto m2runtime_loop_1;
/*111*/ 			}
/*112*/ 		}while(TRUE);
m2runtime_loop_1: ;
/*113*/ 	}
/*113*/ 	return Template_c;
/*117*/ }


/*119*/ ARRAY *
/*119*/ Template_ParseClassDeclTemplate(void)
/*119*/ {
/*121*/ 	ARRAY * Template_surrogates = NULL;
/*121*/ 	Scanner_ReadSym();
/*123*/ 	do{
/*123*/ 		*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Template_surrogates, sizeof(void *), 1, Template_0err_entry_get, 30) = Template_ParseSurrogate();
/*124*/ 		if( (Scanner_sym == 132) ){
/*125*/ 			Scanner_ReadSym();
/*128*/ 		} else {
/*129*/ 			goto m2runtime_loop_1;
/*130*/ 		}
/*130*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*130*/ 	Scanner_Expect(182, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"expected `;' or `>'");
/*131*/ 	Scanner_ReadSym();
/*132*/ 	return Template_surrogates;
/*136*/ }


/*139*/ void
/*139*/ Template_MangleNamesOfSurrogateClasses(RECORD *Template_main_class, ARRAY *Template_surrogates)
/*139*/ {
/*140*/ 	STRING * Template_base_lower = NULL;
/*140*/ 	STRING * Template_base = NULL;
/*141*/ 	int Template_i = 0;
/*143*/ 	RECORD * Template_c = NULL;
/*145*/ 	Template_base = (STRING *)m2runtime_dereference_rhs_RECORD(Template_main_class, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 31);
/*146*/ 	Template_i = (m2runtime_length(Template_base) - 1);
/*148*/ 	do{
/*148*/ 		if( (Template_i < 0) ){
/*150*/ 			goto m2runtime_loop_1;
/*150*/ 		} else if( m2runtime_strcmp(m2runtime_substr(Template_base, Template_i, 0, 0, Template_0err_entry_get, 32), m2runtime_CHR(92)) == 0 ){
/*151*/ 			Template_base_lower = m2runtime_substr((STRING *)m2runtime_dereference_rhs_RECORD(Template_main_class, 1 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 33), (Template_i + 1), m2runtime_length(Template_base), 1, Template_0err_entry_get, 34);
/*152*/ 			Template_base = m2runtime_substr(Template_base, (Template_i + 1), m2runtime_length(Template_base), 1, Template_0err_entry_get, 35);
/*155*/ 			goto m2runtime_loop_1;
/*155*/ 		}
/*155*/ 		m2_inc(&Template_i, -1);
/*158*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*158*/ 	{
/*158*/ 		int m2runtime_for_limit_1;
/*158*/ 		Template_i = 0;
/*158*/ 		m2runtime_for_limit_1 = (m2runtime_count(Template_surrogates) - 1);
/*159*/ 		for( ; Template_i <= m2runtime_for_limit_1; Template_i += 1 ){
/*159*/ 			Template_c = (RECORD *)m2runtime_dereference_rhs_ARRAY(Template_surrogates, Template_i, Template_0err_entry_get, 36);
/*160*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 37) = m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Template_c, 0 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 38), m2runtime_CHR(64), Template_base, (STRING *) 1);
/*161*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&Template_c, 15 * sizeof(void*) + 11 * sizeof(int), 15, 1 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 39) = m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Template_c, 1 * sizeof(void*) + 2 * sizeof(int), Template_0err_entry_get, 40), m2runtime_CHR(64), Template_base_lower, (STRING *) 1);
/*165*/ 		}
/*165*/ 	}
/*168*/ }


char * Template_0func[] = {
    "ParseSurrogate",
    "ParseClassDeclTemplate",
    "MangleNamesOfSurrogateClasses"
};

int Template_0err_entry[] = {
    0 /* ParseSurrogate */, 32,
    0 /* ParseSurrogate */, 34,
    0 /* ParseSurrogate */, 35,
    0 /* ParseSurrogate */, 36,
    0 /* ParseSurrogate */, 37,
    0 /* ParseSurrogate */, 38,
    0 /* ParseSurrogate */, 39,
    0 /* ParseSurrogate */, 40,
    0 /* ParseSurrogate */, 41,
    0 /* ParseSurrogate */, 42,
    0 /* ParseSurrogate */, 44,
    0 /* ParseSurrogate */, 54,
    0 /* ParseSurrogate */, 55,
    0 /* ParseSurrogate */, 56,
    0 /* ParseSurrogate */, 57,
    0 /* ParseSurrogate */, 58,
    0 /* ParseSurrogate */, 59,
    0 /* ParseSurrogate */, 61,
    0 /* ParseSurrogate */, 67,
    0 /* ParseSurrogate */, 70,
    0 /* ParseSurrogate */, 72,
    0 /* ParseSurrogate */, 86,
    0 /* ParseSurrogate */, 88,
    0 /* ParseSurrogate */, 91,
    0 /* ParseSurrogate */, 93,
    0 /* ParseSurrogate */, 95,
    0 /* ParseSurrogate */, 95,
    0 /* ParseSurrogate */, 99,
    0 /* ParseSurrogate */, 101,
    0 /* ParseSurrogate */, 101,
    1 /* ParseClassDeclTemplate */, 123,
    2 /* MangleNamesOfSurrogateClasses */, 145,
    2 /* MangleNamesOfSurrogateClasses */, 150,
    2 /* MangleNamesOfSurrogateClasses */, 151,
    2 /* MangleNamesOfSurrogateClasses */, 151,
    2 /* MangleNamesOfSurrogateClasses */, 152,
    2 /* MangleNamesOfSurrogateClasses */, 160,
    2 /* MangleNamesOfSurrogateClasses */, 160,
    2 /* MangleNamesOfSurrogateClasses */, 160,
    2 /* MangleNamesOfSurrogateClasses */, 161,
    2 /* MangleNamesOfSurrogateClasses */, 161
};

void Template_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Template";
    *f = Template_0func[ Template_0err_entry[2*i] ];
    *l = Template_0err_entry[2*i + 1];
}
