#pragma once

#include "Person.h"
#include "Zachetka.h"

// Класс Student наследует класс Person
class Student : public Person {
	// классы-друзья, которым разрешен доступ 
	// к приватным элементам класса Student (и Person 
	// соответственно) для более прямого взаимодействия
	friend class Univer;
	friend class StudentArray;

	Date _edate; // дата поступления
	string _group; // группа
	string _fac; // факультет
	string _kaf; // кафедра
	Zachetka* _zach; // зачётка
public:
	// Вывести всю информацию о студенте + о человеке
	void fullIntroduce();

	// Конструктор студента
	// Фамилия, имя, отчество, пол, дата рождения, группа факультет, кафедра, год поступления, зачётка
	Student(string, string, string, int, Date, string, string, string, Date, Zachetka*);

	// Конструктор студента из строки импортируемого файла
	Student(string);

	// Деструктор студента
	~Student();

	// Среднее арифметическое всех оценок студента
	float fullAvg();

	// Строка для экспорта данных студента в файл
	string dataForExport();
};