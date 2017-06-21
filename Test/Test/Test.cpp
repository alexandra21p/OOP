// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UI.h"
#include <iostream>
using namespace std;


int main()
{
	Repository repo;
	Controller ctrl(repo);

	ctrl.add_gene("yqgE", "E_Coli_K12", "ATGAATTTACAGCAT");
	ctrl.add_gene("ppiA", "M_tuberculosis", "TTTTCATCACCGTCGG");
	ctrl.add_gene("Col2a1", "Mouse", "TTAAAGCATGGCTCTGTG");
	ctrl.add_gene("yqgE", "E_Coli_ETEC", "GTGACAGCGCCCTTCTTTCCAGG");
	ctrl.add_gene("hokC", "E_Coli_K12", "TTAATGAAGCATAAGCTTGATTTC");

	UI ui(ctrl);
	ui.run();
    return 0;
}

