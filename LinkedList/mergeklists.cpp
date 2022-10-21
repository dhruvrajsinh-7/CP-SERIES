#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    vector<ListNode *> lists;
    lists.push_back(l1);
    lists.push_back(l4);
    ListNode *head = mergeKLists(lists);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    if (n == 0)
        return NULL;
    vector<pair<int, ListNode *>> ans;
    for (int i = 0; i < n; i++)
    {
        ListNode *l1 = lists[i];
        while (l1 != NULL)
        {
            ans.push_back({l1->val, l1});
            l1 = l1->next;
        }
    }
    if (ans.size() == 0)
        return NULL;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size() - 1; i++)
    {
        ans[i].second->next = ans[i + 1].second;
    }
    ans[ans.size() - 1].second->next = NULL;
    return ans[0].second;
}