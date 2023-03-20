#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node *mergeTwoLists(Node *a, Node *b)
{

    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}
Node *flatten(Node *root)
{

    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);

    root = mergeTwoLists(root, root->next);

    return root;
}
int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);
    head->next->next->next->next = new Node(35);
    head->next->next->next->next->next = new Node(40);
    head->next->next->next->next->next->next = new Node(45);
    head->next->next->next->next->next->next->next = new Node(50);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);
    head->next->bottom = new Node(20);
    head->next->bottom->bottom = new Node(22);
    head->next->bottom->bottom->bottom = new Node(50);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);
    head->next->next->next->next->bottom = new Node(40);
    head->next->next->next->next->bottom->bottom = new Node(45);
    head->next->next->next->next->bottom->bottom->bottom = new Node(50);
    head->next->next->next->next->next->bottom = new Node(45);
    head->next->next->next->next->next->bottom->bottom = new Node(50);
    head->next->next->next->next->next->next->bottom = new Node(50);
    Node *res = flatten(head);
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->bottom;
    }
    return 0;
}