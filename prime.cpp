#include<iostream>
#include<cmath>
using namespace std;

void prime(int num)
{
	int i = 2;
	while(i!=num/2)
	{
		if(num%i==0)
		{
			cout << "Not a Prime" << endl;
			return;
		}
		i++;
	}
	cout << "Is a Prime" << endl;
}

int main()
{
	cout << "Enter a num : ";
	int num;
	cin >> num;
	prime(num);
	return 0;
}
