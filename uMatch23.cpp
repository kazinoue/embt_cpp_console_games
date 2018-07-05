//---------------------------------------------------------------------------

#pragma hdrstop

#include "uMatch23.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall g_match23::TMatch23::reset()
{
	nRound = 1;
    nMatch = 23;
}

void __fastcall g_match23::TMatch23::show(std::function<void()> func)
{
	std::wcout	<< std::setw(2) << nRound << L"］マッチの残り本数（"
				<<  std::setw(2) << nMatch << L"）：";
	for (int i = 0; i < nMatch; i++)
	{
		std::wcout << L"●";
	}
	std::wcout << std::endl;
	func();
}

int __fastcall g_match23::TMatch23::choice(int &n, g_player::TPlayerStat turn)
{
	++nRound;
	nMatch -= n;
	return nMatch;
}

g_match23::TMatch23 g_match23::TNPlayer::match23;

void __fastcall g_match23::TCom::reset()
{
	TNPlayer::reset();
	match23.reset();
}

Bool __fastcall g_match23::TCom::play(g_player::TPlayerStat &turn)
{
	SetTextAttribute(FOREGROUND_INTENSITY|FOREGROUND_RED);
	auto l_random = f_random1;
	int n{0};
	int* pn = &n;
	match23.show([pn, l_random](){
		*pn = match23.state(*pn, g_player::TPlayerStat::Com)%4;
		if (*pn == 1)
			*pn = misc::TMisc::get_random(l_random->f_randomize, 0, 3) + 1;
		else
			*pn = (*pn + 3)%4;
		if (*pn > match23.state(*pn, g_player::TPlayerStat::Com))
			*pn = match23.state(*pn, g_player::TPlayerStat::Com);
		Sleep(500);
		std::wcout << L"コンピュータは" << *pn << L"本取りました" << std::endl;

	});

	turn = g_player::TPlayerStat::Man;

	if (match23.choice(n, g_player::TPlayerStat::Com) <= 0)
		return Bool::bFalse;
	else
		return Bool::bTrue;

}

Bool __fastcall g_match23::TMan::play(g_player::TPlayerStat &turn)
{
	SetTextAttribute(FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	int n{0};
	int* pn = &n;

	match23.show([pn](){
		int max = (match23.state(*pn, g_player::TPlayerStat::Man)<3)?
			match23.state(*pn,g_player::TPlayerStat::Man):3;

		*pn = misc::TMisc::get_menu(L"何本とりますか？", 1, max);
		std::wcout << L"貴様は" << *pn << L"本取りました" << std::endl;
	});

	turn = g_player::TPlayerStat::Com;
	if (match23.choice(n, g_player::TPlayerStat::Man) <= 0)
		return Bool::bFalse;
	else
		return Bool::bTrue;

}
void __fastcall g_match23::TMatchGame23::instruction()
{
	playerP[g_player::TPlayerStat::Com]->SetTextAttribute(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
	const UnicodeString s = "マッチが２３本あります。\n貴様とコンピュータで交互にマッチを取ります\n"
		"１回に取れるマッチの本数は、１～３本です\nパスはできません\n"
		"最後にマッチを取った方が負けです\n\n";
	std::wcout << s.c_str() << std::endl;
}

void __fastcall g_match23::TMatchGame23::gdone()
{
	playerP[g_player::TPlayerStat::Com]->SetTextAttribute(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
	g_framework::TGame::gdone();
	if (turn == g_player::TPlayerStat::Com)
	{
		playerP[g_player::TPlayerStat::Com]->SetTextAttribute(FOREGROUND_INTENSITY|FOREGROUND_RED);
		std::wcout << L"コンピュータの勝ちです" << std::endl << std::endl;
		playerP[g_player::TPlayerStat::Com]->win();
	}
	else
	{
		playerP[g_player::TPlayerStat::Com]->SetTextAttribute(FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		std::wcout << L"貴様の勝ちです" << std::endl << std::endl;
		playerP[g_player::TPlayerStat::Man]->win();
	}
	playerP[g_player::TPlayerStat::Com]->SetTextAttribute(FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
}






