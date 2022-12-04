#include "Zachetka.h"
#include "Utils.h"
#include <string>
#include <iomanip>
#include "Subj.h"

#include <iostream>
using namespace std;

// Конструктор зачётки, принимает номер зачётки
Zachetka::Zachetka(string num) {
	_num = num;
}

// Деструктор зачётки, удаляет за собой все семестры
Zachetka::~Zachetka() {
	for (int i = 0;i < sc;i++) {
		delete _sems[i];
	}
}

// Показать все семестры с предметами и оценками
void Zachetka::showAll() {
	for (int i = 0;i < sc;i++) {
		cout << setw(3) << " " <<(i+1) <<" семестр:"<<endl;
		for (int j = 0;j < _sems[i]->sc; j++) {
			if (_sems[i]->_subjects[j]->title == "0subj~~") {
				// это пустой предмет для обозначения существования сессии
			}
			else
				cout << setw(7) << " " << _sems[i]->_subjects[j]->title << ": " << (_sems[i]->_subjects[j]->mark == 1 ? "P" : to_string(_sems[i]->_subjects[j]->mark)) << endl;
		}
	}
}

// получить строку для экспорта в файл
string Zachetka::dump() {
	/*
		Структура выходных данных:

		Subj1 (\2) 5 (\3) Subj2 (\2) 4 (\3)(\1)							// первый семестр с двумя предметами
		(\1)															// второй семестр - нет сессии
		Subj3 (\2) 5 (\3) Subj4 (\2) 4 (\3)(\1)							// третий семестр с двумя предметами
		....															// всего 12 семестров
	*/

	string result; // строка для накопления результата
	string m = "\3", // разделители
		s = "\2",
		le = "\1";

	for (int i = 0;i < 12;i++) {
		// формирование выходной строки в цикле по всем семестрам и предметам внутри них
			for (int j = 0;j < _sems[i]->sc;j++) {
				result.append(_sems[i]->_subjects[j]->title + s + to_string(_sems[i]->_subjects[j]->mark) + m);
			}
			result.append(le);
	}

	return result;
}

// Добавить семестр в зачётку
int Zachetka::addSem(Semestr* s) {
	if (sec < 12) { // проверить, что сессий меньше 9
		_sems[sc] = sec<9 ? s : new Semestr(); // добавить пустой семестр, если больше 9 сессий
		if (s->sc != 0)
			sec++; // увеличить счётчик сессий, если сессия не пуста
		sc++; // увеличить счётчик семестров
		return 1;
	}
	return 0;
}

// Средний балл за все семестры
float Zachetka::average() 
{
	float sum = 0;
	int count = 0;
	// цикл по всем семестрам с подсчётом суммы и кол-ва оценок
	for (int i = 0; i < sc;i++) {
		if (_sems[i]->sc != 0) {
			if (_sems[i]->average() == -1) {
				// не было сессии, так как вообще нет предметов
			}
			else {
				sum += _sems[i]->average();
				count++;
			}
		}
	}
	return count == 0 ? -1 : sum * 1.0 / count; // вернуть среднее арифметическое в случае, если кол-во не равно нулю
}
