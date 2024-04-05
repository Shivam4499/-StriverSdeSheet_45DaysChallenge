#include<bits/stdc++.h>
using namespace std;


int bSearch(int arr[],int n,int k)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]>k)
            high=mid-1;
        else 
            low=mid+1;    
    }
    return -1;
}

int main()
{
    int n=6;
    int arr[]={2,8,5,16,28,45};
    int k=28;

    cout<<bSearch(arr,n,k);
    return 0;
}