/*
 * Medicine.cpp
 *
 *  Created on: 16 Apr 2015
 *      Author: Alexandra
 */


#include "Medicine.h"

using namespace std;

Medicine::Medicine() {
	id = -1;
	name = "";
	activ_subst = "";
	quantity = 0;
}
Medicine::Medicine(int i, string n, string s, int q) {
	id = i;
	name = n;
	activ_subst = s;
	quantity = q;
}

