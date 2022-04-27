#pragma once
#include "wx/wx.h"
#include <string>
#include <vector>

using namespace std;

class cLevelComplete : public wxFrame {
public:

	wxFont font;

	cLevelComplete();
	~cLevelComplete();

	string numeroFase = "";
	wxButton* btnNextGame = nullptr;

	void NovaFase(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};