#include <iostream>
using namespace std;


double rec(double n) {
	if (n == 1) {
		return (2 / 3.);
	}
	return 1 / (n + rec(n - 1));
}


double cycle(double n) {
	double a = 1;
	double b = 2;
	double c = 1;

	while (c < n + 1)
	{
		b = (a / b) + c;
		c++;
	}
	return (1 / b);
}


int main() {
	double n;
	cout << "Enter N: "; 
	cin >> n;

	cout << "====================================" << endl;
	cout << "Recursion:       " << rec(n) << endl;
	cout << "Not recursion:   " << cycle(n);
}
