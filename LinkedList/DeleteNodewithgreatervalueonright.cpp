#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};
Node *compute(Node *head)
{
    // your code goes here
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data > temp->data)
        {
            temp->data = temp->next->data;
            Node *dummy = temp->next;
            temp->next = temp->next->next;
            delete dummy;
            temp = head;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(3);
    Node *temp = compute(head);
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}