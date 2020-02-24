#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("Exit");
		return 1;
	}
	/*========================================================*/
	srand(time(NULL));
	int i = 0; //счетсик цикла
	int kolzn = 0; // переменная равна колличеству знаков в n
	int n, dopn;//колличество чисел
	double RAND_MAX_D = RAND_MAX;
	double Min, Max;// левая и правая границы генерации чисел
	double sum = 0; // переменная хранящая результат
	double* Arr;// указатель на динамический массив
	n = atoi(argv[1]);
	dopn = n;
	Min = atof(argv[2]);
	Max = atof(argv[3]);
	Arr = (double*)malloc(n * sizeof(double));
	/*===================================================*/
	while (dopn > 0)
	{
		dopn = dopn / 10;
		kolzn++;
	}
	/*========================================================*/
	for (i = 0; i < n; i++)
	{
		Arr[i] = (rand() / RAND_MAX_D) * (Max - Min) + Min;
		printf("%lf\n", Arr[i]);
	}
	/*=======================================================*/
	for (i = 0; i < n; i++)
	{
		int ind;
		ind = (int)((Arr[i] - trunc(Arr[i])) * pow(10, kolzn));
		if ((ind < n) && (ind > 0))
		{
			sum = sum - Arr[ind];
			Arr[ind] = 0;
		}
	}
	/*=======================================================*/
	for (i = 0; i < n; i++)
	{
		sum = sum + Arr[i];
	}

	printf("%lf", sum);
}

