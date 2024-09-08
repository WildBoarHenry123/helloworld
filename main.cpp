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
		cout << "*********  欢迎使用职工管理系统！   ********" << endl;
		cout << "*************  0.退出管理程序  *************" << endl;
		cout << "*************  1.增加职工信息  *************" << endl;
		cout << "*************  2.显示职工信息  *************" << endl;
		cout << "*************  3.删除离职职工  *************" << endl;
		cout << "*************  4.修改职工信息  *************" << endl;
		cout << "*************  5.查找职工信息  *************" << endl;
		cout << "*************  6.按照编号排序  *************" << endl;
		cout << "*************  7.清空所有文档  *************" << endl;
		cout << "********************************************" << endl;
		cout << "请输入您的选择：" << endl;
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