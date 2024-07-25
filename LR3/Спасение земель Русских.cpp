#include <iostream>
using namespace std;

int partison( int a[],int s,int e)
{
	int i=s-1, j=e, pivot=a[e];
	
	for (int j=s; j<e;j++)
	{
		if (a[j]<= pivot)
		{
			i=i+1;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}


void Qsort(int *a,int s,int e)
{
	int q;
	if(s >= e) return;
	q=partison(a,s,e);
	Qsort(a,s,q-1);
	Qsort(a,q+1,e);

}

bool Seat(int arr[], int n, int k, int dl) {
  int j = 1, end = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] - end >= dl)
	{
      j++;
      end = arr[i];
    }
    if (j>=k)
	return true;
  }
  return false;
}


int main() {
  int n, k;
  cin >> n >> k;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) 
  {cin >> arr[i];}

  Qsort(arr, 0, n-1);

  int l=0, r=arr[n-1]-arr[0],res=-1;

  while (l<= r) {
    int mid = l + (r-l) / 2;
    if (Seat(arr, n, k, mid)) {
      res=mid;
      l= mid + 1;
    }
    else r= mid - 1;
  }
  cout << res;

  delete[] arr;
  return 0;
}
