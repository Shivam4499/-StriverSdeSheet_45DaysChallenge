#include<bits/stdc++.h>
using namespace std;


int bSearch(int arr[],int low,int high,int x)
{
    if(low<high)
        return -1;
    int mid=(low+high)/2;
    if(arr[mid]==x)
        return mid;
    else if(arr[mid]>x)
        bSearch(arr,low,mid-1,x);
    else 
        bSearch(arr,mid+1,high,x);
}


int main()
{
    int arr[]={23,28,33,39,45,48};
    int n=6;
    int x=39;
    int low=0,high=n-1;
    cout<<bSearch(arr,low,high,x);
    return 0;
}