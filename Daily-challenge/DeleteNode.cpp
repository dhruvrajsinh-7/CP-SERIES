#include<iostream>
#include<algorithm>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
//we have used simple algo in which we just store the data of node into the temporary variable and then change the pointer so its basically doesn't removed from memory 
int main(){
    ListNode* node;
    node->val=1;
    int head[5]={4,5,1,9};
    deleteNode(node);
}
void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        temp->next=nullptr;
        delete(temp);
}
