// ************************************************ MERGE SORT ********************************************************* //



#include<bits/stdc++.h>
using namespace std;

// void mergeSort(int a[],int b[],int m,int n)
// {
//     int i=0,j=0;
//     while(i<m && i<n)
//     {
//         if(a[i]<=b[j])
//         {
//             cout<<a[i]<<" ";
//             i++;
//         }
//         else
//         {
//             cout<<b[j]<<" ";
//             j++;
//         }
//     }
//     while(i<m)
//     {
//         cout<<a[i]<<" ";
//         i++;
//     }
//     while(j<n)
//     {
//         cout<<b[j]<<" ";
//         j++;
//     }
// }

// int main()
// {
    
//     int a[]={1,5,9,11};
//     int b[]={4,8,10,13};
//     int m=4;
//     int n=4;
//     int c[m+n];
//     mergeSort(a,b,m,n);
//     for(int i=0;i<m+n;i++)
//     {
//         if(i<m)
//         {
//             c[i]=a[i];
//         }
//         else
//         {
//             c[i]=a[i];
//         }
//     }
//     return 0;
// }





// ******************************************* Merge Sort Function **************************************************** //




void mergeFunction(int a[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++)
    {
        left[i]=a[low+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=a[mid+i+1];
    }

    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
            k++;
        }
        else
        {
            a[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
}


int main() {
	
    int a[]={10,15,20,40,8,11,15,22,25};
	int low=0,mid=3,high=8;
	
	mergeFunction(a,low,mid,high);
	for(int x: a)
	    cout<<x<<" ";
}