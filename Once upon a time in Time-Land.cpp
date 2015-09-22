#include<bits/stdc++.h>
using namespace std;

long long recur(vector<int> &numbers, int idx, int k, vector<long long> &dp)
{
    if(idx >= numbers.size())
        return 0;
    if(dp[idx] != -1)
        return dp[idx];

    long long leave = recur(numbers, idx+1,k, dp);
    long long take = recur(numbers, idx+k+1,k, dp);

    if( numbers[idx] + take > take)
        take = numbers[idx] + take;
    dp[idx] = max(leave,take);
    return max(leave, take);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int> numbers(n);
        vector<long long> dp(n,-1);
        for(int i = 0 ; i<n; i++)
        {
            cin>>numbers[i];
        }

        cout<<recur(numbers, 0, k, dp)<<endl;
    }

    return 0;
}
