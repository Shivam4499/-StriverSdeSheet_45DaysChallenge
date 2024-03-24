// Problem Statement: You have been given a 2-D array ‘mat’ of size ‘N x M’ where ‘N’ and ‘M’ denote the number of rows 
// and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element 
// of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your
// task is to find if it exists in the given ‘mat’ or not.


#include<bits/stdc++.h>
using namespace std;



// ************************************************* Brute Force Soln *********************************************** //


//   T.C ==> O(N^2)      S.C ==> O(1)


// bool searchMatrix(vector<vector<int>> &matrix,int target)
// {
//     int n=matrix.size(),m=matrix[0].size();
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]==target)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     vector<vector<int>> matrix ={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     searchMatrix(matrix,11)==true ? cout<<"true" : cout<<"false";
//     return 0;
// }





// **************************************************** Better Solution ************************************************** //



//  T.C ==> O(N) + O(logM)     S.C  ==> O(1)



// bool binarySearch(vector<int> &arr,int target)
// {
//     int n=arr.size();
//     int low=0,high=n-1;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if(arr[mid]==target) return true;
//         else if(target>arr[mid]) low=mid+1;
//         else high=mid-1;
//     }
//     return false;
// }
// bool searchMatrix(vector<vector<int>> &matrix,int target)
// {
//     int n=matrix.size(),m=matrix[0].size();
//     for(int i=0;i<n;i++)
//     {
//         if(matrix[i][0]<=target && target<=matrix[i][m-1])
//         {
//             return binarySearch(matrix[i],target);
//         }
//     }
//     return false;
// }

// int main()
// {
//     vector<vector<int>> matrix ={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     searchMatrix(matrix,11)==true ? cout<<"true" : cout<<"false";
//     return 0;
// }




// *************************************************** Optimized Solution *************************************************** //




// T.C ==> O(log(N*M))   S.C ==> O(1)

bool searchMatrix(vector<vector<int>> &matrix,int target)
{
    int n=matrix.size(),m=matrix[0].size();
    int low=0,high=(m*n)-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int row=mid / m , col=mid % m;
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]<target) low=mid+1;
        else high = mid-1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix ={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    searchMatrix(matrix,7)==true ? cout<<"true" : cout<<"false";
    return 0;
}
