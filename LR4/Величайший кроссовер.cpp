#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int j = i;   
    int l=2*i+1;    
    int r= 2*i+2;  
    if (l<n && arr[l] > arr[j])
        j=l;

    if (r<n && arr[r] > arr[j])
        j = r;
    if (j != i) {
        swap(arr[i], arr[j]);
        heapify(arr, n, j);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr ;
    int n,x;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
    	cin>>x;
    	arr.push_back(x);
	}
    heapSort(arr);

    for (int i = 0; i < n; i++)
        cout <<arr[i]<<" ";

    return 0;
}
