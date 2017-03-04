/* Generated by lx */

#ifndef LX_H
#define LX_H

enum lx_like_token {
	TOK_CHAR,
	TOK_MANY,
	TOK_ANY,
	TOK_EOF,
	TOK_ERROR,
	TOK_UNKNOWN
};

/*
 * .byte is 0-based.
 * .line and .col are 1-based; 0 means unknown.
 */
struct lx_pos {
	unsigned byte;
	unsigned line;
	unsigned col;
};

struct lx_like_lx {
	int (*lgetc)(struct lx_like_lx *lx);
	void *opaque;

	int c; /* lx_like_ungetc buffer */

	struct lx_pos start;
	struct lx_pos end;

	void *buf;
	int  (*push) (struct lx_like_lx *lx, char c);
	void (*pop)  (struct lx_like_lx *lx);
	int  (*clear)(struct lx_like_lx *lx);
	void (*free) (struct lx_like_lx *lx);

	enum lx_like_token (*z)(struct lx_like_lx *lx);
};

/*
 * The initial buffer size; this ought to be over the typical token length,
 * so as to avoid a run-up of lots of resizing.
 */
#ifndef LX_DYN_LOW
#define LX_DYN_LOW 1 << 10
#endif

/*
 * High watermark; if the buffer grows over this, it will resize back down
 * by LX_DYN_FACTOR when no longer in use.
 */
#ifndef LX_DYN_HIGH
#define LX_DYN_HIGH 1 << 13
#endif

/*
 * Andrew Koenig said the growth factor should be less than phi, (1 + sqrt(5)) / 2
 * P.J. Plauger said 1.5 works well in practice. (Perhaps because of internal
 * bookkeeping data stored by the allocator.)
 *
 * Non-integer factors here add the constraint that LX_DYN_LOW > 1 because
 * because conversion to size_t truncates, and e.g. 1 * 1.5 == 1 is no good
 * as the requirement is to *increase* a buffer.
 */
#ifndef LX_DYN_FACTOR
#define LX_DYN_FACTOR 2
#endif

/* dynamic token buffer */
struct lx_dynbuf {
	char *p;
	size_t len;
	char *a;
};

const char *lx_like_name(enum lx_like_token t);
const char *lx_like_example(enum lx_like_token (*z)(struct lx_like_lx *), enum lx_like_token t);

void lx_like_init(struct lx_like_lx *lx);
enum lx_like_token lx_like_next(struct lx_like_lx *lx);

int  lx_like_dynpush(struct lx_like_lx *lx, char c);
void lx_like_dynpop(struct lx_like_lx *lx);
int  lx_like_dynclear(struct lx_like_lx *lx);
void lx_like_dynfree(struct lx_like_lx *lx);

#endif

