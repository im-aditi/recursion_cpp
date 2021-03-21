#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Given an integer n denoting the no. of stairs, print all the ways of climbing to the top if you are
//allowed to take 1, 2 or 3 steps.

/*
----------------------------------------------------------------------------
PARAMETERS
----------------------------------------------------------------------------
n :     no. of stairs
----------------------------------------------------------------------------
RETURN TYPE:    vector<string> containing all paths for current n
CALLS:          stair (Recursive)
CALLED FROM:    main (Initial Call)
----------------------------------------------------------------------------
*/
vector<string> stair(int n)
{
    if(n == 0)                      //When we have reached top, we return a single element ""
    {
        vector<string> res;
        res.push_back("");
        return res;
    }
    else if(n < 0)                  //When the path is not possible, we return an empty vector
    {
        vector<string> res;
        return res;
    }
    vector<string> res1, res2, res3, res;
    res1 = stair(n-1);                          //Recursive call for n-1 stairs
    for(int i = 0; i < res1.size(); i++)
    {    
        res1[i].push_back('1');                 //append 1 to all these paths
        res.push_back(res1[i]);
    }
    res2 = stair(n-2);                          //Recursive call for n-2 stairs
    for(int i = 0; i < res2.size(); i++)
    {    
        res2[i].push_back('2');                 //append 2 to all these paths
        res.push_back(res2[i]);
    }
    res3 = stair(n-3);                          //Recursive call for n-3 stairs
    for(int i = 0; i < res3.size(); i++)
    {    
        res3[i].push_back('3');                 //append 3 to all these paths
        res.push_back(res3[i]);
    }
    return res;                                 //Return the combined vector
}

//Main Function
int main()
{
    vector<string> res;
    //int n;
    //cin>>n;
    res = stair(5);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<endl;
    return 0;
}

/*
OUTPUT
11111
2111
1211
311
1121
221
131
1112
212
122
32
113
23
*/