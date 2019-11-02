#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int len = A.size();
    int max_sum_here =0;
    int max_so_far =0;
    int start = 0;
    int end =0;
    for(int i=0; i<len; i++){
        max_sum_here += A[i];
        if(max_sum_here<0){
            max_sum_here = 0;
            start = i;
            end = i;
        }
        if(max_so_far <= max_sum_here){
            max_so_far = max_sum_here;
            end = i;
        }
    }
    if(end >= start+1){
      cout<<"start is "<<start+1<<" and end is "<<end <<endl;
    }
    return max_so_far;
}
int main() {
std::vector<int> A;//[-2,1,-3,4,-1,2,1,-5,4]
A.push_back(-2);
A.push_back(1);
A.push_back(-3);
A.push_back(4);
A.push_back(-1);
A.push_back(2);
A.push_back(1);
A.push_back(-5);
A.push_back(4);

  std::cout << "max sum is " <<maxSubArray(A)<< '\n';
  return 0;
}
