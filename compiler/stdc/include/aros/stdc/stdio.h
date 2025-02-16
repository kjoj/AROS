#ifndef _STDC_STDIO_H_
#define _STDC_STDIO_H_

/*
    Copyright � 1995-2022, The AROS Development Team. All rights reserved.
    $Id$

    C99 header file stdio.h
*/
#include <aros/system.h>


/*
    FIXME: We are supposed to declare it, without including the file.
    This is too compiler specific to handle at the moment.
*/
#include <stdarg.h>

#include <aros/types/size_t.h>

struct __sFILE;
typedef struct __sFILE FILE;

#include <aros/types/fpos_t.h>

#include <aros/types/null.h>
/* Buffering methods that can be specified with setvbuf() */
#define _IOFBF 0 /* Fully buffered. */
#define _IOLBF 1 /* Line buffered. */
#define _IONBF 2 /* Not buffered. */

/* Need to protect against standard Amiga includes */
#ifndef BUFSIZ
#   define BUFSIZ	1024
#endif
#ifndef EOF
#   define EOF (-1)
#endif
#define FOPEN_MAX	16		/* Must be > 8 */
#define FILENAME_MAX	256		/* Amiga files are 256 */
#define L_tmpnam	FILENAME_MAX	/* Max temporary filename */

#include <aros/types/seek.h>            /* SEEK_SET, SEEK_CUR and SEEK_END */

#define TMP_MAX		10240		/* Must be > 10000 */

__BEGIN_DECLS

/* Functions are provided in static linklib in order to be able to access internal
   fields without needing to include proto/stdcio.h.
   These functions will be different if one links with or without posixc.
*/
FILE *__stdio_getstdin(void);
FILE *__stdio_getstdout(void);
FILE *__stdio_getstderr(void);

#define stdin __stdio_getstdin()
#define stdout __stdio_getstdout()
#define stderr __stdio_getstderr()


/* Internal functions */
int __vcformat (void * data, int (*outc)(int, void *),
		const char * format, va_list args);
int __vcscan (void * data, int (*getc)(void *),
		int (*ungetc)(int, void *),
		const char * format, va_list args);

/* Operations on files */
int remove(const char *filename);
int rename(const char *from, const char *to);
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
FILE *tmpfile(void);
char *tmpnam(char *s);
#endif

/* File access functions */
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
int fclose(FILE *stream);
int fflush(FILE *stream);
FILE *fopen(const char * restrict filename, const char * restrict mode);
FILE *freopen(const char * restrict filename, const char * restrict mode,
	FILE * restrict stream);
void setbuf(FILE * restrict stream, char * restrict buf);
int setvbuf(FILE * restrict stream, char * restrict buf, int mode,
	size_t size);
#endif

/* Formatted input/output functions */
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
int fprintf(FILE * restrict stream, const char * restrict format, ...);
int fscanf(FILE * restrict stream, const char * restrict format, ...);
int printf(const char * restrict format, ...);
int scanf(const char * restrict format, ...);
#endif
#if defined(_GNU_SOURCE)
int asprintf(char ** restrict str, const char * restrict format, ...);
#endif
int snprintf(char * restrict s, size_t n, const char * restrict format, ...);
int sprintf(char * restrict s, const char * restrict format, ...);
int sscanf(const char * restrict s, const char * restrict format, ...);
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
int vfprintf(FILE * restrict stream, const char * restrict format,
	va_list arg);
int vfscanf(FILE * restrict stream, const char * restrict format,
	va_list arg);
int vprintf(const char * restrict format, va_list arg);
int vscanf(const char * restrict format, va_list arg);
#endif
#if defined(_GNU_SOURCE)
int vasprintf(char **restrict str, const char *restrict format,
	va_list args);
#endif
int vsnprintf(char * restrict s, size_t n, const char * restrict format,
	va_list arg);
int vsprintf(char * restrict s, const char * restrict format,
	va_list arg);
int vsscanf(const char * restrict s, const char * restrict format,
	va_list arg);

/* Character input/output functions */
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
int fgetc(FILE *stream);
char *fgets(char * restrict s, int n, FILE * restrict stream);
int fputc(int c, FILE *stream);
int fputs(const char * restrict s, FILE * restrict stream);
#endif
int getc(FILE *stream);
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
#ifdef _STDIO_H_NOMACRO
int getchar(void);
#else
#define getchar()       fgetc(stdin)
#endif
char *gets(char *s);
int putchar(int c);
int puts(const char *s);
int ungetc(int c, FILE *stream);
#endif
int putc(int c, FILE *stream);

/* Direct input/output functions */
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
size_t fread(void * restrict ptr, size_t size, size_t nmemb,
    FILE * restrict stream);
size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb,
    FILE * restrict stream);
#endif

/* File positioning functions */
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
int fgetpos(FILE * restrict stream, fpos_t * restrict pos);
int fsetpos(FILE *stream, const fpos_t *pos);
int fseek(FILE *stream, long int offset, int whence);
long int ftell(FILE *stream);
void rewind(FILE *stream);
#endif

/* Error-handling functions */
void clearerr(FILE *stream);
#if (!defined(_XOPEN_SOURCE) && \
     !defined(_POSIX_SOURCE) && \
     !defined(_BSD_SOURCE))
int feof(FILE *stream);
int ferror(FILE *stream);
#endif
void perror(const char *s);

/* AROS specific function to synchronise to keep DOS Input and Output in sync
 * with the C stdin, stdout and stderr
 */
void updatestdio(void);

__END_DECLS

#endif /* _STDC_STDIO_H_ */
