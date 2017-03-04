/* Generated by lx */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include LX_HEADER

static enum lx_native_token z0(struct lx_native_lx *lx);
static enum lx_native_token z1(struct lx_native_lx *lx);
static enum lx_native_token z2(struct lx_native_lx *lx);

#if __STDC_VERSION__ >= 199901L
inline
#endif
static int
lx_getc(struct lx_native_lx *lx)
{
	int c;

	assert(lx != NULL);
	assert(lx->lgetc != NULL);

	if (lx->c != EOF) {
		c = lx->c, lx->c = EOF;
	} else {
		c = lx->lgetc(lx);
		if (c == EOF) {
			return EOF;
		}
	}

	lx->end.byte++;
	lx->end.col++;

	if (c == '\n') {
		lx->end.line++;
		lx->end.col = 1;
	}

	return c;
}

#if __STDC_VERSION__ >= 199901L
inline
#endif
static void
lx_native_ungetc(struct lx_native_lx *lx, int c)
{
	assert(lx != NULL);
	assert(lx->c == EOF);

	lx->c = c;

	if (lx->pop != NULL) {
		lx->pop(lx);
	}

	lx->end.byte--;
	lx->end.col--;

	if (c == '\n') {
		lx->end.line--;
		lx->end.col = 0; /* XXX: lost information */
	}
}

int
lx_native_dynpush(struct lx_native_lx *lx, char c)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);
	assert(c != EOF);

	t = lx->buf;

	assert(t != NULL);

	if (t->p == t->a + t->len) {
		size_t len;
		char *tmp;

		if (t->len == 0) {
			assert(LX_DYN_LOW > 0);
			len = LX_DYN_LOW;
		} else {
			len = t->len * LX_DYN_FACTOR;
			if (len < t->len) {
				errno = ERANGE;
				return -1;
			}
		}

		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->p   = tmp + (t->p - t->a);
		t->a   = tmp;
		t->len = len;
	}

	assert(t->p != NULL);
	assert(t->a != NULL);

	*t->p++ = c;

	return 0;
}

void
lx_native_dynpop(struct lx_native_lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);
	assert(t->a != NULL);
	assert(t->p >= t->a);

	if (t->p == t->a) {
		return;
	}

	t->p--;
}

int
lx_native_dynclear(struct lx_native_lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	if (t->len > LX_DYN_HIGH) {
		size_t len;
		char *tmp;

		len = t->len / LX_DYN_FACTOR;

		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->a   = tmp;
		t->len = len;
	}

	t->p = t->a;

	return 0;
}

void
lx_native_dynfree(struct lx_native_lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	free(t->a);
}
static enum lx_native_token
z0(struct lx_native_lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S0;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* start */
			switch (c) {
			case ',': state = S1; continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S2; continue;
			case '}': state = S3; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "," */
			lx_native_ungetc(lx, c); return TOK_SEP;

		case S2: /* e.g. "0" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': continue;
			default:  lx_native_ungetc(lx, c); return TOK_COUNT;
			}

		case S3: /* e.g. "}" */
			lx_native_ungetc(lx, c); return lx->z = z2, TOK_CLOSECOUNT;
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_SEP;
	case S2: return TOK_COUNT;
	case S3: return TOK_CLOSECOUNT;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_native_token
z1(struct lx_native_lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3, S4, S5, S6, S7, S8, S9
		
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S0;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* start */
			switch (c) {
			case '\x00':
			case '\x01':
			case '\x02':
			case '\x03':
			case '\x04':
			case '\x05':
			case '\x06':
			case '\a':
			case '\b':
			case '\t':
			case '\n':
			case '\v':
			case '\f':
			case '\r':
			case '\x0e':
			case '\x0f':
			case '\x10':
			case '\x11':
			case '\x12':
			case '\x13':
			case '\x14':
			case '\x15':
			case '\x16':
			case '\x17':
			case '\x18':
			case '\x19':
			case '\x1a':
			case '\x1b':
			case '\x1c':
			case '\x1d':
			case '\x1e':
			case '\x1f':
			case ' ':
			case '!':
			case '"':
			case '#':
			case '$':
			case '%':
			case '&':
			case '\'':
			case '(':
			case ')':
			case '*':
			case '+':
			case ',': state = S1; continue;
			case '-': state = S2; continue;
			case '.':
			case '\x2f':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case ':':
			case ';':
			case '<':
			case '=':
			case '>':
			case '?':
			case '@':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '[': state = S1; continue;
			case '\\': state = S3; continue;
			case ']': state = S4; continue;
			case '^': state = S5; continue;
			case '_':
			case '`':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case '{':
			case '|':
			case '}':
			case '~':
			case '\x7f':
			case '\x80':
			case '\x81':
			case '\x82':
			case '\x83':
			case '\x84':
			case '\x85':
			case '\x86':
			case '\x87':
			case '\x88':
			case '\x89':
			case '\x8a':
			case '\x8b':
			case '\x8c':
			case '\x8d':
			case '\x8e':
			case '\x8f':
			case '\x90':
			case '\x91':
			case '\x92':
			case '\x93':
			case '\x94':
			case '\x95':
			case '\x96':
			case '\x97':
			case '\x98':
			case '\x99':
			case '\x9a':
			case '\x9b':
			case '\x9c':
			case '\x9d':
			case '\x9e':
			case '\x9f':
			case '\xa0':
			case '\xa1':
			case '\xa2':
			case '\xa3':
			case '\xa4':
			case '\xa5':
			case '\xa6':
			case '\xa7':
			case '\xa8':
			case '\xa9':
			case '\xaa':
			case '\xab':
			case '\xac':
			case '\xad':
			case '\xae':
			case '\xaf':
			case '\xb0':
			case '\xb1':
			case '\xb2':
			case '\xb3':
			case '\xb4':
			case '\xb5':
			case '\xb6':
			case '\xb7':
			case '\xb8':
			case '\xb9':
			case '\xba':
			case '\xbb':
			case '\xbc':
			case '\xbd':
			case '\xbe':
			case '\xbf':
			case '\xc0':
			case '\xc1':
			case '\xc2':
			case '\xc3':
			case '\xc4':
			case '\xc5':
			case '\xc6':
			case '\xc7':
			case '\xc8':
			case '\xc9':
			case '\xca':
			case '\xcb':
			case '\xcc':
			case '\xcd':
			case '\xce':
			case '\xcf':
			case '\xd0':
			case '\xd1':
			case '\xd2':
			case '\xd3':
			case '\xd4':
			case '\xd5':
			case '\xd6':
			case '\xd7':
			case '\xd8':
			case '\xd9':
			case '\xda':
			case '\xdb':
			case '\xdc':
			case '\xdd':
			case '\xde':
			case '\xdf':
			case '\xe0':
			case '\xe1':
			case '\xe2':
			case '\xe3':
			case '\xe4':
			case '\xe5':
			case '\xe6':
			case '\xe7':
			case '\xe8':
			case '\xe9':
			case '\xea':
			case '\xeb':
			case '\xec':
			case '\xed':
			case '\xee':
			case '\xef':
			case '\xf0':
			case '\xf1':
			case '\xf2':
			case '\xf3':
			case '\xf4':
			case '\xf5':
			case '\xf6':
			case '\xf7':
			case '\xf8':
			case '\xf9':
			case '\xfa':
			case '\xfb':
			case '\xfc':
			case '\xfd':
			case '\xfe':
			case '\xff': state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_native_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. "-" */
			lx_native_ungetc(lx, c); return TOK_RANGE;

		case S3: /* e.g. "\\" */
			switch (c) {
			case '-': state = S6; continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': state = S7; continue;
			case '\\': state = S6; continue;
			case '^': state = S6; continue;
			case 'f': state = S6; continue;
			case 'n': state = S6; continue;
			case 'r': state = S6; continue;
			case 't': state = S6; continue;
			case 'v': state = S6; continue;
			case 'x': state = S8; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S4: /* e.g. "]" */
			lx_native_ungetc(lx, c); return lx->z = z2, TOK_CLOSEGROUP;

		case S5: /* e.g. "^" */
			lx_native_ungetc(lx, c); return TOK_INVERT;

		case S6: /* e.g. "\\f" */
			lx_native_ungetc(lx, c); return TOK_ESC;

		case S7: /* e.g. "\\0" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': continue;
			default:  lx_native_ungetc(lx, c); return TOK_OCT;
			}

		case S8: /* e.g. "\\x" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S9; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': state = S9; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': state = S9; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S9: /* e.g. "\\xa" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': continue;
			default:  lx_native_ungetc(lx, c); return TOK_HEX;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_CHAR;
	case S2: return TOK_RANGE;
	case S4: return TOK_CLOSEGROUP;
	case S5: return TOK_INVERT;
	case S6: return TOK_ESC;
	case S7: return TOK_OCT;
	case S9: return TOK_HEX;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_native_token
z2(struct lx_native_lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, 
		S10, S11, S12, S13, S14, S15, S16, S17
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S0;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* start */
			switch (c) {
			case '\x00':
			case '\x01':
			case '\x02':
			case '\x03':
			case '\x04':
			case '\x05':
			case '\x06':
			case '\a':
			case '\b':
			case '\t':
			case '\n':
			case '\v':
			case '\f':
			case '\r':
			case '\x0e':
			case '\x0f':
			case '\x10':
			case '\x11':
			case '\x12':
			case '\x13':
			case '\x14':
			case '\x15':
			case '\x16':
			case '\x17':
			case '\x18':
			case '\x19':
			case '\x1a':
			case '\x1b':
			case '\x1c':
			case '\x1d':
			case '\x1e':
			case '\x1f':
			case ' ':
			case '!':
			case '"':
			case '#': state = S1; continue;
			case '$': state = S2; continue;
			case '%':
			case '&':
			case '\'': state = S1; continue;
			case '(': state = S3; continue;
			case ')': state = S4; continue;
			case '*': state = S5; continue;
			case '+': state = S6; continue;
			case ',':
			case '-': state = S1; continue;
			case '.': state = S7; continue;
			case '\x2f':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case ':':
			case ';':
			case '<':
			case '=':
			case '>': state = S1; continue;
			case '?': state = S8; continue;
			case '@':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S1; continue;
			case '[': state = S9; continue;
			case '\\': state = S10; continue;
			case ']': state = S1; continue;
			case '^': state = S11; continue;
			case '_':
			case '`':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S1; continue;
			case '{': state = S12; continue;
			case '|': state = S13; continue;
			case '}':
			case '~':
			case '\x7f':
			case '\x80':
			case '\x81':
			case '\x82':
			case '\x83':
			case '\x84':
			case '\x85':
			case '\x86':
			case '\x87':
			case '\x88':
			case '\x89':
			case '\x8a':
			case '\x8b':
			case '\x8c':
			case '\x8d':
			case '\x8e':
			case '\x8f':
			case '\x90':
			case '\x91':
			case '\x92':
			case '\x93':
			case '\x94':
			case '\x95':
			case '\x96':
			case '\x97':
			case '\x98':
			case '\x99':
			case '\x9a':
			case '\x9b':
			case '\x9c':
			case '\x9d':
			case '\x9e':
			case '\x9f':
			case '\xa0':
			case '\xa1':
			case '\xa2':
			case '\xa3':
			case '\xa4':
			case '\xa5':
			case '\xa6':
			case '\xa7':
			case '\xa8':
			case '\xa9':
			case '\xaa':
			case '\xab':
			case '\xac':
			case '\xad':
			case '\xae':
			case '\xaf':
			case '\xb0':
			case '\xb1':
			case '\xb2':
			case '\xb3':
			case '\xb4':
			case '\xb5':
			case '\xb6':
			case '\xb7':
			case '\xb8':
			case '\xb9':
			case '\xba':
			case '\xbb':
			case '\xbc':
			case '\xbd':
			case '\xbe':
			case '\xbf':
			case '\xc0':
			case '\xc1':
			case '\xc2':
			case '\xc3':
			case '\xc4':
			case '\xc5':
			case '\xc6':
			case '\xc7':
			case '\xc8':
			case '\xc9':
			case '\xca':
			case '\xcb':
			case '\xcc':
			case '\xcd':
			case '\xce':
			case '\xcf':
			case '\xd0':
			case '\xd1':
			case '\xd2':
			case '\xd3':
			case '\xd4':
			case '\xd5':
			case '\xd6':
			case '\xd7':
			case '\xd8':
			case '\xd9':
			case '\xda':
			case '\xdb':
			case '\xdc':
			case '\xdd':
			case '\xde':
			case '\xdf':
			case '\xe0':
			case '\xe1':
			case '\xe2':
			case '\xe3':
			case '\xe4':
			case '\xe5':
			case '\xe6':
			case '\xe7':
			case '\xe8':
			case '\xe9':
			case '\xea':
			case '\xeb':
			case '\xec':
			case '\xed':
			case '\xee':
			case '\xef':
			case '\xf0':
			case '\xf1':
			case '\xf2':
			case '\xf3':
			case '\xf4':
			case '\xf5':
			case '\xf6':
			case '\xf7':
			case '\xf8':
			case '\xf9':
			case '\xfa':
			case '\xfb':
			case '\xfc':
			case '\xfd':
			case '\xfe':
			case '\xff': state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_native_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. "$" */
			lx_native_ungetc(lx, c); return TOK_END;

		case S3: /* e.g. "(" */
			lx_native_ungetc(lx, c); return TOK_OPENSUB;

		case S4: /* e.g. ")" */
			lx_native_ungetc(lx, c); return TOK_CLOSESUB;

		case S5: /* e.g. "*" */
			lx_native_ungetc(lx, c); return TOK_STAR;

		case S6: /* e.g. "+" */
			lx_native_ungetc(lx, c); return TOK_PLUS;

		case S7: /* e.g. "." */
			lx_native_ungetc(lx, c); return TOK_ANY;

		case S8: /* e.g. "?" */
			lx_native_ungetc(lx, c); return TOK_OPT;

		case S9: /* e.g. "[" */
			lx_native_ungetc(lx, c); return lx->z = z1, TOK_OPENGROUP;

		case S10: /* e.g. "\\" */
			switch (c) {
			case '$': state = S14; continue;
			case '(':
			case ')':
			case '*':
			case '+': state = S14; continue;
			case '.': state = S14; continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': state = S15; continue;
			case '?': state = S14; continue;
			case '[':
			case '\\': state = S14; continue;
			case '^': state = S14; continue;
			case 'f': state = S14; continue;
			case 'n': state = S14; continue;
			case 'r': state = S14; continue;
			case 't': state = S14; continue;
			case 'v': state = S14; continue;
			case 'x': state = S16; continue;
			case '{':
			case '|': state = S14; continue;
			default:  lx_native_ungetc(lx, c); return TOK_CHAR;
			}

		case S11: /* e.g. "^" */
			lx_native_ungetc(lx, c); return TOK_START;

		case S12: /* e.g. "{" */
			lx_native_ungetc(lx, c); return lx->z = z0, TOK_OPENCOUNT;

		case S13: /* e.g. "|" */
			lx_native_ungetc(lx, c); return TOK_ALT;

		case S14: /* e.g. "\\f" */
			lx_native_ungetc(lx, c); return TOK_ESC;

		case S15: /* e.g. "\\0" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': continue;
			default:  lx_native_ungetc(lx, c); return TOK_OCT;
			}

		case S16: /* e.g. "\\x" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S17; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': state = S17; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': state = S17; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S17: /* e.g. "\\xa" */
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': continue;
			default:  lx_native_ungetc(lx, c); return TOK_HEX;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_CHAR;
	case S2: return TOK_END;
	case S3: return TOK_OPENSUB;
	case S4: return TOK_CLOSESUB;
	case S5: return TOK_STAR;
	case S6: return TOK_PLUS;
	case S7: return TOK_ANY;
	case S8: return TOK_OPT;
	case S9: return TOK_OPENGROUP;
	case S10: return TOK_CHAR;
	case S11: return TOK_START;
	case S12: return TOK_OPENCOUNT;
	case S13: return TOK_ALT;
	case S14: return TOK_ESC;
	case S15: return TOK_OCT;
	case S17: return TOK_HEX;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

const char *
lx_native_name(enum lx_native_token t)
{
	switch (t) {
	case TOK_COUNT: return "COUNT";
	case TOK_SEP: return "SEP";
	case TOK_CLOSECOUNT: return "CLOSECOUNT";
	case TOK_OPENCOUNT: return "OPENCOUNT";
	case TOK_CHAR: return "CHAR";
	case TOK_RANGE: return "RANGE";
	case TOK_INVERT: return "INVERT";
	case TOK_CLOSEGROUP: return "CLOSEGROUP";
	case TOK_OPENGROUP: return "OPENGROUP";
	case TOK_HEX: return "HEX";
	case TOK_OCT: return "OCT";
	case TOK_ESC: return "ESC";
	case TOK_ALT: return "ALT";
	case TOK_ANY: return "ANY";
	case TOK_PLUS: return "PLUS";
	case TOK_STAR: return "STAR";
	case TOK_OPT: return "OPT";
	case TOK_END: return "END";
	case TOK_START: return "START";
	case TOK_CLOSESUB: return "CLOSESUB";
	case TOK_OPENSUB: return "OPENSUB";
	case TOK_EOF:     return "EOF";
	case TOK_ERROR:   return "ERROR";
	case TOK_UNKNOWN: return "UNKNOWN";
	default: return "?";
	}
}

const char *
lx_native_example(enum lx_native_token (*z)(struct lx_native_lx *), enum lx_native_token t)
{
	assert(z != NULL);

	if (z == z0) {
		switch (t) {
		case TOK_COUNT: return "0";
		case TOK_SEP: return ",";
		case TOK_CLOSECOUNT: return "}";
		default: goto error;
		}
	} else
	if (z == z1) {
		switch (t) {
		case TOK_CHAR: return "a";
		case TOK_RANGE: return "-";
		case TOK_INVERT: return "^";
		case TOK_CLOSEGROUP: return "]";
		case TOK_HEX: return "\\xa";
		case TOK_OCT: return "\\0";
		case TOK_ESC: return "\\f";
		default: goto error;
		}
	} else
	if (z == z2) {
		switch (t) {
		case TOK_OPENCOUNT: return "{";
		case TOK_CHAR: return "a";
		case TOK_OPENGROUP: return "[";
		case TOK_HEX: return "\\xa";
		case TOK_OCT: return "\\0";
		case TOK_ESC: return "\\f";
		case TOK_ALT: return "|";
		case TOK_ANY: return ".";
		case TOK_PLUS: return "+";
		case TOK_STAR: return "*";
		case TOK_OPT: return "?";
		case TOK_END: return "$";
		case TOK_START: return "^";
		case TOK_CLOSESUB: return ")";
		case TOK_OPENSUB: return "(";
		default: goto error;
		}
	}

error:

	errno = EINVAL;
	return NULL;
}

void
lx_native_init(struct lx_native_lx *lx)
{
	static const struct lx_native_lx lx_default;

	assert(lx != NULL);

	*lx = lx_default;

	lx->c = EOF;
	lx->z = z2;

	lx->end.byte = 0;
	lx->end.line = 1;
	lx->end.col  = 1;
}

enum lx_native_token
lx_native_next(struct lx_native_lx *lx)
{
	enum lx_native_token t;

	assert(lx != NULL);
	assert(lx->z != NULL);

	if (lx->lgetc == NULL) {
		return TOK_EOF;
	}

	t = lx->z(lx);

	if (lx->push != NULL) {
		if (-1 == lx->push(lx, '\0')) {
			return TOK_ERROR;
		}
	}

	return t;
}

