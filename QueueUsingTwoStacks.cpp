// link -: https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
/*In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2:2: Dequeue the element at the front of the queue.
3:3: Print the element at the front of the queue.

 author - @ItzMv 
*/

/* ALGORITHM :- 
The idea is to use two stack -:
   1. Enq (To push element in it)
   2. Deq ( for getting top and deleting front)
For pushing element in queue is easy, Just push elements in enq stack
 
But when we have to get the front or to delete the front of the queue
Then we have to check for one condition
i.e.  If the deq stack is empty, then we have to push all the values of 
      enq stack into deq.
      After above process, delete the top of deq stack or get the value 
      of the top of deq stack(depend on user).
     
First try it yourself And if you get stuck(after trying 3-4 times) then feel free to take help from the below code
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int main()
{

    int q;
    cin >> q;

    stack < ll > enq;
    stack < ll > deq;

    while(q--)
    {
        int x;
        cin >> x;

        if(x == 1)        // push
        {
            ll y;
            cin >> y;
            enq.push(y);
        }

        else if(x == 2)         // deleting the front of the queue
        {
            if(deq.size() > 0)
            {
                deq.pop();
            }

            else
            {
                while(!enq.empty())           // If its not empty then push all values in deq and then 
                {
                    deq.push(enq.top());
                    enq.pop();
                }
                deq.pop();                   // delete the front of queue
            }
        }
        else              // getting front value of the queue
        {
            if(deq.size() > 0)
            {
                cout << deq.top() << "\n";
            }

            else
            {
                while(!enq.empty())
                {
                    deq.push(enq.top());
                    enq.pop();
                }
                cout << deq.top() << "\n";           // print the front of the queue
            }
        }
    }

    return 0;
}
