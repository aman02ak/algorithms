#include<iostream>
using namespace std;

int a1[2][2] = {{1,1},{1,0}};

void printMat(int **a)
{
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
			cout << a1[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void multiply(int **a1, int **a2)
{
	int r1, c1, r2, c2;
	r1 = 2, c1 = 2, r2 = 2, c2 = 2;
	int res[2][2] = {{0,0},{0,0}};
	
	for(int i=0; i<r1; i++)
		for(int j=0; j<c2; j++)
			for(int k=0; k<c1; k++)
				res[i][j] += a1[i][k]*a2[k][j];
				
	for(int i=0; i<r1; i++)
		for(int j=0; j<c2; j++)
			a1[i][j] = res[i][j];
}

void fib(int **a, int n)
{		
	if(n==1)
		return;
	if(n%2==0)
	{
		//printMat(a);
		fib(a,n/2);
		multiply(a,a);
	}	
	else
	{
		//printMat(a);
		fib(a,(n-1)/2);
		multiply(a,a);
		int **temp = (int**)malloc(2*sizeof(int*));
		for(int i=0; i<2; i++)
			temp[i] = (int*)malloc(2*sizeof(int));
			
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				temp[i][j] = a1[i][j];
		
		
		multiply(a,temp);
	}
}

int main()
{
		
	int **a = (int**)malloc(2*sizeof(int*));
	for(int i=0; i<2; i++)
		a[i] = (int*)malloc(2*sizeof(int));
		
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			a[i][j] = a1[i][j];
	int n;
	cout << "Enter nth num : ";
	cin >> n;
	if(n==1)
	{
		cout << '0' << endl;
		return 0;	
	}
	fib(a,n-1);
	cout << a[1][0] << endl;
	return 0;
}

/*int fib(int n, int f0, int f1)
{
	int fcurr;
	for(int i=0; i<n-2; i++)
	{
		fcurr = f1+f0;
		f0 = f1;
		f1 = fcurr;
	}
	return fcurr;
}*/
