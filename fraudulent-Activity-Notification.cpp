#include <bits/stdc++.h>

using namespace std;
typedef struct Node{
    int val;
    struct Node *next;
}node;
vector<string> split_string(string);
node * addnode(int data,node *head){
    // cout<<"hello add node"<<endl;
    node *newnode = (node *)malloc(sizeof(node));
    // cout<<"YO"<<endl;
    newnode->val = data;
    // cout<<"adding "<<data<<endl;
    newnode->next = NULL;
    if(head == NULL){
        // cout<<"head is null"<<endl;
        head = newnode;
        return head;
    }
    node * p = head;
    while(head->next!=NULL && head->next->val < data){
        head = head->next;
    }
    newnode->next = head->next;
    head->next = newnode;
    // node *tmp = p;
    // while(tmp!=NULL){
    //     cout<<tmp->val<<" ";
    //     tmp = tmp->next;
    // }
    // cout<<endl;
    return p;
}
node * removenode(int val , node *head){
    if(head == NULL)return NULL;
    if(head->val == val){
        // cout<<"removing "<<head->val;
        head = head->next;
        // cout<<head->val<<endl;
        return head;
    }
    node *p = head;
    while(head->next->val != val){
        head = head->next;
    }
    head->next = head->next->next;
    return p;
}
float findMedian(int d , node*head){
    if(d%2==1){
        for(int i=0;i<d/2;i++){
            head = head->next;
        }
        return 2*(head->val);
    }
    else{
        for(int i=0;i<(d/2);i++){
            head = head->next;
        }
        return (head->val + head->next->val);
    }
}
// Complete the activityNotifications function below.
int activityNotifications(vector<int> exp, int d) {
    int n = exp.size();
    node * head = (node *)malloc(sizeof(node));
    head = NULL; 
    int count = 0;
    for(int i=0;i<d;i++){
        head = addnode(exp[i],head);
        // if(head==NULL)cout<<"oh no"<<endl;
    }
    for(int i=d;i<n;i++){
        float a = findMedian(d,head);
        // cout<<a<<" "<<exp[i]<<endl;
        if(exp[i]>=a){
            count++;
        }
        head = removenode(exp[i-d],head);
        addnode(exp[i],head);
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
