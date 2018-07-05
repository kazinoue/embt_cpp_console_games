//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPlayer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>

__fastcall g_player::TGame2::TGame2(const wchar_t* s, std::shared_ptr<g_framework::TRandomObj>& rn, std::shared_ptr<TPlayer> p1, std::shared_ptr<TPlayer> p2):TGame(s,rn)
{
    p1->SetStdHandle(f_hStdOut);
	p2->SetStdHandle(f_hStdOut);
	playerP[g_player::TPlayerStat::Com] = p1;
	playerP[g_player::TPlayerStat::Man] = p2;
}

__fastcall g_player::TGame2::~TGame2()
{

}

g_player::TPlayerStat __fastcall g_player::TGame2::first()
{
	int n = misc::TMisc::get_menu(L"先攻（１:コンピュータ,２:貴様）？", 1, 2);
	std::cout << std::endl;
	return (n == 1)? g_player::TPlayerStat::Com:g_player::TPlayerStat::Man;
}

void __fastcall g_player::TGame2::ginit()
{
	playerP[g_player::TPlayerStat::Com]->reset();
	playerP[g_player::TPlayerStat::Man]->reset();

	turn = first();

	TGame::ginit();
	std::wcout << L"成功：" << playerP[g_player::TPlayerStat::Man]->get_nwin() << L"勝　"
		<< playerP[g_player::TPlayerStat::Com]->get_nwin() << L"負" << std::endl;
}

Bool __fastcall g_player::TGame2::gplay()
{
	return (turn == g_player::TPlayerStat::Com)?
		playerP[g_player::TPlayerStat::Com]->play(turn):playerP[g_player::TPlayerStat::Man]->play(turn);
}

void __fastcall g_player::TGame2::gdone()
{
	int sc = playerP[g_player::TPlayerStat::Com]->get_score();
	int nm = playerP[g_player::TPlayerStat::Man]->get_score();

	TGame::gdone();
	std::wcout << L"総合得点：コンピュータ＝" << sc << L"、貴様＝" << nm << std::endl;

	if (sc == nm)
	{
		std::wcout << L"＊＊＊引き分け＊＊＊" << std::endl;
	}
	else if (sc > nm)
	{
		std::wcout << L"＊＊＊コンピュータの勝利＊＊＊" << std::endl;
		playerP[g_player::TPlayerStat::Com]->win();
	}
	else
	{
		std::wcout << L"＊＊＊貴様は勝利を手にした＊＊＊" << std::endl;
		playerP[g_player::TPlayerStat::Com]->win();
	}
    misc::TMisc::anykey();
}



void __fastcall g_player::TPlayer::SetTextAttribute(WORD wAttributes)
{
	::SetConsoleTextAttribute(f_hStdOut, wAttributes);
}

void __fastcall g_player::TPlayer::SetStdHandle(HANDLE lhstd)
{
	f_hStdOut = lhstd;
}

