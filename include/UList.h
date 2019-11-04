#ifndef __TLISTK_H__
#define __TLISTK_H__
#include <iostream>
template <typename ValType>
class Node
{
public:
	ValType Data = 0;
	Node *next = 0;
	Node(ValType _Data = 0, Node* _next = 0)
	{
		this->Data = _Data;
		this->next = _next;
	}
};

template <typename ValType>
class List
{
	int Size;
	Node<ValType>* head;
public:
	List(int n = 0);
	void Insert(ValType Data, Node<ValType>* prev);
	void Remove(Node<ValType>* prev);
	void push_back(ValType Data);
	void Print();
	int GetSize()
	{
		return Size;
	}

};
template <typename ValType>
List<ValType>::List(int n = 0)
{
	if (n < 0)
		throw "Not correct";
	head = new Node<ValType>;
	Node<ValType>* tmp = head;
	for (int i = 0; i < n; i++)
	{
		Node<ValType>* tmp2 = new Node<ValType>;
		tmp->next = tmp2;
	}
	Size = n;
}
template <typename ValType>
void List<ValType>::Insert(ValType Data, Node<ValType>* prev)
{
	Node<ValType>* a = new Node;
	a->Data = Data;
	Node<ValType>* b = prev->next;
	delete prev->next;
	prev->next = a;
	a->next = b;
	Size++;
}
template <typename ValType>
void List<ValType>::push_back(ValType Data)
{
	if (head == 0)
		head = new Node<ValType>(Data);
	else
	{
		Node<ValType> * current = this->head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new Node<ValType>(Data);
	}
	Size++;
}
template <typename ValType>
void List<ValType>::Remove(Node<ValType>* prev)
{
	Node<ValType>* tmp = prev->next;
	delete prev->next;
	prev->next = tmp;
	Size--;
}
template <typename ValType>
void List<ValType>::Print()
{
	Node<ValType> * current = this->head;
	while (current->next)
	{
		current = current->next;
		std::cout << current->Data << std::endl;
	}
}
#endif