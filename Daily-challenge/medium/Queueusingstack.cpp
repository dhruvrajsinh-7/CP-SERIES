#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> st;
    stack<int> st1;
    MyQueue()
    {
    }
    void push(int x)
    {
        st.push(x);
    }
    int pop()
    {
        int x = peek();
        st1.pop();
        return x;
    }
    int peek()
    {
        if (st1.empty())
        {
            while (st.size())
            {
                st1.push(st.top());
                st.pop();
            }
        }
        return st1.top();
    }
    bool empty()
    {
        if (st.empty() && st1.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    MyQueue *obj = new MyQueue();
    int x;
    cin>>x;
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    return 0;
}