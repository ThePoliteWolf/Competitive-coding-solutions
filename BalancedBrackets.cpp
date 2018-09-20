 /*
 author : @itzmv
 */
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD (lli)1000003

string isBal(string &s)
{
    stack < char > st;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
            st.push(')');
            
        else if(s[i] == '{')
            st.push('}');
            
        else if(s[i] == '[')
            st.push(']');

        else if(st.empty() || st.top() != s[i])
            return "not balanced";
        else
            st.pop();
    }

    if(st.empty())
        return "balanced";
    else
        return "not balanced";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << isBal(s) << "\n";
    }
	return 0;
}
