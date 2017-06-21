/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H


#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
	QVBoxLayout *verticalLayout_2;
	QVBoxLayout *verticalLayout;
	QLabel *questLabel;
	QListWidget *questList;
	QGridLayout *gridLayout;
	QLabel *textLabel;
	QLabel *idLabel;
	QLineEdit *textEdit;
	QLineEdit *idEdit;
	QPushButton *removeBtn;
	QLineEdit *answerEdit;
	QPushButton *addBtn;
	QPushButton *answerBtn;
	QLabel *answerLabel;
	QLineEdit *scoreLEdit;
	QLabel *totalScoreLabel;

	void setupUi(QWidget *GUIClass)
	{
		if (GUIClass->objectName().isEmpty())
			GUIClass->setObjectName(QStringLiteral("GUIClass"));
		GUIClass->resize(600, 400);
		GUIClass->setMinimumSize(QSize(0, 0));
		verticalLayout_2 = new QVBoxLayout(GUIClass);
		verticalLayout_2->setSpacing(6);
		verticalLayout_2->setContentsMargins(11, 11, 11, 11);
		verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
		verticalLayout_2->setContentsMargins(-1, 9, -1, -1);
		verticalLayout = new QVBoxLayout();
		verticalLayout->setSpacing(6);
		verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
		verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
		verticalLayout->setContentsMargins(0, 0, 0, 3);
		questLabel = new QLabel(GUIClass);
		questLabel->setObjectName(QStringLiteral("questLabel"));
		questLabel->setMaximumSize(QSize(200, 20));

		verticalLayout->addWidget(questLabel);

		questList = new QListWidget(GUIClass);
		questList->setObjectName(QStringLiteral("questList"));
		questList->setMaximumSize(QSize(600, 200));

		verticalLayout->addWidget(questList);

		gridLayout = new QGridLayout();
		gridLayout->setSpacing(6);
		gridLayout->setObjectName(QStringLiteral("gridLayout"));
		textLabel = new QLabel(GUIClass);
		textLabel->setObjectName(QStringLiteral("textLabel"));
		textLabel->setMaximumSize(QSize(50, 16777215));

		gridLayout->addWidget(textLabel, 2, 0, 1, 1);

		idLabel = new QLabel(GUIClass);
		idLabel->setObjectName(QStringLiteral("idLabel"));
		idLabel->setMaximumSize(QSize(50, 16777215));

		gridLayout->addWidget(idLabel, 0, 0, 1, 1);

		textEdit = new QLineEdit(GUIClass);
		textEdit->setObjectName(QStringLiteral("textEdit"));
		textEdit->setMaximumSize(QSize(300, 16777215));

		gridLayout->addWidget(textEdit, 2, 2, 1, 1);

		idEdit = new QLineEdit(GUIClass);
		idEdit->setObjectName(QStringLiteral("idEdit"));
		idEdit->setEnabled(true);
		QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(idEdit->sizePolicy().hasHeightForWidth());
		idEdit->setSizePolicy(sizePolicy);
		idEdit->setMaximumSize(QSize(300, 16777215));

		gridLayout->addWidget(idEdit, 0, 2, 1, 1);

		removeBtn = new QPushButton(GUIClass);
		removeBtn->setObjectName(QStringLiteral("removeBtn"));

		gridLayout->addWidget(removeBtn, 2, 6, 1, 1);

		answerEdit = new QLineEdit(GUIClass);
		answerEdit->setObjectName(QStringLiteral("answerEdit"));
		answerEdit->setMaximumSize(QSize(300, 16777215));

		gridLayout->addWidget(answerEdit, 3, 2, 1, 1);

		addBtn = new QPushButton(GUIClass);
		addBtn->setObjectName(QStringLiteral("addBtn"));

		gridLayout->addWidget(addBtn, 0, 6, 1, 1);

		answerBtn = new QPushButton(GUIClass);
		answerBtn->setObjectName(QStringLiteral("answerBtn"));

		gridLayout->addWidget(answerBtn, 3, 6, 1, 1);

		answerLabel = new QLabel(GUIClass);
		answerLabel->setObjectName(QStringLiteral("answerLabel"));
		answerLabel->setMaximumSize(QSize(50, 16777215));

		gridLayout->addWidget(answerLabel, 3, 0, 1, 1);

		scoreLEdit = new QLineEdit(GUIClass);
		scoreLEdit->setObjectName(QStringLiteral("scoreLEdit"));
		scoreLEdit->setMaximumSize(QSize(300, 16777215));

		gridLayout->addWidget(scoreLEdit, 13, 2, 1, 1);

		totalScoreLabel = new QLabel(GUIClass);
		totalScoreLabel->setObjectName(QStringLiteral("totalScoreLabel"));
		totalScoreLabel->setMaximumSize(QSize(100, 16777215));

		gridLayout->addWidget(totalScoreLabel, 13, 0, 1, 1);


		verticalLayout->addLayout(gridLayout);


		verticalLayout_2->addLayout(verticalLayout);


		retranslateUi(GUIClass);

		QMetaObject::connectSlotsByName(GUIClass);
	} // setupUi

	void retranslateUi(QWidget *GUIClass)
	{
		GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", 0));
		questLabel->setText(QApplication::translate("GUIClass", "QUESTIONS", 0));
		textLabel->setText(QApplication::translate("GUIClass", "Text", 0));
		idLabel->setText(QApplication::translate("GUIClass", "ID", 0));
		removeBtn->setText(QApplication::translate("GUIClass", "Remove", 0));
		addBtn->setText(QApplication::translate("GUIClass", "Add", 0));
		answerBtn->setText(QApplication::translate("GUIClass", "Answer", 0));
		answerLabel->setText(QApplication::translate("GUIClass", "Answer", 0));
		totalScoreLabel->setText(QApplication::translate("GUIClass", "Score", 0));
	} // retranslateUi

};

namespace Ui {
	class GUIClass : public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
