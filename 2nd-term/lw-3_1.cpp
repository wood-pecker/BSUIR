#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


struct Stack
{
	double data;
	Stack* next;
};

Stack* top = NULL;


void push(int input)
{
	Stack* new_el = new Stack;
	new_el->data = input;
	new_el->next = top;
	top = new_el;
	cout << "Done! " << input << " has been added to Stack." << endl;
	system("pause");
	system("cls");
}


void create()
{
	int n, x;
	cout << "N = "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Element " << i + 1 << " = "; cin >> x;
		Stack* new_el = new Stack;
		new_el->data = x;
		new_el->next = top;
		top = new_el;
	}
	cout << "Done!" << endl;
	system("pause");
	system("cls");
}


void pop()
{
	Stack* buf = top->next;
	cout << "Element " << top->data << " has been deleted." << endl;
	delete top;
	top = buf;
	system("pause");
	system("cls");
}


void show()
{
	Stack* buf = top;
	do
	{
		cout << buf->data << endl;
		buf = buf->next;
	} while (buf != NULL);
	system("pause");
	system("cls");
}


void average()
{
	double sum = 0;
	int quantity = 0;
	Stack* buf = top;
	while (buf != NULL)
	{
		sum += buf->data;
		quantity++;
		if (buf->next == NULL) break;
		else buf = buf->next;
	}
	cout << "Avarage is " << sum / quantity << endl;
	buf->data = sum / quantity;
	system("pause");
	system("cls");
}


int enter()
{
	cout << "Enter an element you need to add:" << endl;
	int n; cin >> n;
	return n;
}


int main()
{
	bool flag = true;
	do
	{
		cout << "Select function:\n 1. Create Stack\n 2. Push \n 3. Pop\n 4. Show stack\n 5. Calculate avarage and replace on it first element\n 6. Exit" << endl;
		switch (_getch())
		{
		case '1': system("cls"); create(); break;
		case '2': system("cls"); push(enter()); break;
		case '3': system("cls"); pop(); break;
		case '4': system("cls"); show(); break;
		case '5': system("cls"); average(); break;
		case '6': system("cls"); flag = false; break;
		default: system("cls");
		}

	} while (flag);
	return 0;
}