/*
 * Automatically generated from the files:
 *	src/libre/dialect/sql/parser.sid
 * and
 *	src/libre/parser.act
 * by:
 *	sid
 */

/* BEGINNING OF HEADER */

#line 382 "src/libre/parser.act"


	#include <re/re.h>

	typedef struct lex_state * lex_state;
	typedef struct act_state * act_state;

	typedef struct fsm *  fsm;
	typedef enum re_flags flags;
	typedef struct re_err * err;

#line 25 "src/libre/dialect/sql/parser.h"

/* BEGINNING OF FUNCTION DECLARATIONS */

extern void p_re__sql(fsm, flags, lex_state, act_state, err);
/* BEGINNING OF TRAILER */

#line 1187 "src/libre/parser.act"


#line 35 "src/libre/dialect/sql/parser.h"

/* END OF FILE */