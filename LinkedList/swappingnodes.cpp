#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *curr = head;
    for (int i = 0; i < k - 1; i++)
    {
        curr = curr->next;
    }
    ListNode *left = curr;
    ListNode *right = head;

    while (curr->next)
    {
        curr = curr->next;
        right = right->next;
    }
    swap(right->val, left->val);
    return head;
}
int main()
{
    ListNode *head = new ListNode();
    head->val = 1;
    head->next = new ListNode();
    head->next->val = 2;
    head->next->next = new ListNode();
    head->next->next->val = 3;
    head->next->next->next = new ListNode();
    head->next->next->next->val = 4;
    head->next->next->next->next = new ListNode();
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->val = 6;
    head->next->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->next->val = 7;
    head->next->next->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->next->next->val = 8;
    head->next->next->next->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->next->next->next->val = 9;

    swapNodes(head, 5);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}