// *********************************************** Efficient Soln ******************************************************* //


#include<bits/stdc++.h>
using namespace std;

int secLargest(int arr[],int n)
{
    int seclar=-1,largest=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[largest])
        {
            seclar=largest;
            largest=i;
        }
        else if(arr[i]!=arr[largest])
        {
            if(seclar==-1 || arr[i]>arr[seclar])
            {
                seclar=i;
            }
        }
    }
    return seclar;
}


int secSmallest(int arr[],int n)
{
    int secSmall=-1,smallest=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<arr[smallest])
        {
            secSmall=smallest;
            smallest=i;
        }
        else if(arr[i]!=arr[smallest])
        {
            if(secSmall==-1 || arr[i]<arr[secSmall])
            {
                secSmall=i;
            }
        }
    }
    return secSmall;
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
    int seclar=secLargest(arr,n);
    int secsmall=secSmallest(arr,n);
    cout<<"Index of sec Largest: "<<seclar<<endl;
    cout<<"Index of sec smallest: "<<secsmall;
    return 0;
}