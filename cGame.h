#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "wx/wx.h"
#include <wx/datetime.h>

using namespace std;

class cGame : public wxFrame {
public:
        // VARS
    string level = "level_1A.txt";
    vector<string> lines, linesCrip;
    bool gameIsOver = false;
    int numeroDeLetras, pontos = 0;
        // WXWIDG
    wxFont font;
    wxListBox * result_list = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(200, 330), 0, nullptr, wxLB_SINGLE | wxLB_ALWAYS_SB | wxLB_SORT);
    wxTextCtrl* inputC = new wxTextCtrl(this, 10005, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxALIGN_CENTRE_HORIZONTAL);
    wxStaticText* m_timeDisplay = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE);
    //wxStopWatch* tempo = new wxStopWatch();
        // TIMER
    wxTimer* m_timer = new wxTimer;
    wxDateTime* m_startTime = new wxDateTime;

    wxStopWatch sw;


    void readLevelFile() {
        // LE O ARQUIVO DA FASE E COLOCA EM UM VECTOR DE STRING

        string filename("levels/");
        filename = filename + level;

        string line = "", lineCrip = "*           ";

        ifstream input_file(filename);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filename << "'" << endl;
        }
        int aux = 0;
        while (getline(input_file, line)) {
            // ENQUANTO TIVER ALGO NO ARQUIVO, PUSHBACK()

            lines.push_back(line);
            if (aux == 1) {
                for (int i = 0; i < line.length(); i++) {
                    lineCrip[i] = '*';
                }
                result_list->AppendString(lineCrip);
                linesCrip.push_back(lineCrip);
            }

            aux = 1;
            line = "";
        }
        numeroDeLetras = lines[0].length();
        input_file.close();

    };

    void checkInput(wxCommandEvent& evt) {

        for (int i = 1; i < lines.size(); i++) {
            // PERCORRE AS PALAVRAS DO VECTOR
            if (inputC->GetValue().compare(lines[i]) == 0) {
                pontos++;
                linesCrip.erase(linesCrip.begin() + i-1);
                linesCrip.push_back(lines[i]);
                lines.erase(lines.begin() + i);

                atualizaLista();
            }
        }
    }

    void atualizaLista() {
        // ATUALIZA O DISPLAY LISTA
        result_list->Clear();

        for (int i = 0; i < linesCrip.size(); i++) {
            result_list->AppendString(linesCrip[i]);
        }
    }

    void Finalizar(wxCommandEvent& evt) {
        // � PRA FINALIZAR O JOGO E MOSTRAR OUTRA TELA
        cGame* game = new cGame();
        Destroy();
        game->Show();
        evt.Skip();
    }

    void Desistir(wxCommandEvent& evt) {
        // � PRA FINALIZAR O JOGO E MOSTRAR OUTRA TELA
        Destroy();

    }
    

    // FUNCOES DO TIMER

    void OnStartTimer(wxTimerEvent& evt)
    {
        m_startTime->Now() = wxDateTime::Now();
        m_timer->Start(1000); // every second
        UpdateDisplayedTime(); // update immediatelly do not wait a second
    }

    void OnStopTimer(wxTimerEvent& evt)
    {
        m_timer->Stop();
        UpdateDisplayedTime();
    }

    void OnUpdateDisplayedTime(wxTimerEvent& evt)
    {
        UpdateDisplayedTime();
    }

    void UpdateDisplayedTime()
    {
        if (m_timer->IsRunning())
        {
            const wxTimeSpan ellapsedTime = wxDateTime::Now() - m_startTime->Now();

            m_timeDisplay->SetLabel(ellapsedTime.Format("%D:%H:%M:%S"));
        }
        else
        {
            m_timeDisplay->SetLabel("  <Not Timing>  ");
        }
    }
    
    // CONSTRUTOR E DESTRUTOR
    cGame();
    ~cGame();

    // BOTOES DO MENU
    wxButton* btnDesistir = nullptr;
    wxButton* btnFinalizar = nullptr;


    // DE CLARA��O DOS EVENTOS
    wxDECLARE_EVENT_TABLE();
};

