#include<iostream>
using namespace std;

class Bh{
	public:

	int * hArr;      //array pointer
	int mSize;      //max size of array
	int cSize;      //current size of array

	Bh(int mSize){  	//default constructor
		hArr = new int[mSize];
		this->mSize = mSize;
		cSize = 0;
	}

	void swap(int * a, int * b){          //swap values of elements
		int temp = *a;
		*a = *b;
		*b = temp;
	}


	int parent(int i){                  //parent of i'th position
		return (i-1)/2;
	}

	int left(int i){                    //left child of i'th position
		return (i*2)+1;
	}

	int right(int i){                   //right child of i'th position
		return (i*2)+2;
	}

	int getMin(){                       //returns minimum value of binary heap
		return hArr[0];
	}


	void insert(int value){                 	//insert fun

		if(cSize==mSize){                       		//Case for Heap Overflow
			cout << "Heap Overflow" << endl;
			return;
		}

		int i = cSize++;                        		//Insert the new key at the end
		hArr[i] = value;

		//Check if it breaks the heap property and fix it
        while (i != 0 && hArr[parent(i)] > hArr[i])
        {
            swap(&hArr[i], &hArr[parent(i)]);           //swap elements if conditions break
            i = parent(i);                              //moves to parent for checking at higher level
        }
	}

	void display(){                     	//display fun
        for(int i = 0; i < cSize ; i++){
            cout << hArr[i] << ",";
        }
        cout << endl;
    }


	int extractMin(){        	//extract min

        if (cSize <= 0)
            return INT_MAX;
        if (cSize == 1){
            cSize--;
            return hArr[0];
        }

        int root = hArr[0];                 // Stores the minimum value, remove it from heap
        hArr[0] = hArr[cSize-1];
        cSize--;
        minHeapify(0);

        return root;
    }


	void decreaseKey(int i, int new_val){           //reorder the heap if any element's value is changed
        hArr[i] = new_val;
        while (i != 0 && hArr[parent(i)] > hArr[i]){
            swap(&hArr[i], &hArr[parent(i)]);       //swap elements if conditions break
            i = parent(i);                          //moves to parent for checking at higher level
        }
    }


	void deleteKeyAt(int i){                        //delete i'th element
        decreaseKey(i, INT_MIN);                    // decrease value to INT_MIN
        extractMin();                               // calls extractMin
    }

	void minHeapify(int i)                             //see the defn of heapify
    {
        int l = left(i);                                //index of left child
        int r = right(i);                               //index of right child
        int smallest = i;
        if (l < cSize && hArr[l] < hArr[i])
            smallest = l;
        if (r < cSize && hArr[r] < hArr[smallest])
            smallest = r;                               //smallest is min of left and right
        if (smallest != i)                              //if heap is not in order
        {
            swap(&hArr[i], &hArr[smallest]);            //swaps element in i with smaller child
            minHeapify(smallest);                       //recursion to check for lower level
        }
    }
};

int main(){
    Bh bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
    }
    cout << endl;

    bh1.extractMin();
    bh1.display();
    cout << endl;


    bh1.deleteKeyAt(6);
    bh1.display();
    cout << endl;

	return 0;
}
