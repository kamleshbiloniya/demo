#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int findMinLength(string txt){
  string tmp = txt;
  int len = txt.length();
  for (int i = len-1; i >=0; i--) {
    tmp += txt[i];
  }
  int lps[2*len];
  int i=1;
  int j=0;
  lps[0]=0;
  while(i<2*len){
    if(tmp[i]==tmp[j]){
      j++;
      lps[i]=j;
      i++;
    }
    else{
      if(j>0){
        j = lps[j-1];
      }
      else{
        lps[i]=0;
        i++;
      }
    }
  }
int count = 2*len;
for (size_t i = 0; i < count; i++) {
  std::cout << lps[i] <<" ";
}
  return len-lps[2*len - 1];
}

int main(){
  string txt;
  std::cin >> txt;
  int min_l = findMinLength(txt);
  std::cout << "min req"<<min_l << '\n';
  return 0;
}
