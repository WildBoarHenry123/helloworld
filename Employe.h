#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class Employe : public Worker {
public:

	 Employe(int id, string name, int position);

     string getPosition();

	 void getDuty();
};