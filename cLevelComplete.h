#pragma once
#include "wx/wx.h"

class cLevelComplete : public wxFrame {
public:

	wxFont font;

	cLevelComplete();
	~cLevelComplete();

	wxButton* btnNextGame = nullptr;

	void NovaFase(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};