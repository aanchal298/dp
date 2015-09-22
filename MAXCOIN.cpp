#include<bits/stdc++.h>
using namespace std;
map<pair<pair<int,int>,bool>, pair<int,int> > m;

pair<int,int> recur(vector<int> &v, int b, int e, bool turn)
{   //cout<<b<<" "<<e<<" "<<sum1<<" "<<sum2<<" "<<turn<<endl;
    if(m.find({{b,e},turn}) != m.end())
        return m[ { {b,e}, turn }  ];
    int sum1=0,sum2=0;
    if(b == e)
    {
        sum2 += v[e];
        m[ { {b,e}, turn }  ] = {sum1,sum2};
        return {sum1,sum2};
    }
    pair<int,int> result = {0,0};
    if(turn)
    {   pair<int,int> a = recur( v, b+1, e, !turn );a.second+=v[b];
        pair<int,int> t = recur( v, b, e-1,   !turn);t.second+=v[e];

        if(a.second > t.second)
            result = a;
        else if(a.second < t.second)
            result = t;
        else if(a.first < t.first)
            result = a;
        else result = t;

    }
    else
    {
        pair<int,int> a = recur(v, b+1, e, !turn);a.first+=v[b];
        pair<int,int> t =  recur(v,b,e-1,!turn) ;t.first+=v[e];

        if(a.first > t.first)
            result = a;
        else if(a.first < t.first)
            result = t;
        else if(a.second < t.second)
            result = a;
        else result = t;
    }

    m[ { {b,e}, turn }  ] = result;
    return result;
}


int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    cout<<n<<endl;
    vector<int> v(n);

    for(int i = 0 ; i<n ; i++)
        cin>>v[i];
    for(int i = 0 ; i<n ; i++)
        cout<<v[i]<<" ";
    cout<<endl;

    cout<<recur(v,0,n-1,0).first;
}
