#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

/*
* ��������� ��������� ������� ����������� �������,
* � ������� ��������� ������� ��� �������.
*/
//��������� �����
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	printf("������� ������ ���������� ������� (N*N, ���� �����, �� N = 0): ");	
	
	// ������ ����������� ����������� (n*n) �������.
	int n;
	do
	{
		if (n < 0)
			printf("������ �����! ��������� ����(N >= 0): ");
		
		scanf("%d", &n);	
	}while(n < 0);
	
	if (n == 0)
		return 0;
	 
	printf("�������:\n\n");
	// ��������� ��������� ������ �������� n*n
	int matr[n][n];
	
	// �������� �����:
	// 	i - ������
	//	j - �������
	int i, j;
	
	// � ����� ������������� � ������
	// � � ������ ������ ��������� �� ��������
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			// ���� j = i, �� ������� ������������� �� ������� ���������
			// ����� ���� j ������ ��� i, �� ���� ���������� ������� �� j ����������� �� 1
			// ����� 0
			if (j == i)
				matr[i][j] = 1;
			else if (j > i)
				matr[i][j] = matr[i][j-1] + 1;
			else
				matr[i][j] = 0;
		}
	}
	
	// ������� ������� �� �����
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", matr[i][j]);
		printf("\n");
	}
	
	getch();	
	return 0;
}
