/* IMPLEMENTATION MODULE FileName */
#define M2_IMPORT_FileName

#ifndef M2_IMPORT_m2
#    include "m2.c"
#endif

#ifndef M2_IMPORT_io
#    include "io.c"
#endif

#ifndef M2_IMPORT_str
#    include "str.c"
#endif

void FileName_0err_entry_get(int i, char **m, char **f, int *l);
/*  8*/ int FileName_initialized = 0;
/* 11*/ int FileName_WIN = 0;

/* 13*/ void
/* 13*/ FileName_init(void)
/* 13*/ {
/* 13*/ 	if( FileName_initialized ){
/* 15*/ 		return ;
/* 16*/ 	}
/* 16*/ 	FileName_initialized = TRUE;
#if defined(_WIN32)
	FileName_WIN = 1;
#else
	FileName_WIN = 0;
#endif
/* 25*/ }


/* 27*/ void
/* 27*/ FileName_SetTargetOS(int FileName_windows)
/* 27*/ {
/* 27*/ 	FileName_init();
/* 28*/ 	FileName_WIN = FileName_windows;
/* 32*/ }


/* 34*/ STRING *
/* 34*/ FileName_slash_convert(STRING *FileName_p)
/* 34*/ {
/* 34*/ 	return str_substitute(FileName_p, m2runtime_CHR(92), m2runtime_CHR(47));
/* 38*/ }


/* 40*/ int
/* 40*/ FileName_IsAbsolute(STRING *FileName_f)
/* 40*/ {
/* 40*/ 	FileName_init();
/* 41*/ 	if( FileName_WIN ){
/* 42*/ 		FileName_f = FileName_slash_convert(FileName_f);
/* 43*/ 		return (m2_match(FileName_f, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"^[a-zA-Z]:$") || m2_match(FileName_f, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\13,\0,\0,\0)"^[a-zA-Z]:/") || m2_match(FileName_f, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"^//"));
/* 46*/ 	} else {
/* 46*/ 		return ((m2runtime_strcmp(FileName_f, EMPTY_STRING) > 0) && (m2runtime_strcmp(m2runtime_substr(FileName_f, 0, 0, 0, FileName_0err_entry_get, 0), m2runtime_CHR(47)) == 0));
/* 49*/ 	}
/* 49*/ 	m2runtime_missing_return(FileName_0err_entry_get, 1);
/* 49*/ 	return 0;
/* 51*/ }


/* 77*/ STRING *
/* 77*/ FileName_Normalize(STRING *FileName_f)
/* 77*/ {
/* 78*/ 	ARRAY * FileName_b = NULL;
/* 78*/ 	ARRAY * FileName_a = NULL;
/* 79*/ 	int FileName_j = 0;
/* 79*/ 	int FileName_i = 0;
/* 80*/ 	STRING * FileName_w = NULL;
/* 81*/ 	int FileName_abs = 0;
/* 83*/ 	STRING * FileName_drive = NULL;
/* 83*/ 	FileName_init();
/* 84*/ 	if( m2runtime_strcmp(FileName_f, EMPTY_STRING) <= 0 ){
/* 85*/ 		m2runtime_HALT(FileName_0err_entry_get, 2, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\24,\0,\0,\0)"path is NIL or empty");
/* 89*/ 	}
/* 89*/ 	if( FileName_WIN ){
/* 90*/ 		FileName_f = FileName_slash_convert(FileName_f);
/* 91*/ 		if( m2_match(FileName_f, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"^[a-zA-Z]:") ){
/* 92*/ 			FileName_drive = m2runtime_substr(FileName_f, 0, 2, 1, FileName_0err_entry_get, 3);
/* 93*/ 			FileName_f = m2runtime_substr(FileName_f, 2, m2runtime_length(FileName_f), 1, FileName_0err_entry_get, 4);
/* 94*/ 		} else if( m2_match(FileName_f, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"^//") ){
/* 95*/ 			FileName_i = str_find(m2runtime_substr(FileName_f, 2, m2runtime_length(FileName_f), 1, FileName_0err_entry_get, 5), m2runtime_CHR(47));
/* 96*/ 			if( (FileName_i > 0) ){
/* 97*/ 				FileName_drive = m2runtime_substr(FileName_f, 0, (2 + FileName_i), 1, FileName_0err_entry_get, 6);
/* 98*/ 				FileName_f = m2runtime_substr(FileName_f, (2 + FileName_i), m2runtime_length(FileName_f), 1, FileName_0err_entry_get, 7);
/*100*/ 			} else {
/*100*/ 				FileName_drive = EMPTY_STRING;
/*103*/ 			}
/*103*/ 		} else {
/*103*/ 			FileName_drive = EMPTY_STRING;
/*106*/ 		}
/*106*/ 	} else {
/*106*/ 		FileName_drive = EMPTY_STRING;
/*109*/ 	}
/*109*/ 	FileName_a = str_split(FileName_f, m2runtime_CHR(47));
/*110*/ 	FileName_j = 0;
/*111*/ 	{
/*111*/ 		int m2runtime_for_limit_1;
/*111*/ 		FileName_i = 0;
/*111*/ 		m2runtime_for_limit_1 = (m2runtime_count(FileName_a) - 1);
/*112*/ 		for( ; FileName_i <= m2runtime_for_limit_1; FileName_i += 1 ){
/*112*/ 			FileName_w = (STRING *)m2runtime_dereference_rhs_ARRAY(FileName_a, FileName_i, FileName_0err_entry_get, 8);
/*113*/ 			if( m2runtime_strcmp(FileName_w, EMPTY_STRING) == 0 ){
/*114*/ 				if( (FileName_i == 0) ){
/*116*/ 					FileName_abs = TRUE;
/*118*/ 				}
/*118*/ 			} else if( m2runtime_strcmp(FileName_w, m2runtime_CHR(46)) == 0 ){
/*120*/ 			} else if( m2runtime_strcmp(FileName_w, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"..") == 0 ){
/*121*/ 				if( (FileName_j == 0) ){
/*122*/ 					if( FileName_abs ){
/*125*/ 					} else {
/*125*/ 						*(STRING **)m2runtime_dereference_lhs_ARRAY(&FileName_b, sizeof(void *), 1, 0, FileName_0err_entry_get, 9) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"..";
/*126*/ 						FileName_j = 1;
/*128*/ 					}
/*128*/ 				} else if( m2runtime_strcmp((STRING *)m2runtime_dereference_rhs_ARRAY(FileName_b, (FileName_j - 1), FileName_0err_entry_get, 10), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"..") == 0 ){
/*129*/ 					*(STRING **)m2runtime_dereference_lhs_ARRAY(&FileName_b, sizeof(void *), 1, FileName_j, FileName_0err_entry_get, 11) = (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"..";
/*130*/ 					FileName_j = (FileName_j + 1);
/*133*/ 				} else {
/*133*/ 					FileName_j = (FileName_j - 1);
/*135*/ 				}
/*136*/ 			} else {
/*136*/ 				*(STRING **)m2runtime_dereference_lhs_ARRAY(&FileName_b, sizeof(void *), 1, FileName_j, FileName_0err_entry_get, 12) = FileName_w;
/*137*/ 				FileName_j = (FileName_j + 1);
/*140*/ 			}
/*140*/ 		}
/*140*/ 	}
/*140*/ 	if( (FileName_j == 0) ){
/*141*/ 		if( FileName_abs ){
/*142*/ 			return m2runtime_concat_STRING(0, FileName_drive, m2runtime_CHR(47), (STRING *) 1);
/*144*/ 		} else {
/*144*/ 			return m2runtime_CHR(46);
/*147*/ 		}
/*147*/ 	} else {
/*147*/ 		if( FileName_abs ){
/*148*/ 			FileName_f = m2runtime_concat_STRING(0, m2runtime_CHR(47), (STRING *)m2runtime_dereference_rhs_ARRAY(FileName_b, 0, FileName_0err_entry_get, 13), (STRING *) 1);
/*150*/ 		} else {
/*150*/ 			FileName_f = (STRING *)m2runtime_dereference_rhs_ARRAY(FileName_b, 0, FileName_0err_entry_get, 14);
/*152*/ 		}
/*152*/ 		{
/*152*/ 			int m2runtime_for_limit_1;
/*152*/ 			FileName_i = 1;
/*152*/ 			m2runtime_for_limit_1 = (FileName_j - 1);
/*153*/ 			for( ; FileName_i <= m2runtime_for_limit_1; FileName_i += 1 ){
/*153*/ 				FileName_f = m2runtime_concat_STRING(0, FileName_f, m2runtime_CHR(47), (STRING *)m2runtime_dereference_rhs_ARRAY(FileName_b, FileName_i, FileName_0err_entry_get, 15), (STRING *) 1);
/*156*/ 			}
/*156*/ 		}
/*156*/ 	}
/*156*/ 	return m2runtime_concat_STRING(0, FileName_drive, FileName_f, (STRING *) 1);
/*160*/ }


/*161*/ STRING *
/*161*/ FileName_Dirname(STRING *FileName_f)
/*161*/ {
/*163*/ 	int FileName_i = 0;
/*163*/ 	FileName_init();
/*164*/ 	if( FileName_WIN ){
/*165*/ 		FileName_f = FileName_slash_convert(FileName_f);
/*168*/ 	}
/*168*/ 	{
/*168*/ 		int m2runtime_for_limit_1;
/*168*/ 		FileName_i = (m2runtime_length(FileName_f) - 1);
/*168*/ 		m2runtime_for_limit_1 = 0;
/*169*/ 		for( ; FileName_i >= m2runtime_for_limit_1; FileName_i -= 1 ){
/*169*/ 			if( m2runtime_strcmp(m2runtime_substr(FileName_f, FileName_i, 0, 0, FileName_0err_entry_get, 16), m2runtime_CHR(47)) == 0 ){
/*170*/ 				if( (FileName_i == 0) ){
/*171*/ 					return m2runtime_CHR(47);
/*173*/ 				} else {
/*173*/ 					return m2runtime_substr(FileName_f, 0, FileName_i, 1, FileName_0err_entry_get, 17);
/*176*/ 				}
/*177*/ 			}
/*177*/ 		}
/*177*/ 	}
/*177*/ 	return m2runtime_CHR(46);
/*181*/ }


/*182*/ STRING *
/*182*/ FileName_Basename(STRING *FileName_f)
/*182*/ {
/*184*/ 	int FileName_i = 0;
/*184*/ 	FileName_init();
/*185*/ 	if( FileName_WIN ){
/*186*/ 		FileName_f = FileName_slash_convert(FileName_f);
/*189*/ 	}
/*189*/ 	if( m2runtime_strcmp(FileName_f, m2runtime_CHR(47)) == 0 ){
/*190*/ 		return m2runtime_CHR(47);
/*192*/ 	}
/*192*/ 	{
/*192*/ 		int m2runtime_for_limit_1;
/*192*/ 		FileName_i = (m2runtime_length(FileName_f) - 1);
/*192*/ 		m2runtime_for_limit_1 = 0;
/*193*/ 		for( ; FileName_i >= m2runtime_for_limit_1; FileName_i -= 1 ){
/*193*/ 			if( m2runtime_strcmp(m2runtime_substr(FileName_f, FileName_i, 0, 0, FileName_0err_entry_get, 18), m2runtime_CHR(47)) == 0 ){
/*194*/ 				return m2runtime_substr(FileName_f, (FileName_i + 1), m2runtime_length(FileName_f), 1, FileName_0err_entry_get, 19);
/*197*/ 			}
/*197*/ 		}
/*197*/ 	}
/*197*/ 	return FileName_f;
/*201*/ }


/*207*/ STRING *
/*207*/ FileName_Absolute(STRING *FileName_cwd, STRING *FileName_f)
/*207*/ {
/*207*/ 	FileName_init();
/*208*/ 	if( FileName_WIN ){
/*209*/ 		FileName_cwd = FileName_slash_convert(FileName_cwd);
/*210*/ 		FileName_f = FileName_slash_convert(FileName_f);
/*213*/ 	}
/*213*/ 	if( m2runtime_strcmp(FileName_f, EMPTY_STRING) <= 0 ){
/*214*/ 		m2runtime_HALT(FileName_0err_entry_get, 20, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\12,\0,\0,\0)"empty path");
/*217*/ 	}
/*217*/ 	if( !FileName_IsAbsolute(FileName_f) ){
/*218*/ 		if( FileName_cwd == NULL ){
/*219*/ 			m2runtime_ERROR_CODE = 0;
/*219*/ 			FileName_cwd = io_GetCWD(1);
/*220*/ 			switch( m2runtime_ERROR_CODE ){

/*220*/ 			case 0:  break;
/*220*/ 			default:
/*220*/ 				m2runtime_HALT(FileName_0err_entry_get, 21, m2runtime_ERROR_MESSAGE);
/*221*/ 			}
/*221*/ 		}
/*221*/ 		FileName_cwd = FileName_slash_convert(FileName_cwd);
/*222*/ 		FileName_f = m2runtime_concat_STRING(0, FileName_cwd, m2runtime_CHR(47), FileName_f, (STRING *) 1);
/*225*/ 	}
/*225*/ 	return FileName_Normalize(FileName_f);
/*229*/ }


/*231*/ STRING *
/*231*/ FileName_Relative(STRING *FileName_a, STRING *FileName_b)
/*231*/ {
/*232*/ 	int FileName_j = 0;
/*232*/ 	int FileName_i = 0;
/*234*/ 	STRING * FileName_c = NULL;
/*234*/ 	FileName_init();
/*235*/ 	if( FileName_WIN ){
/*236*/ 		FileName_a = FileName_slash_convert(FileName_a);
/*237*/ 		FileName_b = FileName_slash_convert(FileName_b);
/*241*/ 	}
/*241*/ 	FileName_j = -1;
/*242*/ 	FileName_i = 0;
/*244*/ 	do{
/*244*/ 		if( (FileName_i == m2runtime_length(FileName_a)) ){
/*245*/ 			if( (((FileName_i == m2runtime_length(FileName_b))) || (m2runtime_strcmp(m2runtime_substr(FileName_b, FileName_i, 0, 0, FileName_0err_entry_get, 22), m2runtime_CHR(47)) == 0)) ){
/*246*/ 				FileName_j = FileName_i;
/*249*/ 			}
/*249*/ 			goto m2runtime_loop_1;
/*249*/ 		} else if( (FileName_i == m2runtime_length(FileName_b)) ){
/*250*/ 			if( m2runtime_strcmp(m2runtime_substr(FileName_a, FileName_i, 0, 0, FileName_0err_entry_get, 23), m2runtime_CHR(47)) == 0 ){
/*251*/ 				FileName_j = FileName_i;
/*254*/ 			}
/*254*/ 			goto m2runtime_loop_1;
/*254*/ 		} else if( m2runtime_strcmp(m2runtime_substr(FileName_a, FileName_i, 0, 0, FileName_0err_entry_get, 24), m2runtime_substr(FileName_b, FileName_i, 0, 0, FileName_0err_entry_get, 25)) == 0 ){
/*255*/ 			if( m2runtime_strcmp(m2runtime_substr(FileName_a, FileName_i, 0, 0, FileName_0err_entry_get, 26), m2runtime_CHR(47)) == 0 ){
/*256*/ 				FileName_j = FileName_i;
/*258*/ 			}
/*258*/ 			m2_inc(&FileName_i, 1);
/*261*/ 		} else {
/*262*/ 			goto m2runtime_loop_1;
/*263*/ 		}
/*263*/ 	}while(TRUE);
m2runtime_loop_1: ;
/*263*/ 	if( (FileName_j == -1) ){
/*264*/ 		return FileName_b;
/*266*/ 	}
/*266*/ 	if( (FileName_j == m2runtime_length(FileName_b)) ){
/*267*/ 		return FileName_Basename(FileName_b);
/*271*/ 	}
/*271*/ 	FileName_i = (FileName_j + 1);
/*272*/ 	FileName_c = EMPTY_STRING;
/*273*/ 	while( (FileName_i < m2runtime_length(FileName_a)) ){
/*274*/ 		if( m2runtime_strcmp(m2runtime_substr(FileName_a, FileName_i, 0, 0, FileName_0err_entry_get, 27), m2runtime_CHR(47)) == 0 ){
/*275*/ 			FileName_c = m2runtime_concat_STRING(0, FileName_c, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)"../", (STRING *) 1);
/*277*/ 		}
/*277*/ 		m2_inc(&FileName_i, 1);
/*280*/ 	}
/*280*/ 	return m2runtime_concat_STRING(0, FileName_c, m2runtime_substr(FileName_b, (FileName_j + 1), m2runtime_length(FileName_b), 1, FileName_0err_entry_get, 28), (STRING *) 1);
/*284*/ }


/*285*/ STRING *
/*285*/ FileName_DropExtension(STRING *FileName_f)
/*285*/ {
/*287*/ 	int FileName_i = 0;
/*287*/ 	FileName_init();
/*288*/ 	if( FileName_WIN ){
/*289*/ 		FileName_f = FileName_slash_convert(FileName_f);
/*291*/ 	}
/*291*/ 	{
/*291*/ 		int m2runtime_for_limit_1;
/*291*/ 		FileName_i = (m2runtime_length(FileName_f) - 1);
/*291*/ 		m2runtime_for_limit_1 = 0;
/*292*/ 		for( ; FileName_i >= m2runtime_for_limit_1; FileName_i -= 1 ){
/*292*/ 			if( m2runtime_strcmp(m2runtime_substr(FileName_f, FileName_i, 0, 0, FileName_0err_entry_get, 29), m2runtime_CHR(46)) == 0 ){
/*293*/ 				return m2runtime_substr(FileName_f, 0, FileName_i, 1, FileName_0err_entry_get, 30);
/*294*/ 			} else if( m2runtime_strcmp(m2runtime_substr(FileName_f, FileName_i, 0, 0, FileName_0err_entry_get, 31), m2runtime_CHR(47)) == 0 ){
/*295*/ 				return FileName_f;
/*298*/ 			}
/*298*/ 		}
/*298*/ 	}
/*298*/ 	return FileName_f;
/*302*/ }


char * FileName_0func[] = {
    "IsAbsolute",
    "Normalize",
    "Dirname",
    "Basename",
    "Absolute",
    "Relative",
    "DropExtension"
};

int FileName_0err_entry[] = {
    0 /* IsAbsolute */, 46,
    0 /* IsAbsolute */, 48,
    1 /* Normalize */, 85,
    1 /* Normalize */, 92,
    1 /* Normalize */, 93,
    1 /* Normalize */, 95,
    1 /* Normalize */, 97,
    1 /* Normalize */, 98,
    1 /* Normalize */, 113,
    1 /* Normalize */, 125,
    1 /* Normalize */, 128,
    1 /* Normalize */, 129,
    1 /* Normalize */, 136,
    1 /* Normalize */, 149,
    1 /* Normalize */, 151,
    1 /* Normalize */, 154,
    2 /* Dirname */, 169,
    2 /* Dirname */, 173,
    3 /* Basename */, 193,
    3 /* Basename */, 194,
    4 /* Absolute */, 214,
    4 /* Absolute */, 219,
    5 /* Relative */, 245,
    5 /* Relative */, 250,
    5 /* Relative */, 254,
    5 /* Relative */, 254,
    5 /* Relative */, 255,
    5 /* Relative */, 274,
    5 /* Relative */, 280,
    6 /* DropExtension */, 292,
    6 /* DropExtension */, 293,
    6 /* DropExtension */, 294
};

void FileName_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "FileName";
    *f = FileName_0func[ FileName_0err_entry[2*i] ];
    *l = FileName_0err_entry[2*i + 1];
}
