#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "wx/wx.h"
#include <wx/datetime.h>
#include "cLevelComplete.h"
#include "cGameEnd.h"

using namespace std;

class cGame : public wxFrame {
public:
        // VARS
    string levelNumber = "level_";
    string filename = "levels/level";
    string filenameFase = "levels/fase.txt";
    string filenameNumero = "1";
    int countLinhas = 0, countAcertos = 0;

    vector<string> lines, ranks, linesCrip;
    int numeroDeLetras, pontos = 0;
        // WXWIDG
    wxFont font;
    wxListBox * result_list = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(200, 330), 0, nullptr, wxLB_SINGLE | wxLB_ALWAYS_SB | wxLB_SORT);
    wxTextCtrl* inputC = new wxTextCtrl(this, 10005, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxALIGN_CENTRE_HORIZONTAL);
    wxStaticText* m_timeDisplay = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE);
    wxStaticText* pontos_text = new wxStaticText(this, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE | wxBORDER_SIMPLE);
    //wxStopWatch* tempo = new wxStopWatch();
        // TIMER
    wxTimer* m_timer = new wxTimer;
    wxDateTime* m_startTime = new wxDateTime;

    void readActualLevelFile() {
        // LE O ARQUIVO DA FASE PARA SELECIONAR
        string line = "";

        ifstream input_file(filenameFase);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filenameFase << "'" << endl;
        }
        while (getline(input_file, line)) {
            // ENQUANTO TIVER ALGO NO ARQUIVO

            filenameNumero = line;

            line = "";
        }
        input_file.close();

    };


    void readLevelFile() {
        // LE O ARQUIVO DA FASE E COLOCA EM UM VECTOR DE STRING
        srand(time(0));
        char variation = 'a' + rand() % 3;
        filename = filename + filenameNumero + "/" + levelNumber + variation + ".txt";

        string line = "", lineCrip = "*           ";

        ifstream input_file(filename);
        if (!input_file.is_open()) {
            montaRankGeral();
            zeraRankAtual();
            zeraLevelAtual();

            // � PRA FINALIZAR O JOGO E MOSTRAR OUTRA TELA
            cGameEnd* gameEnd = new cGameEnd();
            Destroy();
            gameEnd->Show();
            cerr << "Could not open the file - '" << filename << "'" << endl;
        }
        int aux = 0;
        while (getline(input_file, line)) {
            countLinhas++;
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
                atualizaPontos();
                countAcertos++;
            }
        }
    }

    void atualizaPontos() {
        pontos_text->SetLabel(to_string(pontos));
    }

    void atualizaLista() {
        // ATUALIZA O DISPLAY LISTA
        result_list->Clear();

        for (int i = 0; i < linesCrip.size(); i++) {
            result_list->AppendString(linesCrip[i]);
        }
    }

    void readRankingFile() {
        // LE O ARQUIVO DO RANK E COLOCA EM UM VECTOR DE STRING
        string filenameRA = "ranking/ranking.txt";
        string rank;

        ifstream input_file(filenameRA);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filenameRA << "'" << endl;
        }
        while (getline(input_file, rank)) {
            // ENQUANTO TIVER ALGO NO ARQUIVO, PUSHBACK()

            ranks.push_back(rank);
            rank = "";
        }
        numeroDeLetras = ranks[0].length();
        input_file.close();

    };

    void montaRankAtual() {
        // ESCREVE NO ARQUIVO
        string filenameRankingAtual("ranking/rankingAtual.txt");
        ofstream output_file;
        output_file.open(filenameRankingAtual, ios_base::app);
        if (!output_file.is_open()) {
            cerr << "Could not open the file - '" << filenameRankingAtual << "'" << endl;
        }
        else {
            for (int i = 0; i < ranks.size(); i++)
                output_file << ranks[i] << "\n";
            output_file << pontos << "\n";
        }
        output_file.close();
    }

    void zeraRankAtual() {
        string filenameRankingAtual("ranking/rankingAtual.txt");
        FILE* f = fopen("ranking/rankingAtual.txt", "w");
        fclose(f);
    }

    void montaRankGeral() {
        // ESCREVE NO ARQUIVO
        string filenameRankingAtual("ranking/rankingAtual.txt");
        string filenameRankingGeral("ranking/ranking.txt");
        string line = "";
        stringstream ss;
        int total = 0;



        ifstream input_file(filenameRankingAtual);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filenameRankingAtual << "'" << endl;
        }

        while (getline(input_file, line)) {
            total += stoi(line);
        }
        input_file.close();

        ofstream output_file;
        output_file.open(filenameRankingGeral, ios_base::app);
        output_file << "Pontos: " << total << " na Fase: " << filename << "\n";
        output_file.close();
    }


    void Finalizar(wxCommandEvent& evt) {
        // � PRA FINALIZAR O JOGO E MOSTRAR OUTRA TELA

        if (countAcertos >= countLinhas / 2) {
            montaRankAtual();

            cLevelComplete* levelComplete = new cLevelComplete();
            Destroy();
            levelComplete->Show();
            evt.Skip();
        }
        else {
            wxMessageBox(wxT("Voc� precisa acertar pelo menos metade!"));
        }
    }

    void zeraLevelAtual() {
        FILE* f = fopen("levels/fase.txt", "w");
        fclose(f);

        // ESCREVE NO ARQUIVO
        string filename = "levels/fase.txt";
        ofstream input_file(filename);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filename << "'" << endl;
        }
        input_file << "1" << "\n";
    }

    void Desistir(wxCommandEvent& evt) {

        montaRankGeral();
        zeraRankAtual();
        zeraLevelAtual();

        // � PRA FINALIZAR O JOGO E MOSTRAR OUTRA TELA
        cGameEnd* gameEnd = new cGameEnd();
        Destroy();
        gameEnd->Show();
        evt.Skip();
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


    // DECLARA��O DOS EVENTOS
    wxDECLARE_EVENT_TABLE();
};

