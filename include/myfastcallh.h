#pragma once
#ifdef __GNUC__
#define fastcall __attribute__((regparm(3)))
#endif
#ifdef _MSC_VER
#define fastcall __fastcall
#endif
