/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* x=head;
        ListNode* y=head;
        if(head==NULL)
            return false;
        while(x!=NULL && x->next!=NULL){
            x=x->next->next;
            y=y->next;
            if(x==y)
                return true;
        }
        return false;
    }
};