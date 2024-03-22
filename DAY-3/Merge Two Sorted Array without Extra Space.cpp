// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted
// order.Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#include<bits/stdc++.h>
using namespace std;



// ************************************************ Brute Force Soln ************************************************** //


//    T.C ==> O(N+M) + O(N+M)      S.C ==> O(N+M)


// void merge(long long arr1[],long long arr2[],int n,int m)
// {
//     long long arr3[n+m];
//     int left=0;int right=0;
//     int index=0;
//     while(left<n && right<m)
//     {
//         if(arr1[left]<arr2[right])
//         {
//             arr3[index]=arr1[left];
//             left++;index++;
//         }
//         else{
//             arr3[index]=arr2[right];
//             right++;index++;
//         }
//     }
//     while(left<n)
//     {
//         arr3[index++]=arr1[left++];
//     }
//     while(right<m)
//     {
//         arr3[index++]=arr2[right++];

//     }
//     for(int i=0;i<n+m;i++)
//     {
//         if(i<n)
//         {
//             arr1[i]=arr3[i];
//         }
//         else{
//             arr2[i-n]=arr3[i];
//         }
//     }
// }

// int main()
// {
//     long long arr1[] = {1, 4, 8, 10};
//     long long arr2[] = {2, 3, 9};
//     int n = 4, m = 3;
//     merge(arr1, arr2, n, m);
//     cout << "The merged arrays are: " << "\n";
//     cout << "arr1[] = ";
//     for (int i = 0; i < n; i++) {
//         cout << arr1[i] << " ";
//     }
//     cout << "\narr2[] = ";
//     for (int i = 0; i < m; i++) {
//         cout << arr2[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }




// ******************************************** Optimal Soln 1 ********************************************** //


//    T.C ==> O(min(n,m)) + O(nlogn) + O(nlogn)     S.C ==> O(1)


// void merge(long long arr1[],long long arr2[],int n,int m)
// {
//     int left=n-1;
//     int right=0;
//     while(left>=0 && right<m)
//     {
//         if(arr1[left]>arr2[right])
//         {
//             swap(arr1[left],arr2[right]);
//             left--;right++;
//         }
//         else{
//             break;
//         }
//     }
//     sort(arr1,arr1+n);
//     sort(arr2,arr2+m);
// }

// int main()
// {
//     long long arr1[] = {1, 4, 8, 10};
//     long long arr2[] = {2, 3, 9};
//     int n = 4, m = 3;
//     merge(arr1, arr2, n, m);
//     cout << "The merged arrays are: " << "\n";
//     cout << "arr1[] = ";
//     for (int i = 0; i < n; i++) {
//         cout << arr1[i] << " ";
//     }
//     cout << "\narr2[] = ";
//     for (int i = 0; i < m; i++) {
//         cout << arr2[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }




// *************************************************** Optimal Solution-2 ********************************************* //


//    T.C  ==> O(log(N+M)) + O(N+M)      S.C ==> O(1)



void swapIfGreater(long long arr1[],long long arr2[],int ind1,int ind2)
{
    if(arr1[ind1]>arr2[ind2])
    {
        swap(arr1[ind1],arr2[ind2]);
    }
}
void merge(long long arr1[],long long arr2[],int n,int m)
{
    int len=(n+m);
    int gap=(len/2)+(len%2);
    while(gap>0)
    {
        int left=0;
        int right=left+gap;
        while(right<len)
        {
            //three possible condition
            // 1: left on arr1 and right on arr2
            if(left<n && right>=n)
            {
                swapIfGreater(arr1,arr2,left,right-n);
            }
            // 2: both left and right at arr2
            else if(left>=n)
            {
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            // 3: both left and right at arr1
            else{
                swapIfGreater(arr1,arr1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
            gap = (gap/2) + (gap%2);
    }
}


int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
