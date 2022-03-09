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

    // ��������� ����
    if (pos < 1 and pos > Count)
    {
        std::cout << "Incorrect position !\n";
        return 0;
    }


    // ���� ������ ��� �������
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
    // ���� � ������ ������������ ��������, �� ��������� �� ����
   // � �������� ��������, ������� � ���������
    if (Count != 0)
    {
        Elem* temp = Head;
        while (temp->next != 0)
        {
            cout << "����� ��������: ";
            cout << temp->client_number << "  ����� ���������: ";
            cout << temp->speak_time << " ���.  ����� ���������: ";
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
    // ����� �������
    Elem* temp = new Elem;

    // ����������� ���
    temp->prev = 0;

    // ��������� ������
    temp->client_number = _client_number;
    temp->speak_time = _speak_time;
    temp->user_number = _user_number;
    
    // ��������� - ������ ������
    temp->next = Head;

    // ���� �������� ����?
    if (Head != 0)
        Head->prev = temp;

    // ���� ������� ������, �� �� ������������ � ������ � �����
    if (Count == 0)
        Head = Tail = temp;
    else
        // ����� ����� ������� - ��������
        Head = temp;

    Count++;
}

void Phonelist::AddTail(string _client_number, int _speak_time, string _user_number)
{
    // ������� ����� �������
    Elem* temp = new Elem;
    // ���������� ���
    temp->next = 0;

    // ��������� ������
    temp->client_number = _client_number;
    temp->speak_time = _speak_time;
    temp->user_number = _user_number;

    // ���������� - ������ �����
    temp->prev = Tail;

    // ���� �������� ����?
    if (Tail != 0)
        Tail->next = temp;

    // ���� ������� ������, �� �� ������������ � ������ � �����
    if (Count == 0)
        Head = Tail = temp;
    else
        // ����� ����� ������� - ���������
        Tail = temp;

    Count++;
}
