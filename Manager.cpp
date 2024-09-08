#include "Manager.h"


Manager::Manager(int id, string name, int position) {
	m_id = id;
	m_name = name;
	m_position = position;
}

string Manager::getPosition() {
	return (string)"经理";
}

void Manager::getDuty() {
	cout << "完成老板交给的任务，并下发给员工" << endl;
}