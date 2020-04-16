#include<iostream>

using namespace std;

void printArray(int *a)
{
	for(int i=0; i<5; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int binary_search(int *arr, int l, int h, int key)
{
	if(l<=h)
	{
		int mid = (l+h)/2;
		if(key==arr[mid])
			return mid;
		else if(key<arr[mid])
			return binary_search(arr,l,mid-1,key);
		else if(key>arr[mid])
			return binary_search(arr,mid+1,h,key);
	}
	else
	
	{
		cout << l << ' ' << h << endl;
		return -1;}
}

int main()
{
	int a[5] = {1,2,3,4,5};
	cout << "Array : ";
	printArray(a);
	
	cout << "Enter Key : ";
	int key;
	cin >> key;
	int found = binary_search(a,0,5,key);
	if(found!=-1)
		cout << "Found, Position = " << found << endl;
	else
		cout << "NOT FOUND" << found << endl;
	return 0;
}
