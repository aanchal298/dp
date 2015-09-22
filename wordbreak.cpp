string getString(string &A, int first, int last)
{
    string t;
    for(int i = first; i<= last; i++)
        t.push_back(A[i]);
    return t;
}

int solve(string &A, int last, int ind, map<string,bool> &dict,  vector<vector<int> > &dp)
{
    if(ind == (int)A.size() - 1)
    {
        if( dict[ getString(A,last,ind) ] )
            return 1;
        return 0;
    }
    if(dp[last][ind] != -1)
        return dp[last][ind];

    int part = 0;

    if( dict[ getString(A,last,ind) ])
    {
        part = solve(A,ind+1,ind+1,dict,dp);
    }

    int notpart = solve(A,last,ind+1,dict,dp);


    dp[last][ind] = part || notpart;
    return dp[last][ind];
}

int wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    map<string,bool> dict;
    for(int i = 0 ; i<B.size(); i++)
        dict[B[i]] = true;
    vector<vector<int> > dp (A.size(), vector<int> (A.size(), -1));
    return solve( A, 0, 0, dict, dp );

}


int main()
{
    while(1)
    {
        string A;
        cin>>A;

        int n;
        cin>>n;
        vector<string> B;
        for(int i = 0 ; i<n ; i++)
        {
            cin>>B[i];
        }
        cout<<wordBreak(A,B)<<endl;
    }


}
