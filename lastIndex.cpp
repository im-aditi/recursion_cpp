#include<iostream>
#include<vector>

using namespace std;

//Find the last Index where a given no. occurs, return -1 if the no. is not found

int lastIndex(vector<int> a, int n, int num)
{
    if(a[n] == num)
        return n;                                   //Return index once the element is found
    if(n == 0)
        return -1;                                  //if yhe element is not presentand we have reached the end of the vector, return -1
    else return lastIndex(a, n-1, num);             //else check for previous elements.
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
    cout<<"Enter num to find max index\n";
    cin>>num;
    cout<<"Last Index is "<<lastIndex(a, n-1, num);     //the recursion starts at the end.
}