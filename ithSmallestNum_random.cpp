#include<iostream>
using namespace std;

void printArray(int *a);
void swap(int *a, int *b);

int rand_partition(int *a, int l, int h)
{
	int k = rand()%(h-l)+l;
	swap(&a[l],&a[k]);
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

int ithSmallest(int *a, int l, int h, int i)
{
	if(l>=h)
		return a[l];
	int r = rand_partition(a,l,h);
		
	int k = r+1; //rank of element
	if(i==k)
		return a[i-1];
	else if(i<k)
		return ithSmallest(a,l,r-1,i);
	else if(i>k)
		return ithSmallest(a,r+1,h,i);
}

int main()
{
	int a[10] = {170,45,75,90,802,2,200,180,3,56};
	cout << "Array : ";
	printArray(a);
	int n = 10;
	cout << "Enter for i ";
	int i;
	cin >> i;
	int ans = ithSmallest(a,0,9,i);
	cout << "Found, " << i << "th smallest value = " << ans << endl;
	return 0;
}
//#######################################################################################################################
//#######################################################################################################################

void printArray(int *a)
{
	for(int i=0; i<10; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
