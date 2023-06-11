#ifndef ARRAY_H
#define ARRAY_H
#include"Node.cpp"
template<typename T>
class ALSLL
{
	Node<T> arr[8];
	int ULH = 0;
	int ALH = 0;
	int getNewNode();
public:
	ALSLL();
	int getALH();
	void inertAtHead(T val);
	void insertAtTail(T val);
	void insertBefore(T key, T val);
	void insertAfter(T key, T val);
	void returnNode(int x);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T key);
	void removeBefore(T key);
	void display();



};
#endif
