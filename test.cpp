#include<stdio.h>
int square (int num)
{
..................
}
int find_sum_squares (int len, int *arr)
{
int sum = 0;
while(len){
sum += square (arr[len-1]);
--len;
}
return sum;
}
main( )
{
int sum = 0, len = 5;
int arr[5] = {1, 2, 3, 4, 5};
sum = find_sum_squares (len, arr);
printf(“%d %d\n”,len, sum);
}