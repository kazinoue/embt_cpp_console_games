#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <string>

#include <iostream>
#include "uTGame.h"
#include "uMatch23.h"
#include <memory>

/*
	ゲーム＆＆オブジェクト指向プログラミング
	BORLAND TURBO C++ 平成５年６月２５日初版
	C++Builder 10.2.3(bcc64)
    https://www.embarcadero.com/jp/products/cbuilder
*/
class TNewGame: public g_framework::TGame
{
public:
	virtual Bool __fastcall gplay()
	{
		return bFalse;
	}
	__fastcall TNewGame(wchar_t* s, std::shared_ptr<g_framework::TRandomObj>& rn): TGame(s, rn){}
	__fastcall ~TNewGame(){}
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::shared_ptr<g_framework::TRandomObj> rm{std::make_shared<g_framework::TRandomObj>()};
//	int i = misc::TMisc::get_random(0,5);
//	g_player::TNewGame2 g(L"ゲーム２", rm, new g_player::TCom(rm),  new g_player::TMan(rm));

	//23 Matches ゲーム
	//２３本のマッチを交互に取り合う最後に１本残った方が負け
	//マッチは１度に１～３本取ることができる。パスはできない。
	g_match23::TMatchGame23 g(L"23本のマッチ棒　残１負け", rm,
		std::make_shared<g_match23::TCom>(rm),  std::make_shared<g_match23::TMan>(rm));
	g.exec();
	return 0;
}
