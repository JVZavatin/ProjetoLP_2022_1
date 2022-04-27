#include "cMain.h"
#include "cGame.h"
#include "cRanking.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, NovoJogo)
	EVT_BUTTON(10002, MostrarRanking)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "wxLetroca", wxPoint(30, 30), wxSize(800, 600)) {
	// MAIN SIZER
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* sizer_btnNewGame = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* sizer_btnRanking = new wxBoxSizer(wxVERTICAL);

	btnNewGame = new wxButton(this, 10001, "NOVA PARTIDA", wxPoint(10, 10), wxSize(150, 50));
	btnRanking = new wxButton(this, 10002, "RANKING", wxPoint(500, 10), wxSize(150, 50));

	sizer_btnNewGame->Add(btnNewGame, 1, wxEXPAND);
	sizer_btnRanking->Add(btnRanking, 1, wxEXPAND);

	sizer->Add(sizer_btnNewGame, 1, wxEXPAND | wxALL, 40);
	sizer->Add(sizer_btnRanking, 1, wxEXPAND | wxALL, 40);

	this->SetSizerAndFit(sizer);
}

cMain::~cMain() {
}

void cMain::NovoJogo(wxCommandEvent& evt) {
	cGame* game = new cGame();
	Destroy();
	game->Show();
	evt.Skip();
}

void cMain::MostrarRanking(wxCommandEvent& evt) {
	cRanking* ranking = new cRanking();
	Destroy();
	ranking->Show();
	evt.Skip();
}