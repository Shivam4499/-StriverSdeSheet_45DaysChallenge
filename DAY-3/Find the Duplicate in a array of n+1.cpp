// Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number,
// your task is to find the duplicate number.

#include<bits/stdc++.h>
using namespace std;



// ******************************************** Brute force ********************************************* //

//    T.C  ==> O(NlogN) + O(N)    S.C ==> O[1]


// int findDup(vector<int> &arr)
// {
//     int n=arr.size();
//     sort(arr.begin(),arr.end());
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==arr[i+1])
//         {
//             return arr[i];
//         }
//     }
//     return 0;
// }

// int main()
// {
//     vector<int> arr={1,3,4,2,3};
//     cout<<"Duplicate Element is: "<<findDup(arr);
//     return 0;
// }




// ***************************************************** Better Solution *************************************************** //


//     T.C ==> O(N)    S.C ==> O(1)

// int findDup(vector<int> &arr)
// {
//     int n=arr.size();
//     int freq[n+1]={0};
//     for(int i=0;i<n;i++)
//     {
//         if(freq[arr[i]]==0)
//         {
//             freq[arr[i]]+=1;
//         }
//         else{
//             return arr[i];
//         }
//     }
//     return 0;
// }


// int main()
// {
//     vector<int> arr={1,3,4,2,3};
//     cout<<"Duplicate Element is: "<<findDup(arr);
//     return 0;
// }




// ********************************************* Optimal Solution *********************************************** //


int findDup(vector<int> &arr)
{
    int slow=arr[0];
    int fast=arr[0];
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    } while(slow!=fast);
    fast=arr[0];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
}

int main()
{
    vector<int> arr={1,3,4,2,3};
    cout<<"Duplicate Element is:"<<findDup(arr);
    return 0;
}