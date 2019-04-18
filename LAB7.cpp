#include <iostream>
using namespace std ;

class Node{
public:
    int data;
    Node * left;
    Node * right;
    Node * parent;

    Node(int value){
        data = value;
        left= NULL;
        right= NULL;
        parent= NULL;
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
                    curr->left->parent= curr;
                    return;
            }
            else insrtkro(curr->left, value);
        }

        else{
            //Else move right and call insert
            if(curr->right==NULL){
                    curr->right = new Node(value);
                    curr->right->parent= curr;
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


    Node * find_min(Node * curr){
        if(curr->left != NULL){
            return find_min(curr ->left);
        }
        return curr;
    }

    void replace_with_parent(Node* A, Node* B){
		//if A is not root
		if(A!=root){
			//if A is left child: add B
			if(A->parent->left==A) A->parent->left=B;
			//if A is right child: add B
	        else if(A->parent->right==A) A->parent->right=B;
			//connect B back
	        if(B!=NULL) B->parent=A->parent;
			//disconnect A
	        A->parent=NULL;
		}
		//if root
		else {
			root=B;
		}

	}

	void delet(int value){
		//search node with the value and store the address of node
		Node* remove = serch(value);
		//if not present
		if(remove==NULL){
			cout << value << "Such data not present" << endl;
		}
		//if present
		else{
			//replacement node
			Node* replace ;
			//if the delet node has two children
			if(remove->left!=NULL and remove->right!=NULL){
				//find replacement
				replace = find_min(remove->right);
				//swap values
				int temp=replace->data;
				replace->data=remove->data;
				remove->data=temp;
				//remove the swapped node
				remove=replace;

			}
			//else{
				//if only left child
				if(remove->right==NULL){
					replace = remove->left;
				}
				//if only right child
				else if(remove->left==NULL){
					replace = remove->right;
				}
				//if no child, simply delete
				//replace
				replace_with_parent(remove, replace);
				//if root is removed , replace is new root
				if(root == remove) root = replace;
			//}
			delete remove;
		}
	}


};

int main(){

    BiST e;
    e.insrt(5);
    e.insrt(3);
    e.insrt(4);
    e.insrt(7);
    e.insrt(1);
    e.insrt(8);
    e.insrt(6);
    e.insrt(9);
    e.insrt(32);
    e.display();

    cout<<" minimum from 5:"<<
    cout<<e.find_min(e.serch(5))->data;
    cout<<" minimum from 7:"<<
    cout<<e.find_min(e.serch(7))->data;

    e.delet(32);
    cout<<"Deleted 32, new display: ";
    e.display();



return 0;

}
