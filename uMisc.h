//---------------------------------------------------------------------------

#ifndef uMiscH
#define uMiscH
//---------------------------------------------------------------------------
#include <random>
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <sstream>


#define LineLen 80
enum Bool {bFalse, bTrue};
#define to_str( x ) static_cast< std::wostringstream & >( \
	( std::wostringstream() << std::dec << x ) ).str()

namespace misc{
	struct TMisc
	{
		static void __fastcall anykey();
		static int __fastcall get_check(int min, int max);
		static int __fastcall get_menu(const wchar_t* msg, int min, int max);
		static int __fastcall get_int(const wchar_t* msg);
		static void __fastcall decoration(const wchar_t* s, const wchar_t c);
		static int __fastcall get_random(std::mt19937& l_randomize, int min, int max);
        static void __fastcall randoma();
	};
}

#endif
