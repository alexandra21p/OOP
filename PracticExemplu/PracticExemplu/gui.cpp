#include "gui.h"
#include <QWidget.h>
#include <QObject.h>
#include <QListWidget.h>

GUI::GUI(Controller *c, Participant p, QWidget *parent)
	: ctrl(c), part(p), QWidget(parent)
{
	ui.setupUi(this);

	if (p.getName() == "Presenter") {
		QWidget::setWindowTitle(QString::fromStdString("Presenter"));
		connectSignalsAndSlots();
		populatePresenterList();
	}
	else {
		QWidget::setWindowTitle(QString::fromStdString(p.getName()));
		connectSignalsAndSlots();
		populateList();
		ui.scoreLEdit->setText(QString::number(p.getScore()));
	}
	
}

GUI::~GUI() {}

void GUI::populateList() {
	ui.questList->clear();
	for (auto it : ctrl->getQuestions()) {
		QString itemInList = QString::fromStdString(std::to_string(it.getId()) + " | " + it.getText() + " | "  + std::to_string(it.getScore()) + " points");
		ui.questList->addItem(itemInList);
	}
}


void GUI::populatePresenterList() {
	ui.questList->clear();
	vector<Question> v;
	for (auto el : ctrl->getQuestions()) {
		v.push_back(el);
	}
	ctrl->sortF(v);
	for (auto it : v) {
		QString itemInList = QString::fromStdString(std::to_string(it.getId()) + " | " + it.getText() + " | " + it.getCorrAns() + " | " + std::to_string(it.getScore()) + " points");
		ui.questList->addItem(itemInList);
	}
}

void GUI::connectSignalsAndSlots() {
	QObject::connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(ui.removeBtn, SIGNAL(clicked()), this, SLOT(remove()));
	QObject::connect(ui.answerBtn, SIGNAL(clicked()), this, SLOT(answer()));
}

int GUI::getSelectedItem() {
	auto v = ui.questList->selectedItems();
	if (v.size() == 0)
		return -1;
	return ui.questList->row(v[0]);
}


void GUI::add() {
	int id = ui.idEdit->text().toInt();
	string text = ui.textEdit->text().toStdString();
	string ans = ui.answerEdit->text().toStdString();
	int score = ui.scoreLEdit->text().toInt();
	try {
		ctrl->addQ(id, text, ans, score, part);
	}
	catch (Exception &e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		ui.idEdit->clear();
		ui.textEdit->clear();
		ui.answerEdit->clear();
		ui.scoreLEdit->clear();
	}

}

void GUI::remove() {
	try {
		int ind = getSelectedItem();
		ctrl->removeQ(ctrl->getQuestions()[ind], part);
	}
	catch (Exception &e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.what()));
	}
}

void GUI::answer() {
	int ind = getSelectedItem();
	string ans = ui.answerEdit->text().toStdString();
	int res = ctrl->answerQuest(ctrl->getQuestions()[ind], part, ans);
	ui.scoreLEdit->setText(QString::number(res));
}