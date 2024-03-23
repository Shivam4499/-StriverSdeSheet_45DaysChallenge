// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive.
// Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating
// and missing numbers A and B where A repeats twice and B is missing.

#include<bits/stdc++.h>
using namespace std;



// ************************************************* Brute Force Solution ************************************************** //


//   T.C  ==> O(N^2)    S.C ==> O(1)

// vector<int> findMissingRepeatingNum(vector<int> &arr)
// {
//     int n=arr.size();
//     int missing=-1,repeating=-1;
//     for(int i=1;i<=n;i++)
//     {
//         int cnt=0;
//         for(int j=0;j<n;j++)
//         {
//             if(arr[j]==i)
//             {
//                 cnt++;
//             }
//         }
//         if(cnt==2)
//             repeating=i;
//         else if(cnt==0)
//             missing=i;
//         if(repeating!=-1 && missing!=-1)
//             break;
//     }
//     return {repeating,missing};
// }

// int main()
// {
//     vector<int> arr={4,3,6,2,1,1};
//     vector<int> ans = findMissingRepeatingNum(arr);
//     cout<<"Repeating and Missing Number is: {"<<ans[0]<<","<<ans[1]<<"}";
//     return 0;

// }




// ************************************************ Better Solution ********************************************** //


//    T.C  ==> O(2N)   S.C ==> O(N)


// vector<int> findMissingRepeatingNum(vector<int> &arr)
// {
//     int n = arr.size();
//     int hash[n+1] = {0};
//     for(int i=0;i<n;i++)
//     {
//         hash[arr[i]]++;
//     }
//     int repeating=-1,missing=-1;
//     for(int i=1;i<=n;i++)
//     {
//         if(hash[i]==2)
//             repeating=i;
//         else if(hash[i]==0)
//             missing=i;
//         if(missing!=-1 && repeating!=-1)
//             break;    
//     }
//     return {repeating,missing};
// }



// int main()
// {
//     vector<int> arr={4,3,6,2,2,1};
//     vector<int> ans = findMissingRepeatingNum(arr);
//     cout<<"Repeating and Missing Number is: {"<<ans[0]<<","<<ans[1]<<"}";
//     return 0;

// }




// *************************************************** Optimal Solution 1 ********************************************** //


//    T.C ==> O(N)    S.C ==> O(1)


// vector<int> findMissingRepeatingNum(vector<int> &arr)
// {
//     long long n=arr.size();
//     // val1 = S - Sn ==> x-y
//     // val2 = S2 - S2n  ==> (x-y)(x+y)
//     // x+y = val2/val1;
//     long long Sn = (n*(n+1))/2;
//     long long S2n = (n*(n+1)*(2n+1))/6;
//     long long S = 0, S2 =0;
//     for(int i=0;i<n;i++)
//     {
//         S += arr[i];
//         S += (long long)arr[i] * (long long)arr[i];
//     }
//     long long val1 = S-Sn;  //x-y
//     long long val2 = S2-S2n; // (x-y)(x+y)
//     val2 = val2/val1;       // (x+y)
//     long long x = (val1 + val2)/2;
//     long long y = val2 -x;
//     return {(int)x,(int)y};
// }



// int main()
// {
//     vector<int> arr={4,3,6,2,2,1};
//     vector<int> ans = findMissingRepeatingNum(arr);
//     cout<<"Repeating and Missing Number is: {"<<ans[0]<<","<<ans[1]<<"}";
//     return 0;

// }




// *************************************************** Optimal Solution 2 ************************************************* //


vector<int> findMissingRepeatingNum(vector<int> &arr)
{
    long long n =arr.size();
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^arr[i];
        xr=xr^(i+1);
    }
    int bitNo=0;
    while(1){
        if((xr & (1<<bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++)
    {
        // part of 1 club
        if((arr[i] & (1<<bitNo)) !=0)
        {
            one=one^arr[i];
        }
        // part of 0 club
        else
        {
            zero=zero^arr[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if((i & (1<<bitNo))!=0)
        {
            one=one^i;
        }
        else{
            zero=zero^i;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==zero)
        {
            cnt++;
        }
        if(cnt==2) return {zero,one};
        return {one,zero};
    }
}



int main()
{
    vector<int> arr={4,3,6,3,2,1};
    vector<int> ans = findMissingRepeatingNum(arr);
    cout<<"Repeating and Missing Number is: {"<<ans[0]<<","<<ans[1]<<"}";
    return 0;

}