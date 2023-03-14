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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == 0)
        return list2;
    if (list2 == 0)
        return list1;
    if (list1->val > list2->val)
        swap(list1, list2);
    ListNode *res = list1;

    while (list1 != NULL && list2 != NULL)
    {
        ListNode *temp = NULL;

        while (list1 != NULL && list1->val <= list2->val)
        {
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        swap(list1, list2);
    }
    return res;
}
