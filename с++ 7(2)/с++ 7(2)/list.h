#ifndef __MYLIST_H
#define __MYLIST_H
#include <string>

using namespace std;

struct Elem
{
	// ������
	string client_number;
	int speak_time;
	string user_number;

	Elem* next, * prev;	// ������ �� ���� � ���������� �������
};

class Phonelist
{
private:

	Elem* Head, * Tail;		// ������, �����
	int Count;				// ���������� ���������

public:

	Phonelist();		// �����������
	~Phonelist();		// ����������

	int GetCount();		// �������� ����������
	Elem* GetElem(int);	// �������� ������� ������
	void Print();		// ������ ������

	void AddTail(string _client_number, int _speak_time, string _user_number);	// ���������� � ����� ������
	void AddHead(string _client_number, int _speak_time, string _user_number);	// ���������� � ������ ������
};


#endif