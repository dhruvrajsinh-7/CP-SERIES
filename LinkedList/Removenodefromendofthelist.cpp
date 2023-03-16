#include <iostream>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count == n)
    {
        ListNode *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }
    temp = head;
    for (int i = 0; i < count - n - 1; i++)
    {
        temp = temp->next;
    }
    ListNode *temp1 = temp->next;
    temp->next = temp1->next;
    delete (temp1);
    return head;
}
int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    head = removeNthFromEnd(head, 2);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}