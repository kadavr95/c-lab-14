//Лабораторная работа 14. Вариант 1. Яскович Дмитрий (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//подключение библиотек
#include <stdlib.h>
#include <math.h>
#include <time.h>

int filling(int low, int up, int qty, int *array); //прототипы функций
int output(int qty, int *array);
int checksize(int *arraysize);
int QuickSort(int first, int last, int *array, int qty, int *nstage, int *cmpr);
int swap(int *x, int *y);

int main(void)//главная функция
{
	int *array, arraysize,low,up,cmpr=0,nstage=0,cmprt;//определение переменных
	printf("Enter quantity of elements in array: ");//ввод количества элементов в массиве
	scanf("%d", &arraysize);
	checksize(&arraysize);
	array = malloc((arraysize+1)*sizeof(int));//создание массива
	printf("Enter limits: ");//ввод пределов
	scanf("%d %d", &low,&up);
	if (low>up)//обмен пределов местами
	{
		up=low-up;
		low=low-up;
		up=low+up;
	}
	filling(low,up,arraysize,array);//заполнение массива
	printf("Array\n");
	output(arraysize,array);//вывод массива
	QuickSort(1,arraysize,array,arraysize,&nstage,&cmpr);//сортировка Хоара
	printf("Quick sort\n");
	output(arraysize,array);//вывод массива
	printf("Quantity of comparisons:  %d\n",cmpr);
	cmprt=arraysize*log10(arraysize)/log10(2);
	printf("Computational complexity: %d\n",cmprt);
	fflush(stdin);//ожидание действий пользователя
	getchar();
	return 0;
}

int filling(int low, int up, int qty, int *array)//заполнение массива
{
	int i;//определение переменных
	int stime;
	long int ltime;
	ltime=time(NULL);//создание случайной последовательности
	stime=(unsigned) ltime/2;
	srand(stime);
	for (i = 1; i <=qty ; i++)//заполнение массива
	{
		array[i]=low+(up-low)*rand()/RAND_MAX;
	}
}

int output(int qty, int *array)//вывод массива
{
	int i,j,cycles;//определение переменных
	if (qty>0)
	{
		printf("|     Element      |");
	}
	else
	{
		printf("Array has no elements\n");
	}
	for (i = 1; i <=qty; i++) //цикл по всем элементам
	{
		printf(" %3d |",i);//вывод номера элемента в массиве
		if ((i%10==0)&&(i!=qty)) //определение конца строки
		{
			printf("|      Value       |");
			for (j=9; j >=0; j--)//вывод значений
			{
				printf(" %3d |",(array[i-j]));
			}
			printf("|     Element      |");
		}
		else //или последнего элемента в массиве
		{
			if (i==qty)
			{
				if (i%10!=0)
				{
					printf("\n");
				}
				printf("|      Value       |");//вывод значений
				if (i%10==0)
					cycles=10;
				else
					cycles=(i%10);
				for (j=(cycles-1); j >=0; j--)
				{
					printf(" %3d |",array[i-j]);
				}
				printf("\n\n"); //создание пустой строки после вывода
			}
		}
	}
}

int checksize(int *arraysize)
{
	while (*arraysize<1)//пока не будет введено правильное число
	{
		printf("Quantity of elements in array must be more than zero. Enter correct quantity: ");//ввод другого числа
		scanf("%d", &*arraysize);
	}

}

int QuickSort(int first, int last, int *array,int qty, int *nstage, int *cmpr)
{
	int pivot; //объявление переменных
	int l,r;
	l=first;//передача внешних переменных во внутренние счётчики
	r=last;
	pivot=array[(l+r)/2]; //определение опорного значения
	while (l<=r)//поиск пересечения счётчиков
	{
		while (array[l]<pivot)//пока элемент меньше опорного
		{
			printf("Swap: array[%d]=%d with array[%d]=%d\n",l,array[l],r,array[r]);//вывод номеров и значений элементов
			l++;//увеличение левого
			*cmpr=*cmpr+1;//изменение количества сравнений
		}
		while (array[r]>pivot)//пока элемент больше опорного
		{
			printf("Swap: array[%d]=%d with array[%d]=%d\n",l,array[l],r,array[r]);//вывод номеров и значений элементов
			r--;//уменьшение правого
			*cmpr=*cmpr+1;//изменение количества сравнений
		}
		if (l<=r)//если найдено
		{
			swap(&array[l],&array[r]); //перестановка двух элементов
			printf("Swap: array[%d]=%d with array[%d]=%d\n",l,array[l],r,array[r]);//вывод номеров и значений элементов
			l++;//увеличение левого
			r--;//уменьшение правого
		}
	}
	*nstage=*nstage+1;//определение этапа сортировки
	printf("End of stage %d\n",*nstage);//вывод этапа сортировки
	output(qty, array);//вывод массива
	if (first<r)//сортировка левой части
		QuickSort(first,r,array,qty,nstage,cmpr);
	if (l<last)//сортировка правой части
		QuickSort(l,last,array,qty,nstage,cmpr);
}

int swap(int *x, int *y)//перестановка переменных
{
	int temp; //объявление переменных
	temp=*x;  //обмен переменных через дополнительную переменную
	*x=*y;
	*y=temp;
}


