#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QWidget>
#include <QObject>
#include <QMessageBox>
#include "ui_gui.h"
#include "Observer.h"
#include "Controller.h"
#include "Programmer.h"

class GUI : public QWidget, public Observer
{
	Q_OBJECT

public:
	GUI(Controller* c, Programmer p, QWidget *parent = 0);
	void update() {
		populateList();
	}
	~GUI();

public slots:
	void add();
	void remove();
	void revise();


private:
	Ui::GUIClass ui;
	Controller* ctrl;
	Programmer prog;

	void populateList();
	void connectSignalsAndSlots();
	int getSelectedItem();
};

#endif // GUI_H
