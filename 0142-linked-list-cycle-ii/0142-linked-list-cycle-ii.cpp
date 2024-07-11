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
    ListNode *detectCycle(ListNode *head) {
        
        // using set and we can use map insted 
        // unordered_set<ListNode*> st;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     if(st.find(temp)!=st.end())
        //         return temp;
        //     st.insert(temp);
        //     temp=temp->next;
        // }
        // return NULL;
        
        
        // slow fast pointer
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};