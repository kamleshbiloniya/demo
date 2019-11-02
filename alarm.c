 #include<stdio.h>
 #include <unistd.h>
int main(int argc, char const *argv[])
{
	int a = alarm(1000000000);
	printf("%d\n",a);
	return 0;
}
       