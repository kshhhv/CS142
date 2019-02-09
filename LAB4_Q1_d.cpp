
#include <iostream>
using namespace std;

class QueueArr{
public:

    int a[100];
    int t = 0;
    int f = 1;

    void enqueue(int value){
        if(t<=100){
            a[t+1]=value;
            t++;
        }

        else{
            cout<<"Array size is limited"<<endl;
        }
    }

    void dequeue(){
        if (t>0){
            a[f]=0;
            f=f+1;
        }
        else
            cout<<"Queue has no element."<<endl;
    }

    int siz(){
        return t-f+1;
    }

    bool isEmpty(){
        if(t-f+1==0) return true;
        return false;
    }

    void top(){
        cout<<"Top element: "<<a[t]<<endl;
    }

    void display(){
        for(int i=f;i<=t;i++){
            cout<<a[i];
        }

        cout<<endl;
    }


};





int main(){

    QueueArr q1;
    for(int i=1; i<10;i++){
        q1.enqueue(i);
        q1.display();
    }

    cout<<"Size: "<<q1.siz()<<endl;
    cout<<"isEmpty: "<<q1.isEmpty()<<endl;
    q1.top();
    cout<<endl;


    for(int i=1; i<10;i++){
        q1.dequeue();
        q1.display();
    }
    cout<<"Size: "<<q1.siz()<<endl;
    cout<<"isEmpty: "<<q1.isEmpty()<<endl;
    q1.top();


    return 0;
}
