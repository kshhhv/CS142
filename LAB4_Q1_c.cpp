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

    void top(){
        cout<<"Top element: "<<a[t]<<endl;
    }

    void display(){
        for(int i=1;i<=t;i++){
            cout<<a[i];
        }

        cout<<endl;
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
    s1.top();
    cout<<endl;


    for(int i=1; i<10;i++){
        s1.pop();
        s1.display();
    }
    cout<<"Size: "<<s1.siz()<<endl;
    cout<<"isEmpty: "<<s1.isEmpty()<<endl;
    s1.top();

    StackArr s2;
    int n = s1.siz();
    for(int i=0;i<n;i++){
        s2.a[i]=s1.a[t];
        s1.pop();
    }


    return 0;
}
