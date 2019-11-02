vector<int> Solution::maxset(vector<int> &A) {
  int i1=0 ,j1=0;
  long long int sum1 =0;
   int i2=0 ,j2=0;
  long long int sum2 =0;
  for (int k=0; k<=A.size(); k++){
    if(k != A.size()&& A[k]>=0){
        sum1  += A[k];
        j1 = k;
    }
    else if(k==A.size()){
        
        
        if(sum1>sum2 ){
            i2=i1;
            j2=j1;
            sum2=sum1;
            sum1=0;
            i1=k+1;
            j1=k+1;
            
        }
        else if(sum1<sum2 ){
           i1=k+1;
           j1=k+1;
        }
        else{
            if(j1-i1>j2-i2){
                i2=i1;
                j2=j1;
                sum2=sum1;
                sum1 =0;
                i1=k+1;
                j1=k+1;
            }
          
            
            else{
                i1=k+1;
                j1=k+1;
                
            }
        
        }
    }
    else{
        if(sum1>sum2 ){
            i2=i1;
            j2=j1;
            sum2=sum1;
            sum1=0;
            i1=k+1;
            j1=k+1;
            
        }
        else if(sum1<sum2 ){
           i1=k+1;
           j1=k+1;
           sum1=0;
        }
        else{
            if(j1-i1>j2-i2){
                i2=i1;
                j2=j1;
                sum2=sum1;
                sum1 =0;
                i1=k+1;
                j1=k+1;
            }
          
            
            else{
                i1=k+1;
                j1=k+1;
                sum1=0;
                
            }
        
        }
    }
   
}
vector <int> B;
if(i2>=j2 && A[i2]<0)return B;
for(int i=i2; i<=j2; i++){
    B.push_back(A[i]);
}
return B;
}

//input A : [1, 2, 5, -7, 2, 3]
//output: [1, 2, 5]
