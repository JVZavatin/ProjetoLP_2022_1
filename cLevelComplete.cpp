#include "cLevelComplete.h"

wxBEGIN_EVENT_TABLE(cLevelComplete, wxFrame)
wxEND_EVENT_TABLE()

cLevelComplete::cLevelComplete() : wxFrame(nullptr, wxID_ANY, "wxLetroca - Fase concluída!", wxPoint(30, 30), wxSize(800, 600)) {
}

cLevelComplete::~cLevelComplete() {
}