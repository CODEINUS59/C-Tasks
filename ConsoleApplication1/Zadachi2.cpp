//Задачи: нахождение по формуле Герона и массивы

#include "stdafx.h"
#include "Zadachi2.h"
#include <iostream>

#define count_of( arg ) ( sizeof( arg ) / sizeof( arg[ 0 ] ) )

using namespace std;


double Geron(double a, double b, double c) {
	
	double square,perim;

	perim = (a + b + c) / 2;

	square = sqrt(perim *((perim - a)*(perim - b)*(perim - c)));

	return square;
}

void paralSquare() {

	int x1, y1, x2, y2, x3, y3, x4, y4;
	double dAB, dBC, dCD, dAD, dBD, dAC;
	double paralS;
	//определю кодировку
	setlocale(0, "");
	//Введем координаты вершин
	cout << "Введите координату x1 " << endl;
	cin >> x1;
	cout << "Введите координату y1 " << endl;
	cin >> y1;
	cout << "Введите координату x2 " << endl;
	cin >> x2;
	cout << "Введите координату y2 " << endl;
	cin >> y2;
	cout << "Введите координату x3 " << endl;
	cin >> x3;
	cout << "Введите координату y3 " << endl;
	cin >> y3;
	cout << "Введите координату x4 " << endl;
	cin >> x4;
	cout << "Введите координату y4 " << endl;
	cin >> y4;
	
	//Найдем длины сторон
	
	dAB = sqrt(pow((x2 - x1), 2)+ pow((y2 - y1),2));
	dBC = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
	dCD = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
	dAD = sqrt(pow((x4 - x1), 2) + pow((y4 - y1), 2));
	// 3 сторона треугольника
	dBD = sqrt(pow((x4 - x2), 2) + pow((y4 - y2), 2));
	dAC = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));

	paralS = Geron(dAB, dBC, dAC) + Geron(dAD, dCD, dAC);

	cout << "Площадь паралеллограма = "<< paralS << endl;	
	system("pause");
}

void anyMassive() {

	const int n = 4;
	const int m = 3;
	int arr[n][m];

	setlocale(0, "");
	printf("Заполните массив %d на %d \n", n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

		}
	}

	cout << "Исходный массив: " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] <<" ";

		}
		cout << endl;
	}

	int *dynamic = new int[m];
	int *redynamic = new int[m];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			if (i % 2 == 0) {

				dynamic[j] = arr[i][j];
				
			};

			
		}
		if (i % 2 == 0) {

			int n = 0;
			for (int i = count_of(dynamic); i >= 0; i--) {

				redynamic[n] = dynamic[i];
				n = n + 1;
			}

			for (int g = 0; g < m; g++) {

				arr[i][g] = redynamic[g];
			}
		}
	}

	cout << "Новый массив: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";

		}
		cout << endl;
	}
	
	system("pause");

}



