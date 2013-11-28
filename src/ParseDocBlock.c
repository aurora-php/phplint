/* IMPLEMENTATION MODULE ParseDocBlock */
#define M2_IMPORT_ParseDocBlock

#ifndef M2_IMPORT_Types
#    include "Types.c"
#endif
/* 63*/ int ParseDocBlock_parse_phpdoc = 0;

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_Globals
#    include "Globals.c"
#endif

#ifndef M2_IMPORT_Classes
#    include "Classes.c"
#endif

#ifndef M2_IMPORT_Search
#    include "Search.c"
#endif

#ifndef M2_IMPORT_Scanner
#    include "Scanner.c"
#endif

#ifndef M2_IMPORT_buffer
#    include "buffer.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

void ParseDocBlock_0err_entry_get(int i, char **m, char **f, int *l);
/* 37*/ RECORD * ParseDocBlock_pdb = NULL;
/* 38*/ STRING * ParseDocBlock_in = NULL;
/* 39*/ int ParseDocBlock_pos = 0;
/* 40*/ int ParseDocBlock_line_n = 0;
/* 41*/ int ParseDocBlock_len = 0;
/* 43*/ STRING * ParseDocBlock_c = NULL;
/* 44*/ STRING * ParseDocBlock_return_descr = NULL;
/* 46*/ void * ParseDocBlock_descr = NULL;
/* 50*/ RECORD * ParseDocBlock_template = NULL;
/* 54*/ RECORD * ParseDocBlock_template_where = NULL;
/* 60*/ ARRAY * ParseDocBlock_types = NULL;

/* 62*/ RECORD *
/* 62*/ ParseDocBlock_Suspend(void)
/* 62*/ {
/* 64*/ 	RECORD * ParseDocBlock_status = NULL;
/* 64*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 0) = ParseDocBlock_pdb;
/* 64*/ 	ParseDocBlock_pdb = NULL;
/* 65*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 1 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 1) = ParseDocBlock_in;
/* 66*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 7 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 2) = ParseDocBlock_pos;
/* 67*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 7 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 3) = ParseDocBlock_line_n;
/* 68*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 7 * sizeof(void*) + 4 * sizeof(int), ParseDocBlock_0err_entry_get, 4) = ParseDocBlock_len;
/* 69*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 2 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 5) = ParseDocBlock_c;
/* 70*/ 	*(STRING **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 3 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 6) = ParseDocBlock_return_descr;
/* 71*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 4 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 7) = ParseDocBlock_descr;
/* 71*/ 	ParseDocBlock_descr = NULL;
/* 72*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 8) = ParseDocBlock_template;
/* 72*/ 	ParseDocBlock_template = NULL;
/* 73*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_status, 7 * sizeof(void*) + 5 * sizeof(int), 7, 6 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 9) = ParseDocBlock_template_where;
/* 73*/ 	ParseDocBlock_template_where = NULL;
/* 74*/ 	return ParseDocBlock_status;
/* 78*/ }


/* 80*/ void
/* 80*/ ParseDocBlock_Resume(RECORD *ParseDocBlock_status)
/* 80*/ {
/* 80*/ 	if( ParseDocBlock_status == NULL ){
/* 81*/ 		ParseDocBlock_pdb = NULL;
/* 83*/ 		return ;
/* 84*/ 	}
/* 84*/ 	ParseDocBlock_pdb = (RECORD *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 10);
/* 85*/ 	ParseDocBlock_in = (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 1 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 11);
/* 86*/ 	ParseDocBlock_pos =  *(int *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 7 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 12);
/* 87*/ 	ParseDocBlock_line_n =  *(int *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 7 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 13);
/* 88*/ 	ParseDocBlock_len =  *(int *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 7 * sizeof(void*) + 4 * sizeof(int), ParseDocBlock_0err_entry_get, 14);
/* 89*/ 	ParseDocBlock_c = (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 2 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 15);
/* 90*/ 	ParseDocBlock_return_descr = (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 3 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 16);
/* 91*/ 	ParseDocBlock_descr = (void *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 4 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 17);
/* 92*/ 	ParseDocBlock_template = (RECORD *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 18);
/* 93*/ 	ParseDocBlock_template_where = (RECORD *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_status, 6 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 19);
/* 97*/ }


/* 99*/ int
/* 99*/ ParseDocBlock_isLWSP(STRING *ParseDocBlock_c)
/* 99*/ {
/* 99*/ 	return ((m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(9)) == 0));
/*103*/ }


/*105*/ int
/*105*/ ParseDocBlock_isBlank(STRING *ParseDocBlock_c)
/*105*/ {
/*105*/ 	return ((m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(9)) == 0) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) == 0));
/*109*/ }


/*114*/ STRING *
/*114*/ ParseDocBlock_trim(STRING *ParseDocBlock_s)
/*114*/ {
/*116*/ 	int ParseDocBlock_i2 = 0;
/*116*/ 	int ParseDocBlock_i1 = 0;
/*116*/ 	if( ParseDocBlock_s == NULL ){
/*117*/ 		return NULL;
/*119*/ 	}
/*119*/ 	ParseDocBlock_i1 = 0;
/*120*/ 	while( (((ParseDocBlock_i1 < m2runtime_length(ParseDocBlock_s))) && ParseDocBlock_isBlank(m2runtime_substr(ParseDocBlock_s, ParseDocBlock_i1, 0, 0, ParseDocBlock_0err_entry_get, 20))) ){
/*121*/ 		m2_inc(&ParseDocBlock_i1, 1);
/*123*/ 	}
/*123*/ 	ParseDocBlock_i2 = m2runtime_length(ParseDocBlock_s);
/*124*/ 	while( (((ParseDocBlock_i2 > ParseDocBlock_i1)) && ParseDocBlock_isBlank(m2runtime_substr(ParseDocBlock_s, (ParseDocBlock_i2 - 1), 0, 0, ParseDocBlock_0err_entry_get, 21))) ){
/*125*/ 		m2_inc(&ParseDocBlock_i2, -1);
/*127*/ 	}
/*127*/ 	return m2runtime_substr(ParseDocBlock_s, ParseDocBlock_i1, ParseDocBlock_i2, 1, ParseDocBlock_0err_entry_get, 22);
/*131*/ }


/*140*/ void
/*140*/ ParseDocBlock_readCh(void)
/*140*/ {

/*148*/ 	void
/*148*/ 	ParseDocBlock_lowLevelReadCh(void)
/*148*/ 	{
/*148*/ 		if( ParseDocBlock_c == NULL ){
/*149*/ 			m2runtime_HALT(ParseDocBlock_0err_entry_get, 23, NULL);
/*151*/ 		}
/*151*/ 		if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) == 0 ){
/*152*/ 			m2_inc(&ParseDocBlock_line_n, 1);
/*154*/ 		}
/*154*/ 		if( (ParseDocBlock_pos >= ParseDocBlock_len) ){
/*155*/ 			ParseDocBlock_c = NULL;
/*157*/ 			return ;
/*158*/ 		}
/*158*/ 		ParseDocBlock_c = m2runtime_substr(ParseDocBlock_in, ParseDocBlock_pos, 0, 0, ParseDocBlock_0err_entry_get, 24);
/*159*/ 		m2_inc(&ParseDocBlock_pos, 1);
/*160*/ 		if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(13)) == 0 ){
/*162*/ 			if( (((ParseDocBlock_pos < ParseDocBlock_len)) && (m2runtime_strcmp(m2runtime_substr(ParseDocBlock_in, ParseDocBlock_pos, 0, 0, ParseDocBlock_0err_entry_get, 25), m2runtime_CHR(10)) == 0)) ){
/*163*/ 				m2_inc(&ParseDocBlock_pos, 1);
/*165*/ 			}
/*165*/ 			ParseDocBlock_c = m2runtime_CHR(10);
/*168*/ 		}
/*170*/ 	}

/*171*/ 	int ParseDocBlock_line_start_n = 0;
/*174*/ 	int ParseDocBlock_line_start_pos = 0;
/*174*/ 	if( ParseDocBlock_c == NULL ){
/*176*/ 		return ;
/*176*/ 	} else if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) == 0 ){
/*178*/ 		ParseDocBlock_lowLevelReadCh();
/*179*/ 		ParseDocBlock_line_start_n = ParseDocBlock_line_n;
/*180*/ 		ParseDocBlock_line_start_pos = ParseDocBlock_pos;
/*181*/ 		while( ParseDocBlock_isLWSP(ParseDocBlock_c) ){
/*182*/ 			ParseDocBlock_lowLevelReadCh();
/*184*/ 		}
/*184*/ 		if( ParseDocBlock_c == NULL ){
/*186*/ 			return ;
/*186*/ 		} else if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(42)) == 0 ){
/*188*/ 			ParseDocBlock_lowLevelReadCh();
/*191*/ 		} else {
/*191*/ 			ParseDocBlock_line_n = ParseDocBlock_line_start_n;
/*192*/ 			ParseDocBlock_pos = ParseDocBlock_line_start_pos;
/*193*/ 			ParseDocBlock_c = m2runtime_substr(ParseDocBlock_in, (ParseDocBlock_pos - 1), 0, 0, ParseDocBlock_0err_entry_get, 26);
/*196*/ 		}
/*196*/ 	} else {
/*196*/ 		ParseDocBlock_lowLevelReadCh();
/*199*/ 	}
/*201*/ }


/*208*/ STRING *
/*208*/ ParseDocBlock_textToHtml(STRING *ParseDocBlock_s)
/*208*/ {

/*217*/ 	int
/*217*/ 	ParseDocBlock_skipEscapedUnicodeChar(STRING *ParseDocBlock_s, int ParseDocBlock_i)
/*217*/ 	{
/*219*/ 		STRING * ParseDocBlock_w = NULL;
/*219*/ 		ParseDocBlock_w = m2runtime_substr(ParseDocBlock_s, ParseDocBlock_i, m2runtime_length(ParseDocBlock_s), 1, ParseDocBlock_0err_entry_get, 27);
/*220*/ 		if( m2_match(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"^&#([0-9]+)|(x|X[0-9a-fA-F]+);") ){
/*221*/ 			return (ParseDocBlock_i + str_find(ParseDocBlock_w, m2runtime_CHR(59)));
/*223*/ 		} else {
/*223*/ 			return ParseDocBlock_i;
/*226*/ 		}
/*226*/ 		m2runtime_missing_return(ParseDocBlock_0err_entry_get, 28);
/*226*/ 		return 0;
/*228*/ 	}

/*229*/ 	int ParseDocBlock_j = 0;
/*229*/ 	int ParseDocBlock_i = 0;
/*230*/ 	STRING * ParseDocBlock_c = NULL;
/*232*/ 	void * ParseDocBlock_b = NULL;
/*232*/ 	buffer_Reset(*(void **)(void *)&ParseDocBlock_b);
/*233*/ 	{
/*233*/ 		int m2runtime_for_limit_1;
/*233*/ 		ParseDocBlock_i = 0;
/*233*/ 		m2runtime_for_limit_1 = (m2runtime_length(ParseDocBlock_s) - 1);
/*234*/ 		for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*234*/ 			ParseDocBlock_c = m2runtime_substr(ParseDocBlock_s, ParseDocBlock_i, 0, 0, ParseDocBlock_0err_entry_get, 29);
/*235*/ 			if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(60)) == 0 ){
/*236*/ 				buffer_AddString((void *)&ParseDocBlock_b, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"&lt;");
/*237*/ 			} else if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(62)) == 0 ){
/*238*/ 				buffer_AddString((void *)&ParseDocBlock_b, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"&gt;");
/*239*/ 			} else if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(38)) == 0 ){
/*240*/ 				ParseDocBlock_j = ParseDocBlock_skipEscapedUnicodeChar(ParseDocBlock_s, ParseDocBlock_i);
/*241*/ 				if( (ParseDocBlock_j == ParseDocBlock_i) ){
/*242*/ 					buffer_AddString((void *)&ParseDocBlock_b, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"&amp;");
/*244*/ 				} else {
/*244*/ 					buffer_AddString((void *)&ParseDocBlock_b, m2runtime_substr(ParseDocBlock_s, ParseDocBlock_i, (ParseDocBlock_j + 1), 1, ParseDocBlock_0err_entry_get, 30));
/*245*/ 					ParseDocBlock_i = ParseDocBlock_j;
/*248*/ 				}
/*248*/ 			} else {
/*248*/ 				buffer_AddString((void *)&ParseDocBlock_b, ParseDocBlock_c);
/*251*/ 			}
/*251*/ 		}
/*251*/ 	}
/*251*/ 	return buffer_ToString(ParseDocBlock_b);
/*255*/ }


/*257*/ void
/*257*/ ParseDocBlock_checkMisspelled(STRING *ParseDocBlock_expect, STRING *ParseDocBlock_found)
/*257*/ {
/*257*/ 	if( m2runtime_strcmp(ParseDocBlock_expect, ParseDocBlock_found) == 0 ){
/*259*/ 		return ;
/*260*/ 	}
/*260*/ 	Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"misspelled keyword `", ParseDocBlock_found, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"', expected `", ParseDocBlock_expect, m2runtime_CHR(39), (STRING *) 1));
/*265*/ }


/*271*/ RECORD *
/*271*/ ParseDocBlock_SearchClass(STRING *ParseDocBlock_name)
/*271*/ {
/*273*/ 	STRING * ParseDocBlock_name_lc = NULL;
/*273*/ 	if( (Globals_php_ver == 4) ){
/*274*/ 		return Search_SearchClass(ParseDocBlock_name);
/*277*/ 	}
/*277*/ 	ParseDocBlock_name_lc = str_tolower(ParseDocBlock_name);
/*278*/ 	if( m2runtime_strcmp(ParseDocBlock_name_lc, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"self") == 0 ){
/*279*/ 		ParseDocBlock_checkMisspelled((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"self", ParseDocBlock_name);
/*280*/ 		if( Globals_curr_class == NULL ){
/*281*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"`self': not inside a class");
/*282*/ 			return NULL;
/*284*/ 		}
/*284*/ 		return Globals_curr_class;
/*285*/ 	} else if( m2runtime_strcmp(ParseDocBlock_name_lc, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"parent") == 0 ){
/*286*/ 		ParseDocBlock_checkMisspelled((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"parent", ParseDocBlock_name);
/*287*/ 		if( Globals_curr_class == NULL ){
/*288*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"`parent': not inside a class");
/*289*/ 			return NULL;
/*290*/ 		} else if( (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 3 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 31) == NULL ){
/*291*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"`parent': no parent class");
/*292*/ 			return NULL;
/*294*/ 		}
/*294*/ 		return (RECORD *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 3 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 32);
/*296*/ 	} else {
/*296*/ 		return Search_SearchClass(ParseDocBlock_name);
/*299*/ 	}
/*299*/ 	m2runtime_missing_return(ParseDocBlock_0err_entry_get, 33);
/*299*/ 	return NULL;
/*301*/ }


/*303*/ STRING *
/*303*/ ParseDocBlock_resolve_namespace_operator(STRING *ParseDocBlock_name)
/*303*/ {
/*305*/ 	STRING * ParseDocBlock_s = NULL;
/*305*/ 	if( str_starts_with(ParseDocBlock_name, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"namespace\134") ){
/*306*/ 		ParseDocBlock_s = m2runtime_substr(ParseDocBlock_name, 10, m2runtime_length(ParseDocBlock_name), 1, ParseDocBlock_0err_entry_get, 34);
/*307*/ 		if( (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 35) == NULL ){
/*308*/ 			return m2runtime_concat_STRING(0, m2runtime_CHR(92), ParseDocBlock_s, (STRING *) 1);
/*310*/ 		} else {
/*310*/ 			return m2runtime_concat_STRING(0, m2runtime_CHR(92), (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_package, 4 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 36), m2runtime_CHR(92), ParseDocBlock_s, (STRING *) 1);
/*313*/ 		}
/*313*/ 	} else {
/*313*/ 		return ParseDocBlock_name;
/*316*/ 	}
/*316*/ 	m2runtime_missing_return(ParseDocBlock_0err_entry_get, 37);
/*316*/ 	return NULL;
/*318*/ }


/*325*/ STRING *
/*325*/ ParseDocBlock_resolve_ns(STRING *ParseDocBlock_item)
/*325*/ {
/*326*/ 	RECORD * ParseDocBlock_c = NULL;
/*327*/ 	RECORD * ParseDocBlock_f = NULL;
/*328*/ 	RECORD * ParseDocBlock_class = NULL;
/*329*/ 	int ParseDocBlock_i = 0;
/*331*/ 	STRING * ParseDocBlock_name = NULL;
/*331*/ 	if( (Globals_php_ver == 4) ){
/*332*/ 		return ParseDocBlock_item;
/*335*/ 	}
/*335*/ 	ParseDocBlock_item = ParseDocBlock_resolve_namespace_operator(ParseDocBlock_item);
/*340*/ 	if( m2runtime_strcmp(m2runtime_substr(ParseDocBlock_item, 0, 0, 0, ParseDocBlock_0err_entry_get, 38), m2runtime_CHR(92)) == 0 ){
/*341*/ 		return m2runtime_substr(ParseDocBlock_item, 1, m2runtime_length(ParseDocBlock_item), 1, ParseDocBlock_0err_entry_get, 39);
/*347*/ 	}
/*347*/ 	if( m2runtime_strcmp(m2runtime_substr(ParseDocBlock_item, 0, 0, 0, ParseDocBlock_0err_entry_get, 40), m2runtime_CHR(36)) == 0 ){
/*348*/ 		return ParseDocBlock_item;
/*354*/ 	}
/*354*/ 	ParseDocBlock_i = str_find(ParseDocBlock_item, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"::");
/*355*/ 	if( (ParseDocBlock_i == 0) ){
/*356*/ 		if( Globals_curr_class == NULL ){
/*357*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"{@link ", ParseDocBlock_item, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"}: not inside a class", (STRING *) 1));
/*358*/ 			return ParseDocBlock_item;
/*360*/ 		}
/*360*/ 		return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(Globals_curr_class, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 41), ParseDocBlock_item, (STRING *) 1);
/*361*/ 	} else if( (ParseDocBlock_i > 0) ){
/*362*/ 		ParseDocBlock_name = m2runtime_substr(ParseDocBlock_item, 0, ParseDocBlock_i, 1, ParseDocBlock_0err_entry_get, 42);
/*363*/ 		ParseDocBlock_class = ParseDocBlock_SearchClass(ParseDocBlock_name);
/*364*/ 		if( ParseDocBlock_class == NULL ){
/*365*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"{@link ", ParseDocBlock_item, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"}: unknown class", (STRING *) 1));
/*366*/ 			return ParseDocBlock_item;
/*368*/ 		}
/*368*/ 		return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_class, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 43), m2runtime_substr(ParseDocBlock_item, ParseDocBlock_i, m2runtime_length(ParseDocBlock_item), 1, ParseDocBlock_0err_entry_get, 44), (STRING *) 1);
/*374*/ 	}
/*374*/ 	ParseDocBlock_i = str_find(ParseDocBlock_item, m2runtime_CHR(40));
/*375*/ 	if( (ParseDocBlock_i > 0) ){
/*376*/ 		ParseDocBlock_name = m2runtime_substr(ParseDocBlock_item, 0, ParseDocBlock_i, 1, ParseDocBlock_0err_entry_get, 45);
/*377*/ 		ParseDocBlock_f = Search_SearchFunc(ParseDocBlock_name, TRUE);
/*378*/ 		if( ParseDocBlock_f == NULL ){
/*379*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"{@link ", ParseDocBlock_item, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"}: unknown function", (STRING *) 1));
/*380*/ 			return ParseDocBlock_item;
/*382*/ 		}
/*382*/ 		return m2runtime_concat_STRING(0, (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_f, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 46), m2runtime_substr(ParseDocBlock_item, ParseDocBlock_i, m2runtime_length(ParseDocBlock_item), 1, ParseDocBlock_0err_entry_get, 47), (STRING *) 1);
/*388*/ 	}
/*388*/ 	ParseDocBlock_c = Search_SearchConst(ParseDocBlock_item, TRUE);
/*389*/ 	if( ParseDocBlock_c != NULL ){
/*390*/ 		return (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_c, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 48);
/*396*/ 	}
/*396*/ 	ParseDocBlock_class = ParseDocBlock_SearchClass(ParseDocBlock_item);
/*397*/ 	if( ParseDocBlock_class != NULL ){
/*398*/ 		return (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_class, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 49);
/*401*/ 	}
/*401*/ 	Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"{@link ", ParseDocBlock_item, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\17,\0,\0,\0)"}: unknown item", (STRING *) 1));
/*402*/ 	return ParseDocBlock_item;
/*406*/ }


/*408*/ STRING *
/*408*/ ParseDocBlock_expandInlineTags(STRING *ParseDocBlock_htmlText)
/*408*/ {
/*409*/ 	int ParseDocBlock_i = 0;
/*409*/ 	int ParseDocBlock_n = 0;
/*409*/ 	int ParseDocBlock_i2 = 0;
/*409*/ 	int ParseDocBlock_i1 = 0;
/*410*/ 	void * ParseDocBlock_b = NULL;
/*411*/ 	STRING * ParseDocBlock_w = NULL;
/*411*/ 	STRING * ParseDocBlock_result = NULL;
/*411*/ 	STRING * ParseDocBlock_content = NULL;
/*411*/ 	STRING * ParseDocBlock_tag = NULL;
/*413*/ 	ARRAY * ParseDocBlock_words = NULL;
/*413*/ 	ARRAY * ParseDocBlock_a = NULL;
/*415*/ 	do {
/*417*/ 		ParseDocBlock_i1 = str_find(ParseDocBlock_htmlText, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"{@");
/*418*/ 		if( (ParseDocBlock_i1 < 0) ){
/*420*/ 			if( ParseDocBlock_b == NULL ){
/*421*/ 				return ParseDocBlock_htmlText;
/*423*/ 			} else {
/*423*/ 				buffer_AddString((void *)&ParseDocBlock_b, ParseDocBlock_htmlText);
/*424*/ 				return buffer_ToString(ParseDocBlock_b);
/*427*/ 			}
/*429*/ 		}
/*429*/ 		ParseDocBlock_i2 = str_index(ParseDocBlock_htmlText, ParseDocBlock_i1, m2runtime_CHR(125));
/*430*/ 		if( (ParseDocBlock_i2 < 0) ){
/*432*/ 			buffer_AddString((void *)&ParseDocBlock_b, ParseDocBlock_htmlText);
/*433*/ 			return buffer_ToString(ParseDocBlock_b);
/*437*/ 		}
/*437*/ 		ParseDocBlock_content = m2runtime_substr(ParseDocBlock_htmlText, (ParseDocBlock_i1 + 2), ParseDocBlock_i2, 1, ParseDocBlock_0err_entry_get, 50);
/*440*/ 		ParseDocBlock_a = str_split(ParseDocBlock_content, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)" \011\012");
/*441*/ 		ParseDocBlock_words = (
/*442*/ 			push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*442*/ 			(ARRAY*) pop()
/*442*/ 		);
/*442*/ 		{
/*442*/ 			int m2runtime_for_limit_1;
/*442*/ 			ParseDocBlock_i = 0;
/*442*/ 			m2runtime_for_limit_1 = (m2runtime_count(ParseDocBlock_a) - 1);
/*443*/ 			for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*443*/ 				ParseDocBlock_w = ParseDocBlock_trim((STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_a, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 51));
/*444*/ 				if( (m2runtime_length(ParseDocBlock_w) > 0) ){
/*445*/ 					*(STRING **)m2runtime_dereference_lhs_ARRAY_next(&ParseDocBlock_words, sizeof(void *), 1, ParseDocBlock_0err_entry_get, 52) = ParseDocBlock_w;
/*448*/ 				}
/*450*/ 			}
/*450*/ 		}
/*450*/ 		ParseDocBlock_n = m2runtime_count(ParseDocBlock_words);
/*451*/ 		if( (ParseDocBlock_n > 0) ){
/*452*/ 			ParseDocBlock_tag = (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_words, 0, ParseDocBlock_0err_entry_get, 53);
/*454*/ 		}
/*454*/ 		if( (ParseDocBlock_n == 0) ){
/*455*/ 			ParseDocBlock_result = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"{@";
/*457*/ 		} else if( ((m2runtime_strcmp(ParseDocBlock_tag, m2runtime_CHR(42)) == 0) && ((ParseDocBlock_n == 1))) ){
/*458*/ 			ParseDocBlock_result = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"*/";
/*460*/ 		} else if( ((m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"link") == 0) && ((ParseDocBlock_n >= 2))) ){
/*462*/ 			if( m2_match((STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_words, 1, ParseDocBlock_0err_entry_get, 54), m2runtime_concat_STRING(0, m2runtime_CHR(94), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"(mailto:)|([a-z]+://)", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"|(\134./)|(\134.\134./)", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"|/", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"|([a-zA-Z]:)", (STRING *) 1)) ){
/*470*/ 				ParseDocBlock_result = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"<a href=\042", (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_words, 1, ParseDocBlock_0err_entry_get, 55), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\042>", (STRING *) 1);
/*471*/ 				if( (ParseDocBlock_n >= 3) ){
/*473*/ 					{
/*473*/ 						int m2runtime_for_limit_1;
/*473*/ 						ParseDocBlock_i = 2;
/*473*/ 						m2runtime_for_limit_1 = (ParseDocBlock_n - 1);
/*474*/ 						for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*474*/ 							if( (ParseDocBlock_i > 2) ){
/*475*/ 								ParseDocBlock_result = m2runtime_concat_STRING(0, ParseDocBlock_result, m2runtime_CHR(32), (STRING *) 1);
/*477*/ 							}
/*477*/ 							ParseDocBlock_result = m2runtime_concat_STRING(0, ParseDocBlock_result, (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_words, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 56), (STRING *) 1);
/*480*/ 						}
/*480*/ 					}
/*480*/ 				} else {
/*480*/ 					ParseDocBlock_result = m2runtime_concat_STRING(0, ParseDocBlock_result, (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_words, 1, ParseDocBlock_0err_entry_get, 57), (STRING *) 1);
/*482*/ 				}
/*482*/ 				ParseDocBlock_result = m2runtime_concat_STRING(0, ParseDocBlock_result, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"</a>", (STRING *) 1);
/*486*/ 			} else {
/*486*/ 				ParseDocBlock_result = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"<@item ", ParseDocBlock_resolve_ns((STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_words, 1, ParseDocBlock_0err_entry_get, 58)), m2runtime_CHR(62), (STRING *) 1);
/*487*/ 				if( (ParseDocBlock_n >= 3) ){
/*490*/ 					ParseDocBlock_result = m2runtime_concat_STRING(0, ParseDocBlock_result, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)" (", (STRING *) 1);
/*491*/ 					{
/*491*/ 						int m2runtime_for_limit_1;
/*491*/ 						ParseDocBlock_i = 2;
/*491*/ 						m2runtime_for_limit_1 = (ParseDocBlock_n - 1);
/*492*/ 						for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*492*/ 							if( (ParseDocBlock_i > 2) ){
/*493*/ 								ParseDocBlock_result = m2runtime_concat_STRING(0, ParseDocBlock_result, m2runtime_CHR(32), (STRING *) 1);
/*495*/ 							}
/*495*/ 							ParseDocBlock_result = m2runtime_concat_STRING(0, ParseDocBlock_result, (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_words, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 59), (STRING *) 1);
/*497*/ 						}
/*497*/ 					}
/*497*/ 					ParseDocBlock_result = m2runtime_concat_STRING(0, ParseDocBlock_result, m2runtime_CHR(41), (STRING *) 1);
/*500*/ 				}
/*501*/ 			}
/*501*/ 		} else if( ((m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"img") == 0) && ((ParseDocBlock_n == 2))) ){
/*502*/ 			ParseDocBlock_result = m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"<img src=\042", (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_words, 1, ParseDocBlock_0err_entry_get, 60), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\042>", (STRING *) 1);
/*504*/ 		} else if( ((m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"id") == 0) || (m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"toc") == 0)) ){
/*507*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"the {@", ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"} inline tag not allowed in DocBlock", (STRING *) 1));
/*509*/ 			ParseDocBlock_result = m2runtime_substr(ParseDocBlock_htmlText, ParseDocBlock_i1, (ParseDocBlock_i2 + 1), 1, ParseDocBlock_0err_entry_get, 61);
/*511*/ 		} else if( ((m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"example") == 0) || (m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"internal") == 0) || (m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"inheritdoc") == 0) || (m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"source") == 0) || (m2runtime_strcmp(ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"tutorial") == 0)) ){
/*517*/ 			Scanner_Notice2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"the {@", ParseDocBlock_tag, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"} inline tag still unsupported by PHPLint, sorry", (STRING *) 1));
/*519*/ 			ParseDocBlock_result = m2runtime_substr(ParseDocBlock_htmlText, ParseDocBlock_i1, (ParseDocBlock_i2 + 1), 1, ParseDocBlock_0err_entry_get, 62);
/*522*/ 		} else {
/*522*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"unknown inline tag {@", ParseDocBlock_tag, m2runtime_CHR(125), (STRING *) 1));
/*523*/ 			ParseDocBlock_result = m2runtime_substr(ParseDocBlock_htmlText, ParseDocBlock_i1, (ParseDocBlock_i2 + 1), 1, ParseDocBlock_0err_entry_get, 63);
/*528*/ 		}
/*528*/ 		buffer_AddString((void *)&ParseDocBlock_b, m2runtime_substr(ParseDocBlock_htmlText, 0, ParseDocBlock_i1, 1, ParseDocBlock_0err_entry_get, 64));
/*531*/ 		buffer_AddString((void *)&ParseDocBlock_b, ParseDocBlock_result);
/*534*/ 		ParseDocBlock_htmlText = m2runtime_substr(ParseDocBlock_htmlText, (ParseDocBlock_i2 + 1), m2runtime_length(ParseDocBlock_htmlText), 1, ParseDocBlock_0err_entry_get, 65);
/*536*/ 	} while( !( (m2runtime_length(ParseDocBlock_htmlText) == 0) ));
/*538*/ 	return buffer_ToString(ParseDocBlock_b);
/*548*/ }

/*549*/ ARRAY * ParseDocBlock_tags = NULL;
/*551*/ void * ParseDocBlock_eb = NULL;

/*563*/ STRING *
/*563*/ ParseDocBlock_filterValidHtmlEntities(STRING *ParseDocBlock_s)
/*563*/ {
/*565*/ 	ARRAY * ParseDocBlock_a = NULL;
/*566*/ 	int ParseDocBlock_i = 0;
/*567*/ 	STRING * ParseDocBlock_l = NULL;
/*569*/ 	STRING * ParseDocBlock_t = NULL;

/*578*/ 	void
/*578*/ 	ParseDocBlock_nextTag(void)
/*578*/ 	{

/*579*/ 		STRING *
/*579*/ 		ParseDocBlock_detectTag(STRING *ParseDocBlock_s)
/*579*/ 		{
/*579*/ 			int ParseDocBlock_i = 0;
/*581*/ 			STRING * ParseDocBlock_t = NULL;
/*581*/ 			{
/*581*/ 				int m2runtime_for_limit_1;
/*581*/ 				ParseDocBlock_i = 0;
/*581*/ 				m2runtime_for_limit_1 = (m2runtime_count(ParseDocBlock_tags) - 1);
/*582*/ 				for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*582*/ 					ParseDocBlock_t = (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_tags, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 66);
/*583*/ 					if( (((m2runtime_length(ParseDocBlock_s) >= m2runtime_length(ParseDocBlock_t))) && (m2runtime_strcmp(m2runtime_substr(ParseDocBlock_s, 0, m2runtime_length(ParseDocBlock_t), 1, ParseDocBlock_0err_entry_get, 67), ParseDocBlock_t) == 0)) ){
/*585*/ 						return ParseDocBlock_t;
/*588*/ 					}
/*588*/ 				}
/*588*/ 			}
/*588*/ 			return NULL;
/*592*/ 		}

/*592*/ 		if( (ParseDocBlock_i >= m2runtime_count(ParseDocBlock_a)) ){
/*593*/ 			ParseDocBlock_t = NULL;
/*594*/ 			ParseDocBlock_l = NULL;
/*596*/ 			return ;
/*597*/ 		}
/*597*/ 		ParseDocBlock_l = (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_a, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 68);
/*598*/ 		ParseDocBlock_t = ParseDocBlock_detectTag(ParseDocBlock_l);
/*599*/ 		m2_inc(&ParseDocBlock_i, 1);
/*603*/ 	}


/*604*/ 	STRING *
/*604*/ 	ParseDocBlock_short(STRING *ParseDocBlock_s)
/*604*/ 	{
/*606*/ 		int ParseDocBlock_l = 0;
/*606*/ 		ParseDocBlock_l = m2runtime_length(ParseDocBlock_s);
/*607*/ 		if( (ParseDocBlock_l > 30) ){
/*609*/ 			ParseDocBlock_s = m2runtime_concat_STRING(0, m2runtime_substr(ParseDocBlock_s, 0, 25, 1, ParseDocBlock_0err_entry_get, 69), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"...", (STRING *) 1);
/*611*/ 		}
/*611*/ 		return m2runtime_StringToLiteral(ParseDocBlock_s);
/*615*/ 	}


/*620*/ 	STRING *
/*620*/ 	ParseDocBlock_splitParagraphes(STRING *ParseDocBlock_text)
/*620*/ 	{
/*621*/ 		ARRAY * ParseDocBlock_a = NULL;
/*622*/ 		int ParseDocBlock_i = 0;
/*624*/ 		void * ParseDocBlock_b = NULL;
/*624*/ 		if( ParseDocBlock_text == NULL ){
/*625*/ 			return NULL;
/*629*/ 		}
/*629*/ 		if( (str_find(ParseDocBlock_text, m2runtime_CHR(10)) < 0) ){
/*631*/ 			return ParseDocBlock_text;
/*636*/ 		}
/*636*/ 		ParseDocBlock_a = str_split(ParseDocBlock_text, m2runtime_CHR(10));
/*637*/ 		buffer_AddString((void *)&ParseDocBlock_b, (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_a, 0, ParseDocBlock_0err_entry_get, 70));
/*638*/ 		buffer_AddString((void *)&ParseDocBlock_b, m2runtime_CHR(10));
/*639*/ 		{
/*639*/ 			int m2runtime_for_limit_1;
/*639*/ 			ParseDocBlock_i = 1;
/*639*/ 			m2runtime_for_limit_1 = (m2runtime_count(ParseDocBlock_a) - 2);
/*640*/ 			for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*640*/ 				if( m2_match((STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_a, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 71), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"^[ \011]*$") ){
/*642*/ 					buffer_AddString((void *)&ParseDocBlock_b, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<p>\012");
/*644*/ 				} else {
/*644*/ 					buffer_AddString((void *)&ParseDocBlock_b, (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_a, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 72));
/*645*/ 					buffer_AddString((void *)&ParseDocBlock_b, m2runtime_CHR(10));
/*648*/ 				}
/*648*/ 			}
/*648*/ 		}
/*648*/ 		buffer_AddString((void *)&ParseDocBlock_b, (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_a, (m2runtime_count(ParseDocBlock_a) - 1), ParseDocBlock_0err_entry_get, 73));
/*649*/ 		return buffer_ToString(ParseDocBlock_b);
/*653*/ 	}


/*658*/ 	void
/*658*/ 	ParseDocBlock_addChunk(void)
/*658*/ 	{
/*658*/ 		buffer_AddString((void *)&ParseDocBlock_eb, m2runtime_CHR(60));
/*659*/ 		buffer_AddString((void *)&ParseDocBlock_eb, ParseDocBlock_t);
/*660*/ 		buffer_AddString((void *)&ParseDocBlock_eb, ParseDocBlock_splitParagraphes(m2runtime_substr(ParseDocBlock_l, m2runtime_length(ParseDocBlock_t), m2runtime_length(ParseDocBlock_l), 1, ParseDocBlock_0err_entry_get, 74)));
/*661*/ 		ParseDocBlock_nextTag();
/*664*/ 	}


/*669*/ 	void
/*669*/ 	ParseDocBlock_addBareText(STRING *ParseDocBlock_text)
/*669*/ 	{
/*669*/ 		buffer_AddString((void *)&ParseDocBlock_eb, ParseDocBlock_splitParagraphes(ParseDocBlock_textToHtml(ParseDocBlock_text)));
/*672*/ 	}


/*681*/ 	void
/*681*/ 	ParseDocBlock_parseHtml(void)
/*681*/ 	{

/*690*/ 		int
/*690*/ 		ParseDocBlock_isSimpleTag(void)
/*690*/ 		{
/*690*/ 			return ((m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"b>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"i>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"code>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"sub>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"sup>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"kbd>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"samp>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"var>") == 0));
/*695*/ 		}


/*696*/ 		void
/*696*/ 		ParseDocBlock_parseSimpleTag(void)
/*696*/ 		{
/*698*/ 			STRING * ParseDocBlock_q_end = NULL;
/*698*/ 			STRING * ParseDocBlock_q = NULL;
/*698*/ 			ParseDocBlock_q = ParseDocBlock_t;
/*699*/ 			ParseDocBlock_q_end = m2runtime_concat_STRING(0, m2runtime_CHR(47), ParseDocBlock_q, (STRING *) 1);
/*700*/ 			ParseDocBlock_addChunk();
/*702*/ 			do{
/*702*/ 				if( ParseDocBlock_t == NULL ){
/*703*/ 					if( ParseDocBlock_l == NULL ){
/*704*/ 						Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"missing closing tag `<", ParseDocBlock_q_end, m2runtime_CHR(39), (STRING *) 1));
/*705*/ 						buffer_AddString((void *)&ParseDocBlock_eb, m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_q_end, (STRING *) 1));
/*707*/ 						return ;
/*708*/ 					} else {
/*708*/ 						ParseDocBlock_addBareText(m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_l, (STRING *) 1));
/*709*/ 						ParseDocBlock_nextTag();
/*711*/ 					}
/*711*/ 				} else if( m2runtime_strcmp(ParseDocBlock_t, ParseDocBlock_q_end) == 0 ){
/*712*/ 					ParseDocBlock_addChunk();
/*714*/ 					return ;
/*714*/ 				} else if( ParseDocBlock_isSimpleTag() ){
/*715*/ 					ParseDocBlock_parseSimpleTag();
/*717*/ 				} else {
/*717*/ 					Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected closing tag `<", ParseDocBlock_q_end, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"' near the line `<", ParseDocBlock_short(ParseDocBlock_l), m2runtime_CHR(39), (STRING *) 1));
/*718*/ 					buffer_AddString((void *)&ParseDocBlock_eb, m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_q_end, (STRING *) 1));
/*720*/ 					return ;
/*722*/ 				}
/*724*/ 			}while(TRUE);
/*725*/ 		}


/*733*/ 		void
/*733*/ 		ParseDocBlock_checkEmptyAfterTag(void)
/*733*/ 		{
/*733*/ 			if( !m2_match(ParseDocBlock_l, m2runtime_concat_STRING(0, ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"[ \011\012\015]*$", (STRING *) 1)) ){
/*734*/ 				Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"trailing chars after tag `<", ParseDocBlock_short(ParseDocBlock_l), m2runtime_CHR(39), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", m2runtime_StringToLiteral(m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_l, (STRING *) 1)), (STRING *) 1));
/*737*/ 			}
/*737*/ 			buffer_AddString((void *)&ParseDocBlock_eb, m2runtime_CHR(60));
/*738*/ 			buffer_AddString((void *)&ParseDocBlock_eb, ParseDocBlock_t);
/*739*/ 			buffer_AddString((void *)&ParseDocBlock_eb, m2runtime_CHR(10));
/*740*/ 			ParseDocBlock_nextTag();
/*743*/ 		}


/*746*/ 		void
/*746*/ 		ParseDocBlock_parseLi(void)
/*746*/ 		{
/*746*/ 			ParseDocBlock_addChunk();
/*747*/ 			ParseDocBlock_parseHtml();
/*748*/ 			if( m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"/li>") == 0 ){
/*749*/ 				ParseDocBlock_checkEmptyAfterTag();
/*751*/ 			} else {
/*751*/ 				buffer_AddString((void *)&ParseDocBlock_eb, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"</li>\012");
/*755*/ 			}
/*757*/ 		}


/*758*/ 		void
/*758*/ 		ParseDocBlock_checkNesting(void)
/*758*/ 		{
/*760*/ 			STRING * ParseDocBlock_q_end = NULL;
/*760*/ 			STRING * ParseDocBlock_q = NULL;
/*760*/ 			ParseDocBlock_q = ParseDocBlock_t;
/*761*/ 			ParseDocBlock_q_end = m2runtime_concat_STRING(0, m2runtime_CHR(47), ParseDocBlock_q, (STRING *) 1);
/*762*/ 			ParseDocBlock_addChunk();
/*763*/ 			ParseDocBlock_parseHtml();
/*764*/ 			if( ParseDocBlock_t == NULL ){
/*765*/ 				if( ParseDocBlock_l == NULL ){
/*766*/ 					Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"missing closing tag `<", ParseDocBlock_q_end, m2runtime_CHR(39), (STRING *) 1));
/*767*/ 					buffer_AddString((void *)&ParseDocBlock_eb, m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_q_end, (STRING *) 1));
/*769*/ 					return ;
/*770*/ 				} else {
/*770*/ 					ParseDocBlock_addBareText(m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_l, (STRING *) 1));
/*771*/ 					ParseDocBlock_nextTag();
/*773*/ 				}
/*773*/ 			} else if( m2runtime_strcmp(ParseDocBlock_t, ParseDocBlock_q_end) == 0 ){
/*774*/ 				ParseDocBlock_addChunk();
/*776*/ 				return ;
/*777*/ 			} else {
/*777*/ 				Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"expected closing tag `<", ParseDocBlock_q_end, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"' near the line `<", ParseDocBlock_short(ParseDocBlock_l), m2runtime_CHR(39), (STRING *) 1));
/*778*/ 				buffer_AddString((void *)&ParseDocBlock_eb, m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_q_end, (STRING *) 1));
/*780*/ 				return ;
/*782*/ 			}
/*784*/ 		}

/*785*/ 		do{
/*785*/ 			if( ParseDocBlock_t == NULL ){
/*786*/ 				if( ParseDocBlock_l == NULL ){
/*788*/ 					return ;
/*789*/ 				} else {
/*789*/ 					ParseDocBlock_addBareText(m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_l, (STRING *) 1));
/*790*/ 					ParseDocBlock_nextTag();
/*793*/ 				}
/*793*/ 			} else if( ((m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"br>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"/br>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"p>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"/p>") == 0)) ){
/*796*/ 				ParseDocBlock_addChunk();
/*798*/ 			} else if( ParseDocBlock_isSimpleTag() ){
/*799*/ 				ParseDocBlock_parseSimpleTag();
/*801*/ 			} else if( ((m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"blockquote>") == 0) || (m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"center>") == 0)) ){
/*802*/ 				ParseDocBlock_checkNesting();
/*804*/ 			} else if( m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"pre>") == 0 ){
/*805*/ 				buffer_AddString((void *)&ParseDocBlock_eb, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"<pre>");
/*806*/ 				buffer_AddString((void *)&ParseDocBlock_eb, ParseDocBlock_textToHtml(m2runtime_substr(ParseDocBlock_l, m2runtime_length(ParseDocBlock_t), m2runtime_length(ParseDocBlock_l), 1, ParseDocBlock_0err_entry_get, 75)));
/*807*/ 				ParseDocBlock_nextTag();
/*808*/ 				while( ((m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"/pre>") != 0) && (ParseDocBlock_l != NULL)) ){
/*809*/ 					buffer_AddString((void *)&ParseDocBlock_eb, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"&lt;");
/*810*/ 					buffer_AddString((void *)&ParseDocBlock_eb, ParseDocBlock_textToHtml(ParseDocBlock_l));
/*811*/ 					ParseDocBlock_nextTag();
/*813*/ 				}
/*813*/ 				if( ParseDocBlock_l == NULL ){
/*814*/ 					Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"unclosed <pre> entity");
/*815*/ 					buffer_AddString((void *)&ParseDocBlock_eb, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"</pre>\012");
/*817*/ 					return ;
/*818*/ 				}
/*818*/ 				ParseDocBlock_addChunk();
/*820*/ 			} else if( m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"ul>") == 0 ){
/*821*/ 				ParseDocBlock_checkEmptyAfterTag();
/*822*/ 				while( m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"li>") == 0 ){
/*823*/ 					ParseDocBlock_parseLi();
/*825*/ 				}
/*825*/ 				if( m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"/ul>") == 0 ){
/*826*/ 					ParseDocBlock_addChunk();
/*828*/ 				} else {
/*828*/ 					Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"expected `</ul>' near or at ", ParseDocBlock_short(m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_l, (STRING *) 1)), (STRING *) 1));
/*830*/ 					buffer_AddString((void *)&ParseDocBlock_eb, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"</ul>\012");
/*833*/ 				}
/*833*/ 			} else if( m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"ol>") == 0 ){
/*834*/ 				ParseDocBlock_checkEmptyAfterTag();
/*835*/ 				while( m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"li>") == 0 ){
/*836*/ 					ParseDocBlock_parseLi();
/*838*/ 				}
/*838*/ 				if( m2runtime_strcmp(ParseDocBlock_t, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"/ol>") == 0 ){
/*839*/ 					ParseDocBlock_addChunk();
/*841*/ 				} else {
/*841*/ 					Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"expected `</ol>' near or at ", ParseDocBlock_short(m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_l, (STRING *) 1)), (STRING *) 1));
/*843*/ 					buffer_AddString((void *)&ParseDocBlock_eb, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"</ol>\012");
/*847*/ 				}
/*849*/ 			} else {
/*849*/ 				return ;
/*852*/ 			}
/*853*/ 		}while(TRUE);
/*855*/ 	}

/*856*/ 	if( m2runtime_strcmp(ParseDocBlock_s, EMPTY_STRING) <= 0 ){
/*857*/ 		return ParseDocBlock_s;
/*860*/ 	}
/*860*/ 	if( ParseDocBlock_tags == NULL ){
/*861*/ 		ParseDocBlock_tags = str_split(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\200,\0,\0,\0)"b> /b> i> /i> blockquote> /blockquote> center> /center> code> /code> br> kbd> /kbd> p> /p> pre> /pre> /br> sub> /sub> sup> /sup>", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\63,\0,\0,\0)" ul> /ul> ol> /ol> li> /li> samp> /samp> var> /var>", (STRING *) 1), m2runtime_CHR(32));
/*870*/ 	}
/*870*/ 	ParseDocBlock_a = str_split(ParseDocBlock_s, m2runtime_CHR(60));
/*871*/ 	ParseDocBlock_i = 0;
/*872*/ 	ParseDocBlock_nextTag();
/*873*/ 	buffer_Reset(*(void **)(void *)&ParseDocBlock_eb);
/*876*/ 	ParseDocBlock_addBareText(ParseDocBlock_l);
/*877*/ 	ParseDocBlock_nextTag();
/*880*/ 	do{
/*880*/ 		ParseDocBlock_parseHtml();
/*881*/ 		if( ParseDocBlock_l == NULL ){
/*885*/ 			goto m2runtime_loop_1;
/*886*/ 		} else {
/*886*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"unknown or unexpected HTML entity ", ParseDocBlock_short(m2runtime_concat_STRING(0, m2runtime_CHR(60), ParseDocBlock_l, (STRING *) 1)), (STRING *) 1));
/*888*/ 			ParseDocBlock_addBareText(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"&lt;", ParseDocBlock_l, (STRING *) 1));
/*889*/ 			ParseDocBlock_nextTag();
/*892*/ 		}
/*893*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*893*/ 	return buffer_ToString(ParseDocBlock_eb);
/*897*/ }


/*899*/ void
/*899*/ ParseDocBlock_skipLWSP(void)
/*899*/ {
/*899*/ 	while( ParseDocBlock_isLWSP(ParseDocBlock_c) ){
/*900*/ 		ParseDocBlock_readCh();
/*903*/ 	}
/*905*/ }

/*908*/ void * ParseDocBlock_b = NULL;

/*914*/ STRING *
/*914*/ ParseDocBlock_upToEndOfLine(void)
/*914*/ {
/*914*/ 	ParseDocBlock_skipLWSP();
/*915*/ 	buffer_Reset(*(void **)(void *)&ParseDocBlock_b);
/*916*/ 	while( ((ParseDocBlock_c != NULL) && (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) != 0)) ){
/*917*/ 		buffer_AddString((void *)&ParseDocBlock_b, ParseDocBlock_c);
/*918*/ 		ParseDocBlock_readCh();
/*920*/ 	}
/*920*/ 	if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) == 0 ){
/*921*/ 		ParseDocBlock_readCh();
/*923*/ 	}
/*923*/ 	return buffer_ToString(ParseDocBlock_b);
/*927*/ }


/*951*/ RECORD *
/*951*/ ParseDocBlock_parseType(STRING *ParseDocBlock_w)
/*951*/ {
/*952*/ 	int ParseDocBlock_i = 0;
/*955*/ 	STRING * ParseDocBlock_sym_lc = NULL;
/*955*/ 	STRING * ParseDocBlock_sym = NULL;

/*961*/ 	void
/*961*/ 	ParseDocBlock_next_sym(void)
/*961*/ 	{
/*963*/ 		STRING * ParseDocBlock_c = NULL;
/*965*/ 		int ParseDocBlock_j = 0;
/*965*/ 		if( (ParseDocBlock_i >= m2runtime_length(ParseDocBlock_w)) ){
/*966*/ 			ParseDocBlock_sym = NULL;
/*967*/ 			ParseDocBlock_sym_lc = NULL;
/*969*/ 			return ;
/*970*/ 		}
/*970*/ 		ParseDocBlock_c = m2runtime_substr(ParseDocBlock_w, ParseDocBlock_i, 0, 0, ParseDocBlock_0err_entry_get, 76);
/*971*/ 		if( ((m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(91)) == 0) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(93)) == 0) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(124)) == 0)) ){
/*972*/ 			ParseDocBlock_sym = ParseDocBlock_c;
/*973*/ 			ParseDocBlock_sym_lc = ParseDocBlock_sym;
/*974*/ 			ParseDocBlock_i = (ParseDocBlock_i + 1);
/*976*/ 			return ;
/*977*/ 		}
/*977*/ 		ParseDocBlock_j = str_index(ParseDocBlock_w, ParseDocBlock_i, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"[]|");
/*978*/ 		if( (ParseDocBlock_j < 0) ){
/*979*/ 			ParseDocBlock_sym = m2runtime_substr(ParseDocBlock_w, ParseDocBlock_i, m2runtime_length(ParseDocBlock_w), 1, ParseDocBlock_0err_entry_get, 77);
/*980*/ 			ParseDocBlock_sym_lc = str_tolower(ParseDocBlock_sym);
/*981*/ 			ParseDocBlock_i = m2runtime_length(Scanner_s);
/*983*/ 			return ;
/*984*/ 		}
/*984*/ 		ParseDocBlock_sym = m2runtime_substr(ParseDocBlock_w, ParseDocBlock_i, ParseDocBlock_j, 1, ParseDocBlock_0err_entry_get, 78);
/*985*/ 		ParseDocBlock_sym_lc = str_tolower(ParseDocBlock_sym);
/*986*/ 		ParseDocBlock_i = ParseDocBlock_j;
/*990*/ 	}


/*997*/ 	int
/*997*/ 	ParseDocBlock_isKeyword(STRING *ParseDocBlock_k)
/*997*/ 	{
/*997*/ 		if( m2runtime_strcmp(ParseDocBlock_k, ParseDocBlock_sym_lc) == 0 ){
/*998*/ 			if( m2runtime_strcmp(ParseDocBlock_k, ParseDocBlock_sym) != 0 ){
/*999*/ 				Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"spelling check: expected ", ParseDocBlock_k, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)" but found ", ParseDocBlock_sym, (STRING *) 1));
/*1001*/ 			}
/*1001*/ 			return TRUE;
/*1003*/ 		} else {
/*1003*/ 			return FALSE;
/*1006*/ 		}
/*1006*/ 		m2runtime_missing_return(ParseDocBlock_0err_entry_get, 79);
/*1006*/ 		return 0;
/*1008*/ 	}


/*1009*/ 	RECORD *
/*1009*/ 	ParseDocBlock_ParseTypeName(void)
/*1009*/ 	{
/*1011*/ 		RECORD * ParseDocBlock_cl = NULL;
/*1011*/ 		if( ParseDocBlock_sym == NULL ){
/*1012*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"missing type");
/*1013*/ 			ParseDocBlock_next_sym();
/*1014*/ 			return NULL;
/*1015*/ 		} else if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"void") ){
/*1016*/ 			ParseDocBlock_next_sym();
/*1017*/ 			return Globals_void_type;
/*1018*/ 		} else if( (ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"bool") || ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"boolean")) ){
/*1019*/ 			ParseDocBlock_next_sym();
/*1020*/ 			return Globals_boolean_type;
/*1021*/ 		} else if( m2runtime_strcmp(ParseDocBlock_sym_lc, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"false") == 0 ){
/*1022*/ 			ParseDocBlock_next_sym();
/*1023*/ 			return Globals_boolean_type;
/*1024*/ 		} else if( (ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int") || ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"integer")) ){
/*1025*/ 			ParseDocBlock_next_sym();
/*1026*/ 			return Globals_int_type;
/*1027*/ 		} else if( (ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"float") || ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"double") || ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"real")) ){
/*1028*/ 			ParseDocBlock_next_sym();
/*1029*/ 			return Globals_float_type;
/*1030*/ 		} else if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string") ){
/*1031*/ 			ParseDocBlock_next_sym();
/*1032*/ 			return Globals_string_type;
/*1033*/ 		} else if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"resource") ){
/*1034*/ 			ParseDocBlock_next_sym();
/*1035*/ 			return Globals_resource_type;
/*1036*/ 		} else if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"mixed") ){
/*1037*/ 			ParseDocBlock_next_sym();
/*1038*/ 			return Globals_mixed_type;
/*1039*/ 		} else if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"object") ){
/*1040*/ 			ParseDocBlock_next_sym();
/*1041*/ 			return Globals_object_type;
/*1042*/ 		} else if( m2_match(ParseDocBlock_sym, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"^\134\134?[_a-zA-Z\200-\377]+(\134\134[_0-9a-zA-Z\200-\377]+)*$") ){
/*1043*/ 			ParseDocBlock_cl = ParseDocBlock_SearchClass(ParseDocBlock_resolve_namespace_operator(ParseDocBlock_sym));
/*1044*/ 			if( ParseDocBlock_cl == NULL ){
/*1045*/ 				Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"unknown type/class `", ParseDocBlock_sym, m2runtime_CHR(39), (STRING *) 1));
/*1046*/ 				ParseDocBlock_next_sym();
/*1047*/ 				return NULL;
/*1049*/ 			} else {
/*1049*/ 				ParseDocBlock_next_sym();
/*1050*/ 				return (RECORD *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_cl, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 80);
/*1053*/ 			}
/*1053*/ 		} else {
/*1053*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"invalid type `", ParseDocBlock_sym, m2runtime_CHR(39), (STRING *) 1));
/*1054*/ 			ParseDocBlock_next_sym();
/*1055*/ 			return NULL;
/*1058*/ 		}
/*1058*/ 		m2runtime_missing_return(ParseDocBlock_0err_entry_get, 81);
/*1058*/ 		return NULL;
/*1060*/ 	}


/*1062*/ 	RECORD *
/*1062*/ 	ParseDocBlock_ParseArray(void)
/*1062*/ 	{
/*1064*/ 		RECORD * ParseDocBlock_t = NULL;
/*1064*/ 		ParseDocBlock_t = (
/*1064*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*1064*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*1064*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 7,
/*1064*/ 			push((char*) NULL),
/*1064*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1064*/ 			push((char*) NULL),
/*1065*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1065*/ 			(RECORD*) pop()
/*1065*/ 		);
/*1065*/ 		ParseDocBlock_next_sym();
/*1066*/ 		if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int") ){
/*1067*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 82) = 3;
/*1068*/ 			ParseDocBlock_next_sym();
/*1069*/ 		} else if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string") ){
/*1070*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 83) = 5;
/*1071*/ 			ParseDocBlock_next_sym();
/*1073*/ 		}
/*1073*/ 		if( m2runtime_strcmp(ParseDocBlock_sym, m2runtime_CHR(93)) != 0 ){
/*1074*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\100,\0,\0,\0)"in array type declaration expected `[]' or `[int]' or `[string]'");
/*1075*/ 			return ParseDocBlock_t;
/*1077*/ 		}
/*1077*/ 		ParseDocBlock_next_sym();
/*1078*/ 		if( m2runtime_strcmp(ParseDocBlock_sym, m2runtime_CHR(91)) == 0 ){
/*1079*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 84) = ParseDocBlock_ParseArray();
/*1081*/ 		} else {
/*1081*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_t, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 85) = ParseDocBlock_ParseTypeName();
/*1083*/ 		}
/*1083*/ 		return ParseDocBlock_t;
/*1087*/ 	}


/*1094*/ 	RECORD *
/*1094*/ 	ParseDocBlock_ParseIndeces(RECORD *ParseDocBlock_t)
/*1094*/ 	{
/*1096*/ 		RECORD * ParseDocBlock_a = NULL;
/*1096*/ 		ParseDocBlock_a = (
/*1096*/ 			push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*1096*/ 			*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*1096*/ 			*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 1,
/*1096*/ 			push((char*) NULL),
/*1096*/ 			*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1096*/ 			push((char*) NULL),
/*1097*/ 			*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1097*/ 			(RECORD*) pop()
/*1097*/ 		);
/*1097*/ 		ParseDocBlock_next_sym();
/*1098*/ 		if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int") ){
/*1099*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 86) = 3;
/*1100*/ 			ParseDocBlock_next_sym();
/*1101*/ 		} else if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string") ){
/*1102*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 87) = 5;
/*1103*/ 			ParseDocBlock_next_sym();
/*1104*/ 		} else if( m2runtime_strcmp(ParseDocBlock_sym, m2runtime_CHR(93)) == 0 ){
/*1105*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 88) = 7;
/*1107*/ 		}
/*1107*/ 		if( m2runtime_strcmp(ParseDocBlock_sym, m2runtime_CHR(93)) != 0 ){
/*1108*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\31,\0,\0,\0)"missing `]' in array type");
/*1109*/ 			return NULL;
/*1111*/ 		}
/*1111*/ 		ParseDocBlock_next_sym();
/*1112*/ 		if( m2runtime_strcmp(ParseDocBlock_sym, m2runtime_CHR(91)) == 0 ){
/*1113*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 89) = ParseDocBlock_ParseIndeces(ParseDocBlock_t);
/*1114*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_a, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 90) == NULL ){
/*1115*/ 				return NULL;
/*1118*/ 			}
/*1118*/ 		} else {
/*1118*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_a, 2 * sizeof(void*) + 4 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 91) = ParseDocBlock_t;
/*1120*/ 		}
/*1120*/ 		return ParseDocBlock_a;
/*1124*/ 	}


/*1126*/ 	RECORD *
/*1126*/ 	ParseDocBlock_next_type(void)
/*1126*/ 	{
/*1128*/ 		RECORD * ParseDocBlock_t = NULL;
/*1128*/ 		if( ParseDocBlock_isKeyword((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"array") ){
/*1130*/ 			ParseDocBlock_next_sym();
/*1131*/ 			if( m2runtime_strcmp(ParseDocBlock_sym, m2runtime_CHR(91)) == 0 ){
/*1132*/ 				ParseDocBlock_t = ParseDocBlock_ParseArray();
/*1134*/ 			} else {
/*1134*/ 				ParseDocBlock_t = (
/*1134*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 4 * sizeof(int), 2)),
/*1134*/ 					*(int*) (tos()+2 * sizeof(void*) + 2 * sizeof(int)) = 6,
/*1134*/ 					*(int*) (tos()+2 * sizeof(void*) + 3 * sizeof(int)) = 7,
/*1134*/ 					push((char*) Globals_mixed_type),
/*1134*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1134*/ 					push((char*) NULL),
/*1135*/ 					*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1136*/ 					(RECORD*) pop()
/*1136*/ 				);
/*1138*/ 			}
/*1139*/ 		} else {
/*1139*/ 			ParseDocBlock_t = ParseDocBlock_ParseTypeName();
/*1140*/ 			if( ParseDocBlock_t == NULL ){
/*1141*/ 				return NULL;
/*1143*/ 			}
/*1143*/ 			if( m2runtime_strcmp(ParseDocBlock_sym, m2runtime_CHR(91)) == 0 ){
/*1144*/ 				ParseDocBlock_t = ParseDocBlock_ParseIndeces(ParseDocBlock_t);
/*1147*/ 			}
/*1148*/ 		}
/*1148*/ 		return ParseDocBlock_t;
/*1152*/ 	}

/*1154*/ 	RECORD * ParseDocBlock_ignore = NULL;
/*1154*/ 	RECORD * ParseDocBlock_res = NULL;
/*1154*/ 	ParseDocBlock_i = 0;
/*1155*/ 	ParseDocBlock_next_sym();
/*1156*/ 	ParseDocBlock_res = ParseDocBlock_next_type();
/*1157*/ 	while( m2runtime_strcmp(ParseDocBlock_sym, m2runtime_CHR(124)) == 0 ){
/*1158*/ 		ParseDocBlock_next_sym();
/*1159*/ 		ParseDocBlock_ignore = ParseDocBlock_next_type();
/*1161*/ 	}
/*1161*/ 	if( ParseDocBlock_sym != NULL ){
/*1162*/ 		Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\43,\0,\0,\0)"unknown/unexpected symbol in type: ", ParseDocBlock_sym, (STRING *) 1));
/*1164*/ 	}
/*1164*/ 	return ParseDocBlock_res;
/*1168*/ }


/*1173*/ void
/*1173*/ ParseDocBlock_parseLineTag(void)
/*1173*/ {

/*1180*/ 	void
/*1180*/ 	ParseDocBlock_check_end_of_line_tag(STRING *ParseDocBlock_tag_name)
/*1180*/ 	{
/*1181*/ 		STRING * ParseDocBlock_s = NULL;
/*1183*/ 		int ParseDocBlock_already_signaled = 0;
/*1184*/ 		ParseDocBlock_skipLWSP();
/*1185*/ 		ParseDocBlock_s = ParseDocBlock_upToEndOfLine();
/*1186*/ 		if( m2runtime_strcmp(ParseDocBlock_s, EMPTY_STRING) > 0 ){
/*1187*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"unexpected trailing words inside `", ParseDocBlock_tag_name, m2runtime_CHR(39), (STRING *) 1));
/*1189*/ 			ParseDocBlock_already_signaled = TRUE;
/*1193*/ 		}
/*1193*/ 		do{
/*1193*/ 			ParseDocBlock_skipLWSP();
/*1194*/ 			if( ParseDocBlock_c == NULL ){
/*1196*/ 				return ;
/*1196*/ 			} else if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) == 0 ){
/*1198*/ 				ParseDocBlock_readCh();
/*1199*/ 			} else if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(64)) == 0 ){
/*1202*/ 				return ;
/*1203*/ 			} else {
/*1203*/ 				if( !ParseDocBlock_already_signaled ){
/*1204*/ 					Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\42,\0,\0,\0)"unexpected trailing words inside `", ParseDocBlock_tag_name, m2runtime_CHR(39), (STRING *) 1));
/*1206*/ 					ParseDocBlock_already_signaled = TRUE;
/*1208*/ 				}
/*1208*/ 				ParseDocBlock_s = ParseDocBlock_upToEndOfLine();
/*1211*/ 			}
/*1212*/ 		}while(TRUE);
/*1214*/ 	}


/*1224*/ 	STRING *
/*1224*/ 	ParseDocBlock_getWord(void)
/*1224*/ 	{
/*1225*/ 		do{
/*1225*/ 			if( ParseDocBlock_c == NULL ){
/*1226*/ 				return NULL;
/*1227*/ 			} else if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) == 0 ){
/*1228*/ 				ParseDocBlock_readCh();
/*1229*/ 				ParseDocBlock_skipLWSP();
/*1230*/ 				if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(64)) == 0 ){
/*1231*/ 					return NULL;
/*1233*/ 				}
/*1233*/ 			} else if( ParseDocBlock_isLWSP(ParseDocBlock_c) ){
/*1234*/ 				ParseDocBlock_skipLWSP();
/*1236*/ 			} else {
/*1236*/ 				buffer_Reset(*(void **)(void *)&ParseDocBlock_b);
/*1237*/ 				while( ((ParseDocBlock_c != NULL) && (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) != 0) && !ParseDocBlock_isLWSP(ParseDocBlock_c)) ){
/*1238*/ 					buffer_AddString((void *)&ParseDocBlock_b, ParseDocBlock_c);
/*1239*/ 					ParseDocBlock_readCh();
/*1241*/ 				}
/*1241*/ 				return ParseDocBlock_textToHtml(buffer_ToString(ParseDocBlock_b));
/*1244*/ 			}
/*1245*/ 		}while(TRUE);
/*1245*/ 		m2runtime_missing_return(ParseDocBlock_0err_entry_get, 92);
/*1245*/ 		return NULL;
/*1247*/ 	}


/*1249*/ 	STRING *
/*1249*/ 	ParseDocBlock_upToNextLineTag(void)
/*1249*/ 	{
/*1251*/ 		void * ParseDocBlock_res = NULL;
/*1251*/ 		buffer_AddString((void *)&ParseDocBlock_res, ParseDocBlock_upToEndOfLine());
/*1252*/ 		buffer_AddString((void *)&ParseDocBlock_res, m2runtime_CHR(10));
/*1258*/ 		do{
/*1258*/ 			while( ParseDocBlock_isLWSP(ParseDocBlock_c) ){
/*1259*/ 				buffer_AddString((void *)&ParseDocBlock_res, ParseDocBlock_c);
/*1260*/ 				ParseDocBlock_readCh();
/*1263*/ 			}
/*1263*/ 			if( ((ParseDocBlock_c == NULL) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(64)) == 0)) ){
/*1266*/ 				goto m2runtime_loop_1;
/*1267*/ 			}
/*1267*/ 			buffer_AddString((void *)&ParseDocBlock_res, ParseDocBlock_upToEndOfLine());
/*1268*/ 			buffer_AddString((void *)&ParseDocBlock_res, m2runtime_CHR(10));
/*1270*/ 		}while(TRUE);
m2runtime_loop_1: ;
/*1270*/ 		return ParseDocBlock_trim(buffer_ToString(ParseDocBlock_res));
/*1274*/ 	}


/*1281*/ 	STRING *
/*1281*/ 	ParseDocBlock_getText(void)
/*1281*/ 	{
/*1281*/ 		return ParseDocBlock_textToHtml(ParseDocBlock_upToNextLineTag());
/*1285*/ 	}


/*1293*/ 	STRING *
/*1293*/ 	ParseDocBlock_getDescr(void)
/*1293*/ 	{
/*1293*/ 		return ParseDocBlock_expandInlineTags(ParseDocBlock_filterValidHtmlEntities(ParseDocBlock_upToNextLineTag()));
/*1297*/ 	}


/*1299*/ 	void
/*1299*/ 	ParseDocBlock_parseGlobal(void)
/*1299*/ 	{
/*1302*/ 		RECORD * ParseDocBlock_t = NULL;
/*1304*/ 		STRING * ParseDocBlock_n = NULL;
/*1307*/ 		ParseDocBlock_n = ParseDocBlock_getWord();
/*1308*/ 		if( m2runtime_strcmp(ParseDocBlock_n, EMPTY_STRING) <= 0 ){
/*1309*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"missing type in @global");
/*1310*/ 			ParseDocBlock_n = ParseDocBlock_getText();
/*1312*/ 			return ;
/*1313*/ 		}
/*1313*/ 		ParseDocBlock_t = ParseDocBlock_parseType(ParseDocBlock_n);
/*1314*/ 		if( ParseDocBlock_t == NULL ){
/*1316*/ 			ParseDocBlock_n = ParseDocBlock_getText();
/*1318*/ 			return ;
/*1323*/ 		}
/*1323*/ 		ParseDocBlock_n = ParseDocBlock_getWord();
/*1324*/ 		if( m2runtime_strcmp(ParseDocBlock_n, EMPTY_STRING) <= 0 ){
/*1325*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"missing variable name in @global");
/*1326*/ 			ParseDocBlock_n = ParseDocBlock_getText();
/*1328*/ 			return ;
/*1329*/ 		}
/*1329*/ 		if( (m2_match(ParseDocBlock_n, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"^\134$GLOBALS\134[\042", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"[a-zA-Z_\177-\377][a-zA-Z_0-9\177-\377]*", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"\042\134]$", (STRING *) 1)) || m2_match(ParseDocBlock_n, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"^\134$GLOBALS\134['", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"[a-zA-Z_\177-\377][a-zA-Z_0-9\177-\377]*", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"'\134]$", (STRING *) 1))) ){
/*1331*/ 			ParseDocBlock_n = m2runtime_substr(ParseDocBlock_n, 10, (m2runtime_length(ParseDocBlock_n) - 2), 1, ParseDocBlock_0err_entry_get, 93);
/*1332*/ 		} else if( m2_match(ParseDocBlock_n, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"^\134$", (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\34,\0,\0,\0)"[a-zA-Z_\177-\377][a-zA-Z_0-9\177-\377]*", m2runtime_CHR(36), (STRING *) 1)) ){
/*1333*/ 			ParseDocBlock_n = m2runtime_substr(ParseDocBlock_n, 1, m2runtime_length(ParseDocBlock_n), 1, ParseDocBlock_0err_entry_get, 94);
/*1335*/ 		} else {
/*1335*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"invalid variable name `", ParseDocBlock_n, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"' in @global", (STRING *) 1));
/*1336*/ 			ParseDocBlock_check_end_of_line_tag((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@global");
/*1338*/ 			return ;
/*1339*/ 		}
/*1339*/ 		ParseDocBlock_check_end_of_line_tag((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@global");
/*1340*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 1 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 95) = ParseDocBlock_t;
/*1341*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 2 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 96) = ParseDocBlock_n;
/*1345*/ 	}


/*1346*/ 	RECORD *
/*1346*/ 	ParseDocBlock_parseParam(int ParseDocBlock_position)
/*1346*/ 	{
/*1347*/ 		RECORD * ParseDocBlock_p = NULL;
/*1349*/ 		STRING * ParseDocBlock_w = NULL;
/*1352*/ 		ParseDocBlock_w = ParseDocBlock_getWord();
/*1353*/ 		if( ((m2runtime_strcmp(ParseDocBlock_w, EMPTY_STRING) > 0) && (m2runtime_strcmp(m2runtime_substr(ParseDocBlock_w, 0, 0, 0, ParseDocBlock_0err_entry_get, 97), m2runtime_CHR(36)) == 0)) ){
/*1354*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\65,\0,\0,\0)"invalid @param declaration: expected @param TYPE $var");
/*1355*/ 			ParseDocBlock_w = ParseDocBlock_getDescr();
/*1356*/ 			return NULL;
/*1358*/ 		} else {
/*1358*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_p, 3 * sizeof(void*) + 4 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 98) = ParseDocBlock_parseType(ParseDocBlock_w);
/*1359*/ 			if( (RECORD *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_p, 1 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 99) == Globals_void_type ){
/*1360*/ 				Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"@param cannot be `void'");
/*1361*/ 				*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_p, 3 * sizeof(void*) + 4 * sizeof(int), 3, 1 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 100) = NULL;
/*1364*/ 			}
/*1368*/ 		}
/*1368*/ 		ParseDocBlock_skipLWSP();
/*1369*/ 		if( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(38)) == 0 ){
/*1370*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_p, 3 * sizeof(void*) + 4 * sizeof(int), 3, 3 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 101) = TRUE;
/*1371*/ 			ParseDocBlock_readCh();
/*1377*/ 		}
/*1377*/ 		ParseDocBlock_w = ParseDocBlock_getWord();
/*1378*/ 		if( m2runtime_strcmp(ParseDocBlock_w, EMPTY_STRING) <= 0 ){
/*1379*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\46,\0,\0,\0)"missing parameter name for @param no. ", m2runtime_itos(((ParseDocBlock_position + 1))), (STRING *) 1));
/*1380*/ 			ParseDocBlock_w = ParseDocBlock_getDescr();
/*1381*/ 			return NULL;
/*1382*/ 		} else if( !m2_match(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\40,\0,\0,\0)"^\134$[a-zA-Z_\177-\377][a-zA-Z_0-9\177-\377]*$") ){
/*1383*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"invalid parameter name `", ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"', expected variable name `$varname'", (STRING *) 1));
/*1384*/ 			ParseDocBlock_w = ParseDocBlock_getDescr();
/*1385*/ 			return NULL;
/*1388*/ 		} else {
/*1388*/ 			*(STRING **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_p, 3 * sizeof(void*) + 4 * sizeof(int), 3, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 102) = m2runtime_substr(ParseDocBlock_w, 1, m2runtime_length(ParseDocBlock_w), 1, ParseDocBlock_0err_entry_get, 103);
/*1395*/ 		}
/*1395*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_p, 3 * sizeof(void*) + 4 * sizeof(int), 3, 2 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 104) = ParseDocBlock_getDescr();
/*1397*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_p, 3 * sizeof(void*) + 4 * sizeof(int), 3, 3 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 105) = FALSE;
/*1399*/ 		return ParseDocBlock_p;
/*1402*/ 	}


/*1407*/ 	void
/*1407*/ 	ParseDocBlock_ParseThrows(void)
/*1407*/ 	{
/*1408*/ 		STRING * ParseDocBlock_descr = NULL;
/*1408*/ 		STRING * ParseDocBlock_w = NULL;
/*1410*/ 		RECORD * ParseDocBlock_c = NULL;
/*1415*/ 		ParseDocBlock_w = ParseDocBlock_getWord();
/*1416*/ 		if( m2runtime_strcmp(ParseDocBlock_w, EMPTY_STRING) <= 0 ){
/*1417*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"missing class in @throws");
/*1419*/ 			return ;
/*1421*/ 		}
/*1421*/ 		ParseDocBlock_c = ParseDocBlock_SearchClass(ParseDocBlock_resolve_namespace_operator(ParseDocBlock_w));
/*1422*/ 		if( ParseDocBlock_c == NULL ){
/*1423*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"unknown exception `", ParseDocBlock_w, m2runtime_CHR(39), (STRING *) 1));
/*1424*/ 		} else if( !Classes_IsExceptionClass(ParseDocBlock_c) ){
/*1425*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"class `", ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"' is not an exception", (STRING *) 1));
/*1426*/ 			ParseDocBlock_c = NULL;
/*1429*/ 		}
/*1429*/ 		ParseDocBlock_descr = ParseDocBlock_getDescr();
/*1431*/ 		if( ParseDocBlock_c != NULL ){
/*1432*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 6 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 106), sizeof(void *), 1, ParseDocBlock_0err_entry_get, 107) = ParseDocBlock_c;
/*1433*/ 			if( m2runtime_strcmp(ParseDocBlock_descr, EMPTY_STRING) > 0 ){
/*1434*/ 				*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 7 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 108), sizeof(void *), 1, ParseDocBlock_0err_entry_get, 109) = (
/*1434*/ 					push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*1434*/ 					push((char*) ParseDocBlock_c),
/*1434*/ 					*(RECORD**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1434*/ 					push((char*) ParseDocBlock_descr),
/*1435*/ 					*(STRING**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*1436*/ 					(RECORD*) pop()
/*1436*/ 				);
/*1437*/ 			}
/*1438*/ 		}
/*1440*/ 	}


/*1442*/ 	void
/*1442*/ 	ParseDocBlock_parseUnsupportedUnimplementedLineTag(STRING *ParseDocBlock_w)
/*1442*/ 	{
/*1442*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"<br>", ParseDocBlock_textToHtml(m2runtime_concat_STRING(0, ParseDocBlock_w, m2runtime_CHR(32), ParseDocBlock_getText(), (STRING *) 1)), (STRING *) 1));
/*1447*/ 	}

/*1448*/ 	RECORD * ParseDocBlock_p = NULL;
/*1449*/ 	int ParseDocBlock_position = 0;
/*1451*/ 	STRING * ParseDocBlock_url = NULL;
/*1451*/ 	STRING * ParseDocBlock_w = NULL;
/*1451*/ 	ParseDocBlock_w = ParseDocBlock_getWord();
/*1461*/ 	if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"@abstract") == 0 ){
/*1462*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 8 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 110) = TRUE;
/*1463*/ 		ParseDocBlock_check_end_of_line_tag((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"@abstract");
/*1466*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@access") == 0 ){
/*1467*/ 		ParseDocBlock_w = ParseDocBlock_getWord();
/*1468*/ 		if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"private") == 0 ){
/*1469*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 8 * sizeof(void*) + 4 * sizeof(int), ParseDocBlock_0err_entry_get, 111) = TRUE;
/*1470*/ 		} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"protected") == 0 ){
/*1471*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 8 * sizeof(void*) + 5 * sizeof(int), ParseDocBlock_0err_entry_get, 112) = TRUE;
/*1472*/ 		} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"public") == 0 ){
/*1473*/ 			*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 8 * sizeof(void*) + 6 * sizeof(int), ParseDocBlock_0err_entry_get, 113) = TRUE;
/*1475*/ 		} else {
/*1475*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\57,\0,\0,\0)"expected public|protected|private after @access");
/*1477*/ 		}
/*1477*/ 		ParseDocBlock_check_end_of_line_tag((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@access");
/*1480*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@author") == 0 ){
/*1481*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"<@author ", ParseDocBlock_getText(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">\012", (STRING *) 1));
/*1484*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"@copyright") == 0 ){
/*1485*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\14,\0,\0,\0)"<@copyright ", ParseDocBlock_getDescr(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">\012", (STRING *) 1));
/*1488*/ 	} else if( ((m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"@deprecated") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@deprec") == 0)) ){
/*1489*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"\012<@deprecated ", ParseDocBlock_getDescr(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">\012", (STRING *) 1));
/*1492*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"@final") == 0 ){
/*1493*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 8 * sizeof(void*) + 7 * sizeof(int), ParseDocBlock_0err_entry_get, 114) = TRUE;
/*1494*/ 		ParseDocBlock_check_end_of_line_tag((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"@final");
/*1497*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@global") == 0 ){
/*1498*/ 		ParseDocBlock_parseGlobal();
/*1501*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"@license") == 0 ){
/*1502*/ 		ParseDocBlock_url = ParseDocBlock_getWord();
/*1503*/ 		ParseDocBlock_w = ParseDocBlock_getText();
/*1504*/ 		if( (m2runtime_length(ParseDocBlock_w) == 0) ){
/*1505*/ 			ParseDocBlock_w = ParseDocBlock_url;
/*1507*/ 		}
/*1507*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"\012<@license <a href=\042", ParseDocBlock_url, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\042>", ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"</a>>\012", (STRING *) 1));
/*1510*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"@link") == 0 ){
/*1511*/ 		ParseDocBlock_url = ParseDocBlock_getWord();
/*1512*/ 		ParseDocBlock_w = ParseDocBlock_getText();
/*1513*/ 		if( (m2runtime_length(ParseDocBlock_w) == 0) ){
/*1514*/ 			ParseDocBlock_w = ParseDocBlock_url;
/*1516*/ 		}
/*1516*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"\012<p><b>Link:</b> <a href=\042", ParseDocBlock_url, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\042>", ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"</a></p>\012", (STRING *) 1));
/*1519*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"@package") == 0 ){
/*1520*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 8 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 115) = TRUE;
/*1521*/ 		ParseDocBlock_w = ParseDocBlock_getWord();
/*1522*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"<@package ", ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">\012", (STRING *) 1));
/*1523*/ 		ParseDocBlock_check_end_of_line_tag((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"@package");
/*1526*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"@param") == 0 ){
/*1527*/ 		if( ParseDocBlock_pdb == NULL ){
/*1528*/ 			ParseDocBlock_position = 0;
/*1530*/ 		} else {
/*1530*/ 			ParseDocBlock_position = m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 116));
/*1532*/ 		}
/*1532*/ 		ParseDocBlock_p = ParseDocBlock_parseParam(ParseDocBlock_position);
/*1533*/ 		if( ParseDocBlock_p != NULL ){
/*1534*/ 			if( ParseDocBlock_pdb == NULL ){
/*1535*/ 				*(ARRAY **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 117) = NULL;
/*1537*/ 			}
/*1537*/ 			*(RECORD **)m2runtime_dereference_lhs_ARRAY_next((ARRAY **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 118), sizeof(void *), 1, ParseDocBlock_0err_entry_get, 119) = ParseDocBlock_p;
/*1541*/ 		}
/*1541*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@return") == 0 ){
/*1542*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 4 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 120) = ParseDocBlock_parseType(ParseDocBlock_getWord());
/*1543*/ 		ParseDocBlock_return_descr = ParseDocBlock_getDescr();
/*1548*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"@see") == 0 ){
/*1549*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"<@see ", ParseDocBlock_getWord(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">\012", (STRING *) 1));
/*1550*/ 		ParseDocBlock_check_end_of_line_tag((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"@see");
/*1553*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"@since") == 0 ){
/*1554*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"\012<@since ", ParseDocBlock_getDescr(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">\012", (STRING *) 1));
/*1557*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@static") == 0 ){
/*1558*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 8 * sizeof(void*) + 8 * sizeof(int), ParseDocBlock_0err_entry_get, 121) = TRUE;
/*1559*/ 		ParseDocBlock_check_end_of_line_tag((STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@static");
/*1562*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@throws") == 0 ){
/*1563*/ 		ParseDocBlock_ParseThrows();
/*1566*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"@todo") == 0 ){
/*1567*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"\012<p>\012<b>To-do:</b>\012", ParseDocBlock_getDescr(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"\012</p>\012", (STRING *) 1));
/*1571*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\4,\0,\0,\0)"@var") == 0 ){
/*1572*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 3 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 122) = ParseDocBlock_parseType(ParseDocBlock_getWord());
/*1573*/ 		if( (RECORD *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 3 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 123) == Globals_void_type ){
/*1574*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\25,\0,\0,\0)"@var cannot be `void'");
/*1575*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 3 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 124) = NULL;
/*1577*/ 		}
/*1577*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, ParseDocBlock_getDescr(), m2runtime_CHR(10), (STRING *) 1));
/*1580*/ 	} else if( m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"@version") == 0 ){
/*1581*/ 		ParseDocBlock_w = ParseDocBlock_getDescr();
/*1582*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"<@version ", ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)">\012", (STRING *) 1));
/*1585*/ 	} else if( ((m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"@example") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"@category") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"@example") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"@exception") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"@filesource") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)"@ignore") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"@internal") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"@name") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"@staticvar") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"@subpackage") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\11,\0,\0,\0)"@tutorial") == 0) || (m2runtime_strcmp(ParseDocBlock_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"@uses") == 0)) ){
/*1598*/ 		Scanner_Notice2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"unsupported line tag `", ParseDocBlock_w, m2runtime_CHR(39), (STRING *) 1));
/*1599*/ 		ParseDocBlock_parseUnsupportedUnimplementedLineTag(ParseDocBlock_w);
/*1602*/ 	} else {
/*1602*/ 		Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\22,\0,\0,\0)"unknown line tag `", ParseDocBlock_w, m2runtime_CHR(39), (STRING *) 1));
/*1603*/ 		ParseDocBlock_parseUnsupportedUnimplementedLineTag(ParseDocBlock_w);
/*1607*/ 	}
/*1609*/ }


/*1616*/ void
/*1616*/ ParseDocBlock_parseShortAndLongDescr(STRING **ParseDocBlock_short, STRING **ParseDocBlock_long)
/*1616*/ {

/*1622*/ 	int
/*1622*/ 	ParseDocBlock_findPeriod(STRING *ParseDocBlock_s)
/*1622*/ 	{
/*1623*/ 		int ParseDocBlock_i = 0;
/*1625*/ 		STRING * ParseDocBlock_next_ch = NULL;
/*1626*/ 		do{
/*1626*/ 			ParseDocBlock_i = str_index(ParseDocBlock_s, ParseDocBlock_i, m2runtime_CHR(46));
/*1627*/ 			if( (ParseDocBlock_i < 0) ){
/*1628*/ 				return -1;
/*1629*/ 			} else if( (ParseDocBlock_i == (m2runtime_length(ParseDocBlock_s) - 1)) ){
/*1630*/ 				return ParseDocBlock_i;
/*1632*/ 			}
/*1632*/ 			ParseDocBlock_next_ch = m2runtime_substr(ParseDocBlock_s, (ParseDocBlock_i + 1), 0, 0, ParseDocBlock_0err_entry_get, 125);
/*1633*/ 			if( ((m2runtime_strcmp(ParseDocBlock_next_ch, m2runtime_CHR(32)) == 0) || (m2runtime_strcmp(ParseDocBlock_next_ch, m2runtime_CHR(9)) == 0) || (m2runtime_strcmp(ParseDocBlock_next_ch, m2runtime_CHR(10)) == 0)) ){
/*1634*/ 				return ParseDocBlock_i;
/*1636*/ 			}
/*1636*/ 			m2_inc(&ParseDocBlock_i, 1);
/*1639*/ 		}while(TRUE);
/*1639*/ 		m2runtime_missing_return(ParseDocBlock_0err_entry_get, 126);
/*1639*/ 		return 0;
/*1641*/ 	}

/*1642*/ 	int ParseDocBlock_x = 0;
/*1642*/ 	int ParseDocBlock_i = 0;
/*1643*/ 	void * ParseDocBlock_b = NULL;
/*1644*/ 	STRING * ParseDocBlock_s = NULL;
/*1644*/ 	STRING * ParseDocBlock_spaces = NULL;
/*1647*/ 	ARRAY * ParseDocBlock_a = NULL;
/*1647*/ 	*ParseDocBlock_short = NULL;
/*1648*/ 	*ParseDocBlock_long = NULL;
/*1651*/ 	while( (ParseDocBlock_isLWSP(ParseDocBlock_c) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(10)) == 0)) ){
/*1652*/ 		ParseDocBlock_readCh();
/*1655*/ 	}
/*1655*/ 	buffer_Reset(*(void **)(void *)&ParseDocBlock_b);
/*1668*/ 	do{
/*1668*/ 		ParseDocBlock_spaces = EMPTY_STRING;
/*1669*/ 		while( ParseDocBlock_isLWSP(ParseDocBlock_c) ){
/*1670*/ 			ParseDocBlock_spaces = m2runtime_concat_STRING(0, ParseDocBlock_spaces, ParseDocBlock_c, (STRING *) 1);
/*1671*/ 			ParseDocBlock_readCh();
/*1674*/ 		}
/*1674*/ 		if( ((ParseDocBlock_c == NULL) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(64)) == 0)) ){
/*1675*/ 			*ParseDocBlock_short = str_join(ParseDocBlock_a, m2runtime_CHR(32));
/*1678*/ 			goto m2runtime_loop_1;
/*1679*/ 		}
/*1679*/ 		ParseDocBlock_s = ParseDocBlock_upToEndOfLine();
/*1681*/ 		if( m2runtime_strcmp(ParseDocBlock_s, EMPTY_STRING) <= 0 ){
/*1682*/ 			*ParseDocBlock_short = str_join(ParseDocBlock_a, m2runtime_CHR(32));
/*1685*/ 			goto m2runtime_loop_1;
/*1686*/ 		}
/*1686*/ 		ParseDocBlock_s = m2runtime_concat_STRING(0, ParseDocBlock_spaces, ParseDocBlock_s, (STRING *) 1);
/*1688*/ 		ParseDocBlock_x = ParseDocBlock_findPeriod(ParseDocBlock_s);
/*1690*/ 		if( (ParseDocBlock_x > 0) ){
/*1691*/ 			*ParseDocBlock_short = m2runtime_concat_STRING(0, str_join(ParseDocBlock_a, m2runtime_CHR(32)), m2runtime_CHR(32), m2runtime_substr(ParseDocBlock_s, 0, ParseDocBlock_x, 1, ParseDocBlock_0err_entry_get, 127), (STRING *) 1);
/*1692*/ 			buffer_AddString((void *)&ParseDocBlock_b, m2runtime_substr(ParseDocBlock_s, (ParseDocBlock_x + 1), m2runtime_length(ParseDocBlock_s), 1, ParseDocBlock_0err_entry_get, 128));
/*1693*/ 			buffer_AddString((void *)&ParseDocBlock_b, m2runtime_CHR(10));
/*1696*/ 			goto m2runtime_loop_1;
/*1697*/ 		}
/*1697*/ 		*(STRING **)m2runtime_dereference_lhs_ARRAY_next(&ParseDocBlock_a, sizeof(void *), 1, ParseDocBlock_0err_entry_get, 129) = ParseDocBlock_s;
/*1699*/ 		if( (m2runtime_count(ParseDocBlock_a) >= 3) ){
/*1700*/ 			*ParseDocBlock_short = (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_a, 0, ParseDocBlock_0err_entry_get, 130);
/*1701*/ 			{
/*1701*/ 				int m2runtime_for_limit_1;
/*1701*/ 				ParseDocBlock_i = 1;
/*1701*/ 				m2runtime_for_limit_1 = (m2runtime_count(ParseDocBlock_a) - 1);
/*1702*/ 				for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*1702*/ 					buffer_AddString((void *)&ParseDocBlock_b, (STRING *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_a, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 131));
/*1703*/ 					buffer_AddString((void *)&ParseDocBlock_b, m2runtime_CHR(10));
/*1706*/ 				}
/*1706*/ 			}
/*1707*/ 			goto m2runtime_loop_1;
/*1709*/ 		}
/*1714*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*1716*/ 	do{
/*1716*/ 		ParseDocBlock_s = EMPTY_STRING;
/*1717*/ 		while( ParseDocBlock_isLWSP(ParseDocBlock_c) ){
/*1718*/ 			ParseDocBlock_s = m2runtime_concat_STRING(0, ParseDocBlock_s, ParseDocBlock_c, (STRING *) 1);
/*1719*/ 			ParseDocBlock_readCh();
/*1722*/ 		}
/*1722*/ 		if( ((ParseDocBlock_c == NULL) || (m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(64)) == 0)) ){
/*1725*/ 			goto m2runtime_loop_2;
/*1726*/ 		}
/*1726*/ 		ParseDocBlock_s = m2runtime_concat_STRING(0, ParseDocBlock_s, ParseDocBlock_upToEndOfLine(), (STRING *) 1);
/*1727*/ 		buffer_AddString((void *)&ParseDocBlock_b, ParseDocBlock_s);
/*1728*/ 		buffer_AddString((void *)&ParseDocBlock_b, m2runtime_CHR(10));
/*1731*/ 	}while(TRUE);
m2runtime_loop_2: ;
/*1731*/ 	*ParseDocBlock_short = ParseDocBlock_expandInlineTags(ParseDocBlock_filterValidHtmlEntities(*ParseDocBlock_short));
/*1732*/ 	*ParseDocBlock_long = ParseDocBlock_expandInlineTags(ParseDocBlock_filterValidHtmlEntities(buffer_ToString(ParseDocBlock_b)));
/*1736*/ }


/*1740*/ RECORD *
/*1740*/ ParseDocBlock_ParseDocBlock(STRING *ParseDocBlock_doc)
/*1740*/ {
/*1741*/ 	RECORD * ParseDocBlock_p = NULL;
/*1743*/ 	int ParseDocBlock_i = 0;
/*1747*/ 	int ParseDocBlock_is_template = 0;
/*1750*/ 	STRING * ParseDocBlock_long = NULL;
/*1750*/ 	STRING * ParseDocBlock_short = NULL;
/*1750*/ 	if( !ParseDocBlock_parse_phpdoc ){
/*1751*/ 		return NULL;
/*1757*/ 	}
/*1757*/ 	if( (((m2runtime_length(ParseDocBlock_doc) >= 8)) && (m2runtime_strcmp(m2runtime_substr(ParseDocBlock_doc, 0, 6, 1, ParseDocBlock_0err_entry_get, 132), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"/**#@+") == 0)) ){
/*1758*/ 		if( ParseDocBlock_template != NULL ){
/*1759*/ 			Scanner_Error2(Scanner_here(), m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\60,\0,\0,\0)"missing closing /**#@-*/ for template opened in ", Scanner_reference(ParseDocBlock_template_where), (STRING *) 1));
/*1762*/ 		}
/*1762*/ 		ParseDocBlock_is_template = TRUE;
/*1763*/ 		ParseDocBlock_template = NULL;
/*1764*/ 		ParseDocBlock_template_where = Scanner_here();
/*1770*/ 	}
/*1770*/ 	if( m2runtime_strcmp(ParseDocBlock_doc, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"/**#@-*/") == 0 ){
/*1771*/ 		if( ParseDocBlock_template == NULL ){
/*1772*/ 			Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\33,\0,\0,\0)"no previous template opened");
/*1774*/ 		}
/*1774*/ 		ParseDocBlock_template = NULL;
/*1777*/ 	}
/*1777*/ 	if( ParseDocBlock_types == NULL ){
/*1778*/ 		ParseDocBlock_types = (
/*1779*/ 			push((char*) alloc_ARRAY(sizeof(void *), 1)),
/*1779*/ 			push((char*) (
/*1779*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*1779*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"int"),
/*1779*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*1779*/ 				push((char*) Globals_int_type),
/*1779*/ 				*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1780*/ 				(RECORD*) pop()
/*1780*/ 			)),
/*1780*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),0) = (RECORD*) tos(), pop(),
/*1780*/ 			push((char*) (
/*1780*/ 				push((char*) alloc_RECORD(2 * sizeof(void*) + 2 * sizeof(int), 2)),
/*1780*/ 				push((char*) (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\6,\0,\0,\0)"string"),
/*1780*/ 				*(STRING**) (tosn(1)+0 * sizeof(void*) + 2 * sizeof(int)) = (STRING*) tos(), pop(),
/*1780*/ 				push((char*) Globals_string_type),
/*1781*/ 				*(RECORD**) (tosn(1)+1 * sizeof(void*) + 2 * sizeof(int)) = (RECORD*) tos(), pop(),
/*1782*/ 				(RECORD*) pop()
/*1782*/ 			)),
/*1782*/ 			*(RECORD**) element_ARRAY((ARRAY*) tosn(1),1) = (RECORD*) tos(), pop(),
/*1783*/ 			(ARRAY*) pop()
/*1783*/ 		);
/*1785*/ 	}
/*1785*/ 	ParseDocBlock_in = ParseDocBlock_doc;
/*1786*/ 	if( ParseDocBlock_is_template ){
/*1788*/ 		ParseDocBlock_pos = 6;
/*1790*/ 	} else {
/*1790*/ 		ParseDocBlock_pos = 3;
/*1792*/ 	}
/*1792*/ 	ParseDocBlock_line_n = 1;
/*1793*/ 	ParseDocBlock_len = m2runtime_length(ParseDocBlock_doc);
/*1794*/ 	if( (ParseDocBlock_len <= 5) ){
/*1795*/ 		return NULL;
/*1797*/ 	}
/*1797*/ 	ParseDocBlock_len = (ParseDocBlock_len - 2);
/*1798*/ 	ParseDocBlock_c = m2runtime_CHR(32);
/*1799*/ 	ParseDocBlock_readCh();
/*1802*/ 	ParseDocBlock_pdb = NULL;
/*1803*/ 	ParseDocBlock_return_descr = NULL;
/*1804*/ 	buffer_Reset(*(void **)(void *)&ParseDocBlock_descr);
/*1806*/ 	ParseDocBlock_parseShortAndLongDescr(&ParseDocBlock_short, &ParseDocBlock_long);
/*1807*/ 	if( ((m2runtime_strcmp(ParseDocBlock_short, EMPTY_STRING) > 0) || (m2runtime_strcmp(ParseDocBlock_long, EMPTY_STRING) > 0)) ){
/*1808*/ 		buffer_AddString((void *)&ParseDocBlock_descr, ParseDocBlock_short);
/*1809*/ 		buffer_AddString((void *)&ParseDocBlock_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"\012\012");
/*1810*/ 		buffer_AddString((void *)&ParseDocBlock_descr, ParseDocBlock_long);
/*1817*/ 	}
/*1817*/ 	while( ParseDocBlock_isLWSP(ParseDocBlock_c) ){
/*1818*/ 		ParseDocBlock_readCh();
/*1821*/ 	}
/*1821*/ 	while( m2runtime_strcmp(ParseDocBlock_c, m2runtime_CHR(64)) == 0 ){
/*1822*/ 		ParseDocBlock_parseLineTag();
/*1825*/ 	}
/*1825*/ 	if( ParseDocBlock_c != NULL ){
/*1826*/ 		m2runtime_HALT(ParseDocBlock_0err_entry_get, 133, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\36,\0,\0,\0)"expected @ in DocBlock, found ", m2runtime_StringToLiteral(ParseDocBlock_c), (STRING *) 1));
/*1833*/ 	}
/*1833*/ 	if( ((ParseDocBlock_pdb != NULL) && ((ARRAY *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 134) != NULL)) ){
/*1834*/ 		buffer_Reset(*(void **)(void *)&ParseDocBlock_b);
/*1835*/ 		{
/*1835*/ 			int m2runtime_for_limit_1;
/*1835*/ 			ParseDocBlock_i = 0;
/*1835*/ 			m2runtime_for_limit_1 = (m2runtime_count((ARRAY *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 135)) - 1);
/*1836*/ 			for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*1836*/ 				ParseDocBlock_p = (RECORD *)m2runtime_dereference_rhs_ARRAY((ARRAY *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 136), ParseDocBlock_i, ParseDocBlock_0err_entry_get, 137);
/*1837*/ 				if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_p, 2 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 138), EMPTY_STRING) > 0 ){
/*1838*/ 					buffer_AddString((void *)&ParseDocBlock_b, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"<tr><td valign=top><b><code>$", (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_p, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 139), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)"&nbsp;&nbsp;</code></b></td> <td valign=top>", (STRING *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_p, 2 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 140), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"</td></tr>\012", (STRING *) 1));
/*1843*/ 				}
/*1843*/ 			}
/*1843*/ 		}
/*1843*/ 		if( (buffer_Length(ParseDocBlock_b) > 0) ){
/*1844*/ 			buffer_AddString((void *)&ParseDocBlock_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\37,\0,\0,\0)"\012<p><b>Parameters:</b>\012<table>\012");
/*1845*/ 			buffer_AddString((void *)&ParseDocBlock_descr, buffer_ToString(ParseDocBlock_b));
/*1846*/ 			buffer_AddString((void *)&ParseDocBlock_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\16,\0,\0,\0)"</table>\012</p>\012");
/*1849*/ 		}
/*1853*/ 	}
/*1853*/ 	if( m2runtime_strcmp(ParseDocBlock_return_descr, EMPTY_STRING) > 0 ){
/*1854*/ 		buffer_AddString((void *)&ParseDocBlock_descr, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\23,\0,\0,\0)"\012<p><b>Return:</b> ", ParseDocBlock_return_descr, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\5,\0,\0,\0)"</p>\012", (STRING *) 1));
/*1857*/ 	}
/*1857*/ 	if( (buffer_Length(ParseDocBlock_descr) > 0) ){
/*1858*/ 		*(STRING **)m2runtime_dereference_lhs_RECORD(&ParseDocBlock_pdb, 8 * sizeof(void*) + 9 * sizeof(int), 8, 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 141) = buffer_ToString(ParseDocBlock_descr);
/*1861*/ 	}
/*1861*/ 	if( ParseDocBlock_pdb == NULL ){
/*1862*/ 		if( ParseDocBlock_is_template ){
/*1863*/ 			Scanner_Notice2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"useless empty template");
/*1865*/ 		}
/*1865*/ 		return NULL;
/*1871*/ 	}
/*1871*/ 	if( (( *(int *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 8 * sizeof(void*) + 4 * sizeof(int), ParseDocBlock_0err_entry_get, 142) && (( *(int *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 8 * sizeof(void*) + 5 * sizeof(int), ParseDocBlock_0err_entry_get, 143) ||  *(int *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 8 * sizeof(void*) + 6 * sizeof(int), ParseDocBlock_0err_entry_get, 144)))) || ( *(int *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 8 * sizeof(void*) + 5 * sizeof(int), ParseDocBlock_0err_entry_get, 145) &&  *(int *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 8 * sizeof(void*) + 6 * sizeof(int), ParseDocBlock_0err_entry_get, 146))) ){
/*1873*/ 		Scanner_Error2(Scanner_here(), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\35,\0,\0,\0)"multiple @access declarations");
/*1876*/ 	}
/*1876*/ 	if( ParseDocBlock_is_template ){
/*1877*/ 		ParseDocBlock_template = ParseDocBlock_pdb;
/*1880*/ 	}
/*1880*/ 	return ParseDocBlock_pdb;
/*1884*/ }


/*1886*/ RECORD *
/*1886*/ ParseDocBlock_SearchParam(RECORD *ParseDocBlock_pdb, STRING *ParseDocBlock_name)
/*1886*/ {
/*1887*/ 	ARRAY * ParseDocBlock_params = NULL;
/*1889*/ 	int ParseDocBlock_i = 0;
/*1889*/ 	if( ParseDocBlock_pdb == NULL ){
/*1890*/ 		return NULL;
/*1892*/ 	}
/*1892*/ 	ParseDocBlock_params = (ARRAY *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 147);
/*1893*/ 	{
/*1893*/ 		int m2runtime_for_limit_1;
/*1893*/ 		ParseDocBlock_i = 0;
/*1893*/ 		m2runtime_for_limit_1 = (m2runtime_count(ParseDocBlock_params) - 1);
/*1894*/ 		for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*1894*/ 			if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_params, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 148), 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 149), ParseDocBlock_name) == 0 ){
/*1895*/ 				return (RECORD *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_params, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 150);
/*1898*/ 			}
/*1899*/ 		}
/*1899*/ 	}
/*1899*/ 	return NULL;
/*1903*/ }


/*1905*/ void
/*1905*/ ParseDocBlock_ReportUnusedParams(RECORD *ParseDocBlock_pdb)
/*1905*/ {
/*1906*/ 	ARRAY * ParseDocBlock_params = NULL;
/*1908*/ 	int ParseDocBlock_i = 0;
/*1908*/ 	if( ParseDocBlock_pdb == NULL ){
/*1910*/ 		return ;
/*1911*/ 	}
/*1911*/ 	ParseDocBlock_params = (ARRAY *)m2runtime_dereference_rhs_RECORD(ParseDocBlock_pdb, 5 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 151);
/*1912*/ 	{
/*1912*/ 		int m2runtime_for_limit_1;
/*1912*/ 		ParseDocBlock_i = 0;
/*1912*/ 		m2runtime_for_limit_1 = (m2runtime_count(ParseDocBlock_params) - 1);
/*1913*/ 		for( ; ParseDocBlock_i <= m2runtime_for_limit_1; ParseDocBlock_i += 1 ){
/*1913*/ 			if( ! *(int *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_params, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 152), 3 * sizeof(void*) + 3 * sizeof(int), ParseDocBlock_0err_entry_get, 153) ){
/*1914*/ 				Scanner_Error(m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"undefined parameter `$", (STRING *)m2runtime_dereference_rhs_RECORD((RECORD *)m2runtime_dereference_rhs_ARRAY(ParseDocBlock_params, ParseDocBlock_i, ParseDocBlock_0err_entry_get, 154), 0 * sizeof(void*) + 2 * sizeof(int), ParseDocBlock_0err_entry_get, 155), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\32,\0,\0,\0)"' listed un DocBlock above", (STRING *) 1));
/*1918*/ 			}
/*1919*/ 		}
/*1919*/ 	}
/*1922*/ }


char * ParseDocBlock_0func[] = {
    "Suspend",
    "Resume",
    "trim",
    "lowLevelReadCh",
    "readCh",
    "skipEscapedUnicodeChar",
    "textToHtml",
    "SearchClass",
    "resolve_namespace_operator",
    "resolve_ns",
    "expandInlineTags",
    "detectTag",
    "nextTag",
    "short",
    "splitParagraphes",
    "addChunk",
    "parseHtml",
    "next_sym",
    "isKeyword",
    "ParseTypeName",
    "ParseArray",
    "ParseIndeces",
    "getWord",
    "parseGlobal",
    "parseParam",
    "ParseThrows",
    "parseLineTag",
    "findPeriod",
    "parseShortAndLongDescr",
    "ParseDocBlock",
    "SearchParam",
    "ReportUnusedParams"
};

int ParseDocBlock_0err_entry[] = {
    0 /* Suspend */, 64,
    0 /* Suspend */, 65,
    0 /* Suspend */, 66,
    0 /* Suspend */, 67,
    0 /* Suspend */, 68,
    0 /* Suspend */, 69,
    0 /* Suspend */, 70,
    0 /* Suspend */, 71,
    0 /* Suspend */, 72,
    0 /* Suspend */, 73,
    1 /* Resume */, 84,
    1 /* Resume */, 85,
    1 /* Resume */, 86,
    1 /* Resume */, 87,
    1 /* Resume */, 88,
    1 /* Resume */, 89,
    1 /* Resume */, 90,
    1 /* Resume */, 91,
    1 /* Resume */, 92,
    1 /* Resume */, 93,
    2 /* trim */, 120,
    2 /* trim */, 124,
    2 /* trim */, 127,
    3 /* lowLevelReadCh */, 149,
    3 /* lowLevelReadCh */, 158,
    3 /* lowLevelReadCh */, 162,
    4 /* readCh */, 193,
    5 /* skipEscapedUnicodeChar */, 219,
    5 /* skipEscapedUnicodeChar */, 225,
    6 /* textToHtml */, 234,
    6 /* textToHtml */, 244,
    7 /* SearchClass */, 290,
    7 /* SearchClass */, 294,
    7 /* SearchClass */, 298,
    8 /* resolve_namespace_operator */, 306,
    8 /* resolve_namespace_operator */, 307,
    8 /* resolve_namespace_operator */, 310,
    8 /* resolve_namespace_operator */, 315,
    9 /* resolve_ns */, 340,
    9 /* resolve_ns */, 341,
    9 /* resolve_ns */, 347,
    9 /* resolve_ns */, 360,
    9 /* resolve_ns */, 362,
    9 /* resolve_ns */, 368,
    9 /* resolve_ns */, 368,
    9 /* resolve_ns */, 376,
    9 /* resolve_ns */, 382,
    9 /* resolve_ns */, 382,
    9 /* resolve_ns */, 390,
    9 /* resolve_ns */, 398,
    10 /* expandInlineTags */, 437,
    10 /* expandInlineTags */, 443,
    10 /* expandInlineTags */, 445,
    10 /* expandInlineTags */, 453,
    10 /* expandInlineTags */, 462,
    10 /* expandInlineTags */, 470,
    10 /* expandInlineTags */, 478,
    10 /* expandInlineTags */, 481,
    10 /* expandInlineTags */, 486,
    10 /* expandInlineTags */, 496,
    10 /* expandInlineTags */, 502,
    10 /* expandInlineTags */, 509,
    10 /* expandInlineTags */, 519,
    10 /* expandInlineTags */, 523,
    10 /* expandInlineTags */, 528,
    10 /* expandInlineTags */, 534,
    11 /* detectTag */, 583,
    11 /* detectTag */, 583,
    12 /* nextTag */, 598,
    13 /* short */, 609,
    14 /* splitParagraphes */, 637,
    14 /* splitParagraphes */, 640,
    14 /* splitParagraphes */, 644,
    14 /* splitParagraphes */, 648,
    15 /* addChunk */, 660,
    16 /* parseHtml */, 806,
    17 /* next_sym */, 970,
    17 /* next_sym */, 979,
    17 /* next_sym */, 984,
    18 /* isKeyword */, 1005,
    19 /* ParseTypeName */, 1050,
    19 /* ParseTypeName */, 1057,
    20 /* ParseArray */, 1067,
    20 /* ParseArray */, 1070,
    20 /* ParseArray */, 1079,
    20 /* ParseArray */, 1081,
    21 /* ParseIndeces */, 1099,
    21 /* ParseIndeces */, 1102,
    21 /* ParseIndeces */, 1105,
    21 /* ParseIndeces */, 1113,
    21 /* ParseIndeces */, 1114,
    21 /* ParseIndeces */, 1118,
    22 /* getWord */, 1244,
    23 /* parseGlobal */, 1331,
    23 /* parseGlobal */, 1333,
    23 /* parseGlobal */, 1340,
    23 /* parseGlobal */, 1341,
    24 /* parseParam */, 1353,
    24 /* parseParam */, 1358,
    24 /* parseParam */, 1359,
    24 /* parseParam */, 1361,
    24 /* parseParam */, 1370,
    24 /* parseParam */, 1388,
    24 /* parseParam */, 1388,
    24 /* parseParam */, 1395,
    24 /* parseParam */, 1397,
    25 /* ParseThrows */, 1432,
    25 /* ParseThrows */, 1432,
    25 /* ParseThrows */, 1434,
    25 /* ParseThrows */, 1434,
    26 /* parseLineTag */, 1462,
    26 /* parseLineTag */, 1469,
    26 /* parseLineTag */, 1471,
    26 /* parseLineTag */, 1473,
    26 /* parseLineTag */, 1493,
    26 /* parseLineTag */, 1520,
    26 /* parseLineTag */, 1530,
    26 /* parseLineTag */, 1535,
    26 /* parseLineTag */, 1537,
    26 /* parseLineTag */, 1537,
    26 /* parseLineTag */, 1542,
    26 /* parseLineTag */, 1558,
    26 /* parseLineTag */, 1572,
    26 /* parseLineTag */, 1573,
    26 /* parseLineTag */, 1575,
    27 /* findPeriod */, 1632,
    27 /* findPeriod */, 1638,
    28 /* parseShortAndLongDescr */, 1691,
    28 /* parseShortAndLongDescr */, 1692,
    28 /* parseShortAndLongDescr */, 1697,
    28 /* parseShortAndLongDescr */, 1701,
    28 /* parseShortAndLongDescr */, 1702,
    29 /* ParseDocBlock */, 1757,
    29 /* ParseDocBlock */, 1826,
    29 /* ParseDocBlock */, 1833,
    29 /* ParseDocBlock */, 1835,
    29 /* ParseDocBlock */, 1836,
    29 /* ParseDocBlock */, 1837,
    29 /* ParseDocBlock */, 1837,
    29 /* ParseDocBlock */, 1839,
    29 /* ParseDocBlock */, 1840,
    29 /* ParseDocBlock */, 1858,
    29 /* ParseDocBlock */, 1871,
    29 /* ParseDocBlock */, 1871,
    29 /* ParseDocBlock */, 1871,
    29 /* ParseDocBlock */, 1872,
    29 /* ParseDocBlock */, 1872,
    30 /* SearchParam */, 1892,
    30 /* SearchParam */, 1894,
    30 /* SearchParam */, 1894,
    30 /* SearchParam */, 1896,
    31 /* ReportUnusedParams */, 1911,
    31 /* ReportUnusedParams */, 1913,
    31 /* ReportUnusedParams */, 1913,
    31 /* ReportUnusedParams */, 1914,
    31 /* ReportUnusedParams */, 1914
};

void ParseDocBlock_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "ParseDocBlock";
    *f = ParseDocBlock_0func[ ParseDocBlock_0err_entry[2*i] ];
    *l = ParseDocBlock_0err_entry[2*i + 1];
}
