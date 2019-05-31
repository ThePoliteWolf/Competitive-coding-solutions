#include <bits/stdc++.h>

using namespace std;

int helper(int n);

int solve(int set, int bit[1<<10], const vector<int>& a)
{

    if (set == 0)
    {
        return bit[set] = 0;
    }
    if (bit[set] != -1)
        return bit[set];

    int maxSum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        int bithelper = helper(num);
        if ((set | bithelper) == set)
            maxSum = std::max(solve(set ^ helper(num), bit, a) + num, maxSum);
    }
    return bit[set] = maxSum;
}

int helper(int n)
{
    int helper = 0;
    for (int i = 1; n/i; i*= 10)
    {
        int digit = n/i % 10;
        helper |= 1 << digit;
    }
    return helper;
}

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
        int bit[1<<10];
        for (int i = 0; i < 1 << 10; i++) bit[i] = -1;

        int maxSum = 0;
        for (int i = 0; i < 1 << 10; i++)
        {
            maxSum = std::max(maxSum, solve(i, bit, a));
        }
        cout << maxSum << std::endl;
    }


    return 0;
}
