#include<iostream>
using namespace std;
#include "ALSLL.h"
template <typename T>
ALSLL<T>::ALSLL()
{
	ULH = -1;
	ALH = 0;
	int i;
	for (i = 0; i < 7; i++)
	{
		arr[i].next = i + 1;
	}
	arr[i].next = -1;
}
template <typename T>
int ALSLL<T>::getALH()
{
	cout << ALH;
	return ALH;
}

template <typename T>
int ALSLL<T>::getNewNode()
{
	if (ALH == -1)
		return -1;
	int x = ALH;
	ALH = arr[ALH].next;
	return x;
}
template <typename T>
void ALSLL<T>::inertAtHead(T val)
{
	int x = getNewNode();
	arr[x].next = ULH;
	arr[x].info = val;
	ULH = x;
}
template <typename T>
void ALSLL<T>::insertAtTail(T val)
{
	int x = getNewNode();
	int y = ULH;
	if (ULH == -1)
	{
		inertAtHead(val);
		return;
	}
	while (arr[y].next != -1)
	{
		y = arr[y].next;
	}
	arr[y].next = x;
	arr[x].info = val;
	arr[x].next = -1;
}
template <typename T>
void ALSLL<T>::insertBefore(T key, T val)
{
	int y = ULH;
	int pre = y;
	if (arr[y].info == key)
	{
		inertAtHead(val);
		return;
	}
	while (y != -1)
	{
		if (arr[y].info == key)
		{
			int x = getNewNode();
			arr[pre].next = x;
			arr[x].info = val;
			arr[x].next = y;
		}
		pre = y;
		y = arr[y].next;
	}
}
template <typename T>
void ALSLL<T>::insertAfter(T key, T val)
{
	int y = ULH;
	if (arr[y].info == key)
	{
		insertAtTail(val);
		return;
	}
	while (y != -1)
	{
		if (arr[y].info == key)
		{
			int x = getNewNode();
			arr[x].next = arr[y].next;
			arr[y].next = x;
			arr[x].info = val;
		}
		y = arr[y].next;
	}
}
template <typename T>
void ALSLL<T>::returnNode(int x)
{
	arr[x].next = ALH;
	ALH = x;
}
template <typename T>
void ALSLL<T>::removeAtHead()
{
	if (ULH == -1)
		return;

	int y = ULH;
	ULH = arr[ULH].next;
	returnNode(y);
}
template <typename T>
void ALSLL<T>::removeAtTail()
{
	int y = ULH;
	int pre = y;
	while (arr[y].next != -1)
	{
		pre = y;
		y = arr[y].next;
	}
	arr[pre].next = -1;
	returnNode(y);
}
template <typename T>
void ALSLL<T>::removeAfter(T key)
{
	int x = ULH;
	int nxt = ULH;
	if (arr[ULH].info == key)
	{
		removeAtTail();
		return;
	}
	while (x != -1)
	{
		if (arr[x].info == key)
		{
			nxt = arr[x].next;
			arr[x].next = arr[nxt].next;
			returnNode(nxt); 
			return;
		}
		x = arr[x].next;
	}
}
template <typename T>
void ALSLL<T>::removeBefore(T key)
{
	int x = ULH;
	int pre = ULH;
	int prePre = ULH;
	if (arr[arr[ULH].next].info == key)
	{
		removeAtHead();
		return;
	}
	while (x != -1)
	{
		if (arr[x].info == key)
		{
			arr[prePre].next = arr[pre].next;
			returnNode(pre);
		}
		prePre = pre;
		pre = x;
		x = arr[x].next;

	}
}



template <typename T>
void ALSLL<T>::display()
{
	int p = ULH;
	while (p != -1)
	{
		cout << arr[p].info << " ";
		p = arr[p].next;
	}

}



