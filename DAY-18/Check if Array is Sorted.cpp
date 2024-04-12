// ********************************************** NAIVE SOLN ********************************************************** //


#include<bits/stdc++.h>
using namespace std;

// bool isSorted(int arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]<arr[i])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }



// ************************************************** Efficient Soln *************************************************** //



bool isSorted(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            return false;
        }
    }
    return true;
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
    cout<<"Array is Sorted: "<<isSorted(arr,n);
    return 0;
}