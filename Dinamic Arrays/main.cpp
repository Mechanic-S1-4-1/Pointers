#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value); // Добавляет значение в конец массива
int* push_front(int arr[], int& n, int value); // Добавляет значение в начало массива
int* insert(int arr[], int& n, int index, int value); // Вставляет значение в массив по индексу
int* pop_back(int arr[], int& n);	// Удаляет последний элемент массива
int* pop_front(int arr[], int& n);	// Удаляет нулевой элемент массива
int* erase(int arr[], int& n, int index); // Удаляет элемент с указанным индексом


void main()
{
	setlocale(0,"rus");
	int n; // Размер массива

	cout << "Введите размер массива: ";
	cin >> n;
	int* arr = new int[n] {};//{}; // добавив скобки мы можем проинициализировать. Оператор new выделяет 
	                          // память для n элементов типа int и возвращает адрес выделенной памяти.
	                          // Этот адрес мы присваиваем нашему указателю *arr
	FillRand(arr, n);
	Print(arr, n);

    // Добавим 1 элемент в массив, но возникает ошибка - это и есть исключение. Нужно переопределить память!!!!!!!!
    // т.е.если мы переопределяем память,то старый массив нужно удалить.
/*	arr[n] = 123;
	n++;
	Print(arr, n);
 */
	int value;  // Добавляемое значение
	cout << "\nВведите добавляемое значение в конец массива: "; 
	cin >> value;
	arr = push_back(arr, n, value); 
	Print(arr, n);

	cout << "\nВведите добавляемое значение в начало массива: "; 
	cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;  
	cout << "\nУкажите индекс элемента, для добавления в массив значения: "; 
	cin >> index;
	cout << "Введите добавляемое значение: "; 
	cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	
	cout << "\nУдаление последнего элемента массива: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "\nУдаление первого элемента массива: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "\nУкажите индекс элемента для удаления из массива значения: "; 
	cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0;i < n;i++)
	{
		// [] - оператор интексирования (subscript operator)
		arr[i] = rand()%100;
	}
	cout << endl;
}
void Print(int arr[], const int n)
{
	for (int i = 0;i < n;i++)
	{
		// [] - оператор интексирования (subscript operator)
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
	arr = buffer; // заменяем исходный массив буферным
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
	for (; i < n; i++) // кусок массива сдвигаем
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