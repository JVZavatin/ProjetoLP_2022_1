#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "wx/wx.h"

using namespace std;

class cGame : public wxFrame {
public:
    string input = "NULL";
    string level = "level_1A.txt";
    vector<string> lines;
    bool gameIsOver = false;
    int numeroDeLetras;


    void readLevelFile() {
        // LE O ARQUIVO DA FASE E COLOCA EM UM VECTOR DE STRING

        string filename("levels/");
        filename = filename + level;

        string line;

        ifstream input_file(filename);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filename << "'" << endl;
        }

        while (getline(input_file, line)) {
            // ENQUANTO TIVER ALGO NO ARQUIVO, PUSHBACK()
            lines.push_back(line);
        }
        numeroDeLetras = lines[0].length();
        input_file.close();

    };

    void checkInput(wxCommandEvent& evt) {
        // VERIFICA A PALAVRA
        if (input != "NULL") {
            // SE O JOGO EXISTE
            for (int i = 1; i < lines.size(); i++) {
                // PERCORRE AS PALAVRAS DO VECTOR
                for (int j = 0; j < input.length(); j++) {
                    // PERCORRE AS LETRAS DA ENTRADA 
                    if (input[j] == lines[i][j]) {
                        // MOSTRA A LETRA
                        // PONTOS +1
                    }
                }
            }
        }
    }

    void Finalizar(wxCommandEvent& evt);
   
    cGame();
    ~cGame();

    wxButton* btnFinalizar = nullptr;
    wxButton* btnFinalizar2 = nullptr;

    wxVector<wxButton*> vecBtn;

    wxDECLARE_EVENT_TABLE();
};

