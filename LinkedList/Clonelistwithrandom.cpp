#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{
    Node *traverse = head;
    Node *front = head;
    while (traverse != NULL)
    {
        front = traverse->next;
        Node *dummy = new Node(traverse->val);
        traverse->next = dummy;
        dummy->next = front;

        traverse = front;
    }

    traverse = head;
    while (traverse != NULL)
    {
        if (traverse->random != NULL)
        {
            traverse->next->random = traverse->random->next;
        }
        traverse = traverse->next->next;
    }

    traverse = head;
    Node *anshead = new Node(0);
    Node *dummy = anshead;

    while (traverse != NULL)
    {
        front = traverse->next->next;
        dummy->next = traverse->next;
        traverse->next = front;
        dummy = dummy->next;
        traverse = front;
    }
    return anshead->next;
}
int main()
{
    int n;
    cin >> n;
    Node *head = new Node(0);
    Node *traverse = head;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Node *dummy = new Node(val);
        traverse->next = dummy;
        traverse = traverse->next;
    }
    traverse = head->next;
    while (traverse != NULL)
    {
        int random;
        cin >> random;
        if (random != -1)
        {
            Node *temp = head->next;
            while (random--)
            {
                temp = temp->next;
            }
            traverse->random = temp;
        }
        traverse = traverse->next;
    }
    Node *ans = copyRandomList(head->next);
    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}