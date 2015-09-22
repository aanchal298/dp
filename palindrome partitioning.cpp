#include<bits/stdc++.h>
using namespace std;

bool isPalindrome( string &s, int first, int last )
{
    while(last > first)
    {
        if( s[last] == s[first] )
        {
            first++;
            last--;
        }
        else return false;
    }

    return true;
}
#define MAX 9999999
int palinPart(string &s, int last, int ind, vector<vector<int> > &dp)
{
    if(ind == (int)s.size() - 1)
    {
        if(isPalindrome(s,last, ind))
            return 0;
        return MAX;
    }
    if(dp[last][ind] != -1)
        return dp[last][ind];

    int part = MAX;

    if(isPalindrome(s,last,ind))
    {
        part = 1 + palinPart(s,ind+1,ind+1,dp);
    }

    int notpart = palinPart(s,last,ind+1,dp);


    dp[last][ind] = min(part,notpart);
    return dp[last][ind];
}

int main()
{
    while(1)
    {
        string s;
        cin>>s;
        vector<vector<int> > dp(1000, vector<int> (1000,-1));
        cout<<palinPart(s,0,0, dp)<<endl;


    }



}
