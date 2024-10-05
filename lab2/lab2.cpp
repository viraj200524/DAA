#include <iostream>
#include <vector>
using namespace std;

void linear_search(vector<int>arr, int k)
{
    if(arr.size() == 0)
    {
        cout << "Error!! vector empty" << endl;
        return;
    }
    int index = -1;
    for(int i = 0; i<arr.size();i++)
    {
        if(arr[i] == k)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    cout << "Element not found" << endl;
    else
    cout << "Element found at index " << index << endl;
}

int binary_search(vector<int>& arr, int left, int right, int k)
{
    if(arr.size() == 0)
    {
        cout << "Error !! Vector empty" << endl;
        return -1;
    }
    if (left > right)
    {
        cout << "Element not found" << endl;
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == k)
    {
        cout << "Element found at index " << mid << endl;
        return mid;
    }
    if (arr[mid] > k)
        return binary_search(arr, left, mid - 1, k); 

    return binary_search(arr, mid + 1, right, k); 
}


int main()
{
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {5, 15, 25, 35, 45, 55, 65};
    vector<int> arr3 = {}; 
    cout << "Linear Search:" << endl;
    linear_search(arr1, 20);  
    linear_search(arr1, 50);  
    linear_search(arr2, 55);  

    
    linear_search(arr1, 100);  
    linear_search(arr3, 20); 

    cout << "\nBinary Search:" << endl;
    
    binary_search(arr1,0,arr1.size()-1, 20);  
    binary_search(arr1,0,arr1.size()-1, 30);  
    binary_search(arr2,0,arr2.size()-1, 55);  

    
    binary_search(arr1,0,arr1.size()-1, 100);  
    binary_search(arr3,0,arr3.size()-1, 20); 

    return 0;
}
