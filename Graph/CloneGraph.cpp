#include <bits/stdc++.h>
using namespace std;

unordered_map<Node *, Node *> map;
int val;
vector<Node *> neighbors;
Node()
{
    val = 0;
    neighbors = vector<Node *>();
}
Node(int _val)
{
    val = _val;
    neighbors = vector<Node *>();
}
Node(int _val, vector<Node *> _neighbors)
{
    val = _val;
    neighbors = _neighbors;
}
}
Node *cloneGraph(Node *node)
{
    if (node == NULL)
        return NULL;
    return dfs(node);
}

Node *dfs(Node *node)
{
    if (map.find(node) != map.end())
        return map[node];
    Node *clone = new Node(node->val);
    map[node] = clone;
    for (Node *n : node->neighbors)
        clone->neighbors.push_back(dfs(n));
    return clone;
}
