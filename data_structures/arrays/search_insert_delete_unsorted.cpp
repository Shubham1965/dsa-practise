/* This is a C++ program to search, insert and delete in an unsorted array.    
*/

#include <iostream>

using namespace std;

// Function that takes in the array, size of that array and an element to find in thast array
int findElement(int arr[], int n, int key){

    for (int i=0; i<n; i++){
        if (arr[i] == key){
            return i; // found
        }
    }
    return -1; // not found
}

// Function that takes in the array, size of that array and an element to insert, and the position of insertion
void insertElement(int arr[], int n, int key, int position){

    // shift elements to the right
    for(int i=n-1; i>=position-1; i--){
        arr[i+1] = arr[i];
    }

    arr[position-1] = key;
}

// Function takes in the array, size of that arrax, and the element to be deleted.
void deleteElement(int arr[], int n, int key){
    
    int position = findElement(arr, n, key);

    if (position == -1){
        cout<<"\nElement "<< key << " not found.";
        return;
    }
    
    // shift elements to the left
    for(int i=position; i<n; i++){
        arr[i] = arr[i+1];
    }
}



int main() {

    int arr[] = {20, 15, 60, 37, 69, 13, 7};

    int n = sizeof(arr)/sizeof(arr[0]);
    int index, key = 10;

    index = findElement(arr,n,key);

    if (index >0){
        cout<<"\nFound the element "<<key<<" at position "<< index+1; 
    }
    else{
        cout<< "\nElement "<<key<< " not found";
    }

    int pos = 3;
    int newKey = 45;

    insertElement(arr, n, newKey, pos);
    n++;

    cout<<"\nArray after inertion: ";
    for (int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
    
    newKey = 10;
    deleteElement(arr, n, newKey);
    n--;

    cout<<"\nArray after deletion: ";
    for (int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }

}
