#include "list.h"
#include <iostream>

Phonelist::Phonelist(){
	Head = Tail = nullptr;
	Count = 0;
}
Phonelist::~Phonelist()
{
}

int Phonelist::GetCount()
{
    return Count;
}

Elem* Phonelist::GetElem(int pos)
{
    Elem* temp = Head;

    // Проверяем ввод
    if (pos < 1 and pos > Count)
    {
        std::cout << "Incorrect position !\n";
        return 0;
    }


    // Ищем нужный нам элемент
    int i = 1;
    while (i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }

    if (temp == 0)
        return 0;
    else
        return temp;
}

void Phonelist::Print()
{
    // Если в списке присутствуют элементы, то пробегаем по нему
   // и печатаем элементы, начиная с головного
    if (Count != 0)
    {
        Elem* temp = Head;
        while (temp->next != 0)
        {
            cout << "Номер абонента: ";
            cout << temp->client_number << "  время разговора: ";
            cout << temp->speak_time << " мин.  номер звонящего: ";
            cout << temp->user_number << "\n";

            temp = temp->next;
        }
    }
    else {
        cout << "No elements";
    }
}

void Phonelist::AddHead(string _client_number, int _speak_time, string _user_number)
{
    // новый элемент
    Elem* temp = new Elem;

    // Предыдущего нет
    temp->prev = 0;

    // Заполняем данные
    temp->client_number = _client_number;
    temp->speak_time = _speak_time;
    temp->user_number = _user_number;
    
    // Следующий - бывшая голова
    temp->next = Head;

    // Если элементы есть?
    if (Head != 0)
        Head->prev = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - головной
        Head = temp;

    Count++;
}

void Phonelist::AddTail(string _client_number, int _speak_time, string _user_number)
{
    // Создаем новый элемент
    Elem* temp = new Elem;
    // Следующего нет
    temp->next = 0;

    // Заполняем данные
    temp->client_number = _client_number;
    temp->speak_time = _speak_time;
    temp->user_number = _user_number;

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
}
