#include <iostream>

using namespace std;


void Exchange(int& a, int& b); 

void main()
{
	setlocale(0, "rus");

	/*// ������
	int a = 2;
	int& ra=a;
	ra += 3;
	cout << a << endl;
	cout << ra << endl;
	cout << &a << endl; // ������ ����� �����
	cout << &ra << "\n"<< endl; // ������� �������������� ������, � ����� ����� ����� ��������
	//--------------------------------------------------------------------------------------//*/

	setlocale(0, "rus");
	int a = 2;
	int b = 3;

	cout << a << "\t" << b << endl;

	Exchange(a, b); 
	cout << a << "\t" << b << endl;
}

void Exchange(int& a, int& b) 
{
	int buffer = a; 
	a = b;
	b = buffer;
}
