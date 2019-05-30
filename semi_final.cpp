#include<bits/stdc++.h>
using namespace std;

#define lli long long int

set < int > numToDigits(int n)
{
    set < int > digit;
    while(n > 0)
    {
        digit.insert(n % 10);
        n /= 10;
    }
    return digit;
}

/*
3
4
3 5 7 2
5
121 23 3 333 4
7
32 42 52 62 72 82 92
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

        lli max_sum = 0;

        for(int i = 0; i < n; i++)
        {
            set < int > s = numToDigits(a[i]);
            lli curr_sum = a[i];

            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    set < int > digit = numToDigits(a[j]);
                    int f = 1;
                    for(auto it = digit.begin(); it != digit.end(); it++)
                    {
                        auto ins = s.insert(*it);

                        if(ins.second == false) // duplicate found
                        {
                            f = 0;
                            break;
                        }
                    }
                    if(f)
                    {
                        curr_sum += a[j];
                    }
                }
            }

            max_sum = max(max_sum, curr_sum);
           // cout << max_sum << "\n";
        }
        cout << max_sum << "\n";
    }
    return 0;
}
