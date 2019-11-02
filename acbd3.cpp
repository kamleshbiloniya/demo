#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int count =0;
	for(int a=0;a<1000;a++){
		for(int b=0;b<1000;b++){
			for(int c=0;c<1000;c++){
				for(int d=0;d<1000;d++){
					if(a*a*a + b*b*b == c*c*c + d*d*d){
						// cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
						count++;
					}
				}
			}
		}
	}
	cout<<count<<endl;
	return 0;
}