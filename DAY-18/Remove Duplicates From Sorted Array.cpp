#include<bits/stdc++.h>
using namespace std;

int remDup(int arr[],int n)
{
    int temp[n];
    temp[0]=arr[0];
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(temp[res-1]!=arr[i])
        {
            temp[res]=arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++)
    {
        arr[i]=temp[i];
    }
    return res;
}

int main()
{
    int n;
    cout<<"size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int newSize = remDup(arr,n);
    cout<<"New size: "<<newSize;
    for(int i=0;i<newSize;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}