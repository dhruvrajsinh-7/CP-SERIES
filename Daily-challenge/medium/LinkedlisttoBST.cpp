#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *sortedListToBST(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        TreeNode *root = new TreeNode(head->val);
        return root;
    }
    return Tree(head, NULL);
}
TreeNode *Tree(ListNode *starthead, ListNode *endhead)
{
    if (starthead == endhead)
        return NULL;
    ListNode *start = starthead;
    ListNode *end = starthead;
    while (end != endhead && end->next != endhead)
    {
        start = start->next;
        end = end->next->next;
    }
    TreeNode *root = new TreeNode(start->val);
    root->left = Tree(starthead, start);
    root->right = Tree(start->next, endhead);
    return root;
}
int main()
{
    ListNode *head = new ListNode(-10);
    ListNode *node1 = new ListNode(-3);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(5);
    ListNode *node4 = new ListNode(9);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    TreeNode *root = sortedListToBST(head);
    return 0;
}