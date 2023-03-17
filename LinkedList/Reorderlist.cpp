#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void reorderList(ListNode *head)
{

    ListNode *S_lastnode;
    while (head && head->next && head->next->next)
    {
        S_lastnode = head;
        while (S_lastnode->next->next)
            S_lastnode = S_lastnode->next;

        S_lastnode->next->next = head->next;
        head->next = S_lastnode->next;

        S_lastnode->next = NULL;
        head = head->next->next;
    }
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    reorderList(head);
    return 0;
}