// ************************************* Print Largest and Smallest in Array *********************************************//


#include<bits/stdc++.h>
using namespace std;


// int max(int arr[],int n)
// {
//     int maxi=INT_MIN;
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]>arr[i-1])
//         {
//             maxi=arr[i];
//         }
//     }
//     return maxi;
// }

// int min(int arr[],int n)
// {
//     int mini=INT_MAX;
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]<arr[i-1])
//         {
//             mini=arr[i];
//         }
//     }
//     return mini;
// }

// int main()
// {
//     int n=6;
//     int arr[]={2,5,8,3,9,1};
//     cout<<max(n)<<endl;
//     cout<<min(n);
//     return 0;
// }





// *************************************** Second Largest and Second Smallest ******************************************** //



int secMax(int arr[],int n)
{
    int maxi=-1,secmax=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxi)
        {
            secmax=maxi;
            maxi=arr[i];
        }
        else if(arr[i]!=secmax && arr[i] != maxi){
            secmax=arr[i];
        }
    }
    return secmax;
}

int secMin(int arr[],int n)
{
    int mini=-1,secmin=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            mini=arr[i];
            secmin=mini;
        }
    }
    return secmin;
}
int main()
{
    int n=6;
    int arr[]={2,8,4,7,3,9};
    cout<<secMax(arr,n)<<endl;
    cout<<secMin(arr,n);
    return 0;
}