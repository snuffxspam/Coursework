#pragma once

#include "Person.h"
#include "Zachetka.h"

// ����� Student ��������� ����� Person
class Student : public Person {
	// ������-������, ������� �������� ������ 
	// � ��������� ��������� ������ Student (� Person 
	// ��������������) ��� ����� ������� ��������������
	friend class Univer;
	friend class StudentArray;

	Date _edate; // ���� �����������
	string _group; // ������
	string _fac; // ���������
	string _kaf; // �������
	Zachetka* _zach; // �������
public:
	// ������� ��� ���������� � �������� + � ��������
	void fullIntroduce();

	// ����������� ��������
	// �������, ���, ��������, ���, ���� ��������, ������ ���������, �������, ��� �����������, �������
	Student(string, string, string, int, Date, string, string, string, Date, Zachetka*);

	// ����������� �������� �� ������ �������������� �����
	Student(string);

	// ���������� ��������
	~Student();

	// ������� �������������� ���� ������ ��������
	float fullAvg();

	// ������ ��� �������� ������ �������� � ����
	string dataForExport();
};