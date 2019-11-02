#include <stdio.h>
#include <stdlib.h>
void foo(float *p)
{
	printf("%f\n",*p);
	printf("%f\n",*(p+1));
}
int main() {

	int a=9999;
	float b=a;
	float *p;
	*p= (float)&a;
	printf("%f\n",*p);
	foo(&p);
	return 0;
}