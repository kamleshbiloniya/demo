#include<iostream>
#include<map>
using namespace std;

int main(){
	std::map<int, string> sort;
	sort[3]="kamlesh";
	sort[2]="sonu";
	sort[4]="biloniya";
	sort[1]="garg";
	map<int, string>::iterator itr;
	for(itr=sort.begin();itr!=sort.end();++itr){
		cout<<itr->first<<" "<<itr->second<<endl;
	}
	cout<<sort[0]<<endl;
}