// ************************************************** Naive Soln **************************************************** //


#include<bits/stdc++.h>
using namespace std;

// int maxAppear(int left[],int right[],int n)
// {
//     int freq[100] = {0};
//     for(int i=0;i<n;i++)
//     {
//         for(int j=left[i];j<=right[i];j++)
//         {
//             freq[j]+=1;
//         }
//     }
//     int res=0;
//     for(int i=1;i<100;i++)
//     {
//         if(freq[i]>freq[res])
//             res=i;
//     }
//     return res;
// }






// ************************************************** Efficient Soln ************************************************ //


int maxAppear(int left[],int right[],int n)
{
    int freq[101]={0};
    for(int i=0;i<n;i++)
    {
        freq[left[i]]++;
        freq[right[i]+1]--;
    }
    int res=0;
    for(int i=1;i<100;i++)
    {
        freq[i]=freq[i-1]+freq[i];
        if(freq[i]>freq[res])
        {
            res=i;
        }
    }
    return res;
}

int main()
{
    int n,m;
    cout<<"size of left arr: ";
    cin>>n;
    cout<<"size of right arr: ";
    cin>>m;
    int left[n];
    for(int i=0;i<n;i++)
    {
        cin>>left[i];
    }
    int right[n];
    for(int i=0;i<n;i++)
    {
        cin>>right[i];
    }
    int res=maxAppear(left,right,n);
    cout<<res;
    return 0;
}

