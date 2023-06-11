#include<iostream>
using namespace std;

////int CUT(int N)
////{
////	if (N == 0)
////		return 0;
////	if (N % 2 == 0)
////	{
////		cout << N % 2;
////		return CUT(N / 2);
////	}
////	else
////		return CUT(N / 2) + 1;
////	return CUT(N - 1);
////}
//int main()
//{
//
//	ALSLL<int>l;
//	l.inertAtHead(7);
//
//
//	return 0;
//}
class A
{
	
private:
	int a;
public:
	A() :a(2) {};
	void func1()
	{
		cout << "A:Func1";
	}
	class B
	{
	public:
		int c;
		A::B()
		{
			c = 0;
			cout << "Balue: " << c;
		}
		void func()
		{
			cout << "\nB: Func";
		}
	};
};
int main()
{
	A a1;
	a1.func1();
	A :: B obj;
	obj.func();
	return 0;
}