#include<bits/stdc++.h>

using namespace std;
int case1 = 0;
int case2 = 0;
set<pair<int,int>>s;
void jump(int x,int y){
	cout<<"some"<<endl;
	if(y==0 || y==4){
		case1++;
		return;
	}
	if(x==0 || x==4){
		case2++;
		return;
	}
	if(s.find(make_pair(x,y+1))==s.end()){s.insert(make_pair(x,y+1));jump(x,y+1);}
	if(s.find(make_pair(x,y-1))==s.end()){s.insert(make_pair(x,y-1));jump(x,y-1);}
	if(s.find(make_pair(x+1,y))==s.end()){s.insert(make_pair(x+1,y));jump(x+1,y);}
	if(s.find(make_pair(x-1,y))==s.end()){s.insert(make_pair(x-1,y));jump(x-1,y);}
	return;

}

int main(int argc, char const *argv[])
{
	int x=1;
	int y=2;
	s.insert(make_pair(x,y));
	jump(x,y);
	cout<<case1<<" "<<case2<<endl;
	return 0;
}