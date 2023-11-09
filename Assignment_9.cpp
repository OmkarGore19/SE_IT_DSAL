/*
Assignment No.: 9.Heap Sort
***********************************************************************************
Problem Statement:Implement Heap sort to sort given set of values using max or min
heap.
***********************************************************************************
*/
#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i){
int largest = i;
int l = 2 * i + 1;
int r = 2 * i + 2;
if (l < n && arr[l] > arr[largest])
largest = l;
if (r < n && arr[r] > arr[largest])
largest = r;
if (largest != i) {
swap(arr[i], arr[largest]);
heapify(arr, n, largest);
}
}
void heapSort(int arr[], int n){
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);
for (int i = n - 1; i > 0; i--) {
swap(arr[0], arr[i]);
heapify(arr, i, 0);
}
}
void display(int arr[], int n){
for (int i = 0; i < n; ++i)
cout << arr[i] << " ";
cout << "\n";
}
int main(){
int n;
cout<<"Enter Size of Array :";
cin>>n;
int arr[n];
//input array elements
for(int i=0;i<n;i++){
cout<<"Enter the Element: ";
cin>>arr[i];
}
heapSort(arr, n);
cout << "Sorted array: ";

display(arr, n);
}
//OUTPUT
/*
Enter Size of Array: 6
Enter the Element: 12
Enter the Element: 4
Enter the Element: 54
Enter the Element: 67
Enter the Element: 25
Enter the Element: 36
Sorted array: 4 12 25 36 54 67
*/