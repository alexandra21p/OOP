#ifndef PHARMACYWINDOW_H
#define PHARMACYWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QString>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>


#include "PharmacyController.h"

namespace Ui {
class PharmacyWindow;
}

class PharmacyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PharmacyWindow(unique_ptr <PharmacyController> ctrl, QWidget *parent = 0);
    ~PharmacyWindow();

    void buildWindow();




private slots:
    void populateList();


    void addUI();
    void deleteUI();
    void updateUI();
    void undoUI();
    void filterNameUI();
    void filterQuantityUI();

    // returns the first item selected
    QListWidgetItem getFirstSelected();

    // called when selection changed
    //void selectionChanged();
    void selectionChange();



private:
    unique_ptr <PharmacyController> ctrl;
    Ui::PharmacyWindow *ui;



    // main layout
    QHBoxLayout* mainLayout;

    // sub-layouts
    QVBoxLayout* listPart;
    QGridLayout* formPart;

    // MEDICINE LIST
    QLabel* medLabel;

    QListWidget* medList;

    // MEDICINE FORM
    QLineEdit* idLE;
    QLabel* idL;

    QLineEdit* nameLE;
    QLabel* nameL;

    QLineEdit* substLE;
    QLabel* substL;

    QLineEdit* quantityLE;
    QLabel* quantityL;

    // BUTTONS
    QPushButton* bAdd;
    QPushButton* bDelete;
    QPushButton* bUpdate;
    QPushButton* bUndo;
    QPushButton* bFilterName;
    QPushButton* bFilterQuantity;
    QPushButton* bReloadList;

};

#endif // PHARMACYWINDOW_H
