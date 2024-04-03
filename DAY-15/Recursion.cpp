// ****************************************** decimal to binary ***********************************************************//


#include<bits/stdc++.h>
using namespace std;

// void decimalTobinary(int n)
// {
//     if(n==0)
//         return;
//     decimalTobinary(n/2);
//     cout<<(n%2);    
// }
// int main()
// {
//     int n;
//     cin>>n;
//     decimalTobinary(n);
// }



// ******************************************* GCD and LCM ********************************************************** //



// int gcd(int a,int b)
// {
//     if(b==0)
//         return a;
//     return gcd(b,a%b);
// }

// int lcm(int a,int b)
// {
//     return (a*b)/gcd(a,b);
// }

// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     cout<<gcd(a,b)<<endl;
//     cout<<lcm(a,b);
//     return 0;
// }




// ************************************************** Print N to 1 *************************************************** //


// void printNto1(int n)
// {
//     if(n==0)
//         return;
//     cout<<n<<" ";
//     printNto1(n-1);
// }

// int main()
// {
//     int n;
//     cin>>n;
//     printNto1(n);
// }




// *********************************************** Print 1 to N ************************************************** //


// void print1toN(int n)
// {
//     if(n==0)
//         return;
//     print1toN(n-1);
//     cout<<n<<" ";    
// }

// int main()
// {
//     int n;
//     cin>>n;
//     print1toN(n);
// }




// ************************************************** Fibonacii series ********************************************* //


// int fib(int n)
// {
//     if(n==0)
//         return 0;
//     if(n==1)
//         return 1;
//     return fib(n-1)+fib(n-2);        
    
// }
// int main()
// {
//     int n;
//     cin>>n;
//     cout<<fib(n);
//     return 0;
// }


// *************************************************** Factorial ***************************************************** //


// int fact(int n)
// {
//     if(n==0)
//         return 1;
//     return n*fact(n-1);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     cout<<fact(n);
//     return 0;
// }




// ************************************************ check for Palindrome ************************************************ //


// bool isPal(int n)
// {
//     int rev=0;
//     int temp=n;
//     while(temp!=0)
//     {
//         int ld=temp%10;
//         rev=rev*10+ld;
//         temp=temp/10;
//     }
//     return (rev==n);
// }

// int main()
// {
//     int n;
//     cin>>n;
//     cout<<isPal(n);
// }



// ************************************************* GET DIGIT SUM ****************************************************** //



int getSum(int n)
{
    if(n==0)
        return 0;
    return (getSum(n/10)+n%10)
}

int main()
{
    int n;
    cin>.n;
    cout<<getSum(n);
}