#pragma once
#include "StudentArray.h"
#include "Student.h"
#include <string>
using namespace std;

class Univer {
	string _title; // название университета
	StudentArray* _students; // список студентов
public:
	int N; // текущее кол-во студентов

	// Конструктор университета
	// Название
	Univer(string);

	// Добавить студента
	void addStudent(Student*);

	// Удалить студента
	void removeStudent(string);

	// Изменить информацию студента
	// Номер зачетной книжки и номер поля для изменения
	void changeStudent(string, int);

	// Вывести информацию о каждом студенте университета
	void showStudents();


	// Показать диалог изменения данных студента
	// Принимает номер зачётки
	void showStudentChangeDialog(string);

	// Получить адрес "студента" по номеру зачётки
	Student* getByZach(string);

	// Проверить наличие студента в университете
	int hasStudent(Student*);

	// Проверить наличие студента в университете по номеру зачётки
	int hasStudent(string);

	// Выполнить выборку, согласно условиям 93 варианта
	void var93query(int se, int ee);

	// Деструктор университета
	~Univer();

	// Генерация строки для дальнейшего экспорта в файл
	string exportAll();

	// Сохранить базу данных в файл
	void saveAll();

	// Загрузить базу данных из файла
	void loadAll();
};
