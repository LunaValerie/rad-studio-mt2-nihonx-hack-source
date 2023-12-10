#define CREATE_THREAD_ACCESS (PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_RE
#define INFO_BUFFER_SIZE 32767
#include <vector>
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Nihon.h"
#include "Minimap.h"
#include <direct.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <Wininet.h>
#include <string>
#pragma comment(lib, "wininet.lib")
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

uintptr_t Ez_game_base = (uintptr_t)GetModuleHandleA(NULL);
namespace Ez_memory
{
	uintptr_t Adres(uintptr_t pointer, std::vector<unsigned int>adres)
	{
		uintptr_t adres_c = pointer;
		for (unsigned int i = 0; i < adres.size(); ++i)
		{
			adres_c = *(uintptr_t*)adres_c;
			adres_c += adres[i];
		}
		return adres_c;
	}
}

string replaceAll(string subject, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

string DownloadString(string URL) {
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			string p = replaceAll(rtn, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(interwebs);
	string p = replaceAll(rtn, "|n", "\r\n");
	return p;
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// Pro Damage

 DWORD WINAPI ProDamage(HMODULE hModule)
 {
 while(true)
 {
   if(ServerSelect == 3)// Elym2
   {
	if (Form2->CheckBox11->Checked == true)
	{
	  DWORD vid = (*(DWORD*)(*(DWORD*)Games->Elym2->GetTargetVIDMov + Games->Elym2->GetTargetVID_VID));
	  DWORD CallAdress = Games->Elym2->SendBattlePacketCall;
	  DWORD a = *(DWORD*)Games->Elym2->SendBattlePacketMov;
	  _asm {
		mov ecx, a
		push vid
		push 0
		Call CallAdress
	  }
	  Sleep(Form2->NumberBox5->Value);
	  }
	}
   }
 }

 // Auto pickup
 DWORD WINAPI Autopickup(HMODULE hModule)
 {
 while(true)
 {
   //Application->ShowMainForm = false;
   if(ServerSelect == 3) // Elym2
   {
	 if (Form2->CheckBox10->Checked == true)
	 {
	   DWORD CallAdress = Games->Elym2->PickCloseItemCall;
	   _asm{
		 mov ecx, DWORD ptr ds : [0x015D3414]
		 Call CallAdress
	   }
	   Sleep(Form2->w->Value);
	 }
   }
  }
 }


 // Key_Board_Hook INPUT
 DWORD WINAPI KeyBoard_Hooks(HMODULE hModule)
 {
 while(true)
 {
  // Slot 1
   if(Form2->CheckBox16->Checked == true)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot1)) = 128;
   }
	if(Form2->CheckBox16->Checked == false)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot1)) = 0;
   }
   // Slot 2
   if(Form2->CheckBox18->Checked == true)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot2)) = 128;
   }
	if(Form2->CheckBox18->Checked == false)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot2)) = 0;
   }
   // Slot 3
   if(Form2->CheckBox19->Checked == true)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot3)) = 128;
   }
	if(Form2->CheckBox19->Checked == false)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot3)) = 0;
   }
   // Slot 4
   if(Form2->CheckBox20->Checked == true)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 128;
   }
	if(Form2->CheckBox20->Checked == false)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 0;
   }
   // F1
	if(Form2->CheckBox21->Checked == true)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 128;
   }
	if(Form2->CheckBox21->Checked == false)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 0;
   }
   // F2
	if(Form2->CheckBox22->Checked == true)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 128;
   }
	if(Form2->CheckBox22->Checked == false)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 0;
   }
   // F3
	if(Form2->CheckBox23->Checked == true)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 128;
   }
	if(Form2->CheckBox23->Checked == false)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 0;
   }
   // F4
	if(Form2->CheckBox24->Checked == true)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 128;
   }
	if(Form2->CheckBox24->Checked == false)
   {
	  *(DWORD*)(((DWORD)GetModuleHandleA("DINPUT8.dll") + Games->Elym2->KeyBoard_Slot4)) = 0;
   }
 }
 }

 DWORD WINAPI WaitHack(HMODULE hModule)
 {
	 while(true)
	 {
		 -- kaldırıldı !
	 }
 }

  DWORD WINAPI SkillHack(HMODULE hModule)
  {
	 while(true){//ent_SkillHack
	   if(Form2->CheckBox30->Checked == true)
	   {
		  if(Form2->ComboBox4->Text == "All Character")
		  {
			if(ServerSelect == 3) // Elym2
			{
			  *(long*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_SkillHack }) = dwLocalPlayer.SkillCheat;
			}
		  }
	   }
	 }
  }

	DWORD WINAPI LevelChanger(HMODULE hModule)
	{
		while(true)
		{
		  if(ServerSelect == 3) // Elym2
		  {
			 if(Form2->ComboBox5->Text == "50")
			 {
			 *(int*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_lvl }) = StrToInt(0);
			 }
			 if(Form2->ComboBox5->Text == "100")
			 {
			 *(int*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_lvl }) = StrToInt(10);
			 }
			 if(Form2->ComboBox5->Text == "200")
			 {
			 *(int*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_lvl }) = StrToInt(20);
			 }
		  }
		}
	}

	DWORD WINAPI NameChanger(HMODULE hModule)
	{
		while(true)
		{
			if(ServerSelect == 3)// Elym2
			{
			  *(String*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_name) = UnicodeString("s");//Form2->Edit1->Text
			}
		}
	}

	DWORD WINAPI ChatColors(HMODULE hModule)
	{
		while(true)
		{
			if(ServerSelect == 3) // Elym2
			{
			  if(Form2->ComboBox2->Text == "Purple")
			  {
			   *(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_Chat, { Games->Elym2->ent_Pruple }) = StrToInt(0);
			  }
			  if(Form2->ComboBox2->Text == "Yellow")
			  {
			   *(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_Chat, { Games->Elym2->ent_Yellow }) = StrToInt(0);
			  }
			  if(Form2->ComboBox2->Text == "White")
			  {
			   *(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_Chat, { Games->Elym2->ent_White }) = StrToInt(0);
			  }
			  if(Form2->ComboBox2->Text == "Red")
			  {
			   *(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_Chat, { Games->Elym2->ent_White }) = StrToInt(0);
			  }
			}
		}
	}

	DWORD WINAPI WeaponType(HMODULE hModule)
	{
		while(true)
		{
		  if(ServerSelect == 3) // Elym2
		  {
			if(Form2->ComboBox3->Text == "Punch")
			{
			   *(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr,Games->Elym2->ent_weapon }) = StrToInt(1);
			}
			if(Form2->ComboBox3->Text == "Sword")
			{
			   *(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr,Games->Elym2->ent_weapon }) = StrToInt(2);
			}
			if(Form2->ComboBox3->Text == "Ninja")
			{
			   *(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr,Games->Elym2->ent_weapon }) = StrToInt(4);
			}
		  }
		}
	}



void __fastcall TForm2::FormCreate(TObject *Sender)
{
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Player_Settings, 0, 0, 0);
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ProDamage, 0, 0, 0);
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Autopickup, 0, 0, 0);
  // Wait Hack
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)WaitHack, 0, 0, 0);
  // Mount Hack
  ComboBox1->Items->Add("Saman");
  ComboBox1->Items->Add("Ninja");
  ComboBox1->Items->Add("Fighter");
  ComboBox1->Items->Add("Sura");
  // Chat Settings
  ComboBox2->Items->Add("Purple");
  ComboBox2->Items->Add("Yellow");
  ComboBox2->Items->Add("White");
  ComboBox2->Items->Add("Red");
  // Skill Hack
  ComboBox4->Items->Add("All Character");
  // Weapon Type
  ComboBox3->Items->Add("Punch");
  ComboBox3->Items->Add("Sword");
  ComboBox3->Items->Add("Ninja");
  // Lvl Changer
  ComboBox5->Items->Add("50");
  ComboBox5->Items->Add("100");
  ComboBox5->Items->Add("200");
  // Title Changer Bro XD
  ServerSelect = 3;
}
//---------------------------------------------------------------------------


void RealityMemory()
{
 if(ServerSelect == 3)// Elym2
 {
   try
   {
	// Attack Speed
	if(Form2->CheckBox3->Checked == true)
	{
	*(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_AttackSpeed }) = StrToInt(Form2->TrackBar3->Position);
	}
	// Movement Speed
	if(Form2->CheckBox2->Checked == true)
	{
	*(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_MovementSpeed }) = StrToInt(Form2->TrackBar2->Position);
	}
	// Sword Range
	if(Form2->CheckBox4->Checked == true)
	{
	*(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_SwordRange }) = StrToInt(Form2->TrackBar4->Position);
	}
	// Collission
	if(Form2->CheckBox7->Checked == true)
	{
	*(int*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_Collision }) = Form2->NumberBox1->Value;
	}
	// Quick Age
	if(Form2->CheckBox8->Checked == true)
	{
	*(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_QuickAge }) = Form2->NumberBox2->Value;
	}
	// Skill Speed
	if(Form2->CheckBox14->Checked == true)
	{
	*(float*)Ez_memory::Adres(Ez_game_base + Games->Elym2->ent_localplayer, { Games->Elym2->ent_addr, Games->Elym2->ent_SkillSpeed }) = Form2->NumberBox8->Value;
	}
	// Infınıte Zoom
	if(Form2->CheckBox5->Checked == true)
	{
	*(float*)(((DWORD)GetModuleHandleA(NULL) + Games->Elym2->local_InfınıteZoom)) = StrToFloat(Form2->TrackBar5->Position);
	}
	// Game Speed
	if(Form2->CheckBox6->Checked == true)
	{
	*(float*)(((DWORD)GetModuleHandleA(NULL) + Games->Elym2->local_GameSpeed)) = 500;
	}
   }catch(...){}
 }
}


void Character_Image()
{
 // character pic
 int m_iWarGirl = 4;// 1 yap
 if(m_iWarGirl == dwLocalPlayer.WType)
 {
	Form2->Image1->Picture->Bitmap->LoadFromFile("C:/Resources/warrior_m.bmp");
	Form2->Label8->Caption = UnicodeString("War");
 }
 int m_iSamanGirl = 3;// 1 yap
 if(m_iSamanGirl == dwLocalPlayer.WType)
 {
	Form2->Image1->Picture->Bitmap->LoadFromFile("C:/Resources/chaman_m.bmp");
	Form2->Label8->Caption = UnicodeString("Shaman");
 }
 int m_iNinjaGirl = 1;// 1 yap
 if(m_iNinjaGirl == dwLocalPlayer.WType)
 {
	Form2->Image1->Picture->Bitmap->LoadFromFile("C:/Resources/ninja_m.bmp");
	Form2->Label8->Caption = UnicodeString("Ninja");
 }
 int m_iSuraGirl = 6;// 1 yap
 if(m_iSuraGirl == dwLocalPlayer.WType)
 {
	Form2->Image1->Picture->Bitmap->LoadFromFile("C:/Resources/sura_m.bmp");
	Form2->Label8->Caption = UnicodeString("Sura");
 }
}

//---------------------------------------------------------------------------


 DWORD WINAPI DedectorSysteam(HMODULE hModule)
 {
	 while(true)
	 {
	    -- kaldırıldı !
	  }
	 }
 }

//---------------------------------------------------------------------------
 DWORD WINAPI CharacterNameState(HMODULE hModule)
	{
	while(true)
	{
	 -- kaldırıldı !
	  }
	  Sleep(1900);
	}
 }

//---------------------------------------------------------------------------
DWORD WINAPI PlayerExit(HMODULE hModule)
{
	while(true)
	{
	   String ExitCheatDedect = UnicodeString(Form2->ListBox1->Items->Text);
	   if(Form2->ListBox1->Items->Text == "Ezgi-")
	   {
	   exit(-1);
	   }
	}
}

//---------------------------------------------------------------------------

DWORD WINAPI LegitEnemy(HMODULE hModule)
	{
	while(true)
	{
	  for (int i = 0; i < 231; i+=4){
		 float Distance_Dedector = (MesafeHesapla(Entity[i].x,Entity[i].y,dwLocalPlayer.x,dwLocalPlayer.y));
		 if (Distance_Dedector < StrToFloat(Form2->TrackBar1->Position))
		 {
			-- kaldırıldı !
		 }
	  }
	   Sleep(Form2->TrackBar15->Position);
	}
 }
 DWORD WINAPI LegitStone(HMODULE hModule)
	{
	while(true)
	{
	  for (int i = 0; i < 231; i+=4){
		 float Distance_Dedector = (MesafeHesapla(Entity[i].x,Entity[i].y,dwLocalPlayer.x,dwLocalPlayer.y));
		 if (Distance_Dedector < StrToFloat(Form2->TrackBar1->Position))
		 {
			-- kaldırıldı ! - farmbot

		 }
	  }
	   Sleep(Form2->TrackBar15->Position);
	}
 }


//---------------------------------------------------------------------------
void __fastcall TForm2::teTimer(TObject *Sender)
{
MobCiz(dwLocalPlayer.x,dwLocalPlayer.y);
for (int i = 0; i < 231; i++){
 float Distance_Dedector = (MesafeHesapla(Entity[i].x,Entity[i].y,dwLocalPlayer.x,dwLocalPlayer.y));
 {
 if (Distance_Dedector < StrToFloat(Form2->TrackBar1->Position))   // StrToFloat(Form2->TrackBar1->Position)
 {
	// Player Ciz
	if(Entity[i].tip==6)
	{
	 if(Form2->CheckBox36->Checked == true)
	 {
	   PlayerCiz(Entity[i].x,Entity[i].y);
	 }
	}
	// NPC Ciz
	if(Entity[i].tip==1)
	{
	   NpcCiz(Entity[i].x,Entity[i].y);
	}
	// Enemy Ciz
	if(Entity[i].tip==0)
	{
	  if(Form2->CheckBox37->Checked == true)
	  {
		 EnemyCiz(Entity[i].x,Entity[i].y);
	  }
	  if(Form2->CheckBox13->Checked == true)
	  {
	  // New Mobber Hack
	  if(ServerSelect == 3) // Elym2
	  {
	  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_entitylist) + i) + Games->Elym2->ent_x) = StrToFloat(dwLocalPlayer.x);
	  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_entitylist) + i) + Games->Elym2->ent_y) = StrToFloat(dwLocalPlayer.y);
	  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_entitylist) + i) + Games->Elym2->ent_z) = StrToFloat(dwLocalPlayer.z);
	  }
	  }
	}
	// Metin Ciz
	if(Entity[i].tip==2)
	{
	  if(Form2->CheckBox38->Checked == true)
	  {
	   MetinCiz(Entity[i].x,Entity[i].y);
	  }
	}
	// Portal Ciz
	if(Entity[i].tip == 3)
	{
		PortalCiz(Entity[i].x,Entity[i].y);
	}
 }
 }
 }
 RealityMemory();
 Character_Image();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
if(ServerSelect == 3)// Elym2
{
  if(Form2->ComboBox1->Text == "Saman")
  {
	*(Byte*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_mount) = StrToInt(7);
  }
  if(Form2->ComboBox1->Text == "Ninja")
  {
	*(Byte*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_mount) = StrToInt(4);//
  }
   if(Form2->ComboBox1->Text == "Fighter")
  {
	*(Byte*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_mount) = StrToInt(3);//
  }
   if(Form2->ComboBox1->Text == "Sura")
  {
	*(Byte*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_mount) = StrToInt(2);//
  }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ChatColors, 0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)WeaponType, 0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SkillHack, 0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LevelChanger, 0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button10Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)NameChanger, 0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)KeyBoard_Hooks, 0, 0, 0);
}
//---------------------------------------------------------------------------

DWORD WINAPI TeleportKill(HMODULE hModule)
	{
	while(true)
	{
	  for (int i = 0; i < 231; i++){
		 float Distance_Dedector = (MesafeHesapla(Entity[i].x,Entity[i].y,dwLocalPlayer.x,dwLocalPlayer.y));
		 if (Distance_Dedector < StrToFloat(Form2->TrackBar1->Position))
		 {
			if(Form2->CheckBox33->Checked == true)
			{
			   if(Form2->RadioButton1->Checked == true)
			   {
				   if(Entity[i].tip==0)// Enemy
				   {
					if(Form2->CheckBox33->Checked == true)
					{
					if(ServerSelect == 3) // Elym2
					{
					  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_x) = StrToFloat(Entity[i].x);
					  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_y) = StrToFloat(Entity[i].y);
					  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_z) = StrToFloat(Entity[i].z);
					}
					}
				  }
			   }
			   if(Form2->RadioButton2->Checked == true)
			   {
				   if(Entity[i].tip==2)// Stone
				   {
					if(Form2->CheckBox33->Checked == true)
					{
					 if(ServerSelect == 3) // Elym2
					 {
					  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_x) = StrToFloat(Entity[i].x);
					  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_y) = StrToFloat(Entity[i].y);
					  *(float*)(*(DWORD*)(*(DWORD*)((DWORD)GetModuleHandleA(NULL) + Games->Elym2->ent_localplayer) + Games->Elym2->ent_addr) + Games->Elym2->ent_z) = StrToFloat(Entity[i].z);
					 }
					}
				  }
			   }
			}
		 }
	  }
	  Sleep(Form2->TrackBar14->Position);
	}
 }



void __fastcall TForm2::Button11Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CharacterNameState, 0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DedectorSysteam, 0, 0, 0);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button12Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)TeleportKill, 0, 0, 0);
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LegitEnemy, 0, 0, 0);  //LegitEnemy
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LegitStone, 0, 0, 0);
}
//---------------------------------------------------------------------------



