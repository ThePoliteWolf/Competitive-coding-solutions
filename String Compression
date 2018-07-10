/*
    author :- @ItzMv
*/
#include<bits/stdc++.h>
#include<string>
#define ll int64_t
#define llu uint64_t
#define lli long long int
#define MAX 1000
#define MOD 1000000007
#define mp make_pair
#define fr(i, n) for( int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
// Link :- https://www.careercup.com/question?id=7449675
string combine(string s, int c, string ans, int i)
{
    ostringstream ss;
    ss << c;
    ans += s[i - 1] + ss.str();
    return ans;
}

string string_compression(string s)
{
    int c = 1;
    string ans = "";
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == s[i - 1])
            c++;
        else
        {
            if(c != 1)
            {
                ans = combine(s, c, ans, i);
            }
            else
                ans += s[i - 1];
            c = 1;
        }
    }
    if(c != 1)
    {
        ans = combine(s, c, ans, s.length() - 1);           // for the last term in string
    }
    else
        ans += s[s.length() - 1];

    return s.length() > ans.length() ? ans : s;
}

int main()
{
    string s;
    cin >> s;
    cout << string_compression(s);
    return 0;
}
