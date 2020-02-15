#pragma once
#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include <iostream>
template<typename VT>
class Queue
{
	VT* Data;
	int Size;
	int Xd;
	int Tl;
	int Count;
public:
	Queue(int _Size = 13)
	{
		if (_Size < 0)
			throw "Incorrect size";
		Data = new VT[_Size];
		Size = _Size;
		Xd = 0;
		Count = 0;
		Tl = 1;
	}
	bool IsEmpty()
	{
		bool flag = 0;
		if (Count == 0)
			flag = 1;
		return flag;
	}
	VT& top()
	{
		if (IsEmpty())
			throw "incorrect";
		return Data[Xd];
	}
	void pop()
	{
		if (IsEmpty())
			throw "incorrect";
		Xd = (Xd + 1) % Size;
		Count--;
	}
	void push(const VT& _Data)
	{
		if (Xd == Tl)
		{
			VT* tmp = new VT[4 / 3 * Size + 1];
			for (int i = 0; i < Size; i++)
			{
				tmp[i] = Data[(Xd + i)  % Size];
			}
			delete Data;
			Data = tmp;
			Xd = 0;
			Tl = Size;
			Size = 4 / 3 * Size + 1;
		}
		Data[(Tl - 1) % Size] = _Data;
		Tl = (Tl + 1) % Size;
		Count++;
	}
	~Queue()
	{
		delete[] Data;
	}
};




#endif