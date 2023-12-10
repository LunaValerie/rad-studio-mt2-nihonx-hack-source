//---------------------------------------------------------------------------

#ifndef NihonH
#define NihonH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.NumberBox.hpp>
#include <Vcl.Menus.hpp>
#include <SHDocVw.hpp>
#include <Vcl.OleCtrls.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *HP;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label8;
	TProgressBar *ProgressBar1;
	TPanel *Panel3;
	TImage *Image1;
	TProgressBar *ProgressBar2;
	TProgressBar *ProgressBar3;
	TPanel *Panel6;
	TPanel *Panel5;
	TImage *Image2;
	TButton *Button2;
	TButton *Button3;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TPanel *Panel19;
	TLabel *Label9;
	TLabel *Label10;
	TCheckBox *CheckBox3;
	TTrackBar *TrackBar3;
	TGroupBox *GroupBox9;
	TPanel *Panel11;
	TCheckBox *CheckBox7;
	TNumberBox *NumberBox1;
	TPanel *Panel12;
	TCheckBox *CheckBox8;
	TNumberBox *NumberBox2;
	TPanel *Panel14;
	TCheckBox *CheckBox10;
	TNumberBox *w;
	TPanel *Panel15;
	TCheckBox *CheckBox11;
	TNumberBox *NumberBox5;
	TPanel *Panel17;
	TCheckBox *CheckBox13;
	TNumberBox *NumberBox7;
	TPanel *Panel18;
	TCheckBox *CheckBox14;
	TNumberBox *NumberBox8;
	TPanel *Panel7;
	TLabel *Label11;
	TLabel *Label12;
	TCheckBox *CheckBox2;
	TTrackBar *TrackBar2;
	TPanel *Panel8;
	TLabel *Label13;
	TLabel *Label14;
	TCheckBox *CheckBox4;
	TTrackBar *TrackBar4;
	TPanel *Panel9;
	TLabel *Label15;
	TLabel *Label16;
	TCheckBox *CheckBox5;
	TTrackBar *TrackBar5;
	TPanel *Panel10;
	TLabel *Label17;
	TLabel *Label18;
	TCheckBox *CheckBox6;
	TTrackBar *TrackBar6;
	TPanel *Panel13;
	TLabel *Label19;
	TLabel *Label20;
	TCheckBox *CheckBox9;
	TTrackBar *TrackBar7;
	TPanel *Panel16;
	TLabel *Label21;
	TLabel *Label22;
	TCheckBox *CheckBox12;
	TTrackBar *TrackBar8;
	TPanel *Panel20;
	TLabel *Label23;
	TLabel *Label24;
	TCheckBox *CheckBox15;
	TTrackBar *TrackBar9;
	TTabSheet *TabSheet2;
	TGroupBox *GroupBox1;
	TPanel *Panel21;
	TCheckBox *CheckBox16;
	TPanel *Panel23;
	TCheckBox *CheckBox18;
	TPanel *Panel24;
	TCheckBox *CheckBox19;
	TPanel *Panel25;
	TCheckBox *CheckBox20;
	TPanel *Panel26;
	TCheckBox *CheckBox21;
	TPanel *Panel27;
	TPanel *Panel28;
	TCheckBox *CheckBox22;
	TPanel *Panel29;
	TCheckBox *CheckBox23;
	TPanel *Panel30;
	TCheckBox *CheckBox24;
	TButton *Button1;
	TGroupBox *GroupBox3;
	TComboBox *ComboBox1;
	TButton *Button5;
	TGroupBox *GroupBox4;
	TComboBox *ComboBox2;
	TButton *Button6;
	TGroupBox *GroupBox5;
	TComboBox *ComboBox3;
	TButton *Button7;
	TGroupBox *GroupBox6;
	TComboBox *ComboBox4;
	TButton *Button8;
	TCheckBox *CheckBox30;
	TGroupBox *GroupBox7;
	TButton *Button9;
	TGroupBox *GroupBox8;
	TEdit *Edit1;
	TButton *Button10;
	TTabSheet *TabSheet3;
	TGroupBox *GroupBox10;
	TLabel *Label35;
	TLabel *Label36;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TCheckBox *CheckBox33;
	TTrackBar *TrackBar14;
	TTabSheet *Language;
	TGroupBox *GroupBox2;
	TPanel *Panel22;
	TCheckBox *CheckBox17;
	TNumberBox *NumberBox3;
	TPanel *Panel31;
	TCheckBox *CheckBox25;
	TNumberBox *NumberBox6;
	TButton *Button4;
	TPanel *Panel32;
	TLabel *Label25;
	TLabel *Label26;
	TCheckBox *CheckBox26;
	TTrackBar *TrackBar10;
	TPanel *Panel33;
	TLabel *Label27;
	TLabel *Label28;
	TCheckBox *CheckBox27;
	TTrackBar *TrackBar11;
	TPanel *Panel34;
	TLabel *Label29;
	TLabel *Label30;
	TCheckBox *CheckBox28;
	TTrackBar *TrackBar12;
	TPanel *Panel35;
	TLabel *Label31;
	TLabel *Label32;
	TCheckBox *CheckBox29;
	TTrackBar *TrackBar13;
	TListBox *ListBox1;
	TPanel *Panel36;
	TPanel *Panel37;
	TButton *Button11;
	TEdit *Edit2;
	TCheckBox *CheckBox31;
	TPopupMenu *Banned;
	TMenuItem *ExitCheat1;
	TMenuItem *PlayerBanned1;
	TTimer *te;
	TGroupBox *GroupBox11;
	TLabel *Label33;
	TLabel *Label34;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TCheckBox *CheckBox32;
	TTrackBar *TrackBar15;
	TSearchBox *SearchBox1;
	TGroupBox *GroupBox12;
	TLabel *Label37;
	TLabel *Label38;
	TRadioButton *RadioButton5;
	TRadioButton *RadioButton6;
	TCheckBox *CheckBox34;
	TTrackBar *TrackBar16;
	TGroupBox *GroupBox13;
	TLabel *Label39;
	TLabel *Label40;
	TRadioButton *RadioButton7;
	TRadioButton *RadioButton8;
	TCheckBox *CheckBox35;
	TTrackBar *TrackBar17;
	TButton *Button12;
	TComboBox *ComboBox5;
	TLabel *Label6;
	TPanel *Panel38;
	TCheckBox *CheckBox36;
	TCheckBox *CheckBox37;
	TCheckBox *CheckBox38;
	TPanel *Panel4;
	TCheckBox *CheckBox1;
	TTrackBar *TrackBar1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall teTimer(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
