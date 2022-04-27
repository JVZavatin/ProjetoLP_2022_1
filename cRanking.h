#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "wx/wx.h"
#include <wx/datetime.h>
#include "cLevelComplete.h"
#include "cGameEnd.h"
#include "cGame.h"

using namespace std;

class cRanking : public wxFrame {
public:
        // VARS
    vector<string> lines, linesCrip;
    int numeroDeLetras, pontos = 0;
    string line = "";
        // LISTA DO RANK
    wxFont font;
    wxListBox* rank_list = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(200, 330), 0, nullptr, wxLB_SINGLE | wxLB_ALWAYS_SB | wxLB_SORT);

    void readRankingFile() {
        // LE O ARQUIVO DO RANK E COLOCA EM UM VECTOR DE STRING
        rank_list->Clear();
        string filename = "ranking/ranking.txt";

        ifstream input_file(filename);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filename << "'" << endl;
        }
        while (getline(input_file, line)) {
            // ENQUANTO TIVER ALGO NO ARQUIVO, PUSHBACK()

            lines.push_back(line);
            rank_list->AppendString(line);

            line = "";
        }
        numeroDeLetras = lines[0].length();
        input_file.close();

    };

    void writeRankingFile(string rank) {
        // ESCREVE NO ARQUIVO
        string filename = "ranking/ranking.txt";
        ofstream input_file(filename);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filename << "'" << endl;
        }
        else {
            input_file << rank << "\n";
        }
    }

    void novaFase(wxCommandEvent& evt) {
        cGame* game = new cGame();
        game->zeraRankAtual();
        Destroy();
        game->Show();
        evt.Skip();
    }

    wxButton* btnNextGame = nullptr;

	cRanking();
	~cRanking();

    wxDECLARE_EVENT_TABLE();
};