//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int __fastcall g_framework::TGame::menu()
{
	UnicodeString s = "which 1)説明 2)ゲーム 3)終了　？　";
	int d = misc::TMisc::get_menu(const_cast<wchar_t*>(s.c_str()), 1, 3);
	std::wcout << std::endl;
	return d;
}


void __fastcall g_framework::TGame::instruction()
{
	UnicodeString s = f_title + " : 説明";
	misc::TMisc::decoration(const_cast<wchar_t*>(f_title.c_str()), L'―');
}

void __fastcall g_framework::TGame::run()
{
	++nGame;
	ginit();
	while (gplay())
		;
	gdone();
}

void __fastcall g_framework::TGame::ginit()
{
	UnicodeString s = Format(L"%s：第%d回　ゲーム開始　！！", ARRAYOFCONST((f_title, nGame)));
	misc::TMisc::decoration(const_cast<wchar_t*>(s.c_str()), L'―');
}

void __fastcall g_framework::TGame::gdone()
{
	UnicodeString s = Format(L"%s：第%d回　ゲーム終了　！！", ARRAYOFCONST((f_title, nGame)));
	misc::TMisc::decoration(const_cast<wchar_t*>(s.c_str()), L'―');
	std::cout << "\a" << std::endl;
}

__fastcall g_framework::TGame::TGame(const wchar_t* s, std::shared_ptr<g_framework::TRandomObj>& l_random)
{
	f_hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	f_random1 = l_random;
	std::wcout.imbue(std::locale("Japanese"));
	nGame = 0;
	f_title = s;
	UnicodeString s1 = Format(L"＋＋＋》%s《＋＋＋", ARRAYOFCONST((f_title)) );
	misc::TMisc::decoration(const_cast<wchar_t*>(s1.c_str()), L'―');
	std::cout << std::endl;
}


void __fastcall g_framework::TGame::exec()
{
	for (;;)
	{
		switch (menu()) {
		case 1:
			instruction();
			break;
		case 2:
			run();
			break;
		case 3:
            return;
		default:
			;
		}
	}
}


