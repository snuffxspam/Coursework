#pragma once
#include <string>
#include "Semestr.h"
using namespace std;
class Zachetka
{
	// ������-������, ������� �������� ������ 
	// � ��������� ��������� ������ Zachetka
	// ��� ����� ������� ��������������
	friend class StudentArray;
	friend class Student;
	friend class Univer;

	string _num; // ����� �������
	Semestr* _sems[12]; // 12 ���������
	int sc = 0; // ���-�� ��������� ���������
	int sec = 0; // ���-�� ��������� ������
public:
	// ����������� �������
	// ��������� ����� �������
	Zachetka(string);

	// ������� � ���� ������� ��� �������� � �������� � ��������
	void showAll();

	// ���������� �������
	~Zachetka();

	// �������� ������� � �������
	int addSem(Semestr*);

	// ������� ������ �� ���� �������
	float average();

	// �������� ������ ��� �������� � ����
	string dump();
};

