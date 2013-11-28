/* IMPLEMENTATION MODULE Scanner */
#define M2_IMPORT_Scanner

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif
/*239*/ STRING * Scanner_cwd = NULL;
/*243*/ int Scanner_print_file_name = 0;
/*252*/ int Scanner_print_path_fmt = 0;
/*255*/ int Scanner_ctrl_check = 0;
/*258*/ int Scanner_ascii_ext_check = 0;
/*261*/ int Scanner_tab_size = 0;
/*262*/ int Scanner_print_notices = 0;
/*263*/ int Scanner_print_warnings = 0;
/*264*/ int Scanner_print_errors = 0;
/*265*/ int Scanner_print_context = 0;
/*266*/ int Scanner_print_source = 0;
/*270*/ int Scanner_print_line_numbers = 0;
/*273*/ STRING * Scanner_fn = NULL;
/*276*/ int Scanner_sym = 0;
/*280*/ STRING * Scanner_s = NULL;
/*289*/ int Scanner_warning_counter = 0;
/*289*/ int Scanner_error_counter = 0;

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_io
#    include "io.c"
#endif

#ifndef M2_IMPORT_buffer
#    include "buffer.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

#ifndef M2_IMPORT_FileName
#    include "FileName.c"
#endif

#ifndef M2_IMPORT_Tokens
#    include "Tokens.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

void Scanner_0err_entry_get(int i, char **m, char **f, int *l);
/* 83*/ void * Scanner_fd = NULL;
/* 85*/ int Scanner_code = 0;
/* 88*/ STRING * Scanner_line = NULL;
/* 91*/ int Scanner_line_n = 0;
/* 94*/ int Scanner_line_idx = 0;
/* 97*/ int Scanner_line_pos = 0;
/*106*/ STRING * Scanner_c = NULL;

/*108*/ STRING *
/*108*/ Scanner_mn(RECORD *Scanner_c, RECORD *Scanner_m)
/*108*/ {
/*108*/ 	return m2runtime_concat_STRING(0, m2runtime_CHR(96), (STRING *)m2runtime_dereference_rhs_RECORD(Scanner_c, 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 0), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::", (STRING *)m2runtime_dereference_rhs_RECORD(Scanner_m, 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 1), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"()'", (STRING *) 1);
/*112*/ }


/*113*/ STRING *
/*113*/ Scanner_fmt_fn(STRING *Scanner_abs_path)
/*113*/ {
/*115*/ 	STRING * Scanner_r = NULL;
/*115*/ 	switch(Scanner_print_path_fmt){

/*117*/ 	case 0:
/*118*/ 	return Scanner_abs_path;
/*120*/ 	break;

/*120*/ 	case 1:
/*121*/ 	return FileName_Relative(m2runtime_concat_STRING(0, Scanner_cwd, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"/*", (STRING *) 1), Scanner_abs_path);
/*123*/ 	break;

/*123*/ 	case 2:
/*124*/ 	Scanner_r = FileName_Relative(m2runtime_concat_STRING(0, Scanner_cwd, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"/*", (STRING *) 1), Scanner_abs_path);
/*125*/ 	if( (m2runtime_length(Scanner_r) < m2runtime_length(Scanner_abs_path)) ){
/*126*/ 		return Scanner_r;
/*128*/ 	} else {
/*128*/ 		return Scanner_abs_path;
/*131*/ 	}
/*131*/ 	break;

/*131*/ 	default: m2runtime_missing_case_in_switch(Scanner_0err_entry_get, 2);
/*132*/ 	}
/*132*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 3);
/*132*/ 	return NULL;
/*134*/ }


/*136*/ RECORD *
/*136*/ Scanner_here(void)
/*136*/ {
/*136*/ 	return (
/*136*/ 		push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*136*/ 		push((char*) Scanner_fn),
/*136*/ 		*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*136*/ 		*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = Scanner_line_n,
/*138*/ 		(RECORD*) pop()
/*138*/ 	);
/*140*/ }


/*142*/ STRING *
/*142*/ Scanner_reference(RECORD *Scanner_w)
/*142*/ {
/*142*/ 	if( Scanner_w == NULL ){
/*143*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"?:?";
/*144*/ 	} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Scanner_w, 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 4), Scanner_fn) == 0 ){
/*145*/ 		return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"line ", m2runtime_itos( *(int *)m2runtime_dereference_rhs_RECORD(Scanner_w, 1 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 5)), (STRING *) 1);
/*147*/ 	} else {
/*147*/ 		return m2runtime_concat_STRING(0, Scanner_fmt_fn((STRING *)m2runtime_dereference_rhs_RECORD(Scanner_w, 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 6)), m2runtime_CHR(58), m2runtime_itos( *(int *)m2runtime_dereference_rhs_RECORD(Scanner_w, 1 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 7)), (STRING *) 1);
/*150*/ 	}
/*150*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 8);
/*150*/ 	return NULL;
/*152*/ }


/*154*/ void
/*154*/ Scanner_PrintWhere(RECORD *Scanner_w)
/*154*/ {
/*154*/ 	if( (Scanner_print_context || Scanner_print_source) ){
/*156*/ 		m2_print((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"==== ");
/*159*/ 	}
/*159*/ 	if( Scanner_w == NULL ){
/*160*/ 		m2_print((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"?: ");
/*162*/ 	} else {
/*162*/ 		if( (Scanner_print_file_name || !Scanner_print_source || (m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(Scanner_w, 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 9), Scanner_fn) != 0)) ){
/*165*/ 			m2_print(m2runtime_concat_STRING(0, Scanner_fmt_fn((STRING *)m2runtime_dereference_rhs_RECORD(Scanner_w, 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 10)), m2runtime_CHR(58), (STRING *) 1));
/*167*/ 		}
/*167*/ 		m2_print(m2runtime_concat_STRING(0, m2runtime_itos( *(int *)m2runtime_dereference_rhs_RECORD(Scanner_w, 1 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 11)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", (STRING *) 1));
/*170*/ 	}
/*172*/ }


/*174*/ void
/*174*/ Scanner_PrintCurrPos(void)
/*174*/ {
/*175*/ 	if( Scanner_print_context ){
/*176*/ 		m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\012\011", Scanner_line, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\012\011", str_repeat(m2runtime_CHR(32), (Scanner_line_pos - 1)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"\134_ HERE\012", (STRING *) 1));
/*179*/ 	}
/*179*/ 	Scanner_PrintWhere(Scanner_here());
/*183*/ }


/*185*/ void
/*185*/ Scanner_Fatal(STRING *Scanner_s)
/*185*/ {
/*185*/ 	Scanner_PrintCurrPos();
/*186*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"FATAL ERROR: ", Scanner_s, m2runtime_CHR(10), (STRING *) 1));
/*187*/ 	m2runtime_exit(1);
/*191*/ }


/*193*/ void
/*193*/ Scanner_UnexpectedSymbol(void)
/*193*/ {
/*193*/ 	Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"unexpected symbol ", Tokens_CodeToName(Scanner_sym), (STRING *) 1));
/*194*/ 	m2runtime_exit(1);
/*198*/ }


/*200*/ void
/*200*/ Scanner_Error(STRING *Scanner_s)
/*200*/ {
/*200*/ 	m2_inc(&Scanner_error_counter, 1);
/*201*/ 	if( !Scanner_print_errors ){
/*203*/ 		return ;
/*204*/ 	}
/*204*/ 	Scanner_PrintCurrPos();
/*205*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"ERROR: ", Scanner_s, m2runtime_CHR(10), (STRING *) 1));
/*209*/ }


/*211*/ void
/*211*/ Scanner_Error2(RECORD *Scanner_w, STRING *Scanner_s)
/*211*/ {
/*211*/ 	m2_inc(&Scanner_error_counter, 1);
/*212*/ 	if( !Scanner_print_errors ){
/*214*/ 		return ;
/*215*/ 	}
/*215*/ 	Scanner_PrintWhere(Scanner_w);
/*216*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"ERROR: ", Scanner_s, m2runtime_CHR(10), (STRING *) 1));
/*220*/ }


/*222*/ void
/*222*/ Scanner_Warning(STRING *Scanner_s)
/*222*/ {
/*222*/ 	m2_inc(&Scanner_warning_counter, 1);
/*223*/ 	if( !Scanner_print_warnings ){
/*225*/ 		return ;
/*226*/ 	}
/*226*/ 	Scanner_PrintCurrPos();
/*227*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"Warning: ", Scanner_s, m2runtime_CHR(10), (STRING *) 1));
/*231*/ }


/*233*/ void
/*233*/ Scanner_Warning2(RECORD *Scanner_w, STRING *Scanner_s)
/*233*/ {
/*233*/ 	m2_inc(&Scanner_warning_counter, 1);
/*234*/ 	if( !Scanner_print_warnings ){
/*236*/ 		return ;
/*237*/ 	}
/*237*/ 	Scanner_PrintWhere(Scanner_w);
/*238*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"Warning: ", Scanner_s, m2runtime_CHR(10), (STRING *) 1));
/*242*/ }


/*244*/ void
/*244*/ Scanner_Notice(STRING *Scanner_s)
/*244*/ {
/*244*/ 	if( !Scanner_print_notices ){
/*246*/ 		return ;
/*247*/ 	}
/*247*/ 	Scanner_PrintCurrPos();
/*248*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"notice: ", Scanner_s, m2runtime_CHR(10), (STRING *) 1));
/*252*/ }


/*254*/ void
/*254*/ Scanner_Notice2(RECORD *Scanner_w, STRING *Scanner_s)
/*254*/ {
/*254*/ 	if( !Scanner_print_notices ){
/*256*/ 		return ;
/*257*/ 	}
/*257*/ 	Scanner_PrintWhere(Scanner_w);
/*258*/ 	m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"notice: ", Scanner_s, m2runtime_CHR(10), (STRING *) 1));
/*262*/ }


/*264*/ STRING *
/*264*/ Scanner_SymToName(int Scanner_code)
/*264*/ {
/*264*/ 	return Tokens_CodeToName(Scanner_code);
/*268*/ }


/*270*/ void
/*270*/ Scanner_Expect(int Scanner_es, STRING *Scanner_err)
/*270*/ {
/*270*/ 	if( (Scanner_sym == Scanner_es) ){
/*272*/ 		return ;
/*273*/ 	}
/*273*/ 	Scanner_Fatal(m2runtime_concat_STRING(0, Scanner_err, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)", found symbol ", Scanner_SymToName(Scanner_sym), (STRING *) 1));
/*276*/ }


/*278*/ void
/*278*/ Scanner_PrintLineSource(void)
/*278*/ {
/*278*/ 	if( Scanner_print_line_numbers ){
/*279*/ 		m2_print(m2runtime_itos(Scanner_line_n));
/*281*/ 	}
/*281*/ 	m2_print((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)":\011");
/*282*/ 	m2_print(Scanner_line);
/*283*/ 	m2_print(m2runtime_CHR(10));
/*287*/ }


/*289*/ void
/*289*/ Scanner_ReadCh(void)
/*289*/ {
/*290*/ 	if( Scanner_c == NULL ){
/*291*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(9)) == 0 ){
/*292*/ 		m2_inc(&Scanner_line_pos, Scanner_tab_size);
/*293*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) == 0 ){
/*294*/ 		m2_inc(&Scanner_line_n, 1);
/*295*/ 		Scanner_line_pos = 1;
/*297*/ 	} else {
/*297*/ 		m2_inc(&Scanner_line_pos, 1);
/*301*/ 	}
/*301*/ 	if( Scanner_line == NULL ){
/*302*/ 		Scanner_c = NULL;
/*303*/ 	} else if( (Scanner_line_idx < m2runtime_length(Scanner_line)) ){
/*304*/ 		Scanner_c = m2runtime_substr(Scanner_line, Scanner_line_idx, 0, 0, Scanner_0err_entry_get, 12);
/*305*/ 		m2_inc(&Scanner_line_idx, 1);
/*306*/ 	} else if( (Scanner_line_idx == m2runtime_length(Scanner_line)) ){
/*307*/ 		Scanner_c = m2runtime_CHR(10);
/*308*/ 		m2_inc(&Scanner_line_idx, 1);
/*310*/ 	} else {
/*310*/ 		m2runtime_ERROR_CODE = 0;
/*310*/ 		Scanner_line = io_ReadLine(1, Scanner_fd);
/*311*/ 		switch( m2runtime_ERROR_CODE ){

/*311*/ 		case 0:  break;
/*311*/ 		default:
/*311*/ 			m2runtime_HALT(Scanner_0err_entry_get, 13, m2runtime_ERROR_MESSAGE);
/*311*/ 		}
/*311*/ 		if( Scanner_line == NULL ){
/*312*/ 			Scanner_c = NULL;
/*313*/ 		} else if( (m2runtime_length(Scanner_line) == 0) ){
/*314*/ 			Scanner_c = m2runtime_CHR(10);
/*316*/ 		} else {
/*316*/ 			Scanner_c = m2runtime_substr(Scanner_line, 0, 0, 0, Scanner_0err_entry_get, 14);
/*318*/ 		}
/*318*/ 		Scanner_line_idx = 1;
/*319*/ 		if( (Scanner_print_source && (Scanner_line != NULL)) ){
/*320*/ 			Scanner_PrintLineSource();
/*323*/ 		}
/*324*/ 	}
/*324*/ 	if( Globals_DEBUG ){
/*325*/ 		m2_print(Scanner_c);
/*328*/ 	}
/*330*/ }


/*332*/ int
/*332*/ Scanner_FollowingCharsMatch(STRING *Scanner_s)
/*332*/ {
/*332*/ 	if( ((m2runtime_length(Scanner_line) - Scanner_line_idx) < m2runtime_length(Scanner_s)) ){
/*333*/ 		return FALSE;
/*335*/ 	}
/*335*/ 	return m2runtime_strcmp(m2runtime_substr(Scanner_line, Scanner_line_idx, (Scanner_line_idx + m2runtime_length(Scanner_s)), 1, Scanner_0err_entry_get, 15), Scanner_s) == 0;
/*340*/ }

/*345*/ void * Scanner_b = NULL;
/*351*/ ARRAY * Scanner_php_keywords = NULL;
/*355*/ ARRAY * Scanner_phplint_keywords = NULL;

/*360*/ int
/*360*/ Scanner_SearchKeyword(STRING *Scanner_word, ARRAY *Scanner_list)
/*360*/ {
/*360*/ 	int Scanner_r = 0;
/*360*/ 	int Scanner_i = 0;
/*360*/ 	int Scanner_b = 0;
/*360*/ 	int Scanner_a = 0;
/*362*/ 	int Scanner_k = 0;
/*362*/ 	Scanner_a = 0;
/*363*/ 	Scanner_b = (m2runtime_count(Scanner_list) - 1);
/*365*/ 	do{
/*365*/ 		Scanner_i = (((Scanner_a + Scanner_b)) / 2);
/*366*/ 		Scanner_r = m2runtime_strcmp(Scanner_word, (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Scanner_list, Scanner_i, Scanner_0err_entry_get, 16), 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 17));
/*367*/ 		if( (Scanner_r < 0) ){
/*368*/ 			Scanner_b = (Scanner_i - 1);
/*369*/ 		} else if( (Scanner_r > 0) ){
/*370*/ 			Scanner_a = (Scanner_i + 1);
/*372*/ 		} else {
/*372*/ 			Scanner_k =  *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(Scanner_list, Scanner_i, Scanner_0err_entry_get, 18), 1 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 19);
/*373*/ 			if( (Scanner_k == 2) ){
/*374*/ 				Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"unimplemented keyword `", Scanner_word, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"'. I'm sorry...", (STRING *) 1));
/*376*/ 			}
/*376*/ 			return Scanner_k;
/*378*/ 		}
/*378*/ 		if( (Scanner_a > Scanner_b) ){
/*379*/ 			return 1;
/*382*/ 		}
/*383*/ 	}while(TRUE);
/*383*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 20);
/*383*/ 	return 0;
/*385*/ }


/*387*/ int
/*387*/ Scanner_SearchPhpKeyword(STRING *Scanner_k)
/*387*/ {
/*387*/ 	return Scanner_SearchKeyword(Scanner_k, Scanner_php_keywords);
/*391*/ }


/*393*/ void
/*393*/ Scanner_InitScanner(void)
/*393*/ {
/*393*/ 	if( Scanner_php_keywords != NULL ){
/*395*/ 		return ;
/*396*/ 	}
/*396*/ 	Scanner_php_keywords = (
/*397*/ 		push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*397*/ 		push((char*) (
/*397*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*397*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"FALSE"),
/*397*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*397*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 65,
/*398*/ 			(RECORD*) pop()
/*398*/ 		)),
/*398*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/*398*/ 		push((char*) (
/*398*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*398*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"NULL"),
/*398*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*398*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 63,
/*399*/ 			(RECORD*) pop()
/*399*/ 		)),
/*399*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),1) = (RECORD*) tos(), pop(),
/*399*/ 		push((char*) (
/*399*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*399*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"TRUE"),
/*399*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*399*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 66,
/*400*/ 			(RECORD*) pop()
/*400*/ 		)),
/*400*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),2) = (RECORD*) tos(), pop(),
/*400*/ 		push((char*) (
/*400*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*400*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"abstract"),
/*400*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*400*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 91,
/*401*/ 			(RECORD*) pop()
/*401*/ 		)),
/*401*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),3) = (RECORD*) tos(), pop(),
/*401*/ 		push((char*) (
/*401*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*401*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"and"),
/*401*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*401*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 58,
/*402*/ 			(RECORD*) pop()
/*402*/ 		)),
/*402*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),4) = (RECORD*) tos(), pop(),
/*402*/ 		push((char*) (
/*402*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*402*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"array"),
/*402*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*402*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 70,
/*403*/ 			(RECORD*) pop()
/*403*/ 		)),
/*403*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),5) = (RECORD*) tos(), pop(),
/*403*/ 		push((char*) (
/*403*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*403*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"as"),
/*403*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*403*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 23,
/*404*/ 			(RECORD*) pop()
/*404*/ 		)),
/*404*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),6) = (RECORD*) tos(), pop(),
/*404*/ 		push((char*) (
/*404*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*404*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"bool"),
/*404*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*404*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 64,
/*405*/ 			(RECORD*) pop()
/*405*/ 		)),
/*405*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),7) = (RECORD*) tos(), pop(),
/*405*/ 		push((char*) (
/*405*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*405*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"boolean"),
/*405*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*405*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 64,
/*406*/ 			(RECORD*) pop()
/*406*/ 		)),
/*406*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),8) = (RECORD*) tos(), pop(),
/*406*/ 		push((char*) (
/*406*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*406*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"break"),
/*406*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*406*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 111,
/*407*/ 			(RECORD*) pop()
/*407*/ 		)),
/*407*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),9) = (RECORD*) tos(), pop(),
/*407*/ 		push((char*) (
/*407*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*407*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"case"),
/*407*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*407*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 110,
/*408*/ 			(RECORD*) pop()
/*408*/ 		)),
/*408*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),10) = (RECORD*) tos(), pop(),
/*408*/ 		push((char*) (
/*408*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*408*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"catch"),
/*408*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*408*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 119,
/*409*/ 			(RECORD*) pop()
/*409*/ 		)),
/*409*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),11) = (RECORD*) tos(), pop(),
/*409*/ 		push((char*) (
/*409*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*409*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"class"),
/*409*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*409*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 93,
/*410*/ 			(RECORD*) pop()
/*410*/ 		)),
/*410*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),12) = (RECORD*) tos(), pop(),
/*410*/ 		push((char*) (
/*410*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*410*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"clone"),
/*410*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*410*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 106,
/*411*/ 			(RECORD*) pop()
/*411*/ 		)),
/*411*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),13) = (RECORD*) tos(), pop(),
/*411*/ 		push((char*) (
/*411*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*411*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"const"),
/*411*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*411*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 96,
/*412*/ 			(RECORD*) pop()
/*412*/ 		)),
/*412*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),14) = (RECORD*) tos(), pop(),
/*412*/ 		push((char*) (
/*412*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*412*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"continue"),
/*412*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*412*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 121,
/*413*/ 			(RECORD*) pop()
/*413*/ 		)),
/*413*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),15) = (RECORD*) tos(), pop(),
/*413*/ 		push((char*) (
/*413*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*413*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"declare"),
/*413*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*413*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 9,
/*414*/ 			(RECORD*) pop()
/*414*/ 		)),
/*414*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),16) = (RECORD*) tos(), pop(),
/*414*/ 		push((char*) (
/*414*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*414*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"default"),
/*414*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*414*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 112,
/*415*/ 			(RECORD*) pop()
/*415*/ 		)),
/*415*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),17) = (RECORD*) tos(), pop(),
/*415*/ 		push((char*) (
/*415*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*415*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"define"),
/*415*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*415*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 7,
/*416*/ 			(RECORD*) pop()
/*416*/ 		)),
/*416*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),18) = (RECORD*) tos(), pop(),
/*416*/ 		push((char*) (
/*416*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*416*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"die"),
/*416*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*416*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 113,
/*417*/ 			(RECORD*) pop()
/*417*/ 		)),
/*417*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),19) = (RECORD*) tos(), pop(),
/*417*/ 		push((char*) (
/*417*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*417*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"do"),
/*417*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*417*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 117,
/*418*/ 			(RECORD*) pop()
/*418*/ 		)),
/*418*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),20) = (RECORD*) tos(), pop(),
/*418*/ 		push((char*) (
/*418*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*418*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"double"),
/*418*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*418*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 68,
/*419*/ 			(RECORD*) pop()
/*419*/ 		)),
/*419*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),21) = (RECORD*) tos(), pop(),
/*419*/ 		push((char*) (
/*419*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*419*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"echo"),
/*419*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*419*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 114,
/*420*/ 			(RECORD*) pop()
/*420*/ 		)),
/*420*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),22) = (RECORD*) tos(), pop(),
/*420*/ 		push((char*) (
/*420*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*420*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"else"),
/*420*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*420*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 26,
/*421*/ 			(RECORD*) pop()
/*421*/ 		)),
/*421*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),23) = (RECORD*) tos(), pop(),
/*421*/ 		push((char*) (
/*421*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*421*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"elseif"),
/*421*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*421*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 27,
/*422*/ 			(RECORD*) pop()
/*422*/ 		)),
/*422*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),24) = (RECORD*) tos(), pop(),
/*422*/ 		push((char*) (
/*422*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*422*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"enddeclare"),
/*422*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*422*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 2,
/*423*/ 			(RECORD*) pop()
/*423*/ 		)),
/*423*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),25) = (RECORD*) tos(), pop(),
/*423*/ 		push((char*) (
/*423*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*423*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"endfor"),
/*423*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*423*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 2,
/*424*/ 			(RECORD*) pop()
/*424*/ 		)),
/*424*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),26) = (RECORD*) tos(), pop(),
/*424*/ 		push((char*) (
/*424*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*424*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"endforeach"),
/*424*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*424*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 2,
/*425*/ 			(RECORD*) pop()
/*425*/ 		)),
/*425*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),27) = (RECORD*) tos(), pop(),
/*425*/ 		push((char*) (
/*425*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*425*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"endif"),
/*425*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*425*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 2,
/*426*/ 			(RECORD*) pop()
/*426*/ 		)),
/*426*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),28) = (RECORD*) tos(), pop(),
/*426*/ 		push((char*) (
/*426*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*426*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"endswitch"),
/*426*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*426*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 2,
/*427*/ 			(RECORD*) pop()
/*427*/ 		)),
/*427*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),29) = (RECORD*) tos(), pop(),
/*427*/ 		push((char*) (
/*427*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*427*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"endwhile"),
/*427*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*427*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 2,
/*428*/ 			(RECORD*) pop()
/*428*/ 		)),
/*428*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),30) = (RECORD*) tos(), pop(),
/*428*/ 		push((char*) (
/*428*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*428*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"exit"),
/*428*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*428*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 113,
/*429*/ 			(RECORD*) pop()
/*429*/ 		)),
/*429*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),31) = (RECORD*) tos(), pop(),
/*429*/ 		push((char*) (
/*429*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*429*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"extends"),
/*429*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*429*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 94,
/*430*/ 			(RECORD*) pop()
/*430*/ 		)),
/*430*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),32) = (RECORD*) tos(), pop(),
/*430*/ 		push((char*) (
/*430*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*430*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"false"),
/*430*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*430*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 65,
/*431*/ 			(RECORD*) pop()
/*431*/ 		)),
/*431*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),33) = (RECORD*) tos(), pop(),
/*431*/ 		push((char*) (
/*431*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*431*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"final"),
/*431*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*431*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 102,
/*432*/ 			(RECORD*) pop()
/*432*/ 		)),
/*432*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),34) = (RECORD*) tos(), pop(),
/*432*/ 		push((char*) (
/*432*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*432*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"float"),
/*432*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*432*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 68,
/*433*/ 			(RECORD*) pop()
/*433*/ 		)),
/*433*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),35) = (RECORD*) tos(), pop(),
/*433*/ 		push((char*) (
/*433*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*433*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"for"),
/*433*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*433*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 21,
/*434*/ 			(RECORD*) pop()
/*434*/ 		)),
/*434*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),36) = (RECORD*) tos(), pop(),
/*434*/ 		push((char*) (
/*434*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*434*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"foreach"),
/*434*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*434*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 22,
/*435*/ 			(RECORD*) pop()
/*435*/ 		)),
/*435*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),37) = (RECORD*) tos(), pop(),
/*435*/ 		push((char*) (
/*435*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*435*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"function"),
/*435*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*435*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 8,
/*436*/ 			(RECORD*) pop()
/*436*/ 		)),
/*436*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),38) = (RECORD*) tos(), pop(),
/*436*/ 		push((char*) (
/*436*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*436*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"global"),
/*436*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*436*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 62,
/*437*/ 			(RECORD*) pop()
/*437*/ 		)),
/*437*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),39) = (RECORD*) tos(), pop(),
/*437*/ 		push((char*) (
/*437*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*437*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"goto"),
/*437*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*437*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 129,
/*438*/ 			(RECORD*) pop()
/*438*/ 		)),
/*438*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),40) = (RECORD*) tos(), pop(),
/*438*/ 		push((char*) (
/*438*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*438*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"if"),
/*438*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*438*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 25,
/*439*/ 			(RECORD*) pop()
/*439*/ 		)),
/*439*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),41) = (RECORD*) tos(), pop(),
/*439*/ 		push((char*) (
/*439*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*439*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"implements"),
/*439*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*439*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 95,
/*440*/ 			(RECORD*) pop()
/*440*/ 		)),
/*440*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),42) = (RECORD*) tos(), pop(),
/*440*/ 		push((char*) (
/*440*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*440*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"include"),
/*440*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*440*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 123,
/*441*/ 			(RECORD*) pop()
/*441*/ 		)),
/*441*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),43) = (RECORD*) tos(), pop(),
/*441*/ 		push((char*) (
/*441*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*441*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"include_once"),
/*441*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*441*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 124,
/*442*/ 			(RECORD*) pop()
/*442*/ 		)),
/*442*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),44) = (RECORD*) tos(), pop(),
/*442*/ 		push((char*) (
/*442*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*442*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"instanceof"),
/*442*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*442*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 107,
/*443*/ 			(RECORD*) pop()
/*443*/ 		)),
/*443*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),45) = (RECORD*) tos(), pop(),
/*443*/ 		push((char*) (
/*443*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*443*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int"),
/*443*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*443*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 67,
/*444*/ 			(RECORD*) pop()
/*444*/ 		)),
/*444*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),46) = (RECORD*) tos(), pop(),
/*444*/ 		push((char*) (
/*444*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*444*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"integer"),
/*444*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*444*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 67,
/*445*/ 			(RECORD*) pop()
/*445*/ 		)),
/*445*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),47) = (RECORD*) tos(), pop(),
/*445*/ 		push((char*) (
/*445*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*445*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"interface"),
/*445*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*445*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 92,
/*446*/ 			(RECORD*) pop()
/*446*/ 		)),
/*446*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),48) = (RECORD*) tos(), pop(),
/*446*/ 		push((char*) (
/*446*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*446*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"isset"),
/*446*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*446*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 122,
/*447*/ 			(RECORD*) pop()
/*447*/ 		)),
/*447*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),49) = (RECORD*) tos(), pop(),
/*447*/ 		push((char*) (
/*447*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*447*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"list"),
/*447*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*447*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 108,
/*448*/ 			(RECORD*) pop()
/*448*/ 		)),
/*448*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),50) = (RECORD*) tos(), pop(),
/*448*/ 		push((char*) (
/*448*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*448*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"namespace"),
/*448*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*448*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 127,
/*449*/ 			(RECORD*) pop()
/*449*/ 		)),
/*449*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),51) = (RECORD*) tos(), pop(),
/*449*/ 		push((char*) (
/*449*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*449*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"new"),
/*449*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*449*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 105,
/*450*/ 			(RECORD*) pop()
/*450*/ 		)),
/*450*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),52) = (RECORD*) tos(), pop(),
/*450*/ 		push((char*) (
/*450*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*450*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"null"),
/*450*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*450*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 63,
/*451*/ 			(RECORD*) pop()
/*451*/ 		)),
/*451*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),53) = (RECORD*) tos(), pop(),
/*451*/ 		push((char*) (
/*451*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*451*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"object"),
/*451*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*451*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 71,
/*452*/ 			(RECORD*) pop()
/*452*/ 		)),
/*452*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),54) = (RECORD*) tos(), pop(),
/*452*/ 		push((char*) (
/*452*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*452*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"or"),
/*452*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*452*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 56,
/*453*/ 			(RECORD*) pop()
/*453*/ 		)),
/*453*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),55) = (RECORD*) tos(), pop(),
/*453*/ 		push((char*) (
/*453*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*453*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"parent"),
/*453*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*453*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 104,
/*454*/ 			(RECORD*) pop()
/*454*/ 		)),
/*454*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),56) = (RECORD*) tos(), pop(),
/*454*/ 		push((char*) (
/*454*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*454*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"print"),
/*454*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*454*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 115,
/*455*/ 			(RECORD*) pop()
/*455*/ 		)),
/*455*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),57) = (RECORD*) tos(), pop(),
/*455*/ 		push((char*) (
/*455*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*455*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"private"),
/*455*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*455*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 99,
/*456*/ 			(RECORD*) pop()
/*456*/ 		)),
/*456*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),58) = (RECORD*) tos(), pop(),
/*456*/ 		push((char*) (
/*456*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*456*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"protected"),
/*456*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*456*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 100,
/*457*/ 			(RECORD*) pop()
/*457*/ 		)),
/*457*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),59) = (RECORD*) tos(), pop(),
/*457*/ 		push((char*) (
/*457*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*457*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"public"),
/*457*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*457*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 98,
/*458*/ 			(RECORD*) pop()
/*458*/ 		)),
/*458*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),60) = (RECORD*) tos(), pop(),
/*458*/ 		push((char*) (
/*458*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*458*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"real"),
/*458*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*458*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 68,
/*459*/ 			(RECORD*) pop()
/*459*/ 		)),
/*459*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),61) = (RECORD*) tos(), pop(),
/*459*/ 		push((char*) (
/*459*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*459*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"require"),
/*459*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*459*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 125,
/*460*/ 			(RECORD*) pop()
/*460*/ 		)),
/*460*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),62) = (RECORD*) tos(), pop(),
/*460*/ 		push((char*) (
/*460*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*460*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"require_once"),
/*460*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*460*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 126,
/*461*/ 			(RECORD*) pop()
/*461*/ 		)),
/*461*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),63) = (RECORD*) tos(), pop(),
/*461*/ 		push((char*) (
/*461*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*461*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"return"),
/*461*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*461*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 28,
/*462*/ 			(RECORD*) pop()
/*462*/ 		)),
/*462*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),64) = (RECORD*) tos(), pop(),
/*462*/ 		push((char*) (
/*462*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*462*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"self"),
/*462*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*462*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 103,
/*463*/ 			(RECORD*) pop()
/*463*/ 		)),
/*463*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),65) = (RECORD*) tos(), pop(),
/*463*/ 		push((char*) (
/*463*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*463*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"static"),
/*463*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*463*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 101,
/*464*/ 			(RECORD*) pop()
/*464*/ 		)),
/*464*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),66) = (RECORD*) tos(), pop(),
/*464*/ 		push((char*) (
/*464*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*464*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string"),
/*464*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*464*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 69,
/*465*/ 			(RECORD*) pop()
/*465*/ 		)),
/*465*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),67) = (RECORD*) tos(), pop(),
/*465*/ 		push((char*) (
/*465*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*465*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"switch"),
/*465*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*465*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 109,
/*466*/ 			(RECORD*) pop()
/*466*/ 		)),
/*466*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),68) = (RECORD*) tos(), pop(),
/*466*/ 		push((char*) (
/*466*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*466*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"throw"),
/*466*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*466*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 120,
/*467*/ 			(RECORD*) pop()
/*467*/ 		)),
/*467*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),69) = (RECORD*) tos(), pop(),
/*467*/ 		push((char*) (
/*467*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*467*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"trigger_error"),
/*467*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*467*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 116,
/*468*/ 			(RECORD*) pop()
/*468*/ 		)),
/*468*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),70) = (RECORD*) tos(), pop(),
/*468*/ 		push((char*) (
/*468*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*468*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"true"),
/*468*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*468*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 66,
/*469*/ 			(RECORD*) pop()
/*469*/ 		)),
/*469*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),71) = (RECORD*) tos(), pop(),
/*469*/ 		push((char*) (
/*469*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*469*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"try"),
/*469*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*469*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 118,
/*470*/ 			(RECORD*) pop()
/*470*/ 		)),
/*470*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),72) = (RECORD*) tos(), pop(),
/*470*/ 		push((char*) (
/*470*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*470*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"use"),
/*470*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*470*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 128,
/*471*/ 			(RECORD*) pop()
/*471*/ 		)),
/*471*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),73) = (RECORD*) tos(), pop(),
/*471*/ 		push((char*) (
/*471*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*471*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"var"),
/*471*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*471*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 97,
/*472*/ 			(RECORD*) pop()
/*472*/ 		)),
/*472*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),74) = (RECORD*) tos(), pop(),
/*472*/ 		push((char*) (
/*472*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*472*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"while"),
/*472*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*472*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 24,
/*473*/ 			(RECORD*) pop()
/*473*/ 		)),
/*473*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),75) = (RECORD*) tos(), pop(),
/*473*/ 		push((char*) (
/*473*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*473*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"xor"),
/*473*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*473*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 89,
/*475*/ 			(RECORD*) pop()
/*475*/ 		)),
/*475*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),76) = (RECORD*) tos(), pop(),
/*476*/ 		(ARRAY*) pop()
/*476*/ 	);
/*476*/ 	Scanner_phplint_keywords = (
/*477*/ 		push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*477*/ 		push((char*) (
/*477*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*477*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"abstract"),
/*477*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*477*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 173,
/*478*/ 			(RECORD*) pop()
/*478*/ 		)),
/*478*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/*478*/ 		push((char*) (
/*478*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*478*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"args"),
/*478*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*478*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 156,
/*479*/ 			(RECORD*) pop()
/*479*/ 		)),
/*479*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),1) = (RECORD*) tos(), pop(),
/*479*/ 		push((char*) (
/*479*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*479*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"array"),
/*479*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*479*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 149,
/*480*/ 			(RECORD*) pop()
/*480*/ 		)),
/*480*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),2) = (RECORD*) tos(), pop(),
/*480*/ 		push((char*) (
/*480*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*480*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"bool"),
/*480*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*480*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 145,
/*481*/ 			(RECORD*) pop()
/*481*/ 		)),
/*481*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),3) = (RECORD*) tos(), pop(),
/*481*/ 		push((char*) (
/*481*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*481*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"boolean"),
/*481*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*481*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 145,
/*482*/ 			(RECORD*) pop()
/*482*/ 		)),
/*482*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),4) = (RECORD*) tos(), pop(),
/*482*/ 		push((char*) (
/*482*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*482*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"class"),
/*482*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*482*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 138,
/*483*/ 			(RECORD*) pop()
/*483*/ 		)),
/*483*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),5) = (RECORD*) tos(), pop(),
/*483*/ 		push((char*) (
/*483*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*483*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"const"),
/*483*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*483*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 141,
/*484*/ 			(RECORD*) pop()
/*484*/ 		)),
/*484*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),6) = (RECORD*) tos(), pop(),
/*484*/ 		push((char*) (
/*484*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*484*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"double"),
/*484*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*484*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 147,
/*485*/ 			(RECORD*) pop()
/*485*/ 		)),
/*485*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),7) = (RECORD*) tos(), pop(),
/*485*/ 		push((char*) (
/*485*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*485*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"else"),
/*485*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*485*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 166,
/*486*/ 			(RECORD*) pop()
/*486*/ 		)),
/*486*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),8) = (RECORD*) tos(), pop(),
/*486*/ 		push((char*) (
/*486*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*486*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"end_if_php_ver"),
/*486*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*486*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 167,
/*487*/ 			(RECORD*) pop()
/*487*/ 		)),
/*487*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),9) = (RECORD*) tos(), pop(),
/*487*/ 		push((char*) (
/*487*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*487*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"extends"),
/*487*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*487*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 139,
/*488*/ 			(RECORD*) pop()
/*488*/ 		)),
/*488*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),10) = (RECORD*) tos(), pop(),
/*488*/ 		push((char*) (
/*488*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*488*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"final"),
/*488*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*488*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 175,
/*489*/ 			(RECORD*) pop()
/*489*/ 		)),
/*489*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),11) = (RECORD*) tos(), pop(),
/*489*/ 		push((char*) (
/*489*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*489*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"float"),
/*489*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*489*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 147,
/*490*/ 			(RECORD*) pop()
/*490*/ 		)),
/*490*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),12) = (RECORD*) tos(), pop(),
/*490*/ 		push((char*) (
/*490*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*490*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"forward"),
/*490*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*490*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 136,
/*491*/ 			(RECORD*) pop()
/*491*/ 		)),
/*491*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),13) = (RECORD*) tos(), pop(),
/*491*/ 		push((char*) (
/*491*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*491*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"function"),
/*491*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*491*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 137,
/*492*/ 			(RECORD*) pop()
/*492*/ 		)),
/*492*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),14) = (RECORD*) tos(), pop(),
/*492*/ 		push((char*) (
/*492*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*492*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"if_php_ver_4"),
/*492*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*492*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 164,
/*493*/ 			(RECORD*) pop()
/*493*/ 		)),
/*493*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),15) = (RECORD*) tos(), pop(),
/*493*/ 		push((char*) (
/*493*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*493*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"if_php_ver_5"),
/*493*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*493*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 165,
/*494*/ 			(RECORD*) pop()
/*494*/ 		)),
/*494*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),16) = (RECORD*) tos(), pop(),
/*494*/ 		push((char*) (
/*494*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*494*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"implements"),
/*494*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*494*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 140,
/*495*/ 			(RECORD*) pop()
/*495*/ 		)),
/*495*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),17) = (RECORD*) tos(), pop(),
/*495*/ 		push((char*) (
/*495*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*495*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int"),
/*495*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*495*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 146,
/*496*/ 			(RECORD*) pop()
/*496*/ 		)),
/*496*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),18) = (RECORD*) tos(), pop(),
/*496*/ 		push((char*) (
/*496*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*496*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"integer"),
/*496*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*496*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 146,
/*497*/ 			(RECORD*) pop()
/*497*/ 		)),
/*497*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),19) = (RECORD*) tos(), pop(),
/*497*/ 		push((char*) (
/*497*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*497*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"interface"),
/*497*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*497*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 142,
/*498*/ 			(RECORD*) pop()
/*498*/ 		)),
/*498*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),20) = (RECORD*) tos(), pop(),
/*498*/ 		push((char*) (
/*498*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*498*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"missing_break"),
/*498*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*498*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 168,
/*499*/ 			(RECORD*) pop()
/*499*/ 		)),
/*499*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),21) = (RECORD*) tos(), pop(),
/*499*/ 		push((char*) (
/*499*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*499*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"missing_default"),
/*499*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*499*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 169,
/*500*/ 			(RECORD*) pop()
/*500*/ 		)),
/*500*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),22) = (RECORD*) tos(), pop(),
/*500*/ 		push((char*) (
/*500*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*500*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"mixed"),
/*500*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*500*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 150,
/*501*/ 			(RECORD*) pop()
/*501*/ 		)),
/*501*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),23) = (RECORD*) tos(), pop(),
/*501*/ 		push((char*) (
/*501*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*501*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"namespace"),
/*501*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*501*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 180,
/*502*/ 			(RECORD*) pop()
/*502*/ 		)),
/*502*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),24) = (RECORD*) tos(), pop(),
/*502*/ 		push((char*) (
/*502*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*502*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"object"),
/*502*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*502*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 152,
/*503*/ 			(RECORD*) pop()
/*503*/ 		)),
/*503*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),25) = (RECORD*) tos(), pop(),
/*503*/ 		push((char*) (
/*503*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*503*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"parent"),
/*503*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*503*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 177,
/*504*/ 			(RECORD*) pop()
/*504*/ 		)),
/*504*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),26) = (RECORD*) tos(), pop(),
/*504*/ 		push((char*) (
/*504*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*504*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"pragma"),
/*504*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*504*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 163,
/*505*/ 			(RECORD*) pop()
/*505*/ 		)),
/*505*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),27) = (RECORD*) tos(), pop(),
/*505*/ 		push((char*) (
/*505*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*505*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"private"),
/*505*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*505*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 172,
/*506*/ 			(RECORD*) pop()
/*506*/ 		)),
/*506*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),28) = (RECORD*) tos(), pop(),
/*506*/ 		push((char*) (
/*506*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*506*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"protected"),
/*506*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*506*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 171,
/*507*/ 			(RECORD*) pop()
/*507*/ 		)),
/*507*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),29) = (RECORD*) tos(), pop(),
/*507*/ 		push((char*) (
/*507*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*507*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"public"),
/*507*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*507*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 170,
/*508*/ 			(RECORD*) pop()
/*508*/ 		)),
/*508*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),30) = (RECORD*) tos(), pop(),
/*508*/ 		push((char*) (
/*508*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*508*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"require_module"),
/*508*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*508*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 130,
/*509*/ 			(RECORD*) pop()
/*509*/ 		)),
/*509*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),31) = (RECORD*) tos(), pop(),
/*509*/ 		push((char*) (
/*509*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*509*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"resource"),
/*509*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*509*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 151,
/*510*/ 			(RECORD*) pop()
/*510*/ 		)),
/*510*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),32) = (RECORD*) tos(), pop(),
/*510*/ 		push((char*) (
/*510*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*510*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"return"),
/*510*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*510*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 179,
/*511*/ 			(RECORD*) pop()
/*511*/ 		)),
/*511*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),33) = (RECORD*) tos(), pop(),
/*511*/ 		push((char*) (
/*511*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*511*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"self"),
/*511*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*511*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 176,
/*512*/ 			(RECORD*) pop()
/*512*/ 		)),
/*512*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),34) = (RECORD*) tos(), pop(),
/*512*/ 		push((char*) (
/*512*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*512*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"static"),
/*512*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*512*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 174,
/*513*/ 			(RECORD*) pop()
/*513*/ 		)),
/*513*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),35) = (RECORD*) tos(), pop(),
/*513*/ 		push((char*) (
/*513*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*513*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string"),
/*513*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*513*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 148,
/*514*/ 			(RECORD*) pop()
/*514*/ 		)),
/*514*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),36) = (RECORD*) tos(), pop(),
/*514*/ 		push((char*) (
/*514*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*514*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"throws"),
/*514*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*514*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 178,
/*515*/ 			(RECORD*) pop()
/*515*/ 		)),
/*515*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),37) = (RECORD*) tos(), pop(),
/*515*/ 		push((char*) (
/*515*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*515*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"unchecked"),
/*515*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*515*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 143,
/*516*/ 			(RECORD*) pop()
/*516*/ 		)),
/*516*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),38) = (RECORD*) tos(), pop(),
/*516*/ 		push((char*) (
/*516*/ 			push((char*) alloc_RECORD(1 * sizeof(void*) + 3 * sizeof(int), 1)),
/*516*/ 			push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"void"),
/*516*/ 			*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*516*/ 			*(int*) (tos()+1 * sizeof(void*) + 2 * sizeof(int)) = 144,
/*518*/ 			(RECORD*) pop()
/*518*/ 		)),
/*518*/ 		*(RECORD**) element_ARRAY((ARRAY*) tosn(1),39) = (RECORD*) tos(), pop(),
/*520*/ 		(ARRAY*) pop()
/*520*/ 	);
/*522*/ }


/*529*/ void
/*529*/ Scanner_ParseText(void)
/*529*/ {

/*531*/ 	int
/*531*/ 	Scanner_is_space(STRING *Scanner_c)
/*531*/ 	{
/*531*/ 		return ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(9)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(13)) == 0));
/*535*/ 	}

/*535*/ 	buffer_Reset(*(void **)(void *)&Scanner_b);
/*538*/ 	do{
/*538*/ 		if( Scanner_c == NULL ){
/*539*/ 			if( (buffer_Length(Scanner_b) == 0) ){
/*540*/ 				Scanner_sym = 0;
/*542*/ 			} else {
/*542*/ 				Scanner_sym = 3;
/*543*/ 				Scanner_s = buffer_ToString(Scanner_b);
/*546*/ 			}
/*546*/ 			return ;
/*546*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(60)) == 0 ){
/*547*/ 			if( Scanner_FollowingCharsMatch(m2runtime_CHR(63)) ){
/*548*/ 				if( (buffer_Length(Scanner_b) == 0) ){
/*549*/ 					if( Scanner_FollowingCharsMatch((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"?=") ){
/*552*/ 						Scanner_sym = 5;
/*553*/ 						Scanner_code = 1;
/*554*/ 						Scanner_ReadCh();
/*554*/ 						Scanner_ReadCh();
/*554*/ 						Scanner_ReadCh();
/*556*/ 						return ;
/*556*/ 					} else if( Scanner_FollowingCharsMatch((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"?php") ){
/*557*/ 						Scanner_sym = 4;
/*558*/ 						Scanner_code = 1;
/*559*/ 						Scanner_ReadCh();
/*559*/ 						Scanner_ReadCh();
/*559*/ 						Scanner_ReadCh();
/*559*/ 						Scanner_ReadCh();
/*559*/ 						Scanner_ReadCh();
/*560*/ 						if( ((Scanner_c != NULL) && !Scanner_is_space(Scanner_c)) ){
/*561*/ 							Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"invalid opening tag, expected `<?php' c=", m2runtime_StringToLiteral(Scanner_c), (STRING *) 1));
/*565*/ 						}
/*565*/ 						return ;
/*566*/ 					} else {
/*566*/ 						Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"using deprecated short tag `<?' -- Hint: use `<?php' instead");
/*567*/ 						Scanner_ReadCh();
/*567*/ 						Scanner_ReadCh();
/*568*/ 						Scanner_sym = 4;
/*569*/ 						Scanner_code = 1;
/*571*/ 						return ;
/*573*/ 					}
/*573*/ 				} else {
/*573*/ 					Scanner_sym = 3;
/*574*/ 					Scanner_s = buffer_ToString(Scanner_b);
/*576*/ 					return ;
/*578*/ 				}
/*578*/ 			} else {
/*578*/ 				buffer_AddString((void *)&Scanner_b, Scanner_c);
/*579*/ 				Scanner_ReadCh();
/*582*/ 			}
/*582*/ 		} else {
/*582*/ 			buffer_AddString((void *)&Scanner_b, Scanner_c);
/*583*/ 			Scanner_ReadCh();
/*586*/ 		}
/*587*/ 	}while(TRUE);
/*589*/ }


/*598*/ void
/*598*/ Scanner_SkipNewLineAfterCloseTag(void)
/*598*/ {
/*598*/ 	Scanner_ReadCh();
/*599*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) == 0 ){
/*600*/ 		Scanner_ReadCh();
/*601*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(13)) == 0 ){
/*602*/ 		Scanner_ReadCh();
/*603*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) == 0 ){
/*604*/ 			Scanner_ReadCh();
/*606*/ 		}
/*608*/ 	}
/*610*/ }


/*614*/ int
/*614*/ Scanner_SkipSingleLineComment(void)
/*614*/ {
/*616*/ 	STRING * Scanner_prev = NULL;
/*617*/ 	do{
/*617*/ 		Scanner_prev = Scanner_c;
/*618*/ 		Scanner_ReadCh();
/*619*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) == 0 ){
/*620*/ 			Scanner_ReadCh();
/*621*/ 			return FALSE;
/*622*/ 		} else if( Scanner_c == NULL ){
/*623*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"premature end of the file or missing closing tag");
/*624*/ 		} else if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(62)) == 0) && (m2runtime_strcmp(Scanner_prev, m2runtime_CHR(63)) == 0)) ){
/*625*/ 			Scanner_SkipNewLineAfterCloseTag();
/*626*/ 			return TRUE;
/*629*/ 		}
/*630*/ 	}while(TRUE);
/*630*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 21);
/*630*/ 	return 0;
/*632*/ }


/*638*/ int
/*638*/ Scanner_SkipSpaces(void)
/*638*/ {
/*638*/ 	while( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(9)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(35)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(13)) == 0)) ){
/*640*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(35)) == 0 ){
/*641*/ 			if( Scanner_SkipSingleLineComment() ){
/*642*/ 				return TRUE;
/*645*/ 			}
/*645*/ 		} else {
/*645*/ 			Scanner_ReadCh();
/*648*/ 		}
/*648*/ 	}
/*648*/ 	return FALSE;
/*652*/ }


/*658*/ void
/*658*/ Scanner_SkipMultilineComment(void)
/*658*/ {
/*659*/ 	int Scanner_start_line_n = 0;
/*661*/ 	STRING * Scanner_c2 = NULL;
/*661*/ 	STRING * Scanner_c1 = NULL;
/*661*/ 	if( Globals_DEBUG ){
/*662*/ 		m2_print((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"[comment start]");
/*664*/ 	}
/*664*/ 	buffer_Set((void *)&Scanner_b, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"/*");
/*665*/ 	Scanner_start_line_n = Scanner_line_n;
/*667*/ 	do{
/*667*/ 		buffer_AddString((void *)&Scanner_b, Scanner_c);
/*668*/ 		if( Scanner_c == NULL ){
/*669*/ 			Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\62,\0,\0,\0)"missing closing '*/' in comment beginning in line ", m2runtime_itos(Scanner_start_line_n), (STRING *) 1));
/*671*/ 		} else if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(42)) == 0) && (m2runtime_strcmp(Scanner_c1, m2runtime_CHR(47)) == 0)) ){
/*672*/ 			Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"possible nested multiline comment in comment beginning in line ", m2runtime_itos(Scanner_start_line_n), (STRING *) 1));
/*673*/ 		} else if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(47)) == 0) && (m2runtime_strcmp(Scanner_c1, m2runtime_CHR(42)) == 0)) ){
/*674*/ 			if( m2runtime_strcmp(Scanner_c2, m2runtime_CHR(46)) == 0 ){
/*675*/ 				Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"possible missing `.' in multiline comment beginning in line ", m2runtime_itos(Scanner_start_line_n), (STRING *) 1));
/*677*/ 			}
/*677*/ 			if( Globals_DEBUG ){
/*678*/ 				m2_print((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"[comment end]");
/*680*/ 			}
/*680*/ 			Scanner_ReadCh();
/*681*/ 			Scanner_s = buffer_ToString(Scanner_b);
/*683*/ 			return ;
/*684*/ 		}
/*684*/ 		Scanner_c2 = Scanner_c1;
/*685*/ 		Scanner_c1 = Scanner_c;
/*686*/ 		Scanner_ReadCh();
/*689*/ 	}while(TRUE);
/*691*/ }


/*693*/ STRING *
/*693*/ Scanner_ReportChar(int Scanner_ch)
/*693*/ {
/*693*/ 	if( (((Scanner_ch >= 32)) && ((Scanner_ch <= 126))) ){
/*694*/ 		return m2runtime_concat_STRING(0, m2runtime_CHR(96), m2runtime_CHR(Scanner_ch), m2runtime_CHR(39), (STRING *) 1);
/*695*/ 	} else if( (Scanner_ch == 9) ){
/*696*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"horizontal tabulator, HT, 9";
/*697*/ 	} else if( (Scanner_ch == 10) ){
/*698*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"line feed, LF, 10";
/*699*/ 	} else if( (Scanner_ch == 13) ){
/*700*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"carriage return, CR, 13";
/*701*/ 	} else if( (Scanner_ch == 127) ){
/*702*/ 		return (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"delete, DEL, 127";
/*703*/ 	} else if( (Scanner_ch > 127) ){
/*704*/ 		return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"code ", m2runtime_itos(Scanner_ch), (STRING *) 1);
/*706*/ 	} else {
/*706*/ 		return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"control code ", m2runtime_itos(Scanner_ch), (STRING *) 1);
/*709*/ 	}
/*709*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 22);
/*709*/ 	return NULL;
/*711*/ }


/*713*/ void
/*713*/ Scanner_ReportCTRL(int Scanner_ch)
/*713*/ {
/*713*/ 	if( !Scanner_ctrl_check ){
/*715*/ 		return ;
/*716*/ 	}
/*716*/ 	Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"found control character (", Scanner_ReportChar(Scanner_ch), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\103,\0,\0,\0)") in literal string. This msg is reported only once for each string", (STRING *) 1));
/*721*/ }


/*723*/ void
/*723*/ Scanner_ReportASCIIExt(int Scanner_ch, STRING *Scanner_in)
/*723*/ {
/*723*/ 	if( !Scanner_ascii_ext_check ){
/*725*/ 		return ;
/*726*/ 	}
/*726*/ 	Scanner_Warning(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"non-ASCII character code in ", Scanner_in, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" (", Scanner_ReportChar(Scanner_ch), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\53,\0,\0,\0)"). This msg is reported only once for each ", Scanner_in, (STRING *) 1));
/*731*/ }


/*737*/ int
/*737*/ Scanner_is_id_first_char(STRING *Scanner_c)
/*737*/ {
/*738*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(97)) >= 0 ){
/*739*/ 		return ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(122)) <= 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(128)) >= 0));
/*740*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(65)) >= 0 ){
/*741*/ 		return ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(90)) <= 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(95)) == 0));
/*743*/ 	} else {
/*743*/ 		return FALSE;
/*750*/ 	}
/*750*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 23);
/*750*/ 	return 0;
/*752*/ }


/*754*/ int
/*754*/ Scanner_is_id_char(STRING *Scanner_c)
/*754*/ {
/*754*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(97)) >= 0 ){
/*755*/ 		return ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(122)) <= 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(127)) >= 0));
/*756*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(65)) >= 0 ){
/*757*/ 		return ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(90)) <= 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(95)) == 0));
/*759*/ 	} else {
/*759*/ 		return ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(57)) <= 0));
/*767*/ 	}
/*767*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 24);
/*767*/ 	return 0;
/*769*/ }


/*771*/ int
/*771*/ Scanner_is_digit(STRING *Scanner_c)
/*771*/ {
/*771*/ 	return ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(57)) <= 0));
/*775*/ }


/*777*/ int
/*777*/ Scanner_is_hex(STRING *Scanner_c)
/*777*/ {
/*777*/ 	return (((m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(57)) <= 0)) || ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(65)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(70)) <= 0)) || ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(97)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(102)) <= 0)));
/*783*/ }


/*785*/ int
/*785*/ Scanner_hex(STRING *Scanner_c)
/*785*/ {
/*785*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(57)) <= 0 ){
/*786*/ 		return (m2runtime_ASC(Scanner_c) - m2runtime_ASC(m2runtime_CHR(48)));
/*787*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(90)) <= 0 ){
/*788*/ 		return ((10 + m2runtime_ASC(Scanner_c)) - m2runtime_ASC(m2runtime_CHR(65)));
/*790*/ 	} else {
/*790*/ 		return ((10 + m2runtime_ASC(Scanner_c)) - m2runtime_ASC(m2runtime_CHR(97)));
/*793*/ 	}
/*793*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 25);
/*793*/ 	return 0;
/*796*/ }

/*800*/ STRING * Scanner_here_doc_id = NULL;
/*804*/ STRING * Scanner_end4 = NULL;
/*804*/ STRING * Scanner_end3 = NULL;
/*804*/ STRING * Scanner_end2 = NULL;
/*804*/ STRING * Scanner_end1 = NULL;
/*809*/ STRING * Scanner_wrong_end = NULL;
/*816*/ int Scanner_start_line_n = 0;

/*822*/ STRING *
/*822*/ Scanner_ParseSingleQuotedString(void)
/*822*/ {
/*823*/ 	int Scanner_ch = 0;
/*823*/ 	int Scanner_start_line_n = 0;
/*824*/ 	int Scanner_skip = 0;
/*826*/ 	int Scanner_report_ascii_ext = 0;
/*826*/ 	int Scanner_report_ctrl = 0;
/*826*/ 	buffer_Empty((void *)&Scanner_b);
/*827*/ 	Scanner_skip = FALSE;
/*828*/ 	Scanner_report_ctrl = Scanner_ctrl_check;
/*829*/ 	Scanner_report_ascii_ext = Scanner_ascii_ext_check;
/*830*/ 	Scanner_start_line_n = Scanner_line_n;
/*831*/ 	Scanner_ReadCh();
/*833*/ 	do{
/*833*/ 		if( Scanner_c == NULL ){
/*834*/ 			if( Scanner_here_doc_id == NULL ){
/*835*/ 				Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\74,\0,\0,\0)"missing terminating ' character in string beginning in line ", m2runtime_itos(Scanner_start_line_n), (STRING *) 1));
/*837*/ 			} else {
/*837*/ 				Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\52,\0,\0,\0)"unclosed now-doc string beginning in line ", m2runtime_itos(Scanner_start_line_n), (STRING *) 1));
/*840*/ 			}
/*841*/ 		}
/*841*/ 		Scanner_ch = m2runtime_ASC(Scanner_c);
/*844*/ 		if( (Scanner_report_ctrl && ((((Scanner_ch < 32)) || ((Scanner_ch == 127)))) && (((Scanner_here_doc_id == NULL) || (((Scanner_ch != 10)) && ((Scanner_ch != 13)) && ((Scanner_ch != 9)))))) ){
/*849*/ 			Scanner_ReportCTRL(Scanner_ch);
/*850*/ 			Scanner_report_ctrl = FALSE;
/*853*/ 		}
/*853*/ 		if( (Scanner_report_ascii_ext && ((Scanner_ch > 127))) ){
/*854*/ 			Scanner_ReportASCIIExt(Scanner_ch, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"literal string");
/*855*/ 			Scanner_report_ascii_ext = FALSE;
/*858*/ 		}
/*858*/ 		if( Scanner_skip ){
/*859*/ 			if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(39)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0)) ){
/*860*/ 				buffer_AddString((void *)&Scanner_b, Scanner_c);
/*862*/ 			} else {
/*862*/ 				buffer_AddString((void *)&Scanner_b, m2runtime_CHR(92));
/*863*/ 				buffer_AddString((void *)&Scanner_b, Scanner_c);
/*864*/ 				Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\106,\0,\0,\0)"invalid escape sequence. Hint: allowed escape sequences are only \134' \134\134");
/*866*/ 			}
/*866*/ 			Scanner_skip = FALSE;
/*867*/ 			Scanner_ReadCh();
/*870*/ 		} else if( ((Scanner_here_doc_id == NULL) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(39)) == 0)) ){
/*871*/ 			Scanner_ReadCh();
/*872*/ 			return buffer_ToString(Scanner_b);
/*875*/ 		} else if( ((Scanner_here_doc_id != NULL) && ((Scanner_line_idx == 1)) && m2_match(Scanner_line, Scanner_wrong_end)) ){
/*879*/ 			if( !(((m2runtime_strcmp(Scanner_line, Scanner_end1) == 0) || (m2runtime_strcmp(Scanner_line, Scanner_end2) == 0) || (m2runtime_strcmp(Scanner_line, Scanner_end3) == 0) || (m2runtime_strcmp(Scanner_line, Scanner_end4) == 0))) ){
/*883*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\110,\0,\0,\0)"invisible spaces in terminating line not allowed (PHPLint restriction): ", m2runtime_StringToLiteral(Scanner_line), (STRING *) 1));
/*889*/ 			}
/*889*/ 			do {
/*889*/ 				Scanner_ReadCh();
/*890*/ 			} while( !( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(59)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) == 0)) ));
/*892*/ 			Scanner_here_doc_id = NULL;
/*894*/ 			return buffer_ToString(Scanner_b);
/*896*/ 		} else if( ((Scanner_here_doc_id == NULL) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0)) ){
/*897*/ 			Scanner_skip = TRUE;
/*898*/ 			Scanner_ReadCh();
/*900*/ 		} else {
/*900*/ 			buffer_AddString((void *)&Scanner_b, Scanner_c);
/*901*/ 			Scanner_ReadCh();
/*904*/ 		}
/*905*/ 	}while(TRUE);
/*905*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 26);
/*905*/ 	return NULL;
/*907*/ }


/*922*/ int
/*922*/ Scanner_ParseDoubleQuotedString(void)
/*922*/ {

/*923*/ 	STRING *
/*923*/ 	Scanner_ParseEscapeCode(void)
/*923*/ 	{
/*925*/ 		int Scanner_x = 0;
/*925*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(110)) == 0 ){
/*926*/ 			Scanner_ReadCh();
/*927*/ 			return m2runtime_CHR(10);
/*928*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(114)) == 0 ){
/*929*/ 			Scanner_ReadCh();
/*930*/ 			return m2runtime_CHR(13);
/*931*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(116)) == 0 ){
/*932*/ 			Scanner_ReadCh();
/*933*/ 			return m2runtime_CHR(9);
/*934*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(118)) == 0 ){
/*935*/ 			Scanner_ReadCh();
/*936*/ 			return m2runtime_CHR(11);
/*937*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(102)) == 0 ){
/*938*/ 			Scanner_ReadCh();
/*939*/ 			return m2runtime_CHR(12);
/*940*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0 ){
/*941*/ 			Scanner_ReadCh();
/*942*/ 			return m2runtime_CHR(92);
/*943*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(36)) == 0 ){
/*944*/ 			Scanner_ReadCh();
/*945*/ 			return m2runtime_CHR(36);
/*946*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(34)) == 0 ){
/*947*/ 			Scanner_ReadCh();
/*948*/ 			return m2runtime_CHR(34);
/*949*/ 		} else if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(55)) <= 0)) ){
/*950*/ 			Scanner_x = (m2runtime_ASC(Scanner_c) - m2runtime_ASC(m2runtime_CHR(48)));
/*951*/ 			Scanner_ReadCh();
/*952*/ 			if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(55)) <= 0)) ){
/*953*/ 				Scanner_x = (((8 * Scanner_x) + m2runtime_ASC(Scanner_c)) - m2runtime_ASC(m2runtime_CHR(48)));
/*954*/ 				Scanner_ReadCh();
/*955*/ 				if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(55)) <= 0)) ){
/*956*/ 					Scanner_x = (((8 * Scanner_x) + m2runtime_ASC(Scanner_c)) - m2runtime_ASC(m2runtime_CHR(48)));
/*957*/ 					Scanner_ReadCh();
/*960*/ 				}
/*960*/ 			}
/*960*/ 			if( (Scanner_x > 255) ){
/*961*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"invalid octal code in escape sequence: too big");
/*962*/ 				return NULL;
/*964*/ 			}
/*964*/ 			return m2runtime_CHR(Scanner_x);
/*965*/ 		} else if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(120)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(88)) == 0)) ){
/*966*/ 			Scanner_ReadCh();
/*967*/ 			if( !Scanner_is_hex(Scanner_c) ){
/*968*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"invalid hexadecimal digit in escape sequence");
/*969*/ 				return NULL;
/*971*/ 			}
/*971*/ 			Scanner_x = Scanner_hex(Scanner_c);
/*972*/ 			Scanner_ReadCh();
/*973*/ 			if( Scanner_is_hex(Scanner_c) ){
/*974*/ 				Scanner_x = ((16 * Scanner_x) + Scanner_hex(Scanner_c));
/*975*/ 				Scanner_ReadCh();
/*977*/ 			}
/*977*/ 			return m2runtime_CHR(Scanner_x);
/*979*/ 		} else {
/*979*/ 			Scanner_Warning((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\177,\0,\0,\0)"invalid escape sequence. Hint: allowed escape sequences are only \134n \134r \134t \134v \134f \134$ \134\042 \134\134 \1340-\134377 (octal) \134x0-\134xff (hexadecimal)");
/*980*/ 			return m2runtime_concat_STRING(0, m2runtime_CHR(92), Scanner_c, (STRING *) 1);
/*983*/ 		}
/*983*/ 		m2runtime_missing_return(Scanner_0err_entry_get, 27);
/*983*/ 		return NULL;
/*986*/ 	}

/*987*/ 	int Scanner_ch = 0;
/*989*/ 	int Scanner_report_ascii_ext = 0;
/*989*/ 	int Scanner_report_ctrl = 0;
/*989*/ 	buffer_Empty((void *)&Scanner_b);
/*990*/ 	Scanner_report_ctrl = Scanner_ctrl_check;
/*991*/ 	Scanner_report_ascii_ext = Scanner_ascii_ext_check;
/*993*/ 	do{
/*993*/ 		if( Scanner_c == NULL ){
/*994*/ 			if( Scanner_here_doc_id == NULL ){
/*995*/ 				Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\61,\0,\0,\0)"missing terminating \042 character in literal string");
/*997*/ 			} else {
/*997*/ 				Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"here-doc `<<< ", Scanner_here_doc_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"' not closed", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)" beginning in line ", m2runtime_itos(Scanner_start_line_n), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)". Expected a line containing exactly `", Scanner_here_doc_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\76,\0,\0,\0)"' possibly followed by `;' then a new-line, no spaces allowed.", (STRING *) 1));
/*1003*/ 			}
/*1004*/ 		}
/*1004*/ 		Scanner_ch = m2runtime_ASC(Scanner_c);
/*1007*/ 		if( (Scanner_report_ctrl && ((((Scanner_ch < 32)) || ((Scanner_ch == 127)))) && (((Scanner_here_doc_id == NULL) || (((Scanner_ch != 10)) && ((Scanner_ch != 13)) && ((Scanner_ch != 9)))))) ){
/*1012*/ 			Scanner_ReportCTRL(Scanner_ch);
/*1013*/ 			Scanner_report_ctrl = FALSE;
/*1017*/ 		}
/*1017*/ 		if( (Scanner_report_ascii_ext && ((Scanner_ch > 127))) ){
/*1018*/ 			Scanner_ReportASCIIExt(Scanner_ch, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"literal string");
/*1019*/ 			Scanner_report_ascii_ext = FALSE;
/*1025*/ 		}
/*1025*/ 		if( ((Scanner_here_doc_id == NULL) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(34)) == 0)) ){
/*1028*/ 			Scanner_ReadCh();
/*1030*/ 			Scanner_s = buffer_ToString(Scanner_b);
/*1031*/ 			if( (Scanner_code == 4) ){
/*1032*/ 				Scanner_code = 1;
/*1033*/ 				if( m2runtime_strcmp(Scanner_s, EMPTY_STRING) <= 0 ){
/*1037*/ 					return TRUE;
/*1040*/ 				} else {
/*1040*/ 					Scanner_sym = 36;
/*1041*/ 					return FALSE;
/*1044*/ 				}
/*1044*/ 			} else {
/*1044*/ 				Scanner_code = 1;
/*1045*/ 				Scanner_sym = 34;
/*1046*/ 				return FALSE;
/*1052*/ 			}
/*1052*/ 		} else if( ((Scanner_here_doc_id != NULL) && ((Scanner_line_idx == 1)) && m2_match(Scanner_line, Scanner_wrong_end)) ){
/*1056*/ 			if( !(((m2runtime_strcmp(Scanner_line, Scanner_end1) == 0) || (m2runtime_strcmp(Scanner_line, Scanner_end2) == 0) || (m2runtime_strcmp(Scanner_line, Scanner_end3) == 0) || (m2runtime_strcmp(Scanner_line, Scanner_end4) == 0))) ){
/*1060*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\110,\0,\0,\0)"invisible spaces in terminating line not allowed (PHPLint restriction): ", m2runtime_StringToLiteral(Scanner_line), (STRING *) 1));
/*1066*/ 			}
/*1066*/ 			do {
/*1066*/ 				Scanner_ReadCh();
/*1067*/ 			} while( !( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(59)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) == 0)) ));
/*1069*/ 			Scanner_here_doc_id = NULL;
/*1071*/ 			Scanner_s = buffer_ToString(Scanner_b);
/*1072*/ 			if( (Scanner_code == 4) ){
/*1073*/ 				Scanner_code = 1;
/*1074*/ 				if( m2runtime_strcmp(Scanner_s, EMPTY_STRING) <= 0 ){
/*1078*/ 					return TRUE;
/*1081*/ 				} else {
/*1081*/ 					Scanner_sym = 36;
/*1082*/ 					return FALSE;
/*1085*/ 				}
/*1085*/ 			} else {
/*1085*/ 				Scanner_code = 1;
/*1086*/ 				Scanner_sym = 37;
/*1087*/ 				return FALSE;
/*1090*/ 			}
/*1090*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0 ){
/*1091*/ 			Scanner_ReadCh();
/*1092*/ 			buffer_AddString((void *)&Scanner_b, Scanner_ParseEscapeCode());
/*1093*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(123)) == 0 ){
/*1094*/ 			buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1095*/ 			Scanner_ReadCh();
/*1096*/ 			if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(36)) == 0 ){
/*1097*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"embedded variable in string:", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)" curly braces notation not allowed", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)" (PHPLint limitation)", (STRING *) 1));
/*1100*/ 				buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1101*/ 				Scanner_ReadCh();
/*1103*/ 			}
/*1103*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(36)) == 0 ){
/*1104*/ 			Scanner_ReadCh();
/*1105*/ 			if( Scanner_is_id_first_char(Scanner_c) ){
/*1111*/ 				Scanner_s = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"DUMMY_CONTINUATION_DOUBLE_QUOTED_STRING";
/*1112*/ 				if( (Scanner_code == 1) ){
/*1118*/ 					Scanner_code = 3;
/*1119*/ 					if( Scanner_here_doc_id == NULL ){
/*1120*/ 						Scanner_sym = 34;
/*1122*/ 					} else {
/*1122*/ 						Scanner_sym = 37;
/*1124*/ 					}
/*1124*/ 					return FALSE;
/*1131*/ 				} else {
/*1131*/ 					Scanner_code = 3;
/*1132*/ 					Scanner_sym = 36;
/*1133*/ 					return m2runtime_strcmp(Scanner_s, EMPTY_STRING) <= 0;
/*1136*/ 				}
/*1136*/ 			} else {
/*1136*/ 				if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(91)) == 0 ){
/*1138*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"embedded variable in string:", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)" array selector not allowed", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)" (PHPLint limitation)", (STRING *) 1));
/*1141*/ 				} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(123)) == 0 ){
/*1143*/ 					Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"embedded variable in string:", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)" curly braces notation not allowed", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)" (PHPLint limitation)", (STRING *) 1));
/*1147*/ 				}
/*1147*/ 				buffer_AddString((void *)&Scanner_b, m2runtime_CHR(36));
/*1150*/ 			}
/*1150*/ 		} else {
/*1150*/ 			buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1151*/ 			Scanner_ReadCh();
/*1154*/ 		}
/*1155*/ 	}while(TRUE);
/*1155*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 28);
/*1155*/ 	return 0;
/*1157*/ }


/*1159*/ int
/*1159*/ Scanner_ParseHereAndNowDoc(void)
/*1159*/ {
/*1160*/ 	STRING * Scanner_id = NULL;
/*1162*/ 	int Scanner_double_quoted_label = 0;
/*1162*/ 	int Scanner_single_quoted_label = 0;
/*1165*/ 	Scanner_start_line_n = Scanner_line_n;
/*1167*/ 	while( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(9)) == 0)) ){
/*1168*/ 		Scanner_ReadCh();
/*1171*/ 	}
/*1171*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(39)) == 0 ){
/*1172*/ 		Scanner_single_quoted_label = TRUE;
/*1173*/ 		Scanner_ReadCh();
/*1174*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(34)) == 0 ){
/*1175*/ 		Scanner_double_quoted_label = TRUE;
/*1176*/ 		Scanner_ReadCh();
/*1179*/ 	}
/*1179*/ 	if( (((Globals_php_ver == 4)) && ((Scanner_single_quoted_label || Scanner_double_quoted_label))) ){
/*1180*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)"quoted label in here-doc allowed only since PHP 5.3.0");
/*1184*/ 	}
/*1184*/ 	if( !Scanner_is_id_first_char(Scanner_c) ){
/*1185*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"expected identifier after `<<<'");
/*1187*/ 	}
/*1187*/ 	buffer_Set((void *)&Scanner_b, Scanner_c);
/*1188*/ 	Scanner_ReadCh();
/*1189*/ 	while( Scanner_is_id_char(Scanner_c) ){
/*1190*/ 		buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1191*/ 		Scanner_ReadCh();
/*1193*/ 	}
/*1193*/ 	Scanner_id = buffer_ToString(Scanner_b);
/*1195*/ 	if( Scanner_single_quoted_label ){
/*1196*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(39)) != 0 ){
/*1197*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"expected closing single quote in here-doc label");
/*1199*/ 		}
/*1199*/ 		Scanner_ReadCh();
/*1200*/ 	} else if( Scanner_double_quoted_label ){
/*1201*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(34)) != 0 ){
/*1202*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"expected closing double quote in here-doc label");
/*1204*/ 		}
/*1204*/ 		Scanner_ReadCh();
/*1207*/ 	}
/*1207*/ 	if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(9)) == 0)) ){
/*1208*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"spaces not allowed after `<<<", Scanner_id, m2runtime_CHR(39), (STRING *) 1));
/*1210*/ 	}
/*1210*/ 	while( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(9)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(13)) == 0)) ){
/*1211*/ 		Scanner_ReadCh();
/*1214*/ 	}
/*1214*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(10)) != 0 ){
/*1215*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\72,\0,\0,\0)"expected end of the line (ASCII code LF) after here-doc ID");
/*1217*/ 	}
/*1217*/ 	Scanner_ReadCh();
/*1219*/ 	Scanner_here_doc_id = Scanner_id;
/*1220*/ 	Scanner_end1 = Scanner_id;
/*1221*/ 	Scanner_end2 = m2runtime_concat_STRING(0, Scanner_id, m2runtime_CHR(13), (STRING *) 1);
/*1222*/ 	Scanner_end3 = m2runtime_concat_STRING(0, Scanner_id, m2runtime_CHR(59), (STRING *) 1);
/*1223*/ 	Scanner_end4 = m2runtime_concat_STRING(0, Scanner_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)";\015", (STRING *) 1);
/*1224*/ 	Scanner_wrong_end = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"^[ \011]*", Scanner_id, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"[ \011]*;?[ \011]*\015?$", (STRING *) 1);
/*1226*/ 	if( Scanner_single_quoted_label ){
/*1227*/ 		Scanner_s = Scanner_ParseSingleQuotedString();
/*1228*/ 		Scanner_sym = 33;
/*1229*/ 		return FALSE;
/*1231*/ 	} else {
/*1231*/ 		return Scanner_ParseDoubleQuotedString();
/*1234*/ 	}
/*1234*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 29);
/*1234*/ 	return 0;
/*1236*/ }


/*1244*/ void
/*1244*/ Scanner_ParseKeyword(void)
/*1244*/ {
/*1244*/ 	int Scanner_report_ascii_ext = 0;
/*1246*/ 	STRING * Scanner_low = NULL;
/*1246*/ 	buffer_Empty((void *)&Scanner_b);
/*1247*/ 	Scanner_report_ascii_ext = Scanner_ascii_ext_check;
/*1249*/ 	do{
/*1249*/ 		if( (Scanner_report_ascii_ext && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(127)) >= 0)) ){
/*1250*/ 			Scanner_ReportASCIIExt(m2runtime_ASC(Scanner_c), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"identifier");
/*1251*/ 			Scanner_report_ascii_ext = FALSE;
/*1253*/ 		}
/*1253*/ 		buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1254*/ 		Scanner_ReadCh();
/*1255*/ 		if( !Scanner_is_id_char(Scanner_c) ){
/*1256*/ 			Scanner_s = buffer_ToString(Scanner_b);
/*1259*/ 			goto m2runtime_loop_1;
/*1260*/ 		}
/*1263*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1263*/ 	if( (Scanner_code == 2) ){
/*1264*/ 		Scanner_sym = Scanner_SearchKeyword(Scanner_s, Scanner_phplint_keywords);
/*1265*/ 		if( (Scanner_sym != 1) ){
/*1267*/ 			return ;
/*1268*/ 		}
/*1268*/ 		Scanner_sym = Scanner_SearchKeyword(Scanner_s, Scanner_php_keywords);
/*1269*/ 		if( (Scanner_sym != 1) ){
/*1270*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"invalid keyword `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"' inside PHPLint meta-code", (STRING *) 1));
/*1271*/ 			Scanner_sym = 1;
/*1273*/ 			return ;
/*1275*/ 		}
/*1275*/ 	} else {
/*1275*/ 		Scanner_sym = Scanner_SearchKeyword(Scanner_s, Scanner_php_keywords);
/*1276*/ 		if( (Scanner_sym != 1) ){
/*1278*/ 			return ;
/*1279*/ 		}
/*1279*/ 		Scanner_sym = Scanner_SearchKeyword(Scanner_s, Scanner_phplint_keywords);
/*1280*/ 		if( (Scanner_sym != 1) ){
/*1281*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"invalid PHPLint keyword `", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"' inside PHP code", (STRING *) 1));
/*1282*/ 			Scanner_sym = 1;
/*1284*/ 			return ;
/*1286*/ 		}
/*1288*/ 	}
/*1288*/ 	Scanner_low = str_tolower(Scanner_s);
/*1289*/ 	Scanner_sym = Scanner_SearchKeyword(Scanner_low, Scanner_php_keywords);
/*1290*/ 	if( (Scanner_sym != 1) ){
/*1291*/ 		Scanner_Error(m2runtime_concat_STRING(0, m2runtime_CHR(96), Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\56,\0,\0,\0)"': invalid identifier similar to the keyword `", Scanner_low, m2runtime_CHR(39), (STRING *) 1));
/*1295*/ 		return ;
/*1298*/ 	}
/*1298*/ 	Scanner_sym = Scanner_SearchKeyword(Scanner_low, Scanner_phplint_keywords);
/*1299*/ 	if( (Scanner_sym != 1) ){
/*1300*/ 		Scanner_Error(m2runtime_concat_STRING(0, m2runtime_CHR(96), Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\66,\0,\0,\0)"': invalid identifier similar to the PHPLint keyword `", Scanner_low, m2runtime_CHR(39), (STRING *) 1));
/*1301*/ 		Scanner_sym = 1;
/*1303*/ 		return ;
/*1306*/ 	}
/*1308*/ }


/*1315*/ STRING *
/*1315*/ Scanner_ParseQualifiedIdentifier(void)
/*1315*/ {
/*1317*/ 	void * Scanner_b = NULL;
/*1317*/ 	Scanner_ReadCh();
/*1318*/ 	if( Scanner_SkipSpaces() ){
/*1319*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"expected identifier after `\134'");
/*1321*/ 	}
/*1321*/ 	if( !Scanner_is_id_first_char(Scanner_c) ){
/*1322*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"expected identifier after `\134'");
/*1325*/ 	}
/*1325*/ 	do{
/*1325*/ 		Scanner_ParseKeyword();
/*1326*/ 		if( (Scanner_sym == 1) ){
/*1327*/ 			buffer_AddString((void *)&Scanner_b, m2runtime_CHR(92));
/*1328*/ 			buffer_AddString((void *)&Scanner_b, Scanner_s);
/*1330*/ 		} else {
/*1330*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"keyword used in qualified identifier");
/*1332*/ 		}
/*1332*/ 		if( Scanner_SkipSpaces() ){
/*1335*/ 			goto m2runtime_loop_1;
/*1335*/ 		}
/*1335*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0 ){
/*1336*/ 			Scanner_ReadCh();
/*1339*/ 		} else {
/*1340*/ 			goto m2runtime_loop_1;
/*1341*/ 		}
/*1341*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1341*/ 	return buffer_ToString(Scanner_b);
/*1345*/ }


/*1347*/ int
/*1347*/ Scanner_ParseNumber(void)
/*1347*/ {

/*1350*/ 	void
/*1350*/ 	Scanner_ParseFloat(void)
/*1350*/ 	{
/*1350*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(46)) == 0 ){
/*1351*/ 			buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1352*/ 			Scanner_ReadCh();
/*1353*/ 			if( !Scanner_is_digit(Scanner_c) ){
/*1354*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\70,\0,\0,\0)"literal float number: required digit after decimal point");
/*1356*/ 				return ;
/*1358*/ 			}
/*1358*/ 			do {
/*1358*/ 				buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1359*/ 				Scanner_ReadCh();
/*1360*/ 			} while( !( !Scanner_is_digit(Scanner_c) ));
/*1362*/ 		}
/*1362*/ 		if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(101)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(69)) == 0)) ){
/*1363*/ 			buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1364*/ 			Scanner_ReadCh();
/*1365*/ 			if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(43)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(45)) == 0)) ){
/*1366*/ 				buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1367*/ 				Scanner_ReadCh();
/*1369*/ 			}
/*1369*/ 			if( !Scanner_is_digit(Scanner_c) ){
/*1370*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"literal float number: required digit in exponent");
/*1373*/ 			}
/*1373*/ 			do {
/*1373*/ 				buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1374*/ 				Scanner_ReadCh();
/*1375*/ 			} while( !( !Scanner_is_digit(Scanner_c) ));
/*1377*/ 		}
/*1377*/ 		Scanner_s = buffer_ToString(Scanner_b);
/*1380*/ 	}

/*1382*/ 	int Scanner_n = 0;
/*1386*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) == 0 ){
/*1387*/ 		Scanner_ReadCh();
/*1388*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(120)) == 0 ){
/*1390*/ 			Scanner_ReadCh();
/*1391*/ 			if( !Scanner_is_hex(Scanner_c) ){
/*1392*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"invalid hexadecimal number");
/*1395*/ 			} else {
/*1395*/ 				do {
/*1395*/ 					Scanner_n = (((unsigned int) Scanner_n << 4) + Scanner_hex(Scanner_c));
/*1396*/ 					Scanner_ReadCh();
/*1397*/ 				} while( !( !Scanner_is_hex(Scanner_c) ));
/*1399*/ 			}
/*1399*/ 			Scanner_s = m2runtime_itos(Scanner_n);
/*1400*/ 			return 38;
/*1401*/ 		} else if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(55)) <= 0)) ){
/*1404*/ 			do {
/*1404*/ 				Scanner_n = ((8 * Scanner_n) + m2_stoi(Scanner_c));
/*1405*/ 				Scanner_ReadCh();
/*1406*/ 			} while( !( !(((m2runtime_strcmp(Scanner_c, m2runtime_CHR(48)) >= 0) && (m2runtime_strcmp(Scanner_c, m2runtime_CHR(55)) <= 0))) ));
/*1407*/ 			if( Scanner_is_digit(Scanner_c) ){
/*1408*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"invalid digit `", Scanner_c, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"' in octal number", (STRING *) 1));
/*1409*/ 				Scanner_ReadCh();
/*1411*/ 			}
/*1411*/ 			Scanner_s = m2runtime_itos(Scanner_n);
/*1412*/ 			return 38;
/*1413*/ 		} else if( Scanner_is_digit(Scanner_c) ){
/*1414*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"invalid digit `", Scanner_c, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\21,\0,\0,\0)"' in octal number", (STRING *) 1));
/*1415*/ 			Scanner_ReadCh();
/*1416*/ 			Scanner_s = m2runtime_CHR(48);
/*1417*/ 			return 38;
/*1418*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(46)) == 0 ){
/*1420*/ 			buffer_Empty((void *)&Scanner_b);
/*1421*/ 			buffer_AddString((void *)&Scanner_b, m2runtime_CHR(48));
/*1422*/ 			Scanner_ParseFloat();
/*1423*/ 			return 39;
/*1426*/ 		} else {
/*1426*/ 			Scanner_s = m2runtime_CHR(48);
/*1427*/ 			return 38;
/*1430*/ 		}
/*1430*/ 	} else {
/*1430*/ 		buffer_Empty((void *)&Scanner_b);
/*1432*/ 		do {
/*1432*/ 			buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1433*/ 			Scanner_ReadCh();
/*1434*/ 		} while( !( !Scanner_is_digit(Scanner_c) ));
/*1435*/ 		if( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(46)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(101)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(101)) == 0)) ){
/*1436*/ 			Scanner_ParseFloat();
/*1437*/ 			return 39;
/*1439*/ 		} else {
/*1439*/ 			Scanner_s = buffer_ToString(Scanner_b);
/*1440*/ 			return 38;
/*1443*/ 		}
/*1444*/ 	}
/*1444*/ 	m2runtime_missing_return(Scanner_0err_entry_get, 30);
/*1444*/ 	return 0;
/*1446*/ }


/*1447*/ void
/*1447*/ Scanner_ParseDoc(void)
/*1447*/ {
/*1449*/ 	int Scanner_line_start = 0;
/*1449*/ 	Scanner_line_start = Scanner_line_n;
/*1450*/ 	while( ((m2runtime_strcmp(Scanner_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(9)) == 0)) ){
/*1451*/ 		Scanner_ReadCh();
/*1453*/ 	}
/*1453*/ 	buffer_Empty((void *)&Scanner_b);
/*1455*/ 	do{
/*1455*/ 		if( Scanner_c == NULL ){
/*1456*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\45,\0,\0,\0)"unclosed DOC comment openend in line ", m2runtime_itos(Scanner_line_start), (STRING *) 1));
/*1459*/ 			goto m2runtime_loop_1;
/*1459*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(46)) == 0 ){
/*1460*/ 			Scanner_ReadCh();
/*1461*/ 			if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(42)) == 0 ){
/*1462*/ 				Scanner_ReadCh();
/*1463*/ 				if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(47)) == 0 ){
/*1464*/ 					Scanner_ReadCh();
/*1467*/ 					goto m2runtime_loop_1;
/*1467*/ 				} else {
/*1467*/ 					buffer_AddString((void *)&Scanner_b, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)".*");
/*1470*/ 				}
/*1470*/ 			} else {
/*1470*/ 				buffer_AddString((void *)&Scanner_b, m2runtime_CHR(46));
/*1472*/ 			}
/*1472*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(42)) == 0 ){
/*1473*/ 			Scanner_ReadCh();
/*1474*/ 			if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(47)) == 0 ){
/*1475*/ 				Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"missing `.' in closing `.*/'");
/*1476*/ 				Scanner_ReadCh();
/*1479*/ 				goto m2runtime_loop_1;
/*1479*/ 			} else {
/*1479*/ 				buffer_AddString((void *)&Scanner_b, m2runtime_CHR(42));
/*1482*/ 			}
/*1482*/ 		} else {
/*1482*/ 			buffer_AddString((void *)&Scanner_b, Scanner_c);
/*1483*/ 			Scanner_ReadCh();
/*1486*/ 		}
/*1486*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1486*/ 	Scanner_s = buffer_ToString(Scanner_b);
/*1490*/ }


/*1492*/ void
/*1492*/ Scanner_ParseVarName(void)
/*1492*/ {
/*1492*/ 	Scanner_ReadCh();
/*1493*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(36)) == 0 ){
/*1494*/ 		Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\110,\0,\0,\0)"unsupported variable-variable feature $$var -- trying to continue anyway");
/*1496*/ 		do {
/*1496*/ 			Scanner_ReadCh();
/*1497*/ 		} while( !( m2runtime_strcmp(Scanner_c, m2runtime_CHR(36)) != 0 ));
/*1499*/ 	}
/*1499*/ 	if( !Scanner_is_id_first_char(Scanner_c) ){
/*1500*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"missing variable name after `$'");
/*1502*/ 	}
/*1502*/ 	Scanner_ParseKeyword();
/*1503*/ 	if( (Scanner_sym != 1) ){
/*1504*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the name `$", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"' is a keyword.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)" This is deprecated by PHP and forbidden by PHPLint.", (STRING *) 1));
/*1508*/ 	}
/*1510*/ }


/*1519*/ int
/*1519*/ Scanner_ParseXCode(void)
/*1519*/ {
/*1521*/ 	STRING * Scanner_q = NULL;
/*1521*/ 	if( Scanner_SkipSpaces() ){
/*1522*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"unexpected closing tag inside meta-code");
/*1525*/ 	}
/*1525*/ 	if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(40)) == 0 ){
/*1526*/ 		Scanner_sym = 157;
/*1527*/ 		Scanner_ReadCh();
/*1528*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(41)) == 0 ){
/*1529*/ 		Scanner_sym = 158;
/*1530*/ 		Scanner_ReadCh();
/*1531*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(91)) == 0 ){
/*1532*/ 		Scanner_sym = 159;
/*1533*/ 		Scanner_ReadCh();
/*1534*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(93)) == 0 ){
/*1535*/ 		Scanner_sym = 160;
/*1536*/ 		Scanner_ReadCh();
/*1537*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(123)) == 0 ){
/*1538*/ 		Scanner_sym = 161;
/*1539*/ 		Scanner_ReadCh();
/*1540*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(125)) == 0 ){
/*1541*/ 		Scanner_sym = 162;
/*1542*/ 		Scanner_ReadCh();
/*1543*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(38)) == 0 ){
/*1544*/ 		Scanner_sym = 155;
/*1545*/ 		Scanner_ReadCh();
/*1546*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1547*/ 		Scanner_sym = 135;
/*1548*/ 		Scanner_ReadCh();
/*1549*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(36)) == 0 ){
/*1550*/ 		Scanner_ParseVarName();
/*1551*/ 		Scanner_sym = 154;
/*1552*/ 	} else if( Scanner_is_id_first_char(Scanner_c) ){
/*1553*/ 		Scanner_ParseKeyword();
/*1554*/ 		if( (Scanner_sym == 1) ){
/*1555*/ 			if( m2runtime_strcmp(Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"DOC") == 0 ){
/*1556*/ 				Scanner_ParseDoc();
/*1557*/ 				Scanner_code = 1;
/*1558*/ 				Scanner_sym = 183;
/*1560*/ 			} else {
/*1560*/ 				if( Scanner_SkipSpaces() ){
/*1561*/ 					Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"unexpected closing tag inside meta-code");
/*1563*/ 				}
/*1563*/ 				if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0 ){
/*1564*/ 					Scanner_q = Scanner_s;
/*1565*/ 					Scanner_s = m2runtime_concat_STRING(0, Scanner_q, Scanner_ParseQualifiedIdentifier(), (STRING *) 1);
/*1567*/ 				}
/*1567*/ 				Scanner_sym = 153;
/*1570*/ 			}
/*1570*/ 		}
/*1570*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0 ){
/*1571*/ 		Scanner_s = Scanner_ParseQualifiedIdentifier();
/*1572*/ 		Scanner_sym = 153;
/*1573*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(46)) == 0 ){
/*1574*/ 		Scanner_ReadCh();
/*1575*/ 		if( ((Scanner_c == NULL) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(42)) != 0)) ){
/*1576*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"invalid syntax in extended code");
/*1577*/ 			return TRUE;
/*1579*/ 		}
/*1579*/ 		Scanner_ReadCh();
/*1580*/ 		if( ((Scanner_c == NULL) || (m2runtime_strcmp(Scanner_c, m2runtime_CHR(47)) != 0)) ){
/*1581*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"invalid syntax in extended code");
/*1582*/ 			return TRUE;
/*1584*/ 		}
/*1584*/ 		Scanner_ReadCh();
/*1585*/ 		Scanner_code = 1;
/*1586*/ 		return TRUE;
/*1587*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(44)) == 0 ){
/*1588*/ 		Scanner_ReadCh();
/*1589*/ 		Scanner_sym = 134;
/*1590*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(39)) == 0 ){
/*1591*/ 		Scanner_s = Scanner_ParseSingleQuotedString();
/*1592*/ 		Scanner_sym = 131;
/*1593*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(59)) == 0 ){
/*1594*/ 		Scanner_ReadCh();
/*1595*/ 		Scanner_sym = 132;
/*1596*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(58)) == 0 ){
/*1597*/ 		Scanner_ReadCh();
/*1598*/ 		Scanner_sym = 133;
/*1599*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(42)) == 0 ){
/*1600*/ 		Scanner_ReadCh();
/*1601*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(47)) == 0 ){
/*1602*/ 			Scanner_Error((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\50,\0,\0,\0)"expected `.*/', found `*/' (missing `.')");
/*1603*/ 			Scanner_ReadCh();
/*1604*/ 			Scanner_code = 1;
/*1605*/ 			return TRUE;
/*1607*/ 		} else {
/*1607*/ 			Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"unexpected char `*' in extended code");
/*1609*/ 		}
/*1609*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(60)) == 0 ){
/*1610*/ 		Scanner_ReadCh();
/*1611*/ 		Scanner_sym = 181;
/*1612*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(62)) == 0 ){
/*1613*/ 		Scanner_ReadCh();
/*1614*/ 		Scanner_sym = 182;
/*1616*/ 	} else {
/*1616*/ 		Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"unexpected char ", Scanner_ReportChar(m2runtime_ASC(Scanner_c)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)" in extended code - ignore", (STRING *) 1));
/*1617*/ 		Scanner_ReadCh();
/*1619*/ 	}
/*1619*/ 	return FALSE;
/*1623*/ }


/*1630*/ int
/*1630*/ Scanner_ParseCode(void)
/*1630*/ {
/*1632*/ 	STRING * Scanner_q = NULL;
/*1632*/ 	if( Scanner_SkipSpaces() ){
/*1634*/ 		Scanner_code = 0;
/*1635*/ 		Scanner_sym = 6;
/*1636*/ 		return FALSE;
/*1639*/ 	}
/*1639*/ 	if( Scanner_is_id_first_char(Scanner_c) ){
/*1640*/ 		Scanner_ParseKeyword();
/*1641*/ 		if( (Scanner_sym == 1) ){
/*1642*/ 			if( Scanner_SkipSpaces() ){
/*1643*/ 				Scanner_sym = 29;
/*1644*/ 			} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0 ){
/*1645*/ 				Scanner_q = Scanner_s;
/*1646*/ 				Scanner_s = m2runtime_concat_STRING(0, Scanner_q, Scanner_ParseQualifiedIdentifier(), (STRING *) 1);
/*1648*/ 			}
/*1648*/ 			Scanner_sym = 29;
/*1651*/ 		}
/*1651*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(92)) == 0 ){
/*1652*/ 		Scanner_s = Scanner_ParseQualifiedIdentifier();
/*1653*/ 		Scanner_sym = 29;
/*1655*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(36)) == 0 ){
/*1656*/ 		Scanner_ParseVarName();
/*1657*/ 		Scanner_sym = 20;
/*1659*/ 	} else if( Scanner_is_digit(Scanner_c) ){
/*1660*/ 		Scanner_sym = Scanner_ParseNumber();
/*1662*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(34)) == 0 ){
/*1663*/ 		Scanner_ReadCh();
/*1664*/ 		return Scanner_ParseDoubleQuotedString();
/*1666*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(39)) == 0 ){
/*1667*/ 		Scanner_s = Scanner_ParseSingleQuotedString();
/*1668*/ 		Scanner_sym = 33;
/*1670*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(96)) == 0 ){
/*1671*/ 		Scanner_Fatal((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\77,\0,\0,\0)"unimplemented execution operator \042`\042. Use shell_exec() instead.");
/*1672*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(64)) == 0 ){
/*1672*/ 		Scanner_sym = 59;
/*1672*/ 		Scanner_ReadCh();
/*1673*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(123)) == 0 ){
/*1673*/ 		Scanner_sym = 10;
/*1673*/ 		Scanner_ReadCh();
/*1674*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(125)) == 0 ){
/*1674*/ 		Scanner_sym = 11;
/*1674*/ 		Scanner_ReadCh();
/*1675*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(91)) == 0 ){
/*1675*/ 		Scanner_sym = 14;
/*1675*/ 		Scanner_ReadCh();
/*1676*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(93)) == 0 ){
/*1676*/ 		Scanner_sym = 15;
/*1676*/ 		Scanner_ReadCh();
/*1677*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(40)) == 0 ){
/*1677*/ 		Scanner_sym = 12;
/*1677*/ 		Scanner_ReadCh();
/*1678*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(41)) == 0 ){
/*1678*/ 		Scanner_sym = 13;
/*1678*/ 		Scanner_ReadCh();
/*1679*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(44)) == 0 ){
/*1679*/ 		Scanner_sym = 16;
/*1679*/ 		Scanner_ReadCh();
/*1680*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(59)) == 0 ){
/*1680*/ 		Scanner_sym = 17;
/*1680*/ 		Scanner_ReadCh();
/*1681*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(126)) == 0 ){
/*1681*/ 		Scanner_sym = 90;
/*1681*/ 		Scanner_ReadCh();
/*1683*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(58)) == 0 ){
/*1684*/ 		Scanner_ReadCh();
/*1685*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(58)) == 0 ){
/*1686*/ 			Scanner_ReadCh();
/*1687*/ 			Scanner_sym = 19;
/*1689*/ 		} else {
/*1689*/ 			Scanner_sym = 18;
/*1692*/ 		}
/*1692*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(63)) == 0 ){
/*1693*/ 		Scanner_ReadCh();
/*1694*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(62)) == 0 ){
/*1695*/ 			Scanner_SkipNewLineAfterCloseTag();
/*1696*/ 			Scanner_code = 0;
/*1697*/ 			Scanner_sym = 6;
/*1699*/ 		} else {
/*1699*/ 			Scanner_sym = 30;
/*1702*/ 		}
/*1702*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(43)) == 0 ){
/*1703*/ 		Scanner_ReadCh();
/*1704*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(43)) == 0 ){
/*1705*/ 			Scanner_ReadCh();
/*1706*/ 			Scanner_sym = 52;
/*1707*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1708*/ 			Scanner_ReadCh();
/*1709*/ 			Scanner_sym = 76;
/*1711*/ 		} else {
/*1711*/ 			Scanner_sym = 40;
/*1714*/ 		}
/*1714*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(45)) == 0 ){
/*1715*/ 		Scanner_ReadCh();
/*1716*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(62)) == 0 ){
/*1717*/ 			Scanner_ReadCh();
/*1718*/ 			Scanner_sym = 61;
/*1719*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(45)) == 0 ){
/*1720*/ 			Scanner_ReadCh();
/*1721*/ 			Scanner_sym = 53;
/*1722*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1723*/ 			Scanner_ReadCh();
/*1724*/ 			Scanner_sym = 77;
/*1726*/ 		} else {
/*1726*/ 			Scanner_sym = 41;
/*1729*/ 		}
/*1729*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(42)) == 0 ){
/*1730*/ 		Scanner_ReadCh();
/*1731*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1732*/ 			Scanner_ReadCh();
/*1733*/ 			Scanner_sym = 78;
/*1735*/ 		} else {
/*1735*/ 			Scanner_sym = 42;
/*1738*/ 		}
/*1738*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(47)) == 0 ){
/*1739*/ 		Scanner_ReadCh();
/*1740*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(42)) == 0 ){
/*1741*/ 			Scanner_ReadCh();
/*1742*/ 			if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(46)) == 0 ){
/*1744*/ 				Scanner_code = 2;
/*1745*/ 				Scanner_ReadCh();
/*1746*/ 				return TRUE;
/*1748*/ 			} else {
/*1748*/ 				Scanner_SkipMultilineComment();
/*1749*/ 				if( (((m2runtime_length(Scanner_s) > 5)) && (m2runtime_strcmp(m2runtime_substr(Scanner_s, 0, 3, 1, Scanner_0err_entry_get, 31), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"/**") == 0)) ){
/*1751*/ 					Scanner_sym = 184;
/*1754*/ 				} else {
/*1754*/ 					return TRUE;
/*1757*/ 				}
/*1757*/ 			}
/*1757*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(47)) == 0 ){
/*1758*/ 			if( Scanner_SkipSingleLineComment() ){
/*1760*/ 				Scanner_code = 0;
/*1761*/ 				Scanner_sym = 6;
/*1762*/ 				return FALSE;
/*1764*/ 			}
/*1764*/ 			return TRUE;
/*1765*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1766*/ 			Scanner_sym = 79;
/*1767*/ 			Scanner_ReadCh();
/*1769*/ 		} else {
/*1769*/ 			Scanner_sym = 43;
/*1772*/ 		}
/*1772*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(37)) == 0 ){
/*1773*/ 		Scanner_ReadCh();
/*1774*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1775*/ 			Scanner_sym = 80;
/*1776*/ 			Scanner_ReadCh();
/*1778*/ 		} else {
/*1778*/ 			Scanner_sym = 74;
/*1781*/ 		}
/*1781*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1782*/ 		Scanner_ReadCh();
/*1783*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1784*/ 			Scanner_ReadCh();
/*1785*/ 			if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1786*/ 				Scanner_ReadCh();
/*1787*/ 				Scanner_sym = 45;
/*1789*/ 			} else {
/*1789*/ 				Scanner_sym = 44;
/*1791*/ 			}
/*1791*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(62)) == 0 ){
/*1792*/ 			Scanner_ReadCh();
/*1793*/ 			Scanner_sym = 32;
/*1795*/ 		} else {
/*1795*/ 			Scanner_sym = 31;
/*1798*/ 		}
/*1798*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(60)) == 0 ){
/*1799*/ 		Scanner_ReadCh();
/*1800*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1801*/ 			Scanner_sym = 51;
/*1802*/ 			Scanner_ReadCh();
/*1803*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(62)) == 0 ){
/*1804*/ 			Scanner_sym = 46;
/*1805*/ 			Scanner_ReadCh();
/*1806*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(60)) == 0 ){
/*1807*/ 			Scanner_ReadCh();
/*1808*/ 			if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1809*/ 				Scanner_ReadCh();
/*1810*/ 				Scanner_sym = 84;
/*1811*/ 			} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(60)) == 0 ){
/*1812*/ 				Scanner_ReadCh();
/*1813*/ 				return Scanner_ParseHereAndNowDoc();
/*1815*/ 			} else {
/*1815*/ 				Scanner_sym = 86;
/*1818*/ 			}
/*1818*/ 		} else {
/*1818*/ 			Scanner_sym = 50;
/*1821*/ 		}
/*1821*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(62)) == 0 ){
/*1822*/ 		Scanner_ReadCh();
/*1823*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1824*/ 			Scanner_sym = 49;
/*1825*/ 			Scanner_ReadCh();
/*1826*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(62)) == 0 ){
/*1827*/ 			Scanner_ReadCh();
/*1828*/ 			if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1829*/ 				Scanner_ReadCh();
/*1830*/ 				Scanner_sym = 85;
/*1832*/ 			} else {
/*1832*/ 				Scanner_sym = 87;
/*1835*/ 			}
/*1835*/ 		} else {
/*1835*/ 			Scanner_sym = 48;
/*1838*/ 		}
/*1838*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(33)) == 0 ){
/*1839*/ 		Scanner_ReadCh();
/*1840*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1841*/ 			Scanner_ReadCh();
/*1842*/ 			if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1843*/ 				Scanner_ReadCh();
/*1844*/ 				Scanner_sym = 47;
/*1846*/ 			} else {
/*1846*/ 				Scanner_sym = 46;
/*1849*/ 			}
/*1849*/ 		} else {
/*1849*/ 			Scanner_sym = 54;
/*1852*/ 		}
/*1852*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(124)) == 0 ){
/*1853*/ 		Scanner_ReadCh();
/*1854*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(124)) == 0 ){
/*1855*/ 			Scanner_ReadCh();
/*1856*/ 			Scanner_sym = 55;
/*1857*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1858*/ 			Scanner_sym = 82;
/*1859*/ 			Scanner_ReadCh();
/*1861*/ 		} else {
/*1861*/ 			Scanner_sym = 72;
/*1864*/ 		}
/*1864*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(38)) == 0 ){
/*1865*/ 		Scanner_ReadCh();
/*1866*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(38)) == 0 ){
/*1867*/ 			Scanner_ReadCh();
/*1868*/ 			Scanner_sym = 57;
/*1869*/ 		} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1870*/ 			Scanner_sym = 81;
/*1871*/ 			Scanner_ReadCh();
/*1873*/ 		} else {
/*1873*/ 			Scanner_sym = 73;
/*1876*/ 		}
/*1876*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(46)) == 0 ){
/*1877*/ 		Scanner_ReadCh();
/*1878*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1879*/ 			Scanner_ReadCh();
/*1880*/ 			Scanner_sym = 75;
/*1882*/ 		} else {
/*1882*/ 			Scanner_sym = 60;
/*1885*/ 		}
/*1885*/ 	} else if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(94)) == 0 ){
/*1886*/ 		Scanner_ReadCh();
/*1887*/ 		if( m2runtime_strcmp(Scanner_c, m2runtime_CHR(61)) == 0 ){
/*1888*/ 			Scanner_sym = 83;
/*1889*/ 			Scanner_ReadCh();
/*1891*/ 		} else {
/*1891*/ 			Scanner_sym = 88;
/*1894*/ 		}
/*1894*/ 	} else if( Scanner_c == NULL ){
/*1895*/ 		Scanner_sym = 0;
/*1898*/ 	} else {
/*1898*/ 		Scanner_Fatal(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"unexpected character ", Scanner_ReportChar(m2runtime_ASC(Scanner_c)), (STRING *) 1));
/*1901*/ 	}
/*1901*/ 	return FALSE;
/*1905*/ }


/*1906*/ void
/*1906*/ Scanner_ReadSym(void)
/*1906*/ {
/*1908*/ 	int Scanner_new_sym_found = 0;
/*1909*/ 	do {
/*1910*/ 		Scanner_new_sym_found = FALSE;
/*1912*/ 		switch(Scanner_code){

/*1914*/ 		case 0:
/*1915*/ 		Scanner_ParseText();
/*1916*/ 		Scanner_new_sym_found = FALSE;
/*1918*/ 		break;

/*1918*/ 		case 1:
/*1919*/ 		Scanner_new_sym_found = Scanner_ParseCode();
/*1921*/ 		break;

/*1921*/ 		case 2:
/*1922*/ 		Scanner_new_sym_found = Scanner_ParseXCode();
/*1924*/ 		break;

/*1924*/ 		case 3:
/*1931*/ 		Scanner_ParseKeyword();
/*1932*/ 		if( (Scanner_sym != 1) ){
/*1933*/ 			Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"the name `$", Scanner_s, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"' is a keyword.", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)" This is deprecated by PHP and forbidden by PHPLint.", (STRING *) 1));
/*1936*/ 		}
/*1936*/ 		Scanner_sym = 35;
/*1937*/ 		Scanner_code = 4;
/*1939*/ 		break;

/*1939*/ 		case 4:
/*1946*/ 		Scanner_new_sym_found = Scanner_ParseDoubleQuotedString();
/*1949*/ 		break;

/*1949*/ 		default: m2runtime_missing_case_in_switch(Scanner_0err_entry_get, 32);
/*1950*/ 		}
/*1950*/ 	} while( !( !Scanner_new_sym_found ));
/*1952*/ 	if( Globals_DEBUG ){
/*1953*/ 		m2_print(m2runtime_CHR(91));
/*1954*/ 		m2_print(Tokens_CodeToName(Scanner_sym));
/*1955*/ 		m2_print((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"]\012");
/*1958*/ 	}
/*1960*/ }


/*1962*/ int
/*1962*/ Scanner_Open(STRING *Scanner_abs_fn)
/*1962*/ {
/*1962*/ 	Scanner_fn = Scanner_abs_fn;
/*1963*/ 	m2runtime_ERROR_CODE = 0;
/*1963*/ 	io_Open(1, (void *)&Scanner_fd, Scanner_fn, m2runtime_CHR(114));
/*1965*/ 	switch( m2runtime_ERROR_CODE ){

/*1965*/ 	case 0:  break;
/*1965*/ 	default:
/*1965*/ 		Scanner_Error(m2runtime_ERROR_MESSAGE);
/*1966*/ 		return FALSE;
/*1969*/ 	}
/*1969*/ 	if( Scanner_print_source ){
/*1970*/ 		m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"\012BEGIN parsing of ", Scanner_fmt_fn(Scanner_abs_fn), m2runtime_CHR(10), (STRING *) 1));
/*1973*/ 	}
/*1973*/ 	Scanner_code = 0;
/*1974*/ 	m2runtime_ERROR_CODE = 0;
/*1974*/ 	Scanner_line = io_ReadLine(1, Scanner_fd);
/*1975*/ 	switch( m2runtime_ERROR_CODE ){

/*1975*/ 	case 0:  break;
/*1975*/ 	default:
/*1975*/ 		m2runtime_HALT(Scanner_0err_entry_get, 33, m2runtime_ERROR_MESSAGE);
/*1975*/ 	}
/*1975*/ 	Scanner_line_n = 1;
/*1976*/ 	Scanner_line_idx = 0;
/*1977*/ 	Scanner_line_pos = 0;
/*1978*/ 	Scanner_c = NULL;
/*1980*/ 	if( Scanner_print_source ){
/*1981*/ 		Scanner_PrintLineSource();
/*1984*/ 	}
/*1984*/ 	Scanner_ReadCh();
/*1985*/ 	Scanner_ReadSym();
/*1986*/ 	return TRUE;
/*1990*/ }


/*1991*/ RECORD *
/*1991*/ Scanner_Suspend(void)
/*1991*/ {
/*1993*/ 	RECORD * Scanner_r = NULL;
/*1993*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 5 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 34) = Scanner_code;
/*1994*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 5 * sizeof(void*) + 7 * sizeof(int), Scanner_0err_entry_get, 35) = Scanner_sym;
/*1995*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 1 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 36) = Scanner_fn;
/*1996*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 2 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 37) = Scanner_fd;
/*1997*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 3 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 38) = Scanner_line;
/*1998*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 5 * sizeof(void*) + 8 * sizeof(int), Scanner_0err_entry_get, 39) = Scanner_line_n;
/*1999*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 5 * sizeof(void*) + 9 * sizeof(int), Scanner_0err_entry_get, 40) = Scanner_line_idx;
/*2000*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 5 * sizeof(void*) + 10 * sizeof(int), Scanner_0err_entry_get, 41) = Scanner_line_pos;
/*2001*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 4 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 42) = Scanner_c;
/*2002*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&Scanner_r, 5 * sizeof(void*) + 11 * sizeof(int), 5, 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 43) = Scanner_s;
/*2003*/ 	return Scanner_r;
/*2007*/ }


/*2009*/ void
/*2009*/ Scanner_Resume(RECORD *Scanner_r)
/*2009*/ {
/*2009*/ 	Scanner_code =  *(int *)m2runtime_dereference_rhs_RECORD(Scanner_r, 5 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 44);
/*2010*/ 	Scanner_sym =  *(int *)m2runtime_dereference_rhs_RECORD(Scanner_r, 5 * sizeof(void*) + 7 * sizeof(int), Scanner_0err_entry_get, 45);
/*2011*/ 	Scanner_fn = (STRING *)m2runtime_dereference_rhs_RECORD(Scanner_r, 1 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 46);
/*2012*/ 	Scanner_fd = (void *)m2runtime_dereference_rhs_RECORD(Scanner_r, 2 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 47);
/*2013*/ 	Scanner_line = (STRING *)m2runtime_dereference_rhs_RECORD(Scanner_r, 3 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 48);
/*2014*/ 	Scanner_line_n =  *(int *)m2runtime_dereference_rhs_RECORD(Scanner_r, 5 * sizeof(void*) + 8 * sizeof(int), Scanner_0err_entry_get, 49);
/*2015*/ 	Scanner_line_idx =  *(int *)m2runtime_dereference_rhs_RECORD(Scanner_r, 5 * sizeof(void*) + 9 * sizeof(int), Scanner_0err_entry_get, 50);
/*2016*/ 	Scanner_line_pos =  *(int *)m2runtime_dereference_rhs_RECORD(Scanner_r, 5 * sizeof(void*) + 10 * sizeof(int), Scanner_0err_entry_get, 51);
/*2017*/ 	Scanner_c = (STRING *)m2runtime_dereference_rhs_RECORD(Scanner_r, 4 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 52);
/*2018*/ 	Scanner_s = (STRING *)m2runtime_dereference_rhs_RECORD(Scanner_r, 0 * sizeof(void*) + 2 * sizeof(int), Scanner_0err_entry_get, 53);
/*2022*/ }


/*2024*/ void
/*2024*/ Scanner_Close(void)
/*2024*/ {
/*2024*/ 	if( Scanner_print_source ){
/*2025*/ 		m2_print(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"END parsing of ", Scanner_fmt_fn(Scanner_fn), m2runtime_CHR(10), (STRING *) 1));
/*2027*/ 	}
/*2027*/ 	m2runtime_ERROR_CODE = 0;
/*2027*/ 	io_Close(1, (void *)&Scanner_fd);
/*2028*/ 	switch( m2runtime_ERROR_CODE ){

/*2028*/ 	case 0:  break;
/*2028*/ 	default:
/*2028*/ 		m2runtime_HALT(Scanner_0err_entry_get, 54, m2runtime_ERROR_MESSAGE);
/*2028*/ 	}
/*2028*/ 	Scanner_fn = NULL;
/*2033*/ }


char * Scanner_0func[] = {
    "mn",
    "fmt_fn",
    "reference",
    "PrintWhere",
    "ReadCh",
    "FollowingCharsMatch",
    "SearchKeyword",
    "SkipSingleLineComment",
    "ReportChar",
    "is_id_first_char",
    "is_id_char",
    "hex",
    "ParseSingleQuotedString",
    "ParseEscapeCode",
    "ParseDoubleQuotedString",
    "ParseHereAndNowDoc",
    "ParseNumber",
    "ParseCode",
    "ReadSym",
    "Open",
    "Suspend",
    "Resume",
    "Close"
};

int Scanner_0err_entry[] = {
    0 /* mn */, 108,
    0 /* mn */, 108,
    1 /* fmt_fn */, 130,
    1 /* fmt_fn */, 131,
    2 /* reference */, 144,
    2 /* reference */, 145,
    2 /* reference */, 147,
    2 /* reference */, 147,
    2 /* reference */, 149,
    3 /* PrintWhere */, 164,
    3 /* PrintWhere */, 165,
    3 /* PrintWhere */, 167,
    4 /* ReadCh */, 304,
    4 /* ReadCh */, 310,
    4 /* ReadCh */, 316,
    5 /* FollowingCharsMatch */, 335,
    6 /* SearchKeyword */, 366,
    6 /* SearchKeyword */, 366,
    6 /* SearchKeyword */, 372,
    6 /* SearchKeyword */, 372,
    6 /* SearchKeyword */, 382,
    7 /* SkipSingleLineComment */, 629,
    8 /* ReportChar */, 708,
    9 /* is_id_first_char */, 749,
    10 /* is_id_char */, 766,
    11 /* hex */, 792,
    12 /* ParseSingleQuotedString */, 904,
    13 /* ParseEscapeCode */, 982,
    14 /* ParseDoubleQuotedString */, 1154,
    15 /* ParseHereAndNowDoc */, 1233,
    16 /* ParseNumber */, 1443,
    17 /* ParseCode */, 1749,
    18 /* ReadSym */, 1948,
    19 /* Open */, 1974,
    20 /* Suspend */, 1993,
    20 /* Suspend */, 1994,
    20 /* Suspend */, 1995,
    20 /* Suspend */, 1996,
    20 /* Suspend */, 1997,
    20 /* Suspend */, 1998,
    20 /* Suspend */, 1999,
    20 /* Suspend */, 2000,
    20 /* Suspend */, 2001,
    20 /* Suspend */, 2002,
    21 /* Resume */, 2009,
    21 /* Resume */, 2010,
    21 /* Resume */, 2011,
    21 /* Resume */, 2012,
    21 /* Resume */, 2013,
    21 /* Resume */, 2014,
    21 /* Resume */, 2015,
    21 /* Resume */, 2016,
    21 /* Resume */, 2017,
    21 /* Resume */, 2018,
    22 /* Close */, 2027
};

void Scanner_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "Scanner";
    *f = Scanner_0func[ Scanner_0err_entry[2*i] ];
    *l = Scanner_0err_entry[2*i + 1];
}
