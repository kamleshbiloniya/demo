#include<iostream>

using namespace std;
void swap(int *a,int *b){
	cout<<"from swap fun "<<a<<" "<<b<<endl;
	int tmp = *a;
	*a = *b;
	*b =tmp;
}
int main(int argc, char const *argv[])
{
	int a=100,b=200;
	cout<<"before : "<<&a<<" "<<&b<<endl;
	swap(&a,&b);
	cout<<"after : "<<a<<" "<<b<<endl;
	return 0;
}