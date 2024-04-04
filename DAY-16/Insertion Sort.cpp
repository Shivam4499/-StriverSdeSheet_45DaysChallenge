// *********************************************** Insertion Sort ********************************************************* //


//   T.C ==> O(N^2)


#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}

int main()
{
    int arr[]={5,4,3,2,1};
    int n=5;
    insertionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}