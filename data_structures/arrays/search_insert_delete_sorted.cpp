/* This is a C++ program to search, insert and delete in a sorted array.    
*/

#include <iostream>

using namespace std;

// Function that takes in the array, size of that array and an element to find in that array
int findElementBrute(int arr[], int n, int key){ // This is nice but not effecient for a sorted array

    for (int i=0; i<n; i++){
        if (arr[i] == key){
            return i; // found
        }
    }
    return -1; // not found
}

/**
 * Binary search for finding the index of a key in a sorted array.
 *
 * @param arr The array to be searched.
 * @param low The starting index of the search range.
 * @param high The ending index of the search range.
 * @param key The key to be searched for.
 *
 * @return The index of the key in the array, or -1 if the key is not found.
 *
 * @throws None
 */
int findElementBinSearch(int arr[], int low, int high, int key){ // This is nice but not effecient for a sorted array

    // Iterative form:
    while (low<=high){
        int mid = low + (high - low)/2;

        if (key == arr[mid]){
            return mid;
        }
        if (key > arr[mid]){
            low = mid+1;
        }
        else if (key < arr[mid]){
            high = mid-1;
        }
    }
    return -1; 
}

// Function that takes in the array, size of that array and an element to insert, and the position of insertion
void insertElementBinSearch(int arr[], int n, int key){

    int low = 0;
    int high = n-1;

    while (low<=high){
        int mid = low + (high - low)/2;

        if (key > arr[mid]){
            low = mid+1;
        }
        else if (key < arr[mid]){
            high = mid-1;
        }
    }
    
    int position = low + 1;

    // shift elements to the right
    for(int i=n-1; i>=position-1; i--){
        arr[i+1] = arr[i];
    }

    arr[position-1] = key;
}

/**
 * Inserts an element into a sorted array and returns the new length of the array.
 *
 * @param arr The array to insert the element into.
 * @param n The current length of the array.
 * @param key The element to insert.
 *
 * @return The new length of the array after the element is inserted.
 *
 * @throws None.
 */
int insertElement(int arr[], int n, int key){

    int i;
    for (i = n-1; (i>=0 && arr[i]> key); i--){
        arr[i+1] = arr[i];
    }

    arr[i+1] = key;

    return (n+1);
}

// // Function takes in the array, size of that arrax, and the element to be deleted.
int deleteElement(int arr[], int n, int key){
    
    int position = findElementBinSearch(arr, 0, n-1, key);

    if (position == -1){
        cout<<"\nElement "<< key << " not found.";
        return -1;
    }

    // shift elements to the left
    for(int i=position; i<n; i++){
        arr[i] = arr[i+1];
    }

    return n - 1;
}



int main() {

    int arr[] = {1,3,5,10,30,40};

    int n = sizeof(arr)/sizeof(arr[0]);
    int index, key = 20;

    index = findElementBinSearch(arr, 0, n-1, key);

    if (index >0){
        cout<<"\nFound the element "<<key<<" at position "<< index+1; 
    }
    else{
        cout<< "\nElement "<<key<< " not found";
    }

    int newKey = 45;

    n = insertElement(arr, n, newKey);

    cout<<"\nArray after inertion: ";
    for (int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
    
    newKey = 20;
    n = deleteElement(arr, n-1, newKey);

    if (n != -1){
        cout<<"\nArray after deletion: ";
        for (int i = 0; i<n; i++){
            cout<< arr[i] << " ";
        }
    }

}
