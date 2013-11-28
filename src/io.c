/* IMPLEMENTATION MODULE io */
#define M2_IMPORT_io

#ifndef M2_IMPORT_buffer
#    include "buffer.c"
#endif

void io_0err_entry_get(int i, char **m, char **f, int *l);
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/select.h>

/* 53*/ void
/* 53*/ io_Open(int try_section, RECORD **io_f, STRING *io_fn, STRING *io_fl)
/* 53*/ {
/* 54*/ 	int io_fd = 0;
/* 55*/ 	void * io_b = NULL;
/* 56*/ 	int io_mode = 0;
/* 57*/ 	int io_flags = 0;
/* 58*/ 	STRING * io_c = NULL;
	int g, i, io_unbuffered;
	char *n, *m;
/* 61*/ 	m2runtime_mark(&io_fl);
/* 62*/ 	*io_f = NULL;
/* 63*/ 	if( m2runtime_InvalidZString(io_fn) ){
/* 64*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 0, 22, m2runtime_concat_STRING(0, m2runtime_StringToLiteral(io_fn), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)": pathfile NIL or containing a NUL character", (STRING *) 1));
/* 66*/ 		return ;
/* 67*/ 	}
	io_mode = 0;
	io_flags = 0;
	io_unbuffered = 0;
	if( io_fl != NULL ){
		for( i = 0; i < io_fl->len; i++ ){
			switch( io_fl->s[i] ){

			case 'r': io_mode |= 1; break;
			case 'w': io_mode |= 2; break;

			case 'U': io_unbuffered = 1; break;

			case 'a': io_flags |= O_APPEND; break;
			case 'c': io_flags |= O_CREAT; break;
			case 'e': io_flags |= O_EXCL; break;
			case 'n': io_flags |= O_NONBLOCK; break;
			case 's': io_flags |= O_SYNC; break;
			case 't': io_flags |= O_TRUNC; break;
			case 'y': io_flags |= O_NOCTTY; break;
			case 'f':
#ifdef O_NOFOLLOW
				io_flags |= O_NOFOLLOW;
#endif
				break;
			default:
				io_c = new_STRING(io_fl->s + i, 1);
/* 93*/ 	m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 1, 22, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"unknown flag ", m2runtime_StringToLiteral(io_c), (STRING *) 1));
/* 95*/ 	return ;
			}
		}
	}
	if( io_mode == 0 ){
/* 99*/ 	m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 2, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\30,\0,\0,\0)"required mode w, r or rw");
/*101*/ 	return ;
	} else if( io_mode == 1 )
		g = O_RDONLY;
	else if( io_mode == 2 )
		g = O_WRONLY;
	else
		g = O_RDWR;
	g |= io_flags;
	MK_ZSTRING(n, io_fn);
	io_fd = open(n, g, 0777);
/*110*/ 	if( (io_fd == -1) ){
/*111*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 3, m2runtime_errno(), m2runtime_concat_STRING(0, m2runtime_StringToLiteral(io_fn), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", m2runtime_strerror(), (STRING *) 1));
/*113*/ 		return ;
/*114*/ 	}
/*114*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 4) = io_fd;
/*115*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 5) = TRUE;
	if( g & O_NONBLOCK ){
		if( ! io_unbuffered ){
/*118*/ 	m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 6, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\44,\0,\0,\0)"non-blocking mode require unbuffered");
/*120*/ 	return ;
		}
/*121*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 4 * sizeof(int), io_0err_entry_get, 7) = TRUE;
	}
/*123*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 8) = NULL;
/*124*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 5 * sizeof(int), io_0err_entry_get, 9) = io_mode;
/*125*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 6 * sizeof(int), io_0err_entry_get, 10) = io_flags;
	if( io_unbuffered )  return;
	if( io_mode == 1 ){
		m = "r";
	} else if( io_mode == 2 ){
		if( io_flags & O_APPEND )
			m = "a";
		else
			m = "w";
	} else {
		if( io_flags & O_APPEND )
			m = "a+";
		else
			m = "r+";
	}

	io_b = (void *)fdopen(io_fd, m);
/*145*/ 	if( io_b == NULL ){
/*146*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 11, m2runtime_errno(), m2runtime_concat_STRING(0, io_fn, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", m2runtime_strerror(), (STRING *) 1));
/*147*/ 		*io_f = NULL;
/*149*/ 		return ;
/*151*/ 	}
/*151*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 12) = FALSE;
/*152*/ 	*(RECORD **)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 13) = io_b;
/*156*/ }


/*159*/ void
/*159*/ io_Write(int try_section, RECORD *io_f, STRING *io_s)
/*159*/ {
/*160*/ 	int io_w = 0;
/*160*/ 	int io_n = 0;
/*160*/ 	int io_fd = 0;
/*161*/ 	void * io_b = NULL;
/*163*/ 	STRING * io_t = NULL;
/*163*/ 	if( io_f == NULL ){
/*164*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 14, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"NIL file");
/*166*/ 		return ;
/*167*/ 	}
/*167*/ 	if( (( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 5 * sizeof(int), io_0err_entry_get, 15) & 2) == 0) ){
/*168*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 16, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\26,\0,\0,\0)"file open in read mode");
/*170*/ 		return ;
/*171*/ 	}
/*171*/ 	if( (((m2runtime_length(io_s) == 0)) && ((STRING *)m2runtime_dereference_rhs_RECORD(io_f, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 17) == NULL)) ){
/*173*/ 		return ;
/*174*/ 	}
/*174*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 18) == -1) ){
/*175*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 19, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"file just closed");
/*177*/ 		return ;
/*178*/ 	}
/*178*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 20) ){
/*180*/ 		io_fd =  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 21);
/*182*/ 		if( (STRING *)m2runtime_dereference_rhs_RECORD(io_f, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 22) != NULL ){
/*184*/ 			io_t = (STRING *)m2runtime_dereference_rhs_RECORD(io_f, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 23);
/*185*/ 			io_w =  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 7 * sizeof(int), io_0err_entry_get, 24);
/*187*/ 			do{
				io_n = TEMP_FAILURE_RETRY( write(io_fd, &io_t->s[io_w],
					io_t->len - io_w) );
/*189*/ 				if( (io_n < 0) ){
/*190*/ 					m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 25, m2runtime_errno(), m2runtime_strerror());
/*192*/ 					return ;
/*193*/ 				}
/*193*/ 				io_w = (io_w + io_n);
/*194*/ 				if( (io_w == m2runtime_length(io_t)) ){
/*195*/ 					*(STRING **)m2runtime_dereference_lhs_RECORD(&io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 26) = NULL;
/*196*/ 					*(int *)m2runtime_dereference_lhs_RECORD(&io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 7 * sizeof(int), io_0err_entry_get, 27) = 0;
/*199*/ 					goto m2runtime_loop_1;
/*199*/ 				} else {
/*199*/ 					*(int *)m2runtime_dereference_lhs_RECORD(&io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 7 * sizeof(int), io_0err_entry_get, 28) = io_w;
/*201*/ 					return ;
/*203*/ 				}
/*204*/ 			}while(TRUE);
m2runtime_loop_1: ;
/*206*/ 		}
/*206*/ 		io_w = 0;
/*208*/ 		do{
/*208*/ 			if( (io_w == m2runtime_length(io_s)) ){
/*210*/ 				return ;
/*211*/ 			}
			io_n = TEMP_FAILURE_RETRY( write(io_fd, &io_s->s[io_w],
				io_s->len - io_w) );
/*213*/ 			if( (io_n < 0) ){
/*214*/ 				if( (((m2runtime_errno() == 11)) && ((io_w > 0))) ){
/*215*/ 					*(STRING **)m2runtime_dereference_lhs_RECORD(&io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 29) = io_s;
/*216*/ 					*(int *)m2runtime_dereference_lhs_RECORD(&io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 7 * sizeof(int), io_0err_entry_get, 30) = io_w;
/*218*/ 				} else {
/*218*/ 					m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 31, m2runtime_errno(), m2runtime_strerror());
/*221*/ 				}
/*221*/ 				return ;
/*222*/ 			}
/*222*/ 			io_w = (io_w + io_n);
/*226*/ 		}while(TRUE);
/*227*/ 	} else {
/*227*/ 		io_b = (void *)m2runtime_dereference_rhs_RECORD(io_f, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 32);
		io_n = TEMP_FAILURE_RETRY( fwrite(io_s->s, io_s->len, 1,
			(FILE * )io_b) );
/*230*/ 		if( (io_n == 0) ){
/*231*/ 			m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 33, m2runtime_errno(), m2runtime_strerror());
/*233*/ 			return ;
/*236*/ 		}
/*237*/ 	}
/*239*/ }


/*241*/ int
/*241*/ io_Written(RECORD *io_f)
/*241*/ {
/*241*/ 	if( ((io_f == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 34) == -1))) ){
/*242*/ 		return TRUE;
/*244*/ 	}
/*244*/ 	return (STRING *)m2runtime_dereference_rhs_RECORD(io_f, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 35) == NULL;
/*248*/ }


/*251*/ STRING *
/*251*/ io_Read(int try_section, RECORD *io_f, int io_max)
/*251*/ {
/*252*/ 	int io_n = 0;
/*252*/ 	int io_fd = 0;
/*253*/ 	void * io_b = NULL;
	char *buf;
/*255*/ 	if( io_f == NULL ){
/*256*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 36, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"NIL file");
/*257*/ 		return NULL;
/*259*/ 	}
/*259*/ 	if( (( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 5 * sizeof(int), io_0err_entry_get, 37) & 1) == 0) ){
/*260*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 38, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"file open in write mode");
/*261*/ 		return NULL;
/*263*/ 	}
/*263*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 39) == -1) ){
/*264*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 40, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"file just closed");
/*265*/ 		return NULL;
/*267*/ 	}
/*267*/ 	if( (io_max < 0) ){
/*268*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 41, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\47,\0,\0,\0)"argument `max' must be positive or zero");
/*270*/ 	}
/*270*/ 	if( (io_max == 0) ){
/*271*/ 		return NULL;
/*274*/ 	}
	buf = alloca(io_max);
/*276*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 42) ){
/*278*/ 		io_fd =  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 43);
		io_n = TEMP_FAILURE_RETRY( read(io_fd, buf, io_max) );
/*280*/ 		if( (io_n < 0) ){
/*281*/ 			m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 44, m2runtime_errno(), m2runtime_strerror());
/*282*/ 			return NULL;
/*284*/ 		}
/*284*/ 		if( (io_n == 0) ){
/*285*/ 			return NULL;
/*289*/ 		}
/*290*/ 	} else {
/*290*/ 		io_b = (void *)m2runtime_dereference_rhs_RECORD(io_f, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 45);
		io_n = TEMP_FAILURE_RETRY( fread(buf, 1, io_max, (FILE *)io_b) );
/*292*/ 		if( (io_n == 0) ){
			if( feof((FILE *)io_b) ){
/*294*/ 			return NULL;
			} else if( ferror((FILE *)io_b) ){
/*296*/ 			m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 46, m2runtime_errno(), m2runtime_strerror());
/*297*/ 			return NULL;
			} else {
/*299*/ 			m2runtime_HALT(io_0err_entry_get, 47, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\64,\0,\0,\0)"unexpected condition: no more data, no EOF, no error");
/*300*/ 			return NULL;
			}
/*302*/ 		} else if( (io_n < io_max) ){
			if( ferror((FILE *)io_b) ){
/*304*/ 			m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 48, m2runtime_errno(), m2runtime_strerror());
/*305*/ 			return NULL;
			}
/*310*/ 		}
/*311*/ 	}
	return new_STRING(buf, io_n);
/*313*/ 	m2runtime_missing_return(io_0err_entry_get, 49);
/*313*/ 	return NULL;
/*315*/ }

/*317*/ void * io_line = NULL;

/*320*/ STRING *
/*320*/ io_ReadLine(int try_section, RECORD *io_f)
/*320*/ {
/*322*/ 	STRING * io_c = NULL;
/*322*/ 	if( io_f == NULL ){
/*323*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 50, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"NIL file");
/*324*/ 		return NULL;
/*326*/ 	}
/*326*/ 	if( (( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 5 * sizeof(int), io_0err_entry_get, 51) & 1) == 0) ){
/*327*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 52, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\27,\0,\0,\0)"file open in write mode");
/*328*/ 		return NULL;
/*330*/ 	}
/*330*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 53) == -1) ){
/*331*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 54, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"file just closed");
/*332*/ 		return NULL;
/*334*/ 	}
/*334*/ 	buffer_Empty((void *)&io_line);
/*337*/ 	do{
/*337*/ 		m2runtime_ERROR_CODE = 0;
/*337*/ 		io_c = io_Read(1, io_f, 1);
/*339*/ 		switch( m2runtime_ERROR_CODE ){

/*339*/ 		case 0:  break;
/*339*/ 		default:
/*339*/ 			m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 55, m2runtime_ERROR_CODE, m2runtime_ERROR_MESSAGE);
/*340*/ 			return buffer_ToString(io_line);
/*342*/ 		}
/*342*/ 		if( io_c == NULL ){
/*343*/ 			if( (buffer_Length(io_line) == 0) ){
/*344*/ 				return NULL;
/*346*/ 			} else {
/*346*/ 				return buffer_ToString(io_line);
/*348*/ 			}
/*348*/ 		} else if( m2runtime_strcmp(io_c, m2runtime_CHR(10)) == 0 ){
/*349*/ 			if( (buffer_Length(io_line) == 0) ){
/*350*/ 				return EMPTY_STRING;
/*352*/ 			} else {
/*352*/ 				return buffer_ToString(io_line);
/*355*/ 			}
/*355*/ 		}
/*355*/ 		buffer_AddString((void *)&io_line, io_c);
/*358*/ 	}while(TRUE);
/*358*/ 	m2runtime_missing_return(io_0err_entry_get, 56);
/*358*/ 	return NULL;
/*360*/ }


/*363*/ void
/*363*/ io_Close(int try_section, RECORD **io_f)
/*363*/ {
/*364*/ 	int io_fd = 0;
/*365*/ 	void * io_b = NULL;
/*367*/ 	int io_err = 0;
/*367*/ 	if( *io_f == NULL ){
/*368*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 57, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\10,\0,\0,\0)"NIL file");
/*370*/ 		return ;
/*371*/ 	}
/*371*/ 	if( ( *(int *)m2runtime_dereference_rhs_RECORD(*io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 58) == -1) ){
/*372*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 59, 22, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\20,\0,\0,\0)"file just closed");
/*374*/ 		return ;
/*375*/ 	}
/*375*/ 	if(  *(int *)m2runtime_dereference_rhs_RECORD(*io_f, 2 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 60) ){
/*377*/ 		io_fd =  *(int *)m2runtime_dereference_rhs_RECORD(*io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 61);
		io_err = TEMP_FAILURE_RETRY( close(io_fd) );
/*379*/ 		if( (io_err == -1) ){
/*380*/ 			m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 62, m2runtime_errno(), m2runtime_strerror());
/*384*/ 		}
/*385*/ 	} else {
/*385*/ 		io_b = (void *)m2runtime_dereference_rhs_RECORD(*io_f, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 63);
		if( fclose((FILE *) io_b) ){
/*387*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 64, m2runtime_errno(), m2runtime_strerror());
		}
/*391*/ 	}
/*391*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_f, 2 * sizeof(void*) + 8 * sizeof(int), 2, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 65) = -1;
/*392*/ 	*io_f = NULL;
/*396*/ }


/*398*/ int
/*398*/ io_parse_mode(STRING *io_m)
/*398*/ {
/*399*/ 	int io_b = 0;
/*399*/ 	int io_mode = 0;
/*400*/ 	STRING * io_who = NULL;
/*400*/ 	STRING * io_c = NULL;
/*402*/ 	int io_i = 0;

/*404*/ 	void
/*404*/ 	io_next(void)
/*404*/ 	{
/*404*/ 		if( (io_i >= m2runtime_length(io_m)) ){
/*405*/ 			io_c = NULL;
/*407*/ 		} else {
/*407*/ 			io_c = m2runtime_substr(io_m, io_i, 0, 0, io_0err_entry_get, 66);
/*409*/ 		}
/*409*/ 		io_i = (io_i + 1);
/*413*/ 	}

/*413*/ 	if( (m2runtime_length(io_m) == 0) ){
/*414*/ 		return 0;
/*416*/ 	}
/*416*/ 	io_mode = 0;
/*417*/ 	io_next();
/*419*/ 	do{
/*419*/ 		if( ((m2runtime_strcmp(io_c, m2runtime_CHR(117)) != 0) && (m2runtime_strcmp(io_c, m2runtime_CHR(103)) != 0) && (m2runtime_strcmp(io_c, m2runtime_CHR(111)) != 0)) ){
/*420*/ 			return -1;
/*422*/ 		}
/*422*/ 		io_who = io_c;
/*423*/ 		io_next();
/*424*/ 		if( m2runtime_strcmp(io_c, m2runtime_CHR(61)) != 0 ){
/*425*/ 			return -1;
/*427*/ 		}
/*427*/ 		io_next();
/*428*/ 		while( ((m2runtime_strcmp(io_c, m2runtime_CHR(114)) == 0) || (m2runtime_strcmp(io_c, m2runtime_CHR(119)) == 0) || (m2runtime_strcmp(io_c, m2runtime_CHR(120)) == 0)) ){
/*429*/ 			if( m2runtime_strcmp(io_c, m2runtime_CHR(114)) == 0 ){
/*429*/ 				io_b = 4;
/*430*/ 			} else if( m2runtime_strcmp(io_c, m2runtime_CHR(119)) == 0 ){
/*430*/ 				io_b = 2;
/*431*/ 			} else {
/*431*/ 				io_b = 1;
/*433*/ 			}
/*433*/ 			if( m2runtime_strcmp(io_who, m2runtime_CHR(117)) == 0 ){
/*433*/ 				io_b = ((unsigned int) io_b << 6);
/*434*/ 			} else if( m2runtime_strcmp(io_who, m2runtime_CHR(103)) == 0 ){
/*434*/ 				io_b = ((unsigned int) io_b << 3);
/*436*/ 			}
/*436*/ 			io_mode = (io_mode | io_b);
/*437*/ 			io_next();
/*439*/ 		}
/*439*/ 		if( io_c == NULL ){
/*440*/ 			return io_mode;
/*441*/ 		} else if( m2runtime_strcmp(io_c, m2runtime_CHR(44)) == 0 ){
/*442*/ 			io_next();
/*444*/ 		} else {
/*444*/ 			return -1;
/*447*/ 		}
/*448*/ 	}while(TRUE);
/*448*/ 	m2runtime_missing_return(io_0err_entry_get, 67);
/*448*/ 	return 0;
/*450*/ }


/*452*/ STRING *
/*452*/ io_GetMask(void)
/*452*/ {
/*454*/ 	int io_u = 0;

/*456*/ 	STRING *
/*456*/ 	io_if(int io_b, STRING *io_s)
/*456*/ 	{
/*456*/ 		if( (((io_u & io_b)) == 0) ){
/*457*/ 			return NULL;
/*459*/ 		} else {
/*459*/ 			return io_s;
/*462*/ 		}
/*462*/ 		m2runtime_missing_return(io_0err_entry_get, 68);
/*462*/ 		return NULL;
/*464*/ 	}

	io_u = umask(0);   umask(io_u);
/*465*/ 	io_u = ~io_u;
/*467*/ 	return m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"u=", io_if(((unsigned int) 4 << 6), m2runtime_CHR(114)), io_if(((unsigned int) 2 << 6), m2runtime_CHR(119)), io_if(((unsigned int) 1 << 6), m2runtime_CHR(120)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)",g=", io_if(((unsigned int) 4 << 3), m2runtime_CHR(114)), io_if(((unsigned int) 2 << 3), m2runtime_CHR(119)), io_if(((unsigned int) 1 << 3), m2runtime_CHR(120)), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\3,\0,\0,\0)",o=", io_if(4, m2runtime_CHR(114)), io_if(2, m2runtime_CHR(119)), io_if(1, m2runtime_CHR(120)), (STRING *) 1);
/*473*/ }


/*474*/ void
/*474*/ io_SetMask(STRING *io_mode)
/*474*/ {
/*476*/ 	int io_x = 0;
/*476*/ 	io_x = io_parse_mode(io_mode);
/*477*/ 	if( (io_x == -1) ){
/*478*/ 		m2runtime_HALT(io_0err_entry_get, 69, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"invalid mode ", m2runtime_StringToLiteral(io_mode), (STRING *) 1));
/*480*/ 	}
	umask(~io_x);
/*485*/ }


/*501*/ RECORD *
/*501*/ io_PoolSetNew(void)
/*501*/ {
/*503*/ 	RECORD * io_ps = NULL;
/*503*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 70) = -1;
/*504*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 71) = -1;
/*505*/ 	return io_ps;
/*509*/ }


/*511*/ void
/*511*/ io_SetTimeout(RECORD **io_ps, int io_sec, int io_usec)
/*511*/ {
/*511*/ 	if( (((io_sec < 0)) || ((io_usec < 0)) || ((io_usec > 999999))) ){
/*514*/ 		return ;
/*515*/ 	}
/*515*/ 	if( *io_ps == NULL ){
/*516*/ 		*io_ps = io_PoolSetNew();
/*518*/ 	}
/*518*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 4 * sizeof(int), io_0err_entry_get, 72) = io_sec;
/*519*/ 	*(int *)m2runtime_dereference_lhs_RECORD(io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 5 * sizeof(int), io_0err_entry_get, 73) = io_usec;
/*523*/ }


/*525*/ void
/*525*/ io_Wait(RECORD *io_ps)
/*525*/ {
/*526*/ 	void * io_write_ready_fs = NULL;
/*526*/ 	void * io_read_ready_fs = NULL;
/*526*/ 	void * io_write_fs = NULL;
/*526*/ 	void * io_read_fs = NULL;
/*527*/ 	int io_n = 0;
/*527*/ 	int io_usec = 0;
/*527*/ 	int io_sec = 0;
/*527*/ 	int io_max = 0;
/*527*/ 	int io_write_max = 0;
/*527*/ 	int io_read_max = 0;
	struct timeval tv;
	struct timeval *tvp;
/*530*/ 	m2runtime_mark(&io_n);
/*531*/ 	if( io_ps == NULL ){
/*533*/ 		return ;
/*534*/ 	}
/*534*/ 	io_read_max =  *(int *)m2runtime_dereference_rhs_RECORD(io_ps, 4 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 74);
/*535*/ 	io_write_max =  *(int *)m2runtime_dereference_rhs_RECORD(io_ps, 4 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 75);
/*536*/ 	io_sec =  *(int *)m2runtime_dereference_rhs_RECORD(io_ps, 4 * sizeof(void*) + 4 * sizeof(int), io_0err_entry_get, 76);
/*537*/ 	io_usec =  *(int *)m2runtime_dereference_rhs_RECORD(io_ps, 4 * sizeof(void*) + 5 * sizeof(int), io_0err_entry_get, 77);
/*538*/ 	if( (((io_read_max == -1)) && ((io_write_max == -1)) && ((io_sec == 0)) && ((io_usec == 0))) ){
/*540*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 6 * sizeof(int), io_0err_entry_get, 78) = FALSE;
/*542*/ 		return ;
/*544*/ 	}
/*544*/ 	io_max = io_read_max;
/*545*/ 	if( (io_write_max > io_max) ){
/*546*/ 		io_max = io_write_max;
/*549*/ 	}
/*549*/ 	if( (io_read_max >= 0) ){
/*550*/ 		io_read_fs = (void *)m2runtime_dereference_rhs_RECORD(io_ps, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 79);
/*551*/ 		io_read_ready_fs = (void *)m2runtime_dereference_rhs_RECORD(io_ps, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 80);
/*552*/ 		if( io_read_ready_fs == NULL ){
			io_read_ready_fs = M2_MALLOC_ATOMIC( sizeof( fd_set ) );
/*554*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 81) = io_read_ready_fs;
/*556*/ 		}
		memcpy(io_read_ready_fs, io_read_fs, sizeof( fd_set ) );
		FD_ZERO((fd_set * )io_read_fs);
/*558*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 82) = -1;
/*561*/ 	}
/*561*/ 	if( (io_write_max >= 0) ){
/*562*/ 		io_write_fs = (void *)m2runtime_dereference_rhs_RECORD(io_ps, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 83);
/*563*/ 		io_write_ready_fs = (void *)m2runtime_dereference_rhs_RECORD(io_ps, 3 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 84);
/*564*/ 		if( io_write_ready_fs == NULL ){
			io_write_ready_fs = M2_MALLOC_ATOMIC( sizeof( fd_set ) );
/*566*/ 			*(RECORD **)m2runtime_dereference_lhs_RECORD(&io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 3 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 85) = io_write_ready_fs;
/*568*/ 		}
		memcpy(io_write_ready_fs, io_write_fs, sizeof( fd_set ) );
		FD_ZERO((fd_set * )io_write_fs);
/*570*/ 		*(int *)m2runtime_dereference_lhs_RECORD(&io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 86) = -1;
/*573*/ 	}
/*573*/ 	if( (((io_sec == 0)) && ((io_usec == 0))) ){
		tvp = NULL;
/*576*/ 	} else {
		tv.tv_sec = io_sec;
		tv.tv_usec = io_usec;
		tvp = &tv;
/*581*/ 	}
	io_n = TEMP_FAILURE_RETRY( select(io_max + 1,
		io_read_ready_fs, io_write_ready_fs,
		NULL, tvp) );
/*585*/ 	if( (io_n == -1) ){
/*586*/ 		m2runtime_HALT(io_0err_entry_get, 87, m2runtime_strerror());
/*589*/ 	}
/*589*/ 	*(int *)m2runtime_dereference_lhs_RECORD(&io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 6 * sizeof(int), io_0err_entry_get, 88) = (io_n == 0);
/*593*/ }


/*595*/ int
/*595*/ io_Timeout(RECORD *io_ps)
/*595*/ {
/*595*/ 	return ((io_ps == NULL) ||  *(int *)m2runtime_dereference_rhs_RECORD(io_ps, 4 * sizeof(void*) + 6 * sizeof(int), io_0err_entry_get, 89));
/*599*/ }


/*601*/ int
/*601*/ io_Readable(RECORD **io_ps, RECORD *io_f)
/*601*/ {
/*602*/ 	int io_fd = 0;
/*604*/ 	void * io_fs = NULL;
/*604*/ 	if( ((io_f == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 90) == -1))) ){
/*605*/ 		return FALSE;
/*607*/ 	}
/*607*/ 	if( (( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 5 * sizeof(int), io_0err_entry_get, 91) & 1) == 0) ){
/*609*/ 		return FALSE;
/*612*/ 	}
/*612*/ 	if( *io_ps == NULL ){
/*613*/ 		*io_ps = io_PoolSetNew();
/*616*/ 	}
/*616*/ 	io_fd =  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 92);
/*617*/ 	if( (void *)m2runtime_dereference_rhs_RECORD(*io_ps, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 93) == NULL ){
		io_fs = M2_MALLOC_ATOMIC( sizeof(fd_set) );
		FD_ZERO((fd_set * ) io_fs);
/*620*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 94) = io_fs;
/*622*/ 	} else {
/*622*/ 		io_fs = (void *)m2runtime_dereference_rhs_RECORD(*io_ps, 0 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 95);
/*624*/ 	}
	FD_SET(io_fd, (fd_set * ) io_fs);
/*625*/ 	if( (io_fd >  *(int *)m2runtime_dereference_rhs_RECORD(*io_ps, 4 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 96)) ){
/*626*/ 		*(int *)m2runtime_dereference_lhs_RECORD(io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 97) = io_fd;
/*629*/ 	}
/*629*/ 	io_fs = (void *)m2runtime_dereference_rhs_RECORD(*io_ps, 1 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 98);
/*630*/ 	if( io_fs == NULL ){
/*631*/ 		return FALSE;
/*633*/ 	}
/*633*/ 	io_fd =  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 99);
	if( FD_ISSET(io_fd, (fd_set * ) io_fs) ){
		FD_CLR(io_fd, (fd_set * ) io_fs);
		return TRUE;
	} else {
		return FALSE;
	}
/*641*/ 	m2runtime_missing_return(io_0err_entry_get, 100);
/*641*/ 	return 0;
/*643*/ }


/*645*/ int
/*645*/ io_Writable(RECORD **io_ps, RECORD *io_f)
/*645*/ {
/*646*/ 	int io_fd = 0;
/*648*/ 	void * io_fs = NULL;
/*648*/ 	if( ((io_f == NULL) || (( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 101) == -1))) ){
/*649*/ 		return FALSE;
/*651*/ 	}
/*651*/ 	if( (( *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 5 * sizeof(int), io_0err_entry_get, 102) & 2) == 0) ){
/*653*/ 		return FALSE;
/*656*/ 	}
/*656*/ 	if( *io_ps == NULL ){
/*657*/ 		*io_ps = io_PoolSetNew();
/*660*/ 	}
/*660*/ 	io_fd =  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 103);
/*661*/ 	if( (void *)m2runtime_dereference_rhs_RECORD(*io_ps, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 104) == NULL ){
		io_fs = M2_MALLOC_ATOMIC( sizeof(fd_set) );
		FD_ZERO((fd_set * ) io_fs);
/*664*/ 		*(RECORD **)m2runtime_dereference_lhs_RECORD(io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 105) = io_fs;
/*666*/ 	} else {
/*666*/ 		io_fs = (void *)m2runtime_dereference_rhs_RECORD(*io_ps, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 106);
/*668*/ 	}
	FD_SET(io_fd, (fd_set * ) io_fs);
/*669*/ 	if( (io_fd >  *(int *)m2runtime_dereference_rhs_RECORD(*io_ps, 4 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 107)) ){
/*670*/ 		*(int *)m2runtime_dereference_lhs_RECORD(io_ps, 4 * sizeof(void*) + 7 * sizeof(int), 4, 4 * sizeof(void*) + 3 * sizeof(int), io_0err_entry_get, 108) = io_fd;
/*673*/ 	}
/*673*/ 	io_fs = (void *)m2runtime_dereference_rhs_RECORD(*io_ps, 3 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 109);
/*674*/ 	if( io_fs == NULL ){
/*675*/ 		return FALSE;
/*677*/ 	}
/*677*/ 	io_fd =  *(int *)m2runtime_dereference_rhs_RECORD(io_f, 2 * sizeof(void*) + 2 * sizeof(int), io_0err_entry_get, 110);
	if( FD_ISSET(io_fd, (fd_set * ) io_fs) ){
		FD_CLR(io_fd, (fd_set * ) io_fs);
		return TRUE;
	} else {
		return FALSE;
	}
/*685*/ 	m2runtime_missing_return(io_0err_entry_get, 111);
/*685*/ 	return 0;
/*687*/ }


/*690*/ STRING *
/*690*/ io_GetCWD(int try_section)
/*690*/ {
/*691*/ 	STRING * io_p = NULL;
	char *s;
	int s_size;
	s_size = 100;
	s = M2_MALLOC_ATOMIC(s_size);
	while( getcwd(s, s_size) == NULL ){
		if( errno == ERANGE ){
			s_size = 2*s_size;
			s = M2_MALLOC_ATOMIC(s_size);
		} else {
/*701*/ 	m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 112, m2runtime_errno(), m2runtime_strerror());
/*702*/ 	return NULL;
		}
	}
	io_p = new_STRING(s, strlen(s));
/*706*/ 	return io_p;
/*710*/ }


/*713*/ void
/*713*/ io_ChDir(int try_section, STRING *io_p)
/*713*/ {
	char *pz;
/*715*/ 	if( m2runtime_InvalidZString(io_p) ){
/*716*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 113, 22, m2runtime_concat_STRING(0, m2runtime_StringToLiteral(io_p), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)": pathfile NIL or containing a NUL character", (STRING *) 1));
/*718*/ 		return ;
/*719*/ 	}
	MK_ZSTRING(pz, io_p);
	if( chdir(pz) != 0 ){
/*721*/ 	m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 114, m2runtime_errno(), m2runtime_concat_STRING(0, io_p, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", m2runtime_strerror(), (STRING *) 1));
	}
/*726*/ }


/*729*/ void
/*729*/ io_Unlink(int try_section, STRING *io_f)
/*729*/ {
	char *fz;
/*731*/ 	if( m2runtime_InvalidZString(io_f) ){
/*732*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 115, 22, m2runtime_concat_STRING(0, m2runtime_StringToLiteral(io_f), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)": pathfile NIL or containing a NUL character", (STRING *) 1));
/*734*/ 		return ;
/*735*/ 	}
	MK_ZSTRING(fz, io_f);
	if( remove(fz) == 0 )  return;
/*737*/ 	m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 116, m2runtime_errno(), m2runtime_concat_STRING(0, io_f, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", m2runtime_strerror(), (STRING *) 1));
/*741*/ }


/*744*/ void
/*744*/ io_Rename(int try_section, STRING *io_old, STRING *io_new)
/*744*/ {
 char *oldz, *newz;
/*746*/ 	if( (m2runtime_InvalidZString(io_old) || m2runtime_InvalidZString(io_new)) ){
/*747*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 117, 22, m2runtime_concat_STRING(0, m2runtime_StringToLiteral(io_old), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", m2runtime_StringToLiteral(io_new), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)": pathfile NIL or containing a NUL character", (STRING *) 1));
/*750*/ 		return ;
/*751*/ 	}
	MK_ZSTRING(oldz, io_old);
	MK_ZSTRING(newz, io_new);
	if( rename(oldz, newz) == 0 )  return;
/*754*/ 	m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 118, m2runtime_errno(), m2runtime_concat_STRING(0, io_old, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)", ", io_new, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", m2runtime_strerror(), (STRING *) 1));
/*758*/ }


/*761*/ void
/*761*/ io_MkDir(int try_section, STRING *io_d, STRING *io_mode)
/*761*/ {
/*762*/ 	int io_x = 0;
	char *dz;
/*764*/ 	if( m2runtime_InvalidZString(io_d) ){
/*765*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 119, 22, m2runtime_concat_STRING(0, m2runtime_StringToLiteral(io_d), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)": pathfile NIL or containing a NUL character", (STRING *) 1));
/*767*/ 		return ;
/*768*/ 	}
/*768*/ 	io_x = io_parse_mode(io_mode);
/*769*/ 	if( (io_x == -1) ){
/*770*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 120, 22, m2runtime_concat_STRING(0, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\15,\0,\0,\0)"invalid mode ", m2runtime_StringToLiteral(io_mode), (STRING *) 1));
/*772*/ 		return ;
/*773*/ 	}
	MK_ZSTRING(dz, io_d);
	if( mkdir(dz, io_x) == 0 )  return;
/*775*/ 	m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 121, m2runtime_errno(), m2runtime_concat_STRING(0, io_d, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\7,\0,\0,\0)", mode=", io_mode, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)": ", m2runtime_strerror(), (STRING *) 1));
/*779*/ }


/*781*/ void
/*781*/ io_Touch(int try_section, STRING *io_fn)
/*781*/ {
/*783*/ 	RECORD * io_f = NULL;
/*783*/ 	if( m2runtime_InvalidZString(io_fn) ){
/*784*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 122, 22, m2runtime_concat_STRING(0, m2runtime_StringToLiteral(io_fn), (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\54,\0,\0,\0)": pathfile NIL or containing a NUL character", (STRING *) 1));
/*786*/ 		return ;
/*788*/ 	}
/*788*/ 	m2runtime_ERROR_CODE = 0;
/*788*/ 	io_Open(1, &io_f, io_fn, (STRING *) INTSTR(\0,\0,\0,\0)INTSTR(\2,\0,\0,\0)"wc");
/*790*/ 	switch( m2runtime_ERROR_CODE ){

/*790*/ 	case 0:  break;
/*790*/ 	default:
/*790*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 123, m2runtime_ERROR_CODE, m2runtime_ERROR_MESSAGE);
/*792*/ 		return ;
/*794*/ 	}
/*794*/ 	m2runtime_ERROR_CODE = 0;
/*794*/ 	io_Close(1, &io_f);
/*796*/ 	switch( m2runtime_ERROR_CODE ){

/*796*/ 	case 0:  break;
/*796*/ 	default:
/*796*/ 		m2runtime_RAISE_ERROR(try_section, io_0err_entry_get, 124, m2runtime_ERROR_CODE, m2runtime_ERROR_MESSAGE);
/*799*/ 	}
/*802*/ }


char * io_0func[] = {
    "Open",
    "Write",
    "Written",
    "Read",
    "ReadLine",
    "Close",
    "next",
    "parse_mode",
    "if",
    "SetMask",
    "PoolSetNew",
    "SetTimeout",
    "Wait",
    "Timeout",
    "Readable",
    "Writable",
    "GetCWD",
    "ChDir",
    "Unlink",
    "Rename",
    "MkDir",
    "Touch"
};

int io_0err_entry[] = {
    0 /* Open */, 64,
    0 /* Open */, 93,
    0 /* Open */, 99,
    0 /* Open */, 111,
    0 /* Open */, 114,
    0 /* Open */, 115,
    0 /* Open */, 118,
    0 /* Open */, 121,
    0 /* Open */, 123,
    0 /* Open */, 124,
    0 /* Open */, 125,
    0 /* Open */, 146,
    0 /* Open */, 151,
    0 /* Open */, 152,
    1 /* Write */, 164,
    1 /* Write */, 167,
    1 /* Write */, 168,
    1 /* Write */, 171,
    1 /* Write */, 174,
    1 /* Write */, 175,
    1 /* Write */, 178,
    1 /* Write */, 180,
    1 /* Write */, 182,
    1 /* Write */, 184,
    1 /* Write */, 185,
    1 /* Write */, 190,
    1 /* Write */, 195,
    1 /* Write */, 196,
    1 /* Write */, 199,
    1 /* Write */, 215,
    1 /* Write */, 216,
    1 /* Write */, 218,
    1 /* Write */, 227,
    1 /* Write */, 231,
    2 /* Written */, 241,
    2 /* Written */, 244,
    3 /* Read */, 256,
    3 /* Read */, 259,
    3 /* Read */, 260,
    3 /* Read */, 263,
    3 /* Read */, 264,
    3 /* Read */, 268,
    3 /* Read */, 276,
    3 /* Read */, 278,
    3 /* Read */, 281,
    3 /* Read */, 290,
    3 /* Read */, 296,
    3 /* Read */, 299,
    3 /* Read */, 304,
    3 /* Read */, 312,
    4 /* ReadLine */, 323,
    4 /* ReadLine */, 326,
    4 /* ReadLine */, 327,
    4 /* ReadLine */, 330,
    4 /* ReadLine */, 331,
    4 /* ReadLine */, 339,
    4 /* ReadLine */, 357,
    5 /* Close */, 368,
    5 /* Close */, 371,
    5 /* Close */, 372,
    5 /* Close */, 375,
    5 /* Close */, 377,
    5 /* Close */, 380,
    5 /* Close */, 385,
    5 /* Close */, 387,
    5 /* Close */, 391,
    6 /* next */, 407,
    7 /* parse_mode */, 447,
    8 /* if */, 461,
    9 /* SetMask */, 478,
    10 /* PoolSetNew */, 503,
    10 /* PoolSetNew */, 504,
    11 /* SetTimeout */, 518,
    11 /* SetTimeout */, 519,
    12 /* Wait */, 534,
    12 /* Wait */, 535,
    12 /* Wait */, 536,
    12 /* Wait */, 537,
    12 /* Wait */, 540,
    12 /* Wait */, 550,
    12 /* Wait */, 551,
    12 /* Wait */, 554,
    12 /* Wait */, 558,
    12 /* Wait */, 562,
    12 /* Wait */, 563,
    12 /* Wait */, 566,
    12 /* Wait */, 570,
    12 /* Wait */, 586,
    12 /* Wait */, 589,
    13 /* Timeout */, 595,
    14 /* Readable */, 604,
    14 /* Readable */, 607,
    14 /* Readable */, 616,
    14 /* Readable */, 617,
    14 /* Readable */, 620,
    14 /* Readable */, 622,
    14 /* Readable */, 625,
    14 /* Readable */, 626,
    14 /* Readable */, 629,
    14 /* Readable */, 633,
    14 /* Readable */, 640,
    15 /* Writable */, 648,
    15 /* Writable */, 651,
    15 /* Writable */, 660,
    15 /* Writable */, 661,
    15 /* Writable */, 664,
    15 /* Writable */, 666,
    15 /* Writable */, 669,
    15 /* Writable */, 670,
    15 /* Writable */, 673,
    15 /* Writable */, 677,
    15 /* Writable */, 684,
    16 /* GetCWD */, 701,
    17 /* ChDir */, 716,
    17 /* ChDir */, 721,
    18 /* Unlink */, 732,
    18 /* Unlink */, 737,
    19 /* Rename */, 747,
    19 /* Rename */, 754,
    20 /* MkDir */, 765,
    20 /* MkDir */, 770,
    20 /* MkDir */, 775,
    21 /* Touch */, 784,
    21 /* Touch */, 790,
    21 /* Touch */, 796
};

void io_0err_entry_get(int i, char **m, char **f, int *l)
{
    *m = "io";
    *f = io_0func[ io_0err_entry[2*i] ];
    *l = io_0err_entry[2*i + 1];
}
