#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {
}

cApp::~cApp() {
}

bool cApp::OnInit() {
	frameMenu = new cMain();
	frameMenu->Show();
	return true;
}