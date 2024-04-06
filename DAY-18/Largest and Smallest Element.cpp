// ********************************************* Largest  ********************************************************** //

#include<bits/stdc++.h>
using namespace std;


void largestAndSmallest(int arr[],int n)
{
    int largest=0,smallest=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[largest])
        {
            arr[largest]=arr[i];
            largest=i;
        }
        if(arr[i]<arr[smallest])
        {
            arr[smallest]=arr[i];
            smallest=i;
        }
    }
}

int main()
{
    int arr[]={2,5,7,3,8,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int largest,smallest;
    largestAndSmallest(arr,n);
    cout<<"Index of the Largest"<<largest<<endl;
    cout<<"Index of the Smallest"<<smallest<<endl;
    cout<<"Largest Element"<<arr[largest]<<endl;
    cout<<"Smallest Element"<<arr[smallest];
}