/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
utf8_Lm_fsm(const struct fsm_options *opt)
{
	struct fsm *fsm;
	size_t i;

	struct fsm_state *s[50] = { 0 };

	fsm = fsm_new(opt);
	if (fsm == NULL) {
		return NULL;
	}

	for (i = 0; i < 50; i++) {
		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			goto error;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xca)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xcb)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[3], 0xcd)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[4], 0xd5)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[5], 0xd9)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[6], 0xdb)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[7], 0xdf)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[8], 0xe0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[9], 0xe1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[10], 0xe2)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[11], 0xe3)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[12], 0xea)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[13], 0xef)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[14], 0xf0)) { goto error; }
	for (i = 0xb0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[1], s[15], i)) { goto error; }
	}
	for (i = 0x80; i <= 0x81; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[15], i)) { goto error; }
	}
	for (i = 0x86; i <= 0x91; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[15], i)) { goto error; }
	}
	for (i = 0xa0; i <= 0xa4; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[2], s[15], 0xac)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[2], s[15], 0xae)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[3], s[15], 0xb4)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[3], s[15], 0xba)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[4], s[15], 0x99)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[5], s[15], 0x80)) { goto error; }
	for (i = 0xa5; i <= 0xa6; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[15], i)) { goto error; }
	}
	for (i = 0xb4; i <= 0xb5; i++) {
		if (!fsm_addedge_literal(fsm, s[7], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[7], s[15], 0xba)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[8], s[18], 0xa0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[8], s[19], 0xa5)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[8], s[20], 0xb9)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[8], s[20], 0xbb)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[33], 0xb1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[43], 0x83)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[44], 0x9f)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[45], 0xa1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[46], 0xaa)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[47], 0xb4)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[48], 0xb5)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[49], 0xb6)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[10], s[24], 0x81)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[10], s[25], 0x82)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[10], s[26], 0xb1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[10], s[27], 0xb5)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[10], s[27], 0xb8)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[11], s[21], 0x80)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[11], s[22], 0x82)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[11], s[23], 0x83)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[16], 0x9d)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[16], 0xa9)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[32], 0x80)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[33], 0x93)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[34], 0x98)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[35], 0x99)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[36], 0x9a)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[37], 0x9c)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[38], 0x9e)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[39], 0x9f)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[40], 0xa7)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[41], 0xab)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[42], 0xad)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[13], s[16], 0xbd)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[13], s[17], 0xbe)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[14], s[28], 0x96)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[16], s[15], 0xb0)) { goto error; }
	for (i = 0x9e; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[17], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[18], s[15], 0x9a)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[18], s[15], 0xa4)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[18], s[15], 0xa8)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[19], s[15], 0xb1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[20], s[15], 0x86)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[21], s[15], 0x85)) { goto error; }
	for (i = 0xb1; i <= 0xb5; i++) {
		if (!fsm_addedge_literal(fsm, s[21], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[21], s[15], 0xbb)) { goto error; }
	for (i = 0x9d; i <= 0x9e; i++) {
		if (!fsm_addedge_literal(fsm, s[22], s[15], i)) { goto error; }
	}
	for (i = 0xbc; i <= 0xbe; i++) {
		if (!fsm_addedge_literal(fsm, s[23], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[24], s[15], 0xb1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[24], s[15], 0xbf)) { goto error; }
	for (i = 0x90; i <= 0x9c; i++) {
		if (!fsm_addedge_literal(fsm, s[25], s[15], i)) { goto error; }
	}
	for (i = 0xbc; i <= 0xbd; i++) {
		if (!fsm_addedge_literal(fsm, s[26], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[27], s[15], 0xaf)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[28], s[29], 0xad)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[28], s[30], 0xbe)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[28], s[31], 0xbf)) { goto error; }
	for (i = 0x80; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[29], s[15], i)) { goto error; }
	}
	for (i = 0x93; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[30], s[15], i)) { goto error; }
	}
	for (i = 0xa0; i <= 0xa1; i++) {
		if (!fsm_addedge_literal(fsm, s[31], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[32], s[15], 0x95)) { goto error; }
	for (i = 0xb8; i <= 0xbd; i++) {
		if (!fsm_addedge_literal(fsm, s[33], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[34], s[15], 0x8c)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[35], s[15], 0xbf)) { goto error; }
	for (i = 0x9c; i <= 0x9d; i++) {
		if (!fsm_addedge_literal(fsm, s[36], s[15], i)) { goto error; }
	}
	for (i = 0x97; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[37], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[38], s[15], 0x88)) { goto error; }
	for (i = 0xb8; i <= 0xb9; i++) {
		if (!fsm_addedge_literal(fsm, s[39], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[40], s[15], 0x8f)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[40], s[15], 0xa6)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[41], s[15], 0x9d)) { goto error; }
	for (i = 0xb3; i <= 0xb4; i++) {
		if (!fsm_addedge_literal(fsm, s[41], s[15], i)) { goto error; }
	}
	for (i = 0x9c; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[42], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[43], s[15], 0xbc)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[44], s[15], 0x97)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[45], s[15], 0x83)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[46], s[15], 0xa7)) { goto error; }
	for (i = 0xac; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[47], s[15], i)) { goto error; }
	}
	for (i = 0x80; i <= 0xaa; i++) {
		if (!fsm_addedge_literal(fsm, s[48], s[15], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[48], s[15], 0xb8)) { goto error; }
	for (i = 0x9b; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[49], s[15], i)) { goto error; }
	}

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[15], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}

