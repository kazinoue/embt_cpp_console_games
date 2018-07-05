//---------------------------------------------------------------------------

#ifndef uMatch23H
#define uMatch23H
//---------------------------------------------------------------------------
#include "uPlayer.h"
#include <iomanip>
/*
	23 Matches ゲーム (131頁)
	２３本のマッチをコンピュータ相手と交互に取り合い最後に１つ残った方が負け
	先攻／後攻を最初に決め。先攻からマッチを取る。
	１度に取れるマッチの本数は１～３本
*/

namespace g_match23
{
	class TMatch23: public g_player::TBoard
	{
		int nRound, nMatch;
	public:
		virtual __fastcall ~TMatch23(){}
		virtual void __fastcall reset();
		virtual int __fastcall state(int n, g_player::TPlayerStat turn){return nMatch; };
		virtual void __fastcall show(std::function<void()> func);
		virtual int __fastcall choice(int &n, g_player::TPlayerStat turn);
	};

	class TNPlayer: public g_player::TPlayer
	{
    protected:
		static TMatch23 match23;
	public:
		__fastcall TNPlayer(std::shared_ptr<g_framework::TRandomObj> rn):g_player::TPlayer(rn){}
	};

	class TCom: public TNPlayer
	{
	public:
		__fastcall TCom(std::shared_ptr<g_framework::TRandomObj> rn):TNPlayer(rn){}
		virtual void __fastcall reset();
		virtual Bool __fastcall play(g_player::TPlayerStat &turn);
	};

	class TMan: public TNPlayer
	{
	public:
		__fastcall TMan(std::shared_ptr<g_framework::TRandomObj> rn):TNPlayer(rn){}
		virtual Bool __fastcall play(g_player::TPlayerStat &turn);
	};

	class TMatchGame23: public g_player::TGame2
	{
		virtual void __fastcall instruction();
		virtual void __fastcall gdone();
	public:
		__fastcall TMatchGame23(const wchar_t* s, std::shared_ptr<g_framework::TRandomObj> rn, std::shared_ptr<g_player::TPlayer> p1, std::shared_ptr<g_player::TPlayer> p2):TGame2(s,rn,p1,p2){};
		virtual __fastcall ~TMatchGame23(){};
	};

}

#endif
