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
	//1.文件不存在
	if (!ifs.is_open())
	{
		ArrayCnt = 0;
		FileEmpty = true;
		pArray = NULL;
		ifs.close();
		return;
	}
	//2.文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		ArrayCnt = 0;
		FileEmpty = true;
		pArray = NULL;
		ifs.close();
		return;
	}
	//3.文件存在且有数据
	int id, position, cnt = 0;
	string name;
	while (ifs >> id && ifs >> name && ifs >> position) {
		cnt++;
	}
	ifs.clear(); // 清除 EOF 标志
	ifs.seekg(0); // 重置文件读取位置到开头

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
		cout << "文件打开失败" << endl;
	}
	for (int i = 0; i < ArrayCnt; i++) {
		ofs << pArray[i]->m_id;
		ofs << pArray[i]->m_name;
		ofs << pArray[i]->m_position;
	}
	cout << "文件打开成功！" << endl;
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
	cout << "欢迎下次使用" << endl;
	exit(0);
}
void WorkManager::AddStaff() {
	cout << "请输入增加职工数量：" << endl;
	int num, i;
	cin >> num;
	int newsize = ArrayCnt + num;
	Worker** NewpArray = new Worker * [newsize];
	for ( i = 0; i < ArrayCnt; i++) {
		NewpArray[i] = pArray[i];
	}
	for ( i = ArrayCnt; i < newsize; i++) {
		
		cout << "请输入第" << i - ArrayCnt + 1 << "名员工的编号：" << endl;
		int newid;
		cin >> newid;
		
		cout << "请输入第" << i-ArrayCnt+1 << "名员工的姓名：" << endl;
		string newname;
		cin >> newname;
		
		cout << "请输入岗位：" << endl;
		cout << "1.普通职工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		int position;
		cin >> position;
		
		switch (position) {
		case 1: NewpArray[i] = new Employe(newid, newname, position); break;
		case 2: NewpArray[i] = new Manager(newid, newname, position); break;
		case 3: NewpArray[i] = new Boss(newid, newname, position); break;
		}

	}
	cout << "成功添加" << num << "名新职工" << endl;
	FileEmpty = false;
	ArrayCnt += num;
	delete [] pArray;
	pArray = NewpArray;
	this->save();
}

void WorkManager::ShowStaff() {
	if (FileEmpty) {
		cout << "文件记录为空" << endl;
		//system("pause");
		return;
	}
	for (int i = 0; i < ArrayCnt; i++) {
		cout << "职工编号： " << pArray[i]->m_id;
		cout << " 职工姓名： " << pArray[i]->m_name;
		cout << "\t岗位：" << pArray[i]->getPosition();
		cout << "\t岗位职责：";
		pArray[i]->getDuty();
		cout << endl;
	}
}

void WorkManager::DeleteStaff() {
	if (FileEmpty) {
		cout << "文件记录为空" << endl;
		//system("pause");
		return;
	}
	cout << "请输入想要删除的职工号：" << endl;
	int index = IsExist();
	if (index == -1) {
		cout << "删除失败，未找到该职工！" << endl;
	}
	else {
		delete pArray[index];
		for (int i = index; i < ArrayCnt - 1; i++) {
			pArray[i] = pArray[i + 1];
		}
		cout << "删除成功！" << endl;
	}
	ArrayCnt--;
	if (ArrayCnt == 0) {
		FileEmpty = true;
	}
	this->save();
}

void WorkManager::ChangeStaff() {
	if (FileEmpty) {
		cout << "文件记录为空" << endl;
		//system("pause");
		return;
	}
	cout << "请输入修改职工的编号: " << endl;
	int index = IsExist();
	if (index == -1) {
		cout << "未找到该员工！" << endl;
	}
	else {
		cout << "查到： " << pArray[index]->m_id << "号职工，请输入新职工号：" << endl;
		int newid;
		cin >> newid;
		string newname;
		cout << "请输入新姓名：" << endl;
		cin >> newname;
		int position;
		cout << "请输入岗位：" << endl;
		cout << "1.普通职工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		cin >> position;
		delete pArray[index];
		switch (position) {
		case 1: pArray[index] = new Employe(newid, newname, position); break;
		case 2: pArray[index] = new Manager(newid, newname, position); break;
		case 3: pArray[index] = new Boss(newid, newname, position); break;
		}

	}
    cout << "修改成功！" << endl;
    this->save();			
}

void WorkManager::FindStaff() {
	if (FileEmpty) {
		cout << "文件记录为空" << endl;
		//system("pause");
		return;
	}
	cout << "请输入查找的方式：" << endl;
	cout << "1.按职工编号查找" << endl;
	cout << "2.按姓名查找" << endl;
	int op, index = -1;
	cin >> op;
	switch (op) {
	case 1: {
		cout << "请输入查找的职工编号：" << endl;
		 index = IsExist();
	}break;
	case 2: {
		cout << "请输入查找的姓名：" << endl;
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
		cout << "查找失败，查无此人" << endl;
	}
	else {
		cout << "查找成功！该职工信息如下：" << endl;
		cout << "职工编号： " << pArray[index]->m_id;
		cout << "  职工姓名： " << pArray[index]->m_name;
		cout << "\t岗位：" << pArray[index]->getPosition();
		cout << "\t岗位职责：";
		pArray[index]->getDuty();
		cout << endl;
	}
}

void WorkManager::SortStaff() {
	if (FileEmpty) {
		cout << "文件记录为空" << endl;
		//system("pause");
		return;
	}
	cout << "请选择排序方式" << endl;
	cout << "1.按职工号进行升序" << endl;
	cout << "2.按职工号进行降序" << endl;
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
	
	cout << "排序成功，排序结果为：" << endl;
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