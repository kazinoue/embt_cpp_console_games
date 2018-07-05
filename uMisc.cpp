//---------------------------------------------------------------------------

#pragma hdrstop

#include "uMisc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall misc::TMisc::anykey()
{
	std::wcout << L"HIt any key ...";
	getch();									//エンター無し
	std::wcout << std::endl;
}

int __fastcall misc::TMisc::get_check(int min, int max)
{
	int d = getch() - '0';
	while (d < min || max < d)                  //範囲内になるまで入力
	{
		std::cout << '\a';
		d = getch() - '0';
    }
	return d;
}

int __fastcall misc::TMisc::get_int(const wchar_t* msg)
{
	int d;
	std::wcout << msg;
	std::wcin >> d;
    return d;
}

void __fastcall misc::TMisc::decoration(const wchar_t* s, const wchar_t c)
{
	wchar_t ds[LineLen];
	wcscpy(ds, s);
	_wcsset(ds, c);
	std::wcout << ds << std::endl;
	std::wcout << s  << std::endl;
	std::wcout << ds << std::endl;
}

int __fastcall misc::TMisc::get_random(std::mt19937& l_randomize, int min, int max)
{
	std::uniform_int_distribution<int> l_randomm(0, max-1 ) ;
	return l_randomm(l_randomize) + min;
}

int __fastcall misc::TMisc::get_menu(const wchar_t* msg, int min, int max)
{
	std::wcout << msg;
	int d = get_check(min, max);
	std::wcout << d << std::endl;
	return d;
}
