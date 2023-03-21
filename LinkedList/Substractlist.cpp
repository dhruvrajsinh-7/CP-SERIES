#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *removeLeadingZeros(Node *head)
{
    if (head != NULL and head->data == 0)
    {
        return removeLeadingZeros(head->next);
    }
    else
    {
        return head;
    }
}
Node *reverseNode(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    Node *prev = NULL, *curr = head, *forw = NULL;
    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}
int length(Node *head)
{
    Node *curr = head;
    int len = 0;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }
    return len;
}
Node *subLinkedList(Node *l1, Node *l2)
{
    // Your code here
    l1 = removeLeadingZeros(l1);
    l2 = removeLeadingZeros(l2);
    int n1 = length(l1);
    int n2 = length(l2);
    if (n2 > n1)
    {
        swap(l1, l2);
    }
    else if (n1 == n2)
    {
        Node *c1 = l1, *c2 = l2;
        while (c1->data == c2->data)
        {
            c1 = c1->next;
            c2 = c2->next;
            if (c1 == NULL)
            {
                return new Node(0);
            }
        }
        if (c2->data > c1->data)
        {
            swap(l1, l2);
        }
    }
    Node *c1 = reverseNode(l1);
    Node *c2 = reverseNode(l2);
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    int borrow = 0;
    while (c1 != NULL)
    {
        int diff = borrow + c1->data - (c2 != NULL ? c2->data : 0);
        if (diff < 0)
        {
            diff += 10;
            borrow = -1;
        }
        else
        {
            borrow = 0;
        }
        prev->next = new Node(diff);
        prev = prev->next;
        if (c2 != NULL)
        {
            c2 = c2->next;
        }
        c1 = c1->next;
    }
    Node *head = reverseNode(dummy->next);
    head = removeLeadingZeros(head);
    return head;
}
int main()
{
    int n;
    cin >> n;
    Node *head1 = new Node(0);
    Node *traverse = head1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        traverse->next = new Node(x);
        traverse = traverse->next;
    }
    int m;
    cin >> m;
    Node *head2 = new Node(0);
    traverse = head2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        traverse->next = new Node(x);
        traverse = traverse->next;
    }
    Node *ans = subLinkedList(head1->next, head2->next);
    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}