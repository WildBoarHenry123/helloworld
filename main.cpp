#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include "Worker.h"
#include "Employe.h"
#include "Manager.h"
#include "Boss.h"
#include "WorkManager.h"

int main() {
	WorkManager wm;
	int choice = 0;
	while (true) {
		cout << "********************************************" << endl;
		cout << "*********  ��ӭʹ��ְ������ϵͳ��   ********" << endl;
		cout << "*************  0.�˳��������  *************" << endl;
		cout << "*************  1.����ְ����Ϣ  *************" << endl;
		cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
		cout << "*************  3.ɾ����ְְ��  *************" << endl;
		cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
		cout << "*************  5.����ְ����Ϣ  *************" << endl;
		cout << "*************  6.���ձ������  *************" << endl;
		cout << "*************  7.��������ĵ�  *************" << endl;
		cout << "********************************************" << endl;
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 0: {
			wm.Exit();
		}break;
		case 1: {
			wm.AddStaff();
		}break;
		case 2: {
			wm.ShowStaff();
		}break;
		case 3: {
			wm.DeleteStaff();
		}break;
		case 4: {
			wm.ChangeStaff();
		}break;
		case 5: {
			wm.FindStaff();
		}break;
		case 6: {
			wm.SortStaff();
		}break;
		case 7: {
			wm.EmptyFile();
		}break;
		
		}
		system("pause");
		system("cls");
	}
	system("pause");
	
	return 0;
}