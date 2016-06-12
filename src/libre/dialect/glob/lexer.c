/* Generated by lx */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include LX_HEADER

static enum lx_glob_token z0(struct lx_glob_lx *lx);

static int
lx_getc(struct lx_glob_lx *lx)
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

static void
lx_glob_ungetc(struct lx_glob_lx *lx, int c)
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
lx_glob_fgetc(struct lx_glob_lx *lx)
{
	assert(lx != NULL);
	assert(lx->opaque != NULL);

	return fgetc(lx->opaque);
}

int
lx_glob_dynpush(struct lx_glob_lx *lx, char c)
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
lx_glob_dynpop(struct lx_glob_lx *lx)
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
lx_glob_dynclear(struct lx_glob_lx *lx)
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
lx_glob_dynfree(struct lx_glob_lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	free(t->a);
}
static enum lx_glob_token
z0(struct lx_glob_lx *lx)
{
	int c;

	enum {
		S0, S1, S2, S3
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S3;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* e.g. "*" */
			switch (c) {
			default:  lx_glob_ungetc(lx, c); return TOK_STAR;
			}

		case S1: /* e.g. "?" */
			switch (c) {
			default:  lx_glob_ungetc(lx, c); return TOK_QMARK;
			}

		case S2: /* e.g. "a" */
			switch (c) {
			default:  lx_glob_ungetc(lx, c); return TOK_CHAR;
			}

		case S3: /* start */
			switch (c) {
			case '*': state = S0;      continue;
			case '?': state = S1;      continue;
			default:  state = S2;     continue;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S0: return TOK_STAR;
	case S1: return TOK_QMARK;
	case S2: return TOK_CHAR;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

const char *
lx_glob_name(enum lx_glob_token t)
{
	switch (t) {
	case TOK_CHAR: return "CHAR";
	case TOK_QMARK: return "QMARK";
	case TOK_STAR: return "STAR";
	case TOK_EOF:     return "EOF";
	case TOK_ERROR:   return "ERROR";
	case TOK_UNKNOWN: return "UNKNOWN";
	default: return "?";
	}
}

const char *
lx_glob_example(enum lx_glob_token (*z)(struct lx_glob_lx *), enum lx_glob_token t)
{
	assert(z != NULL);

	if (z == z0) {
		switch (t) {
		case TOK_CHAR: return "a";
		case TOK_QMARK: return "?";
		case TOK_STAR: return "*";
		default: goto error;
		}
	}

error:

	errno = EINVAL;
	return NULL;
}

void
lx_glob_init(struct lx_glob_lx *lx)
{
	static const struct lx_glob_lx lx_default;

	assert(lx != NULL);

	*lx = lx_default;

	lx->c = EOF;
	lx->z = NULL;

	lx->end.byte = 0;
	lx->end.line = 1;
	lx->end.col  = 1;
}

enum lx_glob_token
lx_glob_next(struct lx_glob_lx *lx)
{
	enum lx_glob_token t;

	assert(lx != NULL);

	if (lx->lgetc == NULL) {
		return TOK_EOF;
	}

	if (lx->z == NULL) {
		lx->z = z0;
	}

	t = lx->z(lx);

	if (lx->push != NULL) {
		if (-1 == lx->push(lx, '\0')) {
			return TOK_ERROR;
		}
	}

	if (lx->lgetc == NULL && lx->free != NULL) {
		lx->free(lx);
	}

	return t;
}
