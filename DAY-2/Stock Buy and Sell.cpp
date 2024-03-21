// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to
// sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


#include<bits/stdc++.h>
using namespace std;


// ************************************************* Brute Force ***************************************************** //


//     T.C ==> O(N^2)   S.C ==> O(1)


// int maxProfit(vector<int> &arr)
// {
//     int maxPro=0;
//     int n= arr.size();
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]>arr[i])
//             {
//                 maxPro = max(arr[j]-arr[i],maxPro);
//             }
//         }
//     }
//     return maxPro;
// }

// int main()
// {
//     vector<int> arr={7,1,5,3,6,4};
//     int maxPro = maxProfit(arr);
//     cout<<"max profit earned is: "<<maxPro<<endl;
//     return 0;
// }






// ************************************************** Optimal Solution ******************************************** //



int maxProfit(vector<int> &arr)
{
    int n= arr.size();
    int maxPro=0;
    int minPrice=INT_MAX;
    for(int i=0;i<n;i++)
    {
        minPrice=min(arr[i],minPrice);
        maxPro= max(arr[i]-minPrice,maxPro);
    }
    return maxPro;
}

int main()
{
    vector<int> arr={7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout<<"max profit earned is: "<<maxPro<<endl;
    return 0;
}