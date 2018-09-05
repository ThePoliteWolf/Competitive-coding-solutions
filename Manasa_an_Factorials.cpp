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

// link = https://www.hackerrank.com/challenges/manasa-and-factorials/problem

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)


// this is used to count number of trailing zeros in m!( ! means factorial)
// for on trailing zeros :- https://brilliant.org/wiki/trailing-number-of-zeros/

ll countingTrailingZeros(ll m)                        
{
    if(m == 0)
        return 0;
    return m/5 + countingTrailingZeros(m/5);
}

// the idea is simple to binary search b/w range 0 to 5*n to find the minimum m which has n trailing zeros.

ll solve(ll n)
{
    ll res = -1;
    ll l = 0;
    ll u = 5*n;

    while(l <= u)
    {
        ll mid = (l + u)/2;

        if(countingTrailingZeros(mid) >= n)
        {
            res = mid;
            u = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
