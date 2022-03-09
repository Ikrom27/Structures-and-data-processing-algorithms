#ifndef __MYLIST_H
#define __MYLIST_H
#include <string>

using namespace std;

struct Elem
{
	// данные
	string client_number;
	int speak_time;
	string user_number;

	Elem* next, * prev;	// ссылки на след и предыдущий элемент
};

class Phonelist
{
private:

	Elem* Head, * Tail;		// Голова, хвост
	int Count;				// Количество элементов

public:

	Phonelist();		// Конструктор
	~Phonelist();		// Деструктор

	int GetCount();		// Получить количество
	Elem* GetElem(int);	// Получить элемент списка
	void Print();		// Печать списка

	void AddTail(string _client_number, int _speak_time, string _user_number);	// Добавление в конец списка
	void AddHead(string _client_number, int _speak_time, string _user_number);	// Добавление в начало списка
};


#endif