#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Worker.h"
#include "Employe.h"
#include "Manager.h"
#include "Boss.h"

class WorkManager {
public:
	WorkManager();

	~WorkManager();

	void InitArray();

	void save();

	int IsExist();

	void Exit(); 

	void AddStaff(); 
	
	void ShowStaff();  
	
	void DeleteStaff();  
	
	void ChangeStaff(); 
	
	void FindStaff();    
	
	void SortStaff();  
	
	void EmptyFile();

	bool FileEmpty;
	int ArrayCnt;
	Worker** pArray;
};
