#include "vcl.h"
#include "windows.h"
#include "Nihon.h"
#include "ServerSelectors.h"
#include "Screen.h"
#include <Vcl.Themes.hpp>
#include <Vcl.Styles.hpp>
#include <thread>
#include <iostream>

#include <tlhelp32.h>

#pragma hdrstop
#pragma argsused
#include <Windows.h>
#include <array>
#include <iostream>
#include <vector>
#include <synchapi.h>
#include <winnt.h>
#include "X0r.h"
// ========== bypass battleye vanguard runikac uriel xng eu8 dahi calısıyor  ========= //
BOOL Metin2Naked = FALSE;
void MainCheats()
{
	if (!Metin2Naked)
	{
		 Application->Initialize();
		 TStyleManager::TrySetStyle("Ruby Graphite");// form teması
		 //Application->CreateForm(__classid(TForm3), &Form3);// Server Select
		 Application->CreateForm(__classid(TForm2), &Form2);// Main Hacks
		 Application->Run();
		 Metin2Naked = TRUE;
	}
}

extern "C" __declspec(dllexport)
BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		if(Beep(100,100)){
			CreateThread(0, 0, MainCheats0, 0, 0);
		}
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
extern "C" __declspec(dllexport) int Platinum(int code, WPARAM wParam, LPARAM lParam) {
	return CallNextHookEx(NULL, code, wParam, lParam);
}
