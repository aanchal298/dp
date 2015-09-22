#include<bits/stdc++.h>
using namespace std;

int lcs(string s, string t, int i, int j)
{
    if( i >= s.length() || j >= t.length() )
        return 0;

    if(s[i] == t[j])
        return 1 + lcs(s,t,i+1,j+1);

    return max(  lcs(s,t,i,j+1),lcs(s,t,i+1,j) );
}


int lcs(string s, string t, int dp[100][100])
{
    s = "0" + s;
    t = "0" + t;

    for(int i = 1; i< s.length(); i++)
    {
        for(int j = 1; j< t.length(); j++)
        {
            if(s[i] == t[j])
                dp[i][j] = dp[i-1][j-1] +1 ;
            else
                dp[i][j] =  max (dp[i-1][j],dp[i][j-1] ) ;
        }
    }

    return dp[s.length()-1][t.length()-1];
}

void printLCS(int dp[100][100],string s, string t)
{
    s = "0"+s;
    t = "0"+t;

    int i = 1;
    int j = 1;
    string stringlcs;
    while(i < s.length() && j < t.length())
    {   //cout<<i<<" "<<j<<endl;
        if(dp[i][j] == dp[i-1][j-1]+1 && s[i] == t[j])
        {   cout<<s[i];
            i++;
            j++;
        }
        else
            if(dp[i+1][j] > dp[i][j+1])
                i++;
            else
                j++;
    }

    //reverse(stringlcs.begin(),stringlcs.end());
}

int main()
{
    string s , t;
    cin>>s>>t;
    int dp[100][100] = {{0}};
    cout<<lcs(s,t,0,0)<<endl<<lcs(s,t,dp)<<endl;

    printLCS(dp,s,t);
    cout<<endl;
    for(int i = 0 ; i<=s.length() ; i++)
    {
        for(int j = 0; j<=t.length(); j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
