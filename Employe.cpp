#include "Employe.h"


Employe::Employe(int id, string name, int position) {
	m_id = id;
	m_name = name;
	m_position = position;
}

string Employe::getPosition() {
	return (string)"Ա��";
}

void Employe::getDuty() {
	cout << "��ɾ�����������" << endl;
}