/* IMPLEMENTATION MODULE Classes */
#define M2_IMPORT_Classes

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif
/* 16*/ RECORD * Classes_ArrayAccessClass = NULL;
/* 16*/ RECORD * Classes_CountableClass = NULL;
/* 16*/ RECORD * Classes_IteratorAggregateClass = NULL;
/* 16*/ RECORD * Classes_IteratorClass = NULL;
/* 16*/ RECORD * Classes_TraversableClass = NULL;
/* 16*/ RECORD * Classes_ExceptionClass = NULL;

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_Search
#    include "Search.c"
#endif

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

void Classes_0err_entry_get(int i, char **m, char **f, int *l);

/* 11*/ void
/* 11*/ Classes_PreloadBuiltinSplClasses(void)
/* 11*/ {

/* 12*/ 	RECORD *
/* 12*/ 	Classes_grab(STRING *Classes_name)
/* 12*/ 	{
/* 14*/ 		RECORD * Classes_c = NULL;
/* 14*/ 		Classes_c = Search_SearchClassByAbsName(Classes_name, FALSE);
/* 15*/ 		if( Classes_c == NULL ){
/* 16*/ 			Scanner_Warning2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"missing expected class `", Classes_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"' in standard module spl", (STRING *) 1));
/* 19*/ 		}
/* 19*/ 		return Classes_c;
/* 24*/ 	}

/* 24*/ 	Classes_TraversableClass = Classes_grab((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"Traversable");
/* 25*/ 	Classes_IteratorClass = Classes_grab((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"Iterator");
/* 26*/ 	Classes_IteratorAggregateClass = Classes_grab((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"IteratorAggregate");
/* 27*/ 	Classes_CountableClass = Classes_grab((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"Countable");
/* 28*/ 	Classes_ArrayAccessClass = Classes_grab((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"ArrayAccess");
/* 32*/ }


/* 34*/ int
/* 34*/ Classes_IsSubclassOf(RECORD *Classes_child, RECORD *Classes_parent)
/* 34*/ {
/* 35*/ 	int Classes_i = 0;
/* 37*/ 	ARRAY * Classes_c = NULL;
/* 37*/ 	if( ((Classes_child == NULL) || (Classes_parent == NULL)) ){
/* 38*/ 		return FALSE;
/* 40*/ 	}
/* 40*/ 	if( Classes_child == Classes_parent ){
/* 41*/ 		return TRUE;
/* 43*/ 	}
/* 43*/ 	if( Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_child, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 0), Classes_parent) ){
/* 44*/ 		return TRUE;
/* 46*/ 	}
/* 46*/ 	Classes_c = (ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_child, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 1);
/* 47*/ 	{
/* 47*/ 		int m2runtime_for_limit_1;
/* 47*/ 		Classes_i = 0;
/* 47*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_c) - 1);
/* 48*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/* 48*/ 			if( Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_c, Classes_i, Classes_0err_entry_get, 2), Classes_parent) ){
/* 49*/ 				return TRUE;
/* 52*/ 			}
/* 52*/ 		}
/* 52*/ 	}
/* 52*/ 	return FALSE;
/* 56*/ }


/* 57*/ int
/* 57*/ Classes_IsSubclassOfSet(RECORD *Classes_c, ARRAY *Classes_set)
/* 57*/ {
/* 59*/ 	int Classes_i = 0;
/* 59*/ 	{
/* 59*/ 		int m2runtime_for_limit_1;
/* 59*/ 		Classes_i = 0;
/* 59*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_set) - 1);
/* 60*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/* 60*/ 			if( Classes_IsSubclassOf(Classes_c, (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_set, Classes_i, Classes_0err_entry_get, 3)) ){
/* 61*/ 				return TRUE;
/* 64*/ 			}
/* 64*/ 		}
/* 64*/ 	}
/* 64*/ 	return FALSE;
/* 68*/ }


/* 71*/ ARRAY *
/* 71*/ Classes_OrphanClasses(ARRAY *Classes_parents, ARRAY *Classes_children)
/* 71*/ {
/* 72*/ 	int Classes_i = 0;
/* 74*/ 	ARRAY * Classes_orphans = NULL;
/* 74*/ 	{
/* 74*/ 		int m2runtime_for_limit_1;
/* 74*/ 		Classes_i = 0;
/* 74*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_children) - 1);
/* 75*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/* 75*/ 			if( !Classes_IsSubclassOfSet((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_children, Classes_i, Classes_0err_entry_get, 4), Classes_parents) ){
/* 76*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_orphans, sizeof(void *), 1, Classes_0err_entry_get, 5) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_children, Classes_i, Classes_0err_entry_get, 6);
/* 79*/ 			}
/* 79*/ 		}
/* 79*/ 	}
/* 79*/ 	return Classes_orphans;
/* 83*/ }


/* 85*/ int
/* 85*/ Classes_IsExceptionClass(RECORD *Classes_c)
/* 85*/ {
/* 85*/ 	return Classes_IsSubclassOf(Classes_c, Classes_ExceptionClass);
/* 89*/ }


/* 91*/ ARRAY *
/* 91*/ Classes_CheckedExceptionsSubset(ARRAY *Classes_a)
/* 91*/ {
/* 92*/ 	int Classes_i = 0;
/* 94*/ 	ARRAY * Classes_b = NULL;
/* 94*/ 	{
/* 94*/ 		int m2runtime_for_limit_1;
/* 94*/ 		Classes_i = 0;
/* 94*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_a) - 1);
/* 95*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/* 95*/ 			if( ! *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_i, Classes_0err_entry_get, 7), 15 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 8) ){
/* 96*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_b, sizeof(void *), 1, Classes_0err_entry_get, 9) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_i, Classes_0err_entry_get, 10);
/* 99*/ 			}
/* 99*/ 		}
/* 99*/ 	}
/* 99*/ 	return Classes_b;
/*103*/ }


/*105*/ STRING *
/*105*/ Classes_ClassesList(ARRAY *Classes_set)
/*105*/ {
/*106*/ 	STRING * Classes_s = NULL;
/*108*/ 	int Classes_i = 0;
/*108*/ 	{
/*108*/ 		int m2runtime_for_limit_1;
/*108*/ 		Classes_i = 0;
/*108*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_set) - 1);
/*109*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*109*/ 			if( (Classes_i > 0) ){
/*110*/ 				Classes_s = m2runtime_concat_STRING(0, Classes_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", (STRING *) 1);
/*112*/ 			}
/*112*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_set, Classes_i, Classes_0err_entry_get, 11), 15 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 12) ){
/*113*/ 				Classes_s = m2runtime_concat_STRING(0, Classes_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"unchecked ", (STRING *) 1);
/*115*/ 			}
/*115*/ 			Classes_s = m2runtime_concat_STRING(0, Classes_s, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_set, Classes_i, Classes_0err_entry_get, 13), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 14), (STRING *) 1);
/*117*/ 		}
/*117*/ 	}
/*117*/ 	return Classes_s;
/*121*/ }


/*123*/ ARRAY *
/*123*/ Classes_CloneSet(ARRAY *Classes_set)
/*123*/ {
/*124*/ 	ARRAY * Classes_copy = NULL;
/*126*/ 	int Classes_i = 0;
/*126*/ 	{
/*126*/ 		int m2runtime_for_limit_1;
/*126*/ 		Classes_i = (m2runtime_count(Classes_set) - 1);
/*126*/ 		m2runtime_for_limit_1 = 0;
/*127*/ 		for( ; Classes_i >= m2runtime_for_limit_1; Classes_i -= 1 ){
/*127*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY(&Classes_copy, sizeof(void *), 1, Classes_i, Classes_0err_entry_get, 15) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_set, Classes_i, Classes_0err_entry_get, 16);
/*129*/ 		}
/*129*/ 	}
/*129*/ 	return Classes_copy;
/*133*/ }


/*135*/ ARRAY *
/*135*/ Classes_Sort(ARRAY *Classes_set)
/*135*/ {

/*137*/ 	int
/*137*/ 	Classes_cmp(RECORD *Classes_a, RECORD *Classes_b)
/*137*/ 	{
/*137*/ 		if( Classes_IsSubclassOf(Classes_a, Classes_b) ){
/*138*/ 			return -1;
/*139*/ 		} else if( Classes_IsSubclassOf(Classes_b, Classes_a) ){
/*140*/ 			return 1;
/*141*/ 		} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 15 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 17) && ! *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 15 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 18)) ){
/*142*/ 			return 1;
/*143*/ 		} else if( (! *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 15 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 19) &&  *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 15 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 20)) ){
/*144*/ 			return -1;
/*146*/ 		} else {
/*146*/ 			return m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Classes_a, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 21), (STRING *)m2runtime_dereference_rhs_RECORD(Classes_b, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 22));
/*149*/ 		}
/*149*/ 		m2runtime_missing_return(Classes_0err_entry_get, 23);
/*149*/ 		return 0;
/*151*/ 	}

/*152*/ 	int Classes_j = 0;
/*152*/ 	int Classes_i = 0;
/*153*/ 	RECORD * Classes_t = NULL;
/*155*/ 	ARRAY * Classes_new = NULL;
/*155*/ 	Classes_new = Classes_CloneSet(Classes_set);
/*156*/ 	{
/*156*/ 		int m2runtime_for_limit_1;
/*156*/ 		Classes_i = 0;
/*156*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_new) - 2);
/*157*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*157*/ 			{
/*157*/ 				int m2runtime_for_limit_2;
/*157*/ 				Classes_j = (Classes_i + 1);
/*157*/ 				m2runtime_for_limit_2 = (m2runtime_count(Classes_new) - 1);
/*158*/ 				for( ; Classes_j <= m2runtime_for_limit_2; Classes_j += 1 ){
/*158*/ 					if( (Classes_cmp((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_new, Classes_j, Classes_0err_entry_get, 24), (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_new, Classes_i, Classes_0err_entry_get, 25)) < 0) ){
/*159*/ 						Classes_t = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_new, Classes_i, Classes_0err_entry_get, 26);
/*160*/ 						*(RECORD **)m2runtime_dereference_lhs_ARRAY(&Classes_new, sizeof(void *), 1, Classes_i, Classes_0err_entry_get, 27) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_new, Classes_j, Classes_0err_entry_get, 28);
/*161*/ 						*(RECORD **)m2runtime_dereference_lhs_ARRAY(&Classes_new, sizeof(void *), 1, Classes_j, Classes_0err_entry_get, 29) = Classes_t;
/*164*/ 					}
/*165*/ 				}
/*165*/ 			}
/*165*/ 		}
/*165*/ 	}
/*165*/ 	return Classes_new;
/*169*/ }


/*175*/ STRING *
/*175*/ Classes_pc(RECORD *Classes_c1, RECORD *Classes_c2)
/*175*/ {
/*176*/ 	STRING * Classes_s = NULL;
/*178*/ 	int Classes_i = 0;
/*178*/ 	if( ((Classes_c1 == NULL) || (Classes_c2 == NULL)) ){
/*179*/ 		return NULL;
/*181*/ 	}
/*181*/ 	if( Classes_c1 == Classes_c2 ){
/*182*/ 		return (STRING *)m2runtime_dereference_rhs_RECORD(Classes_c1, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 30);
/*186*/ 	}
/*186*/ 	Classes_s = Classes_pc((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_c1, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 31), Classes_c2);
/*187*/ 	if( Classes_s != NULL ){
/*188*/ 		return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Classes_c1, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 32), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Classes_s, (STRING *) 1);
/*192*/ 	}
/*192*/ 	{
/*192*/ 		int m2runtime_for_limit_1;
/*192*/ 		Classes_i = 0;
/*192*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_c1, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 33)) - 1);
/*193*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*193*/ 			Classes_s = Classes_pc((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_c1, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 34), Classes_i, Classes_0err_entry_get, 35), Classes_c2);
/*194*/ 			if( Classes_s != NULL ){
/*195*/ 				return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Classes_c1, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 36), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", Classes_s, (STRING *) 1);
/*198*/ 			}
/*199*/ 		}
/*199*/ 	}
/*199*/ 	return NULL;
/*203*/ }


/*217*/ RECORD *
/*217*/ Classes_SearchMethod(RECORD *Classes_c, STRING *Classes_name, STRING *Classes_name_lower, int Classes_warn)
/*217*/ {
/*218*/ 	ARRAY * Classes_methods = NULL;
/*219*/ 	int Classes_i = 0;
/*220*/ 	RECORD * Classes_m = NULL;
/*222*/ 	STRING * Classes_action = NULL;
/*222*/ 	if( Classes_c == NULL ){
/*223*/ 		return NULL;
/*225*/ 	}
/*225*/ 	Classes_methods = (ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_c, 8 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 37);
/*226*/ 	{
/*226*/ 		int m2runtime_for_limit_1;
/*226*/ 		Classes_i = 0;
/*226*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_methods) - 1);
/*227*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*227*/ 			Classes_m = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_methods, Classes_i, Classes_0err_entry_get, 38);
/*228*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Classes_m, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 39), Classes_name_lower) == 0 ){
/*229*/ 				if( (Classes_warn && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Classes_m, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 40), Classes_name) != 0)) ){
/*230*/ 					if(  *(int *)m2runtime_dereference_rhs_RECORD(Classes_m, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 41) ){
/*231*/ 						Classes_action = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"implemented";
/*233*/ 					} else {
/*233*/ 						Classes_action = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"overridden";
/*235*/ 					}
/*235*/ 					Scanner_Notice(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"the name of the method `", Classes_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\41,\0,\0,\0)"()' differs from the name of the ", Classes_action, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)" method ", Scanner_mn(Classes_c, Classes_m), (STRING *) 1));
/*239*/ 				}
/*239*/ 				return Classes_m;
/*242*/ 			}
/*242*/ 		}
/*242*/ 	}
/*242*/ 	return NULL;
/*253*/ }


/*260*/ ARRAY *
/*260*/ Classes_MergeIConstArrays(ARRAY *Classes_a, ARRAY *Classes_b, int Classes_errorOnCollision)
/*260*/ {
/*261*/ 	ARRAY * Classes_c = NULL;
/*263*/ 	int Classes_j = 0;
/*263*/ 	int Classes_i = 0;
/*263*/ 	if( Classes_a == NULL ){
/*264*/ 		return Classes_b;
/*266*/ 	}
/*266*/ 	if( Classes_b == NULL ){
/*267*/ 		return Classes_a;
/*271*/ 	}
/*271*/ 	{
/*271*/ 		int m2runtime_for_limit_1;
/*271*/ 		Classes_i = (m2runtime_count(Classes_a) - 1);
/*271*/ 		m2runtime_for_limit_1 = 0;
/*272*/ 		for( ; Classes_i >= m2runtime_for_limit_1; Classes_i -= 1 ){
/*272*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_c, sizeof(void *), 1, Classes_0err_entry_get, 42) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_i, Classes_0err_entry_get, 43);
/*276*/ 		}
/*276*/ 	}
/*276*/ 	{
/*276*/ 		int m2runtime_for_limit_1;
/*276*/ 		Classes_i = 0;
/*276*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_b) - 1);
/*277*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*278*/ 			Classes_j = (m2runtime_count(Classes_a) - 1);
/*280*/ 			do{
/*280*/ 				if( (((Classes_j < 0)) || ((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 44), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 45) == (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 46), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 47))) ){
/*282*/ 					*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_c, sizeof(void *), 1, Classes_0err_entry_get, 48) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 49);
/*285*/ 					goto m2runtime_loop_1;
/*285*/ 				} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 50), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 51), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 52), (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 53), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 54), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 55)) == 0 ){
/*287*/ 					if( ( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 56), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 57), 15 * sizeof(void*) + 7 * sizeof(int), Classes_0err_entry_get, 58) ||  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 59), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 60), 15 * sizeof(void*) + 7 * sizeof(int), Classes_0err_entry_get, 61)) ){
/*291*/ 						if( Classes_errorOnCollision ){
/*292*/ 							Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"colliding inherited constants ", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 62), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 63), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 64), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 65), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 66), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 67), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 68), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 69), 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 70)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" and ", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 71), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 72), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 73), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 74), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 75), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 76), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 77), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 78), 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 79)), (STRING *) 1));
/*305*/ 						}
/*306*/ 					}
/*308*/ 					goto m2runtime_loop_1;
/*308*/ 				}
/*308*/ 				m2_inc(&Classes_j, -1);
/*311*/ 			}while(TRUE);
m2runtime_loop_1: ;
/*312*/ 		}
/*312*/ 	}
/*312*/ 	return Classes_c;
/*316*/ }


/*319*/ ARRAY *
/*319*/ Classes_CollectConsts(RECORD *Classes_cl, int Classes_errorOnCollision)
/*319*/ {
/*320*/ 	ARRAY * Classes_b = NULL;
/*320*/ 	ARRAY * Classes_a = NULL;
/*321*/ 	RECORD * Classes_c = NULL;
/*323*/ 	int Classes_i = 0;
/*323*/ 	if( Classes_cl == NULL ){
/*324*/ 		return NULL;
/*330*/ 	}
/*330*/ 	Classes_a = Classes_CollectConsts((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_cl, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 80), FALSE);
/*335*/ 	{
/*335*/ 		int m2runtime_for_limit_1;
/*335*/ 		Classes_i = 0;
/*335*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 81)) - 1);
/*336*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*336*/ 			Classes_b = Classes_CollectConsts((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 82), Classes_i, Classes_0err_entry_get, 83), FALSE);
/*337*/ 			Classes_a = Classes_MergeIConstArrays(Classes_a, Classes_b, Classes_errorOnCollision);
/*343*/ 		}
/*343*/ 	}
/*343*/ 	Classes_b = NULL;
/*344*/ 	{
/*344*/ 		int m2runtime_for_limit_1;
/*344*/ 		Classes_i = 0;
/*344*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 6 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 84)) - 1);
/*345*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*345*/ 			Classes_c = NULL;
/*346*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Classes_c, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 85) = Classes_cl;
/*347*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Classes_c, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 86) = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 6 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 87), Classes_i, Classes_0err_entry_get, 88);
/*348*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_b, sizeof(void *), 1, Classes_0err_entry_get, 89) = Classes_c;
/*350*/ 		}
/*350*/ 	}
/*350*/ 	Classes_a = Classes_MergeIConstArrays(Classes_b, Classes_a, Classes_errorOnCollision);
/*352*/ 	return Classes_a;
/*363*/ }


/*369*/ ARRAY *
/*369*/ Classes_MergeIPropArrays(ARRAY *Classes_a, ARRAY *Classes_b, int Classes_errorOnCollision)
/*369*/ {
/*370*/ 	ARRAY * Classes_c = NULL;
/*371*/ 	int Classes_j = 0;
/*371*/ 	int Classes_i = 0;
/*373*/ 	STRING * Classes_hint = NULL;
/*373*/ 	if( Classes_a == NULL ){
/*374*/ 		return Classes_b;
/*376*/ 	}
/*376*/ 	if( Classes_b == NULL ){
/*377*/ 		return Classes_a;
/*381*/ 	}
/*381*/ 	{
/*381*/ 		int m2runtime_for_limit_1;
/*381*/ 		Classes_i = (m2runtime_count(Classes_a) - 1);
/*381*/ 		m2runtime_for_limit_1 = 0;
/*382*/ 		for( ; Classes_i >= m2runtime_for_limit_1; Classes_i -= 1 ){
/*382*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_c, sizeof(void *), 1, Classes_0err_entry_get, 90) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_i, Classes_0err_entry_get, 91);
/*386*/ 		}
/*386*/ 	}
/*386*/ 	{
/*386*/ 		int m2runtime_for_limit_1;
/*386*/ 		Classes_i = 0;
/*386*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_b) - 1);
/*387*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*388*/ 			Classes_j = (m2runtime_count(Classes_a) - 1);
/*390*/ 			do{
/*390*/ 				if( (((Classes_j < 0)) || ((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 92), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 93) == (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 94), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 95))) ){
/*392*/ 					*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_c, sizeof(void *), 1, Classes_0err_entry_get, 96) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 97);
/*395*/ 					goto m2runtime_loop_1;
/*395*/ 				} else if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 98), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 99), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 100), (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 101), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 102), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 103)) == 0) && ((((Globals_php_ver == 4)) || (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 104), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 105), 6 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 106) != 0)) || (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 107), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 108), 6 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 109) != 0))))) ){
/*402*/ 					if( Classes_errorOnCollision ){
/*403*/ 						if( (Globals_php_ver == 4) ){
/*404*/ 							Classes_hint = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\162,\0,\0,\0)". Private properties cannot be re-defined nor public|protected properties can be overridden (PHPLint restriction).";
/*406*/ 						} else {
/*406*/ 							Classes_hint = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\111,\0,\0,\0)". Public|protected properties cannot be overridden (PHPLint restriction).";
/*408*/ 						}
/*408*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"colliding inherited properties ", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 110), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 111), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 112), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 113), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 114), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 115), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 116), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 117), 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 118)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" and ", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 119), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 120), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 121), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 122), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 123), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 124), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 125), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 126), 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 127)), Classes_hint, (STRING *) 1));
/*418*/ 					}
/*420*/ 					goto m2runtime_loop_1;
/*420*/ 				}
/*420*/ 				m2_inc(&Classes_j, -1);
/*423*/ 			}while(TRUE);
m2runtime_loop_1: ;
/*424*/ 		}
/*424*/ 	}
/*424*/ 	return Classes_c;
/*428*/ }


/*431*/ ARRAY *
/*431*/ Classes_CollectProps(RECORD *Classes_cl, int Classes_errorOnCollision)
/*431*/ {
/*432*/ 	ARRAY * Classes_b = NULL;
/*432*/ 	ARRAY * Classes_a = NULL;
/*433*/ 	RECORD * Classes_p = NULL;
/*435*/ 	int Classes_i = 0;
/*435*/ 	if( Classes_cl == NULL ){
/*436*/ 		return NULL;
/*442*/ 	}
/*442*/ 	Classes_a = Classes_CollectProps((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_cl, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 128), FALSE);
/*459*/ 	Classes_b = NULL;
/*460*/ 	{
/*460*/ 		int m2runtime_for_limit_1;
/*460*/ 		Classes_i = 0;
/*460*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 7 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 129)) - 1);
/*461*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*461*/ 			Classes_p = NULL;
/*462*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Classes_p, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 130) = Classes_cl;
/*463*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Classes_p, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 131) = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 7 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 132), Classes_i, Classes_0err_entry_get, 133);
/*464*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_b, sizeof(void *), 1, Classes_0err_entry_get, 134) = Classes_p;
/*466*/ 		}
/*466*/ 	}
/*466*/ 	Classes_a = Classes_MergeIPropArrays(Classes_b, Classes_a, Classes_errorOnCollision);
/*468*/ 	return Classes_a;
/*480*/ }


/*486*/ ARRAY *
/*486*/ Classes_MergeIMethodArrays(ARRAY *Classes_a, ARRAY *Classes_b, int Classes_errorOnCollision)
/*486*/ {
/*487*/ 	ARRAY * Classes_c = NULL;
/*488*/ 	int Classes_j = 0;
/*488*/ 	int Classes_i = 0;
/*490*/ 	RECORD * Classes_bm = NULL;
/*490*/ 	RECORD * Classes_am = NULL;
/*490*/ 	if( Classes_a == NULL ){
/*491*/ 		return Classes_b;
/*493*/ 	}
/*493*/ 	if( Classes_b == NULL ){
/*494*/ 		return Classes_a;
/*498*/ 	}
/*498*/ 	{
/*498*/ 		int m2runtime_for_limit_1;
/*498*/ 		Classes_i = (m2runtime_count(Classes_a) - 1);
/*498*/ 		m2runtime_for_limit_1 = 0;
/*499*/ 		for( ; Classes_i >= m2runtime_for_limit_1; Classes_i -= 1 ){
/*499*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_c, sizeof(void *), 1, Classes_0err_entry_get, 135) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_i, Classes_0err_entry_get, 136);
/*503*/ 		}
/*503*/ 	}
/*503*/ 	{
/*503*/ 		int m2runtime_for_limit_1;
/*503*/ 		Classes_i = 0;
/*503*/ 		m2runtime_for_limit_1 = (m2runtime_count(Classes_b) - 1);
/*504*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*505*/ 			Classes_j = (m2runtime_count(Classes_a) - 1);
/*507*/ 			do{
/*507*/ 				if( (((Classes_j < 0)) || ((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 137), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 138) == (RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 139), 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 140))) ){
/*509*/ 					*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_c, sizeof(void *), 1, Classes_0err_entry_get, 141) = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 142);
/*512*/ 					goto m2runtime_loop_1;
/*513*/ 				}
/*513*/ 				Classes_am = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_a, Classes_j, Classes_0err_entry_get, 143);
/*514*/ 				Classes_bm = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_b, Classes_i, Classes_0err_entry_get, 144);
/*516*/ 				if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_am, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 145), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 146), (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_bm, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 147), 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 148)) == 0) && ((((Globals_php_ver == 4)) || (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_am, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 149), 9 * sizeof(void*) + 4 * sizeof(int), Classes_0err_entry_get, 150) != 0)) || (( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_am, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 151), 9 * sizeof(void*) + 4 * sizeof(int), Classes_0err_entry_get, 152) != 0))))) ){
/*523*/ 					if( Classes_errorOnCollision ){
/*524*/ 						Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"colliding inherited methods ", Scanner_mn((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_am, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 153), (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_am, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 154)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_am, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 155), 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 156)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)" and ", Scanner_mn((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_bm, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 157), (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_bm, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 158)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_bm, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 159), 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 160)), (STRING *) 1));
/*533*/ 					}
/*535*/ 					goto m2runtime_loop_1;
/*535*/ 				}
/*535*/ 				m2_inc(&Classes_j, -1);
/*538*/ 			}while(TRUE);
m2runtime_loop_1: ;
/*539*/ 		}
/*539*/ 	}
/*539*/ 	return Classes_c;
/*543*/ }


/*546*/ ARRAY *
/*546*/ Classes_CollectMethods(RECORD *Classes_cl, int Classes_errorOnCollision)
/*546*/ {
/*547*/ 	ARRAY * Classes_b = NULL;
/*547*/ 	ARRAY * Classes_a = NULL;
/*548*/ 	RECORD * Classes_m = NULL;
/*550*/ 	int Classes_i = 0;
/*550*/ 	if( Classes_cl == NULL ){
/*551*/ 		return NULL;
/*562*/ 	}
/*562*/ 	{
/*562*/ 		int m2runtime_for_limit_1;
/*562*/ 		Classes_i = 0;
/*562*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 161)) - 1);
/*563*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*563*/ 			Classes_b = Classes_CollectMethods((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 162), Classes_i, Classes_0err_entry_get, 163), FALSE);
/*564*/ 			Classes_a = Classes_MergeIMethodArrays(Classes_a, Classes_b, Classes_errorOnCollision);
/*570*/ 		}
/*570*/ 	}
/*570*/ 	Classes_b = NULL;
/*571*/ 	{
/*571*/ 		int m2runtime_for_limit_1;
/*571*/ 		Classes_i = 0;
/*571*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 8 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 164)) - 1);
/*572*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*572*/ 			Classes_m = NULL;
/*573*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Classes_m, 2 * sizeof(void*) + 2 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 165) = Classes_cl;
/*574*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&Classes_m, 2 * sizeof(void*) + 2 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 166) = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_cl, 8 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 167), Classes_i, Classes_0err_entry_get, 168);
/*575*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Classes_b, sizeof(void *), 1, Classes_0err_entry_get, 169) = Classes_m;
/*577*/ 		}
/*577*/ 	}
/*577*/ 	Classes_a = Classes_MergeIMethodArrays(Classes_b, Classes_a, Classes_errorOnCollision);
/*579*/ 	return Classes_a;
/*584*/ }


/*586*/ void
/*586*/ Classes_CheckCollisionsBetweenExtendedAndImplementedClasses(RECORD *Classes_cl)
/*586*/ {
/*587*/ 	ARRAY * Classes_ic = NULL;
/*588*/ 	ARRAY * Classes_ip = NULL;
/*590*/ 	ARRAY * Classes_im = NULL;
/*595*/ 	Classes_ic = Classes_CollectConsts(Classes_cl, TRUE);
/*608*/ 	Classes_ip = Classes_CollectProps(Classes_cl, TRUE);
/*613*/ 	Classes_im = Classes_CollectMethods(Classes_cl, TRUE);
/*618*/ }


/*644*/ int
/*644*/ Classes_IsOverridingType(RECORD *Classes_a, RECORD *Classes_b)
/*644*/ {
/*644*/ 	if( ((Classes_a == NULL) && (Classes_b == NULL)) ){
/*645*/ 		return TRUE;
/*648*/ 	}
/*648*/ 	if( ((Classes_a == NULL) || (Classes_b == NULL)) ){
/*649*/ 		return FALSE;
/*652*/ 	}
/*652*/ 	if( Types_SameType(Classes_a, Classes_b) ){
/*653*/ 		return TRUE;
/*656*/ 	}
/*656*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 170)){

/*658*/ 	case 7:
/*660*/ 	return ((( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 171) == 5)) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 172) == 6)) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 173) == 7)) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 174) == 8)) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 175) == 9)));
/*666*/ 	break;

/*666*/ 	case 9:
/*667*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 176) == NULL ){
/*669*/ 		return ((( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 177) == 5)) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 178) == 6)) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 179) == 7)) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 180) == 8)) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 181) == 9)));
/*676*/ 	} else {
/*676*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 182) == 9) ){
/*677*/ 			return Classes_IsSubclassOf((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 183), (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 184));
/*679*/ 		} else {
/*679*/ 			return FALSE;
/*683*/ 		}
/*685*/ 	}
/*685*/ 	break;

/*685*/ 	default:
/*685*/ 	return FALSE;
/*689*/ 	}
/*689*/ 	m2runtime_missing_return(Classes_0err_entry_get, 185);
/*689*/ 	return 0;
/*691*/ }


/*698*/ void
/*698*/ Classes_CheckOverridesImplements(RECORD *Classes_ac, RECORD *Classes_a, RECORD *Classes_bc, RECORD *Classes_b)
/*698*/ {

/*705*/ 	STRING *
/*705*/ 	Classes_CheckSign(RECORD *Classes_a, RECORD *Classes_b)
/*705*/ 	{

/*707*/ 		int
/*707*/ 		Classes_eqbool(int Classes_a, int Classes_b)
/*707*/ 		{
/*707*/ 			return ((Classes_a && Classes_b) || (!Classes_a && !Classes_b));
/*711*/ 		}

/*712*/ 		int Classes_b_n = 0;
/*712*/ 		int Classes_b_m = 0;
/*712*/ 		int Classes_a_n = 0;
/*712*/ 		int Classes_a_m = 0;
/*712*/ 		int Classes_i = 0;
/*714*/ 		RECORD * Classes_b_arg = NULL;
/*714*/ 		RECORD * Classes_a_arg = NULL;
/*718*/ 		if( !Classes_IsOverridingType((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 186), (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 187)) ){
/*719*/ 			return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"incompatible return types";
/*725*/ 		}
/*725*/ 		Classes_a_m =  *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 2 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 188);
/*725*/ 		Classes_a_n = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_a, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 189)) - Classes_a_m);
/*726*/ 		Classes_b_m =  *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 190);
/*726*/ 		Classes_b_n = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_b, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 191)) - Classes_b_m);
/*728*/ 		if( (Classes_a_m != Classes_b_m) ){
/*729*/ 			return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"different number of mandatory arguments";
/*732*/ 		}
/*732*/ 		if( (Classes_b_n < Classes_a_n) ){
/*733*/ 			return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"too few default arguments";
/*736*/ 		}
/*736*/ 		{
/*736*/ 			int m2runtime_for_limit_1;
/*736*/ 			Classes_i = 0;
/*736*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_a, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 192)) - 1);
/*737*/ 			for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*738*/ 				Classes_a_arg = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_a, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 193), Classes_i, Classes_0err_entry_get, 194);
/*739*/ 				Classes_b_arg = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_b, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 195), Classes_i, Classes_0err_entry_get, 196);
/*744*/ 				if( (!Classes_eqbool( *(int *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 197),  *(int *)m2runtime_dereference_rhs_RECORD(Classes_b_arg, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 198)) || !Classes_eqbool( *(int *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 3 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 199),  *(int *)m2runtime_dereference_rhs_RECORD(Classes_b_arg, 3 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 200))) ){
/*747*/ 					return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"invalid passing method in argument no. ", m2runtime_itos(((Classes_i + 1))), (STRING *) 1);
/*753*/ 				}
/*753*/ 				if( !((( *(int *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 201) &&  *(int *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 3 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 202) && Classes_IsOverridingType((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 203), (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b_arg, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 204))) || ( *(int *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 205) && ! *(int *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 3 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 206) && Types_SameType((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b_arg, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 207), (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 208))) || (! *(int *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 209) && Classes_IsOverridingType((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b_arg, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 210), (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a_arg, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 211))))) ){
/*772*/ 					return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\55,\0,\0,\0)"incompatible type in overriding argument no. ", m2runtime_itos(((Classes_i + 1))), (STRING *) 1);
/*775*/ 				}
/*779*/ 			}
/*779*/ 		}
/*779*/ 		if( ( *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 2 * sizeof(void*) + 4 * sizeof(int), Classes_0err_entry_get, 212) && ! *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 4 * sizeof(int), Classes_0err_entry_get, 213)) ){
/*780*/ 			return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"required variable number of arguments /*.args.*/";
/*783*/ 		}
/*783*/ 		return NULL;
/*787*/ 	}

/*788*/ 	STRING * Classes_t = NULL;
/*790*/ 	STRING * Classes_err = NULL;
/*795*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 214) &&  *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 215)) ){
/*796*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 216), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"abstract method ", Scanner_mn(Classes_bc, Classes_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)" redeclares inherited abstract method ", Scanner_mn(Classes_ac, Classes_a), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)" (PHP restriction)", (STRING *) 1));
/*801*/ 	}
/*801*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 217) ){
/*802*/ 		Classes_t = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"implemented";
/*804*/ 	} else {
/*804*/ 		Classes_t = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"overridden";
/*808*/ 	}
/*808*/ 	if( (! *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 218) &&  *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 219)) ){
/*809*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 220), m2runtime_concat_STRING(0, Scanner_mn(Classes_bc, Classes_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)": cannot make abstract the ", Classes_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)" non-abstract method ", Scanner_mn(Classes_ac, Classes_a), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 221)), (STRING *) 1));
/*815*/ 	}
/*815*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 9 * sizeof(void*) + 5 * sizeof(int), Classes_0err_entry_get, 222) && ! *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 9 * sizeof(void*) + 5 * sizeof(int), Classes_0err_entry_get, 223)) ){
/*816*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 224), m2runtime_concat_STRING(0, Scanner_mn(Classes_bc, Classes_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)": cannot make static the ", Classes_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)" non-static method ", Scanner_mn(Classes_ac, Classes_a), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 225)), (STRING *) 1));
/*819*/ 	} else if( (! *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 9 * sizeof(void*) + 5 * sizeof(int), Classes_0err_entry_get, 226) &&  *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 9 * sizeof(void*) + 5 * sizeof(int), Classes_0err_entry_get, 227)) ){
/*820*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 228), m2runtime_concat_STRING(0, Scanner_mn(Classes_bc, Classes_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)": cannot make non-static the ", Classes_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)" static method ", Scanner_mn(Classes_ac, Classes_a), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 229)), (STRING *) 1));
/*826*/ 	}
/*826*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 9 * sizeof(void*) + 6 * sizeof(int), Classes_0err_entry_get, 230) ){
/*827*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 231), m2runtime_concat_STRING(0, Scanner_mn(Classes_bc, Classes_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)": cannot override final method ", Scanner_mn(Classes_ac, Classes_a), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 232)), (STRING *) 1));
/*832*/ 	}
/*832*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Classes_b, 9 * sizeof(void*) + 4 * sizeof(int), Classes_0err_entry_get, 233) <  *(int *)m2runtime_dereference_rhs_RECORD(Classes_a, 9 * sizeof(void*) + 4 * sizeof(int), Classes_0err_entry_get, 234)) ){
/*833*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 235), m2runtime_concat_STRING(0, Scanner_mn(Classes_bc, Classes_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)": cannot lower the visibility of the ", Classes_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)" method ", Scanner_mn(Classes_ac, Classes_a), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 236)), (STRING *) 1));
/*838*/ 	}
/*838*/ 	Classes_err = Classes_CheckSign((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 237), (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 238));
/*839*/ 	if( Classes_err != NULL ){
/*840*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 239), m2runtime_concat_STRING(0, Scanner_mn(Classes_bc, Classes_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)": the signature `", Types_FunctionSignatureToString((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 240)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' does not match the ", Classes_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)" method ", Scanner_mn(Classes_ac, Classes_a), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 241)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)" with signature `", Types_FunctionSignatureToString((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 242)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"': ", Classes_err, (STRING *) 1));
/*848*/ 	}
/*848*/ 	Classes_err = Classes_ClassesList(Classes_Sort(Classes_OrphanClasses(Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_a, 5 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 243)), Classes_CheckedExceptionsSubset((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_b, 5 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 244)))));
/*856*/ 	if( Classes_err != NULL ){
/*857*/ 		Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_b, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 245), m2runtime_concat_STRING(0, Scanner_mn(Classes_bc, Classes_b), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)": more exceptions thrown than declared in ", Classes_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)" method ", Scanner_mn(Classes_ac, Classes_a), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)" declared in ", Scanner_reference((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_a, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 246)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", Classes_err, (STRING *) 1));
/*862*/ 	}
/*864*/ }


/*866*/ void
/*866*/ Classes_ResolveClassMethod(RECORD *Classes_class, STRING *Classes_id, RECORD **Classes_res_class, RECORD **Classes_res_method)
/*866*/ {
/*867*/ 	int Classes_i = 0;
/*869*/ 	RECORD * Classes_m = NULL;
/*869*/ 	if( Classes_class == NULL ){
/*870*/ 		*Classes_res_class = NULL;
/*871*/ 		*Classes_res_method = NULL;
/*873*/ 		return ;
/*876*/ 	}
/*876*/ 	Classes_m = Search_SearchClassMethod(Classes_class, Classes_id, TRUE);
/*877*/ 	if( Classes_m != NULL ){
/*879*/ 		*Classes_res_class = Classes_class;
/*880*/ 		*Classes_res_method = Classes_m;
/*882*/ 		return ;
/*885*/ 	}
/*885*/ 	Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_class, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 247), Classes_id, Classes_res_class, Classes_res_method);
/*886*/ 	if( *Classes_res_method != NULL ){
/*888*/ 		return ;
/*891*/ 	}
/*891*/ 	{
/*891*/ 		int m2runtime_for_limit_1;
/*891*/ 		Classes_i = 0;
/*891*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_class, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 248)) - 1);
/*892*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*892*/ 			Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_class, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 249), Classes_i, Classes_0err_entry_get, 250), Classes_id, Classes_res_class, Classes_res_method);
/*893*/ 			if( *Classes_res_method != NULL ){
/*895*/ 				return ;
/*897*/ 			}
/*899*/ 		}
/*899*/ 	}
/*899*/ 	*Classes_res_class = NULL;
/*900*/ 	*Classes_res_method = NULL;
/*904*/ }


/*908*/ void
/*908*/ Classes_CheckImplementedMethodsRecurse(RECORD *Classes_child, RECORD *Classes_ancestor)
/*908*/ {
/*909*/ 	ARRAY * Classes_ancestor_methods = NULL;
/*910*/ 	int Classes_i = 0;
/*911*/ 	RECORD * Classes_a_m = NULL;
/*912*/ 	RECORD * Classes_r_c = NULL;
/*914*/ 	RECORD * Classes_r_m = NULL;
/*914*/ 	if( Classes_ancestor == NULL ){
/*916*/ 		return ;
/*917*/ 	}
/*917*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Classes_ancestor, 15 * sizeof(void*) + 6 * sizeof(int), Classes_0err_entry_get, 251) ||  *(int *)m2runtime_dereference_rhs_RECORD(Classes_ancestor, 15 * sizeof(void*) + 7 * sizeof(int), Classes_0err_entry_get, 252)) ){
/*918*/ 		Classes_ancestor_methods = (ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_ancestor, 8 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 253);
/*919*/ 		{
/*919*/ 			int m2runtime_for_limit_1;
/*919*/ 			Classes_i = 0;
/*919*/ 			m2runtime_for_limit_1 = (m2runtime_count(Classes_ancestor_methods) - 1);
/*920*/ 			for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*920*/ 				Classes_a_m = (RECORD *)m2runtime_dereference_rhs_ARRAY(Classes_ancestor_methods, Classes_i, Classes_0err_entry_get, 254);
/*921*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Classes_a_m, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 255) ){
/*922*/ 					Classes_ResolveClassMethod(Classes_child, (STRING *)m2runtime_dereference_rhs_RECORD(Classes_a_m, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 256), &Classes_r_c, &Classes_r_m);
/*923*/ 					if( ((Classes_r_m == NULL) ||  *(int *)m2runtime_dereference_rhs_RECORD(Classes_r_m, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 257)) ){
/*924*/ 						Scanner_Error2((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_child, 12 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 258), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"in class `", (STRING *)m2runtime_dereference_rhs_RECORD(Classes_child, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 259), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\61,\0,\0,\0)"': missing implementation of the abstract method ", Scanner_mn(Classes_ancestor, Classes_a_m), (STRING *) 1));
/*929*/ 					}
/*930*/ 				}
/*931*/ 			}
/*931*/ 		}
/*932*/ 	}
/*932*/ 	Classes_CheckImplementedMethodsRecurse(Classes_child, (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_ancestor, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 260));
/*934*/ 	{
/*934*/ 		int m2runtime_for_limit_1;
/*934*/ 		Classes_i = 0;
/*934*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_ancestor, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 261)) - 1);
/*935*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*935*/ 			Classes_CheckImplementedMethodsRecurse(Classes_child, (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_ancestor, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 262), Classes_i, Classes_0err_entry_get, 263));
/*938*/ 		}
/*938*/ 	}
/*940*/ }


/*942*/ void
/*942*/ Classes_CheckImplementedMethods(RECORD *Classes_child)
/*942*/ {
/*944*/ 	int Classes_i = 0;
/*944*/ 	Classes_CheckImplementedMethodsRecurse(Classes_child, (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_child, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 264));
/*946*/ 	{
/*946*/ 		int m2runtime_for_limit_1;
/*946*/ 		Classes_i = 0;
/*946*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_child, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 265)) - 1);
/*947*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*947*/ 			Classes_CheckImplementedMethodsRecurse(Classes_child, (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_child, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 266), Classes_i, Classes_0err_entry_get, 267));
/*950*/ 		}
/*950*/ 	}
/*952*/ }


/*958*/ void
/*958*/ Classes_CheckOverriddenMethod(RECORD *Classes_c, RECORD *Classes_m)
/*958*/ {
/*959*/ 	RECORD * Classes_o_c = NULL;
/*960*/ 	RECORD * Classes_o_m = NULL;
/*963*/ 	int Classes_i = 0;

/*968*/ 	void
/*968*/ 	Classes_CheckImplementation(RECORD *Classes_c, RECORD *Classes_m, RECORD *Classes_if)
/*968*/ 	{
/*969*/ 		RECORD * Classes_i_m = NULL;
/*971*/ 		int Classes_i = 0;
/*971*/ 		if( Classes_if == NULL ){
/*973*/ 			return ;
/*974*/ 		}
/*974*/ 		Classes_i_m = Classes_SearchMethod(Classes_if, (STRING *)m2runtime_dereference_rhs_RECORD(Classes_m, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 268), (STRING *)m2runtime_dereference_rhs_RECORD(Classes_m, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 269), TRUE);
/*975*/ 		if( Classes_i_m != NULL ){
/*976*/ 			Classes_CheckOverridesImplements(Classes_if, Classes_i_m, Classes_c, Classes_m);
/*978*/ 		}
/*978*/ 		{
/*978*/ 			int m2runtime_for_limit_1;
/*978*/ 			Classes_i = 0;
/*978*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_if, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 270)) - 1);
/*979*/ 			for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*979*/ 				Classes_CheckImplementation(Classes_c, Classes_m, (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_if, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 271), Classes_i, Classes_0err_entry_get, 272));
/*982*/ 			}
/*982*/ 		}
/*984*/ 	}

/*988*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_c, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 273) != NULL ){
/*989*/ 		Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_c, 3 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 274), (STRING *)m2runtime_dereference_rhs_RECORD(Classes_m, 0 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 275), &Classes_o_c, &Classes_o_m);
/*990*/ 		if( Classes_o_m == NULL ){
/*992*/ 		} else if( ((Classes_o_m == (RECORD *)m2runtime_dereference_rhs_RECORD(Classes_o_c, 9 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 276)) && ! *(int *)m2runtime_dereference_rhs_RECORD(Classes_o_m, 9 * sizeof(void*) + 3 * sizeof(int), Classes_0err_entry_get, 277)) ){
/*994*/ 		} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Classes_o_m, 9 * sizeof(void*) + 6 * sizeof(int), Classes_0err_entry_get, 278) ){
/*995*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the method ", Scanner_mn(Classes_c, Classes_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)" cannot override the final method ", Scanner_mn(Classes_o_c, Classes_o_m), (STRING *) 1));
/*997*/ 		} else if( ((( *(int *)m2runtime_dereference_rhs_RECORD(Classes_o_m, 9 * sizeof(void*) + 4 * sizeof(int), Classes_0err_entry_get, 279) == 0)) && ((Globals_php_ver == 4))) ){
/*998*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the method ", Scanner_mn(Classes_c, Classes_m), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)" cannot redefine the private method ", Scanner_mn(Classes_o_c, Classes_o_m), (STRING *) 1));
/*1001*/ 		} else {
/*1001*/ 			Classes_CheckOverridesImplements(Classes_o_c, Classes_o_m, Classes_c, Classes_m);
/*1004*/ 		}
/*1005*/ 	}
/*1005*/ 	{
/*1005*/ 		int m2runtime_for_limit_1;
/*1005*/ 		Classes_i = 0;
/*1005*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_c, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 280)) - 1);
/*1006*/ 		for( ; Classes_i <= m2runtime_for_limit_1; Classes_i += 1 ){
/*1006*/ 			Classes_CheckImplementation(Classes_c, Classes_m, (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Classes_c, 4 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 281), Classes_i, Classes_0err_entry_get, 282));
/*1009*/ 		}
/*1009*/ 	}
/*1011*/ }


/*1016*/ void
/*1016*/ Classes_CheckTraversableUsage(RECORD *Classes_class)
/*1016*/ {
/*1018*/ 	int Classes_b2 = 0;
/*1018*/ 	int Classes_b1 = 0;
/*1018*/ 	if( (Globals_php_ver == 4) ){
/*1020*/ 		return ;
/*1022*/ 	}
/*1022*/ 	if( !Classes_IsSubclassOf(Classes_class, Classes_TraversableClass) ){
/*1024*/ 		return ;
/*1027*/ 	}
/*1027*/ 	Classes_b1 = Classes_IsSubclassOf(Classes_class, Classes_IteratorClass);
/*1028*/ 	Classes_b2 = Classes_IsSubclassOf(Classes_class, Classes_IteratorAggregateClass);
/*1030*/ 	if( (Classes_b1 && Classes_b2) ){
/*1031*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\67,\0,\0,\0)"can't implement both `Iterator' and `IteratorAggregate'");
/*1034*/ 	}
/*1034*/ 	if( (Classes_b1 || Classes_b2) ){
/*1037*/ 		return ;
/*1039*/ 	}
/*1039*/ 	Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\142,\0,\0,\0)"classes that implements `Traversable' must also either implement `Iterator' or `IteratorAggregate'");
/*1043*/ }


/*1045*/ int
/*1045*/ Classes_IsObjectConvertibleToString(RECORD *Classes_t)
/*1045*/ {
/*1046*/ 	RECORD * Classes_found_class = NULL;
/*1048*/ 	RECORD * Classes_found_method = NULL;
/*1048*/ 	if( ((Classes_t == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(Classes_t, 2 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 283) != 9)) || ((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_t, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 284) == NULL)) ){
/*1049*/ 		return FALSE;
/*1051*/ 	}
/*1051*/ 	Classes_ResolveClassMethod((RECORD *)m2runtime_dereference_rhs_RECORD(Classes_t, 1 * sizeof(void*) + 2 * sizeof(int), Classes_0err_entry_get, 285), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"__toString", &Classes_found_class, &Classes_found_method);
/*1052*/ 	return Classes_found_method != NULL;
/*1057*/ }


char * Classes_0func[] = {
    "IsSubclassOf",
    "IsSubclassOfSet",
    "OrphanClasses",
    "CheckedExceptionsSubset",
    "ClassesList",
    "CloneSet",
    "cmp",
    "Sort",
    "pc",
    "SearchMethod",
    "MergeIConstArrays",
    "CollectConsts",
    "MergeIPropArrays",
    "CollectProps",
    "MergeIMethodArrays",
    "CollectMethods",
    "IsOverridingType",
    "CheckSign",
    "CheckOverridesImplements",
    "ResolveClassMethod",
    "CheckImplementedMethodsRecurse",
    "CheckImplementedMethods",
    "CheckImplementation",
    "CheckOverriddenMethod",
    "IsObjectConvertibleToString"
};

int Classes_0err_entry[] = {
    0 /* IsSubclassOf */, 43,
    0 /* IsSubclassOf */, 46,
    0 /* IsSubclassOf */, 48,
    1 /* IsSubclassOfSet */, 60,
    2 /* OrphanClasses */, 75,
    2 /* OrphanClasses */, 76,
    2 /* OrphanClasses */, 77,
    3 /* CheckedExceptionsSubset */, 95,
    3 /* CheckedExceptionsSubset */, 95,
    3 /* CheckedExceptionsSubset */, 96,
    3 /* CheckedExceptionsSubset */, 97,
    4 /* ClassesList */, 112,
    4 /* ClassesList */, 112,
    4 /* ClassesList */, 115,
    4 /* ClassesList */, 115,
    5 /* CloneSet */, 127,
    5 /* CloneSet */, 128,
    6 /* cmp */, 141,
    6 /* cmp */, 141,
    6 /* cmp */, 143,
    6 /* cmp */, 143,
    6 /* cmp */, 146,
    6 /* cmp */, 146,
    6 /* cmp */, 148,
    7 /* Sort */, 158,
    7 /* Sort */, 158,
    7 /* Sort */, 160,
    7 /* Sort */, 160,
    7 /* Sort */, 161,
    7 /* Sort */, 161,
    8 /* pc */, 182,
    8 /* pc */, 186,
    8 /* pc */, 188,
    8 /* pc */, 192,
    8 /* pc */, 193,
    8 /* pc */, 193,
    8 /* pc */, 195,
    9 /* SearchMethod */, 225,
    9 /* SearchMethod */, 228,
    9 /* SearchMethod */, 228,
    9 /* SearchMethod */, 229,
    9 /* SearchMethod */, 230,
    10 /* MergeIConstArrays */, 272,
    10 /* MergeIConstArrays */, 273,
    10 /* MergeIConstArrays */, 280,
    10 /* MergeIConstArrays */, 280,
    10 /* MergeIConstArrays */, 280,
    10 /* MergeIConstArrays */, 280,
    10 /* MergeIConstArrays */, 282,
    10 /* MergeIConstArrays */, 283,
    10 /* MergeIConstArrays */, 285,
    10 /* MergeIConstArrays */, 285,
    10 /* MergeIConstArrays */, 285,
    10 /* MergeIConstArrays */, 285,
    10 /* MergeIConstArrays */, 285,
    10 /* MergeIConstArrays */, 285,
    10 /* MergeIConstArrays */, 287,
    10 /* MergeIConstArrays */, 287,
    10 /* MergeIConstArrays */, 287,
    10 /* MergeIConstArrays */, 287,
    10 /* MergeIConstArrays */, 287,
    10 /* MergeIConstArrays */, 287,
    10 /* MergeIConstArrays */, 293,
    10 /* MergeIConstArrays */, 293,
    10 /* MergeIConstArrays */, 293,
    10 /* MergeIConstArrays */, 293,
    10 /* MergeIConstArrays */, 293,
    10 /* MergeIConstArrays */, 293,
    10 /* MergeIConstArrays */, 294,
    10 /* MergeIConstArrays */, 294,
    10 /* MergeIConstArrays */, 294,
    10 /* MergeIConstArrays */, 296,
    10 /* MergeIConstArrays */, 296,
    10 /* MergeIConstArrays */, 296,
    10 /* MergeIConstArrays */, 296,
    10 /* MergeIConstArrays */, 296,
    10 /* MergeIConstArrays */, 296,
    10 /* MergeIConstArrays */, 297,
    10 /* MergeIConstArrays */, 297,
    10 /* MergeIConstArrays */, 297,
    11 /* CollectConsts */, 330,
    11 /* CollectConsts */, 335,
    11 /* CollectConsts */, 336,
    11 /* CollectConsts */, 336,
    11 /* CollectConsts */, 344,
    11 /* CollectConsts */, 346,
    11 /* CollectConsts */, 347,
    11 /* CollectConsts */, 347,
    11 /* CollectConsts */, 348,
    11 /* CollectConsts */, 348,
    12 /* MergeIPropArrays */, 382,
    12 /* MergeIPropArrays */, 383,
    12 /* MergeIPropArrays */, 390,
    12 /* MergeIPropArrays */, 390,
    12 /* MergeIPropArrays */, 390,
    12 /* MergeIPropArrays */, 390,
    12 /* MergeIPropArrays */, 392,
    12 /* MergeIPropArrays */, 393,
    12 /* MergeIPropArrays */, 395,
    12 /* MergeIPropArrays */, 395,
    12 /* MergeIPropArrays */, 395,
    12 /* MergeIPropArrays */, 395,
    12 /* MergeIPropArrays */, 395,
    12 /* MergeIPropArrays */, 395,
    12 /* MergeIPropArrays */, 398,
    12 /* MergeIPropArrays */, 398,
    12 /* MergeIPropArrays */, 398,
    12 /* MergeIPropArrays */, 399,
    12 /* MergeIPropArrays */, 399,
    12 /* MergeIPropArrays */, 399,
    12 /* MergeIPropArrays */, 409,
    12 /* MergeIPropArrays */, 409,
    12 /* MergeIPropArrays */, 409,
    12 /* MergeIPropArrays */, 409,
    12 /* MergeIPropArrays */, 409,
    12 /* MergeIPropArrays */, 409,
    12 /* MergeIPropArrays */, 410,
    12 /* MergeIPropArrays */, 410,
    12 /* MergeIPropArrays */, 410,
    12 /* MergeIPropArrays */, 412,
    12 /* MergeIPropArrays */, 412,
    12 /* MergeIPropArrays */, 412,
    12 /* MergeIPropArrays */, 412,
    12 /* MergeIPropArrays */, 412,
    12 /* MergeIPropArrays */, 412,
    12 /* MergeIPropArrays */, 413,
    12 /* MergeIPropArrays */, 413,
    12 /* MergeIPropArrays */, 413,
    13 /* CollectProps */, 442,
    13 /* CollectProps */, 460,
    13 /* CollectProps */, 462,
    13 /* CollectProps */, 463,
    13 /* CollectProps */, 463,
    13 /* CollectProps */, 464,
    13 /* CollectProps */, 464,
    14 /* MergeIMethodArrays */, 499,
    14 /* MergeIMethodArrays */, 500,
    14 /* MergeIMethodArrays */, 507,
    14 /* MergeIMethodArrays */, 507,
    14 /* MergeIMethodArrays */, 507,
    14 /* MergeIMethodArrays */, 507,
    14 /* MergeIMethodArrays */, 509,
    14 /* MergeIMethodArrays */, 510,
    14 /* MergeIMethodArrays */, 514,
    14 /* MergeIMethodArrays */, 516,
    14 /* MergeIMethodArrays */, 516,
    14 /* MergeIMethodArrays */, 516,
    14 /* MergeIMethodArrays */, 516,
    14 /* MergeIMethodArrays */, 516,
    14 /* MergeIMethodArrays */, 519,
    14 /* MergeIMethodArrays */, 519,
    14 /* MergeIMethodArrays */, 520,
    14 /* MergeIMethodArrays */, 520,
    14 /* MergeIMethodArrays */, 525,
    14 /* MergeIMethodArrays */, 525,
    14 /* MergeIMethodArrays */, 526,
    14 /* MergeIMethodArrays */, 526,
    14 /* MergeIMethodArrays */, 528,
    14 /* MergeIMethodArrays */, 528,
    14 /* MergeIMethodArrays */, 529,
    14 /* MergeIMethodArrays */, 529,
    15 /* CollectMethods */, 562,
    15 /* CollectMethods */, 563,
    15 /* CollectMethods */, 563,
    15 /* CollectMethods */, 571,
    15 /* CollectMethods */, 573,
    15 /* CollectMethods */, 574,
    15 /* CollectMethods */, 574,
    15 /* CollectMethods */, 575,
    15 /* CollectMethods */, 575,
    16 /* IsOverridingType */, 656,
    16 /* IsOverridingType */, 660,
    16 /* IsOverridingType */, 661,
    16 /* IsOverridingType */, 662,
    16 /* IsOverridingType */, 663,
    16 /* IsOverridingType */, 664,
    16 /* IsOverridingType */, 667,
    16 /* IsOverridingType */, 669,
    16 /* IsOverridingType */, 670,
    16 /* IsOverridingType */, 671,
    16 /* IsOverridingType */, 672,
    16 /* IsOverridingType */, 673,
    16 /* IsOverridingType */, 676,
    16 /* IsOverridingType */, 677,
    16 /* IsOverridingType */, 677,
    16 /* IsOverridingType */, 688,
    17 /* CheckSign */, 718,
    17 /* CheckSign */, 718,
    17 /* CheckSign */, 725,
    17 /* CheckSign */, 725,
    17 /* CheckSign */, 726,
    17 /* CheckSign */, 726,
    17 /* CheckSign */, 736,
    17 /* CheckSign */, 738,
    17 /* CheckSign */, 739,
    17 /* CheckSign */, 739,
    17 /* CheckSign */, 744,
    17 /* CheckSign */, 744,
    17 /* CheckSign */, 744,
    17 /* CheckSign */, 745,
    17 /* CheckSign */, 745,
    17 /* CheckSign */, 756,
    17 /* CheckSign */, 756,
    17 /* CheckSign */, 757,
    17 /* CheckSign */, 757,
    17 /* CheckSign */, 762,
    17 /* CheckSign */, 762,
    17 /* CheckSign */, 763,
    17 /* CheckSign */, 763,
    17 /* CheckSign */, 768,
    17 /* CheckSign */, 769,
    17 /* CheckSign */, 769,
    17 /* CheckSign */, 779,
    17 /* CheckSign */, 779,
    18 /* CheckOverridesImplements */, 795,
    18 /* CheckOverridesImplements */, 795,
    18 /* CheckOverridesImplements */, 796,
    18 /* CheckOverridesImplements */, 801,
    18 /* CheckOverridesImplements */, 808,
    18 /* CheckOverridesImplements */, 808,
    18 /* CheckOverridesImplements */, 809,
    18 /* CheckOverridesImplements */, 811,
    18 /* CheckOverridesImplements */, 815,
    18 /* CheckOverridesImplements */, 815,
    18 /* CheckOverridesImplements */, 816,
    18 /* CheckOverridesImplements */, 818,
    18 /* CheckOverridesImplements */, 819,
    18 /* CheckOverridesImplements */, 819,
    18 /* CheckOverridesImplements */, 820,
    18 /* CheckOverridesImplements */, 822,
    18 /* CheckOverridesImplements */, 826,
    18 /* CheckOverridesImplements */, 827,
    18 /* CheckOverridesImplements */, 828,
    18 /* CheckOverridesImplements */, 832,
    18 /* CheckOverridesImplements */, 832,
    18 /* CheckOverridesImplements */, 833,
    18 /* CheckOverridesImplements */, 834,
    18 /* CheckOverridesImplements */, 838,
    18 /* CheckOverridesImplements */, 838,
    18 /* CheckOverridesImplements */, 840,
    18 /* CheckOverridesImplements */, 841,
    18 /* CheckOverridesImplements */, 842,
    18 /* CheckOverridesImplements */, 843,
    18 /* CheckOverridesImplements */, 851,
    18 /* CheckOverridesImplements */, 852,
    18 /* CheckOverridesImplements */, 857,
    18 /* CheckOverridesImplements */, 859,
    19 /* ResolveClassMethod */, 885,
    19 /* ResolveClassMethod */, 891,
    19 /* ResolveClassMethod */, 892,
    19 /* ResolveClassMethod */, 892,
    20 /* CheckImplementedMethodsRecurse */, 917,
    20 /* CheckImplementedMethodsRecurse */, 917,
    20 /* CheckImplementedMethodsRecurse */, 918,
    20 /* CheckImplementedMethodsRecurse */, 921,
    20 /* CheckImplementedMethodsRecurse */, 921,
    20 /* CheckImplementedMethodsRecurse */, 922,
    20 /* CheckImplementedMethodsRecurse */, 923,
    20 /* CheckImplementedMethodsRecurse */, 924,
    20 /* CheckImplementedMethodsRecurse */, 924,
    20 /* CheckImplementedMethodsRecurse */, 932,
    20 /* CheckImplementedMethodsRecurse */, 934,
    20 /* CheckImplementedMethodsRecurse */, 935,
    20 /* CheckImplementedMethodsRecurse */, 935,
    21 /* CheckImplementedMethods */, 944,
    21 /* CheckImplementedMethods */, 946,
    21 /* CheckImplementedMethods */, 947,
    21 /* CheckImplementedMethods */, 947,
    22 /* CheckImplementation */, 974,
    22 /* CheckImplementation */, 974,
    22 /* CheckImplementation */, 978,
    22 /* CheckImplementation */, 979,
    22 /* CheckImplementation */, 979,
    23 /* CheckOverriddenMethod */, 988,
    23 /* CheckOverriddenMethod */, 989,
    23 /* CheckOverriddenMethod */, 989,
    23 /* CheckOverriddenMethod */, 992,
    23 /* CheckOverriddenMethod */, 992,
    23 /* CheckOverriddenMethod */, 994,
    23 /* CheckOverriddenMethod */, 997,
    23 /* CheckOverriddenMethod */, 1005,
    23 /* CheckOverriddenMethod */, 1006,
    23 /* CheckOverriddenMethod */, 1006,
    24 /* IsObjectConvertibleToString */, 1048,
    24 /* IsObjectConvertibleToString */, 1048,
    24 /* IsObjectConvertibleToString */, 1051
};

void Classes_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Classes";
    *f = Classes_0func[ Classes_0err_entry[2*i] ];
    *l = Classes_0err_entry[2*i + 1];
}
