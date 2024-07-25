#include <iostream>
#include <vector>
using namespace std; 

bool F(const int arr[], int n) {
    for (int i=0; i<=(n/2)-1; i++) {
        int l=2*i+1;
        int r=2*i+2;

        if (l<n && arr[i]>arr[l]) {
            return false;
        }

        if (r<n && arr[i]>arr[r]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}

    if (F(arr,n)) {
        cout << "YES" ;
    } else {
        cout << "NO" ;
    }

    return 0;
}
