#include <assert.h>
#include <stdio.h>

int
fsm_main(int (*fsm_getc)(void *opaque), void *opaque)
{
	int c;

	assert(fsm_getc != NULL);

	enum {
		S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, 
		S10, S11, S12, S13, S14, S15, S16, S17, S18, S19, 
		S20, S21, S22, S23, S24, S25, S26, S27
	} state;

	state = S0;

	while (c = fsm_getc(opaque), c != EOF) {
		switch (state) {
		case S0: /* start */
			switch ((unsigned char) c) {
			case 'c': state = S1; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S1: /* e.g. "c" */
			switch ((unsigned char) c) {
			case 'l': state = S2; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S2: /* e.g. "cl" */
			switch ((unsigned char) c) {
			case 'o': state = S3; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S3: /* e.g. "clo" */
			switch ((unsigned char) c) {
			case 'u': state = S4; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S4: /* e.g. "clou" */
			switch ((unsigned char) c) {
			case 'd': state = S5; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S5: /* e.g. "cloud" */
			switch ((unsigned char) c) {
			case 'l': state = S9; break;
			case 'e': state = S7; break;
			case 'i': state = S8; break;
			case 'b': state = S6; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S6: /* e.g. "cloudb" */
			switch ((unsigned char) c) {
			case 'u': state = S14; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S7: /* e.g. "cloude" */
			switch ((unsigned char) c) {
			case 'd': state = S10; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S8: /* e.g. "cloudi" */
			switch ((unsigned char) c) {
			case 'e': state = S19; break;
			case 'n': state = S20; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S9: /* e.g. "cloudl" */
			switch ((unsigned char) c) {
			case 'e': state = S11; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S10: /* e.g. "clouded" */
			return TOK_UNKNOWN;

		case S11: /* e.g. "cloudle" */
			switch ((unsigned char) c) {
			case 's': state = S12; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S12: /* e.g. "cloudles" */
			switch ((unsigned char) c) {
			case 's': state = S13; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S13: /* e.g. "cloudless" */
			return TOK_UNKNOWN;

		case S14: /* e.g. "cloudbu" */
			switch ((unsigned char) c) {
			case 'r': state = S15; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S15: /* e.g. "cloudbur" */
			switch ((unsigned char) c) {
			case 's': state = S16; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S16: /* e.g. "cloudburs" */
			switch ((unsigned char) c) {
			case 't': state = S17; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S17: /* e.g. "cloudburst" */
			switch ((unsigned char) c) {
			case 's': state = S18; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S18: /* e.g. "cloudbursts" */
			return TOK_UNKNOWN;

		case S19: /* e.g. "cloudie" */
			switch ((unsigned char) c) {
			case 'r': state = S21; break;
			case 's': state = S22; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S20: /* e.g. "cloudin" */
			switch ((unsigned char) c) {
			case 'e': state = S24; break;
			case 'g': state = S25; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S21: /* e.g. "cloudier" */
			return TOK_UNKNOWN;

		case S22: /* e.g. "cloudies" */
			switch ((unsigned char) c) {
			case 't': state = S23; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S23: /* e.g. "cloudiest" */
			return TOK_UNKNOWN;

		case S24: /* e.g. "cloudine" */
			switch ((unsigned char) c) {
			case 's': state = S26; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S25: /* e.g. "clouding" */
			return TOK_UNKNOWN;

		case S26: /* e.g. "cloudines" */
			switch ((unsigned char) c) {
			case 's': state = S27; break;
			default:  return TOK_UNKNOWN;
			}
			break;

		case S27: /* e.g. "cloudiness" */
			return TOK_UNKNOWN;

		default:
			; /* unreached */
		}
	}

	/* end states */
	switch (state) {
	case S10: return 0x4; /* "clouded" */
	case S13: return 0x80; /* "cloudless" */
	case S17: return 0x1; /* "cloudburst" */
	case S18: return 0x2; /* "cloudbursts" */
	case S21: return 0x8; /* "cloudier" */
	case S23: return 0x10; /* "cloudiest" */
	case S25: return 0x40; /* "clouding" */
	case S27: return 0x20; /* "cloudiness" */
	default: return EOF; /* unexpected EOF */
	}
}

