#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Given a matrix of m*n, find all the ways of reaching the botom right cell from top left cell if
//you are allowed to go 1 step horizontally or vertically.

/*
----------------------------------------------------------------------------------------
PARAMETERS
----------------------------------------------------------------------------------------
sr :    Source Row
sc :    Source Column
dr :    Destination Row
dc :    Destination Column
----------------------------------------------------------------------------------------
RETURN TYPE: vector<string> containing all possible ways of reaching destination
CALLS: maze (Recursive)
CALLED FROM: main() (initially)
----------------------------------------------------------------------------------------
*/
vector<string> maze(int sr, int sc, int dr, int dc)
{
    if(sr > dr || sc > dc)                  //If we try to exceed the max rowcolumn, then return empty vector
    {
        vector<string> p;
        return p;
    }
    if(sr == dc && sc == dc)                //If we have reached our destination
    {
        vector<string> p;
        p.push_back("");                    //return empty element
        return p;
    }
    else
    {
        vector<string> p1, p2, res;
        p1 = maze(sr + 1, sc, dr, dc);          //First recursive call horizontally
        for(int i = 0; i < p1.size(); i++)
        {
            p1[i].push_back('H');               //Append H
            res.push_back(p1[i]);
        }
        p2 = maze(sr, sc + 1, dr, dc);          //Second recursive call vertically
        for(int i = 0; i < p2.size(); i++)
        {
            p2[i].push_back('V');               //Append V
            res.push_back(p2[i]);
        }
        return res;                             //Return cumulative vector
    }
}

//Main Function
int main()
{
    vector<string> res;
    res = maze(1, 1, 3, 3);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<endl;
    return 0;
}

/*
OUTPUT
 VVHH
 VHVH
 HVVH
 VHHV
 HVHV
 HHVV
*/