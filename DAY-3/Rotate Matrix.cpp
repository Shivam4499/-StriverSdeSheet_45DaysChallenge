//  Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

#include<bits/stdc++.h>
using namespace std;


// ****************************************** Brute Force Soln ************************************************* //


//     T.C ==> O(N^2)      S.C ==> O(N^2)

// vector<vector<int>> rotate(vector<vector<int>> &matrix)
// {
//     int n= matrix.size();
//     vector<vector<int>> rotated(n,vector<int>(n,0));   // Empty matrix of size n*n
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             rotated[j][n-i-1]=matrix[i][j];
//         }
//     }
//     return rotated;
// }

// int main() {
//     vector < vector < int >> arr;
//     arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     vector < vector < int >> rotated = rotate(arr);
//     cout << "Rotated Image" << endl;
//     for (int i = 0; i < rotated.size(); i++) {
//     for (int j = 0; j < rotated[0].size(); j++) {
//         cout << rotated[i][j] << " ";
//     }
//     cout <<endl;
//     }

// }




// ******************************************* Optimal Solution ************************************************* //


//   T.C ==> O(N^2)   S.C ==> O(1)


void rotate(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    // for transpose 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reverse all rows
    for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout<<"Rotated Matrix is: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}