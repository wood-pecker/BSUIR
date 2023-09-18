
#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
using namespace std;


struct Person
{
	char fam[20];
	double gr, fiz, mat, inf;
	double sr;
};

double inp()
{
	char s[30];
	int i = 0;
	double x;
	while (1)
	{
		s[i] = _getch();
		if (s[i] == 13) break;
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			continue;
		}
		cout << s[i];
		i++;
	}
	s[i] = '\0';
	x = strtod(s, NULL);
	cout << endl;
	return x;
}

void vvod(char cs)
{
	ofstream fout;
	if (cs == '1')
	{
		fout.open("myFILE.txt");
	}

	if (cs == '2')
	{
		fout.open("myFILE.txt", ofstream::app);
	}

	Person stud;
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		cout << "Сколько студентов всего?" << endl;
		int kol_stud;
		cin >> kol_stud;
		for (int i = 1; i <= kol_stud; i++)
		{
			cout << "Фамилия:" << endl;
			cin >> stud.fam;
			cout << "Номер группы:" << endl;
			stud.gr = inp();
			cout << "Оценка по физике:" << endl;
			cin >> stud.fiz;
			cout << "Оценка по математике:" << endl;
			stud.mat = inp();
			cout << "Оценка по информатике:" << endl;
			stud.inf = inp();

			stud.sr = (stud.inf + stud.mat + stud.fiz) / 3;

			OemToCharA(stud.fam, stud.fam);

			fout.write((char*)&stud, sizeof(Person));
		}

	}
	fout.close();
	cout << "Информация добавлена!!!";
	system("pause");
	system("cls");
}


void prosmotr()
{
	ifstream fin;
	fin.open("myFILE.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		Person stud;
		while (fin.read((char*)&stud, sizeof(Person)))
		{
			cout << "Фамилия: " << stud.fam << endl <<
				"Номер группы: " << stud.gr << endl <<
				"Оценки за семестр:" << endl <<
				"Физика: " << stud.fiz << endl <<
				"Математика: " << stud.mat << endl <<
				"Информатика: " << stud.inf << endl <<
				"Средний балл: " << stud.sr << endl << endl;
		}

	}
	fin.close();
	system("pause");
}



void clear()
{
	ofstream fout;
	fout.open("task.txt");
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		fout << "";
	}
	fout.close();
	cout << "Файл для печати очищен." << endl;
	system("pause");
	system("cls");
}

void task()
{
	ifstream fin;
	ofstream fout;
	fin.open("myFILE.txt");
	fout.open("task.txt");
	if (!fin.is_open() || !fout.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		Person stud;
		while (fin.read((char*)&stud, sizeof(Person)))
		{
			if (stud.inf == 9 || stud.inf == 10)
			{
				fout << "Фамилия: " << stud.fam << endl <<
					"Номер группы: " << stud.gr << endl <<
					"Оценки за семестр:" << endl <<
					"Физика: " << stud.fiz << endl <<
					"Математика: " << stud.mat << endl <<
					"Информатика: " << stud.inf << endl <<
					"Средний балл: " << stud.sr << endl << endl;
			}
		}

	}
	cout << "Файл для печати создан !!!" << endl;
	fin.close();
	fout.close();
	system("pause");
	system("cls");
}

void prosmotr_task()
{
	ifstream fin;
	fin.open("task.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		char buf;
		while (fin.get(buf))
		{
			cout << buf;
		}
	}
	fin.close();
	system("pause");
	system("cls");
}

int main()
{
	setlocale(LC_ALL, "ru");
	bool flag = 1;
	do
	{
		cout << " Выбери пункт:\n 1. Создание файла.\n 2. Просмотр файла.\n 3. Добавить студента.\n 4. Найти данные студентов, имеющих оценку 9 или 10 по информатике.\n 5. Просмотр файла ИДЗ. \n 6. Выход\n" << endl;
		switch (_getch())
		{
		case '1': system("cls"); cout << "Внесённые до этого данные будут удалены, Вы уверены, что хотите продолжить???" << endl << "1. Да" << endl << "Default - Отмена!!!" << endl; if (_getch() == '1') vvod('1'); else system("cls"); break;
		case '2': system("cls"); prosmotr(); system("cls"); break;
		case '3': system("cls"); vvod('2'); break;
		case '4': system("cls"); task(); break;
		case '5': system("cls"); prosmotr_task(); break;
		case '6': system("cls"); cout << "Удачного дня!";  flag = 0; break;
		default:  system("cls"); cout << "Выбери цифру от 1 до 6!" << endl;
		}
	} while (flag);
	return 0;
}
