#ifndef __TAVLTREE_H__
#define __TAVLTREE_H__
#include <iostream>
#include <string>

class node
{
public:
	int key;
	std::string data; // There might be a template here, but no
	node* left;
	node* right;
	int height;
	node(int key = 0)
	{
		key = key;
		data = "Kitty"; // I like cats 
		left = 0;
		right = 0;
		height = 1;
	}
};
class avltree
{
	node* data;
	void clear(node* p)
	{
		if (p == NULL)
			return;
		clear(p->left);
		clear(p->right);
		delete p;
	}
	int height(node* t)
	{
		return (t == NULL ? -1 : t->height);
	}
	int bfactor(node* t)
	{
		return (t == NULL ? 0 : (height(t->left) - height(t->right)));
	}
	void fixheight(node* t)
	{
		int height_left = height(t->left);
		int height_right = height(t->right);
		t->height = (height_left>height_right ? height_left : height_right) + 1;
	}
	node* rotate_right(node* t) // Why have single and double rotation when you can have only single? 
	{

		node* q = t->left;
		t->left = t->right;
		t->right = t;
		fixheight(t);
		fixheight(q);
		return q;
	}
	node* rotate_left(node* q) 
	{
		node* t = q->right;
		q->right = t->left;
		t->left = q;
		fixheight(q);
		fixheight(t);
		return t;
	}
	node* balance(node* t) 
	{
		fixheight(t);
		if (bfactor(t) == 2)
		{
			if (bfactor(t->right) < 0)
				t->right = rotate_right(t->right);
			return rotate_left(t);
		}
		if (bfactor(t) == -2)
		{
			if (bfactor(t->left) > 0)
				t->left = rotate_left(t->left);
			return rotate_right(t);
		}
		return t; 
	}
	node* insert(node* t, int key) 
	{
		if (!t) return new node(key);
		if (key<t->key)
			t->left = insert(t->left, key);
		else
			t->right = insert(t->right, key);
		return balance(t);
	}
	node* find_min(node* t)
	{
		if (t == 0)
			return 0;
		else if (t->left == 0)
			return t;
		else
			return find_min(t->left);
	}
	node* remove_min(node* t) 
	{
		if (t->left == 0)
			return t->right;
		t->left = remove_min(t->left);
		return balance(t);
	}
	node* remove(node* t, int key)
	{
		if (!t)
			return 0;
		if (key < t->key)
			t->left = remove(t->left, key);
		else if (key > t->key)
			t->right = remove(t->right, key);
		else 
		{
			node* temp_left = t->left;
			node* temp_right = t->right;
			delete t;
			if (!temp_right) return temp_left;
			node* min = find_min(temp_right);
			min->right = remove_min(temp_right);
			min->left = temp_left;
			return balance(min);
		}
		return balance(t);
	}

};
#endif