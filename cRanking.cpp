#include "cRanking.h"

wxBEGIN_EVENT_TABLE(cRanking, wxFrame)
	EVT_BUTTON(10001, novaFase)
wxEND_EVENT_TABLE()

cRanking::cRanking() : wxFrame(nullptr, wxID_ANY, "wxLetroca - Ranking", wxPoint(30, 30), wxSize(800, 600)) {


	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	wxSizer* sizer_titulo = new wxBoxSizer(wxVERTICAL);
	wxStaticText* ranking_text = new wxStaticText(this, wxID_ANY, "Ranking Geral:", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE);
	font = ranking_text->GetFont(); font.MakeBold().MakeLarger(); ranking_text->SetFont(font);
	sizer_titulo->Add(ranking_text, 1, wxEXPAND);
	sizer->Add(sizer_titulo, 1, wxEXPAND | wxALL, 30);

	readRankingFile();
	wxSizer* sizer_top = new wxBoxSizer(wxVERTICAL);
	sizer_top->Add(rank_list, 1, wxEXPAND);
	sizer->Add(sizer_top, 4, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

	wxSizer* sizer_btnNextGame = new wxBoxSizer(wxVERTICAL);
	btnNextGame = new wxButton(this, 10001, "Próximo level", wxPoint(10, 10), wxSize(150, 50));
	sizer_btnNextGame->Add(btnNextGame, 1, wxEXPAND);
	sizer->Add(sizer_btnNextGame, 1, wxEXPAND | wxALL, 30);

	this->SetSizerAndFit(sizer);
}

cRanking::~cRanking() {
}