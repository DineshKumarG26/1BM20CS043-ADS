/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
  
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* ptr = head->next;
        ListNode*node = ptr;

        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        while(ptr!=NULL && ptr->next!=NULL)
        {
            temp->next=ptr->next;
            ptr->next=temp->next->next;
            temp->next->next=node;
            temp=temp->next;
            ptr=ptr->next;
        }
        return head;
    }
};
