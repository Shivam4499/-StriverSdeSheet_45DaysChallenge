//  Problem Statement: This problem has 3 variations. They are stated below:




//In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below: 





//Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

#include<bits/stdc++.h>
 using namespace std;


// ************************************************ Solution ********************************************* //

// int nCr(int n, int r)
// {
//     long long res=1;
//     for(int i=0;i<r;i++)
//     {
//         res=res*(n-i);
//         res=res/(i+1);
//     }
//     return res;
// }

// int pascalTriangle(int r, int c)
// {
//     int element = nCr(r-1,c-1);
//     return element;
// }

// int main()
// {
//     int r = 5;
//     int c = 3;
//     int element = pascalTriangle(r,c);
//     cout<<"element at (r,c) is: "<<element;
//     return 0;
// }



//Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.


// ********************************************** Naive Solution ******************************************** //

// T.C = O(n*r)   S.C = O(1)

// int nCr(int n,int r)
// { long long res=1;
//     for(int i=0;i<r;i++)
//     {
//         res=res*(n-i);
//         res=res/(i+1);
//     }
//     return res;
// }

// int pascalTriangle(int n)
// {
//     for(int c=1;c<=n;c++)
//     {
//         cout<<nCr(n-1,c-1);
//     }
//     cout<<endl;
// }

// int main()
// {
//     int n=5;
//     pascalTriangle(n);
//     return 0;
// }




// ******************************************** Optimal Solution *************************************************** //

// T.C = O(n)   S.C = O(1)

// void pascalTriangle(int n)
// {
//     long long ans=1;
//     cout<<ans<<" ";
//     for(int i=1;i<n;i++)
//     {
//         ans=ans*(n-i);
//         ans=ans/i;
//         cout<<ans<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     int n=5;
//     pascalTriangle(n);
//     return 0;
// }



//Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.


// *************************************** Naive Solution ******************************************* //

// T.C = O(n*n*r)    S.C = O(1)


// int nCr(int n, int r)
// {
//     long long ans=1;
//     for(int i=0;i<r;i++)
//     {
//         ans=ans*(n-i);
//         ans=ans/(i+1);
//     }
//     return ans;
// }

// vector<vector<int>> pascalTriangle(int n)
// {
//     vector<vector<int>> res;


//     //store the entire pascal's triangle:
//     for(int row=1;row<=n;row++)
//     {
//         vector<int> temp;
//         for(int col=1;col<=row;col++)
//         {
//             temp.push_back(nCr(row-1,col-1));
//         }
//         res.push_back(temp);
//     }
//     return res;
// }

// int main()
// {
//     int n=5;
//     vector<vector<int>> res = pascalTriangle(n);
//     for(auto it: res)
//     {
//         for(auto ele: it)
//         {
//             cout<<ele<<" ";
//         }
//         cout<<endl;
//     }
// }





// ******************************************** Optimal Solution *********************************************** //

// T.C = O(n*n)   S.C = O(1)

vector<int> generateRow(int row)
{
    long long ans=1;
    vector<int> ansRow;       //inserting 1st element
    ansRow.push_back(1);

    //calculate the rest of the elements
    for(int col=1; col<row;col++)
    {
        ans=ans*(row-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}



vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> res;

    //store the entire pascal's triangle:
    for(int row;row<=n;row++)
    {
        res.push_back(generateRow(row));
    }
    return res;
}

int main()
{
    int n=5;
    vector<vector<int>> res = pascalTriangle(n);
    for(auto it: res)
    {
        for(auto ele: it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}