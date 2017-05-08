/***************************************************************
 * Name:      RenegadeMain.h
 * Purpose:   Defines Application Frame
 * Author:    Tomasz ()
 * Created:   2015-12-14
 * Copyright: Tomasz ()
 * License:
 **************************************************************/

#ifndef RENEGADEMAIN_H
#define RENEGADEMAIN_H
#include "C:\Users\TSCU01\Desktop\Projekt\gr\settings\settings.h"




//(*Headers(RenegadeFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/spinbutt.h>
#include <wx/statusbr.h>
//*)

class RenegadeFrame: public wxFrame, public Settings
{
    public:

        RenegadeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~RenegadeFrame();


    private:
        void settings (char *name, int *level);
        //(*Handlers(RenegadeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnSpinButton1Change(wxSpinEvent& event);
        void OnSpinButton1Change1(wxSpinEvent& event);
        //*)

        //(*Identifiers(RenegadeFrame)
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_SPINBUTTON1;
        static const long ID_STATICTEXT2;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(RenegadeFrame)
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxSpinButton* SpinButton1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // RENEGADEMAIN_H
