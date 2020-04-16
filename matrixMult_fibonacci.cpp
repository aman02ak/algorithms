#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

typedef struct matix
{
	int **mat;
}matrix;

void mul_matrix(int **a1,int **a2,int **res,int r1,int c1,int r2,int c2);
string dec_to_bin(int num);

int main()
{
	int startMat[2][2] = {{1,1},{1,0}};
	int num = 13;
	string s = dec_to_bin(num);
	
	matrix m[s.length()];
	m[0].mat = (int**)malloc(2*sizeof(int*));
	for(int i=0 ;i<2; i++)
		m[0].mat[i] = (int*)malloc(2*sizeof(int));
	
	//memset(m[0].mat,0,sizeof(m[0].mat));
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			m[0].mat[i][j] = startMat[i][j];
	
	for(int i=1; i<s.length(); i++)
	{
		m[i].mat = (int**)malloc(2*sizeof(int*));
		for(int i=0 ;i<2; i++)
			m[i].mat[i] = (int*)malloc(2*sizeof(int));
			
		mul_matrix(m[i-1].mat,m[i-1].mat,m[i].mat,2,2,2,2);
	}
	return 0;
}

void mul_matrix(int **a1,int **a2,int **res,int r1,int c1,int r2,int c2)
{
	for(int i=0; i<r1; i++)
	{
		for(int j=0; j<c2; j++)
		{
			res[i][j] = 0;
			for(int k=0; k<c1; k++)
				res[i][j] += a1[i][k]*a2[k][j];
		}
	}
}

string dec_to_bin(int num)
{
	string s = "";
	while(num)
	{
		s+=to_string(num%2);
		num /= 2;
	}
	return s;//binary in inverted form
}
