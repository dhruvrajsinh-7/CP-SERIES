#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry == 1)
    {
        int sum = 0;
        if (l1)
        {
            sum = sum + l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum = sum + l2->val;
            l2 = l2->next;
        }
        sum = sum + carry;
        carry = sum / 10;
        ListNode *node = new ListNode(sum % 10);
        curr->next = node;
        curr = curr->next;
    }
    return dummy->next;
}
int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *ans = addTwoNumbers(l1, l2);
    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}