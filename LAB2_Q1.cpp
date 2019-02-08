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
        int c= Count();

        if(pos <= c and pos != 1){
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
        else if (pos == 1){
            Node * temp = new Node;
            //Insert value in node
            temp->data = value;
            temp->next = head;
            head = temp;

		}

		else if (pos==c+1){
			insert(value);
		}


       

        else{
            cout<<"Linked List does not have that many elements." <<endl;
        }
        //update the code for 1st position


    }





    //deletion
    void delet(){
        if(Count()>1){
		    // before tail has to point to NULL
		    Node * current = head;
		    while(current->next->next!=NULL){
		            current = current->next;
		    }
			Node * temp =current->next;
		    current->next = NULL;

		    //update tail
		    tail = current;
		    //delete temp
		    delete temp;
    	}

		else if (Count()==1){
			Node * temp = head;
			head = NULL;
			tail = NULL;
			delete temp;
		}
	}

    //deletion at position
    void deletAt(int pos)
  {
    Node * current= head;
    Node * previous;
    
    
    if (pos==1){
        head=current->next;
        delete current;
    }

    else if(pos>1 and pos<Count()){

        for(int i=1;i<pos-1;i++)
        {
          current=current->next;
        }
		previous=current;
		current = current->next;      
		previous->next=current->next;
        delete current;

      }

	else if(pos==Count()){
		delet();
	}

  }

    int Count()
{
    int i = 0;  // Initialize count
    class Node* current = head;  // Initialize current
    while (current != NULL)
    {
        i++;
        current = current->next;
    }

    return i;
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

    void revDisplay(){
        revDisplay2(head);
        cout<<endl;
    }

    void revDisplay2(Node * current){
        //move to next (till available)
        if(current==NULL) return;
        else{
            //recursion
            revDisplay2(current->next);
            // print while returning
            cout<<current->data<<"->";
        }
    }

    void revLL(){
        Node * temp= head;
        revLL2(head);
        tail=temp;
        temp->next=NULL;
    }

    void revLL2(Node * current){
        //empty list
        if(current==NULL) return;
        //1 node
        else if (current->next==NULL){
            head==current;
            return;
        }
        //for rest of elements
        else{
            revLL2(current->next);
            current->next->next=current;
        }

    }
};


int main()
{

    linkedList l1;

    l1.insert(4);	
    l1.insert(5);
	l1.insert(6);
	l1.insert(7);
    l1.insertAt(1,3);
    l1.display();

    l1.delet();


    l1.display();
    cout<<"No. of elements is: ";
    cout<<l1.Count()<<endl;


    return 0;

}

