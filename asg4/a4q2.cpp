
#include <iostream>
using namespace std;
#define MAX 100
int cq[MAX],front=-1,rear=-1;
bool isEmpty(){ return front==-1; }
bool isFull(){ return (rear+1)%MAX==front; }
void enqueue(int x){
    if(isFull()) cout<<"Queue Overflow\n";
    else{
        if(front==-1) front=0;
        rear=(rear+1)%MAX;
        cq[rear]=x;
    }
}
void dequeue(){
    if(isEmpty()) cout<<"Queue Underflow\n";
    else{
        cout<<"Dequeued "<<cq[front]<<"\n";
        if(front==rear) front=rear=-1;
        else front=(front+1)%MAX;
    }
}
void peek(){ if(isEmpty()) cout<<"Empty\n"; else cout<<cq[front]<<"\n"; }
void display(){
    if(isEmpty()) cout<<"Empty\n";
    else{
        int i=front;
        while(true){
            cout<<cq[i]<<" ";
            if(i==rear) break;
            i=(i+1)%MAX;
        }
        cout<<"\n";
    }
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
