
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
int prec(char c){ if(c=='^') return 3; if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return 0; }
int main(){
    string s; cin>>s;
    stack<char> st;
    string res;
    for(char c:s){
        if(isalnum(c)) res+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){ while(!st.empty()&&st.top()!='('){ res+=st.top(); st.pop(); } st.pop(); }
        else{ while(!st.empty()&&prec(st.top())>=prec(c)){ res+=st.top(); st.pop(); } st.push(c); }
    }
    while(!st.empty()){ res+=st.top(); st.pop(); }
    cout<<res;
}
