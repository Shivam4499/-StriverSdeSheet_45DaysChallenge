// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.


#include<bits/stdc++.h>
using namespace std;



// ************************************************ Brute Force ******************************************************* //



//    T.C ==> O(N^3)      S.C ==> O(1)


// int LongestSubarray(vector<int> &arr,long long k)
// {
//     int n=arr.size();
//     int len=0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             long long s=0;
//             for(int k=i;k<j;k++)
//             {
//                 s+=arr[k];
//             }
//             if(s==k)
//                 len=max(len,j-i+1);
//         }
//     }
//     return len;
// }

// int main()
// {
//     vector<int> arr={2,3,5,1,9};
//     long long k=10;
//     int len=LongestSubarray(arr,k);
//     cout<<"Longest Subarray length is: "<<len;
//     return 0;
// }





// ********************************************** Better Naive Soln ****************************************************** //




// int LongestSubarray(vector<int> &arr,long long k)
// {
//     int n=arr.size();
//     int len=0;
//     for(int i=0;i<n;i++)
//     {
//         long long s=0;
//         for(int j=i;j<n;j++)
//         {
//             s+=arr[j];
//             if(s==k)
//                 len=max(len,j-i+1);
//         }
//     }
//     return len;
// }

// int main()
// {
//     vector<int> arr={2,2,5,1,9};
//     long long k=10;
//     int len=LongestSubarray(arr,k);
//     cout<<"Longest Subarray length is: "<<len;
//     return 0;
// }




// ****************************************** Better Soln(Hashing)  Optimal Soln for Zeros and negative ********************************************* //


// int LongestSubarray(vector<int> &arr,long long k)
// {
//     int n =arr.size();
//     long long sum=0;
//     int maxLen=0;
//     map<long long,int> preSumMap;
//     for(int i=0;i<n;i++)
//     {
//         // calculate prefix sum
//         sum+=arr[i];
//         // if sum==k update the maxLen
//         if(sum==k)
//         {
//             maxLen=max(maxLen,i+1);
//         }
//         //calculating sum of remaining i.e x-k
//         long long rem=sum-k; 

//         // calculate the length and update maxlen
//         if(preSumMap.find(rem)!=preSumMap.end())
//         {
//             int len=i-preSumMap[rem];
//             maxLen=max(maxLen,len);
//         }
//         // finally update the map and checking the condition
//         if(preSumMap.find(sum)== preSumMap.end())
//         {
//             preSumMap[sum]=i;
//         }
//     }
//     return maxLen;
// }

// int main()
// {
//     vector<int> arr={2,2,5,1,9};
//     long long k=10;
//     int len=LongestSubarray(arr,k);
//     cout<<"Longest Subarray length is: "<<len;
//     return 0;
// }




// ************************************* Optimal Soln (For only postives) using two pointers **************************//




//   T.C ==> O(N)




int LongestSubarray(vector<int> &arr,long long k)
{
    int n =arr.size();
    long long sum=arr[0];
    int maxLen=0;
    int left=0,right=0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k)
        {
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        sum+=arr[right];
    }
    return maxLen;
}

int main()
{
    vector<int> arr={2,2,5,1,9};
    long long k=10;
    int len=LongestSubarray(arr,k);
    cout<<"Longest Subarray length is: "<<len;
    return 0;
}




