// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using 
// inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)


#include<bits/stdc++.h>
using namespace std;


// ******************************************** Brute Force *********************************************** //

// 1 -> use merge sort to sort the array.
// 2 -> T.C ==> O(NlogN) and space ==> O(N)





// ****************************************** Better Solution ************************************************* //

//   T.C ==> O(2N)


// void sortArray(vector<int> &arr,int n)
// {
//     int cnt0=0,cnt1=0,cnt2=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==0)
//             cnt0++;
//         else if(arr[i]==1)
//             cnt1++;
//         else
//             cnt2++;
//     }
//     for(int i=0;i<cnt0;i++)
//     {
//         arr[i]=0;
//     }
//     for(int i=cnt0;i<(cnt0 + cnt1);i++)
//     {
//         arr[i]=1;
//     }
//     for(int i=(cnt0+cnt1);i<n;i++)
//     {
//         arr[i]=2;
//     }
// }

// int main()
// {
//     int n=6;
//     vector<int> arr={0, 2, 1, 2, 0, 1};
//     sortArray(arr,n);
//     cout<<"After Sorting"<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }




// ******************************************** Optimal Solution ***************************************** //


//   T.C ==> O(N)  space = O(1)

void sortArray(vector<int> &arr,int n)
{
    int low=0,mid=0,high=0;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    int n=6;
    vector<int> arr={0, 2, 1, 2, 0, 1};
    sortArray(arr,n);
    cout<<"After sort array is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}



