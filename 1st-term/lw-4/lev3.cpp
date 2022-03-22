#include <iostream>
using namespace std;

int arr_length(int n)
{
	int length = 0;
	while (n != 0)
	{	
		n /= 10;
		length++;
	}
	return length;
}

void funk(int n, int* arr)
{
	int i = 1;
	int l = arr_length(n);
	while (n != 0)
	{
		arr[l - i] = (n % 10) * (n % 10);
		n /= 10;
		i++;
	}
}

int main()
{	
	// Input
	int n;
	cout << "N = "; cin >> n;
	int* arr = new int[arr_length(n)];
	// function call
	funk(n, arr);
	// Output
	for (int i = 0; i < arr_length(n); i++)
		cout << arr[i] << " ";
	delete[] arr;
}