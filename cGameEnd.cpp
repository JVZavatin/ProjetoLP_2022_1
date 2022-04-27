#include "cGameEnd.h"
#include "cMain.h"

wxBEGIN_EVENT_TABLE(cGameEnd, wxFrame)
	EVT_BUTTON(10001, VoltarMenu)
wxEND_EVENT_TABLE()

cGameEnd::cGameEnd() : wxFrame(nullptr, wxID_ANY, "wxLetroca - Fim de Jogo!", wxPoint(30, 30), wxSize(800, 600)) {
	btnMenu = new wxButton(this, 10001, "VOLTAR PARA O MENU", wxPoint(10, 10), wxSize(150, 50));
}

cGameEnd::~cGameEnd() {
}

void cGameEnd::VoltarMenu(wxCommandEvent& evt) {
	cMain* menu = new cMain();
	Destroy();
	menu->Show();
	evt.Skip();
}