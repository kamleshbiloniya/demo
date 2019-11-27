#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n=30;
	for (int i = 1; i <= n; ++i)
	{
		cout<<setw(i);
		cout<<i<<endl;
		cout<<setw(n-i);
		cout<<i<<endl;
	}
	return 0;
}