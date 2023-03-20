#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
node *partition(node *root, node *end)
{
    node *pivot = root, *curr = root->next;
    while (curr != end)
    {
        if (curr->data <= pivot->data)
        {
            swap(curr->data, pivot->data);
        }
        curr = curr->next;
    }
    return pivot;
}
void quick_sort(node *root, node *end = NULL)
{
    if (!root || !root->next || root == end)
    {
        return;
    }
    node *mid = partition(root, end);
    quick_sort(root, mid);
    quick_sort(mid->next, end);
}
void quickSort(struct node **headRef)
{
    quick_sort(*headRef);
}
int main()
{
    node *head = new node(5);
    head->next = new node(10);
    head->next->next = new node(19);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(20);
    head->next->next->next->next->next = new node(1);
    quickSort(&head);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}