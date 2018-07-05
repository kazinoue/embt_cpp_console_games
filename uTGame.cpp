//---------------------------------------------------------------------------

#pragma hdrstop

#include "uTGame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
g_player::TCnBoard g_player::TCnPlayer::board_;

int __fastcall g_player::TCnBoard::choice(int &n, g_player::TPlayerStat turn)
{
	data -= n;
    return data;
}

//ボードのリセットコンピュータ側プレーヤーが行う
void __fastcall g_player::TCom::reset()
{
	g_player::TCnPlayer::reset();
	board_.reset();
}

//コンピュータ側プレーヤーこのゲームでは常に1を選択
Bool __fastcall g_player::TCom::play(TPlayerStat& turn)
{
	int* pscore = &score;
	board_.show([&pscore]()
	{
		std::wcout << L"Com:score=" << (*pscore)++ << std::endl;
	});

	turn = Man;
	int n = 1;
	return (board_.choice(n, turn) <= 0)? bFalse: bTrue;
}

//人側
Bool __fastcall g_player::TMan::play(TPlayerStat& turn)
{
	int* pscore = &score;
	board_.show([&pscore](){
		std::wcout << L"Man:score=" << (*pscore)++ << std::endl;
	});
	turn = Com;
	int n = 1;
	return (board_.choice(n, turn) <= 0)? bFalse: bTrue;
}






