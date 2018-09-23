#pragma once

#include <iostream>
using namespace std;

template <typename myType> 
class CMyStack
{
public:
	CMyStack();//конструктор
	~CMyStack();//деструктор
	void Push(myType d); // Вставка элемента
	myType Pop(); //Удаление элемента и возврат его значения
	bool isEmpty();//Проверка пустой ли стек
	void Print(); //Вывод на экран
private:
	struct Node
	{
		myType d;
		Node *p;
	};

	Node *top;
};

template <typename myType>
CMyStack<myType>::CMyStack() :top(NULL){}

template <typename myType>
void CMyStack<myType>::Push(myType d)
{
	Node *pv = new Node;
	pv->d = d;
	pv->p = top;
	top = pv;
}

template <typename myType>
myType CMyStack<myType>::Pop()
{
	if (isEmpty())
	{
		return -1;
	}
	myType temp = top->d;
	Node *pv = top;
	top = top->p;
	delete pv;
	return temp;
}

template <typename myType>
bool CMyStack<myType>::isEmpty()
{
	return top ? false : true;
}

template <typename myType>
void CMyStack<myType>::Print()
{
	while (top)
	{
		cout << Pop() << ' ';
	}
	cout << endl;
}

template <typename myType>
CMyStack<myType>::~CMyStack()
{
	while (top)
	{
		Node *pv = top;
		top = top->p;
		delete pv;
	}
}