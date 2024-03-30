// Longest Subarray with sum K | [Postives and Negatives]
// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.


#include<bits/stdc++.h>
using namespace std;



// ********************************************* Brute Force **************************************************** //



//   T.C ==> O(N^3)



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




// ******************************************************* Better Solution *********************************************** //


//  T.C ==> O(N^2)



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





// **************************************************** Optimal Solution ************************************* //



int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = { -1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
