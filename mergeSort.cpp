#include<iostream>

using namespace std;

void printArray(int *a)
{
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void merge(int *a1, int l, int h, int mid);
void mergeSort(int *arr, int l, int h)
{
	if(l<h)
	{
		int mid = (l+h)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,h);
		merge(arr,l,h,mid);
	}
}

void merge(int *a1, int l, int h, int mid)
{
	int *res;
	res = (int*)malloc((l+h)*sizeof(int));
	int i = l, j = mid+1, k = 0;
	while(i<=mid && j<=h)
	{
		if(a1[i]<a1[j])
			res[k++] = a1[i++];
		else
			res[k++] = a1[j++];
	}
	while(i<=mid)
		res[k++] = a1[i++];
	while(j<=h)
		res[k++] = a1[j++];
	for(int w = l; w<k; w++)
		a1[w] = res[w];
}

int main()
{
	int a[5] = {9,8,7,6,5};
	cout << "Unsorted : ";
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
	mergeSort(a,0,4);
	cout << "Sorted : ";
	printArray(a);
	return 0;
}
