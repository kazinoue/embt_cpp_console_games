//---------------------------------------------------------------------------

#ifndef uGameH
#define uGameH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "uMisc.h"
#include <memory>
#include <windows.h>
#include <vcl.h>


namespace g_framework
{
	struct TRandomObj
	{
		std::random_device 	f_rnd;
		std::mt19937 		f_randomize{f_rnd()};
	};
	class TGame
	{
		UnicodeString 		f_title;
		int nGame{0};
	protected:
		HANDLE              f_hStdOut;
		std::weak_ptr<g_framework::TRandomObj> f_random1;
		virtual int __fastcall menu();
		virtual void __fastcall instruction();
		void __fastcall run();
		virtual void __fastcall ginit();
		virtual Bool __fastcall gplay() = 0;
		virtual void __fastcall gdone();
	public:
		__fastcall TGame(const wchar_t* s, std::shared_ptr<g_framework::TRandomObj>& l_random);
		virtual __fastcall ~TGame(){}
		void __fastcall exec();
	};

}
#endif
