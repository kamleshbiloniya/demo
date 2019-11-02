#include<stdio.h>

int square (int num)
{

return num*num;
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
int main( )
{
 int sum = 0, len = 5;
 int arr[5] = {1, 2, 3, 4, 5};
 sum = find_sum_squares (len, arr);
 printf("%d %d\n",len, sum);
 return 0;
}

// int main()
// {
 
//  unsigned long crs_val;
//  asm volatile ("mov %%cs, %0;"
//  : "=r" (crs_val)
//  :
//  :"memory"
//  );
//  printf("%lx\n", crs_val);
//  asm volatile ("mov %0, %%cs;"
//  :
//  : "r" (crs_val)
//  );

// return 0;
// }

// unsigned long cr3_val;
//  asm volatile("mov %%rsp, %0;"
//  : "=r" (cr3_val)
//  :
//  :"memory"
//  );

// printf("%lx\n", cr3_val);