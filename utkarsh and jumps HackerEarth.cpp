#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin>>n;
        double p;
        cin>>p;
        vector<double> v(n+10,0);
        p = p/100;
        v[0] = 1;
        double one = 1.0;
        for(int i = 0 ; i<=n ; i++)
        {
            v[i+2] += v[i]*p;
            v[i+3] += v[i]*(one-p);
        }

        printf("%.6f\n",v[n]);

    return 0;
}
