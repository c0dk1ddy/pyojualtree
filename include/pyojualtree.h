#pragma once
#ifndef _PYOJUALTREE_H
#include <mybool.h>
#include <myfastcall.h>
#define _PYOJUALTREE_H(cmd, compile_flag) inline bool alu(register autolike cmd, register bool compile_flag)
#define __PYOJUALTREE_END__ pyojualtree_ending()
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

_Noreturn inline void __pyjualtree_exit__(void) {
	exit(0);
}

inline fastcall bool pyojualtree_ending(register bool bool_flag_var) {
	__pyojualtree_exit__();
	return bool_flag_var;
}

inline fastcall blocks cycling(register blocks cmd, register bool bool_flag_var) {
	bool_flag_var = false;
	cmd = alu(cmd->jmpnt, bool_flag_var)?cmd->y:cmd->n;
	return cmd;
}

inline fastcall void cpu(register blocks pyojualtree_point, register bool bool_flag_var) {
	while (true) pyojualtree_point = cycling(pyojualtree_point, bool_flag_var);
}

__Noreturn inline fastcall void run(register blocks pyojualtree_point, register bool bool_flag_var) {
	run(pyojualtree_point, bool_flag_var);
}

inline fastcall bool compile(register uncompiled_blocks x, register uncompiled_blocks y, register bool bool_flag_var) {
	for (bool_flag_var = true; x != y; y--) {
		if (alu(&y->instruction, bool_flag_var)) {
			y->edge_of_y = x[y->edge_of_y]; //[ TODO :: 1 ] need to find it use simd
			y->edge_of_n = x[y->edge_of_n];
		} else {
			bool_flag_var = false;
			return bool_flag_var;
		}
	}
	return bool_flag_var;
}

typedef struct {
	char* v;
	bool ischarptr;
} writing_unit;

inline fastcall writing_unit get_write_unit(char x, writing_unit retv) {
	static bool ischarptr[256] = {[};
	static char stringptr[256] = {};
	retv = {.stringptr = stringptr[x], .ischarptr = ischarptr[x]};
	return ret.v;
}

#endif
