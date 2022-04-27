#include "cLevelComplete.h"
#include "cGame.h"

wxBEGIN_EVENT_TABLE(cLevelComplete, wxFrame)
	EVT_BUTTON(10001, NovaFase)
wxEND_EVENT_TABLE()

cLevelComplete::cLevelComplete() : wxFrame(nullptr, wxID_ANY, "wxLetroca - Fase concluída!", wxPoint(30, 30), wxSize(800, 600)) {
	btnNextGame = new wxButton(this, 10001, "Próximo level", wxPoint(10, 10), wxSize(150, 50));
}

cLevelComplete::~cLevelComplete() {
}


void cLevelComplete::NovaFase(wxCommandEvent& evt) {
	cGame* game = new cGame();
	Destroy();
	game->Show();
	evt.Skip();
}