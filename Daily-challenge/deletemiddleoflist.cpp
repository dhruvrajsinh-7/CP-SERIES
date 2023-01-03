#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ListNode *head;
    head->val = 1;
    int head[5] = {4, 5, 1, 9};
    deleteMiddle(head);
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *deleteMiddle(ListNode *head)
{
    if (head->next == NULL)
        return NULL;
    ListNode *fast = head->next->next;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}
