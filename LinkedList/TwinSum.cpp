#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int pairSum(ListNode *head)
{
    if (head == nullptr || head->next == NULL)
    {
        return 0;
    }
    ListNode *curr = head;
    vector<int> helper;
    while (curr != NULL)
    {
        helper.push_back(curr->val);
        curr = curr->next;
    }
    int n = helper.size() - 1, maxsum = 0;
    for (int left = 0, right = n; left < right; left++, right--)
    {
        maxsum = max(maxsum, helper[left] + helper[right]);
    }
    return maxsum;
}
int main()
{
    int n;
    cin >> n;
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    cout << pairSum(head->next);
    return 0;
}