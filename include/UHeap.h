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
	std::vector<priority_elem<ValType>> data;
	int demension;
	heap(int _d = 2)
	{
		demension = _d;
	}
	int approachMyChild(int id, int childInd)
	{
		if (childInd >= demension || childInd < 0)
			throw "WTF!?!?!";
		return (demension*id + childInd);
	}
	int parent(int id)
	{
		return ((id - 1) / demension);
	}
	int minChild(int id)
	{
		int min = approachMyChild(id; 0);
		for (int i = 0; i < demension; i++)
		{
			if (data[approachMyChild(id), i] < data[min])
			{
				min = i;
			}
		}
		return min;
	}
	void swap(int id1, int id2)
	{
		priority_elem<ValType> tmp = data[j1];
		data[j1] = data[j2];
		data[j2] = tmp;
	}
	void diving(int id)
	{
		int j1, j2;
		j1 = id;
		j2 = minChild(id);
		while (j2 != -1 && data[j1] > data[j2])
		{
			data.swap(j1, j2);
			//swap(j1, j2);
			j1 = j2;
			j2 = minChild(j1);
		}
	}
	void emersion(int id)
	{
		int j1, j2;
		j1 = id;
		j2 = parent(id);
		while (data[j1] < data[j2] && j2!= -1)
		{
			data.swap(j1, j2);
			j1 = j2;
			j2 = parent(j1);
		}
	}
	void insert(priority_elem<ValType> el)
	{
		data.push_back(el);
		emersion(data.size() - 1);
	}
	void deleteMin()
	{
		data.swap(0, data.size() - 1);
		data.pop_back();
		diving(0);
	}
	void decreaseWeight(int id, int delta)
	{
		data[id].priority -= delta;
		emersion(id);
	}
	void Delete(int id)
	{
		decreaseWeight(id, INF);
		deleteMin();
	}
	void makeHeap()
	{
		for (int i = data.size() - 1; i >= 1; i++)
			diving(i);
	}
};
#endif
