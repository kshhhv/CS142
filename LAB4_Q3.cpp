

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

    int top(){
        return a[t];
    }

    int btm(){
        return a[f];
    }

    void display(){

        for(int i=f;i<=t;i++){
            cout<<a[i];
        }

        cout<<endl;
    }

    void pop(){
        QueueArr q2;
        int n = siz();
        for(int i=0; i<n-1; i++){
           int temp =btm();
           q2.enqueue(temp);
           dequeue();

       }
       dequeue();

       for(int i=0; i<n-1; i++){
           int temp = q2.btm();
           enqueue(temp);
           q2.dequeue();

       }
       display();

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
    cout<<"Top element: "<<q1.top()<<endl;
    cout<<endl;

    q1.pop();


    for(int i=1; i<10;i++){
        q1.pop();
    }
    cout<<"Size: "<<q1.siz()<<endl;
    cout<<"isEmpty: "<<q1.isEmpty()<<endl;
    cout<<"Top element: "<<q1.top()<<endl;


    return 0;
}
