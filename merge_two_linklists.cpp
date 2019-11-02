#include <iostream>

using namespace std;

typedef struct Node
{
	int val;
	struct Node * next; 	
}node;

void merge(node * f , node *s , node * p){
	node * k = p;
	while(k!=NULL){
		cout<<k->val<<" ";
		k = k->next;
	}
	cout<<"\\"<<endl;
	if(f==NULL){
		while(p!=NULL){
			cout<<p->val<<" ";
			p = p->next;
		}
		while(s!=NULL){
			cout<< s->val <<" ";
			s = s->next;
		}
		cout<<endl;
	}
	else if (s==NULL){
		while(p!=NULL){
			cout<<p->val<<" ";
			p = p->next;
		}
		while(f!=NULL){
			cout<< f->val <<" ";
			f = f->next;
		}
		cout<<endl;
	}
	else{
		node *root = p;
		while(p!=NULL){
			p = p->next;
		}
		node * tmp = (node * )malloc(sizeof(node));
		tmp->val = f->val;
		tmp->next = NULL;
		p = tmp;
		merge(f->next,s,root);
		node * tmp2 = (node * )malloc(sizeof(node));
		tmp2->val = s->val;
		tmp2->next = NULL;
		p = tmp2;
		merge(f,s->next,root); 
	}
}

int main(int argc, char const *argv[])
{
	node *f = (node *)malloc(sizeof(node));
	f->val = 1;	
	f->next = (node *)malloc(sizeof(node));
	f->next->val = 2;
	f->next->next = NULL;
	node *s = (node *)malloc(sizeof(node));
	s->val = 3;	
	s->next = (node *)malloc(sizeof(node));
	s->next->val = 4;
	s->next->next = NULL;
	node *p = (node *)malloc(sizeof(node));
	p=NULL;
	merge(f,s,p);
	return 0;
}