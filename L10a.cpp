#include <iostream>
using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b; 
    b = temp;
}

void displayArray (int *arr, int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}   

void swapAlternate(int *arr, int size){
    for( int i = 0; i<size; i+=2) {
        if(i+1 <= size){
            swap(arr[i], arr[i+1]);
        }
    }
}

int main (int argc, char *argv[]) {
    int arr[] = {2, 4, 5, 2, 5, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout << size <<endl;
    swapAlternate(arr, size);
    displayArray(arr, size);
    return 0;
}