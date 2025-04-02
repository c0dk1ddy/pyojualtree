#pragma once
#ifndef _CONSTEXPRCOMPILING_H
#define _CONSTEXPRCOMPILING_H
#define __PYOJUALTREE_INSTRUCTION_ERROR__
#include <pyojualtree_cpp_wrapper.h>

template <typename T, T L, T I = L - 1>
constexpr struct __v_t {
	noncompiled_block core[L];
	constexpr inline blocks operator&(void) {
		return &this->core[I];
	}
};

template <typename T, T L, T B = (3*L)+1>
constexpr struct __s_t {
	char core[B];
};

template <typename T, T L, typename G = __v_t<T, L>, typename E = __s_t<T, L>>
constexpr struct constexprv_t {
	union {
		E s;
		G v;
	};
	constexpr inline G operator()(void) {
		if constexpr (!compile(&this->v.core, &this->v)) {
			__PYOJUALTREE_INSTRUCTION_ERROR__
		}
		return this->v;
	}

	constexpr inline constexprv_t(E s) {
		this->s = s;
	}
};

#endif
