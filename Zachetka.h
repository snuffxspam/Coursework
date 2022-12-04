#pragma once
#include <string>
#include "Semestr.h"
using namespace std;
class Zachetka
{
	// классы-друзья, которым разрешен доступ 
	// к приватным элементам класса Zachetka
	// для более прямого взаимодействия
	friend class StudentArray;
	friend class Student;
	friend class Univer;

	string _num; // номер зачётки
	Semestr* _sems[12]; // 12 семестров
	int sc = 0; // кол-во имеющихся семестров
	int sec = 0; // кол-во имеющихся сессий
public:
	// Конструктор зачётки
	// Принимает номер зачётки
	Zachetka(string);

	// Вывести в окно консоли все семестры и предметы с оценками
	void showAll();

	// Деструктор зачётки
	~Zachetka();

	// Добавить семестр в зачётку
	int addSem(Semestr*);

	// Средняя оценка по всей зачётке
	float average();

	// Получить данные для экспорта в файл
	string dump();
};

