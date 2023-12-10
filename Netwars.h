int ServerSelect = 0;
struct Elym2
{
 // LocalPlayer
 DWORD ent_localplayer = 0x4036C0;
 DWORD ent_addr = 0x10;
 // Radar
 DWORD ent_tip = 0x359C;
 // Binek > mount
 DWORD ent_mount = 0x19DC;
 // Mount vector
 DWORD ent_mount_vector = 0x0033B3C0;
 DWORD ent_mount_addr = 0x8;
 DWORD ent_mount_addr2 = 0x8;
 DWORD ent_mount_y = 0x3A8;
 DWORD ent_mount_x = 0x3A4;
 DWORD ent_mount_z = 0x3AC;
 // Character - Hazır
 DWORD ent_status = 0x694;
 DWORD ent_name = 0x1C;
 DWORD ent_lvl = 0x5C;
 DWORD ent_x = 0x360C;
 DWORD ent_y = 0x3610;
 DWORD ent_z = 0x3614;
 DWORD ent_vıd = 0x370C;
 DWORD ent_weapon = 0x19DC;
 DWORD ent_QuickAge = 0x3634;
 DWORD ent_SkillSpeed = 0x19D0;
 DWORD ent_AttackSpeed = 0x3640;
 DWORD ent_MovementSpeed = 0x363C;
 DWORD ent_SwordRange = 0x3638;
 DWORD ent_Collision = 0x3714;
 DWORD ent_SkillHack = 0x34C4;
 // Skill Hack
 DWORD ent_SuikastMaster = 521416136; // Ninja
 DWORD ent_DragonAttack = 698529040; // Shaman
 DWORD ent_ParmakDarbesi = 587496280; // Sura
 DWORD ent_KılıcCevirme = 514165080; // Savascı
 // Chat Settings
 DWORD ent_Chat = 0x011D34AC;
 DWORD ent_Pruple = 0x44;
 DWORD ent_Yellow = 0x48;
 DWORD ent_White = 0x4C;
 // Farmbot
 DWORD ent_walk_farm = 0x011D3418;
 DWORD ent_walk = 0x50;
 // Entitylist
  DWORD ent_entitylist = 0x4D1FF9D8;
 // Others
 DWORD local_InfınıteZoom = 0x359DE0;
 DWORD local_GameSpeed = 0x359DC0;
 DWORD Local_MovementSpeedBypassed = 0x13A4CF;
 // Type Character
 DWORD ent_Type = 0x3598;
 // Assembly
 DWORD PickCloseItemCall = 0x007AC750;
 DWORD PickCloseItemMov = *(DWORD*)0x00B01D44;
 // Send Battle Packet Error
 DWORD SendBattlePacketCall = 0x007920B0;
 DWORD SendBattlePacketMov = 0x00AB3694;
 // GetTargetVID
 DWORD GetTargetVIDMov = 0x00B01D44;
 DWORD GetTargetVID_VID = 0x001616BC;
 // Keyboard DINPUT8 Slot
 DWORD KeyBoard_AutoAttack = 0x30290;
 DWORD KeyBoard_Slot1 = 0x3025A;
 DWORD KeyBoard_Slot2 = 0x3025B;
 DWORD KeyBoard_Slot3 = 0x3025C;
 DWORD KeyBoard_Slot4 = 0x3025D;
 // Keyboard DINPUT8 F
 DWORD KeyBoard_F1 = 0x30293;
 DWORD KeyBoard_F2 = 0x30294;
 DWORD KeyBoard_F3 = 0x30295;
 DWORD KeyBoard_F4 = 0x30296;
 __forceinline Elym2* operator->() { return this; }
};
struct Servers
{
	Elym2 Elym2;
	__forceinline Servers* operator->() { return this; }
};
inline Servers Games;
