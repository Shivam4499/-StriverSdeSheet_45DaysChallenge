// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which 
// contains the consecutive elements.



#include<bits/stdc++.h>
using namespace std;



// ********************************************** Brute Force Soln **************************************************** //


//  T.C ==> O(N^2)   S.C ==> O(1)



// bool linearSearch(vector<int> &arr,int num)
// {
//     int n=arr.size();
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==num)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int longestSequence(vector<int> &arr)
// {
//     int n=arr.size();
//     int longest=1;
//     for(int i=0;i<n;i++)
//     {
//         int x=arr[i];
//         int cnt=1;
//         while(linearSearch(arr,x+1)==true)
//         {
//             x+=1;
//             cnt+=1;
//         }
//         longest=max(cnt,longest);
//     }
//     return longest;
// }

// int main()
// {
//     vector<int> arr={6,100,200,1,2,3,4,5};
//     int ans=longestSequence(arr);
//     cout<<"Longest Consecutive Subsequence: "<<ans<<endl;
//     return 0;
// }





// *************************************************** Better Solution ************************************************* //



//   T.C ==> O(NlogN)    S.C ==> O(1)



// int longestSequence(vector<int> &arr)
// {
//     int n = arr.size();
//     sort(arr.begin(),arr.end());
//     int longest=1;
//     int cnt=0;
//     int lastSmaller=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]-1==lastSmaller)
//         {
//             cnt+=1;
//             lastSmaller=arr[i];
//         }
//         else if(arr[i]!=lastSmaller)
//         {
//             cnt=1;
//             lastSmaller=arr[i];
//         }
//         longest=max(longest,cnt);
//     }
//     return longest;
// }


// int main()
// {
//     vector<int> arr={100,101,2,1,1,2,3,4,101,103,102,104,105};
//     int ans=longestSequence(arr);
//     cout<<"longest Consecutive Subsequence: "<<ans<<endl;
//     return 0;
// }



// ********************************************** Optimal Solution ****************************************************** //


//   T.C ==> O(N)    S.C ==> O(N)



int longestSequence(vector<int> &arr)
{
    int n=arr.size();
    if(n==0) return 0;
    int longest=1;
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    for(auto it: s)
    {
        if(s.find(it-1)==s.end())
        {
            int cnt=1;
            int x=it;
            while(s.find(x+1)!=s.end())
            {
                x+=1;
                cnt+=1;
            }
            longest= max(longest,cnt);
        }
    }
    return longest;
}

int main()
{
    vector<int> arr={100,101,2,1,1,2,3,4,101,103,102,104,105};
    int ans=longestSequence(arr);
    cout<<"Longest Consecutive Sequence: "<<ans;
    return 0;
}