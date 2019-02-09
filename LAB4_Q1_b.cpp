#include <iostream>
#include "LAB2_Q1.cpp"

using namespace std;

class Queue{
public:
    Node * top;
    linkedList l1;

    Queue(){
        top = l1.head;

    }

    //Pushes on top
    void enqueue(int value){
        l1.insertAt(1,value);
        top = l1.head;
    }

    //pops the top
    void dequeue(){
        l1.delet();
        top = l1.head;
    }

    bool isEmpty(){
        if(top == NULL) return true;

        return false;
    }

    int size(){
        return l1.Count();
    }

    void topDisplay(){
    }

    void display(){
        l1.display();
    }

};

int main(){
    Queue q1;
    for(int i=0;i<5;i++){
        q1.enqueue(i);

    }
    q1.display();
    q1.dequeue();
    q1.display();

    return 0;
}
