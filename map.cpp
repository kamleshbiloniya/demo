vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n1=A.size();
    vector<int>result;
    for(int i=0;i<n1;i++){
        result.push_back(-1);
    }
    map<int,int> keyval;
    for(int i=0;i<n1;i++){
        keyval.insert(make_pair(A[i],B[i]));
    }
    map<int,int>:: iterator it;
    int count=0;
    for(it=keyval.end();it!=keyval.begin();it--){
        it--;
        int inf= (*it).second;
        if(inf==count){
            result[count]=(*it).first;
            // cout<<count<<" at"<<result[count]<<endl;
            count++;

        }
        else{
            count++;
            int tmp_count = count;
            while(inf!=count){
                result[count]=result[count-1];
                count--;
            }
            result[count]=(*it).first;
            // cout<<count<<" att"<<result[count]<<endl;
            count = tmp_count;
        }
        it++;
    }
    return result;

}
