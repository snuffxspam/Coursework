#pragma once
#include "Subj.h"
class Semestr
{
	// классы-друзья, которые могут получить доступ к приватным
	// элементам семестра для более удобного взаимодействия
	friend class Student;
	friend class Zachetka;
	friend class Univer;

	Subj* _subjects[10]; // массив из 10 возможных предметов в семестре (сессии)

public:
	int sc=0; // кол-во имеющихся предметов
	// Конструктор класса семестр
	Semestr();
	// Проверить наличие предмета в семестре
	// 1=существует, 0=не существует
	int hasSubj(string);
	// Получить адрес предмета по его названию
	Subj* getByTitle(string);
	// Добавить предмет в семестр
	int addSubj(Subj*);
	// Среднее арифметическое оценок за семестр
	float average();
};

