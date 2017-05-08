/***************************************************************
 * Name:      RenegadeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Tomasz ()
 * Created:   2015-12-14
 * Copyright: Tomasz ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "RenegadeMain.h"
#include <wx/msgdlg.h>
#include <windows.h>

//#include "mainr.h"

//(*InternalHeaders(RenegadeFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)



//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(RenegadeFrame)
const long RenegadeFrame::ID_BUTTON1 = wxNewId();
const long RenegadeFrame::ID_TEXTCTRL1 = wxNewId();
const long RenegadeFrame::ID_STATICTEXT1 = wxNewId();
const long RenegadeFrame::ID_SPINBUTTON1 = wxNewId();
const long RenegadeFrame::ID_STATICTEXT2 = wxNewId();
const long RenegadeFrame::ID_MENUITEM1 = wxNewId();
const long RenegadeFrame::idMenuAbout = wxNewId();
const long RenegadeFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RenegadeFrame,wxFrame)
    //(*EventTable(RenegadeFrame)
    //*)
END_EVENT_TABLE()

RenegadeFrame::RenegadeFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(RenegadeFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(493,148));
    Button1 = new wxButton(this, ID_BUTTON1, _("Start"), wxPoint(304,72), wxSize(152,50), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Nazwa gracza"), wxPoint(16,24), wxSize(-1,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetMaxLength(20);
    TextCtrl1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    TextCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Easy"), wxPoint(352,32), wxSize(40,21), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(13,wxROMAN,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    SpinButton1 = new wxSpinButton(this, ID_SPINBUTTON1, wxPoint(400,32), wxSize(24,24), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON1"));
    SpinButton1->SetRange(0, 1);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Wybierz poziom:"), wxPoint(344,8), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RenegadeFrame::OnButton1Click1);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&RenegadeFrame::OnTextCtrl1Text);
    Connect(ID_SPINBUTTON1,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&RenegadeFrame::OnSpinButton1Change1);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RenegadeFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RenegadeFrame::OnAbout);
    //*)
}

RenegadeFrame::~RenegadeFrame()
{
    //(*Destroy(RenegadeFrame)
    //*)
}

void RenegadeFrame::settings (char *name, int *level)
{
    FILE *plik;
    int status,l;
    Lvl lvl;
    strcpy(lvl.name, name);
    lvl.level=*level;
    plik=fopen("log/settings.ini", "w+b");


        status=fwrite(&lvl, sizeof(lvl), 1, plik);


    fclose(plik);
}

void RenegadeFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void RenegadeFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to Renegade"));
}

void RenegadeFrame::OnButton1Click1(wxCommandEvent& event)
{
    char pname[20];
    int level;
    strcpy(pname, (TextCtrl1->GetValue()).mb_str(wxConvUTF8));

    level=SpinButton1->GetValue();

    settings(pname, &level);
    WinExec("Game/gr.exe",SW_SHOWNORMAL);
    Close();

}

void RenegadeFrame::OnTextCtrl1Text(wxCommandEvent& event)
{

}


void RenegadeFrame::OnSpinButton1Change1(wxSpinEvent& event)
{
    if (SpinButton1->GetValue()==1)
        StaticText1->SetLabel("Hard");
    else
        StaticText1->SetLabel("Easy");
}
