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

// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0
// source cracking the coding interview Book question (1.8)
// Time and space complexity :- O(mn) & O(1) resp.

using namespace std;

void NulifyColumn(vector < vector < int > > &a, int k, int m)    // set whole column k to zero
{
    for(int i = 0; i < m; i++)
        a[i][k] = 0;
}

void NulifyRow(vector < vector < int > > &a, int k, int n)       // set whole row k to zero
{
    for(int i = 0; i < n; i++)
        a[k][i] = 0;
}

void zeroMatrix(vector < vector < int > > &a, int m, int n)
{
    int rhz = 0;
    int chz = 0;

    for(int i = 0; i < n; i++)    // checking first row
    {
        if(a[0][i] == 0)
        {
            rhz = 1;
            break;
        }
    }

    for(int i = 0; i < m; i++)     // checking first column
    {
        if(a[i][0] == 0)
        {
            chz = 1;
            break;
        }
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(a[i][j] == 0)
            {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(a[0][i] == 0)
        {
            NulifyColumn(a, i, m);
        }
    }

    for(int i = 0; i < m; i++)
    {
        if(a[i][0] == 0)
        {
            NulifyRow(a, i, n);
        }
    }

    if(rhz) NulifyRow(a, 0, n);
    if(chz) NulifyColumn(a, 0, m);

}

int main()
{
    int m, n;
    cin >> m >> n;
    vector < vector < int > > a(m, vector < int > (n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    zeroMatrix(a, m, n);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
