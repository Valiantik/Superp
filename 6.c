#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

/*
* 
*/

// Функция возвращает псевдослучайное число r: left <= r <= right
int randlr(int left, int right);

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	
	printf("Введите A: ");
	
	// Левая граница для генерации чисел
	int a;
	scanf("%d", &a);
	
	printf("Введите B(B > A): ");
	
	// Правая граница для генерации числе
	int b;
	do
	{		
		scanf("%d", &b);
		if (b < a)
			printf("Ошибка ввода! Повторите ввод: ");
	}while(b < a);
	
	printf("Введите кол-во строк m: ");
	
	int m = 1;
	do
	{
		if (m < 1)
			printf("Ошибка ввода! Повторите ввод: ");
		
		scanf("%d", &m);
	}while(m < 1); 
	
	printf("Введите кол-во столбцов n: ");
	
	int n = 1;
	do
	{
		if (n < 1)
			printf("Ошибка ввода! Повторите ввод: ");
		
		scanf("%d", &n);
	}while(n < 1);
	
	int matr[m][n];
	
	int i, j;
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			matr[i][j] = randlr(a, b);
			
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", matr[i][j]);
		printf("\n");
	}
	
	int min_val = matr[0][0], min_i = 0;
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (matr[i][j] <= min_val)
			{
				min_val = matr[i][j];
				min_i = i;
			}
	
	for (i = 0, j = 0; j < n; j++)
	{
		int temp = matr[i][j];
		matr[i][j] = matr[min_i][j];
		matr[min_i][j] = temp;
	}
	
	printf("\n Была заменена %d строка.\n\n", min_i + 1);	
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", matr[i][j]);
		printf("\n");
	}
	
	getch();
	return 0;
}

// Функция возвращает псевдослучайное число r: left <= r <= right
int randlr(int left, int right)
{
	// Генерируем число от left до right включая эти числа
	int result = rand() % (right - left +1) + left;
	
	return result;
}
