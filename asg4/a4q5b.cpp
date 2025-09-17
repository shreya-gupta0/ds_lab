
//one queue
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
void push(int x){
    int sz=q.size();
    q.push(x);
    for(int i=0;i<sz;i++){ q.push(q.front()); q.pop(); }
}
void pop(){ if(!q.empty()) q.pop(); }
int top(){ return q.front(); }
int main(){
    push(5); push(9); cout<<top()<<"\n"; pop(); cout<<top();
}
