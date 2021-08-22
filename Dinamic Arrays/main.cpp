#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value); // ��������� �������� � ����� �������
int* push_front(int arr[], int& n, int value); // ��������� �������� � ������ �������
int* insert(int arr[], int& n, int index, int value); // ��������� �������� � ������ �� �������
int* pop_back(int arr[], int& n);	// ������� ��������� ������� �������
int* pop_front(int arr[], int& n);	// ������� ������� ������� �������
int* erase(int arr[], int& n, int index); // ������� ������� � ��������� ��������


void main()
{
	setlocale(0,"rus");
	int n; // ������ �������

	cout << "������� ������ �������: ";
	cin >> n;
	int* arr = new int[n] {};//{}; // ������� ������ �� ����� �������������������. �������� new �������� 
	                          // ������ ��� n ��������� ���� int � ���������� ����� ���������� ������.
	                          // ���� ����� �� ����������� ������ ��������� *arr
	FillRand(arr, n);
	Print(arr, n);

    // ������� 1 ������� � ������, �� ��������� ������ - ��� � ���� ����������. ����� �������������� ������!!!!!!!!
    // �.�.���� �� �������������� ������,�� ������ ������ ����� �������.
/*	arr[n] = 123;
	n++;
	Print(arr, n);
 */
	int value;  // ����������� ��������
	cout << "\n������� ����������� �������� � ����� �������: "; 
	cin >> value;
	arr = push_back(arr, n, value); 
	Print(arr, n);

	cout << "\n������� ����������� �������� � ������ �������: "; 
	cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;  
	cout << "\n������� ������ ��������, ��� ���������� � ������ ��������: "; 
	cin >> index;
	cout << "������� ����������� ��������: "; 
	cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	
	cout << "\n�������� ���������� �������� �������: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "\n�������� ������� �������� �������: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "\n������� ������ �������� ��� �������� �� ������� ��������: "; 
	cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0;i < n;i++)
	{
		// [] - �������� �������������� (subscript operator)
		arr[i] = rand()%100;
	}
	cout << endl;
}
void Print(int arr[], const int n)
{
	for (int i = 0;i < n;i++)
	{
		// [] - �������� �������������� (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
    for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer; // �������� �������� ������ ��������
	arr[n] = value;
	n++; 

	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int index, int value)
{
	if (index >= n)
	return arr;
	int* buffer = new int[n + 1];
	int i = 0;
	for (; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (; i < n; i++) // ����� ������� ��������
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;

	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;

	return buffer;
}
int* erase(int arr[], int& n, int index)
{
	if (index < 0 || index >= n)
	return arr;
	int* buffer = new int[--n];
	int i = 0;
	for (; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;

	return buffer;
}