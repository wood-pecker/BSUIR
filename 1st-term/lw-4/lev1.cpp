#include <iostream>
using namespace std;

int main() 
{	
	int n = 0, pos = 0, quantity = 0, sum = 0;
	cout << "N = "; cin >> n;
	
	int arr[20];
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = "; cin >> arr[i];
	}

	int min = arr[0];
	for (int i = 0; i < n; i++)
	{	
		if (arr[i] == min) quantity++;
		if (arr[i] < min) {
			min = arr[i];
			pos = i;
			quantity = 1;
		}
	}

	if (pos == n - 1) cout << "The minimum element is the last one!" << endl;
	if (quantity > 1) cout << "The minimum element must be the only one!" << endl;
	if (quantity == 1 && pos != n-1)
	{
		for (int i = pos + 1; i < n; i++)
			sum += arr[i];
		cout << "Sum = " << sum << endl;
	}
}