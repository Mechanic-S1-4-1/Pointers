#include <iostream>

using namespace std;

void Exchange(int* a, int* b); // ������ ����������� int a � int b


void main()
{

	setlocale(0, "rus");
	int a = 2;
	int b = 3;

	cout << a <<"\t" <<b<< endl;
	Exchange(&a, &b); // ���� � ������� ������������� �� ��������, � ����� ������������ ���������� 
	                  // �� ������ & - �������� ������ ������

	                                /*��������� - ��� � ���� �����, ��� ����� = ��������� �.�. int*, char* �.�.�. ��� ���
									 ���������. ���� ��������� ����� � ������ �.�. ���� ���������� ������� ������ ����� 
									 - ��� �������� ����������, ����� � ��� ���� ����� ����� �����.
									 � * ����� ���� ������������ �.�. �� ����� ��� �� ������-�� ������ ����� ������ ��� ��� 
									 �������� � �� ����� ������ ��� ��� �� �������� �.�. ��������� ���, �������� ���,����
									 ���������� ��� �.� �� �� ����� ��������, �� ����� �����, �� �������� ���(��������)
									 �����, ����� ��� ��� �� ������ �������� ������������� ����� ������ � �������� �������� 
									 ����� ������, � ��� ������ � ��� ��� ����� � ������ ����������.*/
	cout << a << "\t" <<b<< endl;
}

void Exchange(int *a, int *b) // � ������ ������ ���������� ��������� ����� �����������
{
	int buffer = *a; // �������������� a � b
	*a = *b;
	*b = buffer;
}




