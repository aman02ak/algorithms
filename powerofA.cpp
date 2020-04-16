#include<iostream>
#define int long long
using namespace std;

int expo(int a, int n)
{
	if(n==1)
		return a;
	if(n%2==0)
	{
		int ans = expo(a,n/2);
		return ans*ans;
	}	
	else
	{
		int ans = expo(a,(n-1)/2);
		return ans*ans*a;
	}
}

int32_t main()
{
	int a, n;
	cout << "Enter a num : ";
	cin >> a;
	cout << "Enter expo : ";
	cin >> n;
	int ans = expo(a,n);
	cout << "Answer : " << ans << endl;
	return 0;
}
