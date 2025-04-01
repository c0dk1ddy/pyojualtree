#pragma once
#ifndef _PYOJUALTREE_H
#include <mybool.h>
#define _PYOJUALTREE_H(cmd, compile_flag) inline bool alu(register autolike cmd, register bool compile_flag)
#define __MY_EMPTY__

typedef void* autolike;

typedef struct {
	autolike instruction;
	autolike edge_of_y;
	autolike edge_of_n;
} uncompiled_block;

typedef struct {
	autolike jmpnt;
	block* y;
	block* n;
} block;

typedef block* blocks;
typedef uncompiled_block* uncompiled_blocks*;

_PYOJUALTREE_H(__MY_EMPTY__, __MYEMPTY__);

inline blocks cycling(register blocks cmd, register bool bool_flag_var) {
	bool_flag_var = false;
	cmd = alu(cmd->jmpnt, bool_flag_var)?cmd->y:cmd->n;
	return cmd;
}

inline bool compile(register uncompiled_blocks x, register uncompiled_blocks y, register bool bool_flag_var) {
	for (bool_flag_var = true; x != y; y--) {
		if alu(&y->instruction, bool_flag_var) {
			y->edge_of_y = x[y->edge_of_y];
			y->edge_of_n = x[y->edge_of_n];
		} else {
			bool_flag_var = false;
			return bool_flag_var;
		}
	}
	return bool_flag_var;
}

#endif
