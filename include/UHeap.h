#ifndef __THEAD_H__
#define __THEAD_H__
#include <string>
#include <vector>
#include<iostream>
template <typename ValType>
class priority_elem
{
public:
	ValType data;
	int priority;
	priority_elem(int _pr, ValType _data)
	{
		priority = _pr;
		data = _data;
	}
	bool operator>(priority_elem<ValType> _e)
	{
		return priority > _e.priority;
	}
	bool operator<(priority_elem<ValType> _e)
	{
		return !(priority > _e.priority);
	}
};
template <typename ValType>
class heap
{
public:
	std::vector<priority_elem<ValType>> ar;
	int demension;
	heap(int _d)
	{
		demention = _d;
	}
};
#endif
