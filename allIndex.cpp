#include<iostream>
#include<vector>

using namespace std;

//Print all the indices where a given element occurs

/*
----------------------------------------------------------------------------
PARAMETERS
----------------------------------------------------------------------------
a :     vector containing all integers
index : vector which will have all the indices where the element is found
n :     current index where we are comparing the element
num:    Element whose occurance we need to find
----------------------------------------------------------------------------
RETURN TYPE: void
CALLS: allIndex (Recursive)
CALLED FROM: main()
DESCRIPTION: Stores all the indices where num occurs in vector a
----------------------------------------------------------------------------
*/
void allIndex(vector<int> a, vector<int> &index, int n, int num)
{
    if(a[n] == num)
        index.push_back(n);                         //If element is found, append the index in the vector
    if(n == 0)
        return;                                     //Return once we reach the beginning of vector
    else allIndex(a, index, n-1, num);              //Recursive call
}


//Main Function
int main()
{
    vector<int> a, index;
    int n, num;
    cout<<"Enter array size\n";
    cin>>n;
    cout<<"Enter Array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        a.push_back(num);
    }
    cout<<"Enter num to find all indices\n";
    cin>>num;
    allIndex(a, index, n-1, num);
    if(index.size() == 0)
        cout<<"Element is absent\n";                    // If no occurance of element is found
    else
    {
        cout<<num<<" is present at following indices";
        for(int i = 0; i < index.size(); i++)
            cout<<endl<<index[i];
    }
    return 0;
}