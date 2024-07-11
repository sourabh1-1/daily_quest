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
    ListNode* prev=NULL;
public:
    ListNode* recursion(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* newHead=recursion(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        
        // using stack
        // ListNode* temp=head;
        // stack<int> st;
        // while(temp!=NULL){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(!st.empty()){
        //     temp->val=st.top();
        //     st.pop();
        //     temp=temp->next;
        // }
        // return head;
        
        
        // optimise
        // ListNode* temp=head;
        // ListNode* prev=NULL;
        // while(temp!=NULL){
        //     ListNode* front=temp->next;
        //     temp->next=prev;
        //     prev=temp;
        //     temp=front;
        // }
        // head=prev;
        // return head;
        
        
        //recursion
        return recursion(head);
    }
};