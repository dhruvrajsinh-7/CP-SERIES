#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    vector<int> helper;
    ListNode *dummy = head;
    while (dummy != NULL)
    {
        helper.push_back(dummy->val);
        dummy = dummy->next;
    }
    int n = helper.size();
    for (int i = 0; i < helper.size() - 1; i += 2)
    {
        swap(helper[i], helper[i + 1]);
    }
    int i = 0;
    dummy = head;
    while (dummy != NULL)
    {
        dummy->val = helper[i++];
        dummy = dummy->next;
    }
    return head;
}
int main()
{
    // Write driver code here
    int n;
    cin >> n;
    ListNode *head = NULL;
    ListNode *dummy = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *temp = new ListNode();
        temp->val = x;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            dummy = temp;
        }
        else
        {
            dummy->next = temp;
            dummy = dummy->next;
        }
    }
    head = swapPairs(head);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}