
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n; cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){ int x; cin>>x; q.push(x); }
    int half=n/2;
    queue<int> first;
    for(int i=0;i<half;i++){ first.push(q.front()); q.pop(); }
    while(!first.empty()){
        cout<<first.front()<<" "; first.pop();
        cout<<q.front()<<" "; q.pop();
    }
}
