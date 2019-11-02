#include<bits/stdc++.h>

using namespace std;

void set_(){
	unordered_set<int> s; // Ordered set increasing order
	// set<int,greater<int>>s; // Ordered set decreasing order
	s.insert(2);
	s.insert(5);
	s.insert(6);
	s.insert(1);

	unordered_set<int>::iterator itr;
	int n = s.size();
	cout<<"size of set = "<<n<<endl;
	for(itr=s.begin();itr!=s.end();++itr){
		cout<<*itr<<endl;
	}

	s.erase(5);

	cout<<"after erasing 5  "<<endl;
	unordered_set<int>::iterator ritr;
	for(ritr=s.begin();ritr!=s.end();++ritr){
		cout<<*ritr<<endl;
	}
	if(s.find(5)==s.end()){
		s.insert(5);
		cout<<"element 5 was not found "<<endl;
	}
	s.clear();

}

void multiset_(){
	// multiset<int> s; // Ordered set increasing order
	multiset<int,greater<int>>s; // Ordered set decreasing order
	s.insert(2);
	s.insert(5);
	s.insert(5);
	s.insert(6);
	s.insert(6);
	s.insert(1);

	set<int>::iterator itr;
	int n = s.size();
	cout<<"size of set = "<<n<<endl;
	for(itr=s.begin();itr!=s.end();++itr){
		cout<<*itr<<endl;
	}

	s.erase(5);

	cout<<"after erasing 5  "<<endl;
	set<int>::reverse_iterator ritr;
	for(ritr=s.rbegin();ritr!=s.rend();++ritr){
		cout<<*ritr<<endl;
	}
	s.clear();

}

void stack_(){
	stack<int>s;
	s.push(2);
	s.push(10);
	s.push(8);
	s.push(12);
	s.push(21);
	int n = s.size();
	cout<<"sizeof s = "<<n<<endl;
	cout<<"top was "<<s.top()<<endl;
	s.pop();
	cout<<"now top is "<<s.top()<<endl;


}
void queue_(){
	queue<int>q;
	q.push(2);
	q.push(50);
	q.push(8);
	q.push(12);
	q.push(5);
	int n= q.size();
	cout<<"size of queue = "<<n<<endl;
	cout<<"top is "<<q.front()<<endl;
	cout<<"back is "<<q.back()<<endl;
	q.pop();
	cout<<"Now top is "<<q.front()<<endl;
}
void list_(){
	list<int>lst;
	lst.push_front(2);
	lst.push_back(1);
	lst.push_front(7);
	lst.push_back(5);
	lst.push_front(3);
	lst.push_back(6);
	lst.push_front(2);
	

	int n= lst.size();
	cout<<" size of list is "<<n<<endl;

	cout<<" front element is "<<lst.front()<<endl;
	cout<<" last element is "<<lst.back()<<endl;
	lst.pop_back();
	lst.pop_front();
	cout<<"Now front element is "<<lst.front()<<endl;
	cout<<"Now last element is "<<lst.back()<<endl;

	
	list<int>::iterator itr;
	for(itr=lst.begin();itr!=lst.end();++itr){
		cout<<*itr<<endl;
	}
	lst.unique();
	cout<<"dup removed "<<endl;
	for(itr=lst.begin();itr!=lst.end();++itr){
		cout<<*itr<<endl;
	}
	lst.sort();
	cout<<"sorted list "<<endl;
	for(itr=lst.begin();itr!=lst.end();++itr){
		cout<<*itr<<endl;
	}

	lst.clear();

}
void deque_(){
	deque<int> dq;
	dq.push_back(2);
	dq.push_front(5);
	dq.push_back(5);
	dq.push_front(3);
	dq.push_back(6);
	dq.push_front(2);
	dq.push_front(2);
	dq.push_back(1);
	dq.push_front(7);
	deque<int>::iterator itr;
	for(itr=dq.begin();itr!=dq.end();++itr){
		cout<<*itr<<endl;
	}
	cout<<"element at index 1 :"<<dq.at(1)<<endl;
}
void priority_queue_(){
	// priority_queue<int>pq; // Max heap
	priority_queue<int,std::vector<int> ,greater<int>> pq; //min heap
	pq.push(2);
	pq.push(5);
	pq.push(5);
	pq.push(3);
	pq.push(6);
	pq.push(2);
	pq.push(2);
	pq.push(1);
	pq.push(7);
	cout<<"top priority is "<<pq.top()<<endl;
	pq.pop();
	cout<<"now top priority is "<<pq.top()<<endl;
}
void pair_(){
	pair<int,int> p;
	p.first = 1;
	p.second = 2;
	// cout<<p.first<<" "<<p.second<<endl;

	set<pair<int,int>>s;
	s.insert(p);
	s.insert(make_pair(3,4));
	set<pair<int,int>>::iterator itr;
	for(itr= s.begin();itr!= s.end();++itr){
		cout<<(*itr).first<<" "<<(*itr).second<<endl;
	}
}
void binary_search_(){
	int arr[]={1,5,6,8,9,12,15};
	int n = sizeof(arr)/sizeof(arr[0]);
	if(binary_search(arr,arr+n,10)){
		cout<<"element 8 found "<<endl;
	}
	else{
		cout<<"element 10 not found"<<endl;
	}
}
int main(int argc, char const *argv[])
{
	// set_();
	// multiset_();
	// stack_();
	// queue_();
	// list_();
	// deque_();
	// priority_queue_();
	// pair_();
	binary_search_();
	return 0;
}