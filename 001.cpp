#include <stdio.h>
#include <cstring>
#include <sstream>
#include <iostream>
#include <utility>

using namespace std;

bool read(int *array, int size)
{
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	for (int i = 0; i < size; ++i)
	{
		if (!(stream >> array[i]))
		{
			cout << "An error has occured while reading input data." << endl;
			return false;
		}
		if (!(stream.eof()))
		{
		   cout << "An error has occured while reading input data." << endl;
		   return false; 
		}
	}
	return true;
}

void Sort(int *arr, int n)
{
	int i;
	for (i = 0; i < n/2; i++)
	{
		swap(arr[i], arr[n - i - 1]);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << ' ';
}

int main()
{
	int size;
	string number;
	getline(cin, number);
	istringstream stream(number);
	if (!(stream >> size))
	{
		cout << "An error has occured while reading input data." << endl;
		return -1;
	}
	if (size < 0)
	{
		cout << "An error has occured while reading input data." << endl;
		return -2;
	}
	int *arr = new int[size];
	if (read(arr, size))
	{
		Sort(arr, size);
		cout << "Sorted array: \n";
		printArray(arr, size);
	}

	cin.get();
	return 0;
}
