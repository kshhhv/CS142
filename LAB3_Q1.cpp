#include <iostream>
using namespace std;

class Node{
public:
    int data;

    Node * next;
    Node * pre;


    Node(){
        next = NULL;
        pre = NULL;
    }
};

class dLL{
public:
    Node * head;
    Node * tail;

    dLL(){
        head = NULL;
        tail = NULL;
    }

    void insrt(int value){
        Node*temp = new Node;
        temp->data= value;
        if (head==NULL)
            head = temp;
        else{
            Node * current = head;
            while (current->next != NULL){
                current=current->next;
                }
                current->next = temp;
                temp->pre = current;
                temp->next=NULL;


        }
    }


    void display(){
        Node * current = head;
        Node * last;

        cout<<"True order: ";
        while(current != NULL){
            cout<<current->data<<"->";
            last = current;
            current = current->next;

        }


        cout<<endl;
        cout<<"Reverse order: ";
        while(last != NULL){
            cout<<last->data<<"->";
            last = last->pre;

        }
	cout<<endl;
    }

	void insertAt(int pos, int value){
		//reach the place before pos
		Node * current = head;
		int i=1;
		int c= Count();

		if(pos <= c){
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
		temp->pre=current;
		current=current->next;
		current=current->next;
		current->pre=temp;
		}
		else{
		    cout<<"Linked List does not have that many elements." <<endl;
		}
	}

	void delet(){
		//reach the lace before pos
		Node * current = head;
		Node * last;		
	
			while(current->next != NULL){
				current= current->next;
			}
			last = current->pre;
			last->next=NULL;
			delete current;
		}

		


	void deletAt(int pos){
		//reach the lace before pos
		Node * current = head;
		int i=1;
		int c= Count();

		if(pos <= c){
			while (i<pos){
		  		i++;
		  		current = current->next;
		 	}
			Node * previous= current->pre; // previous is behind the node to be deleted
			Node * agla = current->next;	//agla is after the node to be deleted
			previous->next=current->next;
			agla->pre=previous;
			delete current;
		}

		else
			cout<<"List has not that many elements."<<endl;
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

};




int main(){
 dLL dLL1;

   for(int i=1; i<12 ; i++){
        dLL1.insrt(i*i);
   }

    dLL1.display();
	cout<<"No. of elements is: "<<dLL1.Count()<<endl;

	dLL1.insertAt(3,20);

	dLL1.display();
	cout<<"No. of elements is: "<<dLL1.Count()<<endl;

	dLL1.deletAt(3);
	dLL1.delet();

	dLL1.display();
	cout<<"No. of elements is: "<<dLL1.Count()<<endl;

  return 0;

}
