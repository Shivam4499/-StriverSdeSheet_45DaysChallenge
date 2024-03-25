// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times 
// in the given array. You may consider that such an element always exists in the array.


#include<bits/stdc++.h>
using namespace std;



// ********************************************** Brute Force Soln ******************************************************* //


//  T.C ==> O(N^2)        S.C ==> O(1)



// int majorityElement(vector<int> &arr)
// {
//     int n=arr.size();
//     for(int i=0;i<n;i++)
//     {
//         int cnt=0;
//         for(int j=0;j<n;j++)
//         {
//             if(arr[j]==arr[i])
//             {
//                 cnt++;
//             }
//         }
//         if(cnt>(n/2))
//             return arr[i];
//     }
//     return -1;
// }

// int main()
// {
//     vector<int> arr={2,2,1,1,1,2,2};
//     int ans=majorityElement(arr);
//     cout<<"Majority Element is: "<<ans;
//     return 0;
// }






// *********************************************** Better Solution ***************************************************** //


//   T.C  ==> O(NlogN) + O(N)     S.C ==> O(N)


// int majorityElement(vector<int> &arr)
// {
//     int n=arr.size();
//     map<int,int> mp;
//     for(int i=0;i<n;i++)
//     {
//         mp[arr[i]]++;
//     }
//     for(auto it:mp)
//     {
//         if(it.second>(n/2))
//             return it.first;
//     }
//     return -1;
// }

// int main()
// {
//     vector<int> arr={2,2,1,1,1,2,2};
//     int ans=majorityElement(arr);
//     cout<<"Majority Element is: "<<ans;
//     return 0;
// }





// *********************************************** Optimal Solution(Moore's Voting Algorithm) ******************************************************** //


//   T.C ==> O(N) + O(N)     S.C ==> O(1)



int majorityElement(vector<int> &arr)
{
    int n= arr.size();
    int cnt=0;
    int ele;
    for(int i=0;i<n;i++)
    {
        if(cnt==0)
        {
            cnt=1;
            ele=arr[i];
        }
        else if(arr[i]==ele)
        {
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            cnt1++;
        }
    }
    if(cnt1>(n/2))
        return ele;
    return -1;    
}

int main()
{
    vector<int> arr={2,2,1,1,1,1,1,2,2};
    int ans=majorityElement(arr);
    cout<<"Majority Element is: "<<ans;
    return 0;
}
