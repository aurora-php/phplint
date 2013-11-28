/* IMPLEMENTATION MODULE MagicConstants */
#define M2_IMPORT_MagicConstants

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_FileName
#    include "FileName.c"
#endif

void MagicConstants_0err_entry_get(int i, char **m, char **f, int *l);

/*  9*/ RECORD *
/*  9*/ MagicConstants_Resolve(RECORD *MagicConstants_c)
/*  9*/ {
/* 11*/ 	STRING * MagicConstants_name = NULL;
/* 11*/ 	MagicConstants_name = (STRING *)m2runtime_dereference_rhs_RECORD(MagicConstants_c, 0 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 0);
/* 12*/ 	if( (((m2runtime_length(MagicConstants_name) < 3)) || (m2runtime_strcmp(m2runtime_substr(MagicConstants_name, 0, 0, 0, MagicConstants_0err_entry_get, 1), m2runtime_CHR(95)) != 0) || (m2runtime_strcmp(m2runtime_substr(MagicConstants_name, 1, 0, 0, MagicConstants_0err_entry_get, 2), m2runtime_CHR(95)) != 0)) ){
/* 13*/ 		return (RECORD *)m2runtime_dereference_rhs_RECORD(MagicConstants_c, 4 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 3);
/* 16*/ 	}
/* 16*/ 	if( (((Globals_php_ver == 5)) && (m2runtime_strcmp(MagicConstants_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"__DIR__") == 0)) ){
/* 17*/ 		return (
/* 17*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 17*/ 			push((char*) Globals_string_type),
/* 17*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 17*/ 			push((char*) FileName_Dirname((STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 0 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 4))),
/* 18*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 19*/ 			(RECORD*) pop()
/* 19*/ 		);
/* 19*/ 	} else if( m2runtime_strcmp(MagicConstants_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"__FILE__") == 0 ){
/* 20*/ 		return (
/* 20*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 20*/ 			push((char*) Globals_string_type),
/* 20*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 20*/ 			push((char*) (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 0 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 5)),
/* 21*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 22*/ 			(RECORD*) pop()
/* 22*/ 		);
/* 22*/ 	} else if( m2runtime_strcmp(MagicConstants_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"__LINE__") == 0 ){
/* 23*/ 		return (
/* 23*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 23*/ 			push((char*) Globals_int_type),
/* 23*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 23*/ 			push((char*) m2runtime_itos( *(int *)m2runtime_dereference_rhs_RECORD(Scanner_here(), 1 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 6))),
/* 24*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 25*/ 			(RECORD*) pop()
/* 25*/ 		);
/* 25*/ 	} else if( (((Globals_php_ver == 5)) && (m2runtime_strcmp(MagicConstants_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"__NAMESPACE__") == 0)) ){
/* 26*/ 		return (
/* 26*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 26*/ 			push((char*) Globals_string_type),
/* 26*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 26*/ 			push((char*) m2runtime_concat_STRING(0, EMPTY_STRING, (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 7), (STRING *) 1)),
/* 27*/ 			*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 28*/ 			(RECORD*) pop()
/* 28*/ 		);
/* 28*/ 	} else if( m2runtime_strcmp(MagicConstants_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"__FUNCTION__") == 0 ){
/* 29*/ 		if( Globals_curr_func == NULL ){
/* 30*/ 			return (
/* 30*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 30*/ 				push((char*) Globals_string_type),
/* 30*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 30*/ 				push((char*) EMPTY_STRING),
/* 31*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 32*/ 				(RECORD*) pop()
/* 32*/ 			);
/* 32*/ 		} else {
/* 32*/ 			if( (Globals_php_ver == 4) ){
/* 33*/ 				return (
/* 33*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 33*/ 					push((char*) Globals_string_type),
/* 33*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 33*/ 					push((char*) (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 1 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 8)),
/* 34*/ 					*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 35*/ 					(RECORD*) pop()
/* 35*/ 				);
/* 35*/ 			} else {
/* 35*/ 				return (
/* 35*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 35*/ 					push((char*) Globals_string_type),
/* 35*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 35*/ 					push((char*) (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_func, 0 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 9)),
/* 36*/ 					*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 37*/ 					(RECORD*) pop()
/* 37*/ 				);
/* 38*/ 			}
/* 39*/ 		}
/* 39*/ 	} else if( m2runtime_strcmp(MagicConstants_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"__CLASS__") == 0 ){
/* 40*/ 		if( Globals_curr_class == NULL ){
/* 41*/ 			return (
/* 41*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 41*/ 				push((char*) Globals_string_type),
/* 41*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 41*/ 				push((char*) EMPTY_STRING),
/* 42*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 43*/ 				(RECORD*) pop()
/* 43*/ 			);
/* 43*/ 		} else {
/* 43*/ 			if( (Globals_php_ver == 4) ){
/* 44*/ 				return (
/* 44*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 44*/ 					push((char*) Globals_string_type),
/* 44*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 44*/ 					push((char*) (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 1 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 10)),
/* 45*/ 					*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 46*/ 					(RECORD*) pop()
/* 46*/ 				);
/* 46*/ 			} else {
/* 46*/ 				return (
/* 46*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 46*/ 					push((char*) Globals_string_type),
/* 46*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 46*/ 					push((char*) (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 0 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 11)),
/* 47*/ 					*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 48*/ 					(RECORD*) pop()
/* 48*/ 				);
/* 49*/ 			}
/* 50*/ 		}
/* 50*/ 	} else if( (((Globals_php_ver == 5)) && (m2runtime_strcmp(MagicConstants_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__METHOD__") == 0)) ){
/* 51*/ 		if( Globals_curr_method == NULL ){
/* 52*/ 			return (
/* 52*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 52*/ 				push((char*) Globals_string_type),
/* 52*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 52*/ 				push((char*) EMPTY_STRING),
/* 53*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 54*/ 				(RECORD*) pop()
/* 54*/ 			);
/* 54*/ 		} else {
/* 54*/ 			return (
/* 54*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/* 54*/ 				push((char*) Globals_string_type),
/* 54*/ 				*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/* 54*/ 				push((char*) (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_method, 0 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 12)),
/* 55*/ 				*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 56*/ 				(RECORD*) pop()
/* 56*/ 			);
/* 58*/ 		}
/* 58*/ 	} else {
/* 58*/ 		return (RECORD *)m2runtime_dereference_rhs_RECORD(MagicConstants_c, 4 * sizeof(void*) + 2 * sizeof(int), MagicConstants_0err_entry_get, 13);
/* 63*/ 	}
/* 63*/ 	m2runtime_missing_return(MagicConstants_0err_entry_get, 14);
/* 63*/ 	return NULL;
/* 65*/ }


char * MagicConstants_0func[] = {
    "Resolve"
};

int MagicConstants_0err_entry[] = {
    0 /* Resolve */, 11,
    0 /* Resolve */, 12,
    0 /* Resolve */, 12,
    0 /* Resolve */, 13,
    0 /* Resolve */, 17,
    0 /* Resolve */, 20,
    0 /* Resolve */, 23,
    0 /* Resolve */, 26,
    0 /* Resolve */, 33,
    0 /* Resolve */, 35,
    0 /* Resolve */, 44,
    0 /* Resolve */, 46,
    0 /* Resolve */, 54,
    0 /* Resolve */, 58,
    0 /* Resolve */, 62
};

void MagicConstants_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "MagicConstants";
    *f = MagicConstants_0func[ MagicConstants_0err_entry[2*i] ];
    *l = MagicConstants_0err_entry[2*i + 1];
}
