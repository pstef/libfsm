/* $Id$ */

#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

#include <re/re.h>

const char *
re_strerror(enum re_errno e)
{
	switch (e) {
	case RE_ESUCCESS: return "Success";
	case RE_ENOMEM:   return strerror(ENOMEM);
	case RE_EBADFORM: return "Bad form";
	case RE_EXSUB:    return "Syntax error: expected sub-expression";
	case RE_EXTERM:   return "Syntax error: expected group term";
	case RE_EXGROUP:  return "Syntax error: expected group";
	case RE_EXATOM:   return "Syntax error: expected atom";
	case RE_EXCOUNT:  return "Syntax error: expected count";
	case RE_EXATOMS:  return "Syntax error: expected atoms list";
	case RE_EXALTS:   return "Syntax error: expected alternative list";
	case RE_EXEOF:    return "Syntax error: expected EOF";
	}

	assert(!"unreached");
	return NULL;
}
