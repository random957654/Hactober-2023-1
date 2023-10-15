#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &qu){
    stack<int> st;
    while(!qu.empty()){
       int temp = qu.front();
       qu.pop();
       st.push(temp);
    }
    while(!st.empty()){
       int temp = st.top();
       st.pop();
       qu.push(temp);
    }
}

void display(queue<int> qu){
    while(not qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    display(qu);
    reverseQueue(qu);
    display(qu);
    return 0;
}
