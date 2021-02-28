#include<iostream>
using namespace std;

int maxm(int a[], int n)
{
    if(n == 1)
        return a[0] > a[1] ? a[0] : a[1];
    int num = maxm(a, n-1);
    //return a[n] > maxm(a, n-1) ? a[n] : maxm(a, n-1);
    return a[n] > num ? a[n] : num;
}

int main()
{
    int a[10];
    cout<<"Enter 10 no.s\n";
    for(int i=0; i<10; i++)
        cin>>a[i];
    cout<<"Max Element is "<<maxm(a, 9);
    return 0;
}