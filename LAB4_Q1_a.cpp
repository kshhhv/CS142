#include <iostream>
#include "LAB2_Q1.cpp"

using namespace std;

class Stack{
public:
    Node * top;
    linkedList l1;

    Stack(){
        top = l1.head;

    }

    //insert on top
    void push(int value){
        l1.insertAt(1,value);
        top = l1.head;
    }

    //delete the top
    void pop(){
        l1.deletAt(1);
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

    linkedList l1;


    Stack s1;

    for(int i=0; i<5 ; i++){
        s1.push(i);
        s1.display();
    }

    for(int i=0; i<5 ; i++){
        s1.pop();
        s1.display();
    }



    return 0;


}



