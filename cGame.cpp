#include "cGame.h"

wxBEGIN_EVENT_TABLE(cGame, wxFrame)
    EVT_BUTTON(10003, Desistir)
    EVT_BUTTON(10004, Finalizar)
    EVT_TEXT_ENTER(10005, checkInput)
    EVT_TIMER(wxID_ANY, OnUpdateDisplayedTime)
wxEND_EVENT_TABLE()

cGame::cGame() : wxFrame(nullptr, wxID_ANY, "wxLetroca - Jogando", wxPoint(30, 30), wxSize(800, 600)) {

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    readLevelFile();

    // LISTA DE PALAVRAS NA FASE
    wxSizer* sizer_top = new wxBoxSizer(wxVERTICAL);
    sizer_top->Add(result_list, 1, wxEXPAND);
    sizer->Add(sizer_top, 4, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

    // CAIXA DE INPUT DE TEXTO
    wxSizer* sizer_middle = new wxBoxSizer(wxVERTICAL);
    inputC->SetMaxLength(numeroDeLetras);
    sizer_middle->Add(inputC, 1, wxEXPAND);
    sizer->Add(sizer_middle, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);
    
    // TEXTO COM AS LETRAS DA FASE
    wxSizer* sizer_botton = new wxBoxSizer(wxVERTICAL);
    wxStaticText* botton_text = new wxStaticText(this, wxID_ANY, lines[0], wxPoint(500, 10), wxSize(150, 50), wxALIGN_CENTRE_HORIZONTAL);
    font = botton_text->GetFont();
    font.MakeBold().MakeLarger();
    botton_text->SetFont(font);
    sizer_botton->Add(botton_text, 1, wxEXPAND);
    sizer->Add(sizer_botton, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

    // MENU INFERIOR
    wxSizer* sizer_menu = new wxBoxSizer(wxHORIZONTAL);
        // BOTOES
    btnDesistir = new wxButton(this, 10003, "Desistir", wxPoint(500, 10), wxSize(150, 50));
    btnFinalizar = new wxButton(this, 10004, "Finalizar", wxPoint(500, 10), wxSize(150, 50));
        // TEMPORIZADOR NAO FUNCIONA
    font = m_timeDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_timeDisplay->SetFont(font);
    m_timer->Start();
    UpdateDisplayedTime();
        // PONTUAÇÃO
    wxStaticText* pontos_text = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE);
    font = pontos_text->GetFont();
    font.MakeBold().MakeLarger();
    //pontos_text->SetLabel();
    pontos_text->SetFont(font);


        // ADCIONA NO SIZER_MENU
    sizer_menu->Add(btnDesistir, 1, wxEXPAND);
    sizer_menu->Add(m_timeDisplay, 1, wxEXPAND);
    sizer_menu->Add(pontos_text, 1, wxEXPAND);
    sizer_menu->Add(btnFinalizar, 1, wxEXPAND);

    // MAIN SIZER DO GAME
    sizer->Add(sizer_menu, 1, wxEXPAND | wxALL, 20);
    this->SetSizerAndFit(sizer);
}

cGame::~cGame() {
}


