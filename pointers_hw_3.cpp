#include<iostream>

using namespace std;

int main()
{
	int b = 654;
	int* a = &b;

	cout << *a << endl;
	cout << b << endl;
	cout << &a << endl;

	int* c = &a;

	return 0;
}