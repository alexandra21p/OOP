#include "gui.h"
#include <QWidget.h>
#include <QObject.h>
#include <QListWidget.h>

GUI::GUI(Controller* c, Programmer p, QWidget *parent)
	: ctrl(c), prog(p), QWidget(parent)
{
	ui.setupUi(this);
	QWidget::setWindowTitle(QString::fromStdString(p.getName()));
	connectSignalsAndSlots();
	populateList();
	ui.nrFilesEdit->setText(QString::number(prog.getNrFiles()));
}

GUI::~GUI() {}

void GUI::populateList() {
	ui.filesWidget->clear();
	for (auto it : ctrl->getSourceFiles()) {
		if (it.getReviewer() == "null") {
			QString st = QString::fromStdString(it.getName() + " | " + it.getStatus() + " | CREATED BY: " + it.getCreator());
			ui.filesWidget->addItem(st);

		}
		else
		{
			QString st = QString::fromStdString(it.getName() + " | " + it.getStatus() + " | CREATED BY: " + it.getCreator() + " | REVIEWED BY: " + it.getReviewer());
			ui.filesWidget->addItem(st);
		}
	}
}


void GUI::connectSignalsAndSlots() {
	QObject::connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(ui.removeBtn, SIGNAL(clicked()), this, SLOT(remove()));
	QObject::connect(ui.reviseBtn, SIGNAL(clicked()), this, SLOT(revise()));
}

int GUI::getSelectedItem() {
	auto v = ui.filesWidget->selectedItems();
	if (v.size() == 0)
		return -1;
	return ui.filesWidget->row(v[0]);
}

void GUI::add() {
	string name = ui.lnameLineEdit->text().toStdString();
	try {
		SourceCodeFile f{name,"not_revised", prog.getName(), "null"};
		ctrl->add_file(f);
	}
	catch (Exception &ex) {
		QMessageBox msg;
		msg.critical(0, "ERROR", QString::fromStdString(ex.what()));
	}

}


void GUI::remove() {
	int ind = getSelectedItem();
	ctrl->removeFile(ctrl->getSourceFiles()[ind]);
}

void GUI::revise() {
	try {
		//ui.filesWidget->clear();
		int ind = getSelectedItem();
		int res = ctrl->updateFile(ctrl->getSourceFiles()[ind], prog);
		ui.nrFilesEdit->setText(QString::number(res));
		populateList();
	}
	catch (Exception &ex) {
		QMessageBox msg;
		msg.critical(0, "ERROR", QString::fromStdString(ex.what()));
	}
}