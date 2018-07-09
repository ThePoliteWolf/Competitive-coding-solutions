/*
    author :- @ItzMv
*/
#include<bits/stdc++.h>
#define ll int64_t
#define llu uint64_t
#define lli long long int
#define MAX 1000
#define MOD 1000000007
#define mp make_pair
#define fr(i, n) for( int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

// link :- https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

int LargestSquareSubMatrix(vector < vector < int > >a, int m, int n)
{
    vector < vector < int > >cache(m, vector < int >(n));

    int largesq_size = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || j == 0)
                cache[i][j] = a[i][j];
            else if(a[i][j] != 0)
            {
                cache[i][j] = min(cache[i][j - 1], min(cache[i - 1][j], cache[i - 1][j - 1])) + 1;
            }

            if(largesq_size < cache[i][j])
                    largesq_size = cache[i][j];
        }
    }
    return largesq_size;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        vector < vector < int > >a(m, vector < int >(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        cout << LargestSquareSubMatrix(a, m, n) << "\n";

    }
    return 0;
}
