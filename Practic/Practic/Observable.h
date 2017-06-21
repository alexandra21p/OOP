#pragma once
#include "Observer.h"
#include <vector>

class Observable {
private:
	std::vector<Observer*> obs;

public:
	Observable();
	~Observable();
	void attach(Observer* o) {
		obs.push_back(o);
	}
	void notify() {
		for (auto it : obs)
			it->update();
	}
};

