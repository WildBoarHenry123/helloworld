#include "WorkManager.h"
using namespace std;

WorkManager::WorkManager() {
	 FileEmpty = true;
	 ArrayCnt = 0;
	 pArray = NULL;
	 this->InitArray();
}
WorkManager::~WorkManager() {
	if (pArray != NULL) {
		
		delete[] pArray;
		pArray = NULL;
	}
}
void WorkManager::InitArray() {
	ifstream ifs;
	ifs.open("staff.txt", ios::in);
	//1.�ļ�������
	if (!ifs.is_open())
	{
		ArrayCnt = 0;
		FileEmpty = true;
		pArray = NULL;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		ArrayCnt = 0;
		FileEmpty = true;
		pArray = NULL;
		ifs.close();
		return;
	}
	//3.�ļ�������������
	int id, position, cnt = 0;
	string name;
	while (ifs >> id && ifs >> name && ifs >> position) {
		cnt++;
	}
	ifs.clear(); // ��� EOF ��־
	ifs.seekg(0); // �����ļ���ȡλ�õ���ͷ

	pArray = new Worker * [cnt];
	
	while (ifs >> id && ifs >> name && ifs >> position) {
		switch (position) {
		case 1: pArray[ArrayCnt++] = new Employe(id, name, position); break;
		case 2: pArray[ArrayCnt++] = new Manager(id, name, position); break;
		case 3: pArray[ArrayCnt++] = new Boss(id, name, position); break;
		}
		
	}
	ArrayCnt = cnt;
	FileEmpty = false;
	ifs.close();
}

void WorkManager::save() {
	ofstream ofs;
	ofs.open("staff.txt", ios::out);
	if (!ofs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	for (int i = 0; i < ArrayCnt; i++) {
		ofs << pArray[i]->m_id;
		ofs << pArray[i]->m_name;
		ofs << pArray[i]->m_position;
	}
	cout << "�ļ��򿪳ɹ���" << endl;
	ofs.close();
}

int WorkManager::IsExist() {
	int ret = -1;
	int id;
	cin >> id;
	for (int i = 0; i < ArrayCnt; i++) {
		if (pArray[i]->m_id == id) {
			ret = i;
			break;
		}
	}
	return ret;
}
void WorkManager::Exit() {
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}
void WorkManager::AddStaff() {
	cout << "����������ְ��������" << endl;
	int num, i;
	cin >> num;
	int newsize = ArrayCnt + num;
	Worker** NewpArray = new Worker * [newsize];
	for ( i = 0; i < ArrayCnt; i++) {
		NewpArray[i] = pArray[i];
	}
	for ( i = ArrayCnt; i < newsize; i++) {
		
		cout << "�������" << i - ArrayCnt + 1 << "��Ա���ı�ţ�" << endl;
		int newid;
		cin >> newid;
		
		cout << "�������" << i-ArrayCnt+1 << "��Ա����������" << endl;
		string newname;
		cin >> newname;
		
		cout << "�������λ��" << endl;
		cout << "1.��ְͨ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		int position;
		cin >> position;
		
		switch (position) {
		case 1: NewpArray[i] = new Employe(newid, newname, position); break;
		case 2: NewpArray[i] = new Manager(newid, newname, position); break;
		case 3: NewpArray[i] = new Boss(newid, newname, position); break;
		}

	}
	cout << "�ɹ����" << num << "����ְ��" << endl;
	FileEmpty = false;
	ArrayCnt += num;
	delete [] pArray;
	pArray = NewpArray;
	this->save();
}

void WorkManager::ShowStaff() {
	if (FileEmpty) {
		cout << "�ļ���¼Ϊ��" << endl;
		//system("pause");
		return;
	}
	for (int i = 0; i < ArrayCnt; i++) {
		cout << "ְ����ţ� " << pArray[i]->m_id;
		cout << " ְ�������� " << pArray[i]->m_name;
		cout << "\t��λ��" << pArray[i]->getPosition();
		cout << "\t��λְ��";
		pArray[i]->getDuty();
		cout << endl;
	}
}

void WorkManager::DeleteStaff() {
	if (FileEmpty) {
		cout << "�ļ���¼Ϊ��" << endl;
		//system("pause");
		return;
	}
	cout << "��������Ҫɾ����ְ���ţ�" << endl;
	int index = IsExist();
	if (index == -1) {
		cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
	}
	else {
		delete pArray[index];
		for (int i = index; i < ArrayCnt - 1; i++) {
			pArray[i] = pArray[i + 1];
		}
		cout << "ɾ���ɹ���" << endl;
	}
	ArrayCnt--;
	if (ArrayCnt == 0) {
		FileEmpty = true;
	}
	this->save();
}

void WorkManager::ChangeStaff() {
	if (FileEmpty) {
		cout << "�ļ���¼Ϊ��" << endl;
		//system("pause");
		return;
	}
	cout << "�������޸�ְ���ı��: " << endl;
	int index = IsExist();
	if (index == -1) {
		cout << "δ�ҵ���Ա����" << endl;
	}
	else {
		cout << "�鵽�� " << pArray[index]->m_id << "��ְ������������ְ���ţ�" << endl;
		int newid;
		cin >> newid;
		string newname;
		cout << "��������������" << endl;
		cin >> newname;
		int position;
		cout << "�������λ��" << endl;
		cout << "1.��ְͨ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> position;
		delete pArray[index];
		switch (position) {
		case 1: pArray[index] = new Employe(newid, newname, position); break;
		case 2: pArray[index] = new Manager(newid, newname, position); break;
		case 3: pArray[index] = new Boss(newid, newname, position); break;
		}

	}
    cout << "�޸ĳɹ���" << endl;
    this->save();			
}

void WorkManager::FindStaff() {
	if (FileEmpty) {
		cout << "�ļ���¼Ϊ��" << endl;
		//system("pause");
		return;
	}
	cout << "��������ҵķ�ʽ��" << endl;
	cout << "1.��ְ����Ų���" << endl;
	cout << "2.����������" << endl;
	int op, index = -1;
	cin >> op;
	switch (op) {
	case 1: {
		cout << "��������ҵ�ְ����ţ�" << endl;
		 index = IsExist();
	}break;
	case 2: {
		cout << "��������ҵ�������" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < ArrayCnt; i++) {
			if (name.compare(pArray[i]->m_name) == 0) {
				 index = i;
				break;
			}
		}
	}break;
	}
	if (index == -1) {
		cout << "����ʧ�ܣ����޴���" << endl;
	}
	else {
		cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
		cout << "ְ����ţ� " << pArray[index]->m_id;
		cout << "  ְ�������� " << pArray[index]->m_name;
		cout << "\t��λ��" << pArray[index]->getPosition();
		cout << "\t��λְ��";
		pArray[index]->getDuty();
		cout << endl;
	}
}

void WorkManager::SortStaff() {
	if (FileEmpty) {
		cout << "�ļ���¼Ϊ��" << endl;
		//system("pause");
		return;
	}
	cout << "��ѡ������ʽ" << endl;
	cout << "1.��ְ���Ž�������" << endl;
	cout << "2.��ְ���Ž��н���" << endl;
	int op;
	cin >> op;
	int i, j, minmax;
		for (i = 0; i < ArrayCnt - 1; i++) {
			 minmax = i;
			for (j = i + 1; j < ArrayCnt; j++) {
				if(op == 1){
					if (pArray[j]->m_id < pArray[minmax]->m_id) {
						minmax = j;
					}
				}
				else {
					if (pArray[j]->m_id > pArray[minmax]->m_id) {
						minmax = j;
					}
				}
		}
			if (minmax != i) {
				Worker* temp;
				temp = pArray[i];
				pArray[i] = pArray[minmax];
				pArray[minmax] = temp;
				temp = NULL;
			}
			
	}
	
	cout << "����ɹ���������Ϊ��" << endl;
	this->save();
	this->ShowStaff();
}

void WorkManager::EmptyFile() {
	if (pArray != NULL) {
		for (int i = 0; i < ArrayCnt; i++) {
			delete pArray[i];
		}
		delete[] pArray;
		pArray = NULL;
	}
	ArrayCnt = 0;
	FileEmpty = true;
	this->save();
}