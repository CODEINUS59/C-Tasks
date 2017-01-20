// Задачи Вахрушев.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> 


using namespace std;
//Найти сумму ряда Фибоначчи
int Fib(int i)
{
	int f1 = 0;
	int f2 = 1;
	int newest;
	int sum = 1;

	if (i < 1)
	{
		return 0;
	}

	if (i == 1)
	{
		cout << "0\n";
		cout << "1\n";
	}
	if (i > 1)
	{
		cout << "0 \n1 \n";
		for (int j = 1; j < i; j++)
		{
			newest = f1 + f2;
			cout << newest << "\n";
			f1 = f2;
			f2 = newest;
			sum = sum + newest;
		}
	}
	printf("Sum of sequence is: %d \n", sum);
	return 0;
};

void psequence()
{

	int input;
	char choise;

	cout << "Enter you sequence value: ";
	cin >> input;

	Fib(input);


	cout << "Try again? Y/N: ";
	cin >> choise;


	while (choise == 'y' || choise == 'Y')
	{
		cout << "\nEnter you sequence value: ";
		cin >> input;
		Fib(input);
		cout << "Try again? Y/N: ";
		cin >> choise;
	}
	system("Pause");
}

int lucky_ticket()
{
	int sum = 0;
	int i, j, k;
	int ticklen[6];
	for (i = 0; i <= 999999; i++)
	{
		for (k = i, j = 0; j < 6; j++, k /= 10)
		{
			ticklen[j] = k % 10;
		}
		if (ticklen[0] + ticklen[1] + ticklen[2] == ticklen[3] + ticklen[4] + ticklen[5])
		{
			++sum;
		}
	}
	return sum;
}

void sum_lucky()
{
	setlocale(0, "");
	int kolvo = lucky_ticket();
	cout << "Количество счастливых билетов: " << kolvo << endl;
	system("pause");
}

int main()
{
	//Найти сумму ряда Фибоначчи
	psequence();
	//Найти все счастливые билеты
	//sum_lucky();
	return 0;
}
