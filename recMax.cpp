#include<iostream>
using namespace std;

//max no in array using recursion

int max(int a[], int n, int b);         // n is the index and b is the starting element for comparision

int main()
{
    int a[10], n;
    cout<<"Enter size\n";
    cin>>n;
    cout<<"Enter array";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"The max element is "<<max(a,n-1,0);
}

int max(int a[], int n, int b)         // n is the index and b is the starting element for comparision
{
    if ( n == 0 )
        return a[0] > b ? a[0] : b;
    else return a[n] > b ? max(a, n-1, a[n]) : max(a, n-1, b);
}