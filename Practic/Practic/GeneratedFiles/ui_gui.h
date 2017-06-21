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
	QWidget *verticalLayoutWidget;
	QVBoxLayout *verticalLayout;
	QLabel *label;
	QListWidget *filesWidget;
	QGridLayout *gridLayout;
	QLabel *nameLabel;
	QPushButton *addBtn;
	QLineEdit *lnameLineEdit;
	QPushButton *reviseBtn;
	QLineEdit *nrFilesEdit;
	QPushButton *removeBtn;
	QLabel *nrFilesLabel;

	void setupUi(QWidget *GUIClass)
	{
		if (GUIClass->objectName().isEmpty())
			GUIClass->setObjectName(QStringLiteral("GUIClass"));
		GUIClass->resize(600, 400);
		verticalLayoutWidget = new QWidget(GUIClass);
		verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
		verticalLayoutWidget->setGeometry(QRect(10, 10, 582, 388));
		verticalLayout = new QVBoxLayout(verticalLayoutWidget);
		verticalLayout->setSpacing(6);
		verticalLayout->setContentsMargins(11, 11, 11, 11);
		verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
		verticalLayout->setContentsMargins(0, 0, 0, 0);
		label = new QLabel(verticalLayoutWidget);
		label->setObjectName(QStringLiteral("label"));
		label->setMinimumSize(QSize(580, 20));
		label->setMaximumSize(QSize(580, 20));

		verticalLayout->addWidget(label);

		filesWidget = new QListWidget(verticalLayoutWidget);
		filesWidget->setObjectName(QStringLiteral("filesWidget"));
		filesWidget->setMinimumSize(QSize(580, 250));
		filesWidget->setMaximumSize(QSize(580, 250));

		verticalLayout->addWidget(filesWidget);

		gridLayout = new QGridLayout();
		gridLayout->setSpacing(6);
		gridLayout->setObjectName(QStringLiteral("gridLayout"));
		nameLabel = new QLabel(verticalLayoutWidget);
		nameLabel->setObjectName(QStringLiteral("nameLabel"));
		nameLabel->setMinimumSize(QSize(50, 30));
		nameLabel->setMaximumSize(QSize(50, 30));

		gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

		addBtn = new QPushButton(verticalLayoutWidget);
		addBtn->setObjectName(QStringLiteral("addBtn"));
		addBtn->setMinimumSize(QSize(100, 30));
		addBtn->setMaximumSize(QSize(100, 30));

		gridLayout->addWidget(addBtn, 0, 2, 1, 1);

		lnameLineEdit = new QLineEdit(verticalLayoutWidget);
		lnameLineEdit->setObjectName(QStringLiteral("lnameLineEdit"));
		lnameLineEdit->setMinimumSize(QSize(250, 20));
		lnameLineEdit->setMaximumSize(QSize(250, 20));

		gridLayout->addWidget(lnameLineEdit, 0, 1, 1, 1);

		reviseBtn = new QPushButton(verticalLayoutWidget);
		reviseBtn->setObjectName(QStringLiteral("reviseBtn"));
		reviseBtn->setMinimumSize(QSize(250, 25));
		reviseBtn->setMaximumSize(QSize(250, 25));

		gridLayout->addWidget(reviseBtn, 2, 1, 1, 1);

		nrFilesEdit = new QLineEdit(verticalLayoutWidget);
		nrFilesEdit->setObjectName(QStringLiteral("nrFilesEdit"));
		nrFilesEdit->setMinimumSize(QSize(250, 20));
		nrFilesEdit->setMaximumSize(QSize(250, 20));

		gridLayout->addWidget(nrFilesEdit, 1, 1, 1, 1);

		removeBtn = new QPushButton(verticalLayoutWidget);
		removeBtn->setObjectName(QStringLiteral("removeBtn"));
		removeBtn->setMinimumSize(QSize(100, 30));
		removeBtn->setMaximumSize(QSize(100, 30));

		gridLayout->addWidget(removeBtn, 1, 2, 1, 1);

		nrFilesLabel = new QLabel(verticalLayoutWidget);
		nrFilesLabel->setObjectName(QStringLiteral("nrFilesLabel"));
		nrFilesLabel->setMinimumSize(QSize(60, 30));
		nrFilesLabel->setMaximumSize(QSize(50, 30));

		gridLayout->addWidget(nrFilesLabel, 1, 0, 1, 1);


		verticalLayout->addLayout(gridLayout);


		retranslateUi(GUIClass);

		QMetaObject::connectSlotsByName(GUIClass);
	} // setupUi

	void retranslateUi(QWidget *GUIClass)
	{
		GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", 0));
		label->setText(QApplication::translate("GUIClass", "SOURCE CODE FILES", 0));
		nameLabel->setText(QApplication::translate("GUIClass", "Name", 0));
		addBtn->setText(QApplication::translate("GUIClass", "Add", 0));
		reviseBtn->setText(QApplication::translate("GUIClass", "REVISE", 0));
		removeBtn->setText(QApplication::translate("GUIClass", "Remove", 0));
		nrFilesLabel->setText(QApplication::translate("GUIClass", "No. of files", 0));
	} // retranslateUi

};

namespace Ui {
	class GUIClass : public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE


#endif // UI_GUI_H
