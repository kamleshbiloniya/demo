#include<stdio.h>
void fun(int arr[]){
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("%d",size);
}
int main(int argc, char const *argv[])
{
	int arr[]={1,2,3,4,5};
	fun(arr);
	return 0;
}