// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR 
// of all elements equal to k.


#include<bits/stdc++.h>
using namespace std;




// ***************************************************** Brute Force Solution ********************************************* //



//  T.C  ==> O(N^2)    S.C ==> O(1)



// int subarrayWithXor(vector<int> &arr,int k)
// {
//     int n=arr.size();
//     int cnt=0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             int xr=0;
//             for(int k=i;k<=j;k++)
//             {
//                 xr=xr^arr[k];
//             }
//             if(xr==k)
//                 cnt++;
//         }
//     }
//     return cnt;
// }

// int main()
// {
//     vector<int> arr={4, 2, 2, 6, 4};
//     int k=6;
//     int cnt=subarrayWithXor(arr,k);
//     cout<<"Numbers of subarray with Xor K is: "<<cnt<<endl;
//     return 0;
// }





// ************************************************ Better Solution ******************************************************* //


//    T.C ==> O(N^2)   S.C ==> O(1)



// int subarrayWithXor(vector<int> &arr,int k)
// {
//     int n=arr.size();
//     int cnt=0;
//     for(int i=0;i<n;i++)
//     {
//         int xorr=0;
//         for(int j=i;j<n;j++)
//         {
//             xorr=xorr^arr[j];
//             if(xorr==k)
//                 cnt++;
//         }
//     }
//     return cnt;
// }

// int main()
// {
//     vector<int> arr={4, 2, 2, 6, 4};
//     int k=6;
//     int cnt=subarrayWithXor(arr,k);
//     cout<<"Numbers of subarray with Xor K is: "<<cnt<<endl;
//     return 0;
// }







// ************************************************** Optimal Solution ************************************************* //



int subarrayWithXor(vector<int> &arr,int k)
{
    int n=arr.size();
    int cnt=0;
    int xr=0;
    map<int,int> mp;
    mp[xr]++;
    for(int i=0;i<n;i++)
    {
        xr=xr^arr[i];
        // k
        int x=xr^k;
        cnt+=mp[x];
        mp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr={4, 2, 2, 6, 4};
    int k=6;
    int cnt=subarrayWithXor(arr,k);
    cout<<"Numbers of subarray with Xor K is: "<<cnt<<endl;
    return 0;
}
