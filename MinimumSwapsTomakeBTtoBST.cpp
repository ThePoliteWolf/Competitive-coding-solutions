//link - https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/little-monk-and-swaps/
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define MOD (lli)(1e9 + 7)

vector < int > v;

void inorder(vector < int > &a, int index, int n)
{
    if(index >= n)
        return;

    inorder(a, 2 * index + 1, n);
    v.push_back(a[index]);
    inorder(a, 2 * index + 2, n);
}

int main()
{
    int n;
    cin >> n;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    inorder(a, 0, n);

    vector < pair < int, int > > arr(n + 1);

    for(int i = 0; i < n; i++)
    {
        arr[i + 1].first = v[i];
        arr[i + 1].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int vis[(int)1e5 + 1] = {0};

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] || arr[i].second == i)
            continue;

        int c = 0;
        int j = i;
        while(!vis[j])
        {
            vis[j] = 1;
            j = arr[j].second;
            c++;
        }
        if(c > 0)
            ans += c - 1;
    }
    cout << ans << "\n";
    return 0;
}
