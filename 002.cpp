#include <stdio.h>
#include <cstring>
#include <sstream>
#include <iostream>
#include <utility>

using namespace std;

bool read(int *array, unsigned int size)
{
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	for (unsigned int i = 0; i < size; ++i)
	{
		if (!(stream >> array[i]))
		{
			cout << "An error has occured while reading input data." << endl;
			return false;
		}
	}
	return true;
}

void Sort(int *arr, int n, int sdv)
{
	int i;
	int *arrL = new int[n - sdv];
	int *arrR = new int[sdv];
	for (i = 0; i < n; ++i) 
	{
		if (i < n - sdv) 
		{
			arrL[i] = arr[i];
		}
		else {
			arrR[i + sdv - n] = arr[i];
		}
	}
	for (i = 0; i < (n - sdv) / 2; ++i) 
	{
		swap(arrL[i], arrL[n - sdv - 1 - i]);
	}
	for (i = 0; i < sdv / 2; ++i) 
	{
		swap(arrR[i], arrR[sdv - 1 - i]);
	}
	for (i = 0; i < n; ++i) 
	{
		if (i < n - sdv) 
		{
			arr[i] = arrL[i];
		}
		else 
		{
			arr[i] = arrR[i + sdv - n];
		}
	}
	for (i = 0; i < n / 2; ++i) {
		swap(arr[i], arr[n - 1 - i]);
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
		int sdv;
		string s1;
		getline(cin, s1);
		istringstream stream1(s1);
		if (!(stream1 >> sdv) || (sdv<0)) 
		{
			cout << "An error has occured while reading input data." << endl;
			return -3;
		}
		Sort(arr, size, sdv);
		cout << "Sorted array: \n";
		printArray(arr, size);
	}
	cin.get();
	return 0;
}
