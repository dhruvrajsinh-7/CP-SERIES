#include<iostream>
#include<algorithm>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
//we have used simple algo in which we just store the data of node into the temporary variable and then change the pointer so its basically doesn't removed from memory 
//delete node in linkedlist
//void deletenode(ListNode* node){
//    ListNode* temp=node->next;
//    node->val=temp->val;
//    node->next=temp->next;
//    delete temp;
//}
void deleteNode(ListNode* node) {
     ListNode* temp=node->next;
     node->next=node->next->next;
     delete(temp);
}

int main(){
    ListNode* head=new ListNode(4);
    head->next=new ListNode(5);
    head->next->next=new ListNode(1);
    head->next->next->next=new ListNode(9);
    deleteNode(head);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}