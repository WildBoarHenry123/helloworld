#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker {
public:

	virtual string getPosition() = 0;

	virtual void getDuty() = 0;

	int m_id;
	string m_name;
	int m_position;
};