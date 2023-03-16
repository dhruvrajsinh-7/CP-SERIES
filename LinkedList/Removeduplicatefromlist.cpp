#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};
Node *removeDuplicates(Node *head)
{
    // your code goes here
    unordered_set<int> mp;
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL)
    {
        if (mp.find(current->data) != mp.end())
        {
            previous->next = current->next;
            delete (current);
        }
        else
        {
            mp.insert(current->data);
            previous = current;
        }
        current = previous->next;
    }
    return head;
}
int main()
{
    Node *head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);
    head = removeDuplicates(head);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}