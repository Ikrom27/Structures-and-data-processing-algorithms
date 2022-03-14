#include "list.h"
#include <iostream>
#include <stdlib.h>

Phonelist::Phonelist()
{
	Head = Tail = NULL;
	Count = 0;
}

Phonelist::~Phonelist()
{
}

void Phonelist::show()
{
    // Если в списке присутствуют элементы, то пробегаем по нему
    // и печатаем элементы, начиная с головного
    if (Count != 0)
    {
        Elem* temp = Head;
        while (temp->next != 0)
        {
            cout << "ID-";
            cout << temp->ab_index << " книга: ";
            cout << "<<" << temp->book_name << ">>" << " дата выдачи: ";
            cout << temp->date_issue << " дата возврата: ";
            cout << temp->date_return << " дата фактического возврата: ";
            cout << temp->date_fact << "\n";
            temp = temp->next;
        }
        cout << "ID-";
        cout << temp->ab_index << " книга: ";
        cout << "<<" << temp->book_name << ">>" << " дата выдачи: ";
        cout << temp->date_issue << " дата возврата: ";
        cout << temp->date_return << " дата фактического возврата: ";
        cout << temp->date_fact << "\n";
    }
}

void Phonelist::change(int index, string _date_fact)
{
    if (0 < index and index <= Count) {
        if ((Count / 2) > index)
        {
            Elem* temp = Head;
            while (temp->ab_index != index)
            {
                temp = temp->next;
            }
            temp->date_fact = _date_fact;
            cout << "start from head\n";
        }
        else
        {
            Elem* temp = Tail;
            while (temp->ab_index != index)
            {
                temp = temp->prev;
            }
            temp->date_fact = _date_fact;
            cout << "start from tail\n";
        }
    }
    else
    {
        cout << "incorrect index!\n";
    }
}

void Phonelist::remove_same()
{
    int pos = 1;
    int i = 1;
    Elem* Del = Head;

    while (pos <= Count) {
        if (Del->ab_index != pos) {
            Del->ab_index = pos;
        }
        if (Del->date_fact == Del->date_return) {
            cout << Del->book_name << " " << Del->ab_index << " " << Count << " " << Del->date_fact << " "<< Del->date_return << " DEELL\n";
            //находим предыдущий и следующий элемент
            Elem* PrevDel = Del->prev;
            Elem* AfterDel = Del->next;

            // Если удаляем не голову
            if (PrevDel != 0 && Count != 1)
                PrevDel->next = AfterDel;
            // Если удаляем не хвост
            if (AfterDel != 0 && Count != 1)
                AfterDel->prev = PrevDel;

            // Удаляются крайние?
            if (pos == 1)
                Head = AfterDel;
            if (pos == Count)
                Tail = PrevDel;

            // Удаление элемента
            delete Del;
            Count--;
            if (AfterDel != 0) {
                Del = AfterDel;
            }
        }
        else
        {
            cout << Del->book_name << " " << Del->ab_index << " " << Count << " " << Del->date_fact << " " << Del->date_return << "\n";
            Del = Del->next;
            pos ++;
        }
    }
    //Count = pos;
}

void Phonelist::AddTail(string _book_name, string _date_issue, string _date_return, string _date_fact)
{
    // Создаем новый элемент
    Elem* temp = new Elem;
    // Следующего нет
    temp->next = 0;
    
    // Заполняем данные
    temp->book_name = _book_name;
    temp->date_issue = _date_issue;
    temp->date_return = _date_return;
    temp->date_fact = _date_fact;

    // Предыдущий - бывший хвост
    temp->prev = Tail;

    // Если элементы есть?
    if (Tail != 0)
        Tail->next = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - хвостовой
        Tail = temp;

    Count++;
    temp->ab_index = Count;
}


