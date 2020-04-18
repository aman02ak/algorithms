// Bucket Sort
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void printArray(float *a, int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void bucketSort(float *a, int n)
{
	vector<float> b[n];
	for(int i=0; i<n; i++)
	{
		int idx = n*a[i];
		b[idx].push_back(a[i]);
	}
	for(int i=0; i<n; i++)
		sort(b[i].begin(),b[i].end());

	int idx = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<b[i].size(); j++)
			a[idx++] = b[i][j];
}

int main()
{
	float a[5] = {0.897,0.565,0.656,0.1234,0.665};
	cout << "Unsorted : ";
	printArray(a,5);
	
	bucketSort(a,5);
	
	cout << "Sorted : ";
	printArray(a,5);
	return 0;
}
