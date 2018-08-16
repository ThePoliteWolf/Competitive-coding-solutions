/*
 author : @itzmv
 */
#include<bits/stdc++.h>
using namespace std;

#define ll int64_t
#define llu uint64_t
#define lli long long int
#define MAX 1000
#define MOD 1000000007
#define mp make_pair
#define fr(i, n) for( int i = 0; i < n; i++)

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

//link :- https://practice.geeksforgeeks.org/problems/special-matrix/0 

int TotalWays(vector < vector < int > > &a, int n, int m)
{
    if(a[0][0] == 0)
        return 0;

    vector < vector < int > > dp(n, vector < int >(m, 0));
    dp[0][0] = 1;

    for(int i = 1; i < n; i++)
    {
        if(a[i][0] == 1)
            dp[i][0] = 1;
        else
            break;
    }

    for(int i = 1; i < m; i++)
    {
        if(a[0][i] == 1)
            dp[0][i] = 1;
        else
            break;
    }


    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(a[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }


    return dp[n - 1][m - 1];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, b;
        cin >> n >> m >> b;
        vector < vector < int > >a(n, vector < int >(m, 1));
        while(b--)
        {
            int x, y;
            cin >> x >> y;
            a[x - 1][y - 1] = 0;
        }

        int ways = TotalWays(a, n, m);
        cout <<  ways ;
    }
    return 0;
}


