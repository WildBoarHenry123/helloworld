#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class Boss : public Worker {
public:

	Boss(int id, string name, int position);

	string getPosition();

	void getDuty();
};