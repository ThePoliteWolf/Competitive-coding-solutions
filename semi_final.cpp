#include<bits/stdc++.h>
using namespace std;

#define lli long long int

vector < int > numToDigits(int n)
{
    vector < int > digit;
    while(n > 0)
    {
        digit.push_back(n % 10);
        n /= 10;
    }
    return digit;
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

        lli max_sum = 0;
        for(int i = 0; i < n; i++)
        {
            set < int > s;
            lli curr_sum = 0;
            curr_sum += a[i];
            vector < int > digit = numToDigits(a[i]);
            for(int k = 0; k < digit.size(); k++)
            {
                s.insert(digit[k]);
                //cout << digit[k] << " ";
            }

            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    digit = numToDigits(a[j]);
                    int f = 1;
                    for(int k = 0; k < digit.size(); k++)
                    {
                        auto ins = s.insert(digit[k]);
                        if(ins.second == false)
                        {
                            f = 0;
                            //cout << a[i] << "=>" << a[j] << "\n";
                            break;
                        }
                    }
                    if(f)
                    {
                        curr_sum += a[j];
                        cout << a[i] << "=>" << a[j] << "\n";
                    }
                }
            }

            max_sum = max(max_sum, curr_sum);
        }
        cout << max_sum << "\n";
    }
    return 0;
}
