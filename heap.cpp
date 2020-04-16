//Heap Sort

#include<iostream>

using namespace std;

void printArray(int *a);
void swap(int *a, int *b);
void max_heapify(int *a, int n, int i);
void buildMaxHeap(int *a, int n);
void heapSort(int *a, int n)
{
	buildMaxHeap(a,n);
	
	while(n!=0)
	{
		swap(&a[0],&a[n-1]);
		n-=1;
		max_heapify(a,n,0);
	}
}

int main()
{
	//int a[5] = {9,8,7,6,5};
	int a[5] = {8,14,10,16,5};
	cout << "Unsorted : ";
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
	heapSort(a,5);
	//buildMaxHeap(a,5);
	cout << "Sorted : ";
	printArray(a);
	return 0;
}

void printArray(int *a)
{
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int *a, int n, int i)
{
	int largest = i;
	int left = (2*i)+1, right = (2*i)+2;
	if(left<n && a[left]>a[largest])
		largest = left;
	if(right<n && a[right]>a[largest])
		largest = right;
	
	if(largest!=i)
	{
		swap(&a[i],&a[largest]);
		max_heapify(a,n,largest);
	}
}

void buildMaxHeap(int *a, int n)
{
	for(int i=(n/2)-1; i>=0; i--)
		max_heapify(a,n,i);
}
