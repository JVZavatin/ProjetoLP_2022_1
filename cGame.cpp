#include "cGame.h"

wxBEGIN_EVENT_TABLE(cGame, wxFrame)
    EVT_BUTTON(10003, Finalizar)
    EVT_BUTTON(10004, Finalizar)
    EVT_TEXT_ENTER(10005, checkInput)

wxEND_EVENT_TABLE()

cGame::cGame() : wxFrame(nullptr, wxID_ANY, "wxLetroca - Jogando", wxPoint(30, 30), wxSize(800, 600)) {
    wxPanel* panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, 100));
    panel_top->SetBackgroundColour(wxColor(100, 100, 200));

    wxPanel* panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, 100));
    panel_bottom->SetBackgroundColour(wxColor(100, 200, 100));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(panel_top, 3, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);

    wxSizer* sizer_middle = new wxBoxSizer(wxVERTICAL);
    wxTextCtrl* control = new wxTextCtrl(this, wxID_ANY);
    control->SetMaxLength(8);
    sizer_middle->Add(control, 1, wxEXPAND);
    sizer->Add(sizer_middle, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    


    sizer->Add(panel_bottom, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxSizer* sizer_menu = new wxBoxSizer(wxHORIZONTAL);
    btnFinalizar = new wxButton(this, 10003, "RANKING", wxPoint(500, 10), wxSize(150, 50));
    btnFinalizar2 = new wxButton(this, 10004, "RANKING", wxPoint(500, 10), wxSize(150, 50));
    sizer_menu->Add(btnFinalizar, 1, wxEXPAND);
    sizer_menu->Add(btnFinalizar2, 1, wxEXPAND);

    sizer->Add(sizer_menu, 1, wxEXPAND | wxALL, 10);

    this->SetSizerAndFit(sizer);
}

cGame::~cGame() {
}



void cGame::Finalizar(wxCommandEvent& evt) {
    cGame* game = new cGame();
    Destroy();
    game->Show();
    evt.Skip();
}
