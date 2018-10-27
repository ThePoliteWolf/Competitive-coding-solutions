
/*
 Problem Statement :- Given a number N. our task is to find the closest Palindrome number whose absolute difference with given number is minimum.
 Input :
  2   -- testcase
  9   -- Value1
  489 -- Value2

output:
  9    ans1
  484  ans2
*/


//Solution
/*
  1) Simple Solution is to linearly traverse to the left and right of the number. And the answer is the palindromic value who has min absolute diff. with
  the n.
  
  2) There exist simple solution in which we only need 5 values to get the closest plaindrome to n.
      1st is Mirror of the value  
          e.g. if val = 123456
                  mirror = 123321
      2nd is (half value + 1) then concatenate with the remaining value and mirror it 
          e.g. if val = 123456
               half val = 123 
               new_val =  123 + 1 = 124
               new_val = 12456 (concatenate other digits), Now
               mirror = 124421
      3rd is same as second, here we include one more digit with half val and add 1 in it and then mirror it
              e.g. if val = 123456
               half val = 1234 
               new_val =  1234 + 1 = 1235
               new_val = 123556 (concatenate other digits), Now
               mirror = 123321
      and same goes with 4th and 5th value but we subtract 1 instead of addition and the rest process is same
       
  3) Now insert all these values in array and then check one by one with whom the n has the least minimum absolute difference,
    the value with least diff. is our answer.
    
      
*/

/*
    author : @itzmv
*/
#include<bits/stdc++.h>
using namespace std;

#define ll int64_t
#define llu uint64_t
#define lli long long int
#define MAX 20000001
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

ll mirror(string a)
{
    int i = 0, j = a.length()-1;
    while(i < j)
    {
        a[j--] = a[i++];
    }
    return stoll(a);
}

lli Closest_palindrome(lli num)
{
    string nums = to_string(num);
    ll normal = mirror(nums);
    int n = nums.length();

    ll plus1 = mirror( to_string(stoll(nums.substr(0,n/2))+1)+nums.substr(n/2) );
    ll plus2 = mirror( to_string(stoll(nums.substr(0,n/2+1))+1)+nums.substr(n/2+1));

    ll minus1 = mirror( to_string(stoll(nums.substr(0,n/2))-1)+nums.substr(n/2) );
    ll minus2 = mirror( to_string(stoll(nums.substr(0,n/2+1))-1)+nums.substr(n/2+1) );

    //cout << normal << " " << plus1 << " " << plus2 << " " << minus1 << " " << minus2 << "\n";

    vector<ll>d;
    d.pb(normal);
    d.pb(plus1);
    d.pb(minus2);
    d.pb(minus2);
    d.pb(plus2);

    ll diff = (ll) 1e15;
    ll ans = (ll) 1e15;
    for(auto val : d)
    {
        if(abs(val-num) <= diff)
        {
            diff = abs(val-num);
            ans = val;
        }
    }
    return ans;
}

int main()
{
    ll num;
    cin>>num;
    cout << Closest_palindrome(num) << "\n";
    return 0;
}
