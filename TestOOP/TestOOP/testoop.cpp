#include "testoop.h"

TestOOP::TestOOP(Controller& c, QWidget *parent)
	: ctrl(c), QWidget{parent}
{
	//ui.setupUi(this);
	this->initGUI();
	this->currentCountriesInRepoList = this->ctrl.getRepo().getFruits();
	this->populateRepoList();
}

TestOOP::~TestOOP() {}

void TestOOP::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	this->repoList = new QListWidget{};
	
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	QWidget* dataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ dataWidget };
	this->nameEdit = new QLineEdit{};
	this->nutrEdit = new QLineEdit{};
	this->quantityEdit = new QLineEdit{};
	formLayout->addRow("&Name:", nameEdit);
	formLayout->addRow("&Nutrition Benefits:", nutrEdit);
	formLayout->addRow("&Quantity:", quantityEdit);


	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->sortButton = new QPushButton("Sort");
	this->filterButton = new QPushButton("Show fruits");
	this->refreshButton = new QPushButton("Refresh");


	gridLayout->addWidget(sortButton, 0, 0);
	gridLayout->addWidget(filterButton, 0, 1);
	gridLayout->addWidget(refreshButton, 0, 2);

	
	leftSide->addWidget(new QLabel{"Fruits List"});
	leftSide->addWidget(repoList);
	leftSide->addWidget(dataWidget);
	leftSide->addWidget(buttonsWidget);

	layout->addWidget(leftWidget);
	this->connectSignalsAndSlots();
}

void TestOOP::connectSignalsAndSlots()
{
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterByBenefit()));
	QObject::connect(this->sortButton, SIGNAL(clicked()), this, SLOT(sortByNutr()));
	QObject::connect(this->refreshButton, SIGNAL(clicked()), this, SLOT(refresh()));
}

void TestOOP::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Fruit> fruits = this->currentCountriesInRepoList;


	if (idx >= fruits.size())
		return;
	Fruit f = fruits[idx];
	this->nameEdit->setText(QString::fromStdString(f.getName()));
	this->nutrEdit->setText(QString::fromStdString(f.getNutr()));
	this->quantityEdit->setText(QString::number(f.getQuantity()));
}

void TestOOP::populateRepoList()
{

	if (this->repoList->count() > 0)
		this->repoList->clear();

	for (auto s : this->currentCountriesInRepoList)

	{
		QString itemInList = QString::fromStdString(s.getName() + " | " + std::to_string(s.getQuantity()));
		this->repoList->addItem(itemInList);
	}


	if (this->currentCountriesInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}
int TestOOP::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->nameEdit->clear();
		this->nutrEdit->clear();
		this->quantityEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void TestOOP::sortByNutr() {
	this->ctrl.sort();
	this->currentCountriesInRepoList = this->ctrl.getRepo().getSortedList();
	this->populateRepoList();
}

void TestOOP::filterByBenefit() {
	std::string benefit = this->nutrEdit->text().toStdString();
	double total = this->ctrl.filter(benefit);
	//this->quantityEdit->setText(QString::number(total));

	this->currentCountriesInRepoList = this->ctrl.getRepo().getFilteredList();

	this->populateRepoList();
	this->nameEdit->clear();
	this->nutrEdit->clear();
	this->quantityEdit->clear();
	this->quantityEdit->setText(QString::number(total));
}

void TestOOP::refresh() {
	this->currentCountriesInRepoList = this->ctrl.getRepo().getFruits();
	this->populateRepoList();
}