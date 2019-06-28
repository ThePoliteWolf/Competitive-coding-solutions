#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define MOD (lli)(1e9 + 7)

//https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem

vector < vector < lli > > mul(vector < vector < lli > >a, vector < vector < lli > > b)
{
    lli w = ((a[0][0]%MOD)*(b[0][0]%MOD) % MOD) + ((a[0][1]%MOD)*(b[1][0]%MOD) % MOD);
    lli x = ((a[0][0]%MOD)*(b[0][1]%MOD) % MOD) + ((a[0][1]%MOD)*(b[1][1]%MOD) % MOD);

    lli y = ((a[1][0]%MOD)*(b[0][0]%MOD) % MOD) + ((a[1][1]%MOD)*(b[1][0]%MOD) % MOD);
    lli z = ((a[1][0]%MOD)*(b[0][1]%MOD) % MOD) + ((a[1][1]%MOD)*(b[1][1]%MOD) % MOD);

    a[0][0] = w;
    a[0][1] = x;
    a[1][0] = y;
    a[1][1] = z;

    return a;
}

lli nthFib(lli a, lli b, lli n)
{


    vector < vector < lli > > res = {{1, 1},{1, 1}};
    vector < vector < lli > >f =    {{1, 1},{1, 0}};
    //fast matrix exponention method
    while(n)
    {
        if(n % 2 == 1)
            res = mul(res, f);
        f = mul(f, f);
        n /= 2;
    }

    return ( (res[0][0]*b)%MOD + (res[0][1]*a) % MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        lli a, b, n;
        cin >> a >> b >> n;
        if(n == 0)
            cout << a << "\n";
        else if(n == 1)
            cout << b << "\n";
        else if(n == 2)
            cout << a + b << "\n";
        else
            cout << nthFib(a, b, n - 2) << "\n";
    }
    return 0;
}
