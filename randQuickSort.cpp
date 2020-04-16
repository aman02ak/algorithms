//Randomized Quick Sort

#include<iostream>

using namespace std;

void printArray(int *a)
{
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *a, int l, int h)
{
	int x = a[l];
	int i = l;
	for(int j=l+1; j<=h; j++)
	{
		if(a[j]<x)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[l],&a[i]);
	return i;
}

void quickSort(int *a, int l, int h)
{
	if(l>=h)
		return;
	else
	{
		int k = rand()%(h-l)+l;
		swap(&a[l],&a[k]);
		int r = partition(a,l,h);
		quickSort(a,l,r-1);
		quickSort(a,r+1,h);
	}
}

int main()
{
	int a[5] = {9,8,7,6,5};
	//int a[5] = {8,14,10,16,5};
	cout << "Unsorted : ";
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
	quickSort(a,0,4);
	cout << "Sorted : ";
	printArray(a);
	return 0;
}
