#pragma once
#ifdef _DO_BARE_MATEL_
#define true 1
#define false 0
typedef unsigned char bool;
#else
#include <stdbool.h>
#endif
