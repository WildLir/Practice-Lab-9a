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

void Change(int** p, int n)
{
	int i, j,k,g;
	int max=p[0][0];
	int buf;
	for (i = 0; i < n; i++)
		for (j = 0 ; j < n; j++)
		{
			if (max <= p[i][j])
			{
				k = i;
				g = j;
				max = p[i][j];
			}
		}

	if (g > n / 2)
		while (g != n / 2 )
		{
			for (i = 0; i < n - 1; i++)
			{
				buf = p[k][i];
				p[k][i] = p[k][i + 1];
				p[k][i + 1] = buf;
			}
			g--;
		}
	else
		if (g<n/2)
		while (g != n / 2 + 1 )
		{
			for (i = 1; i < n; i++)
			{
				buf = p[k][i];
				p[k][i] = p[k][i-1];
				p[k][i-1] = buf;
			}
			g++;
		}
	g = n / 2;

	if (k > n / 2 )
	{
		while (k != n / 2 )
		{
			for (i = 0; i < n - 1; i++)
			{
				buf = p[i][g];
				p[i][g] = p[i + 1][g];
				p[i + 1][g] = buf;
			}
			k--;
		}
	}
	else 
		if (k < n / 2)
			while (k != n / 2 + 1)
			{
				for (i = 1; i < n; i++)
				{
					buf = p[i][g];
					p[i][g] = p[i - 1][g];
					p[i - 1][g] = buf;
				}
				k++;
			}

	
}

int main()
{
	setlocale(LC_CTYPE, "");
	int** p = 0;
	int n;
	cout << "Введите разрядность матрицы(Должна быть нечетной)" << endl;
	cin >> n;
	while (n % 2 == 0)
	{
		cout << "Разрядность четная, введите другое число" << endl;
		cin >> n;
	}
	input(p, n);
	Change(p, n);
	output(p, n);
}