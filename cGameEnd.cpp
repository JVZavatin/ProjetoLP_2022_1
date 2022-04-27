#include "cGameEnd.h"

wxBEGIN_EVENT_TABLE(cGameEnd, wxFrame)
wxEND_EVENT_TABLE()

cGameEnd::cGameEnd() : wxFrame(nullptr, wxID_ANY, "wxLetroca - Fim de Jogo!", wxPoint(30, 30), wxSize(800, 600)) {
}

cGameEnd::~cGameEnd() {
}