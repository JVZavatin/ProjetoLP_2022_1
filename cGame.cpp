#include "cGame.h"

wxBEGIN_EVENT_TABLE(cGame, wxFrame)
    EVT_BUTTON(10003, Desistir)
    EVT_BUTTON(10004, Finalizar)
    EVT_TEXT_ENTER(10005, checkInput)
    EVT_TIMER(10010, OnUpdateDisplayedTime)
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
    wxSizer* sizer_middle_tittle = new wxBoxSizer(wxVERTICAL);
    wxSizer* sizer_middle_text = new wxBoxSizer(wxVERTICAL);

    wxStaticText* input_tittle = new wxStaticText(this, wxID_ANY, "Entrada:", wxPoint(10, 10), wxSize(50, 50), wxALIGN_CENTRE_HORIZONTAL);
    font = input_tittle->GetFont(); font.MakeBold().MakeLarger(); input_tittle->SetFont(font);
    sizer_middle_tittle->Add(input_tittle, 1, wxEXPAND);

    inputC->SetMaxLength(numeroDeLetras);
    sizer_middle_text->Add(inputC, 1, wxEXPAND);
    sizer_middle->Add(sizer_middle_tittle, 1, wxEXPAND);
    sizer_middle->Add(sizer_middle_text, 3, wxEXPAND);
    sizer->Add(sizer_middle, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    
    // TEXTO COM AS LETRAS DA FASE
    wxSizer* sizer_botton = new wxBoxSizer(wxVERTICAL);
    wxStaticText* botton_text = new wxStaticText(this, wxID_ANY, lines[0], wxPoint(10, 10), wxSize(50, 50), wxALIGN_CENTRE_HORIZONTAL);
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
    wxSizer* sizer_menu_tempo = new wxBoxSizer(wxVERTICAL);
    wxStaticText* tempo_tittle_text = new wxStaticText(this, 10010, "Tempo:", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE);
    font = tempo_tittle_text->GetFont(); font.MakeBold().MakeLarger(); tempo_tittle_text->SetFont(font);
    sizer_menu_tempo->Add(tempo_tittle_text, 1, wxEXPAND);
    font = m_timeDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_timeDisplay->SetFont(font);
    m_timer->Start();
    UpdateDisplayedTime();
    sizer_menu_tempo->Add(m_timeDisplay, 3, wxEXPAND);

        // PONTUAÇÃO
            // TITULO
    wxSizer* sizer_menu_pontos = new wxBoxSizer(wxVERTICAL);
    wxStaticText* pontos_tittle_text = new wxStaticText(this, wxID_ANY, "Pontos:", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE);
    font = pontos_tittle_text->GetFont();font.MakeBold().MakeLarger();pontos_tittle_text->SetFont(font);
    sizer_menu_pontos->Add(pontos_tittle_text, 1, wxEXPAND);
            // PONTOS
    font = pontos_text->GetFont();font.MakeBold().MakeLarger();pontos_text->SetFont(font);
    sizer_menu_pontos->Add(pontos_text, 3, wxEXPAND);

        // ADCIONA NO SIZER_MENU
    sizer_menu->Add(btnDesistir, 1, wxEXPAND);
    sizer_menu->Add(sizer_menu_tempo, 1, wxEXPAND);
    sizer_menu->Add(sizer_menu_pontos, 1, wxEXPAND);
    sizer_menu->Add(btnFinalizar, 1, wxEXPAND);

    // MAIN SIZER DO GAME
    sizer->Add(sizer_menu, 1, wxEXPAND | wxALL, 20);
    this->SetSizerAndFit(sizer);
}

cGame::~cGame() {
}


