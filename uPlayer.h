//---------------------------------------------------------------------------

#ifndef uPlayerH
#define uPlayerH
//---------------------------------------------------------------------------
#include "uGame.h"
#include <array>
#include <memory>
#include <functional>
#include <windows.h>

namespace g_player
{
	enum TPlayerStat {Com, Man};

	struct TBoard
	{
		__fastcall TBoard(){}
		virtual __fastcall ~TBoard(){}

		virtual void __fastcall reset() = 0;
		virtual void __fastcall show(std::function<void()> func) = 0;
		virtual int __fastcall state(int n, TPlayerStat turn){return n;}
		virtual Bool __fastcall is_not_sel(int n, TPlayerStat turn)
			{return bTrue; }
		virtual int __fastcall choice(int& n, TPlayerStat turn) = 0;
		virtual Bool __fastcall is_over(){return bTrue;}
		virtual void __fastcall push(){}
		virtual void __fastcall pop(){}
	};

	struct TPlayer
	{
	protected:
		int 	nWin, score;
		HANDLE  f_hStdOut;
		std::shared_ptr<g_framework::TRandomObj > f_random1;
	public:
		TPlayer(std::shared_ptr<g_framework::TRandomObj>& rn){
			nWin = 0; f_random1 = rn; }
		virtual void __fastcall win(){++nWin;}
		virtual int __fastcall get_nwin(){return nWin;}
		virtual void __fastcall reset(){score = 0;}
		virtual int __fastcall get_score(){return score;}
		virtual Bool __fastcall play(TPlayerStat& turn) = 0;
		void __fastcall SetTextAttribute(WORD wAttributes);
		void __fastcall SetStdHandle(HANDLE lhstd);
	};

	struct TGame2 : public g_framework::TGame
	{
	protected:
		TPlayerStat turn;
		std::array<std::shared_ptr<TPlayer>, 2> playerP;
		TPlayerStat __fastcall first();
		virtual void __fastcall ginit();
		virtual Bool __fastcall gplay();
		virtual void __fastcall gdone();
	public:
		__fastcall TGame2(const wchar_t* s,std::shared_ptr<g_framework::TRandomObj>& rn, std::shared_ptr<TPlayer> p1, std::shared_ptr<TPlayer> p2);
		virtual __fastcall ~TGame2();

	};
}
#endif
