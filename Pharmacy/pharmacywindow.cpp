#include "pharmacywindow.h"
#include "ui_pharmacywindow.h"
#include <algorithm>



////used for splittling the string from the ListItem
#include <string>
#include <sstream>
#include <vector>


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


////

PharmacyWindow::PharmacyWindow(unique_ptr <PharmacyController> ctrl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PharmacyWindow)
{

    ui->setupUi(this);
    this->ctrl = std::move(ctrl);
    buildWindow();
    populateList();

}

PharmacyWindow::~PharmacyWindow()
{
    delete ui;
    //delete ctrl;
}



void PharmacyWindow::buildWindow() {

    // main layout
    mainLayout = new QHBoxLayout();

    // sub layouts
    listPart = new QVBoxLayout();
    formPart = new QGridLayout();


    // MED LIST widget initialization
    this->medLabel = new QLabel("MEDICINES: ");
    medLabel->show();
    this->medList = new QListWidget();

    // add the widgets to the subLayout
    listPart->addWidget(this->medLabel);
    listPart->addWidget(this->medList);
    //QObject::connect(medList,SIGNAL(itemSelectionChanged()),this,SLOT(selectionChanged()));
    QObject::connect(medList,SIGNAL(itemSelectionChanged()),this,SLOT(selectionChange()));

    // add the sublayout to the main layout
    mainLayout->addLayout(listPart);


    // MEDICINE FORM widget initialization

    // labels
    this->idL = new QLabel("ID:");
    this->nameL = new QLabel("Name:");
    this->substL = new QLabel("Active Substance:");
    this->quantityL = new QLabel("Quantity:");

    // line edits
    this->idLE = new QLineEdit();
    this->nameLE = new QLineEdit();
    this->substLE = new QLineEdit();
    this->quantityLE = new QLineEdit();

    // buttons
    this->bAdd = new QPushButton("Add");
    this->bDelete = new QPushButton("Delete");
    this->bUpdate = new QPushButton("Update");
    this->bUndo = new QPushButton("Undo");
    this->bFilterName = new QPushButton("Filter by Name");
    this->bFilterQuantity = new QPushButton("Filter by Quantity");
    this->bReloadList = new QPushButton("Reload List");


    // adding the widgets to the form subLayout

    // labels
    formPart->addWidget(this->idL,0,0);
    formPart->addWidget(this->nameL,1,0);
    formPart->addWidget(this->substL,2,0);
    formPart->addWidget(this->quantityL,3,0);

    // line edits
    formPart->addWidget(this->idLE,0,1,1,3);
    formPart->addWidget(this->nameLE,1,1,1,3);
    formPart->addWidget(this->substLE,2,1,1,3);
    formPart->addWidget(this->quantityLE,3,1,1,3);

    // BUTTONS

    // add them to the Form subLayout
    formPart->addWidget(this->bAdd,4,0);
    formPart->addWidget(this->bDelete,4,1);
    formPart->addWidget(this->bUpdate,4,2);
    formPart->addWidget(this->bUndo,4,3);
    formPart->addWidget(this->bFilterName,5,0,1,2);
    formPart->addWidget(this->bFilterQuantity,5,2,1,3);
    formPart->addWidget(this->bReloadList,6,0,1,4);

    // connect them to their slots
    QObject::connect(bAdd,SIGNAL(clicked()),this,SLOT(addUI()));
    QObject::connect(bDelete,SIGNAL(clicked()),this,SLOT(deleteUI()));
    QObject::connect(bUpdate,SIGNAL(clicked()),this,SLOT(updateUI()));
    QObject::connect(bUndo,SIGNAL(clicked()),this,SLOT(undoUI()));
    QObject::connect(bReloadList,SIGNAL(clicked()),this,SLOT(populateList()));
    QObject::connect(bFilterName,SIGNAL(clicked()),this,SLOT(filterNameUI()));
    QObject::connect(bFilterQuantity,SIGNAL(clicked()),this,SLOT(filterQuantityUI()));

    //add form Sublayout to main layout
    mainLayout->addLayout(formPart);


    this->centralWidget()->setLayout(mainLayout);
}



QListWidgetItem PharmacyWindow::getFirstSelected() {
    QList<QListWidgetItem*> items = medList->selectedItems();
    if(items.size() > 0)
    return *items.at(0);
    else
    {
        cout<<" Nothing selected"<<endl;
        QListWidgetItem item;
        item.setText(QString::fromStdString("EMPTY"));
        return item;
    }
}


void PharmacyWindow::selectionChange() {
    QList<QListWidgetItem*> l = medList->selectedItems();
    if(l.size()==0)
        return;
    QListWidgetItem i = *l.at(0);
    QString st = i.text();

    QStringList stv = st.split(" ");
    idLE->setText(stv[0]);
    nameLE->setText(stv[1]);
    substLE->setText(stv[2]);
    quantityLE->setText(stv[3]);

}

void PharmacyWindow::populateList() {
    vector<Medicine> all = ctrl->getAllMeds();

    medList->clear();

    for_each(all.begin(), all.end(), [&](Medicine& one){
        QString representation = QString::number(one.getId()) + " " + QString::fromStdString(one.getName()) + " "
                + QString::fromStdString(one.getSubst()) + " " + QString::number(one.getQuantity());
        return new QListWidgetItem(representation, this->medList);
    });
}


void PharmacyWindow::addUI() {
    int id = idLE->text().toInt();
    string name = nameLE->text().toStdString();
    string activ_subst = substLE->text().toStdString();
    int quantity = quantityLE->text().toInt();

    /*
     * QString sId = idLE->text();
    QString sName = nameLE->text();
    QString sSubst = substLE->text();
    QString sQuant = quantityLE->text();

    int id = sId.toInt();
    string name = sName.toStdString();
    string activ_subst = sSubst.toStdString();
    int quantity = sQuant.toInt();
    */


    try {
        ctrl->add_medicine(id, name, activ_subst, quantity);

        // to clear the text from the lineEdits
        idLE->text()="";
        nameLE->text()="";
        substLE->text()="";
        quantityLE->text()="";
        populateList();

    } catch(PharmacyException &ex) {
        QMessageBox::critical(this,"Error",QString::fromStdString(ex.getMsg()));
    }

}



void PharmacyWindow::deleteUI() {

    QString sId = idLE->text();
    int id = sId.toInt();

    try {
        ctrl->delete_medicine(id);

        populateList();

    } catch(PharmacyException &ex){
        QMessageBox::critical(this,"Error",QString::fromStdString(ex.getMsg()));
    }

}



void PharmacyWindow::updateUI(){

    QString sId = idLE->text();
    QString sName = nameLE->text();
    QString sSubst = substLE->text();
    QString sQuant = quantityLE->text();

    int id = sId.toInt();
    string name = sName.toStdString();
    string activ_subst = sSubst.toStdString();
    int quantity = sQuant.toInt();

    try {
        ctrl->modify_medicine(id, name, activ_subst, quantity);
        populateList();

        // to clear the text from the lineEdits
        idLE->text()="";
        nameLE->text()="";
        substLE->text()="";
        quantityLE->text()="";


    } catch(PharmacyException &ex) {
        QMessageBox::critical(this,"Error",QString::fromStdString(ex.getMsg()));
    }


}


void PharmacyWindow::undoUI() {
    try {
        ctrl->undoController();
        populateList();
    } catch(PharmacyException &ex) {
        QMessageBox::critical(this,"Error",QString::fromStdString(ex.getMsg()));
    }

}




void PharmacyWindow::filterNameUI() {


    QString sname = nameLE->text();
    string name = sname.toStdString();
    vector<Medicine> rez = ctrl->filterByName(name);


    medList->clear();

    for_each(rez.begin(), rez.end(), [&](Medicine& one){
        QString representation = QString::number(one.getId()) + " " + QString::fromStdString(one.getName()) + " "
                + QString::fromStdString(one.getSubst()) + " " + QString::number(one.getQuantity());
        return new QListWidgetItem(representation, this->medList);
    });

}




void PharmacyWindow::filterQuantityUI() {


    QString squant = quantityLE->text();
    int quantity = squant.toInt();
    vector<Medicine> rez = ctrl->filterByQuantity(quantity);


    medList->clear();

    for_each(rez.begin(), rez.end(), [&](Medicine& one){
        QString representation = QString::number(one.getId()) + " " + QString::fromStdString(one.getName()) + " "
                + QString::fromStdString(one.getSubst()) + " " + QString::number(one.getQuantity());
        return new QListWidgetItem(representation, this->medList);
    });

}






/*
 * void PharmacyWindow::selectionChanged() {

    QListWidgetItem s = getFirstSelected();

    QString s_string = s.text();

    string med = s_string.toStdString();
    if(med != "EMPTY"){



    std::vector<std::string> x = split(med, ' ');

      cout<<"Selected medicine with ID = "<<x[0];

    idLE->setText(QString::fromStdString(x[0]));
    nameLE->setText(QString::fromStdString(x[1]));
    substLE->setText(QString::fromStdString(x[2]));
    quantityLE->setText(QString::fromStdString(x[3]));
    }

    else
    {
        idLE->setText(QString::fromStdString(""));
        nameLE->setText(QString::fromStdString(""));
        substLE->setText(QString::fromStdString(""));
        quantityLE->setText(QString::fromStdString(""));
    }

}
*/


