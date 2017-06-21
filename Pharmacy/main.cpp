#include <QApplication>

#include "pharmacywindow.h"
#include "PharmacyRepo.h"
#include "FileRepo.h"
#include "InMemoryPharmacyRepo.h"
#include "PharmacyController.h"
#include <memory>


#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //create validator
    unique_ptr <MedicineValidator> val (new MedicineValidator());

    //create repository
    //unique_ptr <PharmacyRepo> repo(new InMemoryPharmacyRepo());
    unique_ptr <PharmacyRepo> repo(new FileRepo());

    //create controller
    unique_ptr <PharmacyController> ctrl(new PharmacyController(move(repo), move(val)));
    //PharmacyController ph(repo, val);


    //PharmacyWindow w(&ph);
    PharmacyWindow w(move(ctrl));
    w.show();

    return a.exec();
}
