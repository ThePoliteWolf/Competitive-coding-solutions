/*Given  two-dimensional points in space, determine whether they lie on some vertical or horizontal line. If yes, print YES; otherwise, print NO.

Input Format

The first line contains a single positive integer, , denoting the number of points. 
Each line  of  subsequent lines contain two space-separated integers detailing the respective values of  and  (i.e., the coordinates of the  point).

Constraints

Output Format

Print YES if all points lie on some horizontal or vertical line; otherwise, print NO.

Sample Input 0

5
0 1
0 2
0 3
0 4
0 5
*/
// link -: https://www.hackerrank.com/challenges/points-on-a-line/problem

/*
  Solution:- Horizontal line means y-coordinate is same
             Vertical line means x-coordinate is same
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

bool IsEqual(int a[], int n)
{
    for(int i = 1; i < n; i++)
        if(a[i] != a[i - 1])
            return 0;
    return 1;
}


int main()
{
    int n;
    cin >> n;
    int a[n], b[n];

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    if(IsEqual(a, n) || IsEqual(b, n))    // Line is staright, If any of the given coordinates stream is same :)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
