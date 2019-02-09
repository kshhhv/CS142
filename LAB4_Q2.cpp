#include <iostream>
using namespace std;






class StackArr{
public:

    int a[100];
    int t = 0;

    void push(int value){
        if(t<=100){
            a[t+1]=value;
            t++;
        }

        else{
            cout<<"Array size is limited"<<endl;
        }
    }

    void pop(){
        if (t>0){
            a[t]=0;
            t=t-1;
        }
        else
            cout<<"Stack has no element."<<endl;
    }

    int siz(){
        return t;
    }

    bool isEmpty(){
        if(t==0) return true;
        return false;
    }

    int top(){
        return a[t];
    }

    void display(){
        for(int i=1;i<=t;i++){
            cout<<a[i];
        }

        cout<<endl;
    }


    void dequeue(){
    StackArr s2;
    int n = siz();
    for(int i=1;i<n;i++){
        int temp = top();
        s2.push(temp);
        pop();
    }

    pop();

    for(int i=1;i<n;i++){
        int temp = s2.top();
        push(temp);
        s2.pop();
    }
}

};







int main(){

    StackArr s1;
    for(int i=1; i<10;i++){
        s1.push(i);
        s1.display();
    }

    cout<<"Size: "<<s1.siz()<<endl;
    cout<<"isEmpty: "<<s1.isEmpty()<<endl;
    cout<<"Top element: "<<s1.top()<<endl;
    cout<<endl;


    for(int i=1; i<10;i++){
        s1.dequeue();
        s1.display();
    }



    cout<<"Size: "<<s1.siz()<<endl;
    cout<<"isEmpty: "<<s1.isEmpty()<<endl;
    cout<<"Top element: "<<s1.top()<<endl;




    return 0;
}
