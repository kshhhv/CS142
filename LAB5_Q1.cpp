#include<iostream>
using namespace std;

void swp(int* a, int* b)                            // function to swap address of element
{
    int t = *a;
    *a = *b;
    *b = t;
}

int prtition (int arr[], int l, int h){
    int pivot= arr[h];                 // pivot
    int pi= (l - 1);                   // Index of smaller element

    for(int i=l;i<=h-1;i++){
        if (arr[i]<= pivot){
            pi++;                               // increment index of smaller element
            swp(&arr[pi], &arr[i]);             //swap i th element with current p index
        }
    }
    swp(&arr[pi + 1], &arr[h]);                 //swap the last element
    return pi+1;                                //return the index of pivot
}

void quicksort(int arr[],int l,int h){                            //divides array
    int p;
    if(l<=h){
        p=prtition(arr,l,h);                                        //refer partition
        quicksort(arr,l,p-1);                                       //lower half recurse to sort
        quicksort(arr,p+1,h);                                       //upper half recurse to sort
    }
}


void display(int arr[], int n){                             // output array
    cout<<"Display:"<<endl;

    for(int i=0;i<n;i++){                                   // loop to access every element of array
        cout<<arr[i];
    }
    cout<<endl;
}

int main(){
    int n=10;                                                  //take an array
    int arr[n]={9,4,2,5,1,3,6,0,7,5};

    cout<<"Input array: "<<display(arr,n)<<endl;;              //display array

    quicksort(arr,0,n-1);                                      //sorts array
    cout<<"Sorted array"<<display(arr,n)<<endl;                //output sorted array


    return 0;
}
