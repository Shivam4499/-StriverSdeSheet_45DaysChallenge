// ************************************************* Naive Soln ******************************************************* //


#include<bits/stdc++.h>
using namespace std;


// int getSum(int arr[],int l,int r)
// {
//     int res=0;
//     for(int i=l;i<=r;i++)
//     {
//         res+=arr[i];
//     }
//     return res;
// }

// int main()
// {
//     int n;
//     cout<<"size of array: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int l,r;
//     cout<<"value of l: "<<endl;
//     cin>>l;
//     cout<<"value of r: ";
//     cin>>r;
//     int sum=getSum(arr,l,r);
//     cout<<"Sum is: "<<sum;
// }




// ***************************************** Efficient Solution *************************************************** //


//Prefix getSum

#include <iostream>
#include <cmath>
using namespace std;

int getSum(int ps[], int l, int r){
    if(l==0)
        return ps[r];
    return ps[r]-ps[l-1];
}

int main(){
    int arr[]={2, 8, 3, 9, 6, 5, 4};
    int n=7;
    int ps[n];
    ps[0] = arr[0];
    for(int i=1; i<n; i++)
        ps[i] = ps[i-1]+ arr[i];
   cout<<getSum(ps,1,3); 
    return 0;
}