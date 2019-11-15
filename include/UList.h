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
class MIFL
{
private:
	Node<ValType>* ptr;
public:
	MIFL();
	MIFL(const MIFL& A);
	MIFL(Node<ValType>* A);
	MIFL operator++();
	MIFL operator++(int);
	MIFL& operator= (const MIFL& A);
	ValType& operator*();
	bool operator== (const MIFL& A)
	{
		return (ptr == A.ptr);
	}
	bool operator!= (const MIFL& A)
	{
		return (ptr != A.ptr);
	}
};
template <typename ValType>
class List
{
	int Size;
	Node<ValType>* head;
	Node<ValType>* tail;
public:
	List();
	List(int n);
	void Insert(ValType Data, Node<ValType>* prev);
	void Insert(ValType Data, int Ind);
	void Remove(Node<ValType>* prev);
	void Remove(int Ind);
	void push_back(ValType Data);
	ValType pop_back();
	void pop_front();
	void push_front(ValType Data);
	ValType Front();
	ValType Back();
	ValType& operator [](int n);
	~List();
	Node<ValType>* GetHead()
	{
		return head;
	}
	int GetSize()
	{
		return Size;
	}
	MIFL<ValType> begin()
	{
		MIFL<ValType> A(head);
		return A;
	}
	MIFL<ValType> end()
	{
		Node<ValType>* tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp = tmp->next;
		MIFL<ValType> A(tmp);
		return A;
	}
};

template <typename ValType>
void List<ValType>::push_front(ValType Data)
{
	head = new Node<ValType>(Data, head);
	if (Size == 0)
		tail = head;
	Size++;
}
template <typename ValType>
ValType List<ValType>::pop_back()
{
	int Counter = 0;
	ValType Tmp;
	Node<ValType> *current = this->head;
	while (current)
	{
		if (Counter == Size - 1)
		{
			Tmp = current->Data;
		}
		current = current->next;
		Counter++;
	}
	Remove(Size - 1);
	return Tmp;
}
template <typename ValType>
ValType List<ValType>::Front()
{
	if (Size != 0)
	{
		return head->Data;
	}
	else throw "Cant front from empty list";
}
template <typename ValType>
ValType List<ValType>::Back()
{
	if (Size != 0)
	{
		return operator [](Size - 1);
	}
	else throw "Cant back from empty list";
}
template <typename ValType>
void List<ValType>::pop_front()
{
	Node<ValType> *tmp = head;
	head = head->next;
	delete tmp;
	Size--;
}
template <typename ValType>
 ValType& List<ValType>::operator [](int n)
{
	 int Counter = 0;
	 if (n < 0 || n > Size)
	 {
		 throw "Incorrect index";
	 }
	 Node<ValType> *current = this->head;
	 while (current)
	 {
		 if (Counter == n)
		 {
			 return current->Data;
		 }
		 current = current->next;
		 Counter++;
	 }
}
template <typename ValType>
List<ValType>::List()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}
template <typename ValType>
List<ValType>::List(int n)
{
	if (n < 0)
		throw "Not correct";
	head = 0;
	tail = 0;
	Size = n;
	for (int i = 0; i < Size; i++) 
	{
		head = new Node<ValType>(0, head);
	}
}
template <typename ValType>
void List<ValType>::Insert(ValType Data, int n)
{
	if (n == 0)
	{
		push_front(Data);
	}
	else
	{
		Node<ValType> *Prev = this->head;
		for (int i = 0; i < n - 1; i++)
		{
			Prev = Prev->next;
		}
		Node<ValType> *New = new Node<ValType>(Data, Prev->next);
		Prev->next = New;
		Size++;
	}
}
template <typename ValType>
void List<ValType>::Insert(ValType Data, Node<ValType>* prev) 
{
	Node<ValType>* a = new Node;
	a->Data = Data;
	Node<ValType>* b = prev->next;
	prev->next = a;
	a->next = b;
	Size++;
}
template <typename ValType>
void List<ValType>::push_back(ValType Data)
{
	if (head == nullptr)
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
void List<ValType>::Remove(int Ind)
{
	if (Ind == 0)
	{
		pop_front();
	}
	else
	{
		Node<ValType> *Prev = this->head;
		for (int i = 0; i < Ind - 1; i++)
		{
			Prev = Prev->next;
		}
		Node<ValType> *tmp = Prev->next;
		Prev->next = tmp->next;
		delete tmp;
		Size--;
	}
}
template <typename ValType>
List<ValType>::~List()
{
	while (Size)
	{
		pop_front();
	}
	tail = 0;
}
template<typename ValType>
MIFL<ValType>::MIFL()
{
	ptr = 0;
}

template<typename ValType>
MIFL<ValType>::MIFL(const MIFL & A)
{
	ptr = A.ptr;
}
template<typename ValType>
 MIFL<ValType>::MIFL(Node<ValType>* A)
{
	 ptr = A;
}

 template<typename ValType>
 MIFL<ValType> MIFL<ValType>::operator++()
 {
	 ptr = ptr->next;
	 return *this;
 }


 template<typename ValType>
 MIFL<ValType> MIFL<ValType>::operator++(int)
 {
	 MIFL<ValType> tmp(ptr);
	 ptr = ptr->next;
	 return tmp;
 }

 template<typename ValType>
 MIFL<ValType>& MIFL<ValType>::operator=(const MIFL & A)
 {
	 ptr = A.ptr;
	 return *this;
 }

 template<typename ValType>
ValType & MIFL<ValType>::operator*()
 {
	return ptr->Data;
 }
#endif