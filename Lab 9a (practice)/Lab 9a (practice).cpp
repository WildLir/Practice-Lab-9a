#include<stdio.h>
#include<locale.h>
#include<iostream>
using namespace std;

void input(int**& p, int n)
{
	int i, j;
	p = new int* [n];
	for (i = 0; i < n; i++)
		p[i] = new int[n]();
	cout << "Введите элементы массива" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> p[i][j];
	cout << "Исходная матрица" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}
}

void output(int** p, int n)
{
	int i, j;
	cout << "Полученная матрица" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}
	delete[]p;
}
