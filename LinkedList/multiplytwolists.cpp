#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};
long long mod = 1000000007;
long long multiplyTwoLists(Node *l1, Node *l2)
{
    // Your code here
    long long ans = 1;
    long long res1 = 0, res2 = 0;
    Node *point1 = l1;
    Node *point2 = l2;
    while (point1 != nullptr)
    {
        res1 = (res1 * 10) % mod + point1->data;
        point1 = point1->next;
    }
    while (point2 != nullptr)
    {
        res2 = (res2 * 10) % mod + point2->data;
        point2 = point2->next;
    }
    ans = ((res1 % mod) * (res2 % mod)) % mod;
    return ans;
}
int main()
{
    Node *head1 = new Node(4);
    head1->next = new Node(5);
    head1->next->next = new Node(1);
    head1->next->next->next = new Node(9);
    Node *head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = new Node(1);
    head2->next->next->next = new Node(9);
    cout << multiplyTwoLists(head1, head2);
    return 0;
}