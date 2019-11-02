#include<iostream>
using namespce std
__global__ void mykernal()
{
	
}

int main(){
	mykernal<<<1,1>>>();
	return0;
}

//<<<no. of block,no of thread>>>

threads can talk within a block
bharatk@nvidia.com
