#include<bits/stdc++.h>
using namespace std;

bool val(char c)
{
    return (c == 'T')? true: false;
}
int ans = 0;

bool recur(string s, int idx = 0, bool value)
{
    if(idx == s.length())
    {   if(value == true)
            ans++;
        return ans;
    }
    if( idx == s.length() - 1 )
        return val(s[idx]);

    bool a = val(s[idx]);
    bool b = val(s[idx+2);




}

int main()
{

    while(1)
    {
        string s;
        cin>>s;
        cout<<recur(s,0);
    }

}
