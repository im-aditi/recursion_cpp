#include<iostream>
#include<vector>
using namespace std;

//Starting out with vectors!!!!

//Finding out the min index of an element in a given array of elements
//Return -1 if the element is not found.

int minIndex(vector<int> a, int n, int num)
{
    if( n == a.size())
        return -1;                                  // Entire vector has been traversed and the element has not been found
    if(a[n] == num)
        return n;                                   //If the element is found, return its index
    else return minIndex(a, n+1, num);              //else continue traversing the vector
}

int main()
{
    vector<int> a;
    int n, num;
    cout<<"Enter array size\n";
    cin>>n;
    cout<<"Enter Array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        a.push_back(num);
    }
    cout<<"Enter num to find min index\n";
    cin>>num;
    cout<<"Min Index is "<<minIndex(a, 0, num);     //Starting from 0th index
}