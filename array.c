#include<stdio.h>
int main(){
	int a ;
	scanf("%d",&a);
	int arr[a];
	int ctr=4;
	do{
		printf("running....\n");
		ctr--;
		arr[ctr]=0;
	}while(ctr>=0);
	printf("%d\n",arr[3]);
}