#include <stdio.h>
#include<string.h>

// #define MAX_OBJS 1 << 20 
unsigned long MAX_OBJS  = (1 << 20) ;
unsigned long hash(char *key)
{
	int len=0;
	while(*key++){
		len++;
	}
	printf("length = %d\n",len);
    unsigned long hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash%MAX_OBJS;
}
int main(int argc, char const *argv[])
{
	
	unsigned long a=hash("CS330###2");
	printf("a= %u\n",a);
	printf("MAX_OBJS=%d\n",MAX_OBJS);
	int res = a%MAX_OBJS;
	printf("a  modulo MAX_OBJS=%u\n",601214328%1048576);
	printf("%d\n",res);
	return 0;
}