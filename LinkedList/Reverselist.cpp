#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseList(ListNode *head)
{
    ListNode *currpointer = head;
    ListNode *prevpointer = NULL;
    ListNode *nextpointer;
    while (currpointer != nullptr)
    {
        nextpointer = nextpointer->next;
        currpointer->next = prevpointer;
        prevpointer = currpointer;
        currpointer = nextpointer;
    }
    head = prevpointer;
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head = reverseList(head);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}