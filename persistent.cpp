#include <bits/stdc++.h>

using namespace std;

int isAllneg(vector < int > a)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] > -1)
            return 0;
    }
    return 1;
}

int findMax(vector < int > a)
{
    int mx = a[0];
    for(int i = 1; i < a.size(); i++)
    {
        mx = max(a[i], mx);
    }
    return mx;
}

void maxAdjSumarray(vector < int > &a, int n)
{
    vector < int > dp(a.size() + 1);
    dp[0] = 0;
    dp[1] = a[0];

    for(int i = 2; i < dp.size(); i++)
    {
        if(a[i])
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1]);
    }

    /*for(int i = 0; i < dp.size(); i++)
        cout << dp[i] << " ";*/

    cout << "\n";

    int size = dp.size();
    if(dp[size - 1] == dp[size - 2])
    {
        if(a[n - 1] >= a[n - 2])
        {
            for(int i = n - 1; i >= 0; i-=2)
                if(a[i] > 0)
                    cout << a[i];
        }
        else
        {
            for(int i = n - 2; i >= 0; i-=2)
                if(a[i] > 0)
                    cout << a[i];
        }
        /*vector < int > frst;
        vector < int > scnd;

        for(int i = n - 1; i >= 0; i-=2)
            frst.push_back(a[i]);

        for(int i = n - 2; i >= 0; i-=2)
            scnd.push_back(a[i]);*/
    }
    else
    {
        for(int i = n - 1; i >= 0; i-=2)
                if(a[i] > 0)
                    cout << a[i];
    }





}
/*
5
5
-1 7 8 -5 4
4
3 2 1 -1
4
11 12 -2 -1
4
4 5 4 3
4
5 10 4 -1
*/
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector < int > a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(isAllneg(a))
        {
            cout << findMax(a);
        }
        else
        {
            vector < int > chng = a;

            //change all negtaive to zero
            for(int i = 0; i < chng.size(); i++)
            {
                if(chng[i] < 0)
                    chng[i] = 0;
            }
            maxAdjSumarray(chng, n);
        }

    }
    return 0;
}
