/*
 author : @itzmv
 */
#include<bits/stdc++.h>
using namespace std;

#define ll int64_t
#define llu uint64_t
#define lli long long int
#define INF 12345

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
/*
https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem
3 5
1 2 2
1 3 6
2 3 1
2 1 3
3 2 2

*/

int main()
{
        int n, m;
        cin >> n >> m;
        vector < vector < int > > a(n, vector < int >(n, INF));


        for(int i = 0; i < m; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            a[x - 1][y - 1] = w;
        }

        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    a[i][j] = 0;
            }
        }


        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n ; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(a[i][j] > a[i][k] + a[k][j])
                        a[i][j] = a[i][k] + a[k][j];
                }
            }
        }


        int q;
        cin >> q;
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            if(a[x - 1][y - 1] == INF)
                cout << "-1\n";
            else
                cout << a[x - 1][y - 1] << "\n";
        }

    return 0;
}
