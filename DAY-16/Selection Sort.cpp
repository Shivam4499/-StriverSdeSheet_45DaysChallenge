// ******************************************** Selection Sort ******************************************************** //



//   T.C ==> O(N^2)    



#include<bits/stdc++.h>
using namespace std;


void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_ind])
            {
                min_ind=j;
            }
        }
        swap(arr[i],arr[min_ind]);
    }
}

int main()
{
    int arr[]={5,4,3,2,1};
    int n=5;
    selectionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}