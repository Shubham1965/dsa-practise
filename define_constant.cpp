/*
*** Run the following code and see that it gives us an error since we are trying to immute an already defined constant variable.
*/

#include <iostream>

using namespace std;

int main() {
    
    const int a = 10;
    cout<<a<<endl;
    // a = 20; // error: assignment of read-only variable 'a'
    cout<<a<<endl;
}