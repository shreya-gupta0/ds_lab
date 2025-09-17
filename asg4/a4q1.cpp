
#include <iostream>
using namespace std;
#define MAX 100
int q[MAX],front=-1,rear=-1;
bool isEmpty(){ return front==-1; }
bool isFull(){ return rear==MAX-1; }
void enqueue(int x){
    if(isFull()) cout<<"Queue Overflow\n";
    else{
        if(front==-1) front=0;
        q[++rear]=x;
    }
}
void dequeue(){
    if(isEmpty()) cout<<"Queue Underflow\n";
    else{
        cout<<"Dequeued "<<q[front]<<"\n";
        if(front==rear) front=rear=-1;
        else front++;
    }
}
void peek(){ if(isEmpty()) cout<<"Empty\n"; else cout<<q[front]<<"\n"; }
void display(){
    if(isEmpty()) cout<<"Empty\n";
    else{ for(int i=front;i<=rear;i++) cout<<q[i]<<" "; cout<<"\n"; }
}
int main(){
    int ch,x;
    do{
        cin>>ch;
        if(ch==1){cin>>x; enqueue(x);}
        else if(ch==2) dequeue();
        else if(ch==3) cout<<(isEmpty()?"Yes":"No")<<"\n";
        else if(ch==4) cout<<(isFull()?"Yes":"No")<<"\n";
        else if(ch==5) display();
        else if(ch==6) peek();
    }while(ch!=0);
}
