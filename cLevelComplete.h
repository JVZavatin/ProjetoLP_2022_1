#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "wx/wx.h"
#include <wx/datetime.h>

using namespace std;

class cLevelComplete : public wxFrame {
public:

	wxFont font;

	cLevelComplete();
	~cLevelComplete();

	string filenameFase = "levels/fase.txt";
    string line = "";
	char filenameNumero;

	wxButton* btnNextGame = nullptr;

    void zeraLevelAtual() {
        FILE* f = fopen("levels/fase.txt", "w");
        fclose(f);
    }

    char readActualLevelFile() {
        // LE O ARQUIVO DA FASE PARA SELECIONAR

        ifstream input_file(filenameFase);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filenameFase << "'" << endl;
        }
        while (getline(input_file, line)) {
            // ENQUANTO TIVER ALGO NO ARQUIVO

            filenameNumero = line[0];
            filenameNumero++;

            line = "";
        }
        input_file.close();
        return filenameNumero;
    };

    void writeLevelFile(char valor) { 
        // ESCREVE NO ARQUIVO
        ofstream input_file(filenameFase);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << filenameFase << "'" << endl;
        }
        else {
            input_file << valor;
        }
    }

	void NovaFase(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};