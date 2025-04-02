#pragma once
#ifndef _CONSTEXPRCOMPILING_H
#define _CONSTEXPRCOMPILING_H
#define __PYOJUALTREE_INSTRUCTION_ERROR__
#include <pyojualtree_cpp_wrapper.h>

template <typename T, T L, T I = L - 1, typename G = noncompiled_block[L]>
constexpr struct __v_t {
	noncompiled_block core[L];
	constexpr inline blocks operator&(void) {
		return &this->core[I];
	}
	using coreT = G;
};

template <typename T, T L, T B = (3*L)+1>
constexpr struct __s_t {
	char core[B];
	constexpr inline __s_t(char core[B]) {
		this->core = core;
	}
	using size = B;
};

template <typename T, T L, typename G = __v_t<T, L>, typename E = __s_t<T, L>, T B = E::size, typename R = G::coreT>
constexpr struct constexprv_t {
	union {
		E s;
		G v;
	};
	constexpr inline auto operator()(bool p = false) {
		if (p) {
			if constexpr (!compile(&this->v.core, &this->v)) {
				__PYOJUALTREE_INSTRUCTION_ERROR__
				return nullptr;
			} else {
				return this->v;
			}
		} else {
			return (R) this(true); //__PYOJUALTREE_INSTRUCTION_ERROR__
		}
	}

	constexpr inline constexprv_t(char strv[B]) {
		this->s = E(strv);
	}
};

#endif
