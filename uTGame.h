//---------------------------------------------------------------------------

#ifndef uTGameH
#define uTGameH
//---------------------------------------------------------------------------
#include "uPlayer.h"
#include <iostream>
#include <memory>


//ゲーム固有のゲーム盤
namespace g_player
{
	struct TCnBoard: public TBoard
	{
		int data;
	public:
		__fastcall TCnBoard(){reset(); }
		virtual __fastcall ~TCnBoard(){}
		void __fastcall reset(){data = 7;}
		virtual void __fastcall show(std::function<void()> func)
		{
			std::wcout << L"New Board : left = " << data << std::endl;
            func();
		}
		virtual int __fastcall choice(int& n, TPlayerStat turn);
	};

	//ゲーム固有のプレーヤ
	class TCnPlayer: public TPlayer
	{
	protected:
		static  TCnBoard board_;
	public:
		__fastcall TCnPlayer(std::shared_ptr<g_framework::TRandomObj> rn):TPlayer(rn){}
	};

	//コンピュータ側のプレーヤ
	class TCom: public TCnPlayer
	{
	public:
		__fastcall TCom(std::shared_ptr<g_framework::TRandomObj> rn):TCnPlayer(rn){}
		virtual void __fastcall reset();
		virtual Bool __fastcall play(TPlayerStat& turn);
	};

	//人間側プレーヤ
	class TMan: public TCnPlayer
	{
	public:
		__fastcall TMan(std::shared_ptr<g_framework::TRandomObj> rn):TCnPlayer(rn){}
		virtual Bool __fastcall play(TPlayerStat& turn);
	};

	class TNewGame2: public TGame2
	{
	public:
		TNewGame2(const wchar_t* s,std::shared_ptr<g_framework::TRandomObj> rn, std::shared_ptr<TPlayer> p1, std::shared_ptr<TPlayer> p2):TGame2(s, rn ,p1,p2){}
		virtual __fastcall ~TNewGame2(){};
	};
}
#endif
