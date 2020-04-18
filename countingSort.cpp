//Counting Sort

#include<iostream>

using namespace std;

void printArray(int *a, int n);
void swap(int *a, int *b);
void countSort(int *a, int n)
{
	int k = 20;
	int *c = (int*)malloc(k*sizeof(int));
	int *b = (int*)malloc(n*sizeof(int));
	for(int i=0; i<k; i++)
		c[i] = 0;
	for(int i=0; i<n; i++)
		c[a[i]] += 1;
	for(int i=1; i<k; i++)
		c[i] = c[i-1]+c[i];
	for(int i=n-1; i>=0; i--)
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]] -= 1;
	}
	for(int i=0; i<n; i++)
		a[i] = b[i];
}


int main()
{
	//int a[5] = {9,8,7,6,5};
	int a[5] = {8,14,10,16,5};
	cout << "Unsorted : ";
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
	countSort(a,5);
	cout << "Sorted : ";
	printArray(a,5);
	return 0;
}

void printArray(int *a, int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
