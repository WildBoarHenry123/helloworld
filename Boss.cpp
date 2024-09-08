#include "Boss.h"

Boss::Boss(int id, string name, int position) {
	m_id = id;
	m_name = name;
	m_position = position;
}

string Boss::getPosition() {
	return (string)"老板";
}

void Boss::getDuty() {
	cout << "管理公司所有事务" << endl;
}