#pragma once
#include <string>
#include <ctime>
#include "Date.h"
#include <iostream>

using namespace std;
class Person {
protected:
	string _sname; // �������
	string _fname; // ���
	string _mname; // ��������
	Date _bdate; // ���� ��������
	int _gender; // ���: 0=�, 1=�
public:
	// ����� ���������� � ��������
	void fullIntroduce(); 
};

