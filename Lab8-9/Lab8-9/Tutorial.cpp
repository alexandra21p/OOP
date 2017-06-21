#include "stdafx.h"
#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>


Tutorial::Tutorial() : title(""), presenter(""), duration(Duration()), likes(0), link("") {}

Tutorial::Tutorial(std::string t, std::string p, Duration d, double li, std::string lk) : title(t), presenter(p), duration(d), likes(li), link(lk) {}

/*
Tutorial::Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const double& likes, const std::string& link) {
this->title = title;
this->presenter = presenter;
this->duration = duration;
this->likes = likes;
this->link = link;
}
*/
Tutorial::~Tutorial() {}


void Tutorial::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}