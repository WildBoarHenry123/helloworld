#include "Boss.h"

Boss::Boss(int id, string name, int position) {
	m_id = id;
	m_name = name;
	m_position = position;
}

string Boss::getPosition() {
	return (string)"�ϰ�";
}

void Boss::getDuty() {
	cout << "����˾��������" << endl;
}