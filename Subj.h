#pragma once
#include <string>

using namespace std;
class Subj {
public:
	string title; // Название предмета
	int mark; // Оценка

	// Конструктор предмета
	// Название, оценка
	Subj(string, int);

	// Конструктор предмета для массивов
	Subj();
};