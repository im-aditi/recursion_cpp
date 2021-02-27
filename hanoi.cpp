#include<iostream>
using namespace std;

void toh(int n, char a, char b, char c)
{
    if(n == 1)
    {
        cout<<"\nMove disk "<<n<<" from "<<a<<" to "<<b;
        return;
    }
    else
    {
        toh(n-1,a,c,b);                                     //move n-1 disks from tower 1 to tower 3 using tower 1
        cout<<"\nMove disk "<<n<<" from "<<a<<" to "<<b;    //move last (nth) disk from tower 1 to tower 2
        toh(n-1,c,b,a);                                     //move n-1 disks from tower 3 to tower 2 using tower 1
    }
}

int main()
{
    int n;
    char a = 'A', b = 'B', c = 'C';                         //Should be user input
    cout<<"Enter no of disks\t";
    cin>>n;
    toh(n, a, b, c);
}
