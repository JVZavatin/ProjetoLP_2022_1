#pragma once
#include "wx/wx.h"

class cMain : public wxFrame {
public:
	cMain();
	~cMain();

	wxButton* btnNewGame = nullptr;
	wxButton* btnRanking = nullptr;

	void NovoJogo(wxCommandEvent& evt);
	void MostrarRanking(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};