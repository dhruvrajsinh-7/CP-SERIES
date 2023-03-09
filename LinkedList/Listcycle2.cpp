#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next, fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for (int i = 2; i < 6; i++)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    p->next = head->next->next;
    ListNode *q = detectCycle(head);
    if (q)
        cout << "Present at index value" << q->val << endl;
    else
        cout << "NULL" << endl;
    return 0;
}