#include <tlhelp32.h>

#include "Netwars.h"

HANDLE MEMORY = OpenProcess(PROCESS_ALL_ACCESS, 0, GetCurrentProcessId());
DWORD metin2client;
BOOL PointModule = FALSE;

struct dwLocalPlayer
{
  char name[50];
  char durum[50];
  float x;
  float y;
  float z;
  int level;
  long SkillCheat;
  int WType;
}dwLocalPlayer;

struct dwEntitylist
{
  char name[4];
  int tip;
  float x;
  float y;
  float z;
  int vid;
  int level;
  float dist;
}Entity[255];


struct Mobber
{
  float x;
  float y;
  float z;
}Mob[255];

void PortalCiz(float x,float y)
{
 try
 {
 Form2->Image2->Canvas->Brush->Color=clBlack; // orta
 Form2->Image2->Canvas->Pen->Color = clWhite; // radus
 Form2->Image2->Canvas->Brush->Style = bsSolid;
 float Gelenx=abs(x)/100;
 float Geleny=abs(y)/100;
 Form2->Image2->Canvas->Rectangle(Gelenx,Geleny,Gelenx+7,Geleny+7);

 } catch (...) {
 }
}

void MetinCiz(float x,float y)
{
 try
 {
 Form2->Image2->Canvas->Brush->Color=clAqua; // orta
 Form2->Image2->Canvas->Pen->Color = clNavy; // radus
 Form2->Image2->Canvas->Brush->Style = bsSolid;
 float Gelenx=abs(x)/100;
 float Geleny=abs(y)/100;
 Form2->Image2->Canvas->Rectangle(Gelenx,Geleny,Gelenx+7,Geleny+7);

 } catch (...) {
 }
}

void EnemyCiz(float x,float y)
{
 try
 {
 Form2->Image2->Canvas->Brush->Color=clYellow;
 Form2->Image2->Canvas->Pen->Color = clFuchsia;
 Form2->Image2->Canvas->Brush->Style=bsSolid;
 float Gelenx=abs(x)/100;
 float Geleny=abs(y)/100;
 Form2->Image2->Canvas->Rectangle(Gelenx,Geleny,Gelenx+7,Geleny+7);

 } catch (...) {
 }
}


void NpcCiz(float x,float y)
{
 try
 {
 Form2->Image2->Canvas->Brush->Color=clRed;
 Form2->Image2->Canvas->Pen->Color = clWhite;
 Form2->Image2->Canvas->Brush->Style=bsSolid;
 float Gelenx=abs(x)/100;
 float Geleny=abs(y)/100;
 Form2->Image2->Canvas->Rectangle(Gelenx,Geleny,Gelenx+7,Geleny+7);

 } catch (...) {
 }
}

void PlayerCiz(float x,float y)
{
 try
 {
 Form2->Image2->Canvas->Brush->Color=clAqua;
 Form2->Image2->Canvas->Pen->Color = clYellow;
 Form2->Image2->Canvas->Brush->Style=bsSolid;
 float Gelenx=abs(x)/100;
 float Geleny=abs(y)/100;
 Form2->Image2->Canvas->Ellipse(Gelenx,Geleny,Gelenx+5,Geleny+5);

 } catch (...) {
 }
}

float MesafeHesapla(float x, float y, float Px,float Py){return sqrt((Px-x)*(Px-x)+(Py-y)*(Py-y));}
void MobCiz(float x,float y)
{
 try
 {
 //
 Form2->Image2->Canvas->Brush->Color= clBlack;
 Form2->Image2->Canvas->FillRect(Form2->Image2->Canvas->ClipRect);

 // Image
 if(Form2->CheckBox1->Checked)
 {
  Form2->Image2->Picture->Bitmap->LoadFromFile("C:/Resources/Radar/metin2_map_a1.bmp");
 }


 Form2->Image2->Canvas->Pen->Color =  clAqua;
 Form2->Image2->Canvas->Brush->Color=clWhite;
 Form2->Image2->Canvas->Brush->Style=bsDiagCross;
 float Gelenx=abs(x)/100;
 float Geleny=abs(y)/100;
 float alan= 58; //StrToFloat(Form2->TrackBar1->Position);
 //float alan= 64;
  if (alan>0) {
	 // 2 si main player character
	 if(Form2->CheckBox1->Checked)
	 {
			Form2->Image2->Canvas->Ellipse(Gelenx-alan, Geleny-alan, Gelenx+alan+5, Geleny+alan+5);
			PlayerCiz(dwLocalPlayer.x,dwLocalPlayer.y);
	 }
  }

 float haritax=abs((Form2->Panel5->Width/2)+abs(Form2->Image2->Left));
 float haritay=abs((Form2->Panel5->Height/2)+abs(Form2->Image2->Top));
 int xfark=(Gelenx-haritax);
 int yfark=(Geleny-haritay);
 Form2->Image2->Left  -=  xfark;
 Form2->Image2->Top   -=    yfark;
 if (Form2->Image2->Left>0)
 {
	Form2->Image2->Left=0;
 }
 if (Form2->Image2->Top>0)
 {
	Form2->Image2->Top=0;
 }

 } catch (...) {
 }}



 bool ServerGlobal = false;
 DWORD WINAPI Player_Settings(HMODULE hModule)
 {
	 if (!PointModule)
	 {
		metin2client = (DWORD)GetModuleHandleA(NULL);
		PointModule = TRUE;
	 }
	 while(true)
	 {
	   if(ServerSelect == 3) // Elym2
	   {
		  ServerGlobal = true;
		  if(ServerGlobal)
		  {
			DWORD m_iName = metin2client + Games->Elym2->ent_localplayer;
			DWORD OFF1, OFF2;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + Games->Elym2->ent_addr), &OFF2, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_x), &dwLocalPlayer.x, 4, NULL);

			DWORD m_iName1 = metin2client + Games->Elym2->ent_localplayer;
			DWORD OFF3, OFF4;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName1), &OFF3, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF3 + Games->Elym2->ent_addr), &OFF4, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF4 + Games->Elym2->ent_y), &dwLocalPlayer.y, 4, NULL);

			DWORD m_iName2 = metin2client + Games->Elym2->ent_localplayer;
			DWORD OFF6, OFF7;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName1), &OFF6, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF3 + Games->Elym2->ent_addr), &OFF7, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF4 + Games->Elym2->ent_z), &dwLocalPlayer.z, 4, NULL);
		  }
		  // Name
		  if(ServerGlobal)
		  {
		   DWORD m_iName = metin2client + Games->Elym2->ent_localplayer;
		   DWORD OFF1, OFF2;
		   ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + Games->Elym2->ent_addr), &OFF2, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_name), &dwLocalPlayer.name, 4, NULL);
		   Form2->Label6->Caption = UnicodeString(dwLocalPlayer.name);
		  }
		  // Level
		  if(ServerGlobal)
		  {
		   DWORD m_iName = metin2client + Games->Elym2->ent_localplayer;
		   DWORD OFF1, OFF2;
		   ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + Games->Elym2->ent_addr), &OFF2, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_lvl), &dwLocalPlayer.level, 4, NULL);
		   Form2->Label7->Caption = StrToInt(dwLocalPlayer.level);
		   Form2->ProgressBar1->Position = StrToInt(dwLocalPlayer.level);
		  }
		  // Status
		  if(ServerGlobal)
		  {
		   DWORD m_iName = metin2client + Games->Elym2->ent_localplayer;
		   DWORD OFF1;
		   ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + Games->Elym2->ent_status), &dwLocalPlayer.durum, 4, NULL);
		   //Form2->Label8->Caption = UnicodeString(dwLocalPlayer.durum);
		  }
		  // Radar
		  if(ServerGlobal)
		  {
		  for (int i = 0; i < 231; i+=4){
			// X
			DWORD m_iName = metin2client + Games->Elym2->ent_entitylist;
			DWORD OFF1, OFF2;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + i), &OFF2, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_x), &Entity[i].x, 4, NULL);
			// Y
			DWORD m_iName1 = metin2client + Games->Elym2->ent_entitylist;
			DWORD OFF3, OFF4;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName1), &OFF3, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF3 + i), &OFF4, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF4 + Games->Elym2->ent_y), &Entity[i].y, 4, NULL);
			// Z
			DWORD m_iName2 = metin2client + Games->Elym2->ent_entitylist;
			DWORD OFF5, OFF6;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName2), &OFF5, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF5 + i), &OFF6, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF6 + Games->Elym2->ent_z), &Entity[i].z, 4, NULL);
		  }
	   }
		// tip
		if(ServerGlobal)
		{
		for (int i = 0; i < 231; i+=4){
			DWORD m_iName = metin2client + Games->Elym2->ent_entitylist;
			DWORD OFF1, OFF2;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + i), &OFF2, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_tip), &Entity[i].tip, 4, NULL);
		 }
		}
		// Character Type
		if(ServerGlobal)
		{
		 for (int i = 0; i < 231; i+=4){
			DWORD m_iName = metin2client + Games->Elym2->ent_localplayer;
			DWORD OFF1, OFF2;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + Games->Elym2->ent_addr), &OFF2, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_Type), &dwLocalPlayer.WType, 4, NULL);
		}
	   }
	   // VID
	   if(ServerGlobal)
	   {
	   for (int i = 0; i < 231; i+=4){
			DWORD m_iName = metin2client + Games->Elym2->ent_entitylist;
			DWORD OFF1, OFF2;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + i), &OFF2, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_vıd), &Entity[i].vid, 4, NULL);
		}
		// Entity_Lvl
		if(ServerGlobal)
	   {
	   for (int i = 0; i < 231; i+=4){
		   DWORD m_iName = metin2client + Games->Elym2->ent_entitylist;
		   DWORD OFF1, OFF2;
		   ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + i), &OFF2, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_lvl), &Entity[i].level, 4, NULL);
	   }
	   }
	   // Skill Hack   ent_SkillHack
	   if(ServerGlobal)
	   {
		   DWORD m_iName = metin2client + Games->Elym2->ent_localplayer;
		   DWORD OFF1, OFF2;
		   ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + Games->Elym2->ent_addr), &OFF2, 4, NULL);
		   ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_SkillHack), &dwLocalPlayer.SkillCheat, 4, NULL);
	   }
	   // Player Name Everyone
	   if(ServerGlobal)
	   {
	   for (int i = 0; i < 231; i+=4){
			DWORD m_iName = metin2client + Games->Elym2->ent_entitylist;
			DWORD OFF1, OFF2;
			ReadProcessMemory(MEMORY, (LPVOID)(m_iName), &OFF1, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF1 + i), &OFF2, 4, NULL);
			ReadProcessMemory(MEMORY, (LPVOID)(OFF2 + Games->Elym2->ent_name), &Entity[i].name, 4, NULL);
		}
	   }
	   }
	   }
	 }
 }
