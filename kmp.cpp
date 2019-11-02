#include<iostream>
#include<stdio.h>
using namespace std;

int main() {

  string txt;
  string pat;
  std::cout << "Enter string:";
  std::cin >> txt;
  std::cout << "Enter pattern:";
  std::cin >> pat;
  // cout<<txt<<" "<<pat<<endl;
//calculation of lps[]
  int M = pat.length();
  int N = txt.length();
  int j=0;
  int lps[M];
  int i=1;
  lps[0]=0; //length of prefix which is also suffix
  while(i<M){
    if(pat[i]==pat[j]){
      j++;
      lps[i]=j;
      i++;
    }
    else{
      if(j!=0){
        j=lps[j-1];
      }
      else{
        lps[i]=0;
        i++;
      }
    }
  }
////calculation of lps[]
  // for (size_t i = 0; i <M; i++) {
  //   std::cout << lps[i]<<" ";
  // }
i=0;
j=0;
while (i<N) {
  if(pat[j]==txt[i]){
    i++;
    j++;

    if(j==M){
      std::cout << "pattern found at "<<i-j<< '\n';
      j = lps[j-1];
    }
  }
  else{
    if(j>0){
      j=lps[j-1];
    }
    else{
      i++;
    }
  }


}

  return 0;
}
