/* IMPLEMENTATION MODULE str */
#define M2_IMPORT_str

void str_0err_entry_get(int i, char **m, char **f, int *l);

/*  5*/ STRING *
/*  5*/ str_repeat(STRING *str_s, int str_n)
/*  5*/ {
/*  6*/ 	STRING * str_r = NULL;
	int i;
/*  8*/ 	if( ((str_s == NULL) || ((str_n <= 0))) ){
/*  9*/ 		return NULL;
/* 11*/ 	}
/* 11*/ 	if( (str_n == 1) ){
/* 12*/ 		return str_s;
/* 14*/ 	}
	str_r = M2_MALLOC_ATOMIC(sizeof(STRING) + str_s->len * str_n);
	str_r->type = STRING_type;
	str_r->len = str_s->len * str_n;
	for( i=0; i<str_n; i++ )
		memcpy(&str_r->s[i*str_s->len], str_s->s, str_s->len);
/* 19*/ 	return str_r;
/* 23*/ }


/* 24*/ STRING *
/* 24*/ str_toupper(STRING *str_s)
/* 24*/ {
/* 25*/ 	STRING * str_r = NULL;
	char *a, *b;
	int i;
/* 28*/ 	if( str_s == NULL ){
/* 29*/ 		return NULL;
/* 31*/ 	}
	str_r = M2_MALLOC(sizeof(STRING) + str_s->len);
	str_r->type = STRING_type;
   str_r->len = str_s->len;
	a = str_s->s; b = str_r->s;
	for( i=str_s->len; i>0; i-- )
		*b++ = toupper(*a++);
/* 37*/ 	return str_r;
/* 41*/ }


/* 42*/ STRING *
/* 42*/ str_tolower(STRING *str_s)
/* 42*/ {
/* 43*/ 	STRING * str_r = NULL;
	char *a, *b;
	int i;
/* 46*/ 	if( str_s == NULL ){
/* 47*/ 		return NULL;
/* 49*/ 	}
	str_r = M2_MALLOC(sizeof(STRING) + str_s->len);
	str_r->type = STRING_type;
   str_r->len = str_s->len;
	a = str_s->s; b = str_r->s;
	for( i=str_s->len; i>0; i-- )
		*b++ = tolower(*a++);
/* 55*/ 	return str_r;
/* 59*/ }


/* 64*/ int
/* 64*/ str_index(STRING *str_s, int str_i, STRING *str_t)
/* 64*/ {
 int a, b;
/* 66*/ 	if( ((str_s == NULL) || (str_t == NULL) || ((str_i < 0)) || ((str_i > m2runtime_length(str_s)))) ){
/* 67*/ 		return -1;
/* 69*/ 	}
	for( a = str_i; a < str_s->len; a++ ){
		for( b = 0; b < str_t->len; b++ ){
			if( str_s->s[a] == str_t->s[b] ){
				return a;
			}
		}
	}
/* 76*/ 	return -1;
/* 80*/ }


/* 82*/ ARRAY *
/* 82*/ str_split(STRING *str_s, STRING *str_t)
/* 82*/ {
/* 83*/ 	int str_j = 0;
/* 83*/ 	int str_i = 0;
/* 85*/ 	ARRAY * str_a = NULL;
/* 85*/ 	str_i = 0;
/* 87*/ 	do{
/* 87*/ 		str_j = str_index(str_s, str_i, str_t);
/* 88*/ 		if( (str_j < 0) ){
/* 89*/ 			if( (str_i <= m2runtime_length(str_s)) ){
/* 90*/ 				*(STRING **)m2runtime_dereference_lhs_ARRAY(&str_a, sizeof(void *), 1, m2runtime_count(str_a), str_0err_entry_get, 0) = m2runtime_substr(str_s, str_i, m2runtime_length(str_s), 1, str_0err_entry_get, 1);
/* 92*/ 			}
/* 92*/ 			return str_a;
/* 94*/ 		}
/* 94*/ 		*(STRING **)m2runtime_dereference_lhs_ARRAY(&str_a, sizeof(void *), 1, m2runtime_count(str_a), str_0err_entry_get, 2) = m2runtime_substr(str_s, str_i, str_j, 1, str_0err_entry_get, 3);
/* 95*/ 		str_i = (str_j + 1);
/* 97*/ 	}while(TRUE);
/* 97*/ 	return str_a;
/*101*/ }


/*103*/ STRING *
/*103*/ str_join(ARRAY *str_a, STRING *str_sep)
/*103*/ {
/*104*/ 	STRING * str_s = NULL;
/*106*/ 	int str_i = 0;
/*106*/ 	str_s = EMPTY_STRING;
/*107*/ 	{
/*107*/ 		int m2runtime_for_limit_1;
/*107*/ 		str_i = 0;
/*107*/ 		m2runtime_for_limit_1 = (m2runtime_count(str_a) - 1);
/*108*/ 		for( ; str_i <= m2runtime_for_limit_1; str_i += 1 ){
/*108*/ 			if( (str_i == 0) ){
/*109*/ 				str_s = (STRING *)m2runtime_dereference_rhs_ARRAY(str_a, 0, str_0err_entry_get, 4);
/*111*/ 			} else {
/*111*/ 				str_s = m2runtime_concat_STRING(0, str_s, str_sep, (STRING *)m2runtime_dereference_rhs_ARRAY(str_a, str_i, str_0err_entry_get, 5), (STRING *) 1);
/*114*/ 			}
/*114*/ 		}
/*114*/ 	}
/*114*/ 	return str_s;
/*118*/ }


/*119*/ int
/*119*/ str_find(STRING *str_s, STRING *str_t)
/*119*/ {
/*121*/ 	int str_x = 0;
/*121*/ 	if( (((m2runtime_length(str_s) == 0)) || ((m2runtime_length(str_t) == 0)) || ((m2runtime_length(str_t) > m2runtime_length(str_s)))) ){
/*122*/ 		return -1;
/*124*/ 	}
/*124*/ 	{
/*124*/ 		int m2runtime_for_limit_1;
/*124*/ 		str_x = 0;
/*124*/ 		m2runtime_for_limit_1 = (m2runtime_length(str_s) - m2runtime_length(str_t));
/*125*/ 		for( ; str_x <= m2runtime_for_limit_1; str_x += 1 ){
		if( memcmp(str_s->s + str_x, str_t->s, str_t->len) == 0 )
			return str_x;
/*128*/ 		}
/*128*/ 	}
/*128*/ 	return -1;
/*132*/ }


/*134*/ STRING *
/*134*/ str_substitute(STRING *str_s, STRING *str_target, STRING *str_sub)
/*134*/ {
/*135*/ 	STRING * str_r = NULL;
/*137*/ 	int str_x = 0;
/*137*/ 	if( str_s == NULL ){
/*138*/ 		return NULL;
/*139*/ 	} else if( m2runtime_strcmp(str_s, EMPTY_STRING) == 0 ){
/*140*/ 		return EMPTY_STRING;
/*141*/ 	} else if( (m2runtime_length(str_target) == 0) ){
/*142*/ 		return str_s;
/*145*/ 	}
/*145*/ 	do{
/*145*/ 		str_x = str_find(str_s, str_target);
/*146*/ 		if( (str_x < 0) ){
/*147*/ 			return m2runtime_concat_STRING(0, str_r, str_s, (STRING *) 1);
/*149*/ 		}
/*149*/ 		str_r = m2runtime_concat_STRING(0, str_r, m2runtime_substr(str_s, 0, str_x, 1, str_0err_entry_get, 6), str_sub, (STRING *) 1);
/*150*/ 		str_s = m2runtime_substr(str_s, (str_x + m2runtime_length(str_target)), m2runtime_length(str_s), 1, str_0err_entry_get, 7);
/*153*/ 	}while(TRUE);
/*153*/ 	m2runtime_missing_return(str_0err_entry_get, 8);
/*153*/ 	return NULL;
/*156*/ }


/*158*/ int
/*158*/ str_starts_with(STRING *str_s, STRING *str_head)
/*158*/ {
/*158*/ 	if( str_s == NULL ){
/*159*/ 		return str_head == NULL;
/*160*/ 	} else if( str_head == NULL ){
/*161*/ 		return TRUE;
/*162*/ 	} else if( (m2runtime_length(str_head) > m2runtime_length(str_s)) ){
/*163*/ 		return FALSE;
/*167*/ 	} else {
		return memcmp(str_s->s, str_head->s, str_head->len) == 0;
/*170*/ 	}
/*170*/ 	m2runtime_missing_return(str_0err_entry_get, 9);
/*170*/ 	return 0;
/*172*/ }


/*174*/ int
/*174*/ str_ends_with(STRING *str_s, STRING *str_tail)
/*174*/ {
/*174*/ 	if( str_s == NULL ){
/*175*/ 		return str_tail == NULL;
/*176*/ 	} else if( str_tail == NULL ){
/*177*/ 		return TRUE;
/*178*/ 	} else if( (m2runtime_length(str_tail) > m2runtime_length(str_s)) ){
/*179*/ 		return FALSE;
/*183*/ 	} else {
		return memcmp(str_s->s + str_s->len - str_tail->len,
			str_tail->s, str_tail->len) == 0;
/*187*/ 	}
/*187*/ 	m2runtime_missing_return(str_0err_entry_get, 10);
/*187*/ 	return 0;
/*190*/ }


char * str_0func[] = {
    "split",
    "join",
    "substitute",
    "starts_with",
    "ends_with"
};

int str_0err_entry[] = {
    0 /* split */, 90,
    0 /* split */, 90,
    0 /* split */, 94,
    0 /* split */, 94,
    1 /* join */, 110,
    1 /* join */, 112,
    2 /* substitute */, 149,
    2 /* substitute */, 150,
    2 /* substitute */, 152,
    3 /* starts_with */, 169,
    4 /* ends_with */, 186
};

void str_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "str";
    *f = str_0func[ str_0err_entry[2*i] ];
    *l = str_0err_entry[2*i + 1];
}
