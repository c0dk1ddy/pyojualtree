#pragma once
#ifndef _CONSTEXPRCOMPILING_H
#define _CONSTEXPRCOMPILING_H
#include <pyojualtree_cpp_wrapper.h>

template <typename T, T L>
struct __v_t {
	noncompiled_block core[L];
};

template <typename T, T L, T B = (3*L)+1, typename G = __v_t<T, L>>
struct constexprv_t {
	union {
		char s[B];
		G v;
	};
	using v_t = G; 
	
};

constexpr inline 
#endif
