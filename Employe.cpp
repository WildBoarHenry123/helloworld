#include "Employe.h"


Employe::Employe(int id, string name, int position) {
	m_id = id;
	m_name = name;
	m_position = position;
}

string Employe::getPosition() {
	return (string)"员工";
}

void Employe::getDuty() {
	cout << "完成经理交给的任务" << endl;
}