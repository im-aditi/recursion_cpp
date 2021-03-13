#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

//Given a keypad digit sequence, find the words that can be generated.
//eg if user presses 123, one sequence is adg (1->(a/b/c), 2->(d/e/f), 3->(g/h/i))

/*
----------------------------------------------------------------------------
PARAMETERS
----------------------------------------------------------------------------
num :   Keypad Sequence
res :   vector which will store all the subsequences
key :   vector containing the alphabets for each no. at index = no.
----------------------------------------------------------------------------
RETURN TYPE: void
CALLS: getKeypad (Recursive)
CALLED FROM: main (Initial Call)
----------------------------------------------------------------------------
*/
void getKeypad(int num, vector<string> &res, vector<string> key)
{
    if(num % 10 == num)                                 //Checks if the no. is single digit
    {
        for(int i = 0; i < key[num].size(); i++)
        {
            res.push_back(string(1,key[num][i]));       //append all letters at that no. separately
        }
    }
    else
    {
        int n = num % 10;                               //Storing the last digit
        num = num / 10;                                 //Knocking off the last digit
        getKeypad(num, res, key);                       //Recursive call
        int size = res.size();                          //Since size increases in the loop, we store it beforehand
        for(int i = 0; i < size; i++)                   //We will append the characters at current digit to all the elements in res
        {
            for(int j = 0; j < key[n].size(); j++)      //Iterating over all characters for that no.
            {
                string t = res[i] + key[n][j];          //Appending the characters
                res.push_back(t);                       //Appending the generated string in the vector
            }
        }
    }
}

//main method
int main()
{
    vector<string> key;
    //Appending the characters at the position of the no. i.e. key[i] will contain the characters at ith key 
    key.push_back("?!");                                //key 0
    key.push_back("abc");
    key.push_back("def");
    key.push_back("ghi");
    key.push_back("jkl");
    key.push_back("mnop");
    key.push_back("qrst");
    key.push_back("uv");
    key.push_back("wxyz");
    key.push_back(".,");                                //key 9
    vector<string> res;
    int num,dig;
    cout<<"Enter sequence of keys pressed\n";
    cin>>num;
    dig = log10(num) + 1;                           //no. of digits in an integer
    getKeypad(num, res, key);                       //Initial method call
    for(int i = 0; i < res.size(); i++)
    {
        if(res[i].size() == dig)                    //Only print those sequences that are complete
            cout<<res[i]<<endl;
    }
    return 0;
}