#include<stdio.h>

int main(int argc, char const *argv[])
{
	int a[2]={2,4};
	printf("0x%p\n0x%lld\n",a,&a[0]);
	return 0;
}