#include<bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef struct Screen{
	int snum; // screen num instead screen name;
	int rows;
	int seats;
	int **mapp;
}screen;

std::vector<screen *> all_screens;
std::map<int,int> dict;

int find_screen_number(string s){
	int n=0;
	int len = s.length();
	for(int i=6;i<len;i++){
		n = n*10+ s[i]-'0';
	}
	return n;
}
void addScreen(int snum,int rows, int seats,std::vector<int> arr){
	if(dict[snum]){
		cout<<"failure"<<endl;
		return;
	}
	int **p = (int **)malloc(rows*seats*sizeof(int*));
	int al = arr.size();
	for(int i=0;i<rows;i++){
		p[i] = (int *)malloc(seats*sizeof(int));
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<seats;j++){
			p[i][j]=-1;
		}
		for(int j=0;j<al;j++){
			p[i][arr[j]-1]=0;
		}
	}
	screen *news = (screen *)malloc(sizeof(screen));
	news->snum = snum;
	news->rows = rows;
	news->seats=seats;
	news->mapp=p;
	all_screens.push_back(news);
	dict[snum] = all_screens.size();
	cout<<"success"<<endl;
	return;
}

void reserve_Seat(int snum,int row , std::vector<int>arr){
	int n = arr.size();
	if(!dict[snum]){
		cout<<"failure"<<endl;
		return;
	}
	screen *sc = all_screens[dict[snum]-1];
	if(sc->rows<row){
		cout<<"failure"<<endl;
		return;
	}

	int **p = sc->mapp;
	for(int i=0;i<n;i++){
		if(arr[i]> sc->seats || p[row-1][arr[i]-1]==1){
			cout<<"failure"<<endl;
			return;
		}
	}

	for(int i=0;i<n;i++){
		p[row-1][arr[i]-1]=1;
	}
	cout<<"success"<<endl;
	return;

}

void get_unreserved_seat(int snum, int row ){
	if(!dict[snum]){
		cout<<"failure"<<endl;
		return;
	}
	screen *sc = all_screens[dict[snum]-1];
	if(sc->rows < row){
		cout<<"failure"<<endl;
		return;
	}

	int **p = sc->mapp;
	int n = sc->seats;
	for(int i=0;i<n;i++){
		if(p[row-1][i] !=1){
			cout<<i+1<<" ";
		}
	}
	cout<<endl;
	return;
}
void suggest_seats(int snum, int k, int row, int choice){
	if(!dict[snum]){
		cout<<"failure"<<endl;
		return;
	}
	screen *sc = all_screens[dict[snum]-1];
	if(sc->rows < row || k > sc->seats){
		cout<<"failure"<<endl;
		return;
	}
	int **p = sc->mapp;
	int f=0;
	int b=0;
	int n = sc->seats;
	for(int i=choice-1;i>=0;i--){
		if(p[row-1][i]!=1)b++;
		if(i!= choice-1 && p[row-1][i]==0)break;
	}
	if(b>=k){
		std::vector<int> v;
		for(int i= choice-1;i>=0&&k>0;i--){
			if(p[row-1][i]!=1){
				v.push_back(i+1);
				k--;
			}
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i= choice-1;i<n;i++){
		if(p[row-1][i]!=1)f++;
		if(i!= choice-1 && p[row-1][i]==0)break;
	}
	if(f>=k){
		for(int i= choice-1;i<n && k >0;i++){
			if(p[row-1][i]!=1){
				cout<<i+1<<" ";
				k--;
			}
		}
		cout<<endl;
		return;
	}
	cout<<"none"<<endl;
	return;

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string t,s; // t== query type , screen name
		cin>>t>>s;
		int snum = find_screen_number(s);
		if(t[0]=='a'){
			int rows;
			int seats;
			cin>>rows>>seats;
			string nums;
			getline(cin,nums);
			int tmp;
			std::vector<int> arr;
			stringstream stream(nums);
			while(stream>>tmp){
				arr.push_back(tmp);
			}
			addScreen(snum,rows,seats,arr);

		}
		else if(t[0]=='r'){
			int row;
			cin>>row;
			string nums;
			getline(cin,nums);
			stringstream stream(nums);
			int tmp;
			std::vector<int> arr;
			while(stream>>tmp){
				arr.push_back(tmp);
			}
			reserve_Seat(snum,row,arr);
		}
		else if(t[0]=='g'){
			int row;
			cin>>row;
			get_unreserved_seat(snum,row);
		}
		else{ // for suggest
			int k,row,choice;
			cin>>k>>row>>choice;
			suggest_seats(snum,k,row,choice);
		}
	}	
	return 0;
}






/* 
5
ad screen1 12 10 4 5 8 9
re screen1 2 4 5
re screen1 2 8 11
get screen1 2
suggest screen1 6 2 6




9
add screen1 12 10 4 5 8 9
add screen2 220 25 3 4 12 13 17 18
re screen1 4 5 6 7
re screen2 13 6 7 8 9 10
re screen2 13 4 5 6
ge screen2 13
su screen1 3 3 4
su screen1 4 12 4
su screen1 4 10 3
*/