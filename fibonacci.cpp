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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////	METHOD -2 //////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
#define RES(i,n) for(int i=0; i<n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
int const K = 2;

void call();
matrix mul(matrix A, matrix B)
{
	matrix res(K, vector<ll>(K));
	RES(i, K) RES(j, K) RES(k, K)
		res[i][j] += A[i][k]*B[k][j];

	return res;
}

matrix pow(matrix A, ll n)
{
	if(n == 1)
		return A;
	matrix retMat;
	if(n%2 == 0)
	{
		retMat = pow(A, n/2);
		retMat = mul(retMat, retMat);
	}
	else
	{
		retMat = pow(A, (n-1)/2);
		retMat = mul(retMat, retMat);
		retMat = mul(retMat, A);
	}
	return retMat;
}

ll fib(ll n)
{
	if(n == 0 || n == 1)
		return 1;

	matrix T(K, vector<ll>(K));
	T[0][0] = 0, T[0][1] = 1;
	T[1][0] = 1, T[1][1] = 1;
	T = pow(T, n);

	vector<int> v(K+1);
	v[0] = 1;
	v[1] = 1;
	ll ans = 0;
	ans = v[1]*T[1][1];
	return ans;
}

int main()
{
	call();
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		cin.ignore();
		cout << "Answer : " << fib(n-1) << endl;
	}
	return 0;
}

void call()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
