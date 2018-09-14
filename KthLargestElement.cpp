/*
 author : @itzmv
 */
 
/*
  Find K-th largest element in an array.

  Example
  In array [9,3,2,4,8], the 3rd largest element is 4.

  In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.
*/

// Time complexity - O(nlogK), n - no. of elements and k - kth largest number

// idea is to build a Max Heap
// Remove the top k - 1 time 
// At kth time the top is our answer

#include<bits/stdc++.h>
using namespace std;

#define lli long long int

// Max-Heap or priority queue
class Heap
{
public:
    vector < lli > a;
    void push(int x);
    void maxheapify();
    void pop();
    int front();
};

void Heap :: push(int x)
{
    a.push_back(x);
    maxheapify();
}

// Max Heap
void Heap :: maxheapify()
{
    if(a.size() == 1)
        return;
    int ind = a.size() - 1;
    int root = (ind - 1)/2;
    while(a[root] < a[ind])
    {
        swap(a[root], a[ind]);
        if(root == 0)
            break;
        ind = root;
        root = (ind - 1)/2;
    }
}

int Heap :: front()
{
    if(a.size())
        return a[0];
    else
    {
        cout << "EMPTY\n";
        return -1;
    }

}

// Deleting root
void Heap :: pop()
{
    if(!a.size())
        return;
    if(a.size() == 1)
    {
        a.erase(a.begin());
        a.resize(0);
        return;
    }

    swap(a[0], a[a.size() - 1]);
    a.pop_back();

    if(a.size() == 1)
        return;
    int root = 0;
    int left = 1;
    int right = 2;

    while(a[root] < a[left] ||(right < a.size() && a[root] < a[right]))
    {
        int ind;
        if(a[root] < a[left] && (right >= a.size() || a[left] > a[right]))
            ind = left;
        else
            ind = right;

        swap(a[root], a[ind]);
        root = ind;
        left = 2*root + 1;
        right = 2*root + 2;
        if(left >= a.size() && right >= a.size())
            break;
    }

}
int kthLargestElement(int k, vector<int> &a)
{
    Heap h;
    for(int i = 0; i < a.size(); i++)
    {
        h.push(a[i]);
    }

    while(k > 1)
    {
        int ans = h.front();
        h.pop();
        k--;
    }
    return h.front();

}

int main()
{

    int n;
    cin >> n;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int k;
    cin >> k;

    cout << kthLargestElement(k, a);
    return 0;
}
