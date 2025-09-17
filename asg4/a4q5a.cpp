
//two queue
#include <iostream>
#include <queue>
using namespace std;
queue<int> q1,q2;
void push(int x){
    q2.push(x);
    while(!q1.empty()){ q2.push(q1.front()); q1.pop(); }
    swap(q1,q2);
}
void pop(){ if(!q1.empty()) q1.pop(); }
int top(){ return q1.front(); }
int main(){
    push(10); push(20); cout<<top()<<"\n"; pop(); cout<<top();
}
