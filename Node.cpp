#include<iostream>
template<typename T>
struct Node
{
	T info;
	int next;
	Node()
	{
		
		next = 0;
	}
	Node(T val)
	{
		info = val;
		next = 0;
	}

};