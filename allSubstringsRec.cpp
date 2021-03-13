#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Print all subsequences of given string using recursion

/*
----------------------------------------------------------------------------
PARAMETERS
----------------------------------------------------------------------------
str :   string for which substrings are to be found
res :   vector containing all the substrings
----------------------------------------------------------------------------
RETURN TYPE: void
CALLS: getss (Recursive)
CALLED FROM: main() (initially)
----------------------------------------------------------------------------
*/
void getss(string str, vector<string> &res)
{
    if(str.size() == 1)                                 //for the first element
    {
        res.push_back("");                              //null string
        res.push_back(string(1,str[str.size()-1]));     //first charater
                                                        //string(n,c)---converts char c into string with 1 occurance
    }
    else
    {
        string temp = str.substr(0, str.size()-1);      //get a substring with 1 less character
        getss(temp, res);                               //get substrings for that string
        int n = res.size();                             //the size of res increases in the loop, hence get the size beforehand  to prevent infinite loop
        for(int i = 0; i < n; i++)
        {
            string t = res[i] + str[str.size()-1];      //append the character to each substring obtained
            res.push_back(t);                           //append the new string into res
        }
    }
}

//main function
int main()
{
    string str = "abc";
    vector<string> res;
    getss(str, res);
    cout<<"All subsequences are:\n";
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<endl;
    return 0;
}

/*
OUTPUT

a
b
ab
c
ac
bc
abc
*/