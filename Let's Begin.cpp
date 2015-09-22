#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
    	int n;
    	cin>>n;
        if(n == 1)
            cout<<-1<<endl;
        else if(n%7 == 0)
    	{
    		cout<<n/7<<endl;
    	}
    	else
    	{	int ans = 0;
    		if(n % 7 == 1)
    		{	ans += n/7-1;
    			n = 8;
    		}
    		else
    		{
    			ans += n / 7;
    			n = n % 7;
    		}

    		int A[] = {0,0,1,1,2,1,2,1,2};

    		ans += A[n];
    		cout<<ans<<endl;
    	}
    }

    return 0;
}
