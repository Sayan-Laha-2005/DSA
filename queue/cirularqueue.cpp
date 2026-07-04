#include<iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int currSize,cap;
    int f,r;

public:
    CircularQueue(int size){
        cap=size;
        arr=new int[cap];
        currSize=0;
        f=0;
        r=-1;

    }

    void push(int data){
        if(currSize==cap){
            cout<<"Queue is full"<<endl;
            return;
        }
        r=(r+1)%cap;
        arr[r]=data;
        currSize++;


    }

    void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f=(f+1)%cap;
        currSize--;

    }

    int front(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];

    }

    bool empty(){
        return currSize==0;
    }

    void printArr(){
        for(int i=0;i<cap;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    CircularQueue cq(3);
    cq.push(10);        
    cq.push(20);
    cq.push(30);
    cq.pop();
    cq.push(40); // Queue is full
    //cq.printArr();

    while ((!cq.empty())){
        cout<<cq.front()<<" ";
        cq.pop();

    }
    cout<<endl;
    

    return 0;

}