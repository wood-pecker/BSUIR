#include <iostream>
using namespace std;

// Choose the option: 
// Use TRUE to generate values randomly
// Use FALSE to input the values from the keyboard
bool setting = false;

void generate_randomly(int arr[20], int n)
{
	#include <stdlib.h>
	cout << "Generated array (Random):  ";
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() + i) % 7 - (n % 2);
		cout << arr[i] << " ";
	}
	cout << endl;
}


void keyboard_input(int arr[20], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = "; cin >> arr[i];
	}
}


int main() 
{	
	int n = 0, arr[20], pos_zer = 404, pos_max = 0, quantity = 0, sum = 0, max, i;
	cout << "N = "; cin >> n;
	
	if (setting) generate_randomly(arr, n);
	else keyboard_input(arr, n);
	cout << "=============================================" << endl;
	
	// Find 0(zero)
	for (i = n - 1; i >= 0; i--)
	{
		if (arr[i] == 0)
		{
			pos_zer = i;
			break;
		}
	}

	// Find max
	max = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			quantity = 1;
			pos_max = i;
		}
		else if (arr[i] == max) quantity += 1;
	}

	// Calculate the answer
	if (pos_zer == 404) cout << "There are no zero in the array!" << endl;
	else if (quantity != 1) cout << "There are several maximums. Must be one!" << endl;
	else if (abs(pos_zer - pos_max) <= 1) cout << "There are no elements between max and zero!" << endl;
	else
	{	
		if (pos_max < pos_zer)
		{
			for (i = pos_max + 1; i < pos_zer; i++)
				{
					sum += arr[i];
				}
		}
		else
		{
			for (i = pos_zer+ 1; i < pos_max; i++)
			{
				sum += arr[i];
			}
		}
		cout << "Sum is " << sum << endl;
	}
	cout << "=============================================" << endl;
}