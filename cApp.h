#pragma once
#include "wx/wx.h"
#include "cMain.h"
#include "cGame.h"

class cApp : public wxApp {
public:
	cApp();
	~cApp();
	virtual bool OnInit();

private:
	cMain* frameMenu = nullptr;
};