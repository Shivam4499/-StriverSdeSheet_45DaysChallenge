// ************************************************ NAIve Soln ***************************************************************** //



#include<bits/stdc++.h>
using namespace std;

// bool ePoint(int arr[],int n)
// {
//     for (int i=0;i<n;i++)
//     {
//         int ls=0,rs=0;
//         for(int j=0;j<i;j++)
//         {
//             ls+=arr[j];
//         }
//         for(int j=i+1;j<n;j++)
//         {
//             rs+=arr[j];
//         }
//         if(ls==rs)
//             return true;
//     }
//     return false;
// }






// ************************************************ Efficient Soln ******************************************************* //



bool ePoint(int arr[],int n)
{
    int rs=0;
    for(int i=0;i<n;i++)
    {
        rs+=arr[i];
    }
    int ls=0;
    for(int i=0;i<n;i++)
    {
        rs-=arr[i];
        if(ls==rs)
            return true;
        ls+=arr[i];
    }
    return false;
}

int main()
{
    int n;
    cout<<"size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res=ePoint(arr,n);
    cout<<res;
    return 0;
}

