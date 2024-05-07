#include<iostream>

using namespace std;

void reverseArray(int arr[], int n){
    int mid, temp;

    if (n%2 == 0){
        mid = n/2 -1;
    }
    else{
        mid = n/2;
    }

    for(int i=0; i<=mid; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

int main(){
    int arr[] = {1,3,5,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"\nOriginal Array: ";
    for (int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }

    reverseArray(arr, n);

    cout<<"\nReversed Array: ";
    for (int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }

}