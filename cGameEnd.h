#pragma once
#include "wx/wx.h"

class cGameEnd : public wxFrame {
public:
	cGameEnd();
	~cGameEnd();

	wxButton* btnMenu = nullptr;

	void VoltarMenu(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};