#include <iostream>
using namespace std ;

class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int value){
        data = value;
        left= NULL;
        right= NULL;
    }
};

class BiST{
public:
    Node * root;

BiST(){
    root= NULL;
}

    void insrt(int value){
        if(root == NULL)
            root = new Node(value);
        else insrtkro(root,value);
    }

    void insrtkro(Node * curr, int value){
        //compare the curr data with value
        if (value < curr->data){
            // if value is less than curr, move left and recall
            if(curr->left==NULL){
                    curr->left= new Node(value);
                    return;
            }
            else insrtkro(curr->left, value);
        }

        else{
            //Else move right and call insert
            if(curr->right==NULL){
                    curr->right = new Node(value);
                    return;
            }
            else insrtkro(curr->right, value);
        }

    }
    void display(){
        if(root== NULL)
            cout<<"Tree has nothing to show."<<endl;
        else display2(root);


    }
    void display2(Node * current){
        //display left
        if (current->left != NULL)
            display2(current->left);
        //display current
        cout<<current->data<<",";
        //display right
        if(current->right != NULL)
            display2(current->right);
        else return;

    }
    Node * serch(int value){
        Node * add = serch2(root,value);
        if(add==NULL)
            cout<<"Element not present"<<endl;
        return add;
    }
    Node * serch2(Node * current, int value){
        //if value found or reached the end
        if (current->data == value)
            return current;
        else if (value < current->data){
            if(current-> left == NULL)
                return NULL;
            return serch2 (current->left,value);
        }
        else if (value > current->data){
            if(current-> right == NULL)
                return NULL;
            return serch2(current->right, value);
        }
    }




};

int main(){

    BiST e;
    e.insrt(5);
    e.insrt(3);
    e.insrt(4);
    e.insrt(7);
    e.insrt(0);
    e.insrt(1);
    e.insrt(8);
    e.insrt(6);
    e.insrt(9);
    e.insrt(32);
    e.display();
    cout<<e.serch(32)->data;

return 0;
}
