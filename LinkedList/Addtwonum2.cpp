#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> s1, s2;
    while (l1)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }

    int carry = 0, first, second;
    ListNode *head = NULL;
    while (!s1.empty() || !s2.empty() || carry)
    {
        if (!s1.empty())
        {
            first = s1.top();
            s1.pop();
        }
        else
            first = 0;

        if (!s2.empty())
        {
            second = s2.top();
            s2.pop();
        }
        else
            second = 0;

        int temp = first + second + carry;
        ListNode *node = new ListNode(temp % 10);
        node->next = head;
        head = node;
        carry = temp / 10;
    }
    return head;
}
int main()
{
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *ans = addTwoNumbers(l1, l2);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}