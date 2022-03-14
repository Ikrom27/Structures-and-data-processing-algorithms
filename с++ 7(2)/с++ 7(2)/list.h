#ifndef __MYLIST_H
#define __MYLIST_H
#include <string>

using namespace std;

struct Elem
{
	int ab_index;
	string book_name;
	string date_issue;
	string date_return;
	string date_fact;

	Elem* next, * prev;	
};

class Phonelist
{
private:

	Elem* Head, * Tail;		
	int Count;			

public:

	Phonelist();		
	~Phonelist();		

	int GetCount() { return Count; };

	void show();		
	void change(int index, string _date_fact);
	void remove_same();
	void AddTail(string _book_name, string _date_issue, string _date_return, string _date_fact);
	//void AddHead(int _ab_index, string _book_name, string _date_issue, string _date_return, string _date_fact);
};


#endif