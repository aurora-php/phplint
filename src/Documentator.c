/* IMPLEMENTATION MODULE Documentator */
#define M2_IMPORT_Documentator

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

#ifndef M2_IMPORT_io
#    include "io.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif

#ifndef M2_IMPORT_Errors
#    include "Errors.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_buffer
#    include "buffer.c"
#endif

#ifndef M2_IMPORT_FileName
#    include "FileName.c"
#endif

void Documentator_0err_entry_get(int i, char **m, char **f, int *l);
/* 19*/ int Documentator_generate = 0;
/* 22*/ STRING * Documentator_extension = NULL;
/* 25*/ STRING * Documentator_page_footer = NULL;
/* 25*/ STRING * Documentator_page_header = NULL;
/* 34*/ ARRAY * Documentator_ref_remap = NULL;
/* 35*/ int Documentator_php_ver = 0;
/* 37*/ STRING * Documentator_fn = NULL;
/* 38*/ STRING * Documentator_package_descr = NULL;
/* 39*/ ARRAY * Documentator_required_packages = NULL;
/* 40*/ ARRAY * Documentator_include_path = NULL;
/* 41*/ ARRAY * Documentator_consts = NULL;
/* 42*/ ARRAY * Documentator_vars = NULL;
/* 43*/ ARRAY * Documentator_funcs = NULL;
/* 45*/ ARRAY * Documentator_classes = NULL;
/* 48*/ void * Documentator_fd = NULL;
/* 52*/ STRING * Documentator_fn_remapped = NULL;
/* 60*/ RECORD * Documentator_curr_class = NULL;
/* 68*/ STRING * Documentator_see = NULL;
/* 68*/ STRING * Documentator_deprecated = NULL;
/* 68*/ STRING * Documentator_since = NULL;
/* 68*/ STRING * Documentator_authors = NULL;
/* 68*/ STRING * Documentator_license = NULL;
/* 68*/ STRING * Documentator_copyright = NULL;
/* 68*/ STRING * Documentator_version = NULL;
/* 68*/ STRING * Documentator_package = NULL;
/* 71*/ int Documentator_prev_item_big_vspace = 0;
/* 74*/ STRING * Documentator_private_items = NULL;

/* 76*/ void
/* 76*/ Documentator_DocError(STRING *Documentator_msg)
/* 76*/ {
/* 76*/ 	Scanner_Error2((
/* 76*/ 		push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/* 76*/ 		push((char*) Documentator_fn),
/* 76*/ 		*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/* 76*/ 		*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 0,
/* 76*/ 		(RECORD*) pop()
/* 76*/ 	), Documentator_msg);
/* 80*/ }


/* 82*/ void
/* 82*/ Documentator_p(STRING *Documentator_s)
/* 82*/ {
/* 82*/ 	m2runtime_ERROR_CODE = 0;
/* 82*/ 	io_Write(1, *(void **)(void *)&Documentator_fd, Documentator_s);
/* 83*/ 	switch( m2runtime_ERROR_CODE ){

/* 83*/ 	case 0:  break;
/* 83*/ 	default:
/* 83*/ 		m2runtime_HALT(Documentator_0err_entry_get, 0, m2runtime_ERROR_MESSAGE);
/* 84*/ 	}
/* 86*/ }


/* 88*/ int
/* 88*/ Documentator_is_space(STRING *Documentator_c)
/* 88*/ {
/* 88*/ 	return ((m2runtime_strcmp(Documentator_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(Documentator_c, m2runtime_CHR(9)) == 0) || (m2runtime_strcmp(Documentator_c, m2runtime_CHR(10)) == 0) || (m2runtime_strcmp(Documentator_c, m2runtime_CHR(13)) == 0));
/* 92*/ }


/* 94*/ STRING *
/* 94*/ Documentator_Anchor(STRING *Documentator_url, STRING *Documentator_text)
/* 94*/ {
/* 94*/ 	return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"<a href=\042", Documentator_url, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"\042><code>", Documentator_text, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"</code></a>", (STRING *) 1);
/* 98*/ }


/*108*/ STRING *
/*108*/ Documentator_RefMap(STRING *Documentator_f)
/*108*/ {
/*109*/ 	STRING * Documentator_t = NULL;
/*111*/ 	int Documentator_i = 0;
/*111*/ 	{
/*111*/ 		int m2runtime_for_limit_1;
/*111*/ 		Documentator_i = 0;
/*111*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_ref_remap) - 1);
/*112*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 2 ){
/*112*/ 			Documentator_t = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_ref_remap, Documentator_i, Documentator_0err_entry_get, 1);
/*113*/ 			if( (((m2runtime_length(Documentator_t) <= m2runtime_length(Documentator_f))) && (m2runtime_strcmp(m2runtime_substr(Documentator_f, 0, m2runtime_length(Documentator_t), 1, Documentator_0err_entry_get, 2), Documentator_t) == 0)) ){
/*114*/ 				return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_ref_remap, (Documentator_i + 1), Documentator_0err_entry_get, 3), m2runtime_substr(Documentator_f, m2runtime_length(Documentator_t), m2runtime_length(Documentator_f), 1, Documentator_0err_entry_get, 4), (STRING *) 1);
/*117*/ 			}
/*117*/ 		}
/*117*/ 	}
/*117*/ 	return Documentator_f;
/*121*/ }


/*137*/ STRING *
/*137*/ Documentator_ItemToUrl(STRING *Documentator_t)
/*137*/ {

/*139*/ 	STRING *
/*139*/ 	Documentator_err(STRING *Documentator_msg)
/*139*/ 	{
/*139*/ 		Documentator_DocError(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"<@item ", Documentator_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)">: ", Documentator_msg, m2runtime_CHR(10), (STRING *) 1));
/*140*/ 		return m2runtime_CHR(35);
/*144*/ 	}


/*145*/ 	RECORD *
/*145*/ 	Documentator_SearchConst(STRING *Documentator_n)
/*145*/ 	{
/*147*/ 		int Documentator_i = 0;
/*147*/ 		{
/*147*/ 			int m2runtime_for_limit_1;
/*147*/ 			Documentator_i = 0;
/*147*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_consts) - 1);
/*148*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*148*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 5), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 6), Documentator_n) == 0 ){
/*149*/ 					return (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 7);
/*152*/ 				}
/*152*/ 			}
/*152*/ 		}
/*152*/ 		return NULL;
/*156*/ 	}


/*157*/ 	RECORD *
/*157*/ 	Documentator_SearchVar(STRING *Documentator_n)
/*157*/ 	{
/*159*/ 		int Documentator_i = 0;
/*159*/ 		{
/*159*/ 			int m2runtime_for_limit_1;
/*159*/ 			Documentator_i = 0;
/*159*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_vars) - 1);
/*160*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*160*/ 				if( (((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_vars, Documentator_i, Documentator_0err_entry_get, 8) != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_vars, Documentator_i, Documentator_0err_entry_get, 9), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 10), Documentator_n) == 0)) ){
/*161*/ 					return (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_vars, Documentator_i, Documentator_0err_entry_get, 11);
/*164*/ 				}
/*164*/ 			}
/*164*/ 		}
/*164*/ 		return NULL;
/*168*/ 	}


/*169*/ 	RECORD *
/*169*/ 	Documentator_SearchFunc(STRING *Documentator_n)
/*169*/ 	{
/*171*/ 		int Documentator_i = 0;
/*171*/ 		{
/*171*/ 			int m2runtime_for_limit_1;
/*171*/ 			Documentator_i = 0;
/*171*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_funcs) - 1);
/*172*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*172*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_funcs, Documentator_i, Documentator_0err_entry_get, 12), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 13), Documentator_n) == 0 ){
/*173*/ 					return (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_funcs, Documentator_i, Documentator_0err_entry_get, 14);
/*176*/ 				}
/*176*/ 			}
/*176*/ 		}
/*176*/ 		return NULL;
/*180*/ 	}


/*181*/ 	RECORD *
/*181*/ 	Documentator_SearchClass(STRING *Documentator_n)
/*181*/ 	{
/*183*/ 		int Documentator_i = 0;
/*183*/ 		{
/*183*/ 			int m2runtime_for_limit_1;
/*183*/ 			Documentator_i = 0;
/*183*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_classes) - 1);
/*184*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*184*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_classes, Documentator_i, Documentator_0err_entry_get, 15), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 16), Documentator_n) == 0 ){
/*185*/ 					return (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_classes, Documentator_i, Documentator_0err_entry_get, 17);
/*188*/ 				}
/*188*/ 			}
/*188*/ 		}
/*188*/ 		return NULL;
/*192*/ 	}


/*193*/ 	RECORD *
/*193*/ 	Documentator_SearchClassConst(RECORD *Documentator_cl, STRING *Documentator_n)
/*193*/ 	{
/*193*/ 		int Documentator_i = 0;
/*195*/ 		ARRAY * Documentator_consts = NULL;
/*195*/ 		Documentator_consts = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 18);
/*196*/ 		{
/*196*/ 			int m2runtime_for_limit_1;
/*196*/ 			Documentator_i = 0;
/*196*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_consts) - 1);
/*197*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*197*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 19), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 20), Documentator_n) == 0 ){
/*198*/ 					return (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 21);
/*201*/ 				}
/*201*/ 			}
/*201*/ 		}
/*201*/ 		return NULL;
/*205*/ 	}


/*206*/ 	RECORD *
/*206*/ 	Documentator_SearchClassVar(RECORD *Documentator_cl, STRING *Documentator_n)
/*206*/ 	{
/*206*/ 		int Documentator_i = 0;
/*208*/ 		ARRAY * Documentator_p = NULL;
/*208*/ 		Documentator_p = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 22);
/*209*/ 		{
/*209*/ 			int m2runtime_for_limit_1;
/*209*/ 			Documentator_i = 0;
/*209*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_p) - 1);
/*210*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*210*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_p, Documentator_i, Documentator_0err_entry_get, 23), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 24), Documentator_n) == 0 ){
/*211*/ 					return (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_p, Documentator_i, Documentator_0err_entry_get, 25);
/*214*/ 				}
/*214*/ 			}
/*214*/ 		}
/*214*/ 		return NULL;
/*218*/ 	}


/*219*/ 	RECORD *
/*219*/ 	Documentator_SearchClassFunc(RECORD *Documentator_cl, STRING *Documentator_n)
/*219*/ 	{
/*219*/ 		int Documentator_i = 0;
/*221*/ 		ARRAY * Documentator_m = NULL;
/*221*/ 		Documentator_m = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 26);
/*222*/ 		{
/*222*/ 			int m2runtime_for_limit_1;
/*222*/ 			Documentator_i = 0;
/*222*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_m) - 1);
/*223*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*223*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_m, Documentator_i, Documentator_0err_entry_get, 27), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 28), Documentator_n) == 0 ){
/*224*/ 					return (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_m, Documentator_i, Documentator_0err_entry_get, 29);
/*227*/ 				}
/*227*/ 			}
/*227*/ 		}
/*227*/ 		return NULL;
/*231*/ 	}


/*232*/ 	STRING *
/*232*/ 	Documentator_report(RECORD *Documentator_decl_in)
/*232*/ 	{
/*234*/ 		int Documentator_i = 0;
/*234*/ 		if( Documentator_decl_in == NULL ){
/*235*/ 			return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"not declared / not assigned");
/*237*/ 		}
/*237*/ 		Documentator_i = str_find(Documentator_t, m2runtime_CHR(40));
/*238*/ 		if( (Documentator_i >= 0) ){
/*239*/ 			Documentator_t = m2runtime_concat_STRING(0, m2runtime_substr(Documentator_t, 0, Documentator_i, 1, Documentator_0err_entry_get, 30), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1);
/*241*/ 		}
/*241*/ 		Documentator_t = str_substitute(Documentator_t, m2runtime_CHR(92), m2runtime_CHR(47));
/*242*/ 		if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_decl_in, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 31), Documentator_fn) == 0 ){
/*243*/ 			return m2runtime_concat_STRING(0, m2runtime_CHR(35), Documentator_t, (STRING *) 1);
/*245*/ 		} else {
/*245*/ 			return FileName_Relative(Documentator_fn_remapped, Documentator_RefMap(m2runtime_concat_STRING(0, FileName_DropExtension((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_decl_in, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 32)), Documentator_extension, m2runtime_CHR(35), Documentator_t, (STRING *) 1)));
/*249*/ 		}
/*249*/ 		m2runtime_missing_return(Documentator_0err_entry_get, 33);
/*249*/ 		return NULL;
/*251*/ 	}

/*252*/ 	STRING * Documentator_n = NULL;
/*253*/ 	int Documentator_j = 0;
/*254*/ 	int Documentator_tlen = 0;
/*255*/ 	RECORD * Documentator_c = NULL;
/*256*/ 	RECORD * Documentator_v = NULL;
/*257*/ 	RECORD * Documentator_f = NULL;
/*258*/ 	RECORD * Documentator_cl = NULL;
/*261*/ 	RECORD * Documentator_cl_c = NULL;
/*261*/ 	Documentator_tlen = m2runtime_length(Documentator_t);
/*262*/ 	if( (Documentator_tlen == 0) ){
/*263*/ 		return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"empty target");
/*266*/ 	}
/*266*/ 	if( m2runtime_strcmp(m2runtime_substr(Documentator_t, 0, 0, 0, Documentator_0err_entry_get, 34), m2runtime_CHR(36)) == 0 ){
/*267*/ 		Documentator_v = Documentator_SearchVar(m2runtime_substr(Documentator_t, 1, Documentator_tlen, 1, Documentator_0err_entry_get, 35));
/*268*/ 		if( Documentator_v == NULL ){
/*269*/ 			return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"variable not found in global scope");
/*271*/ 		} else {
/*271*/ 			return Documentator_report((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_v, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 36));
/*274*/ 		}
/*275*/ 	}
/*275*/ 	Documentator_j = str_find(Documentator_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::");
/*276*/ 	if( (Documentator_j >= 0) ){
/*279*/ 		if( (Documentator_j == 0) ){
/*280*/ 			if( Documentator_curr_class == NULL ){
/*281*/ 				Documentator_DocError((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"missing class name");
/*282*/ 				Documentator_cl = NULL;
/*284*/ 			} else {
/*284*/ 				Documentator_cl = Documentator_curr_class;
/*285*/ 				Documentator_t = m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 37), Documentator_t, (STRING *) 1);
/*286*/ 				Documentator_j = m2runtime_length((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 38));
/*287*/ 				Documentator_tlen = m2runtime_length(Documentator_t);
/*290*/ 			}
/*290*/ 		} else {
/*290*/ 			Documentator_cl = Documentator_SearchClass(m2runtime_substr(Documentator_t, 0, Documentator_j, 1, Documentator_0err_entry_get, 39));
/*292*/ 		}
/*292*/ 		if( Documentator_cl == NULL ){
/*293*/ 			return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"class not found");
/*298*/ 		}
/*298*/ 		Documentator_n = m2runtime_substr(Documentator_t, (Documentator_j + 2), Documentator_tlen, 1, Documentator_0err_entry_get, 40);
/*300*/ 		if( (((m2runtime_length(Documentator_n) >= 1)) && (m2runtime_strcmp(m2runtime_substr(Documentator_n, 0, 0, 0, Documentator_0err_entry_get, 41), m2runtime_CHR(36)) == 0)) ){
/*301*/ 			if( Documentator_SearchClassVar(Documentator_cl, m2runtime_substr(Documentator_n, 1, m2runtime_length(Documentator_n), 1, Documentator_0err_entry_get, 42)) == NULL ){
/*302*/ 				return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"property not found");
/*304*/ 			} else {
/*304*/ 				return Documentator_report((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 12 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 43));
/*307*/ 			}
/*308*/ 		}
/*308*/ 		if( (((m2runtime_length(Documentator_n) >= 2)) && (m2runtime_strcmp(m2runtime_substr(Documentator_n, (m2runtime_length(Documentator_n) - 1), 0, 0, Documentator_0err_entry_get, 44), m2runtime_CHR(41)) == 0)) ){
/*309*/ 			Documentator_j = str_find(Documentator_n, m2runtime_CHR(40));
/*310*/ 			if( (Documentator_j < 0) ){
/*311*/ 				return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"missing ( in method name");
/*313*/ 			}
/*313*/ 			if( Documentator_SearchClassFunc(Documentator_cl, m2runtime_substr(Documentator_n, 0, Documentator_j, 1, Documentator_0err_entry_get, 45)) == NULL ){
/*314*/ 				return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"method not found");
/*316*/ 			} else {
/*316*/ 				return Documentator_report((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 12 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 46));
/*319*/ 			}
/*320*/ 		}
/*320*/ 		Documentator_cl_c = Documentator_SearchClassConst(Documentator_cl, Documentator_n);
/*321*/ 		if( Documentator_cl_c != NULL ){
/*322*/ 			return Documentator_report((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl_c, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 47));
/*325*/ 		}
/*325*/ 		return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"class constant not found");
/*328*/ 	}
/*328*/ 	if( (((Documentator_tlen > 2)) && (m2runtime_strcmp(m2runtime_substr(Documentator_t, (Documentator_tlen - 1), 0, 0, Documentator_0err_entry_get, 48), m2runtime_CHR(41)) == 0)) ){
/*329*/ 		Documentator_j = str_find(Documentator_t, m2runtime_CHR(40));
/*330*/ 		if( (Documentator_j < 0) ){
/*331*/ 			return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"missing ( in function name");
/*333*/ 		}
/*333*/ 		Documentator_f = Documentator_SearchFunc(m2runtime_substr(Documentator_t, 0, Documentator_j, 1, Documentator_0err_entry_get, 49));
/*334*/ 		if( Documentator_f == NULL ){
/*335*/ 			return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"function not found");
/*337*/ 		}
/*337*/ 		return Documentator_report((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_f, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 50));
/*340*/ 	}
/*340*/ 	Documentator_cl = Documentator_SearchClass(Documentator_t);
/*341*/ 	if( Documentator_cl != NULL ){
/*342*/ 		return Documentator_report((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 12 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 51));
/*345*/ 	}
/*345*/ 	Documentator_c = Documentator_SearchConst(Documentator_t);
/*346*/ 	if( Documentator_c != NULL ){
/*347*/ 		return Documentator_report((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 52));
/*350*/ 	}
/*350*/ 	return Documentator_err((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"constant / class not found");
/*354*/ }


/*355*/ void
/*355*/ Documentator_AnchorToClass(RECORD *Documentator_c)
/*355*/ {
/*357*/ 	STRING * Documentator_name = NULL;
/*357*/ 	Documentator_name = (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 53);
/*358*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 4 * sizeof(int), Documentator_0err_entry_get, 54) ){
/*359*/ 		Documentator_DocError(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"the class ", Documentator_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)" is private and cannot be referenced", (STRING *) 1));
/*360*/ 		Documentator_p(Documentator_name);
/*362*/ 	} else {
/*362*/ 		Documentator_p(Documentator_Anchor(Documentator_ItemToUrl(Documentator_name), Documentator_name));
/*365*/ 	}
/*367*/ }


/*368*/ STRING *
/*368*/ Documentator_ResolveTag(STRING *Documentator_tag, STRING *Documentator_arg)
/*368*/ {
/*370*/ 	STRING * Documentator_s = NULL;
/*370*/ 	if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"package") == 0 ){
/*371*/ 		Documentator_package = Documentator_arg;
/*372*/ 	} else if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"version") == 0 ){
/*373*/ 		Documentator_version = Documentator_arg;
/*374*/ 	} else if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"copyright") == 0 ){
/*375*/ 		Documentator_copyright = Documentator_arg;
/*376*/ 	} else if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"license") == 0 ){
/*377*/ 		Documentator_license = Documentator_arg;
/*378*/ 	} else if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"author") == 0 ){
/*379*/ 		if( (m2runtime_length(Documentator_authors) == 0) ){
/*380*/ 			Documentator_authors = Documentator_arg;
/*382*/ 		} else {
/*382*/ 			Documentator_authors = m2runtime_concat_STRING(0, Documentator_authors, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", Documentator_arg, (STRING *) 1);
/*384*/ 		}
/*384*/ 	} else if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"since") == 0 ){
/*385*/ 		Documentator_since = Documentator_arg;
/*386*/ 	} else if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"item") == 0 ){
/*387*/ 		return Documentator_Anchor(Documentator_ItemToUrl(Documentator_arg), Documentator_arg);
/*388*/ 	} else if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"deprecated") == 0 ){
/*389*/ 		Documentator_deprecated = Documentator_arg;
/*390*/ 	} else if( m2runtime_strcmp(Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"see") == 0 ){
/*391*/ 		Documentator_s = Documentator_Anchor(Documentator_ItemToUrl(Documentator_arg), Documentator_arg);
/*392*/ 		if( (m2runtime_length(Documentator_see) == 0) ){
/*393*/ 			Documentator_see = Documentator_s;
/*395*/ 		} else {
/*395*/ 			Documentator_see = m2runtime_concat_STRING(0, Documentator_see, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", Documentator_s, (STRING *) 1);
/*398*/ 		}
/*398*/ 	} else {
/*398*/ 		Documentator_DocError(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"undefined tag <@", Documentator_tag, m2runtime_CHR(62), (STRING *) 1));
/*400*/ 	}
/*400*/ 	return EMPTY_STRING;
/*404*/ }


/*409*/ STRING *
/*409*/ Documentator_ResolveTags(STRING *Documentator_s)
/*409*/ {
/*410*/ 	int Documentator_i = 0;
/*411*/ 	STRING * Documentator_r = NULL;
/*411*/ 	STRING * Documentator_arg = NULL;
/*411*/ 	STRING * Documentator_tag = NULL;
/*412*/ 	int Documentator_l = 0;
/*414*/ 	int Documentator_recursive_tags = 0;
/*415*/ 	do {
/*415*/ 		Documentator_i = str_find(Documentator_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"<@");
/*416*/ 		if( (Documentator_i < 0) ){
/*417*/ 			return m2runtime_concat_STRING(0, Documentator_r, Documentator_s, (STRING *) 1);
/*419*/ 		}
/*419*/ 		Documentator_r = m2runtime_concat_STRING(0, Documentator_r, m2runtime_substr(Documentator_s, 0, Documentator_i, 1, Documentator_0err_entry_get, 55), (STRING *) 1);
/*420*/ 		m2_inc(&Documentator_i, 2);
/*423*/ 		while( (((Documentator_i < m2runtime_length(Documentator_s))) && Documentator_is_space(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 56))) ){
/*424*/ 			m2_inc(&Documentator_i, 1);
/*428*/ 		}
/*428*/ 		Documentator_tag = NULL;
/*429*/ 		while( (((Documentator_i < m2runtime_length(Documentator_s))) && !Documentator_is_space(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 57)) && (m2runtime_strcmp(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 58), m2runtime_CHR(62)) != 0)) ){
/*430*/ 			Documentator_tag = m2runtime_concat_STRING(0, Documentator_tag, m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 59), (STRING *) 1);
/*431*/ 			m2_inc(&Documentator_i, 1);
/*435*/ 		}
/*435*/ 		while( (((Documentator_i < m2runtime_length(Documentator_s))) && Documentator_is_space(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 60))) ){
/*436*/ 			m2_inc(&Documentator_i, 1);
/*440*/ 		}
/*440*/ 		Documentator_arg = NULL;
/*441*/ 		Documentator_recursive_tags = FALSE;
/*442*/ 		Documentator_l = 0;
/*443*/ 		while( (((Documentator_i < m2runtime_length(Documentator_s))) && ((((Documentator_l > 0)) || (m2runtime_strcmp(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 61), m2runtime_CHR(62)) != 0)))) ){
/*444*/ 			Documentator_arg = m2runtime_concat_STRING(0, Documentator_arg, m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 62), (STRING *) 1);
/*445*/ 			if( m2runtime_strcmp(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 63), m2runtime_CHR(60)) == 0 ){
/*446*/ 				Documentator_recursive_tags = TRUE;
/*447*/ 				m2_inc(&Documentator_l, 1);
/*449*/ 			}
/*449*/ 			if( m2runtime_strcmp(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 64), m2runtime_CHR(62)) == 0 ){
/*450*/ 				m2_inc(&Documentator_l, -1);
/*452*/ 			}
/*452*/ 			m2_inc(&Documentator_i, 1);
/*456*/ 		}
/*456*/ 		while( (((Documentator_i < m2runtime_length(Documentator_s))) && Documentator_is_space(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 65))) ){
/*457*/ 			m2_inc(&Documentator_i, 1);
/*460*/ 		}
/*460*/ 		if( (((Documentator_i == m2runtime_length(Documentator_s))) || (m2runtime_strcmp(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 66), m2runtime_CHR(62)) != 0)) ){
/*461*/ 			Documentator_DocError(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"missing closing > IN <@", Documentator_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"...>\012", (STRING *) 1));
/*463*/ 		} else {
/*463*/ 			m2_inc(&Documentator_i, 1);
/*466*/ 		}
/*466*/ 		if( Documentator_recursive_tags ){
/*467*/ 			Documentator_arg = Documentator_ResolveTags(Documentator_arg);
/*470*/ 		}
/*470*/ 		Documentator_r = m2runtime_concat_STRING(0, Documentator_r, Documentator_ResolveTag(Documentator_tag, Documentator_arg), (STRING *) 1);
/*471*/ 		Documentator_s = m2runtime_substr(Documentator_s, Documentator_i, m2runtime_length(Documentator_s), 1, Documentator_0err_entry_get, 67);
/*472*/ 	} while( !( (m2runtime_length(Documentator_s) == 0) ));
/*473*/ 	return Documentator_r;
/*477*/ }


/*478*/ STRING *
/*478*/ Documentator_trim(STRING *Documentator_s)
/*478*/ {
/*480*/ 	int Documentator_len = 0;
/*480*/ 	int Documentator_j = 0;
/*480*/ 	int Documentator_i = 0;
/*480*/ 	Documentator_len = m2runtime_length(Documentator_s);
/*481*/ 	if( (Documentator_len == 0) ){
/*482*/ 		return NULL;
/*485*/ 	}
/*485*/ 	Documentator_i = 0;
/*486*/ 	while( (((Documentator_i < Documentator_len)) && Documentator_is_space(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 68))) ){
/*487*/ 		m2_inc(&Documentator_i, 1);
/*490*/ 	}
/*490*/ 	Documentator_j = (Documentator_len - 1);
/*491*/ 	while( (((Documentator_j >= Documentator_i)) && Documentator_is_space(m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 69))) ){
/*492*/ 		m2_inc(&Documentator_j, -1);
/*495*/ 	}
/*495*/ 	return m2runtime_substr(Documentator_s, Documentator_i, (Documentator_j + 1), 1, Documentator_0err_entry_get, 70);
/*499*/ }


/*501*/ void
/*501*/ Documentator_VSpaceBeforeItem(int Documentator_big)
/*501*/ {
/*501*/ 	if( Documentator_prev_item_big_vspace ){
/*503*/ 		return ;
/*503*/ 	} else if( Documentator_big ){
/*504*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"<PRE>\012\012</PRE>\012");
/*506*/ 	} else {
/*506*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<P>\012");
/*509*/ 	}
/*511*/ }


/*513*/ void
/*513*/ Documentator_VSpaceAfterItem(int Documentator_big)
/*513*/ {
/*513*/ 	if( Documentator_big ){
/*514*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"<PRE>\012\012</PRE>\012");
/*516*/ 	}
/*516*/ 	Documentator_prev_item_big_vspace = Documentator_big;
/*520*/ }


/*522*/ void
/*522*/ Documentator_ItemAnchor(STRING *Documentator_s)
/*522*/ {
/*522*/ 	Documentator_p(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"\012<A name=\042", str_substitute(Documentator_s, m2runtime_CHR(92), m2runtime_CHR(47)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"\042></A>\012", (STRING *) 1));
/*526*/ }


/*534*/ void
/*534*/ Documentator_DocString(STRING *Documentator_s)
/*534*/ {

/*536*/ 	STRING *
/*536*/ 	Documentator_hex(int Documentator_h)
/*536*/ 	{
/*536*/ 		if( (Documentator_h < 10) ){
/*537*/ 			return m2runtime_CHR((m2runtime_ASC(m2runtime_CHR(48)) + Documentator_h));
/*539*/ 		} else {
/*539*/ 			return m2runtime_CHR(((m2runtime_ASC(m2runtime_CHR(65)) + Documentator_h) - 10));
/*542*/ 		}
/*542*/ 		m2runtime_missing_return(Documentator_0err_entry_get, 71);
/*542*/ 		return NULL;
/*544*/ 	}

/*545*/ 	STRING * Documentator_c = NULL;
/*547*/ 	int Documentator_ch = 0;
/*547*/ 	int Documentator_i = 0;
/*547*/ 	if( m2runtime_strcmp(Documentator_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL") == 0 ){
/*549*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL");
/*551*/ 		return ;
/*552*/ 	}
/*552*/ 	Documentator_p(m2runtime_CHR(34));
/*553*/ 	{
/*553*/ 		int m2runtime_for_limit_1;
/*553*/ 		Documentator_i = 0;
/*553*/ 		m2runtime_for_limit_1 = (m2runtime_length(Documentator_s) - 1);
/*554*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*554*/ 			Documentator_c = m2runtime_substr(Documentator_s, Documentator_i, 0, 0, Documentator_0err_entry_get, 72);
/*555*/ 			Documentator_ch = m2runtime_ASC(Documentator_c);
/*557*/ 			if( (((Documentator_ch <= 31)) || ((Documentator_ch >= 127))) ){
/*558*/ 				if( (Documentator_ch == 10) ){
/*558*/ 					Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\134n");
/*559*/ 				} else if( (Documentator_ch == 13) ){
/*559*/ 					Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\134r");
/*560*/ 				} else if( (Documentator_ch == 9) ){
/*560*/ 					Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\134t");
/*562*/ 				} else {
/*562*/ 					Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\134x");
/*563*/ 					Documentator_p(Documentator_hex((Documentator_ch / 16)));
/*564*/ 					Documentator_p(Documentator_hex((Documentator_ch % 16)));
/*567*/ 				}
/*567*/ 			} else if( m2runtime_strcmp(Documentator_c, m2runtime_CHR(32)) == 0 ){
/*567*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"&nbsp;");
/*568*/ 			} else if( m2runtime_strcmp(Documentator_c, m2runtime_CHR(92)) == 0 ){
/*568*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\134\134");
/*569*/ 			} else if( m2runtime_strcmp(Documentator_c, m2runtime_CHR(34)) == 0 ){
/*569*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\134\042");
/*570*/ 			} else if( m2runtime_strcmp(Documentator_c, m2runtime_CHR(38)) == 0 ){
/*570*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"&amp;");
/*571*/ 			} else if( m2runtime_strcmp(Documentator_c, m2runtime_CHR(60)) == 0 ){
/*571*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"&lt;");
/*572*/ 			} else if( m2runtime_strcmp(Documentator_c, m2runtime_CHR(62)) == 0 ){
/*572*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"&gt;");
/*573*/ 			} else {
/*573*/ 				Documentator_p(Documentator_c);
/*576*/ 			}
/*576*/ 		}
/*576*/ 	}
/*576*/ 	Documentator_p(m2runtime_CHR(34));
/*580*/ }


/*582*/ void
/*582*/ Documentator_DocValue(RECORD *Documentator_t, STRING *Documentator_v)
/*582*/ {
/*582*/ 	if( Documentator_t == NULL ){
/*583*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"<I>FIXME_UNKNOWN_TYPE</I>");
/*585*/ 		return ;
/*586*/ 	}
/*586*/ 	if( Documentator_v == NULL ){
/*587*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"<I>FIXME_UNKNOWN_VALUE</I>");
/*589*/ 		return ;
/*590*/ 	}
/*590*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_t, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 73) == 5) ){
/*591*/ 		if( m2runtime_strcmp(Documentator_v, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"NIL") == 0 ){
/*592*/ 			Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL");
/*595*/ 		} else {
/*595*/ 			Documentator_DocString(Documentator_v);
/*597*/ 		}
/*597*/ 	} else if( ( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_t, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 74) == 0) ){
/*598*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL");
/*600*/ 	} else {
/*600*/ 		Documentator_p(Documentator_v);
/*603*/ 	}
/*605*/ }


/*607*/ void
/*607*/ Documentator_sort(ARRAY *Documentator_a)
/*607*/ {
/*608*/ 	int Documentator_j = 0;
/*608*/ 	int Documentator_i = 0;
/*610*/ 	STRING * Documentator_t = NULL;
/*610*/ 	{
/*610*/ 		int m2runtime_for_limit_1;
/*610*/ 		Documentator_i = 0;
/*610*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_a) - 2);
/*611*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*611*/ 			{
/*611*/ 				int m2runtime_for_limit_2;
/*611*/ 				Documentator_j = (Documentator_i + 1);
/*611*/ 				m2runtime_for_limit_2 = (m2runtime_count(Documentator_a) - 1);
/*612*/ 				for( ; Documentator_j <= m2runtime_for_limit_2; Documentator_j += 1 ){
/*612*/ 					if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_a, Documentator_j, Documentator_0err_entry_get, 75), (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_a, Documentator_i, Documentator_0err_entry_get, 76)) > 0 ){
/*613*/ 						Documentator_t = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_a, Documentator_j, Documentator_0err_entry_get, 77);
/*613*/ 						*(STRING **)m2runtime_dereference_lhs_ARRAY(&Documentator_a, sizeof(void *), 1, Documentator_j, Documentator_0err_entry_get, 78) = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_a, Documentator_i, Documentator_0err_entry_get, 79);
/*613*/ 						*(STRING **)m2runtime_dereference_lhs_ARRAY(&Documentator_a, sizeof(void *), 1, Documentator_i, Documentator_0err_entry_get, 80) = Documentator_t;
/*616*/ 					}
/*617*/ 				}
/*617*/ 			}
/*618*/ 		}
/*618*/ 	}
/*621*/ }

/*624*/ void * Documentator_descr = NULL;

/*633*/ void
/*633*/ Documentator_DocDescr(int Documentator_pkg_descr, STRING *Documentator_s)
/*633*/ {
/*634*/ 	int Documentator_i = 0;
/*635*/ 	STRING * Documentator_long = NULL;
/*635*/ 	STRING * Documentator_short = NULL;
/*636*/ 	STRING * Documentator_path = NULL;
/*637*/ 	RECORD * Documentator_pkg = NULL;
/*639*/ 	int Documentator_none = 0;
/*642*/ 	if( (!Documentator_pkg_descr && (Documentator_s == NULL)) ){
/*644*/ 		return ;
/*647*/ 	}
/*647*/ 	Documentator_package = NULL;
/*648*/ 	Documentator_version = NULL;
/*649*/ 	Documentator_copyright = NULL;
/*650*/ 	Documentator_license = NULL;
/*651*/ 	Documentator_authors = NULL;
/*652*/ 	Documentator_since = NULL;
/*653*/ 	Documentator_deprecated = NULL;
/*654*/ 	Documentator_see = NULL;
/*660*/ 	Documentator_i = str_find(Documentator_s, m2runtime_CHR(10));
/*661*/ 	if( (Documentator_i < 0) ){
/*662*/ 		Documentator_short = Documentator_ResolveTags(Documentator_trim(Documentator_s));
/*663*/ 		Documentator_long = EMPTY_STRING;
/*665*/ 	} else {
/*665*/ 		Documentator_short = Documentator_ResolveTags(Documentator_trim(m2runtime_substr(Documentator_s, 0, Documentator_i, 1, Documentator_0err_entry_get, 81)));
/*666*/ 		Documentator_long = Documentator_ResolveTags(Documentator_trim(m2runtime_substr(Documentator_s, (Documentator_i + 1), m2runtime_length(Documentator_s), 1, Documentator_0err_entry_get, 82)));
/*673*/ 	}
/*673*/ 	buffer_Empty((void *)&Documentator_descr);
/*675*/ 	if( Documentator_pkg_descr ){
/*676*/ 		if( Documentator_package == NULL ){
/*677*/ 			Documentator_package = FileName_DropExtension(FileName_Basename(Documentator_fn));
/*679*/ 		}
/*679*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<H1>", Documentator_package, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"</H1>\012", (STRING *) 1));
/*683*/ 	} else {
/*684*/ 	}
/*684*/ 	if( m2runtime_strcmp(Documentator_short, EMPTY_STRING) > 0 ){
/*685*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"<P><b>", Documentator_short, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"</b></P>", (STRING *) 1));
/*688*/ 	}
/*688*/ 	if( Documentator_version != NULL ){
/*689*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"<P><B>Version:</B> ", Documentator_version, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</P>\012", (STRING *) 1));
/*692*/ 	}
/*692*/ 	if( Documentator_copyright != NULL ){
/*693*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"<P><B>Copyright:</B> ", Documentator_copyright, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</P>\012", (STRING *) 1));
/*696*/ 	}
/*696*/ 	if( Documentator_license != NULL ){
/*697*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"<P><B>License:</B> ", Documentator_license, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</P>\012", (STRING *) 1));
/*700*/ 	}
/*700*/ 	if( Documentator_pkg_descr ){
/*702*/ 		buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"<P><B>PHP version:</B> ");
/*703*/ 		if( (Documentator_php_ver == 4) ){
/*704*/ 			buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"4</P>\012");
/*706*/ 		} else {
/*706*/ 			buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"5</P>\012");
/*709*/ 		}
/*709*/ 		buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"<P><B>Required modules:</B>\012");
/*710*/ 		Documentator_none = TRUE;
/*711*/ 		{
/*711*/ 			int m2runtime_for_limit_1;
/*711*/ 			Documentator_i = 0;
/*711*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_required_packages) - 1);
/*712*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*712*/ 				Documentator_pkg = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_required_packages, Documentator_i, Documentator_0err_entry_get, 83);
/*713*/ 				if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pkg, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 84), Documentator_fn) != 0) &&  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_pkg, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 85)) ){
/*714*/ 					if( !Documentator_none ){
/*715*/ 						buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ");
/*717*/ 					}
/*717*/ 					Documentator_none = FALSE;
/*718*/ 					Documentator_path = FileName_Relative(Documentator_fn_remapped, Documentator_RefMap(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pkg, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 86), Documentator_extension, (STRING *) 1)));
/*720*/ 					buffer_AddString((void *)&Documentator_descr, Documentator_Anchor(Documentator_path, FileName_Basename((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pkg, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 87))));
/*723*/ 				}
/*723*/ 			}
/*723*/ 		}
/*723*/ 		if( Documentator_none ){
/*724*/ 			buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"<I>none</I>");
/*726*/ 		}
/*726*/ 		buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<P>\012");
/*728*/ 		buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"<P><B>Required packages:</B>\012");
/*729*/ 		Documentator_none = TRUE;
/*730*/ 		{
/*730*/ 			int m2runtime_for_limit_1;
/*730*/ 			Documentator_i = 0;
/*730*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_required_packages) - 1);
/*731*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*731*/ 				Documentator_pkg = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_required_packages, Documentator_i, Documentator_0err_entry_get, 88);
/*732*/ 				if( ((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pkg, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 89), Documentator_fn) != 0) && ! *(int *)m2runtime_dereference_rhs_RECORD(Documentator_pkg, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 90)) ){
/*733*/ 					if( !Documentator_none ){
/*734*/ 						buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ");
/*736*/ 					}
/*736*/ 					Documentator_none = FALSE;
/*737*/ 					Documentator_path = FileName_Relative(Documentator_fn_remapped, Documentator_RefMap(m2runtime_concat_STRING(0, FileName_DropExtension((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pkg, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 91)), Documentator_extension, (STRING *) 1)));
/*739*/ 					buffer_AddString((void *)&Documentator_descr, Documentator_Anchor(Documentator_path, FileName_Basename(FileName_Relative(Documentator_fn_remapped, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pkg, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 92)))));
/*747*/ 				}
/*747*/ 			}
/*747*/ 		}
/*747*/ 		if( Documentator_none ){
/*748*/ 			buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"<I>none</I>");
/*750*/ 		}
/*750*/ 		buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<P>\012");
/*753*/ 	}
/*753*/ 	if( (m2runtime_count(Documentator_include_path) > 0) ){
/*754*/ 		buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"<P><B>include_path must resolve these packages:</B>\012");
/*755*/ 		{
/*755*/ 			int m2runtime_for_limit_1;
/*755*/ 			Documentator_i = 0;
/*755*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_include_path) - 1);
/*756*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*756*/ 				if( (Documentator_i > 0) ){
/*757*/ 					buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ");
/*759*/ 				}
/*759*/ 				buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"<code>");
/*760*/ 				buffer_AddString((void *)&Documentator_descr, (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_include_path, Documentator_i, Documentator_0err_entry_get, 93));
/*761*/ 				buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"</code>");
/*763*/ 			}
/*763*/ 		}
/*763*/ 		buffer_AddString((void *)&Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</P>\012");
/*766*/ 	}
/*766*/ 	if( Documentator_authors != NULL ){
/*767*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"<P><B>Author:</B> ", Documentator_authors, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</P>\012", (STRING *) 1));
/*770*/ 	}
/*770*/ 	if( Documentator_since != NULL ){
/*771*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"<P><B>Since:</B> ", Documentator_since, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</P>\012", (STRING *) 1));
/*774*/ 	}
/*774*/ 	if( Documentator_deprecated != NULL ){
/*775*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"<P><B>Deprecated:</B> ", Documentator_deprecated, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</P>\012", (STRING *) 1));
/*778*/ 	}
/*778*/ 	if( m2runtime_strcmp(Documentator_long, EMPTY_STRING) > 0 ){
/*779*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<P>\012", Documentator_long, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"\012</P>\012", (STRING *) 1));
/*782*/ 	}
/*782*/ 	if( m2runtime_strcmp(Documentator_see, EMPTY_STRING) > 0 ){
/*783*/ 		buffer_AddString((void *)&Documentator_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"<P><b>See also:</b> ", Documentator_see, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"\012</P>\012", (STRING *) 1));
/*786*/ 	}
/*786*/ 	if( Documentator_pkg_descr ){
/*787*/ 		Documentator_p(buffer_ToString(Documentator_descr));
/*788*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"<HR>\012");
/*790*/ 	} else {
/*790*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"<BLOCKQUOTE>\012");
/*791*/ 		Documentator_p(buffer_ToString(Documentator_descr));
/*792*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"</BLOCKQUOTE>\012");
/*795*/ 	}
/*797*/ }


/*799*/ void
/*799*/ Documentator_AddPrivateItem(STRING *Documentator_item)
/*799*/ {
/*799*/ 	Documentator_private_items = m2runtime_concat_STRING(0, Documentator_private_items, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"<code>", Documentator_item, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"</code><br>\012", (STRING *) 1);
/*803*/ }


/*805*/ void
/*805*/ Documentator_DocConst(RECORD *Documentator_c)
/*805*/ {
/*805*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 94) ){
/*806*/ 		Documentator_AddPrivateItem((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 95));
/*808*/ 		return ;
/*809*/ 	}
/*809*/ 	Documentator_VSpaceBeforeItem((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 96) != NULL);
/*810*/ 	Documentator_ItemAnchor((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 97));
/*811*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"<CODE><BIG><B>");
/*812*/ 	Documentator_p((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 98));
/*813*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"</B></BIG> = ");
/*814*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 99) == NULL ){
/*815*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"<i>FAILED_TO_PARSE</i>");
/*817*/ 	} else {
/*817*/ 		Documentator_DocValue((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 100), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 101), (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 102), 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 103));
/*819*/ 	}
/*819*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"</CODE>\012");
/*820*/ 	Documentator_DocDescr(FALSE, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 104));
/*821*/ 	Documentator_VSpaceAfterItem(m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 105), NULL) > 0);
/*825*/ }


/*831*/ STRING *
/*831*/ Documentator_DocType(RECORD *Documentator_t)
/*831*/ {
/*832*/ 	RECORD * Documentator_c = NULL;
/*834*/ 	STRING * Documentator_x = NULL;
/*834*/ 	if( Documentator_t == NULL ){
/*835*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"FIXME_UNKNOWN_TYPE";
/*838*/ 	}
/*838*/ 	switch( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_t, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 106)){

/*839*/ 	case 0:
/*839*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"null";
/*840*/ 	break;

/*840*/ 	case 1:
/*840*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"void";
/*841*/ 	break;

/*841*/ 	case 2:
/*841*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"boolean";
/*842*/ 	break;

/*842*/ 	case 3:
/*842*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int";
/*843*/ 	break;

/*843*/ 	case 4:
/*843*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"float";
/*844*/ 	break;

/*844*/ 	case 5:
/*844*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string";
/*846*/ 	break;

/*846*/ 	case 6:
/*848*/ 	do {
/*848*/ 		switch( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_t, 2 * sizeof(void*) + 3 * sizeof(int), Documentator_0err_entry_get, 107)){

/*849*/ 		case 1:
/*849*/ 		Documentator_x = m2runtime_concat_STRING(0, Documentator_x, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"[unknown]", (STRING *) 1);
/*850*/ 		break;

/*850*/ 		case 3:
/*850*/ 		Documentator_x = m2runtime_concat_STRING(0, Documentator_x, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"[int]", (STRING *) 1);
/*851*/ 		break;

/*851*/ 		case 5:
/*851*/ 		Documentator_x = m2runtime_concat_STRING(0, Documentator_x, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"[string]", (STRING *) 1);
/*852*/ 		break;

/*852*/ 		case 7:
/*852*/ 		Documentator_x = m2runtime_concat_STRING(0, Documentator_x, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"[]", (STRING *) 1);
/*854*/ 		break;

/*854*/ 		default: m2runtime_missing_case_in_switch(Documentator_0err_entry_get, 108);
/*854*/ 		}
/*854*/ 		Documentator_t = (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_t, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 109);
/*855*/ 	} while( !( ((Documentator_t == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_t, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 110) != 6))) ));
/*856*/ 	return m2runtime_concat_STRING(0, Documentator_DocType(Documentator_t), Documentator_x, (STRING *) 1);
/*858*/ 	break;

/*858*/ 	case 7:
/*858*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"mixed";
/*859*/ 	break;

/*859*/ 	case 8:
/*859*/ 	return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"resource";
/*860*/ 	break;

/*860*/ 	case 9:
/*861*/ 	Documentator_c = (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_t, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 111);
/*862*/ 	if( Documentator_c == NULL ){
/*863*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"object";
/*864*/ 	} else if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 4 * sizeof(int), Documentator_0err_entry_get, 112) ){
/*865*/ 		return (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 113);
/*867*/ 	} else {
/*867*/ 		return Documentator_Anchor(Documentator_ItemToUrl((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 114)), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 115));
/*870*/ 	}
/*870*/ 	break;

/*870*/ 	default: m2runtime_missing_case_in_switch(Documentator_0err_entry_get, 116);
/*871*/ 	}
/*871*/ 	m2runtime_missing_return(Documentator_0err_entry_get, 117);
/*871*/ 	return NULL;
/*873*/ }


/*875*/ void
/*875*/ Documentator_DocVar(RECORD *Documentator_v)
/*875*/ {
/*875*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_v, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 118) ){
/*876*/ 		Documentator_AddPrivateItem(m2runtime_concat_STRING(0, m2runtime_CHR(36), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_v, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 119), (STRING *) 1));
/*878*/ 		return ;
/*879*/ 	}
/*879*/ 	Documentator_VSpaceBeforeItem((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_v, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 120) != NULL);
/*880*/ 	Documentator_ItemAnchor(m2runtime_concat_STRING(0, m2runtime_CHR(36), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_v, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 121), (STRING *) 1));
/*881*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"<CODE><I>");
/*882*/ 	Documentator_p(Documentator_DocType((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_v, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 122)));
/*883*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"</I> <BIG><B>$");
/*884*/ 	Documentator_p((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_v, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 123));
/*885*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"</B></BIG>");
/*890*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"</CODE>\012");
/*891*/ 	Documentator_DocDescr(FALSE, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_v, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 124));
/*892*/ 	Documentator_VSpaceAfterItem((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_v, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 125) != NULL);
/*896*/ }


/*898*/ void
/*898*/ Documentator_DocSignature(STRING *Documentator_name, RECORD *Documentator_s)
/*898*/ {
/*899*/ 	int Documentator_i = 0;
/*900*/ 	ARRAY * Documentator_args = NULL;
/*902*/ 	RECORD * Documentator_a = NULL;
/*902*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"<I>");
/*903*/ 	Documentator_p(Documentator_DocType((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_s, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 126)));
/*904*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</I> ");
/*905*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_s, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 127) ){
/*906*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"&amp; ");
/*908*/ 	}
/*908*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"<BIG><B>");
/*909*/ 	Documentator_p(Documentator_name);
/*910*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"</B></BIG>(");
/*911*/ 	Documentator_args = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_s, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 128);
/*912*/ 	{
/*912*/ 		int m2runtime_for_limit_1;
/*912*/ 		Documentator_i = 0;
/*912*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_args) - 1);
/*913*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*913*/ 			Documentator_a = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_args, Documentator_i, Documentator_0err_entry_get, 129);
/*914*/ 			if( (Documentator_i == 0) ){
/*915*/ 				Documentator_p(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<br>", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"&nbsp;&nbsp;&nbsp;&nbsp;", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"&nbsp;&nbsp;&nbsp;&nbsp;", (STRING *) 1));
/*917*/ 			} else {
/*917*/ 				Documentator_p(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)",\012<br>", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"&nbsp;&nbsp;&nbsp;&nbsp;", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"&nbsp;&nbsp;&nbsp;&nbsp;", (STRING *) 1));
/*919*/ 			}
/*919*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_a, 3 * sizeof(void*) + 3 * sizeof(int), Documentator_0err_entry_get, 130) ){
/*920*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"return ");
/*922*/ 			}
/*922*/ 			Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"<I>");
/*923*/ 			Documentator_p(Documentator_DocType((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_a, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 131)));
/*924*/ 			Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"</I>&nbsp;");
/*925*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_a, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 132) ){
/*926*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"&amp; ");
/*928*/ 			}
/*928*/ 			Documentator_p(m2runtime_CHR(36));
/*929*/ 			Documentator_p((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_a, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 133));
/*930*/ 			if( (Documentator_i >=  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_s, 2 * sizeof(void*) + 3 * sizeof(int), Documentator_0err_entry_get, 134)) ){
/*931*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)" = ");
/*932*/ 				Documentator_DocValue((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_a, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 135), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_a, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 136));
/*935*/ 			}
/*935*/ 		}
/*935*/ 	}
/*935*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_s, 2 * sizeof(void*) + 4 * sizeof(int), Documentator_0err_entry_get, 137) ){
/*936*/ 		if( (Documentator_i == 0) ){
/*937*/ 			Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"...");
/*939*/ 		} else {
/*939*/ 			Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)", ...");
/*942*/ 		}
/*942*/ 	}
/*942*/ 	Documentator_p(m2runtime_CHR(41));
/*946*/ }


/*948*/ void
/*948*/ Documentator_DocRaisedErrors(int Documentator_errs)
/*948*/ {
/*949*/ 	ARRAY * Documentator_a = NULL;
/*951*/ 	int Documentator_i = 0;
/*951*/ 	if( (Documentator_errs == 0) ){
/*953*/ 		return ;
/*954*/ 	}
/*954*/ 	Documentator_a = Errors_ErrorsSetToNames(Documentator_errs);
/*955*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"<br><i>triggers</i> ");
/*956*/ 	{
/*956*/ 		int m2runtime_for_limit_1;
/*956*/ 		Documentator_i = 0;
/*956*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_a) - 1);
/*957*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*957*/ 			if( (Documentator_i > 0) ){
/*958*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ");
/*960*/ 			}
/*960*/ 			Documentator_p(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"<CODE>", (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_a, Documentator_i, Documentator_0err_entry_get, 138), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"</CODE>", (STRING *) 1));
/*962*/ 		}
/*962*/ 	}
/*962*/ 	Documentator_p(m2runtime_CHR(10));
/*966*/ }


/*969*/ void
/*969*/ Documentator_DocThrownExceptions(ARRAY *Documentator_exc)
/*969*/ {
/*970*/ 	int Documentator_i = 0;
/*972*/ 	RECORD * Documentator_e = NULL;
/*972*/ 	Documentator_exc = Classes_Sort(Classes_CheckedExceptionsSubset(Documentator_exc));
/*973*/ 	if( (m2runtime_count(Documentator_exc) == 0) ){
/*975*/ 		return ;
/*976*/ 	}
/*976*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"<br>throws ");
/*977*/ 	{
/*977*/ 		int m2runtime_for_limit_1;
/*977*/ 		Documentator_i = 0;
/*977*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_exc) - 1);
/*978*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*978*/ 			if( (Documentator_i > 0) ){
/*979*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ");
/*981*/ 			}
/*981*/ 			Documentator_e = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_exc, Documentator_i, Documentator_0err_entry_get, 139);
/*982*/ 			if( Documentator_e == NULL ){
/*983*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"<i>FIXME_UNKNOWN_EXCEPTION</i>");
/*985*/ 			} else {
/*985*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_e, 15 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 140) ){
/*986*/ 					Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"unchecked ");
/*988*/ 				}
/*988*/ 				Documentator_AnchorToClass(Documentator_e);
/*991*/ 			}
/*992*/ 		}
/*992*/ 	}
/*994*/ }


/*998*/ void
/*998*/ Documentator_DocThrownExceptionsDescr(ARRAY *Documentator_descrs)
/*998*/ {
/*999*/ 	int Documentator_i = 0;
/*1001*/ 	RECORD * Documentator_e = NULL;
/*1001*/ 	if( (m2runtime_count(Documentator_descrs) == 0) ){
/*1003*/ 		return ;
/*1004*/ 	}
/*1004*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"<blockquote>\012<b>Throws:</b><ul>\012");
/*1005*/ 	{
/*1005*/ 		int m2runtime_for_limit_1;
/*1005*/ 		Documentator_i = 0;
/*1005*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_descrs) - 1);
/*1006*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1006*/ 			Documentator_e = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_descrs, Documentator_i, Documentator_0err_entry_get, 141);
/*1007*/ 			Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<li>");
/*1010*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_e, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 142), 15 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 143) ){
/*1011*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"unchecked ");
/*1013*/ 			}
/*1013*/ 			Documentator_AnchorToClass((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_e, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 144));
/*1016*/ 			Documentator_p(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"&nbsp;&nbsp;&nbsp;&nbsp;", Documentator_ResolveTags(Documentator_trim((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_e, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 145))), (STRING *) 1));
/*1018*/ 			Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"\012</li>\012");
/*1020*/ 		}
/*1020*/ 	}
/*1020*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"</ul>\012</blockquote>\012");
/*1024*/ }


/*1026*/ void
/*1026*/ Documentator_DocFunc(RECORD *Documentator_f)
/*1026*/ {
/*1026*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_f, 10 * sizeof(void*) + 3 * sizeof(int), Documentator_0err_entry_get, 146) ){
/*1027*/ 		Documentator_AddPrivateItem(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_f, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 147), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1));
/*1029*/ 		return ;
/*1030*/ 	}
/*1030*/ 	Documentator_VSpaceBeforeItem((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_f, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 148) != NULL);
/*1031*/ 	Documentator_ItemAnchor(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_f, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 149), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1));
/*1032*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"<CODE>");
/*1033*/ 	Documentator_DocSignature((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_f, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 150), (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_f, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 151));
/*1034*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"</CODE>\012");
/*1035*/ 	Documentator_DocRaisedErrors( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_f, 10 * sizeof(void*) + 5 * sizeof(int), Documentator_0err_entry_get, 152));
/*1036*/ 	Documentator_DocThrownExceptions((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_f, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 153));
/*1037*/ 	Documentator_DocDescr(FALSE, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_f, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 154));
/*1038*/ 	Documentator_DocThrownExceptionsDescr((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_f, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 155));
/*1039*/ 	Documentator_VSpaceAfterItem(((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_f, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 156), NULL) > 0) || ((m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_f, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 157)) > 0))));
/*1044*/ }


/*1051*/ void
/*1051*/ Documentator_DocClassConst(RECORD *Documentator_cl, RECORD *Documentator_parent, RECORD *Documentator_c)
/*1051*/ {
/*1051*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 158) == 0) ){
/*1053*/ 		return ;
/*1054*/ 	}
/*1054*/ 	Documentator_VSpaceBeforeItem(((Documentator_parent == NULL) && ((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 159) != NULL)));
/*1055*/ 	Documentator_ItemAnchor(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 160), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 161), (STRING *) 1));
/*1056*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"<CODE><BIG><B>");
/*1057*/ 	Documentator_p((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 162));
/*1058*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"</B></BIG> = ");
/*1059*/ 	Documentator_DocValue((RECORD *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 163), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 164), (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 165), 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 166));
/*1060*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"</CODE>\012");
/*1061*/ 	if( Documentator_parent == NULL ){
/*1062*/ 		Documentator_DocDescr(FALSE, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 167));
/*1063*/ 		Documentator_VSpaceAfterItem(m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 168), NULL) > 0);
/*1065*/ 	} else {
/*1065*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"<BR><I>inherited from</i> <CODE>");
/*1066*/ 		Documentator_p(Documentator_Anchor(Documentator_ItemToUrl(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_parent, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 169), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 170), (STRING *) 1)), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_parent, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 171)));
/*1067*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"</CODE>\012");
/*1068*/ 		Documentator_VSpaceAfterItem(FALSE);
/*1071*/ 	}
/*1073*/ }


/*1075*/ void
/*1075*/ Documentator_DocClassProperty(RECORD *Documentator_c, RECORD *Documentator_parent, RECORD *Documentator_pr)
/*1075*/ {
/*1075*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 172) == 0) ){
/*1076*/ 		if( ((Documentator_parent == NULL) && ((Documentator_php_ver == 4))) ){
/*1077*/ 			Documentator_AddPrivateItem(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 173), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 174), (STRING *) 1));
/*1080*/ 		}
/*1080*/ 		return ;
/*1081*/ 	}
/*1081*/ 	Documentator_VSpaceBeforeItem(((Documentator_parent == NULL) && ((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 175) != NULL)));
/*1082*/ 	Documentator_ItemAnchor(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 176), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 177), (STRING *) 1));
/*1083*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"<CODE>");
/*1084*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 178) == 1) ){
/*1085*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"protected ");
/*1087*/ 	}
/*1087*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 6 * sizeof(void*) + 3 * sizeof(int), Documentator_0err_entry_get, 179) ){
/*1088*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"static ");
/*1095*/ 	}
/*1095*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"<I>");
/*1096*/ 	Documentator_p(Documentator_DocType((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 180)));
/*1097*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"</I> <BIG><B>$");
/*1098*/ 	Documentator_p((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 181));
/*1099*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"</B></BIG>");
/*1100*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 182) != NULL) && ((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 183) != NULL)) ){
/*1101*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)" = ");
/*1102*/ 		Documentator_DocValue((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 184), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 185));
/*1104*/ 	}
/*1104*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"</CODE>\012");
/*1105*/ 	if( Documentator_parent == NULL ){
/*1106*/ 		Documentator_DocDescr(FALSE, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 186));
/*1107*/ 		Documentator_VSpaceAfterItem(m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 187), NULL) > 0);
/*1109*/ 	} else {
/*1109*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"<BR><I>inherited from</i> ");
/*1110*/ 		Documentator_p(Documentator_Anchor(Documentator_ItemToUrl(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_parent, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 188), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"::$", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_pr, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 189), (STRING *) 1)), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_parent, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 190)));
/*1111*/ 		Documentator_p(m2runtime_CHR(10));
/*1112*/ 		Documentator_VSpaceAfterItem(FALSE);
/*1115*/ 	}
/*1117*/ }


/*1119*/ int
/*1119*/ Documentator_IsClassInSet(RECORD *Documentator_c, ARRAY *Documentator_set)
/*1119*/ {
/*1121*/ 	int Documentator_i = 0;
/*1121*/ 	{
/*1121*/ 		int m2runtime_for_limit_1;
/*1121*/ 		Documentator_i = 0;
/*1121*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_set) - 1);
/*1122*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1122*/ 			if( (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_set, Documentator_i, Documentator_0err_entry_get, 191) == Documentator_c ){
/*1123*/ 				return TRUE;
/*1126*/ 			}
/*1126*/ 		}
/*1126*/ 	}
/*1126*/ 	return FALSE;
/*1130*/ }


/*1148*/ void
/*1148*/ Documentator_ListImplementedOrOverriddenMethods(RECORD *Documentator_c, RECORD *Documentator_m, ARRAY *Documentator_traversed, int Documentator_found_overridden)
/*1148*/ {
/*1149*/ 	int Documentator_i = 0;
/*1151*/ 	RECORD * Documentator_m2 = NULL;
/*1156*/ 	if( ((Documentator_c == NULL) ||  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m, 9 * sizeof(void*) + 3 * sizeof(int), Documentator_0err_entry_get, 192) || Documentator_IsClassInSet(Documentator_c, Documentator_traversed)) ){
/*1158*/ 		return ;
/*1161*/ 	}
/*1161*/ 	{
/*1161*/ 		int m2runtime_for_limit_1;
/*1161*/ 		Documentator_i = 0;
/*1161*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 193)) - 1);
/*1162*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1162*/ 			Documentator_m2 = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 194), Documentator_i, Documentator_0err_entry_get, 195);
/*1164*/ 			if( ((Documentator_m2 != Documentator_m) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m2, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 196), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 197)) == 0) && (( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 7 * sizeof(int), Documentator_0err_entry_get, 198) || (Documentator_m2 != (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 9 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 199))))) ){
/*1171*/ 				if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m2, 9 * sizeof(void*) + 3 * sizeof(int), Documentator_0err_entry_get, 200) ){
/*1172*/ 					Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"\012<BR><I>implements</i> ");
/*1174*/ 				} else {
/*1174*/ 					if( Documentator_found_overridden ){
/*1175*/ 						Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ");
/*1177*/ 					} else {
/*1177*/ 						Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"\012<BR><I>overrides</i> ");
/*1178*/ 						Documentator_found_overridden = TRUE;
/*1181*/ 					}
/*1181*/ 				}
/*1181*/ 				Documentator_p(Documentator_Anchor(Documentator_ItemToUrl(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 201), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m2, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 202), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1)), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 203)));
/*1184*/ 			}
/*1185*/ 		}
/*1185*/ 	}
/*1185*/ 	*(RECORD **)m2runtime_dereference_lhs_ARRAY_next(&Documentator_traversed, sizeof(void *), 1, Documentator_0err_entry_get, 204) = Documentator_c;
/*1188*/ 	Documentator_ListImplementedOrOverriddenMethods((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 205), Documentator_m, Documentator_traversed, Documentator_found_overridden);
/*1191*/ 	{
/*1191*/ 		int m2runtime_for_limit_1;
/*1191*/ 		Documentator_i = 0;
/*1191*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 206)) - 1);
/*1192*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1192*/ 			Documentator_ListImplementedOrOverriddenMethods((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 207), Documentator_i, Documentator_0err_entry_get, 208), Documentator_m, Documentator_traversed, Documentator_found_overridden);
/*1195*/ 		}
/*1195*/ 	}
/*1197*/ }


/*1207*/ void
/*1207*/ Documentator_DocClassMethod(RECORD *Documentator_c, RECORD *Documentator_parent, RECORD *Documentator_m)
/*1207*/ {
/*1207*/ 	if( ((Documentator_parent == NULL) && (( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m, 9 * sizeof(void*) + 4 * sizeof(int), Documentator_0err_entry_get, 209) == 0))) ){
/*1208*/ 		if( (Documentator_php_ver == 4) ){
/*1209*/ 			Documentator_AddPrivateItem(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 210), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 211), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1));
/*1212*/ 		}
/*1212*/ 		return ;
/*1214*/ 	}
/*1214*/ 	Documentator_VSpaceBeforeItem(((Documentator_parent == NULL) && ((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 212) != NULL)));
/*1215*/ 	Documentator_ItemAnchor(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 213), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 214), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1));
/*1216*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"<CODE>");
/*1217*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m, 9 * sizeof(void*) + 3 * sizeof(int), Documentator_0err_entry_get, 215) && ! *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 7 * sizeof(int), Documentator_0err_entry_get, 216)) ){
/*1217*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"abstract ");
/*1218*/ 	}
/*1218*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m, 9 * sizeof(void*) + 4 * sizeof(int), Documentator_0err_entry_get, 217) == 1) ){
/*1218*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"protected ");
/*1219*/ 	}
/*1219*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m, 9 * sizeof(void*) + 5 * sizeof(int), Documentator_0err_entry_get, 218) ){
/*1219*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"static ");
/*1220*/ 	}
/*1220*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m, 9 * sizeof(void*) + 6 * sizeof(int), Documentator_0err_entry_get, 219) ){
/*1220*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"final ");
/*1221*/ 	}
/*1221*/ 	Documentator_DocSignature((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 220), (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_m, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 221));
/*1222*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"</CODE>\012");
/*1223*/ 	Documentator_DocRaisedErrors( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m, 9 * sizeof(void*) + 9 * sizeof(int), Documentator_0err_entry_get, 222));
/*1224*/ 	Documentator_DocThrownExceptions((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_m, 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 223));
/*1225*/ 	if( Documentator_parent == NULL ){
/*1226*/ 		Documentator_ListImplementedOrOverriddenMethods(Documentator_c, Documentator_m, (
/*1226*/ 			push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*1226*/ 			(ARRAY*) pop()
/*1226*/ 		), FALSE);
/*1227*/ 		Documentator_DocDescr(FALSE, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 224));
/*1228*/ 		Documentator_DocThrownExceptionsDescr((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_m, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 225));
/*1229*/ 		Documentator_VSpaceAfterItem(((m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 226), NULL) > 0) || ((m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_m, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 227)) > 0))));
/*1232*/ 	} else {
/*1232*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"<BR><I>inherited from</i> ");
/*1233*/ 		Documentator_p(Documentator_Anchor(Documentator_ItemToUrl(m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_parent, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 228), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 229), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"()", (STRING *) 1)), (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_parent, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 230)));
/*1234*/ 		Documentator_p(m2runtime_CHR(10));
/*1235*/ 		Documentator_VSpaceAfterItem(FALSE);
/*1238*/ 	}
/*1240*/ }


/*1241*/ int
/*1241*/ Documentator_NotInList(STRING *Documentator_name, ARRAY **Documentator_l)
/*1241*/ {
/*1243*/ 	int Documentator_i = 0;
/*1243*/ 	{
/*1243*/ 		int m2runtime_for_limit_1;
/*1243*/ 		Documentator_i = 0;
/*1243*/ 		m2runtime_for_limit_1 = (m2runtime_count(*Documentator_l) - 1);
/*1244*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1244*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(*Documentator_l, Documentator_i, Documentator_0err_entry_get, 231), Documentator_name) == 0 ){
/*1245*/ 				return FALSE;
/*1248*/ 			}
/*1248*/ 		}
/*1248*/ 	}
/*1248*/ 	*(STRING **)m2runtime_dereference_lhs_ARRAY(Documentator_l, sizeof(void *), 1, Documentator_i, Documentator_0err_entry_get, 232) = Documentator_name;
/*1249*/ 	return TRUE;
/*1253*/ }


/*1255*/ void
/*1255*/ Documentator_DocInheritedConsts(RECORD *Documentator_cl)
/*1255*/ {
/*1256*/ 	ARRAY * Documentator_l = NULL;
/*1257*/ 	ARRAY * Documentator_consts = NULL;
/*1258*/ 	RECORD * Documentator_p = NULL;
/*1260*/ 	int Documentator_i = 0;
/*1260*/ 	if( (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 233) == NULL ){
/*1262*/ 		return ;
/*1263*/ 	}
/*1263*/ 	Documentator_consts = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 234);
/*1264*/ 	{
/*1264*/ 		int m2runtime_for_limit_1;
/*1264*/ 		Documentator_i = 0;
/*1264*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_consts) - 1);
/*1265*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1265*/ 			*(STRING **)m2runtime_dereference_lhs_ARRAY(&Documentator_l, sizeof(void *), 1, Documentator_i, Documentator_0err_entry_get, 235) = (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 236), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 237);
/*1267*/ 		}
/*1267*/ 	}
/*1267*/ 	Documentator_p = (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 238);
/*1269*/ 	do {
/*1269*/ 		Documentator_consts = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_p, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 239);
/*1270*/ 		{
/*1270*/ 			int m2runtime_for_limit_1;
/*1270*/ 			Documentator_i = 0;
/*1270*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_consts) - 1);
/*1271*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1271*/ 				if( ((( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 240), 5 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 241) != 0)) && Documentator_NotInList((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 242), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 243), &Documentator_l)) ){
/*1273*/ 					Documentator_DocClassConst(Documentator_cl, Documentator_p, (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 244));
/*1276*/ 				}
/*1276*/ 			}
/*1276*/ 		}
/*1276*/ 		Documentator_p = (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_p, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 245);
/*1277*/ 	} while( !( Documentator_p == NULL ));
/*1281*/ }


/*1283*/ void
/*1283*/ Documentator_DocInheritedProperties(RECORD *Documentator_cl)
/*1283*/ {
/*1284*/ 	ARRAY * Documentator_l = NULL;
/*1285*/ 	ARRAY * Documentator_properties = NULL;
/*1287*/ 	int Documentator_i = 0;

/*1289*/ 	void
/*1289*/ 	Documentator_ScanProperties(RECORD *Documentator_c)
/*1289*/ 	{
/*1290*/ 		ARRAY * Documentator_properties = NULL;
/*1292*/ 		int Documentator_i = 0;
/*1292*/ 		if( Documentator_c == NULL ){
/*1294*/ 			return ;
/*1295*/ 		}
/*1295*/ 		Documentator_properties = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 246);
/*1296*/ 		{
/*1296*/ 			int m2runtime_for_limit_1;
/*1296*/ 			Documentator_i = 0;
/*1296*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_properties) - 1);
/*1297*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1297*/ 				if( (!(( *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_properties, Documentator_i, Documentator_0err_entry_get, 247), 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 248) == 0)) && Documentator_NotInList((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_properties, Documentator_i, Documentator_0err_entry_get, 249), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 250), &Documentator_l)) ){
/*1299*/ 					Documentator_DocClassProperty(Documentator_cl, Documentator_c, (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_properties, Documentator_i, Documentator_0err_entry_get, 251));
/*1302*/ 				}
/*1303*/ 			}
/*1303*/ 		}
/*1304*/ 	}


/*1305*/ 	void
/*1305*/ 	Documentator_ScanPropertiesRecursive(RECORD *Documentator_c)
/*1305*/ 	{
/*1307*/ 		int Documentator_i = 0;
/*1307*/ 		if( Documentator_c == NULL ){
/*1309*/ 			return ;
/*1310*/ 		}
/*1310*/ 		Documentator_ScanProperties(Documentator_c);
/*1311*/ 		Documentator_ScanPropertiesRecursive((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 252));
/*1312*/ 		{
/*1312*/ 			int m2runtime_for_limit_1;
/*1312*/ 			Documentator_i = 0;
/*1312*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 253)) - 1);
/*1313*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1313*/ 				Documentator_ScanPropertiesRecursive((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 254), Documentator_i, Documentator_0err_entry_get, 255));
/*1316*/ 			}
/*1316*/ 		}
/*1318*/ 	}

/*1318*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 256) == NULL) && ((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 257) == NULL)) ){
/*1320*/ 		return ;
/*1323*/ 	}
/*1323*/ 	Documentator_properties = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 258);
/*1324*/ 	{
/*1324*/ 		int m2runtime_for_limit_1;
/*1324*/ 		Documentator_i = 0;
/*1324*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_properties) - 1);
/*1325*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1325*/ 			*(STRING **)m2runtime_dereference_lhs_ARRAY(&Documentator_l, sizeof(void *), 1, Documentator_i, Documentator_0err_entry_get, 259) = (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_properties, Documentator_i, Documentator_0err_entry_get, 260), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 261);
/*1329*/ 		}
/*1329*/ 	}
/*1329*/ 	Documentator_ScanPropertiesRecursive((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 262));
/*1332*/ 	if( !(( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 15 * sizeof(void*) + 6 * sizeof(int), Documentator_0err_entry_get, 263) ||  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 15 * sizeof(void*) + 7 * sizeof(int), Documentator_0err_entry_get, 264))) ){
/*1334*/ 		return ;
/*1335*/ 	}
/*1335*/ 	{
/*1335*/ 		int m2runtime_for_limit_1;
/*1335*/ 		Documentator_i = 0;
/*1335*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 265)) - 1);
/*1336*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1336*/ 			Documentator_ScanPropertiesRecursive((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 266), Documentator_i, Documentator_0err_entry_get, 267));
/*1339*/ 		}
/*1339*/ 	}
/*1341*/ }


/*1343*/ void
/*1343*/ Documentator_DocInheritedMethods(RECORD *Documentator_cl)
/*1343*/ {
/*1344*/ 	ARRAY * Documentator_l = NULL;
/*1345*/ 	ARRAY * Documentator_methods = NULL;
/*1347*/ 	int Documentator_i = 0;

/*1349*/ 	void
/*1349*/ 	Documentator_ScanMethods(RECORD *Documentator_c)
/*1349*/ 	{
/*1350*/ 		ARRAY * Documentator_methods = NULL;
/*1351*/ 		int Documentator_i = 0;
/*1353*/ 		RECORD * Documentator_m = NULL;
/*1353*/ 		if( Documentator_c == NULL ){
/*1355*/ 			return ;
/*1356*/ 		}
/*1356*/ 		Documentator_methods = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 268);
/*1357*/ 		{
/*1357*/ 			int m2runtime_for_limit_1;
/*1357*/ 			Documentator_i = 0;
/*1357*/ 			m2runtime_for_limit_1 = (m2runtime_count(Documentator_methods) - 1);
/*1358*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1358*/ 				Documentator_m = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_methods, Documentator_i, Documentator_0err_entry_get, 269);
/*1359*/ 				if( (!(( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_m, 9 * sizeof(void*) + 4 * sizeof(int), Documentator_0err_entry_get, 270) == 0)) && Documentator_NotInList((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_m, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 271), &Documentator_l)) ){
/*1360*/ 					Documentator_DocClassMethod(Documentator_cl, Documentator_c, Documentator_m);
/*1363*/ 				}
/*1364*/ 			}
/*1364*/ 		}
/*1365*/ 	}


/*1366*/ 	void
/*1366*/ 	Documentator_ScanMethodsRecursive(RECORD *Documentator_c)
/*1366*/ 	{
/*1368*/ 		int Documentator_i = 0;
/*1368*/ 		if( Documentator_c == NULL ){
/*1370*/ 			return ;
/*1371*/ 		}
/*1371*/ 		Documentator_ScanMethods(Documentator_c);
/*1372*/ 		Documentator_ScanMethodsRecursive((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 272));
/*1373*/ 		{
/*1373*/ 			int m2runtime_for_limit_1;
/*1373*/ 			Documentator_i = 0;
/*1373*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 273)) - 1);
/*1374*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1374*/ 				Documentator_ScanMethodsRecursive((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 274), Documentator_i, Documentator_0err_entry_get, 275));
/*1377*/ 			}
/*1377*/ 		}
/*1379*/ 	}

/*1379*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 276) == NULL) && ((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 277) == NULL)) ){
/*1381*/ 		return ;
/*1384*/ 	}
/*1384*/ 	Documentator_methods = (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 278);
/*1385*/ 	{
/*1385*/ 		int m2runtime_for_limit_1;
/*1385*/ 		Documentator_i = 0;
/*1385*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_methods) - 1);
/*1386*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1386*/ 			*(STRING **)m2runtime_dereference_lhs_ARRAY(&Documentator_l, sizeof(void *), 1, Documentator_i, Documentator_0err_entry_get, 279) = (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_methods, Documentator_i, Documentator_0err_entry_get, 280), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 281);
/*1390*/ 		}
/*1390*/ 	}
/*1390*/ 	Documentator_ScanMethodsRecursive((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 282));
/*1393*/ 	if( !(( *(int *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 15 * sizeof(void*) + 6 * sizeof(int), Documentator_0err_entry_get, 283) ||  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 15 * sizeof(void*) + 7 * sizeof(int), Documentator_0err_entry_get, 284))) ){
/*1395*/ 		return ;
/*1396*/ 	}
/*1396*/ 	{
/*1396*/ 		int m2runtime_for_limit_1;
/*1396*/ 		Documentator_i = 0;
/*1396*/ 		m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 285)) - 1);
/*1397*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1397*/ 			Documentator_ScanMethodsRecursive((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 286), Documentator_i, Documentator_0err_entry_get, 287));
/*1400*/ 		}
/*1400*/ 	}
/*1402*/ }


/*1404*/ void
/*1404*/ Documentator_DocClassHierarchy(RECORD *Documentator_c)
/*1404*/ {

/*1406*/ 	void
/*1406*/ 	Documentator_recurse(RECORD *Documentator_c, STRING *Documentator_indent_this, STRING *Documentator_indent_next, int Documentator_anchor)
/*1406*/ 	{
/*1407*/ 		int Documentator_i = 0;
/*1409*/ 		STRING * Documentator_b = NULL;
/*1409*/ 		STRING * Documentator_a = NULL;
/*1409*/ 		Documentator_p(Documentator_indent_this);
/*1410*/ 		if( Documentator_anchor ){
/*1411*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 7 * sizeof(int), Documentator_0err_entry_get, 288) ){
/*1412*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"(<i>");
/*1414*/ 			}
/*1414*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 289) ){
/*1415*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"unchecked ");
/*1417*/ 			}
/*1417*/ 			Documentator_AnchorToClass(Documentator_c);
/*1418*/ 			if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 7 * sizeof(int), Documentator_0err_entry_get, 290) ){
/*1419*/ 				Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</i>)");
/*1422*/ 			}
/*1422*/ 		}
/*1422*/ 		Documentator_p(m2runtime_CHR(10));
/*1424*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 291) != NULL ){
/*1425*/ 			if( (ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 292) == NULL ){
/*1426*/ 				Documentator_a = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"  `--";
/*1427*/ 				Documentator_b = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"     ";
/*1429*/ 			} else {
/*1429*/ 				Documentator_a = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"  +--";
/*1430*/ 				Documentator_b = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"  |  ";
/*1432*/ 			}
/*1432*/ 			Documentator_recurse((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 293), m2runtime_concat_STRING(0, Documentator_indent_next, Documentator_a, (STRING *) 1), m2runtime_concat_STRING(0, Documentator_indent_next, Documentator_b, (STRING *) 1), TRUE);
/*1435*/ 		}
/*1435*/ 		{
/*1435*/ 			int m2runtime_for_limit_1;
/*1435*/ 			Documentator_i = 0;
/*1435*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 294)) - 1);
/*1436*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1436*/ 				if( (Documentator_i == (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 295)) - 1)) ){
/*1437*/ 					Documentator_a = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"  `--";
/*1438*/ 					Documentator_b = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"     ";
/*1440*/ 				} else {
/*1440*/ 					Documentator_a = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"  +--";
/*1441*/ 					Documentator_b = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"  |  ";
/*1443*/ 				}
/*1443*/ 				Documentator_recurse((RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 296), Documentator_i, Documentator_0err_entry_get, 297), m2runtime_concat_STRING(0, Documentator_indent_next, Documentator_a, (STRING *) 1), m2runtime_concat_STRING(0, Documentator_indent_next, Documentator_b, (STRING *) 1), TRUE);
/*1446*/ 			}
/*1446*/ 		}
/*1448*/ 	}

/*1448*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 298) == NULL) && ((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 299) == NULL)) ){
/*1450*/ 		return ;
/*1451*/ 	}
/*1451*/ 	Documentator_recurse(Documentator_c, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"      |  ", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"    ", FALSE);
/*1455*/ }


/*1457*/ void
/*1457*/ Documentator_DocClass(RECORD *Documentator_c)
/*1457*/ {
/*1460*/ 	int Documentator_i = 0;
/*1460*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 4 * sizeof(int), Documentator_0err_entry_get, 300) ){
/*1461*/ 		Documentator_AddPrivateItem((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 301));
/*1463*/ 		return ;
/*1464*/ 	}
/*1464*/ 	Documentator_VSpaceBeforeItem(TRUE);
/*1465*/ 	Documentator_curr_class = Documentator_c;
/*1466*/ 	Documentator_ItemAnchor((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 302));
/*1467*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"<pre>");
/*1468*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 6 * sizeof(int), Documentator_0err_entry_get, 303) ){
/*1469*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"abstract ");
/*1471*/ 	}
/*1471*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 5 * sizeof(int), Documentator_0err_entry_get, 304) ){
/*1472*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"final ");
/*1474*/ 	}
/*1474*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 305) ){
/*1475*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"unchecked ");
/*1477*/ 	}
/*1477*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(Documentator_c, 15 * sizeof(void*) + 7 * sizeof(int), Documentator_0err_entry_get, 306) ){
/*1478*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"interface ");
/*1480*/ 	} else {
/*1480*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"class ");
/*1482*/ 	}
/*1482*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"<BIG><B>");
/*1483*/ 	Documentator_p((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 307));
/*1484*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"</B></BIG>\012");
/*1512*/ 	Documentator_DocClassHierarchy(Documentator_c);
/*1513*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"</pre>\012");
/*1514*/ 	Documentator_DocDescr(FALSE, (STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 13 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 308));
/*1515*/ 	Documentator_VSpaceAfterItem(m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Documentator_c, 13 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 309), NULL) > 0);
/*1517*/ 	Documentator_VSpaceBeforeItem(FALSE);
/*1518*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"<CODE>{</CODE>\012<BLOCKQUOTE>\012");
/*1519*/ 	Documentator_VSpaceAfterItem(FALSE);
/*1528*/ 	if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 3 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 310) != NULL) && ((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 4 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 311) == NULL) && ((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 312) == NULL) && ((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 313) == NULL) && ((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 314) == NULL)) ){
/*1535*/ 		Documentator_p(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"<i>This class merely extends another class and does not add any", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\73,\0,\0,\0)" new member. Please see the extended class for details.</i>", (STRING *) 1));
/*1542*/ 	} else {
/*1542*/ 		{
/*1542*/ 			int m2runtime_for_limit_1;
/*1542*/ 			Documentator_i = 0;
/*1542*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 315)) - 1);
/*1543*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1543*/ 				Documentator_DocClassConst(Documentator_c, NULL, (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 6 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 316), Documentator_i, Documentator_0err_entry_get, 317));
/*1545*/ 			}
/*1545*/ 		}
/*1545*/ 		Documentator_DocInheritedConsts(Documentator_c);
/*1547*/ 		{
/*1547*/ 			int m2runtime_for_limit_1;
/*1547*/ 			Documentator_i = 0;
/*1547*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 318)) - 1);
/*1548*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1548*/ 				Documentator_DocClassProperty(Documentator_c, NULL, (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 7 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 319), Documentator_i, Documentator_0err_entry_get, 320));
/*1550*/ 			}
/*1550*/ 		}
/*1550*/ 		Documentator_DocInheritedProperties(Documentator_c);
/*1552*/ 		{
/*1552*/ 			int m2runtime_for_limit_1;
/*1552*/ 			Documentator_i = 0;
/*1552*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 321)) - 1);
/*1553*/ 			for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1553*/ 				Documentator_DocClassMethod(Documentator_c, NULL, (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(Documentator_c, 8 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 322), Documentator_i, Documentator_0err_entry_get, 323));
/*1555*/ 			}
/*1555*/ 		}
/*1555*/ 		Documentator_DocInheritedMethods(Documentator_c);
/*1559*/ 	}
/*1559*/ 	Documentator_VSpaceBeforeItem(FALSE);
/*1560*/ 	Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"</BLOCKQUOTE>\012<CODE>}</CODE>\012");
/*1561*/ 	Documentator_VSpaceAfterItem(TRUE);
/*1563*/ 	Documentator_curr_class = NULL;
/*1567*/ }


/*1569*/ void
/*1569*/ Documentator_Help(void)
/*1569*/ {
/*1569*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"PHPLint Documentator\012\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"Options:\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"  --doc                 generate documentation\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\114,\0,\0,\0)"  --doc-extension EXT   extension of the generated documents (def. \042.html\042)\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"  --doc-page-header H   header text of the generated HTML page\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"  --doc-page-footer F   footer text of the generated HTML page\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\104,\0,\0,\0)"  --doc-ref-remap A B   remap HTML anchors references from A* to B*\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"\012More help: www.icosaedro.it/phplint/\012\012", (STRING *) 1));
/*1584*/ }


/*1586*/ void
/*1586*/ Documentator_Init(void)
/*1586*/ {
/*1593*/ 	Documentator_extension = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)".html";
/*1594*/ 	Documentator_page_header = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"<HTML><BODY>\012";
/*1595*/ 	Documentator_page_footer = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"\012<HR><P align=right>", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"<FONT size='-2'>Generated by ", Documentator_Anchor((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"http://www.icosaedro.it/phplint/", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"PHPLint Documentator"), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"</FONT></P>\012", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"</BODY></HTML>\012", (STRING *) 1);
/*1603*/ }


/*1604*/ int
/*1604*/ Documentator_ParseParameter(int Documentator_i, ARRAY *Documentator_args)
/*1604*/ {
/*1606*/ 	STRING * Documentator_arg = NULL;
/*1606*/ 	Documentator_arg = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_args, Documentator_i, Documentator_0err_entry_get, 324);
/*1607*/ 	if( m2runtime_strcmp(Documentator_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"--doc-help") == 0 ){
/*1608*/ 		Documentator_Help();
/*1609*/ 	} else if( m2runtime_strcmp(Documentator_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"--doc") == 0 ){
/*1610*/ 		Documentator_generate = TRUE;
/*1611*/ 	} else if( m2runtime_strcmp(Documentator_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"--doc-extension") == 0 ){
/*1612*/ 		m2_inc(&Documentator_i, 1);
/*1613*/ 		if( (Documentator_i >= m2runtime_count(Documentator_args)) ){
/*1614*/ 			m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"phplint: missing argument for --doc-extension\012");
/*1615*/ 			m2runtime_exit(1);
/*1617*/ 		}
/*1617*/ 		Documentator_extension = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_args, Documentator_i, Documentator_0err_entry_get, 325);
/*1618*/ 	} else if( m2runtime_strcmp(Documentator_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"--doc-page-header") == 0 ){
/*1619*/ 		m2_inc(&Documentator_i, 1);
/*1620*/ 		if( (Documentator_i >= m2runtime_count(Documentator_args)) ){
/*1621*/ 			m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"phplint: missing argument for --doc-page-header\012");
/*1622*/ 			m2runtime_exit(1);
/*1624*/ 		}
/*1624*/ 		Documentator_page_header = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_args, Documentator_i, Documentator_0err_entry_get, 326);
/*1625*/ 	} else if( m2runtime_strcmp(Documentator_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"--doc-page-footer") == 0 ){
/*1626*/ 		m2_inc(&Documentator_i, 1);
/*1627*/ 		if( (Documentator_i >= m2runtime_count(Documentator_args)) ){
/*1628*/ 			m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"phplint: missing argument for --doc-page-footer\012");
/*1629*/ 			m2runtime_exit(1);
/*1631*/ 		}
/*1631*/ 		Documentator_page_footer = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_args, Documentator_i, Documentator_0err_entry_get, 327);
/*1632*/ 	} else if( m2runtime_strcmp(Documentator_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"--doc-ref-remap") == 0 ){
/*1633*/ 		if( ((Documentator_i + 2) >= m2runtime_count(Documentator_args)) ){
/*1634*/ 			m2_error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"phplint: more args required for --doc-ref-remap\012");
/*1635*/ 			m2runtime_exit(1);
/*1637*/ 		}
/*1637*/ 		*(STRING **)m2runtime_dereference_lhs_ARRAY_next(&Documentator_ref_remap, sizeof(void *), 1, Documentator_0err_entry_get, 328) = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_args, (Documentator_i + 1), Documentator_0err_entry_get, 329);
/*1638*/ 		*(STRING **)m2runtime_dereference_lhs_ARRAY_next(&Documentator_ref_remap, sizeof(void *), 1, Documentator_0err_entry_get, 330) = (STRING *)m2runtime_dereference_rhs_ARRAY(Documentator_args, (Documentator_i + 2), Documentator_0err_entry_get, 331);
/*1639*/ 		m2_inc(&Documentator_i, 2);
/*1641*/ 	} else {
/*1641*/ 		m2_error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"phplint: unknown option `", Documentator_arg, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"'\012", (STRING *) 1));
/*1642*/ 		m2runtime_exit(1);
/*1645*/ 	}
/*1645*/ 	return Documentator_i;
/*1649*/ }


/*1660*/ void
/*1660*/ Documentator_Generate(int Documentator__php_ver, STRING *Documentator__fn, STRING *Documentator__package_descr, ARRAY *Documentator__required_packages, ARRAY *Documentator__include_path, ARRAY *Documentator__consts, ARRAY *Documentator__vars, ARRAY *Documentator__funcs, ARRAY *Documentator__classes)
/*1660*/ {
/*1661*/ 	int Documentator_i = 0;
/*1662*/ 	RECORD * Documentator_c = NULL;
/*1663*/ 	RECORD * Documentator_v = NULL;
/*1664*/ 	RECORD * Documentator_f = NULL;
/*1666*/ 	RECORD * Documentator_cl = NULL;
/*1667*/ 	if( !Documentator_generate ){
/*1669*/ 		return ;
/*1671*/ 	}
/*1671*/ 	Documentator_php_ver = Documentator__php_ver;
/*1672*/ 	Documentator_fn = Documentator__fn;
/*1673*/ 	Documentator_package_descr = Documentator__package_descr;
/*1674*/ 	Documentator_required_packages = Documentator__required_packages;
/*1675*/ 	Documentator_sort(Documentator__include_path);
/*1676*/ 	Documentator_include_path = Documentator__include_path;
/*1677*/ 	Documentator_consts = Documentator__consts;
/*1678*/ 	Documentator_vars = Documentator__vars;
/*1679*/ 	Documentator_funcs = Documentator__funcs;
/*1680*/ 	Documentator_classes = Documentator__classes;
/*1682*/ 	Documentator_prev_item_big_vspace = FALSE;
/*1683*/ 	Documentator_private_items = NULL;
/*1685*/ 	Documentator_fn_remapped = Documentator_RefMap(m2runtime_concat_STRING(0, FileName_DropExtension(Documentator_fn), Documentator_extension, (STRING *) 1));
/*1687*/ 	m2runtime_ERROR_CODE = 0;
/*1687*/ 	io_Open(1, (void *)&Documentator_fd, m2runtime_concat_STRING(0, FileName_DropExtension(Documentator_fn), Documentator_extension, (STRING *) 1), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"cwt");
/*1688*/ 	switch( m2runtime_ERROR_CODE ){

/*1688*/ 	case 0:  break;
/*1688*/ 	default:
/*1688*/ 		m2runtime_HALT(Documentator_0err_entry_get, 332, m2runtime_ERROR_MESSAGE);
/*1689*/ 	}
/*1689*/ 	Documentator_p(Documentator_page_header);
/*1691*/ 	Documentator_DocDescr(TRUE, Documentator_package_descr);
/*1693*/ 	{
/*1693*/ 		int m2runtime_for_limit_1;
/*1693*/ 		Documentator_i = 0;
/*1693*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_consts) - 1);
/*1694*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1694*/ 			Documentator_c = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_consts, Documentator_i, Documentator_0err_entry_get, 333);
/*1695*/ 			if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 334) != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_c, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 335), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 336), Documentator_fn) == 0)) ){
/*1696*/ 				Documentator_DocConst(Documentator_c);
/*1699*/ 			}
/*1700*/ 		}
/*1700*/ 	}
/*1700*/ 	{
/*1700*/ 		int m2runtime_for_limit_1;
/*1700*/ 		Documentator_i = 0;
/*1700*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_vars) - 1);
/*1701*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1701*/ 			Documentator_v = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_vars, Documentator_i, Documentator_0err_entry_get, 337);
/*1702*/ 			if( ((Documentator_v != NULL) && ((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_v, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 338) != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_v, 1 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 339), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 340), Documentator_fn) == 0)) ){
/*1703*/ 				Documentator_DocVar(Documentator_v);
/*1706*/ 			}
/*1707*/ 		}
/*1707*/ 	}
/*1707*/ 	{
/*1707*/ 		int m2runtime_for_limit_1;
/*1707*/ 		Documentator_i = 0;
/*1707*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_funcs) - 1);
/*1708*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1708*/ 			Documentator_f = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_funcs, Documentator_i, Documentator_0err_entry_get, 341);
/*1709*/ 			if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_f, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 342) != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_f, 2 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 343), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 344), Documentator_fn) == 0)) ){
/*1710*/ 				Documentator_DocFunc(Documentator_f);
/*1713*/ 			}
/*1714*/ 		}
/*1714*/ 	}
/*1714*/ 	{
/*1714*/ 		int m2runtime_for_limit_1;
/*1714*/ 		Documentator_i = 0;
/*1714*/ 		m2runtime_for_limit_1 = (m2runtime_count(Documentator_classes) - 1);
/*1715*/ 		for( ; Documentator_i <= m2runtime_for_limit_1; Documentator_i += 1 ){
/*1715*/ 			Documentator_cl = (RECORD *)m2runtime_dereference_rhs_ARRAY(Documentator_classes, Documentator_i, Documentator_0err_entry_get, 345);
/*1716*/ 			if( (((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 12 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 346) != NULL) && (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_RECORD(Documentator_cl, 12 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 347), 0 * sizeof(void*) + 2 * sizeof(int), Documentator_0err_entry_get, 348), Documentator_fn) == 0)) ){
/*1717*/ 				Documentator_DocClass(Documentator_cl);
/*1720*/ 			}
/*1721*/ 		}
/*1721*/ 	}
/*1721*/ 	if( m2runtime_strcmp(Documentator_private_items, NULL) > 0 ){
/*1722*/ 		Documentator_VSpaceBeforeItem(TRUE);
/*1723*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"<h2>Private items</h2>\012<blockquote>\012");
/*1724*/ 		Documentator_p(Documentator_private_items);
/*1725*/ 		Documentator_p((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"\012</blockquote>\012");
/*1728*/ 	}
/*1728*/ 	Documentator_p(Documentator_page_footer);
/*1730*/ 	m2runtime_ERROR_CODE = 0;
/*1730*/ 	io_Close(1, (void *)&Documentator_fd);
/*1731*/ 	switch( m2runtime_ERROR_CODE ){

/*1731*/ 	case 0:  break;
/*1731*/ 	default:
/*1731*/ 		m2runtime_HALT(Documentator_0err_entry_get, 349, m2runtime_ERROR_MESSAGE);
/*1732*/ 	}
/*1734*/ }


/*1737*/ STRING *
/*1737*/ Documentator_ExtractDeprecated(STRING *Documentator_descr)
/*1737*/ {

/*1740*/ 	STRING *
/*1740*/ 	Documentator_trim_to_linear_string(STRING *Documentator_s)
/*1740*/ 	{
/*1740*/ 		int Documentator_len = 0;
/*1742*/ 		STRING * Documentator_s2 = NULL;
/*1742*/ 		Documentator_s = Documentator_trim(Documentator_s);
/*1743*/ 		Documentator_len = m2runtime_length(Documentator_s);
/*1744*/ 		if( (Documentator_len > 240) ){
/*1745*/ 			Documentator_s = m2runtime_concat_STRING(0, m2runtime_substr(Documentator_s, 0, (240 - 5), 1, Documentator_0err_entry_get, 350), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"[...]", (STRING *) 1);
/*1747*/ 		}
/*1747*/ 		Documentator_s = str_substitute(Documentator_s, m2runtime_CHR(9), m2runtime_CHR(32));
/*1748*/ 		Documentator_s = str_substitute(Documentator_s, m2runtime_CHR(13), m2runtime_CHR(32));
/*1749*/ 		Documentator_s = str_substitute(Documentator_s, m2runtime_CHR(10), m2runtime_CHR(32));
/*1751*/ 		do{
/*1751*/ 			Documentator_s2 = str_substitute(Documentator_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"  ", m2runtime_CHR(32));
/*1752*/ 			if( m2runtime_strcmp(Documentator_s2, Documentator_s) == 0 ){
/*1755*/ 				goto m2runtime_loop_1;
/*1755*/ 			}
/*1755*/ 			Documentator_s = Documentator_s2;
/*1757*/ 		}while(TRUE);
m2runtime_loop_1: ;
/*1757*/ 		return Documentator_s;
/*1762*/ 	}

/*1765*/ 	int Documentator_nest_level = 0;
/*1765*/ 	int Documentator_len = 0;
/*1765*/ 	int Documentator_j = 0;
/*1765*/ 	int Documentator_i = 0;
/*1767*/ 	STRING * Documentator_deprecated = NULL;
/*1770*/ 	do{
/*1770*/ 		Documentator_i = str_find(Documentator_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"<@deprecated");
/*1771*/ 		if( (Documentator_i < 0) ){
/*1772*/ 			return Documentator_trim_to_linear_string(Documentator_deprecated);
/*1778*/ 		}
/*1778*/ 		Documentator_i = (Documentator_i + m2runtime_length((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"<@deprecated"));
/*1779*/ 		Documentator_j = Documentator_i;
/*1780*/ 		Documentator_len = m2runtime_length(Documentator_descr);
/*1781*/ 		Documentator_nest_level = 1;
/*1783*/ 		do{
/*1783*/ 			if( (Documentator_j >= Documentator_len) ){
/*1784*/ 				Documentator_j = Documentator_len;
/*1787*/ 				goto m2runtime_loop_2;
/*1787*/ 			}
/*1787*/ 			if( m2runtime_strcmp(m2runtime_substr(Documentator_descr, Documentator_j, 0, 0, Documentator_0err_entry_get, 351), m2runtime_CHR(60)) == 0 ){
/*1788*/ 				m2_inc(&Documentator_nest_level, 1);
/*1789*/ 			} else if( m2runtime_strcmp(m2runtime_substr(Documentator_descr, Documentator_j, 0, 0, Documentator_0err_entry_get, 352), m2runtime_CHR(62)) == 0 ){
/*1790*/ 				m2_inc(&Documentator_nest_level, -1);
/*1791*/ 				if( (Documentator_nest_level <= 0) ){
/*1794*/ 					goto m2runtime_loop_2;
/*1795*/ 				}
/*1795*/ 			}
/*1795*/ 			m2_inc(&Documentator_j, 1);
/*1797*/ 		}while(TRUE);
m2runtime_loop_2: ;
/*1797*/ 		if( m2runtime_strcmp(Documentator_deprecated, EMPTY_STRING) > 0 ){
/*1798*/ 			Documentator_deprecated = m2runtime_concat_STRING(0, Documentator_deprecated, m2runtime_CHR(32), (STRING *) 1);
/*1800*/ 		}
/*1800*/ 		Documentator_deprecated = m2runtime_concat_STRING(0, Documentator_deprecated, m2runtime_substr(Documentator_descr, Documentator_i, Documentator_j, 1, Documentator_0err_entry_get, 353), (STRING *) 1);
/*1801*/ 		if( (Documentator_j >= Documentator_len) ){
/*1802*/ 			return Documentator_trim_to_linear_string(Documentator_deprecated);
/*1806*/ 		}
/*1806*/ 		Documentator_descr = m2runtime_substr(Documentator_descr, Documentator_j, Documentator_len, 1, Documentator_0err_entry_get, 354);
/*1809*/ 	}while(TRUE);
/*1809*/ 	m2runtime_missing_return(Documentator_0err_entry_get, 355);
/*1809*/ 	return NULL;
/*1812*/ }


char * Documentator_0func[] = {
    "p",
    "RefMap",
    "SearchConst",
    "SearchVar",
    "SearchFunc",
    "SearchClass",
    "SearchClassConst",
    "SearchClassVar",
    "SearchClassFunc",
    "report",
    "ItemToUrl",
    "AnchorToClass",
    "ResolveTags",
    "trim",
    "hex",
    "DocString",
    "DocValue",
    "sort",
    "DocDescr",
    "DocConst",
    "DocType",
    "DocVar",
    "DocSignature",
    "DocRaisedErrors",
    "DocThrownExceptions",
    "DocThrownExceptionsDescr",
    "DocFunc",
    "DocClassConst",
    "DocClassProperty",
    "IsClassInSet",
    "ListImplementedOrOverriddenMethods",
    "DocClassMethod",
    "NotInList",
    "DocInheritedConsts",
    "ScanProperties",
    "ScanPropertiesRecursive",
    "DocInheritedProperties",
    "ScanMethods",
    "ScanMethodsRecursive",
    "DocInheritedMethods",
    "recurse",
    "DocClassHierarchy",
    "DocClass",
    "ParseParameter",
    "Generate",
    "trim_to_linear_string",
    "ExtractDeprecated"
};

int Documentator_0err_entry[] = {
    0 /* p */, 82,
    1 /* RefMap */, 113,
    1 /* RefMap */, 113,
    1 /* RefMap */, 114,
    1 /* RefMap */, 114,
    2 /* SearchConst */, 148,
    2 /* SearchConst */, 148,
    2 /* SearchConst */, 150,
    3 /* SearchVar */, 160,
    3 /* SearchVar */, 160,
    3 /* SearchVar */, 160,
    3 /* SearchVar */, 162,
    4 /* SearchFunc */, 172,
    4 /* SearchFunc */, 172,
    4 /* SearchFunc */, 174,
    5 /* SearchClass */, 184,
    5 /* SearchClass */, 184,
    5 /* SearchClass */, 186,
    6 /* SearchClassConst */, 195,
    6 /* SearchClassConst */, 197,
    6 /* SearchClassConst */, 197,
    6 /* SearchClassConst */, 199,
    7 /* SearchClassVar */, 208,
    7 /* SearchClassVar */, 210,
    7 /* SearchClassVar */, 210,
    7 /* SearchClassVar */, 212,
    8 /* SearchClassFunc */, 221,
    8 /* SearchClassFunc */, 223,
    8 /* SearchClassFunc */, 223,
    8 /* SearchClassFunc */, 225,
    9 /* report */, 239,
    9 /* report */, 242,
    9 /* report */, 246,
    9 /* report */, 248,
    10 /* ItemToUrl */, 266,
    10 /* ItemToUrl */, 267,
    10 /* ItemToUrl */, 271,
    10 /* ItemToUrl */, 285,
    10 /* ItemToUrl */, 286,
    10 /* ItemToUrl */, 290,
    10 /* ItemToUrl */, 298,
    10 /* ItemToUrl */, 300,
    10 /* ItemToUrl */, 301,
    10 /* ItemToUrl */, 304,
    10 /* ItemToUrl */, 308,
    10 /* ItemToUrl */, 313,
    10 /* ItemToUrl */, 316,
    10 /* ItemToUrl */, 322,
    10 /* ItemToUrl */, 328,
    10 /* ItemToUrl */, 333,
    10 /* ItemToUrl */, 337,
    10 /* ItemToUrl */, 342,
    10 /* ItemToUrl */, 347,
    11 /* AnchorToClass */, 357,
    11 /* AnchorToClass */, 358,
    12 /* ResolveTags */, 419,
    12 /* ResolveTags */, 423,
    12 /* ResolveTags */, 429,
    12 /* ResolveTags */, 429,
    12 /* ResolveTags */, 430,
    12 /* ResolveTags */, 435,
    12 /* ResolveTags */, 443,
    12 /* ResolveTags */, 444,
    12 /* ResolveTags */, 445,
    12 /* ResolveTags */, 449,
    12 /* ResolveTags */, 456,
    12 /* ResolveTags */, 460,
    12 /* ResolveTags */, 471,
    13 /* trim */, 486,
    13 /* trim */, 491,
    13 /* trim */, 495,
    14 /* hex */, 541,
    15 /* DocString */, 554,
    16 /* DocValue */, 590,
    16 /* DocValue */, 597,
    17 /* sort */, 612,
    17 /* sort */, 612,
    17 /* sort */, 613,
    17 /* sort */, 613,
    17 /* sort */, 613,
    17 /* sort */, 613,
    18 /* DocDescr */, 665,
    18 /* DocDescr */, 666,
    18 /* DocDescr */, 713,
    18 /* DocDescr */, 713,
    18 /* DocDescr */, 713,
    18 /* DocDescr */, 719,
    18 /* DocDescr */, 720,
    18 /* DocDescr */, 732,
    18 /* DocDescr */, 732,
    18 /* DocDescr */, 732,
    18 /* DocDescr */, 738,
    18 /* DocDescr */, 742,
    18 /* DocDescr */, 760,
    19 /* DocConst */, 805,
    19 /* DocConst */, 806,
    19 /* DocConst */, 809,
    19 /* DocConst */, 810,
    19 /* DocConst */, 812,
    19 /* DocConst */, 814,
    19 /* DocConst */, 817,
    19 /* DocConst */, 817,
    19 /* DocConst */, 817,
    19 /* DocConst */, 817,
    19 /* DocConst */, 820,
    19 /* DocConst */, 821,
    20 /* DocType */, 838,
    20 /* DocType */, 848,
    20 /* DocType */, 853,
    20 /* DocType */, 854,
    20 /* DocType */, 855,
    20 /* DocType */, 861,
    20 /* DocType */, 864,
    20 /* DocType */, 865,
    20 /* DocType */, 867,
    20 /* DocType */, 867,
    20 /* DocType */, 869,
    20 /* DocType */, 870,
    21 /* DocVar */, 875,
    21 /* DocVar */, 876,
    21 /* DocVar */, 879,
    21 /* DocVar */, 880,
    21 /* DocVar */, 882,
    21 /* DocVar */, 884,
    21 /* DocVar */, 891,
    21 /* DocVar */, 892,
    22 /* DocSignature */, 903,
    22 /* DocSignature */, 905,
    22 /* DocSignature */, 911,
    22 /* DocSignature */, 914,
    22 /* DocSignature */, 919,
    22 /* DocSignature */, 923,
    22 /* DocSignature */, 925,
    22 /* DocSignature */, 929,
    22 /* DocSignature */, 930,
    22 /* DocSignature */, 932,
    22 /* DocSignature */, 932,
    22 /* DocSignature */, 935,
    23 /* DocRaisedErrors */, 960,
    24 /* DocThrownExceptions */, 982,
    24 /* DocThrownExceptions */, 985,
    25 /* DocThrownExceptionsDescr */, 1007,
    25 /* DocThrownExceptionsDescr */, 1010,
    25 /* DocThrownExceptionsDescr */, 1010,
    25 /* DocThrownExceptionsDescr */, 1013,
    25 /* DocThrownExceptionsDescr */, 1016,
    26 /* DocFunc */, 1026,
    26 /* DocFunc */, 1027,
    26 /* DocFunc */, 1030,
    26 /* DocFunc */, 1031,
    26 /* DocFunc */, 1033,
    26 /* DocFunc */, 1033,
    26 /* DocFunc */, 1035,
    26 /* DocFunc */, 1036,
    26 /* DocFunc */, 1037,
    26 /* DocFunc */, 1038,
    26 /* DocFunc */, 1039,
    26 /* DocFunc */, 1040,
    27 /* DocClassConst */, 1051,
    27 /* DocClassConst */, 1054,
    27 /* DocClassConst */, 1055,
    27 /* DocClassConst */, 1055,
    27 /* DocClassConst */, 1057,
    27 /* DocClassConst */, 1059,
    27 /* DocClassConst */, 1059,
    27 /* DocClassConst */, 1059,
    27 /* DocClassConst */, 1059,
    27 /* DocClassConst */, 1062,
    27 /* DocClassConst */, 1063,
    27 /* DocClassConst */, 1066,
    27 /* DocClassConst */, 1066,
    27 /* DocClassConst */, 1066,
    28 /* DocClassProperty */, 1075,
    28 /* DocClassProperty */, 1077,
    28 /* DocClassProperty */, 1077,
    28 /* DocClassProperty */, 1081,
    28 /* DocClassProperty */, 1082,
    28 /* DocClassProperty */, 1082,
    28 /* DocClassProperty */, 1084,
    28 /* DocClassProperty */, 1087,
    28 /* DocClassProperty */, 1096,
    28 /* DocClassProperty */, 1098,
    28 /* DocClassProperty */, 1100,
    28 /* DocClassProperty */, 1100,
    28 /* DocClassProperty */, 1102,
    28 /* DocClassProperty */, 1102,
    28 /* DocClassProperty */, 1106,
    28 /* DocClassProperty */, 1107,
    28 /* DocClassProperty */, 1110,
    28 /* DocClassProperty */, 1110,
    28 /* DocClassProperty */, 1110,
    29 /* IsClassInSet */, 1122,
    30 /* ListImplementedOrOverriddenMethods */, 1156,
    30 /* ListImplementedOrOverriddenMethods */, 1161,
    30 /* ListImplementedOrOverriddenMethods */, 1162,
    30 /* ListImplementedOrOverriddenMethods */, 1163,
    30 /* ListImplementedOrOverriddenMethods */, 1167,
    30 /* ListImplementedOrOverriddenMethods */, 1167,
    30 /* ListImplementedOrOverriddenMethods */, 1169,
    30 /* ListImplementedOrOverriddenMethods */, 1169,
    30 /* ListImplementedOrOverriddenMethods */, 1171,
    30 /* ListImplementedOrOverriddenMethods */, 1181,
    30 /* ListImplementedOrOverriddenMethods */, 1181,
    30 /* ListImplementedOrOverriddenMethods */, 1181,
    30 /* ListImplementedOrOverriddenMethods */, 1185,
    30 /* ListImplementedOrOverriddenMethods */, 1188,
    30 /* ListImplementedOrOverriddenMethods */, 1191,
    30 /* ListImplementedOrOverriddenMethods */, 1192,
    30 /* ListImplementedOrOverriddenMethods */, 1192,
    31 /* DocClassMethod */, 1207,
    31 /* DocClassMethod */, 1209,
    31 /* DocClassMethod */, 1209,
    31 /* DocClassMethod */, 1214,
    31 /* DocClassMethod */, 1215,
    31 /* DocClassMethod */, 1215,
    31 /* DocClassMethod */, 1217,
    31 /* DocClassMethod */, 1217,
    31 /* DocClassMethod */, 1218,
    31 /* DocClassMethod */, 1219,
    31 /* DocClassMethod */, 1220,
    31 /* DocClassMethod */, 1221,
    31 /* DocClassMethod */, 1221,
    31 /* DocClassMethod */, 1223,
    31 /* DocClassMethod */, 1224,
    31 /* DocClassMethod */, 1227,
    31 /* DocClassMethod */, 1228,
    31 /* DocClassMethod */, 1229,
    31 /* DocClassMethod */, 1230,
    31 /* DocClassMethod */, 1233,
    31 /* DocClassMethod */, 1233,
    31 /* DocClassMethod */, 1233,
    32 /* NotInList */, 1244,
    32 /* NotInList */, 1248,
    33 /* DocInheritedConsts */, 1260,
    33 /* DocInheritedConsts */, 1263,
    33 /* DocInheritedConsts */, 1265,
    33 /* DocInheritedConsts */, 1265,
    33 /* DocInheritedConsts */, 1265,
    33 /* DocInheritedConsts */, 1267,
    33 /* DocInheritedConsts */, 1269,
    33 /* DocInheritedConsts */, 1271,
    33 /* DocInheritedConsts */, 1271,
    33 /* DocInheritedConsts */, 1272,
    33 /* DocInheritedConsts */, 1272,
    33 /* DocInheritedConsts */, 1273,
    33 /* DocInheritedConsts */, 1276,
    34 /* ScanProperties */, 1295,
    34 /* ScanProperties */, 1297,
    34 /* ScanProperties */, 1297,
    34 /* ScanProperties */, 1298,
    34 /* ScanProperties */, 1298,
    34 /* ScanProperties */, 1299,
    35 /* ScanPropertiesRecursive */, 1311,
    35 /* ScanPropertiesRecursive */, 1312,
    35 /* ScanPropertiesRecursive */, 1313,
    35 /* ScanPropertiesRecursive */, 1313,
    36 /* DocInheritedProperties */, 1318,
    36 /* DocInheritedProperties */, 1318,
    36 /* DocInheritedProperties */, 1323,
    36 /* DocInheritedProperties */, 1325,
    36 /* DocInheritedProperties */, 1325,
    36 /* DocInheritedProperties */, 1325,
    36 /* DocInheritedProperties */, 1329,
    36 /* DocInheritedProperties */, 1332,
    36 /* DocInheritedProperties */, 1332,
    36 /* DocInheritedProperties */, 1335,
    36 /* DocInheritedProperties */, 1336,
    36 /* DocInheritedProperties */, 1336,
    37 /* ScanMethods */, 1356,
    37 /* ScanMethods */, 1359,
    37 /* ScanMethods */, 1359,
    37 /* ScanMethods */, 1359,
    38 /* ScanMethodsRecursive */, 1372,
    38 /* ScanMethodsRecursive */, 1373,
    38 /* ScanMethodsRecursive */, 1374,
    38 /* ScanMethodsRecursive */, 1374,
    39 /* DocInheritedMethods */, 1379,
    39 /* DocInheritedMethods */, 1379,
    39 /* DocInheritedMethods */, 1384,
    39 /* DocInheritedMethods */, 1386,
    39 /* DocInheritedMethods */, 1386,
    39 /* DocInheritedMethods */, 1386,
    39 /* DocInheritedMethods */, 1390,
    39 /* DocInheritedMethods */, 1393,
    39 /* DocInheritedMethods */, 1393,
    39 /* DocInheritedMethods */, 1396,
    39 /* DocInheritedMethods */, 1397,
    39 /* DocInheritedMethods */, 1397,
    40 /* recurse */, 1411,
    40 /* recurse */, 1414,
    40 /* recurse */, 1418,
    40 /* recurse */, 1424,
    40 /* recurse */, 1425,
    40 /* recurse */, 1432,
    40 /* recurse */, 1435,
    40 /* recurse */, 1436,
    40 /* recurse */, 1443,
    40 /* recurse */, 1443,
    41 /* DocClassHierarchy */, 1448,
    41 /* DocClassHierarchy */, 1448,
    42 /* DocClass */, 1460,
    42 /* DocClass */, 1461,
    42 /* DocClass */, 1466,
    42 /* DocClass */, 1468,
    42 /* DocClass */, 1471,
    42 /* DocClass */, 1474,
    42 /* DocClass */, 1477,
    42 /* DocClass */, 1483,
    42 /* DocClass */, 1514,
    42 /* DocClass */, 1515,
    42 /* DocClass */, 1528,
    42 /* DocClass */, 1529,
    42 /* DocClass */, 1530,
    42 /* DocClass */, 1531,
    42 /* DocClass */, 1532,
    42 /* DocClass */, 1542,
    42 /* DocClass */, 1543,
    42 /* DocClass */, 1543,
    42 /* DocClass */, 1547,
    42 /* DocClass */, 1548,
    42 /* DocClass */, 1548,
    42 /* DocClass */, 1552,
    42 /* DocClass */, 1553,
    42 /* DocClass */, 1553,
    43 /* ParseParameter */, 1607,
    43 /* ParseParameter */, 1618,
    43 /* ParseParameter */, 1625,
    43 /* ParseParameter */, 1632,
    43 /* ParseParameter */, 1637,
    43 /* ParseParameter */, 1638,
    43 /* ParseParameter */, 1638,
    43 /* ParseParameter */, 1639,
    44 /* Generate */, 1687,
    44 /* Generate */, 1695,
    44 /* Generate */, 1695,
    44 /* Generate */, 1695,
    44 /* Generate */, 1695,
    44 /* Generate */, 1702,
    44 /* Generate */, 1702,
    44 /* Generate */, 1702,
    44 /* Generate */, 1702,
    44 /* Generate */, 1709,
    44 /* Generate */, 1709,
    44 /* Generate */, 1709,
    44 /* Generate */, 1709,
    44 /* Generate */, 1716,
    44 /* Generate */, 1716,
    44 /* Generate */, 1716,
    44 /* Generate */, 1716,
    44 /* Generate */, 1730,
    45 /* trim_to_linear_string */, 1745,
    46 /* ExtractDeprecated */, 1787,
    46 /* ExtractDeprecated */, 1789,
    46 /* ExtractDeprecated */, 1800,
    46 /* ExtractDeprecated */, 1806,
    46 /* ExtractDeprecated */, 1808
};

void Documentator_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Documentator";
    *f = Documentator_0func[ Documentator_0err_entry[2*i] ];
    *l = Documentator_0err_entry[2*i + 1];
}
