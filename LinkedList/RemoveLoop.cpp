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
void removeLoop(Node *head)
{
    // code here
    Node *slow = head;
    Node *fast = head;
    if (slow == NULL || slow->next == NULL)
        return;

    slow = slow->next;
    fast = fast->next->next;
    if (fast == NULL)
        return;
    while (fast != NULL && fast->next != NULL)
    {

        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL || fast->next == NULL)
        return;

    slow = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    while (fast->next != slow)
    {
        fast = fast->next;
    }

    fast->next = NULL;
    return;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = head->next->next;
    removeLoop(head);
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}