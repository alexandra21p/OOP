#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "ui_gui.h"
#include "Controller.h"
#include "Participant.h"
#include "Observer.h"

class GUI : public QWidget, public Observer
{
	Q_OBJECT

public:
	GUI(Controller *c, Participant p, QWidget *parent = 0);
	~GUI();
	void update() {
		populateList();
	}

public slots:
	void add();
	void remove();
	void answer();

private:
	Ui::GUIClass ui;
	Controller* ctrl;
	Participant part;

	int getSelectedItem();
	void populateList();
	void populatePresenterList();
	void connectSignalsAndSlots();

};

#endif // GUI_H
