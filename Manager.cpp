#include "Manager.h"


Manager::Manager(int id, string name, int position) {
	m_id = id;
	m_name = name;
	m_position = position;
}

string Manager::getPosition() {
	return (string)"����";
}

void Manager::getDuty() {
	cout << "����ϰ彻�������񣬲��·���Ա��" << endl;
}