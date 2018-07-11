/*
    author :- @ItzMv
*/
#include<bits/stdc++.h>
#include<string>
#define ll int64_t
#define llu uint64_t
#define lli long long int
#define MAX 1000001
#define MOD 1000000007
#define mp make_pair
#define fr(i, n) for( int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
//link :- https://www.geeksforgeeks.org/rotate-matrix-90-degree-without-using-extra-space-set-2/
// time complexity : O(n) and space complexity :- O(1)

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        for(int i = 0; i < n; i++)     // in place transpose
            for(int j = i + 1; j < n; j++)
                swap(a[i][j], a[j][i]);


        for(int i = 0; i < n/2; i++)   // reversing the column of transpose
        {
            for(int j = 0; j < n; j++)
                swap(a[i][j], a[n - 1 - i][j]);
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cout << a[i][j] << " ";

        cout << "\n";

    }
    return 0;
}
