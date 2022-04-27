#include "cLevelComplete.h"
#include "cGame.h"

wxBEGIN_EVENT_TABLE(cLevelComplete, wxFrame)
	EVT_BUTTON(10001, NovaFase)
wxEND_EVENT_TABLE()

cLevelComplete::cLevelComplete() : wxFrame(nullptr, wxID_ANY, "wxLetroca - Fase concluída!", wxPoint(30, 30), wxSize(800, 600)) {

	// SIZER PRINCIPAL	
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	wxSizer* sizer_titulo = new wxBoxSizer(wxVERTICAL);
	wxStaticText* parabens_text = new wxStaticText(this, wxID_ANY, "Parabéns", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE);
	font = parabens_text->GetFont(); font.MakeBold().MakeLarger(); parabens_text->SetFont(font);
	sizer_titulo->Add(parabens_text, 1, wxEXPAND);
	sizer->Add(sizer_titulo, 2, wxEXPAND | wxALL, 30);

	wxSizer* sizer_btnNextGame = new wxBoxSizer(wxVERTICAL);
	btnNextGame = new wxButton(this, 10001, "Próximo level", wxPoint(10, 10), wxSize(150, 50));
	sizer_btnNextGame->Add(btnNextGame, 1, wxEXPAND);
	sizer->Add(sizer_btnNextGame, 1, wxEXPAND | wxALL, 30);

	wxSizer* sizer_btnRanking = new wxBoxSizer(wxVERTICAL);
	btnRanking = new wxButton(this, 10002, "Ranking Geral", wxPoint(10, 10), wxSize(150, 50));
	sizer_btnRanking->Add(btnRanking, 1, wxEXPAND);
	sizer->Add(sizer_btnRanking, 1, wxEXPAND | wxALL, 30);

	this->SetSizerAndFit(sizer);
}

cLevelComplete::~cLevelComplete() {
}

void cLevelComplete::NovaFase(wxCommandEvent& evt) {
	cGame* newGame = new cGame();
	char valor = readActualLevelFile();
	zeraLevelAtual();
	writeLevelFile(valor);
	Destroy();
	newGame->Show();
	evt.Skip();
}