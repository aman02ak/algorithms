#include<iostream>
#include<cstring>
using namespace std;


void printArray(int *a, int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int getMax(int *a, int n)
{
	int max = a[0];
	for(int i=1; i<n; i++)
		if(a[i]>max)
			max = a[i];
			
	return max;
}

void countSort(int *a, int n, int idx)
{
	int k = 11;
	int *c = (int*)malloc(k*sizeof(int));
	memset(c,0,sizeof(c));
	for(int i=0; i<n; i++)
		c[((a[i]/idx)%10)] += 1;
		
	for(int i=1; i<k; i++)
		c[i] = c[i-1]+c[i];
	
	int *b = (int*)malloc(n*sizeof(int));
	for(int i=n-1; i>=0; i--)
	{
		b[c[(a[i]/idx)%10]-1] = a[i];
		c[(a[i]/idx)%10] -= 1;
	}
	
	for(int i=0; i<n; i++)
		a[i] = b[i];
}

void radixSort(int *a, int n)
{
	int max = getMax(a,n);
	for(int i=1; max/i>0; i*=10)
		countSort(a,n,i);
}

int main()
{
	int a[6] = {170,45,75,90,802,2};
	cout << "Unsorted Array : ";
	printArray(a,6);
	radixSort(a,6);
	cout << "Sorted Array : ";
	printArray(a,6);
	return 0;
}
