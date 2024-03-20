// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 
// 0 and then return the matrix.


// ********************************************* Brute Force Solution ********************************************** //

// Time Complexity= O((n*m)(n+m)+(n+m))

#include<bits/stdc++.h>
using namespace std;

// // set all non-zero element in row i as -1
// void markRow(vector<vector<int>> &matrix,int n,int m,int i)
// {
//     for(int j=0;j<m;j++)
//     {
//         if(matrix[i][j]!=0)
//         {
//             matrix[i][j]=-1;
//         }
//     }
// }

// // set all non-zero element in col j as -1
// void markCol(vector<vector<int>> &matrix,int n,int m,int j)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(matrix[i][j]!=0)
//         {
//             matrix[i][j]=-1;
//         }
//     }
// }

// vector<vector<int>> setZeros(vector<vector<int>> &matrix,int n, int m)
// {

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]==0)
//             {
//                 markRow(matrix,n,m,i);
//                 markCol(matrix,n,m,j);
//             }
//         }
//     }
//     // now make all the -1 element as 0
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]==-1)
//             {
//                 matrix[i][j]=0;
//             }
//         }
//     }
//     return matrix;
// }

// int main()
// {
//     vector<vector<int>> matrix={{1,1,1},{1,0,1},{1,1,1}};
//     int n= matrix.size();
//     int m= matrix[0].size();
//     vector<vector<int>> ans= setZeros(matrix,n,m);
//     cout<<"the final matrix is:"<<endl;
//     for(auto it:ans)
//     {
//         for(auto ele:it)
//         {
//             cout<<ele<<" ";
//         }
//         cout<<endl;
//     }
// }



// **************************************** Better Solution ************************************************** //

// Time Complexity: O(n*m)  Space Complexity: O(n+m)


// vector<vector<int>> setZeros(vector<vector<int>> matrix)
// {
//     int n= matrix.size();
//     int m= matrix[0].size();
//     vector<int> row(n,0);
//     vector<int> col(m,0);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]==0)
//             {
//                 row[i]=1;
//                 col[j]=1;
//             }
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(row[i]==1 || col[j]==1)
//             {
//                 matrix[i][j]=0;
//             }
//         }
//     }
//     return matrix;
// }

// int main()
// {
//     vector<vector<int>> matrix= {{1,1,1,1},{1,0,1,1},{0,1,0,1},{1,0,0,1}};
//     vector<vector<int>> ans= setZeros(matrix);
//     cout<<"final matrix is: "<<endl;
//     for(auto it: ans)
//     {
//         for(auto ele: it)
//         {
//             cout<<ele<<" ";
//         }
//         cout<<endl;
//     }

// }



// ******************************************* Optimal Solution ***************************************** //


 vector<vector<int>> setZeros(vector<vector<int>> matrix)
 {
    int col0 =1;
    int n=matrix.size();
    int m=matrix[0].size();
    // vector<int> row(n,0)  ->   matrix[.][0]
    // vector<int> col(m,0)  ->   matrix[0][.]

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                //mark ith row
                matrix[i][0]=0;
                //mark jth col
                if(j!=0)
                {
                    matrix[0][j]=0;
                }
                else
                {
                    col0=0;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(matrix[i][j]!=0)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0)
    {
        for(int j=0;j<m;j++)
        {
            matrix[0][j]=0;
        }
    }
    if(col0==0)
    {
        for(int i=0;i<n;i++)
        {
            matrix[i][0]=0;
        }
    }
    return matrix;
 }

 int main()
 {
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> ans = setZeros(matrix);
    cout<<"final matrix is: "<<endl;
    for(auto it: ans)
    {
        for(auto ele: it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
 }