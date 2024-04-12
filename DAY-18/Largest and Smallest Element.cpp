// ********************************************* NAIVE SOLn  ********************************************************** //




#include<bits/stdc++.h>
using namespace std;




// int getLargest(int arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         bool flag=true;
//         for(int j=0;j<n;j++)
//         {
//             if(arr[j]>arr[i])
//             {
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag==true)
//             return i;
//     }
//     return -1;
// }
// int getSmallest(int arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         bool flag=true;
//         for(int j=0;j<n;j++)
//         {
//             if(arr[j]<arr[i])
//             {
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag==true)
//             return i;
//     }
//     return -1;
// }



// *********************************************** Efficient Soln ********************************************************* //


int getLargest(int arr[],int n)
{
    int lar=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[lar])
        {
            lar=i;
        }
    }
    return lar;
}

int getSmallest(int arr[],int n)
{
    int small=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[small])
        {
            small=i;
        }
    }
    return small;
}


int main()
{
    cout<<"size of array: ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int largest=getLargest(arr,n);
    int smallest=getSmallest(arr,n);
    cout<<"Index of the Largest: "<<largest<<endl;
    cout<<"Index of the Smallest: "<<smallest<<endl;
    return 0;
}