#include<iostream>
using namespace std;

void printMat(int **c, int m, int n);
int max(int a, int b);

int lcs(string x, string y, int m, int n)
{
	int **c = (int **)malloc((m+1)*sizeof(int*));
	for(int i=0; i<(m+1); i++)
		c[i] = (int*)malloc((n+1)*sizeof(int));
		
	for(int i=0; i<=m; i++)
		c[i][0] = 0;
	for(int j=0; j<=n; j++)
		c[0][j] = 0;
	
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(x[i-1]==y[j-1])
				c[i][j] = c[i-1][j-1]+1;
			else
				c[i][j] = max(c[i-1][j],c[i][j-1]);
		}
	}
	return c[m][n];
}

int main()
{
	string x = "ABCBDAB";
	string y = "BDCABA";
	int m =  x.length(), n = y.length();
	
	int ans = lcs(x,y,m,n);
	cout << "Length of Longest Common Subsequence : " << ans << endl;
	return 0;
}

void printMat(int **c, int m, int n)
{
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
			cout << c[i][j] << ' ';
		cout << endl;	
	}
}
int max(int a, int b)
{
	return (a>b)? a:b;
}
