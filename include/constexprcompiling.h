#pragma once
#ifndef _CONSTEXPRCOMPILING_H
#define _CONSTEXPRCOMPILING_H
#include <pyojualtree_cpp_wrapper.h>

template <typename T, T L, T I = L - 1>
constexpr struct __v_t {
	noncompiled_block core[L];
	constexpr inline blocks operator&(void) {
		return &this->core[I];
	}
};

template <typename T, T L, T B = (3*L)+1, typename G = __v_t<T, L>>
constexpr struct constexprv_t {
	union {
		char s[B];
		G v;
	};
	using v_t = G;
};

template <typename T, T L, typename G = constexpr_t<T, L>>
constexpr static inline auto constexprcompiling(G x) {
	if constexpr (compile(&x.v.core, &x.v)) {
	
	}
}
#endif
