/*

155. Min Stack
Easy

7402

588

Add to List

Share
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.


Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

#include <bits/stdc++.h>
using namespace std;

// Failed as incase of high values
// But doesnt uses extra stack
class MinStack
{
public:
    stack<long long int> st;
    long long int min = INT_MAX;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            min = val;
            st.push(val);
        }
        else
        {
            long long int x = val;
            // Hshing it if less then min
            if (x < min)
            {
                x = 2 * ((long long int)(val)) - min;
                min = val;
            }
            st.push(x);
        }
    }

    void pop()
    {
        long long int x = st.top();
        if (x > min)
        {
            // Means not hash
            st.pop();
        }
        else
        {
            // means it's min element and ill have to find prev min from it
            // Calculating prev min
            long long int prevmin = 2 * min - x;
            st.pop();
            min = prevmin;
        }
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min;
    }
};
//Efficient soln but uses 2 stacks
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;//For keeping track of min element
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty()||val<=getMin())s2.push(val);
    }
    
    void pop() {
        int top=s1.top();
        s1.pop();
        if(s2.top()==top) s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        if(s2.empty())return -1;
        return s2.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */