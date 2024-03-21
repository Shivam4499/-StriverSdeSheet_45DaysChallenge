// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.


#include<bits/stdc++.h>
using namespace std;



// ************************************************* Brute Force ************************************************ //

// T.C ==> O(N^3)


// int maxSubarraySum(int arr[],int n)
// {
//     int maximum = INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             int sum=0;
//             for(int k=i;k<j;k++)
//             {
//                 sum=sum+arr[k];
//             }
//             maximum=max(sum,maximum);
//         }
//     }
//     return maximum;
// }

// int main()
// {
//     int arr[]={-2,-3,4,-1,-2,1,5,-3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int maxSum = maxSubarraySum(arr,n);
//     cout<<"max subarray sum is: "<<maxSum;
//     return 0;
// }




// ********************************************** Better Solution ********************************************** //


//   T.C ==> O(N^2)


// int maxSubarraySum(int arr[],int n)
// {
//     int maxi=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         int sum=0;
//         for(int j=i;j<n;j++)
//         {
//             sum+=arr[j];
//         }
//         maxi=max(sum,maxi);
//     }
//     return maxi;
// }

// int main()
// {
//     int arr[]={-2,-3,4,-1,-2,1,5,-3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int maxSum = maxSubarraySum(arr,n);
//     cout<<"max subarray sum is: "<<maxSum;
//     return 0;
// }




// ************************************ Optimal Solution (Kadane's Algorithm) ******************************************** //


//    T.C ==> O(N)


int maxSubarraySum(int arr[],int n)
{
    int maxi = INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        if(sum>maxi)
        {
            maxi=sum;
        }

        if(sum<0)
        {
            sum=0;
        }
    }
    return maxi;
}

int main()
{
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr,n);
    cout<<"max subarray sum is: "<<maxSum;
    return 0;
}