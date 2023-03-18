#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
Node *reverseDLL(Node *head)
{
    // Your code here
    Node *prev = NULL;
    Node *curr = head;
    Node *temp;

    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        curr->prev = temp;
        prev = curr;
        curr = temp;
    }

    return prev;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        Node *head = new Node(x);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            tail->next = new Node(x);
            tail->next->prev = tail;
            tail = tail->next;
        }
        head = reverseDLL(head);
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    return 0;
}