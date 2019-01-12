#include <iostream>
using namespace std;

class Node
{
public:
    //data
    int data;
    //pointer to the next node
    Node * next;
    // constructor that makes the pointer to NULL
    Node()
    {
        next = NULL;

    }

};

class  linkedList
{
    ;
public:
    // head => node type pointer
    Node * head;
    Node * tail;
    //constructor
    linkedList()
    {
        head=NULL;
        tail=NULL;
    }
    // circles inside each other
    //rules to link circle

    //insert
    void insert(int value)
    {
        Node * temp = new Node;
        //Insert value in node
        temp->data = value;
        //1st node only
        if(head==NULL){
            head = temp;

        }
        //any other node
        else{
            tail->next= temp;

        }
         tail = temp;
    }



    void insertAt(int pos, int value){
        //reach the lace before pos
        Node * current = head;
        int i=1;
        if(current != tail){
            while (i<pos-1){
                i++;
                current = current->next;

            }
            //create  a node
            Node *temp = new Node;
            temp -> data = value;

            //move pointers like magic
            temp->next = current->next;
            current->next = temp;
        }
        else{
            cout<<"Linked List does not have that many elements." <<endl;
        }
        //update the code for 1st position


    }



    //deletion
    void delet(){
        //store the tail in temp
        Node * temp = tail;
        // before tail has to point to NULL
        Node * current = head;
        while(current->next != tail){
                current = current->next;
        }
        current->next = NULL;

        //update tail
        tail = current;
        //delete temp
        delete temp;
    }

    //deletion at position
    void deletAt(int pos)
  {
    Node * current=new Node;
    Node * previous=new Node;
    current=head;

    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
  }

  void Count()
{
    int i = 0;  // Initialize count
    class Node* current = head;  // Initialize current
    while (current != NULL)
    {
        i++;
        current = current->next;
    }
    cout<<"No. of elements is: "<<i<<endl;
}

    //display
    void display(){
        Node * current = head;
        while(current!= NULL){
                cout<< current->data<<"->";
                current = current->next;
        }
        cout<<endl;
    }

};


int main()
{

    linkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.display();
    l1.Count();
    l1.delet();
    l1.deletAt(2);
    l1.display();
    l1.insertAt(2,4);
    l1.display();

    l1.Count();
    l1.display();

    return 0;
}
