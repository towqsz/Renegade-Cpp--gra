/***************************************************************
 * Name:      RenegadeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Tomasz ()
 * Created:   2015-12-14
 * Copyright: Tomasz ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "RenegadeApp.h"

//(*AppHeaders
#include "RenegadeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(RenegadeApp);

bool RenegadeApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	RenegadeFrame* Frame = new RenegadeFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
