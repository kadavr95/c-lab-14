//������������ ������ 14. ������� 1. ������� ������� (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//����������� ���������
#include <stdlib.h>
#include <math.h>
#include <time.h>

int filling(int low, int up, int qty, int *array); //��������� �������
int output(int qty, int *array);
int checksize(int *arraysize);
int QuickSort(int first, int last, int *array, int qty, int *nstage, int *cmpr);
int swap(int *x, int *y);

int main(void)//������� �������
{
	int *array, arraysize,low,up,cmpr=0,nstage=0,cmprt;//����������� ����������
	printf("Enter quantity of elements in array: ");//���� ���������� ��������� � �������
	scanf("%d", &arraysize);
	checksize(&arraysize);
	array = malloc((arraysize+1)*sizeof(int));//�������� �������
	printf("Enter limits: ");//���� ��������
	scanf("%d %d", &low,&up);
	if (low>up)//����� �������� �������
	{
		up=low-up;
		low=low-up;
		up=low+up;
	}
	filling(low,up,arraysize,array);//���������� �������
	printf("Array\n");
	output(arraysize,array);//����� �������
	QuickSort(1,arraysize,array,arraysize,&nstage,&cmpr);//���������� �����
	printf("Quick sort\n");
	output(arraysize,array);//����� �������
	printf("Quantity of comparisons:  %d\n",cmpr);
	cmprt=arraysize*log10(arraysize)/log10(2);
	printf("Computational complexity: %d\n",cmprt);
	fflush(stdin);//�������� �������� ������������
	getchar();
	return 0;
}

int filling(int low, int up, int qty, int *array)//���������� �������
{
	int i;//����������� ����������
	int stime;
	long int ltime;
	ltime=time(NULL);//�������� ��������� ������������������
	stime=(unsigned) ltime/2;
	srand(stime);
	for (i = 1; i <=qty ; i++)//���������� �������
	{
		array[i]=low+(up-low)*rand()/RAND_MAX;
	}
}

int output(int qty, int *array)//����� �������
{
	int i,j,cycles;//����������� ����������
	if (qty>0)
	{
		printf("|   Element   |");
	}
	else
	{
		printf("Array has no elements\n");
	}
	for (i = 1; i <=qty; i++) //���� �� ���� ���������
	{
		printf(" %10d |",i);//����� ������ �������� � �������
		if ((i%5==0)&&(i!=qty)) //����������� ����� ������
		{
			printf("|    Value    |");
			for (j=4; j >=0; j--)//����� ��������
			{
				printf(" %10d |",(array[i-j]));
			}
			printf("|   Element   |");
		}
		else //��� ���������� �������� � �������
		{
			if (i==qty)
			{
				if (i%5!=0)
				{
					printf("\n");
				}
				printf("|    Value    |");//����� ��������
				if (i%5==0)
					cycles=5;
				else
					cycles=(i%5);
				for (j=(cycles-1); j >=0; j--)
				{
					printf(" %10d |",array[i-j]);
				}
				printf("\n\n"); //�������� ������ ������ ����� ������
			}
		}
	}
}

int checksize(int *arraysize)
{
	while (*arraysize<1)//���� �� ����� ������� ���������� �����
	{
		printf("Quantity of elements in array must be more than zero. Enter correct quantity: ");//���� ������� �����
		scanf("%d", &*arraysize);
	}

}

int QuickSort(int first, int last, int *array,int qty, int *nstage, int *cmpr)
{
	int pivot; //���������� ����������
	int l,r;
	l=first;//�������� ������� ���������� �� ���������� ��������
	r=last;
	pivot=array[(l+r)/2]; //����������� �������� ��������
	while (l<=r)//����� ����������� ���������
	{
		while (array[l]<pivot)//���� ������� ������ ��������
		{
			l++;//���������� ������
			*cmpr=*cmpr+1;//��������� ���������� ���������
		}
		while (array[r]>pivot)//���� ������� ������ ��������
		{
			r--;//���������� �������
			*cmpr=*cmpr+1;//��������� ���������� ���������
		}
		if (l<=r)//���� �������
		{
			swap(&array[l],&array[r]); //������������ ���� ���������
			printf("Swap: array[%d]=%d with array[%d]=%d\n",l,array[l],r,array[r]);//����� ������� � �������� ���������
			l++;//���������� ������
			r--;//���������� �������
		}
	}
	*nstage=*nstage+1;//����������� ����� ����������
	printf("End of stage %d\n",*nstage);//����� ����� ����������
	output(qty, array);//����� �������
	if (first<r)//���������� ����� �����
		QuickSort(first,r,array,qty,nstage,cmpr);
	if (l<last)//���������� ������ �����
		QuickSort(l,last,array,qty,nstage,cmpr);
}

int swap(int *x, int *y)//������������ ����������
{
	int temp; //���������� ����������
	temp=*x;  //����� ���������� ����� �������������� ����������
	*x=*y;
	*y=temp;
}

