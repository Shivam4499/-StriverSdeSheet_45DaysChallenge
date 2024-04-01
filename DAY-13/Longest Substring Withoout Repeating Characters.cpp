// Problem Statement: Given a String, find the length of longest substring without any repeating character.


#include<bits/stdc++.h>
using namespace std;




// *************************************************** NAIVE SOLN ***************************************************** //



int solve(string str)
{
    if(str.size()==0)
        return 0;
    int maxans=INT_MIN;
    for(int i=0;i<str.length();i++)
    {
        unordered_set<int> s;
        for(int j=i;j<str.length();j++)
        {
            if(s.find(str[j])!=s.end())
            {
                maxans=max(maxans,j-i);
                break;
            }
            s.insert(str[j]);
        }
    }
    return maxans;
}


int main()
{
    string str="abcabcbb";
    cout<<"Longest substring is:"<<solve(str);
    return 0;
}