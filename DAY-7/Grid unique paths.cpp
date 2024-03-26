// Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints 
// that from each cell you can either only move to the rightward direction or the downward direction.





#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
     int countPaths(int i,int j,int n,int m)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       return countPaths(0,0,m,n);
    }
};
int main()
{
    Solution obj;
    int totalCount= obj.uniquePaths(3,7);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}