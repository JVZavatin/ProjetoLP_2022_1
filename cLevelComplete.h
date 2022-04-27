#pragma once
#include "wx/wx.h"
#include <string>
#include <vector>

using namespace std;

class cLevelComplete : public wxFrame {
public:
	string numeroFase = "";

	wxFont font;

	cLevelComplete();
	~cLevelComplete();

	wxButton* btnNextGame = nullptr;
	wxButton* btnRanking = nullptr;



	void NovaFase(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};