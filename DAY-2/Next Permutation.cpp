//Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next
//greater permutation of numbers.
//If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).



// ********************************************* Brute Force ************************************************** //

// T.C ==> O(N!*N)


// 1 -> find all the possible permutataion in sorted order by using recursion.
// 2 -> Now linear search to get the index of given array.
// 3 -> Now next index permutation is our ans ans if there is no next index then it will print the first permutation.




// ********************************************** Better Solution ******************************************** //



#include<bits/stdc++.h>
using namespace std;

// vector<int> nextPermutation(vector<int> &A)
// {
//     next_permutation(A.begin(),A.end());
//     return A;
// }

// int main()
// {
//     vector<int> A = {2, 1, 5, 4, 3, 0, 0};
//     vector<int> ans= nextPermutation(A);
//     cout<<" the next permutaion is: ";
//     for(auto it: ans)
//     {
//         cout<<it<<" ";
//     }
// }





// ********************************************* Optimal Solution ********************************************* //


// T.C ==> O(3N)

vector<int> nextPermutation(vector<int> &A)
{
    int ind=-1;
    int n= A.size();
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
            ind=i;
            break;
        }
    }
    if(ind==-1)
    {
        reverse(A.begin(),A.end());
        return A;
    }
    else{
        for(int i=n-1;i>0;i--)
        {
            if(A[i]>A[ind])
            {
                swap(A[i],A[ind]);
                break;
            }
        }
        reverse(A.begin()+ind+1,A.end());
    }
    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans= nextPermutation(A);
    cout<<" the next permutaion is: ";
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}