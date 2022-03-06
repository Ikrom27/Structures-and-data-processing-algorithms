// c++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


template <typename T>
class List {
public:

    List();     //конструктор класса 
    ~List();    //деструктор

    void push_back(T data);
    int getsize() { return size; }
    T& operator[](const int index);

private:
    template <typename T>   //шаблонный класс
    class Node {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int size;
    Node<T>* head;
};
template <typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
};
template <typename T>
List<T>::~List()
{
}
template<typename T>
void List<T>::push_back(T data)
{   
    if (head == nullptr)    // Если первый элемент пустой
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr) {     //ищем последний элемент списка
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);     //когда находим,то пихаем в нее конструктор класса Node
    }
    size++;
}
template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
};


int main()
{
    List<int> lst1;
    List<int> lst2;

    int L1[10] = {1, 3, 34, 45, 32, 21, 23, 232, 12, 33};
    int L2[10] = {2, 4, 34, 45, 36, 22, 23, 230, 10, 33};

    for (int i = 0; i < 10; i++) {
        lst1.push_back(L1[i]);
        lst2.push_back(L2[i]);
    }

    for (int i = 0; i < lst1.getsize(); i++) {
        std::cout << lst1[i] << " ";
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
