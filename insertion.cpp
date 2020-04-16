#include<iostream>

using namespace std;

void insertionSort(int *arr, int n)
{
	for(int j=1; j<5; j++)
	{
		int key = arr[j];
		int i = j-1;
		while(i>=0 && key<arr[i])
		{
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
	cout << "Sorted : ";
	for(int i=0; i<5; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int main()
{
	int a[5] = {9,8,7,6,5};
	cout << "Unsorted : ";
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
	insertionSort(a,5);
	return 0;
}
