#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    ListNode *l4 = new ListNode(1);
    ListNode *l5 = new ListNode(3);
    ListNode *l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;
    ListNode *head = mergeTwoLists(l1, l4);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
ListNode *mergeTwoLists(ListNode *List1, ListNode *List2)
{
    if (List1 == NULL)
    {
        return List2;
    }
    if (List2 == NULL)
    {
        return List1;
    }
    if (List1->val < List2->val)
    {
        List1->next = mergeTwoLists(List1->next, List2);
        return List1;
    }
    else
    {
        List2->next = mergeTwoLists(List1, List2->next);
        return List2;
    }
}