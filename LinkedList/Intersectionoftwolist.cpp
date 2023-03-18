#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> st;
    while (headA != nullptr)
    {
        st.insert(headA);
        headA = headA->next;
    }
    while (headB != nullptr)
    {
        if (st.find(headB) != st.end())
        {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int x;
        cin >> x;
        ListNode *headA = new ListNode(x);
        ListNode *tailA = headA;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            tailA->next = new ListNode(x);
            tailA = tailA->next;
        }
        cin >> x;
        ListNode *headB = new ListNode(x);
        ListNode *tailB = headB;
        for (int i = 0; i < m - 1; i++)
        {
            cin >> x;
            tailB->next = new ListNode(x);
            tailB = tailB->next;
        }
        ListNode *common = getIntersectionNode(headA, headB);
        if (common)
            cout << common->val << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}