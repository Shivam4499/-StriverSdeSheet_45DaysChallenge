#include<bits/stdc++.h>
using namespace std;

void moveZeros(int arr[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[count]);
            count++;
        }
    }
}

int main()
{
    int arr[]={2,0,5,0,3,0,0,2,6};
    int n=9;
    moveZeros(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}